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

use crate::arch::Chunk;
use crate::fp512bn::big::NLEN;

// Base Bits= 29
pub const MODULUS: [Chunk; NLEN] = [
    0x2ADEF33, 0x7594049, 0x131919ED, 0x14AB9CBE, 0x16FE1916, 0x12EF5591, 0x2E39231, 0x3D597D3,
    0x55146CF, 0x88D877A, 0x102EF8F0, 0x1196A60F, 0x1C60BA1D, 0x1CF63F80, 0x1FFFFFFF, 0x1FFFFFFF,
    0x1FFFFFFF, 0x7FFFF,
];
pub const ROI: [Chunk; NLEN] = [
    0x2ADEF32, 0x7594049, 0x131919ED, 0x14AB9CBE, 0x16FE1916, 0x12EF5591, 0x2E39231, 0x3D597D3,
    0x55146CF, 0x88D877A, 0x102EF8F0, 0x1196A60F, 0x1C60BA1D, 0x1CF63F80, 0x1FFFFFFF, 0x1FFFFFFF,
    0x1FFFFFFF, 0x7FFFF,
];
pub const R2MODP: [Chunk; NLEN] = [
    0xFD68B47, 0xFCF5D2C, 0x437675A, 0x1BBC3FBF, 0x1411E413, 0x13453559, 0x10B5639, 0x1C34CE79,
    0x6D476BF, 0xFD05F2B, 0x15D17C28, 0x6C9F76E, 0x1C2375B3, 0x78CCE9B, 0x15F0AB33, 0x1960F32E,
    0x1A8D44E, 0x57A38,
];
pub const MCONST: Chunk = 0x1CCC5C05;
pub const SQRTM3:[Chunk;NLEN]=[0x3332330,0x2EB416F,0xAB7E1C3,0x1A5BD227,0xDC2F246,0x167768AE,0xF2DA0A,0x1E517201,0xCBD4F70,0x6E88A80,0x17226ED7,0x94B06CE,0xB44920B,0x1CF63E47,0x1FFFFFFF,0x1FFFFFFF,0x1FFFFFFF,0x7FFFF];
pub const CURVE_COF_I: isize = 1;
pub const CURVE_B_I: isize = 3;
pub const CURVE_B: [Chunk; NLEN] = [
    0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
];
pub const CURVE_ORDER: [Chunk; NLEN] = [
    0x119A09ED, 0x153252FA, 0x1E68AD01, 0x627C09, 0x79A34A1, 0x12EF5593, 0x2E39231, 0x3D597D3,
    0x45146CF, 0x88D877A, 0x102EF8F0, 0x1196A60F, 0x1C60BA1D, 0x1CF63F80, 0x1FFFFFFF, 0x1FFFFFFF,
    0x1FFFFFFF, 0x7FFFF,
];
pub const CURVE_GX: [Chunk; NLEN] = [
    0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
];
pub const CURVE_GY: [Chunk; NLEN] = [
    0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
];

pub const FRA: [Chunk; NLEN] = [
    0x14B73AB2, 0x4B0BD8F, 0xABB47D, 0x2A29EC4, 0x18681E17, 0x104069DE, 0x12EED67D, 0x1553D0A5,
    0x398E9F8, 0x7971034, 0xAC9AF23, 0x52DEF23, 0x14EA18A5, 0x1463E345, 0x6DE465A, 0x17F212B4,
    0x1AA9CF5B, 0xF7B8,
];
pub const FRB: [Chunk; NLEN] = [
    0xDF6B481, 0x2A882B9, 0x126D6570, 0x1208FDFA, 0x1E95FAFF, 0x2AEEBB2, 0xFF4BBB4, 0xE81C72D,
    0x1B85CD6, 0xF67746, 0x56549CD, 0xC68B6EC, 0x776A178, 0x8925C3B, 0x1921B9A5, 0x80DED4B,
    0x55630A4, 0x70847,
];
pub const CURVE_BNX: [Chunk; NLEN] = [
    0x1E1BD80F, 0x59835DA, 0xC3DFC04, 0x5EB8061, 0x688, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0,
];
pub const CURVE_COF: [Chunk; NLEN] = [
    0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
];
pub const CRU: [Chunk; NLEN] = [
    0x1C79298A, 0x1838B104, 0x2C5F052, 0x1DCCF337, 0x6092AEC, 0x4B35F29, 0x1EB361E, 0x11384EA,
    0x3074B20, 0x17BB08FD, 0x3A8B3E3, 0xD70D66F, 0x3D2A614, 0x1CF63EE4, 0x1FFFFFFF, 0x1FFFFFFF,
    0x1FFFFFFF, 0x7FFFF,
];
pub const CURVE_PXA: [Chunk; NLEN] = [
    0xDB646B5, 0x183D4B70, 0x1CBFFA3, 0x11F0E632, 0x1C78F221, 0x1F10DE5D, 0x171B715E, 0xF0C6A29,
    0x10B02453, 0xBE63C66, 0xE6D5F69, 0x166B1E1B, 0x4BBBD29, 0x179E750F, 0x6E9D04, 0xC912B10,
    0x1339E138, 0x1D8B2,
];
pub const CURVE_PXB: [Chunk; NLEN] = [
    0x1A8AE0E9, 0xDAE5F7E, 0x22446CF, 0x1948239B, 0x15ADCE40, 0xB709C1E, 0x18357943, 0xE50AA4D,
    0x19781E22, 0x12B35CA6, 0x11DAA2C0, 0x18D8DDE4, 0x5EA656D, 0x15F45A41, 0xD311A02, 0xCFCD913,
    0x13CBF850, 0x240E0,
];
pub const CURVE_PYA: [Chunk; NLEN] = [
    0xDDE67A1, 0x12401895, 0x17BEE178, 0x142F5AC2, 0xB7BC5CD, 0x92A1404, 0x1A3B748C, 0x17BD82A7,
    0x14B6CD18, 0xAC34CE, 0x1740FB97, 0x1ECC15F9, 0x17085B1D, 0x1D1BA793, 0x1BD6AC32, 0x18F70525,
    0xC84C827, 0x3780F,
];
pub const CURVE_PYB: [Chunk; NLEN] = [
    0x84F8E8B, 0xC5B8C36, 0xFDD85A1, 0xB84449, 0x19C08DFF, 0x56BF713, 0x1C5290C4, 0x187C5CA0,
    0x1DA2897F, 0x24B0CA0, 0x326D8F4, 0x2310CF6, 0x1021438C, 0xFBAEC8F, 0xD9030C5, 0x1CF06358,
    0x1CEC8B04, 0x28D1D,
];
pub const CURVE_W: [[Chunk; NLEN]; 2] = [
    [
        0x9834583, 0x887C4BA, 0x5A85CFC, 0xBF7223A, 0xF63FE96, 0x1FFFFFFE, 0x1FFFFFFF, 0x1FFFFFFF,
        0xFFFFFF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    ],
    [
        0x1C37B01F, 0xB306BB5, 0x187BF808, 0xBD700C2, 0xD10, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
        0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    ],
];
pub const CURVE_SB: [[[Chunk; NLEN]; 2]; 2] = [
    [
        [
            0xD4B9564, 0x1D575904, 0xD2C64F3, 0x202177, 0xF63F186, 0x1FFFFFFE, 0x1FFFFFFF,
            0x1FFFFFFF, 0xFFFFFF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
        ],
        [
            0x156259CE, 0xA01E744, 0x5ECB4F9, 0x148B7B47, 0x79A2790, 0x12EF5593, 0x2E39231,
            0x3D597D3, 0x45146CF, 0x88D877A, 0x102EF8F0, 0x1196A60F, 0x1C60BA1D, 0x1CF63F80,
            0x1FFFFFFF, 0x1FFFFFFF, 0x1FFFFFFF, 0x7FFFF,
        ],
    ],
    [
        [
            0x1C37B01F, 0xB306BB5, 0x187BF808, 0xBD700C2, 0xD10, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
            0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
        ],
        [
            0x9834583, 0x887C4BA, 0x5A85CFC, 0xBF7223A, 0xF63FE96, 0x1FFFFFFE, 0x1FFFFFFF,
            0x1FFFFFFF, 0xFFFFFF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
        ],
    ],
];
pub const CURVE_WB: [[Chunk; NLEN]; 4] = [
    [
        0x155A29F0, 0x16D59B55, 0xF4C305, 0x18858C0B, 0x5215FBF, 0xAAAAAAA, 0x15555555, 0xAAAAAAA,
        0x555555, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    ],
    [
        0x2355D4B, 0x1758095D, 0x1FE13C5F, 0x41F83FA, 0xBB5E5CF, 0x97D4EF1, 0xB503D62, 0x172C0C9B,
        0x16315274, 0x15E1A9A8, 0x859835D, 0x2C3DFC0, 0x105EB806, 0x68, 0x0, 0x0, 0x0, 0x0,
    ],
    [
        0x289AAD, 0x1E781F9C, 0x60F9C31, 0x1505822E, 0x15DAF62B, 0x4BEA778, 0x15A81EB1, 0xB96064D,
        0xB18A93A, 0x1AF0D4D4, 0x42CC1AE, 0x161EFE0, 0x82F5C03, 0x34, 0x0, 0x0, 0x0, 0x0,
    ],
    [
        0x192279D1, 0xBA52F9F, 0x878CAFD, 0xCAE8B48, 0x52152AF, 0xAAAAAAA, 0x15555555, 0xAAAAAAA,
        0x555555, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    ],
];
pub const CURVE_BB: [[[Chunk; NLEN]; 4]; 4] = [
    [
        [
            0x1E1BD810, 0x59835DA, 0xC3DFC04, 0x5EB8061, 0x688, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
            0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
        ],
        [
            0x1E1BD80F, 0x59835DA, 0xC3DFC04, 0x5EB8061, 0x688, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
            0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
        ],
        [
            0x1E1BD80F, 0x59835DA, 0xC3DFC04, 0x5EB8061, 0x688, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
            0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
        ],
        [
            0x156259CF, 0xA01E744, 0x5ECB4F9, 0x148B7B47, 0x79A2790, 0x12EF5593, 0x2E39231,
            0x3D597D3, 0x45146CF, 0x88D877A, 0x102EF8F0, 0x1196A60F, 0x1C60BA1D, 0x1CF63F80,
            0x1FFFFFFF, 0x1FFFFFFF, 0x1FFFFFFF, 0x7FFFF,
        ],
    ],
    [
        [
            0x1C37B01F, 0xB306BB5, 0x187BF808, 0xBD700C2, 0xD10, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
            0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
        ],
        [
            0x137E31DE, 0xF9A1D1F, 0x122AB0FD, 0x1A76FBA8, 0x79A2E18, 0x12EF5593, 0x2E39231,
            0x3D597D3, 0x45146CF, 0x88D877A, 0x102EF8F0, 0x1196A60F, 0x1C60BA1D, 0x1CF63F80,
            0x1FFFFFFF, 0x1FFFFFFF, 0x1FFFFFFF, 0x7FFFF,
        ],
        [
            0x137E31DD, 0xF9A1D1F, 0x122AB0FD, 0x1A76FBA8, 0x79A2E18, 0x12EF5593, 0x2E39231,
            0x3D597D3, 0x45146CF, 0x88D877A, 0x102EF8F0, 0x1196A60F, 0x1C60BA1D, 0x1CF63F80,
            0x1FFFFFFF, 0x1FFFFFFF, 0x1FFFFFFF, 0x7FFFF,
        ],
        [
            0x137E31DE, 0xF9A1D1F, 0x122AB0FD, 0x1A76FBA8, 0x79A2E18, 0x12EF5593, 0x2E39231,
            0x3D597D3, 0x45146CF, 0x88D877A, 0x102EF8F0, 0x1196A60F, 0x1C60BA1D, 0x1CF63F80,
            0x1FFFFFFF, 0x1FFFFFFF, 0x1FFFFFFF, 0x7FFFF,
        ],
    ],
    [
        [
            0x1C37B01E, 0xB306BB5, 0x187BF808, 0xBD700C2, 0xD10, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
            0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
        ],
        [
            0x1C37B01F, 0xB306BB5, 0x187BF808, 0xBD700C2, 0xD10, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
            0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
        ],
        [
            0x1C37B01F, 0xB306BB5, 0x187BF808, 0xBD700C2, 0xD10, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
            0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
        ],
        [
            0x1C37B01F, 0xB306BB5, 0x187BF808, 0xBD700C2, 0xD10, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
            0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
        ],
    ],
    [
        [
            0x137E31DF, 0xF9A1D1F, 0x122AB0FD, 0x1A76FBA8, 0x79A2E18, 0x12EF5593, 0x2E39231,
            0x3D597D3, 0x45146CF, 0x88D877A, 0x102EF8F0, 0x1196A60F, 0x1C60BA1D, 0x1CF63F80,
            0x1FFFFFFF, 0x1FFFFFFF, 0x1FFFFFFF, 0x7FFFF,
        ],
        [
            0x192AA9AF, 0x1ED17B8E, 0xD70BCF0, 0x8B47A84, 0x79A1A80, 0x12EF5593, 0x2E39231,
            0x3D597D3, 0x45146CF, 0x88D877A, 0x102EF8F0, 0x1196A60F, 0x1C60BA1D, 0x1CF63F80,
            0x1FFFFFFF, 0x1FFFFFFF, 0x1FFFFFFF, 0x7FFFF,
        ],
        [
            0x1C37B01D, 0xB306BB5, 0x187BF808, 0xBD700C2, 0xD10, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
            0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
        ],
        [
            0x137E31DF, 0xF9A1D1F, 0x122AB0FD, 0x1A76FBA8, 0x79A2E18, 0x12EF5593, 0x2E39231,
            0x3D597D3, 0x45146CF, 0x88D877A, 0x102EF8F0, 0x1196A60F, 0x1C60BA1D, 0x1CF63F80,
            0x1FFFFFFF, 0x1FFFFFFF, 0x1FFFFFFF, 0x7FFFF,
        ],
    ],
];

pub const USE_GLV: bool = true;
pub const USE_GS_G2: bool = true;
pub const USE_GS_GT: bool = true;
pub const GT_STRONG: bool = false;
