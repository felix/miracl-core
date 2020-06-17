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
use crate::ed25519::big::NLEN;

// Base Bits= 29
// Curve25519 Modulus
pub const MODULUS: [Chunk; NLEN] = [
    0x1FFFFFED, 0x1FFFFFFF, 0x1FFFFFFF, 0x1FFFFFFF, 0x1FFFFFFF, 0x1FFFFFFF, 0x1FFFFFFF, 0x1FFFFFFF,
    0x7FFFFF,
];
pub const ROI:[Chunk;NLEN]=[0xA0EA0B0,0x770D93A,0xBF91E31,0x6300D5A,0x1D7A72F4,0x4C9EFD,0x1C2CAD34,0x1009F83B,0x2B8324];
pub const R2MODP: [Chunk; NLEN] = [0x169000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0];
pub const MCONST: Chunk = 0x13;

// Ed25519 Curve
pub const CURVE_COF_I: isize = 8;
pub const CURVE_B_I: isize = 0;
pub const CURVE_COF: [Chunk; NLEN] = [0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0];
pub const CURVE_B: [Chunk; NLEN] = [
    0x135978A3, 0xF5A6E50, 0x10762ADD, 0x149A82, 0x1E898007, 0x3CBBBC, 0x19CE331D, 0x1DC56DFF,
    0x52036C,
];
pub const CURVE_ORDER: [Chunk; NLEN] = [
    0x1CF5D3ED, 0x9318D2, 0x1DE73596, 0x1DF3BD45, 0x14D, 0x0, 0x0, 0x0, 0x100000,
];
pub const CURVE_GX: [Chunk; NLEN] = [
    0xF25D51A, 0xAB16B04, 0x969ECB2, 0x198EC12A, 0xDC5C692, 0x1118FEEB, 0xFFB0293, 0x1A79ADCA,
    0x216936,
];
pub const CURVE_GY: [Chunk; NLEN] = [
    0x6666658, 0x13333333, 0x19999999, 0xCCCCCCC, 0x6666666, 0x13333333, 0x19999999, 0xCCCCCCC,
    0x666666,
];
