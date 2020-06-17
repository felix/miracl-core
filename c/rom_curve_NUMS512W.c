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
#include "arch.h"
#include "ecp_NUMS512W.h"

/*  NUMS 512-bit Curve - Weierstrass */

#if CHUNK==16

#error Not supported

#endif

#if CHUNK==32

const int CURVE_Cof_I_NUMS512W= 1;
const BIG_512_29 CURVE_Cof_NUMS512W= {0x1,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0};
const int CURVE_B_I_NUMS512W= 121243;
const BIG_512_29 CURVE_B_NUMS512W= {0x1D99B,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0};
const BIG_512_29 CURVE_Order_NUMS512W= {0x433555D,0x10A9F9C8,0x1F3490F3,0xD166CC0,0xBDC63B5,0xC76CBE8,0xC6D3F09,0x1F729CF0,0x1F5B3CA4,0x1FFFFFFF,0x1FFFFFFF,0x1FFFFFFF,0x1FFFFFFF,0x1FFFFFFF,0x1FFFFFFF,0x1FFFFFFF,0x1FFFFFFF,0x7FFFF};
const BIG_512_29 CURVE_Gx_NUMS512W= {0xCABAE57,0x4143CAC,0x1BD778B7,0x1AC026FA,0x15831D5,0x14312AB,0x167A4DE5,0xA20ED66,0x195021A1,0x129836CF,0x1141B830,0xA03ED0A,0xCAD83BB,0x1E9DA94C,0xDC00A80,0x1527B45,0x1447141D,0x1D601};
const BIG_512_29 CURVE_Gy_NUMS512W= {0x183527A6,0x1D043B01,0x1F43FA48,0x16B83C99,0x5602CF2,0x1420592D,0x17A70486,0x1B5161DD,0x14A28415,0x3DE8A78,0x3D2C983,0x17797719,0x197DBDEA,0x15D88025,0x1BBB718F,0xAD679C1,0x14CA29AD,0x4A1D2};
#endif

#if CHUNK==64

const int CURVE_Cof_I_NUMS512W= 1;
const BIG_512_56 CURVE_Cof_NUMS512W= {0x1L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L};
const int CURVE_B_I_NUMS512W= 121243;
const BIG_512_56 CURVE_B_NUMS512W= {0x1D99BL,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L,0x0L};
const BIG_512_56 CURVE_Order_NUMS512W= {0x153F390433555DL,0x8B36607CD243CEL,0xED97D0BDC63B56L,0x94E7831B4FC258L,0xFFFFFF5B3CA4FBL,0xFFFFFFFFFFFFFFL,0xFFFFFFFFFFFFFFL,0xFFFFFFFFFFFFFFL,0xFFFFFFFFFFFFFFL,0xFFL};
const BIG_512_56 CURVE_Gx_NUMS512W= {0x8287958CABAE57L,0x60137D6F5DE2DCL,0x86255615831D5DL,0x76B359E937942L,0x6D9F95021A151L,0xF6854506E0C253L,0x5298CAD83BB501L,0xDA2B7002A03D3BL,0xC03447141D0A93L,0x3AL};
const BIG_512_56 CURVE_Gy_NUMS512W= {0xA08760383527A6L,0x5C1E4CFD0FE923L,0x40B25A5602CF2BL,0x8B0EEDE9C121A8L,0xD14F14A28415DAL,0xBB8C8F4B260C7BL,0x4B97DBDEABBCL,0xCE0EEEDC63EBB1L,0x3A54CA29AD56B3L,0x94L};
#endif
