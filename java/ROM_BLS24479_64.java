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

/* Fixed Data in ROM - Field and Curve parameters */


package org.miracl.core.BLS24479;

public class ROM
{

// Base Bits= 56
	public static final long[] Modulus= {0x44C1674A06152BL,0xFFE2E82D30DAF8L,0x6F1C5CBDB6A642L,0x3220DF068A328BL,0xE09E1F24406187L,0xBA825079733568L,0x6E803F2E77E4C1L,0x3CCC5BA839AECL,0x555C0078L};
	public static final long[] ROI= {0x44C1674A06152AL,0xFFE2E82D30DAF8L,0x6F1C5CBDB6A642L,0x3220DF068A328BL,0xE09E1F24406187L,0xBA825079733568L,0x6E803F2E77E4C1L,0x3CCC5BA839AECL,0x555C0078L};
	public static final long[] R2modp= {0x6A4A1FE013DF5BL,0xE8E46D4D1BDE65L,0x1F841391F45C67L,0x9148A4516FB28L,0x4398524EDF4C88L,0x41C0E241B6DCE8L,0xE42C208C19411L,0xA7FE6FD73A7B1CL,0xFCCCA76L};
	public static final long MConst= 0xBD5D7D8095FE7DL;
    public static final long[] SQRTm3= {0x338CC191A91428L,0x747E3EE8B5998FL,0xF307D1E6911549L,0xF2991861BCA96BL,0x23CCFD4AF96A86L,0xF27F3D5CCDCB73L,0xF41800E24A1A2DL,0x3CAC5968136DBL,0x555C0078L};
	public static final long[] Fra= {0x5CA74ABBF96F1DL,0x1FF8BD0C6FFBADL,0x49E9E26237469CL,0x3CECA48407F8E5L,0x69D68FF59267B7L,0x5D199E33127CBDL,0xB97549184F313AL,0x4E77242DA52D8DL,0x4BBC87B9L};
	public static final long[] Frb= {0xE81A1C8E0CA60EL,0xDFEA2B20C0DF4AL,0x25327A5B7F5FA6L,0xF5343A828239A6L,0x76C78F2EADF9CFL,0x5D68B24660B8ABL,0xB50AF61628B387L,0xB555A18CDE6D5EL,0x99F78BEL};

	public static final int CURVE_B_I= 19;
	public static final int CURVE_Cof_I= 0;
	public static final long[] CURVE_B= {0x13L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L};
	public static final long[] CURVE_Order= {0x1A08FFF0000001L,0x1E7033FF551190L,0x6ADE7EE322DDAFL,0x848FC9D0CED13AL,0x50D81729CC224L,0x1F0F05B98BB44AL,0x10010010005A0L,0x0L,0x0L};
	public static final long[] CURVE_Gx= {0x6760F5EBE3CCD4L,0xEFE2DAED9F4564L,0x783F08EBA1FCC1L,0xC6F8D95AF88134L,0xDCA8D1AE2D8477L,0x9077586CEFE4BFL,0x8B7FEA5D99BC1DL,0x17CAF9486DE9E1L,0x1AB2BE34L};
	public static final long[] CURVE_Gy= {0xCBA5CAD21E5245L,0x6D6608C55DF6C4L,0xB3ED294F39746BL,0x145824920FF3C8L,0x63AA4FD63E5A64L,0x492A2BF79CE00FL,0x66A7A4529FF79AL,0x6C53E477B861CAL,0x47FCB70CL};

	public static final long[] CURVE_Bnx= {0x100020011FF80L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L};
	public static final long[] CURVE_Cof= {0x100020011FF7FL,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L};	
	//public static final long[] CURVE_Cof= {0xC1FFBFF9F415ABL,0x5556AAB7FFL,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L};
	public static final long[] CRu= {0xBC27146DD794A9L,0x3A30938AF33A43L,0xB112175223DDC6L,0x125CFBB4236DFBL,0x2358E379CE607L,0xD680C6EB20806EL,0x314C200860FF77L,0x3CBC5A88268E4L,0x555C0078L};
	public static final long[] CURVE_Pxaa= {0xE2935374E24678L,0xC34342582408BL,0xF765CCDEFC69EL,0xC33AAD2888D7F9L,0x7FD2458967473AL,0x52908ED55CBAB3L,0x786671EB14AB88L,0xA3EC96077958C8L,0x959DE53L};
	public static final long[] CURVE_Pxab= {0x7F9EBAFFB099B8L,0x3775A012A47038L,0x6B5D1B1FC23856L,0x7F0A26A730F9E3L,0x1C38F85DB2A5CAL,0x76A753E17E6926L,0x2D39D1BE5AD0F9L,0x31733DFC651E4CL,0x3B0DED08L};
	public static final long[] CURVE_Pxba= {0xA1CDE711AD15D3L,0x853178DF6E16EDL,0x64BF43EA3E09A1L,0x2D8CD6DE566B2FL,0xF21C26C74FDB8BL,0x47BCC89E3F6B1EL,0x3FE2103F329F00L,0x4E507AF2AA28C3L,0x3EC27FADL};
	public static final long[] CURVE_Pxbb= {0x7AB2875EE0F480L,0x4556E43D6C4B8CL,0xFB22DF80E1CB99L,0xF70FD0122F1FFDL,0xD5DB25698EF5EAL,0x4805CE1AF1BA3AL,0x1DA7CE2E465CB7L,0xCA0799F7E65855L,0xA5B38DBL};
	public static final long[] CURVE_Pyaa= {0x86499314781AA0L,0x609DA303B70AB1L,0xA52A6145FC44BBL,0x462E04C42A3124L,0xC383AE19AE68BBL,0xA1B34F6BE4FCADL,0x198F901AD0BF4L,0x736C094362CED0L,0x5057F35DL};
	public static final long[] CURVE_Pyab= {0xBBEC57EEAE08FAL,0x78774BAA5F96ADL,0x64CAF099A42CA0L,0xC89FBBCCF70478L,0x6B720FEF855245L,0x97F916376F7B3EL,0x60F5587B5DF7E1L,0x61EE89637816BDL,0x2CE2B496L};
	public static final long[] CURVE_Pyba= {0x730276A5F0CC41L,0xF89325530AA1F5L,0xD9CD879AF8A147L,0xEE53E8A9FE2880L,0x420F07D3715390L,0x4C15D519B71F3AL,0x1A39DD3CB5B9B1L,0x3EE631A6BE39F8L,0x18070466L};
	public static final long[] CURVE_Pybb= {0xF1B2E6515C1CAEL,0xD40D355B0988DCL,0xC243FDC38A7772L,0x5D338136B675CAL,0x164E8A1D72FCDFL,0xBBAE5CD0961ACL,0xD6D04691771EB1L,0xD9BDEC8B792840L,0x499D14EAL};
//	public static final long[][] CURVE_W= {{0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L},{0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L}};
//	public static final long[][][] CURVE_SB= {{{0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L},{0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L}},{{0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L},{0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L}}};
//	public static final long[][] CURVE_WB= {{0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L},{0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L},{0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L},{0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L}};
//	public static final long[][][] CURVE_BB= {{{0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L},{0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L},{0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L},{0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L}},{{0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L},{0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L},{0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L},{0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L}},{{0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L},{0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L},{0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L},{0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L}},{{0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L},{0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L},{0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L},{0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L}}};

}

