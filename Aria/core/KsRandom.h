/*************************************************************************************************/
/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2014 A567W
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 * 
 * @file	KsRandom.h
 * @brief	乱数発生（高速バージョン）
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
/************************************************************************************************/
#ifndef __KSRAND_H__
#define __KSRAND_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                           */
/*==============================================================================================*/
#include "KsCoreCommon.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * 乱数発生の種
 * @param	seed	乱数の種
 */
/************************************************************************************************/
ksENGINE_API void KsRandSeed( KsUInt32 seed );

/************************************************************************************************/
/**
 * 乱数発生
 * @return		0 <= return <= 65535 の乱数を返します
 */
/************************************************************************************************/
ksENGINE_API KsUInt32 KsRand();

/************************************************************************************************/
/**
 * 乱数発生
 * @return		0.0f <= return <= 1.0f の乱数を返します
 */
/************************************************************************************************/
ksENGINE_API KsReal KsRandF();

/************************************************************************************************/
/**
 * 乱数発生
 * @param	num		乱数範囲
 * @return			0 <= return <= num の乱数を返します
 */
/************************************************************************************************/
ksENGINE_API KsUInt32 KsRandX( KsUInt32 num );

ksNS_KS_END

#endif	/* __KSRAND_H__ */


