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

/**
 * @file config_curve.h
 * @author Mike Scott
 * @brief Config Curve  Header File
 *
 */

#ifndef CONFIG_CURVE_ZZZ_H
#define CONFIG_CURVE_ZZZ_H

#include"core.h"
#include"config_field_YYY.h"

// ECP stuff

#define CURVETYPE_ZZZ @CT@
#define CURVE_A_ZZZ @CA@
#define PAIRING_FRIENDLY_ZZZ @PF@
#define CURVE_SECURITY_ZZZ @CS@

#if PAIRING_FRIENDLY_ZZZ != NOT_PF
//#define USE_GLV_ZZZ     /**< Note this method is patented (GLV), so maybe you want to comment this out */
//#define USE_GS_G2_ZZZ /**< Well we didn't patent it :) But may be covered by GLV patent :( */
#define USE_GS_GT_ZZZ /**< Not patented, so probably OK to always use this */

#define POSITIVEX 0
#define NEGATIVEX 1

#define SEXTIC_TWIST_ZZZ @ST@
#define SIGN_OF_X_ZZZ @SX@

#define ATE_BITS_ZZZ @AB@
#define G2_TABLE_ZZZ @G2@

#endif

#if CURVE_SECURITY_ZZZ == 128
#define AESKEY_ZZZ 16 /**< Symmetric Key size - 128 bits */
#define HASH_TYPE_ZZZ SHA256  /**< Hash type */
#endif

#if CURVE_SECURITY_ZZZ == 192
#define AESKEY_ZZZ 24 /**< Symmetric Key size - 192 bits */
#define HASH_TYPE_ZZZ SHA384  /**< Hash type */
#endif

#if CURVE_SECURITY_ZZZ == 256
#define AESKEY_ZZZ 32 /**< Symmetric Key size - 256 bits */
#define HASH_TYPE_ZZZ SHA512  /**< Hash type */
#endif



#endif
