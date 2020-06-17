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
#include "fp_BN254CX.h"

namespace BN254CX {

/* Curve BN254CX - Pairing friendly BN curve */

/* CertiVox BN curve/field  */

#if CHUNK==16

using namespace B256_13;

// Base Bits= 13
const BIG Modulus= {0x15B3,0xDA,0x1BD7,0xC47,0x1BE6,0x1F70,0x24,0x1DC3,0x1FD6,0x1921,0x19B4,0x14C6,0x1647,0x1EEF,0x16C2,0x541,0x870,0x0,0x0,0x48};
const BIG ROI= {0x15B2,0xDA,0x1BD7,0xC47,0x1BE6,0x1F70,0x24,0x1DC3,0x1FD6,0x1921,0x19B4,0x14C6,0x1647,0x1EEF,0x16C2,0x541,0x870,0x0,0x0,0x48};
const BIG R2modp= {0x1527,0x146B,0x12A7,0x1A60,0x1E0A,0x1382,0x2BC,0x1D3F,0xB30,0xA8,0xD19,0x11AB,0x1D40,0x1965,0xD6D,0x643,0x10FF,0x1BC7,0x1E61,0x31};
const BIG SQRTm3= {0x1C84,0x1EA4,0x100C,0x9FB,0x15AA,0x181A,0x10A8,0x4A6,0x418,0x1516,0x1A2A,0x225,0x1646,0x1EEF,0x1482,0x541,0x870,0x0,0x0,0x48};
const BIG CRu= {0x1C97,0x11A,0x5E5,0x126,0x31E,0x3AB,0x7BE,0xC8E,0x1DDF,0x205,0xFC5,0x1950,0x0,0x0,0x120,0x0,0x0,0x0,0x0,0x0};
const chunk MConst= 0x1E85;
const BIG Fra= {0xEA3,0xE40,0xCD5,0x1210,0x15BD,0x1C10,0x5CF,0x4DE,0x773,0x343,0x626,0x194E,0x18AA,0x10C5,0x12BF,0x2C,0x63A,0x17D,0x1642,0x26};
const BIG Frb= {0x710,0x129A,0xF01,0x1A37,0x628,0x360,0x1A55,0x18E4,0x1863,0x15DE,0x138E,0x1B78,0x1D9C,0xE29,0x403,0x515,0x236,0x1E83,0x9BD,0x21};


#endif

#if CHUNK==32

using namespace B256_28;

// Base Bits= 28
const BIG Modulus= {0xC1B55B3,0x6623EF5,0x93EE1BE,0xD6EE180,0x6D3243F,0x647A636,0xDB0BDDF,0x8702A0,0x4000000,0x2};
const BIG ROI= {0xC1B55B2,0x6623EF5,0x93EE1BE,0xD6EE180,0x6D3243F,0x647A636,0xDB0BDDF,0x8702A0,0x4000000,0x2};
const BIG R2modp= {0x8A0800A,0x466A061,0x43056A3,0x2B3A225,0x9C6600,0x148515B,0x6BDF50,0xEC9EA56,0xC992E66,0x1};
const BIG SQRTm3= {0x3D49C84,0xA4FDC03,0xA30355A,0x1825342,0x8AAA2C4,0x646112E,0xD20BDDF,0x8702A0,0x4000000,0x2};
const chunk MConst= 0x9789E85;
const BIG Fra= {0x5C80EA3,0xD908335,0x3F8215B,0x7326F17,0x8986867,0x8AACA71,0x4AFE18B,0xA63A016,0x359082F,0x1};
const BIG Frb= {0x6534710,0x8D1BBC0,0x546C062,0x63C7269,0xE3ABBD8,0xD9CDBC4,0x900DC53,0x623628A,0xA6F7D0,0x1};

#endif

#if CHUNK==64

using namespace B256_56;

// Base Bits= 56
const BIG Modulus= {0x6623EF5C1B55B3L,0xD6EE18093EE1BEL,0x647A6366D3243FL,0x8702A0DB0BDDFL,0x24000000L};
const BIG ROI= {0x6623EF5C1B55B2L,0xD6EE18093EE1BEL,0x647A6366D3243FL,0x8702A0DB0BDDFL,0x24000000L};
const BIG R2modp= {0x466A0618A0800AL,0x2B3A22543056A3L,0x148515B09C6600L,0xEC9EA5606BDF50L,0x1C992E66L};
const chunk MConst= 0x4E205BF9789E85L;
const BIG SQRTm3= {0x4L,0x60CL,0x3CF0FL,0x4000000126CD89L,0x25236482L};
const BIG Fra= {0xD9083355C80EA3L,0x7326F173F8215BL,0x8AACA718986867L,0xA63A0164AFE18BL,0x1359082FL};
const BIG Frb= {0x8D1BBC06534710L,0x63C7269546C062L,0xD9CDBC4E3ABBD8L,0x623628A900DC53L,0x10A6F7D0L};
#endif

}
