/*
 * Copyright (c) 2012-2020 MIRACL UK Ltd.
 *
 * This file is part of MIRACL Core
 * (see https://github.com/miracl/core).
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

var PAIR192 = function(ctx) {
    "use strict";
    var PAIR192 = {

		dbl: function(A,AA,BB,CC) {
            CC.copy(A.getx());
            var YY = new ctx.FP4(A.gety());
            BB.copy(A.getz());
            AA.copy(YY);

            AA.mul(BB); //YZ
            CC.sqr(); //X^2
            YY.sqr(); //Y^2
            BB.sqr(); //Z^2

			AA.add(AA);
			AA.neg(); AA.norm();       //-2AA
			AA.times_i();

			var sb = 3 * ctx.ROM_CURVE.CURVE_B_I;
			BB.imul(sb);
			CC.imul(3);
			if (ctx.ECP.SEXTIC_TWIST==ctx.ECP.D_TYPE)
			{
				YY.times_i();
				CC.times_i();
			}
			if (ctx.ECP.SEXTIC_TWIST==ctx.ECP.M_TYPE)
			{
				BB.times_i();
			}
			BB.sub(YY);
			BB.norm();

			A.dbl();

		},

		add: function(A,B,AA,BB,CC) {
            AA.copy(A.getx()); // X1
            CC.copy(A.gety()); // Y1
            var T1 = new ctx.FP4(A.getz()); // Z1
            BB.copy(A.getz()); // Z1

            T1.mul(B.gety()); // T1=Z1.Y2
            BB.mul(B.getx()); // T2=Z1.X2

            AA.sub(BB);
            AA.norm(); // X1=X1-Z1.X2
            CC.sub(T1);
            CC.norm(); // Y1=Y1-Z1.Y2

            T1.copy(AA); // T1=X1-Z1.X2

            if (ctx.ECP.SEXTIC_TWIST == ctx.ECP.M_TYPE) {
                AA.times_i();
                AA.norm();
            }

            T1.mul(B.gety()); // T1=(X1-Z1.X2).Y2

            BB.copy(CC); // T2=Y1-Z1.Y2
            BB.mul(B.getx()); // T2=(Y1-Z1.Y2).X2
            BB.sub(T1);
            BB.norm(); // T2=(Y1-Z1.Y2).X2 - (X1-Z1.X2).Y2
            CC.neg();
            CC.norm(); // Y1=-(Y1-Z1.Y2).Xs

            A.add(B);
		},


        /* Line function */
        line: function(A, B, Qx, Qy) {
            var r = new ctx.FP24(1);

			var a,b,c;
			var AA=new ctx.FP4(0);
			var BB=new ctx.FP4(0);
			var CC=new ctx.FP4(0);
            if (A == B) 
				PAIR192.dbl(A,AA,BB,CC);
			else
				PAIR192.add(A,B,AA,BB,CC);

			CC.qmul(Qx);
			AA.qmul(Qy);

            a = new ctx.FP8(AA, BB); 
            if (ctx.ECP.SEXTIC_TWIST == ctx.ECP.D_TYPE) {
                b = new ctx.FP8(CC); // L(0,1) | L(0,0) | L(1,0)
                c = new ctx.FP8(0);
            }
            if (ctx.ECP.SEXTIC_TWIST == ctx.ECP.M_TYPE) {
                b = new ctx.FP8(0);
                c = new ctx.FP8(CC); c.times_i();
            }

            r.set(a, b, c);
			r.settype(ctx.FP.SPARSER);

            return r;
        },

/* prepare for multi-pairing */
		initmp: function() {
			var r=[];
			for (var i=0;i<ctx.ECP.ATE_BITS;i++)
				r[i] = new ctx.FP24(1);
			return r;
		},

/* basic Miller loop */
		miller: function(r) {
			var res=new ctx.FP24(1);
			for (var i=ctx.ECP.ATE_BITS-1; i>=1; i--)
			{
				res.sqr();
				res.ssmul(r[i]); 
				r[i].zero();
			}

			if (ctx.ECP.SIGN_OF_X==ctx.ECP.NEGATIVEX)
				res.conj();
			res.ssmul(r[0]);
			r[0].zero();

			return res;
		},

// Store precomputed line details in an FP8
		pack: function(AA,BB,CC) {
			var i=new ctx.FP4(CC);
			i.inverse();
			var a=new ctx.FP4(AA);
			a.mul(i);
			var b=new ctx.FP4(BB);
			b.mul(i);
			return new ctx.FP8(a,b);
		},

		unpack: function(T,Qx,Qy) {
			var a,b,c;
			a=new ctx.FP8(T);
			a.geta().qmul(Qy);
			var t=new ctx.FP4(Qx);
            if (ctx.ECP.SEXTIC_TWIST == ctx.ECP.D_TYPE) {
				b=new ctx.FP8(t);
				c=new ctx.FP8(0);

			}
			if (ctx.ECP.SEXTIC_TWIST == ctx.ECP.M_TYPE) {
				b=new ctx.FP8(0);
				c=new ctx.FP8(t); c.times_i();
			}
			var v=new ctx.FP24(a,b,c);
			v.settype(ctx.FP.SPARSEST);
			return v;
		},

		precomp : function(QV) {
			var n=new ctx.BIG(0);
			var n3=new ctx.BIG(0);
			var nb=PAIR192.lbits(n3,n);
			var P=new ctx.ECP4(); P.copy(QV);
			var AA=new ctx.FP4(0);
			var BB=new ctx.FP4(0);
			var CC=new ctx.FP4(0);
			var j,bt;

			var A=new ctx.ECP4();
			A.copy(P);
			var MP=new ctx.ECP4();
			MP.copy(P); MP.neg();
			j=0;

			var T=[];
			for (var i=nb-2;i>=1;i--)
			{
				PAIR192.dbl(A,AA,BB,CC);
				T[j++]=PAIR192.pack(AA,BB,CC);

				bt=n3.bit(i)-n.bit(i); 
				if (bt==1)
				{
					PAIR192.add(A,P,AA,BB,CC);
					T[j++]=PAIR192.pack(AA,BB,CC);
				}
				if (bt==-1)
				{
					PAIR192.add(A,MP,AA,BB,CC);
					T[j++]=PAIR192.pack(AA,BB,CC);
				}
			}
			return T;
		},

/* Accumulate another set of line functions for n-pairing, assuming precomputation on G2 */
		another_pc(r,T,QV) {
			var n=new ctx.BIG(0);
			var n3=new ctx.BIG(0);
			var nb=PAIR192.lbits(n3,n);
			var lv,lv2;
			var j,bt;

			if (QV.is_infinity()) return;

			var Q=new ctx.ECP(); Q.copy(QV); Q.affine();
			var Qx=new ctx.FP(Q.getx());
			var Qy=new ctx.FP(Q.gety());

			j=0;
			for (var i=nb-2;i>=1;i--)
			{
				lv=PAIR192.unpack(T[j++],Qx,Qy);
				bt=n3.bit(i)-n.bit(i); 
				if (bt==1)
				{
					lv2=PAIR192.unpack(T[j++],Qx,Qy);
					lv.smul(lv2);
				}
				if (bt==-1)
				{
					lv2=PAIR192.unpack(T[j++],Qx,Qy);
					lv.smul(lv2);
				}
				r[i].ssmul(lv);
			}
		},

/* Accumulate another set of line functions for n-pairing */
		another: function(r,P1,Q1) {

			var f;
			var n=new ctx.BIG(0);
			var n3=new ctx.BIG(0);
			var lv,lv2;
			var bt;

			if (Q1.is_infinity()) return;
// P is needed in affine form for line function, Q for (Qx,Qy) extraction
			var P=new ctx.ECP4(); P.copy(P1); P.affine();
			var Q=new ctx.ECP(); Q.copy(Q1); Q.affine();

			P.affine();
			Q.affine();

			var Qx=new ctx.FP(Q.getx());
			var Qy=new ctx.FP(Q.gety());

			var A=new ctx.ECP4();
			A.copy(P);

			var MP=new ctx.ECP4();
			MP.copy(P); MP.neg();

			var nb=PAIR192.lbits(n3,n);

			for (var i=nb-2;i>=1;i--)
			{
				lv=PAIR192.line(A,A,Qx,Qy);

				bt=n3.bit(i)-n.bit(i); 
				if (bt==1)
				{
					lv2=PAIR192.line(A,P,Qx,Qy);
					lv.smul(lv2);
				}
				if (bt==-1)
				{
					lv2=PAIR192.line(A,MP,Qx,Qy);
					lv.smul(lv2);
				}
				r[i].ssmul(lv);
			} 
		},


        /* Optimal R-ate pairing */
        ate: function(P1, Q1) {
            var x, n, n3, lv, lv2,
                Qx, Qy, A, NP, r, nb, bt,
                i;

			if (Q1.is_infinity()) return new ctx.FP24(1);
            n = new ctx.BIG(0);
			n3 = new ctx.BIG(0);

			var P=new ctx.ECP4(); P.copy(P1); P.affine();
			var Q=new ctx.ECP(); Q.copy(Q1); Q.affine();

            Qx = new ctx.FP(Q.getx()); 
            Qy = new ctx.FP(Q.gety()); 

            A = new ctx.ECP4();
            r = new ctx.FP24(1);

            A.copy(P);
			NP = new ctx.ECP4();
			NP.copy(P);
			NP.neg();


            nb = PAIR192.lbits(n3,n);

            for (i = nb - 2; i >= 1; i--) {
                r.sqr();
                lv = PAIR192.line(A, A, Qx, Qy);
                bt=n3.bit(i)-n.bit(i);

                if (bt == 1) {
                    lv2 = PAIR192.line(A, P, Qx, Qy);
                    lv.smul(lv2);
                }
                if (bt == -1) {
                    lv2 = PAIR192.line(A, NP, Qx, Qy);
                    lv.smul(lv2);
                }
                r.ssmul(lv);
            }

            if (ctx.ECP.SIGN_OF_X == ctx.ECP.NEGATIVEX) {
                r.conj();
            }

            return r;
        },

        /* Optimal R-ate double pairing e(P,Q).e(R,S) */
        ate2: function(P1, Q1, R1, S1) {
            var x, n, n3, lv, lv2,
                Qx, Qy, Sx, Sy, A, B, NP, NR, r, nb, bt,
                i;

			if (Q1.is_infinity()) return PAIR192.ate(R1,S1);
			if (S1.is_infinity()) return PAIR192.ate(P1,Q1);

            n = new ctx.BIG(0);
			n3 = new ctx.BIG(0);

			var P=new ctx.ECP4(); P.copy(P1); P.affine();
			var Q=new ctx.ECP(); Q.copy(Q1); Q.affine();
			var R=new ctx.ECP4(); R.copy(R1); R.affine();
			var S=new ctx.ECP(); S.copy(S1); S.affine();


            Qx = new ctx.FP(Q.getx());
            Qy = new ctx.FP(Q.gety());

            Sx = new ctx.FP(S.getx());
            Sy = new ctx.FP(S.gety());

            A = new ctx.ECP4();
            B = new ctx.ECP4();
            r = new ctx.FP24(1);

            A.copy(P);
            B.copy(R);
			NP = new ctx.ECP4();
			NP.copy(P);
			NP.neg();
			NR = new ctx.ECP4();
			NR.copy(R);
			NR.neg();

            nb = PAIR192.lbits(n3,n);

            for (i = nb - 2; i >= 1; i--) {
                r.sqr();
                lv = PAIR192.line(A, A, Qx, Qy);
                lv2 = PAIR192.line(B, B, Sx, Sy);
				lv.smul(lv2);
                r.ssmul(lv);

                bt=n3.bit(i)-n.bit(i);

                if (bt == 1) {
                    lv = PAIR192.line(A, P, Qx, Qy);
                    lv2 = PAIR192.line(B, R, Sx, Sy);
					lv.smul(lv2);
                    r.ssmul(lv);
                }
                if (bt == -1) {
                    lv = PAIR192.line(A, NP, Qx, Qy);
                    lv2 = PAIR192.line(B, NR, Sx, Sy);
					lv.smul(lv2);
                    r.ssmul(lv);
                }
            }

            if (ctx.ECP.SIGN_OF_X == ctx.ECP.NEGATIVEX) {
                r.conj();
            }

            return r;
        },

        /* final exponentiation - keep separate for multi-pairings and to avoid thrashing stack */
        fexp: function(m) {
            var fa, fb, f, x, r, lv,
                t0,t1,t2,t3,t4,t5,t6,t7;

            fa = new ctx.BIG(0);
            fa.rcopy(ctx.ROM_FIELD.Fra);
            fb = new ctx.BIG(0);
            fb.rcopy(ctx.ROM_FIELD.Frb);
            f = new ctx.FP2(fa, fb);
            x = new ctx.BIG(0);
            x.rcopy(ctx.ROM_CURVE.CURVE_Bnx);

            r = new ctx.FP24(m); //r.copy(m);

            /* Easy part of final exp */
            lv = new ctx.FP24(r); //lv.copy(r);
            lv.inverse();
            r.conj();
            r.mul(lv);
            lv.copy(r);
            r.frob(f,4);
            r.mul(lv);

            /* Hard part of final exp */
            // Ghamman & Fouotsa Method
            t7=new ctx.FP24(r); t7.usqr();
            t1=t7.pow(x);

            x.fshr(1);
            t2=t1.pow(x);
            x.fshl(1);

            if (ctx.ECP.SIGN_OF_X==ctx.ECP.NEGATIVEX) {
                t1.conj();
            }
            t3=new ctx.FP24(t1); t3.conj();
            t2.mul(t3);
            t2.mul(r);

            t3=t2.pow(x);
            t4=t3.pow(x);
            t5=t4.pow(x);

            if (ctx.ECP.SIGN_OF_X==ctx.ECP.NEGATIVEX) {
                t3.conj(); t5.conj();
            }

            t3.frob(f,6); t4.frob(f,5);
            t3.mul(t4);

            t6=t5.pow(x);
            if (ctx.ECP.SIGN_OF_X==ctx.ECP.NEGATIVEX) {
                t6.conj();
            }

            t5.frob(f,4);
            t3.mul(t5);

            t0=new ctx.FP24(t2); t0.conj();
            t6.mul(t0);

            t5.copy(t6);
            t5.frob(f,3);

            t3.mul(t5);
            t5=t6.pow(x);
            t6=t5.pow(x);

            if (ctx.ECP.SIGN_OF_X==ctx.ECP.NEGATIVEX) {
                t5.conj();
            }

            t0.copy(t5);
            t0.frob(f,2);
            t3.mul(t0);
            t0.copy(t6);
            t0.frob(f,1);

            t3.mul(t0);
            t5=t6.pow(x);

            if (ctx.ECP.SIGN_OF_X==ctx.ECP.NEGATIVEX) {
                t5.conj();
            }
            t2.frob(f,7);

            t5.mul(t7);
            t3.mul(t2);
            t3.mul(t5);

            r.mul(t3);

            r.reduce();

            return r;
        }
    };

/* prepare ate parameter, n=6u+2 (BN) or n=u (BLS), n3=3*n */
	PAIR192.lbits = function(n3,n)
	{
		n.rcopy(ctx.ROM_CURVE.CURVE_Bnx);
		n3.copy(n);
		n3.pmul(3);
		n3.norm();
		return n3.nbits();
	};

    /* GLV method */
    PAIR192.glv = function(e) {
        var u = [],
            q, x, x2;

        // -(x^2).P = (Beta.x,y)
        q = new ctx.BIG(0);
        q.rcopy(ctx.ROM_CURVE.CURVE_Order);
        x = new ctx.BIG(0);
        x.rcopy(ctx.ROM_CURVE.CURVE_Bnx);
        x2 = ctx.BIG.smul(x, x);
        x = ctx.BIG.smul(x2,x2);
        u[0] = new ctx.BIG(e);
        u[0].mod(x);
        u[1] = new ctx.BIG(e);
        u[1].div(x);
        u[1].rsub(q);

        return u;
    };

    /* Galbraith & Scott Method */
    PAIR192.gs = function(e) {
        var u = [],
            i, q, x, w;

        x = new ctx.BIG(0);
        x.rcopy(ctx.ROM_CURVE.CURVE_Bnx);
        q = new ctx.BIG(0);
        q.rcopy(ctx.ROM_CURVE.CURVE_Order);
        w = new ctx.BIG(e);

        for (i = 0; i < 7; i++) {
            u[i] = new ctx.BIG(w);
            u[i].mod(x);
            w.div(x);
        }

        u[7] = new ctx.BIG(w);
        if (ctx.ECP.SIGN_OF_X==ctx.ECP.NEGATIVEX) {
            u[1].copy(ctx.BIG.modneg(u[1], q));
            u[3].copy(ctx.BIG.modneg(u[3], q));
            u[5].copy(ctx.BIG.modneg(u[5], q));
            u[7].copy(ctx.BIG.modneg(u[7], q));
        }

        return u;
    };

    /* Multiply P by e in group G1 */
    PAIR192.G1mul = function(P, e) {
        var R, Q, q, bcru, cru, t, u, np, nn;

        if (ctx.ROM_CURVE.USE_GLV) {
            R = new ctx.ECP();
            R.copy(P);
            Q = new ctx.ECP();
            Q.copy(P); Q.affine();
            q = new ctx.BIG(0);
            q.rcopy(ctx.ROM_CURVE.CURVE_Order);
            bcru = new ctx.BIG(0);
            bcru.rcopy(ctx.ROM_FIELD.CRu);
            cru = new ctx.FP(bcru);
            t = new ctx.BIG(0);
            u = PAIR192.glv(e);

            Q.getx().mul(cru);

            np = u[0].nbits();
            t.copy(ctx.BIG.modneg(u[0], q));
            nn = t.nbits();
            if (nn < np) {
                u[0].copy(t);
                R.neg();
            }

            np = u[1].nbits();
            t.copy(ctx.BIG.modneg(u[1], q));
            nn = t.nbits();
            if (nn < np) {
                u[1].copy(t);
                Q.neg();
            }
            u[0].norm();
            u[1].norm();
            R = R.mul2(u[0], Q, u[1]);
        } else {
            R = P.mul(e);
        }

        return R;
    };

    /* Multiply P by e in group G2 */
    PAIR192.G2mul = function(P, e) {
        var R, Q, F, q, u, t, i, np, nn;

        if (ctx.ROM_CURVE.USE_GS_G2) {
            Q = [];
            F = ctx.ECP4.frob_constants();

            q = new ctx.BIG(0);
            q.rcopy(ctx.ROM_CURVE.CURVE_Order);

            u = PAIR192.gs(e);
            t = new ctx.BIG(0);
          
            Q[0] = new ctx.ECP4();
            Q[0].copy(P);

            for (i = 1; i < 8; i++) {
                Q[i] = new ctx.ECP4();
                Q[i].copy(Q[i - 1]);
                Q[i].frob(F,1);
            }

            for (i = 0; i < 8; i++) {
                np = u[i].nbits();
                t.copy(ctx.BIG.modneg(u[i], q));
                nn = t.nbits();

                if (nn < np) {
                    u[i].copy(t);
                    Q[i].neg();
                }
                u[i].norm();
            }

            R = ctx.ECP4.mul8(Q, u);
        } else {
            R = P.mul(e);
        }
        return R;
    };

    /* Note that this method requires a lot of RAM */
    PAIR192.GTpow = function(d, e) {
        var r, g, fa, fb, f, q, t, u, i, np, nn;

        if (ctx.ROM_CURVE.USE_GS_GT) {
            g = [];
            fa = new ctx.BIG(0);
            fa.rcopy(ctx.ROM_FIELD.Fra);
            fb = new ctx.BIG(0);
            fb.rcopy(ctx.ROM_FIELD.Frb);
            f = new ctx.FP2(fa, fb);
            q = new ctx.BIG(0);
            q.rcopy(ctx.ROM_CURVE.CURVE_Order);
            t = new ctx.BIG(0);
            u = PAIR192.gs(e);

            g[0] = new ctx.FP24(d);

            for (i = 1; i < 8; i++) {
                g[i] = new ctx.FP24(0);
                g[i].copy(g[i - 1]);
                g[i].frob(f,1);
            }

            for (i = 0; i < 8; i++) {
                np = u[i].nbits();
                t.copy(ctx.BIG.modneg(u[i], q));
                nn = t.nbits();

                if (nn < np) {
                    u[i].copy(t);
                    g[i].conj();
                }
                u[i].norm();
            }

            r = ctx.FP24.pow8(g, u);
        } else {
            r = d.pow(e);
        }

        return r;
    };

/* test G1 group membership */
    PAIR192.G1member=function(P)
    {
        var q = new ctx.BIG(0);
        q.rcopy(ctx.ROM_CURVE.CURVE_Order);
        if (P.is_infinity()) return false;
        var W=PAIR192.G1mul(P,q);
        if (!W.is_infinity()) return false;
        return true;
    }
/* test G2 group membership */
    PAIR192.G2member=function(P)
    {
        var q = new ctx.BIG(0);
        q.rcopy(ctx.ROM_CURVE.CURVE_Order);
        if (P.is_infinity()) return false;
        var W=PAIR192.G2mul(P,q);
        if (!W.is_infinity()) return false;
        return true;
    }
/* test group membership - no longer needed */
/* Check that m!=1, conj(m)*m==1, and m.m^{p^8}=m^{p^4} */

    PAIR192.GTmember= function(m)
    {
        if (m.isunity()) return false;
        var r=new ctx.FP24(m);
        r.conj();
        r.mul(m);
        if (!r.isunity()) return false;

        var fa=new ctx.BIG(0); fa.rcopy(ctx.ROM_FIELD.Fra);
        var fb=new ctx.BIG(0); fb.rcopy(ctx.ROM_FIELD.Frb);
        var f=new ctx.FP2(fa,fb); 

        r.copy(m); r.frob(f,4); 
        var w=new ctx.FP24(r); w.frob(f,4); 
        w.mul(m);
        if (!w.equals(r)) return false;

        var q = new ctx.BIG(0);
        q.rcopy(ctx.ROM_CURVE.CURVE_Order);

        w.copy(m); 
        r.copy(PAIR192.GTpow(w,q));
        if (!r.isunity()) return false;
        return true;
    };


    return PAIR192;
};
