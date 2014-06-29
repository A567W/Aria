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
 * @file	KsMD5.h
 * @brief	MD5
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
/************************************************************************************************/
#ifndef __KSMD5_H__
#define __KSMD5_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                           */
/*==============================================================================================*/
#include "KsCoreCommon.h"

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/************************************************************************************************/
/**
 * @struct		KsMD5.h
 * @brief		MD5用コンテキスト
 * @author		A567W
 * @date		2005/10/17
 * @since		2005/10/17
 * @version		1.0.0
 * @note		なし
 */
/************************************************************************************************/
typedef struct _KsMD5Context
{
	KsUInt32			buf[ 4 ];
	KsUInt32			bits[ 2 ];
	KsUInt8			in[ 64 ];

}KsMD5Context;

/************************************************************************************************/
/**
 * MD5コンテキストの初期化
 * @param		pContext		コンテキスト
 */
/************************************************************************************************/
ksENGINE_API void KsMD5Init( KsMD5Context* pContext );

/************************************************************************************************/
/**
 * MD5コンテキストの更新処理
 * @param		pContext		コンテキスト
 * @param		buf				バッファ
 * @param		len				バッファサイズ
 */
/************************************************************************************************/
ksENGINE_API void KsMD5Update( KsMD5Context* pContext, const KsUInt8 *buf, KsUInt32 len );

/************************************************************************************************/
/**
 * MD5終了処理
 * @param		pContext		コンテキスト
 */
/************************************************************************************************/
ksENGINE_API void KsMD5Final( KsUInt8 digest[16], KsMD5Context* pContext );

/************************************************************************************************/
/**
 * MD5コンテキストの初期化
 * @param		pContext		コンテキスト
 */
/************************************************************************************************/
ksENGINE_API void KsMD5Transform( KsUInt32 buf[4], KsUInt32 in[16] );

/************************************************************************************************/
/**
 * MD5コンテキストの初期化
 * @param		pContext		コンテキスト
 */
/************************************************************************************************/
ksENGINE_API KsInt8* KsCryptMD5( const KsInt8* pw, const KsInt8* salt );

#endif /* __KSMD5_H__ */

