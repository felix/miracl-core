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
#include "ecp_SECP160R1.h"

/* Curve SECP160R1 */

#if CHUNK==16

// Base Bits= 13

const int CURVE_Cof_I_SECP160R1= 1;
const BIG_160_13 CURVE_Cof_SECP160R1= {0x1,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0};
const int CURVE_B_I_SECP160R1= 0;
const BIG_160_13 CURVE_B_SECP160R1= {0x1A45,0xB2F,0xB71,0x9A9,0x181D,0x1C4F,0x16B3,0x116C,0x1D7A,0x2A5,0xFBF,0x192F,0x1};
const BIG_160_13 CURVE_Order_SECP160R1= {0x257,0x13A9,0x14F2,0xF5D,0xF92,0x1A64,0x7,0x0,0x0,0x0,0x0,0x0,0x10};
const BIG_160_13 CURVE_Gx_SECP160R1= {0x1C82,0x1E5F,0xE44,0x717,0x168C,0x14C4,0x1991,0x508,0x1573,0x477,0xD5A,0x152D,0x4};
const BIG_160_13 CURVE_Gy_SECP160R1= {0x1B32,0x162F,0xDDE,0x6A2,0x42,0x489,0x773,0xFAB,0x894,0x98B,0xA15,0x74C,0x2};

#endif

#if CHUNK==32

// Base Bits= 29

const int CURVE_Cof_I_SECP160R1= 1;
const BIG_160_29 CURVE_Cof_SECP160R1= {0x1,0x0,0x0,0x0,0x0,0x0};
const int CURVE_B_I_SECP160R1= 0;
const BIG_160_29 CURVE_B_SECP160R1= {0x565FA45,0xEA6A56E,0xB3E27E0,0x1AF516CB,0x1BEFC54B,0xE4B};
const BIG_160_29 CURVE_Order_SECP160R1= {0xA752257,0x93D769E,0x7D323E,0x0,0x0,0x8000};
const BIG_160_29 CURVE_Gx_SECP160R1= {0x13CBFC82,0x61C5DC8,0x191A625A,0xAE6508C,0xB5688EF,0x254B};
const BIG_160_29 CURVE_Gy_SECP160R1= {0x1AC5FB32,0x11A89BB,0x17324481,0x1128FAB3,0x2855316,0x11D3};

#endif

#if CHUNK==64

// Base Bits= 56

const int CURVE_A_SECP160R1= -3;
const int CURVE_Cof_I_SECP160R1= 1;
const BIG_160_56 CURVE_Cof_SECP160R1= {0x1L,0x0L,0x0L};
const int CURVE_B_I_SECP160R1= 0;
const BIG_160_56 CURVE_B_SECP160R1= {0xD4D4ADC565FA45L,0x7A8B65ACF89F81L,0x1C97BEFC54BDL};
const BIG_160_56 CURVE_Order_SECP160R1= {0x27AED3CA752257L,0x1F4C8F9L,0x1000000000000L};
const BIG_160_56 CURVE_Gx_SECP160R1= {0xC38BB913CBFC82L,0x73284664698968L,0x4A96B5688EF5L};
const BIG_160_56 CURVE_Gy_SECP160R1= {0x2351377AC5FB32L,0x947D59DCC91204L,0x23A628553168L};

#endif

