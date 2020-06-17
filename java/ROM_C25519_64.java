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


package org.miracl.core.C25519;

public class ROM
{

// Base Bits= 56
public static final long[] Modulus= {0xFFFFFFFFFFFFEDL,0xFFFFFFFFFFFFFFL,0xFFFFFFFFFFFFFFL,0xFFFFFFFFFFFFFFL,0x7FFFFFFFL};
public static final long[] ROI= {0xEE1B274A0EA0B0L,0x1806AD2FE478C4L,0x993DFBD7A72F43L,0x4FC1DF0B2B4D00L,0x2B832480L};
public static final long[] R2modp= {0xA4000000000000L,0x5L,0x0L,0x0L,0x0L};
public static final long MConst= 0x13L;

public static final int CURVE_Cof_I= 8;
public static final long[] CURVE_Cof= {0x8L,0x0L,0x0L,0x0L,0x0L};
public static final int CURVE_B_I= 0;
public static final long[] CURVE_B= {0x0L,0x0L,0x0L,0x0L,0x0L};
public static final long[] CURVE_Order= {0x12631A5CF5D3EDL,0xF9DEA2F79CD658L,0x14DEL,0x0L,0x10000000L};
public static final long[] CURVE_Gx= {0x9L,0x0L,0x0L,0x0L,0x0L};
public static final long[] CURVE_Gy= {0x0L,0x0L,0x0L,0x0L,0x0L};
}

