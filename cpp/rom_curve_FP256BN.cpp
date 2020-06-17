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
#include "ecp_FP256BN.h"

namespace FP256BN {

/* Curve BN254 - Pairing friendly BN curve */

#if CHUNK==16

#error Not supported

#endif

#if CHUNK==32

using namespace B256_28;

const int CURVE_Cof_I=1;
const int CURVE_B_I= 3;
const BIG CURVE_B= {0x3,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0};
const BIG CURVE_Order= {0x10B500D,0x2D536CD,0x9921AF6,0x65FB129,0x49E0CDC,0x5EEE71A,0xD46E5F2,0xFFFCF0C,0xFFFFFFF,0xF};
const BIG CURVE_Gx= {0x1,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0};
const BIG CURVE_Gy= {0x2,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0};

const BIG CURVE_Bnx= {0xB0A801,0x82F5C03,0x68,0x0,0x0,0x0,0x0,0x0,0x0,0x0};
const BIG CURVE_Cof= {0x1,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0};

const BIG CURVE_Pxa= {0x9C09EFB,0x2616B68,0xF843CD2,0x539A12B,0x13ACE1C,0x577C289,0x28560F,0xB4C96C2,0xE0C3350,0xF};
const BIG CURVE_Pxb= {0x37E6A2B,0x69ED34A,0x3589D2,0x78E287D,0x3B924DD,0xC637D81,0x4DB5AE1,0x738AC05,0xEA66057,0x4};
const BIG CURVE_Pya= {0xEDC27FF,0x9B481B,0x15848E9,0x24758D6,0xE51EFCB,0x75124E3,0x376770D,0xC542A3B,0x2046E7,0x7};
const BIG CURVE_Pyb= {0xAAD049B,0x1281114,0xA98B3E0,0xBE80821,0x29F8B4C,0x49297EB,0x42EEA6,0xD388C29,0x554E3BC,0x0};
const BIG CURVE_W[2]= {{0xB054003,0xF0036E1,0xE78663A,0xFFFFFFF,0xFFFF,0x0,0x0,0x0,0x0,0x0},{0x1615001,0x5EB806,0xD1,0x0,0x0,0x0,0x0,0x0,0x0,0x0}};
const BIG CURVE_SB[2][2]= {{{0xC669004,0xF5EEEE7,0xE78670B,0xFFFFFFF,0xFFFF,0x0,0x0,0x0,0x0,0x0},{0x1615001,0x5EB806,0xD1,0x0,0x0,0x0,0x0,0x0,0x0,0x0}},{{0x1615001,0x5EB806,0xD1,0x0,0x0,0x0,0x0,0x0,0x0,0x0},{0x606100A,0x3D4FFEB,0xB19B4BB,0x65FB129,0x49D0CDC,0x5EEE71A,0xD46E5F2,0xFFFCF0C,0xFFFFFFF,0xF}}};
const BIG CURVE_WB[4]= {{0xD30A800,0x20678F0,0x4D2CC10,0x5555555,0x5555,0x0,0x0,0x0,0x0,0x0},{0xD7DC805,0xD6764C0,0xBC3AD1A,0x8FBEA10,0x4467DE,0x8061601,0xD105EB,0x0,0x0,0x0},{0xF173803,0xACB6061,0x5E1D6C1,0x47DF508,0x82233EF,0xC030B00,0x6882F5,0x0,0x0,0x0},{0xE91F801,0x26530F6,0x4D2CCE1,0x5555555,0x5555,0x0,0x0,0x0,0x0,0x0}};
const BIG CURVE_BB[4][4]= {{{0x5AA80D,0xAA5DACA,0x9921A8D,0x65FB129,0x49E0CDC,0x5EEE71A,0xD46E5F2,0xFFFCF0C,0xFFFFFFF,0xF},
                                           {0x5AA80C,0xAA5DACA,0x9921A8D,0x65FB129,0x49E0CDC,0x5EEE71A,0xD46E5F2,0xFFFCF0C,0xFFFFFFF,0xF},
	                                       {0x5AA80C,0xAA5DACA,0x9921A8D,0x65FB129,0x49E0CDC,0x5EEE71A,0xD46E5F2,0xFFFCF0C,0xFFFFFFF,0xF},
	                                       {0x1615002,0x5EB806,0xD1,0x0,0x0,0x0,0x0,0x0,0x0,0x0}},
	                                       {{0x1615001,0x5EB806,0xD1,0x0,0x0,0x0,0x0,0x0,0x0,0x0},
	                                        {0x5AA80C,0xAA5DACA,0x9921A8D,0x65FB129,0x49E0CDC,0x5EEE71A,0xD46E5F2,0xFFFCF0C,0xFFFFFFF,0xF},
	                                        {0x5AA80D,0xAA5DACA,0x9921A8D,0x65FB129,0x49E0CDC,0x5EEE71A,0xD46E5F2,0xFFFCF0C,0xFFFFFFF,0xF},
	                                        {0x5AA80C,0xAA5DACA,0x9921A8D,0x65FB129,0x49E0CDC,0x5EEE71A,0xD46E5F2,0xFFFCF0C,0xFFFFFFF,0xF}},
	                                        {{0x1615002,0x5EB806,0xD1,0x0,0x0,0x0,0x0,0x0,0x0,0x0},
	                                         {0x1615001,0x5EB806,0xD1,0x0,0x0,0x0,0x0,0x0,0x0,0x0},
	                                         {0x1615001,0x5EB806,0xD1,0x0,0x0,0x0,0x0,0x0,0x0,0x0},
	                                         {0x1615001,0x5EB806,0xD1,0x0,0x0,0x0,0x0,0x0,0x0,0x0}},
	                                         {{0xB0A802,0x82F5C03,0x68,0x0,0x0,0x0,0x0,0x0,0x0,0x0},
	                                          {0x2C2A002,0xBD700C,0x1A2,0x0,0x0,0x0,0x0,0x0,0x0,0x0},
	                                          {0xFAA000A,0x2767EC6,0x9921A25,0x65FB129,0x49E0CDC,0x5EEE71A,0xD46E5F2,0xFFFCF0C,0xFFFFFFF,0xF},
	                                          {0xB0A802,0x82F5C03,0x68,0x0,0x0,0x0,0x0,0x0,0x0,0x0}}};




#endif

#if CHUNK==64

using namespace B256_56;

const int CURVE_Cof_I=1;
const int CURVE_B_I= 3;
const BIG CURVE_B= {0x3L,0x0L,0x0L,0x0L,0x0L};
const BIG CURVE_Order= {0x2D536CD10B500DL,0x65FB1299921AF6L,0x5EEE71A49E0CDCL,0xFFFCF0CD46E5F2L,0xFFFFFFFFL};
const BIG CURVE_Gx= {0x1L,0x0L,0x0L,0x0L,0x0L};
const BIG CURVE_Gy= {0x2L,0x0L,0x0L,0x0L,0x0L};

const BIG CURVE_Bnx= {0x82F5C030B0A801L,0x68L,0x0L,0x0L,0x0L};
const BIG CURVE_Cof= {0x1L,0x0L,0x0L,0x0L,0x0L};

const BIG CURVE_Pxa= {0x2616B689C09EFBL,0x539A12BF843CD2L,0x577C28913ACE1CL,0xB4C96C2028560FL,0xFE0C3350L};
const BIG CURVE_Pxb= {0x69ED34A37E6A2BL,0x78E287D03589D2L,0xC637D813B924DDL,0x738AC054DB5AE1L,0x4EA66057L};
const BIG CURVE_Pya= {0x9B481BEDC27FFL,0x24758D615848E9L,0x75124E3E51EFCBL,0xC542A3B376770DL,0x702046E7L};
const BIG CURVE_Pyb= {0x1281114AAD049BL,0xBE80821A98B3E0L,0x49297EB29F8B4CL,0xD388C29042EEA6L,0x554E3BCL};
const BIG CURVE_W[2]= {{0xF0036E1B054003L,0xFFFFFFFE78663AL,0xFFFFL,0x0L,0x0L},{0x5EB8061615001L,0xD1L,0x0L,0x0L,0x0L}};
const BIG CURVE_SB[2][2]= {{{0xF5EEEE7C669004L,0xFFFFFFFE78670BL,0xFFFFL,0x0L,0x0L},{0x5EB8061615001L,0xD1L,0x0L,0x0L,0x0L}},{{0x5EB8061615001L,0xD1L,0x0L,0x0L,0x0L},{0x3D4FFEB606100AL,0x65FB129B19B4BBL,0x5EEE71A49D0CDCL,0xFFFCF0CD46E5F2L,0xFFFFFFFFL}}};
const BIG CURVE_WB[4]= {{0x20678F0D30A800L,0x55555554D2CC10L,0x5555L,0x0L,0x0L},{0xD6764C0D7DC805L,0x8FBEA10BC3AD1AL,0x806160104467DEL,0xD105EBL,0x0L},{0xACB6061F173803L,0x47DF5085E1D6C1L,0xC030B0082233EFL,0x6882F5L,0x0L},{0x26530F6E91F801L,0x55555554D2CCE1L,0x5555L,0x0L,0x0L}};
const BIG CURVE_BB[4][4]= {{{0xAA5DACA05AA80DL,0x65FB1299921A8DL,0x5EEE71A49E0CDCL,0xFFFCF0CD46E5F2L,0xFFFFFFFFL},{0xAA5DACA05AA80CL,0x65FB1299921A8DL,0x5EEE71A49E0CDCL,0xFFFCF0CD46E5F2L,0xFFFFFFFFL},{0xAA5DACA05AA80CL,0x65FB1299921A8DL,0x5EEE71A49E0CDCL,0xFFFCF0CD46E5F2L,0xFFFFFFFFL},{0x5EB8061615002L,0xD1L,0x0L,0x0L,0x0L}},{{0x5EB8061615001L,0xD1L,0x0L,0x0L,0x0L},{0xAA5DACA05AA80CL,0x65FB1299921A8DL,0x5EEE71A49E0CDCL,0xFFFCF0CD46E5F2L,0xFFFFFFFFL},{0xAA5DACA05AA80DL,0x65FB1299921A8DL,0x5EEE71A49E0CDCL,0xFFFCF0CD46E5F2L,0xFFFFFFFFL},{0xAA5DACA05AA80CL,0x65FB1299921A8DL,0x5EEE71A49E0CDCL,0xFFFCF0CD46E5F2L,0xFFFFFFFFL}},{{0x5EB8061615002L,0xD1L,0x0L,0x0L,0x0L},{0x5EB8061615001L,0xD1L,0x0L,0x0L,0x0L},{0x5EB8061615001L,0xD1L,0x0L,0x0L,0x0L},{0x5EB8061615001L,0xD1L,0x0L,0x0L,0x0L}},{{0x82F5C030B0A802L,0x68L,0x0L,0x0L,0x0L},{0xBD700C2C2A002L,0x1A2L,0x0L,0x0L,0x0L},{0x2767EC6FAA000AL,0x65FB1299921A25L,0x5EEE71A49E0CDCL,0xFFFCF0CD46E5F2L,0xFFFFFFFFL},{0x82F5C030B0A802L,0x68L,0x0L,0x0L,0x0L}}};



#endif

}
