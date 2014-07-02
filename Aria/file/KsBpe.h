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
 * @file	KsBpe.h
 * @brief	BPE(Byte Pair Encoding:バイト対符号化)圧縮
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
/************************************************************************************************/
#ifndef __KSBPE_H__
#define __KSBPE_H__

#include "KsCoreCommon.h"


ksNS_KS_BEGIN

/**
@class  CBPE
@brief  BPE圧縮クラス
@author IZAYA
*/
class CBPE
{
    private:
        //  member variable definitions
        enum
        {
            BPE_WORKBUFFERSIZE = 2048,
            BPE_PAIRBUFFERSIZE = 768,
        };

        KsInt32     m_BufSize;
        KsInt32     m_PairCnt;
        KsByte*     m_WorkBuf;
        KsByte*     m_PairBuf;

    public:
        //  prototype definitions(public member functions)
        /**
        @brief  コンストラクタ
        @author IZAYA
        */
        CBPE();

        /**
        @brief  デストラクタ
        @author IZAYA
        */
        ~CBPE();

        /**
        @brief  圧縮関数
        @author IZAYA
        @param  [out] pDest 演算結果を格納する配列アドレス
        @param  [in] pSrc 処理基となる配列アドレス
        @param  [in] SrcSize 処理基となる配列アドレスのサイズ
        @retval 成功 圧縮後のファイルサイズ  失敗　0

        @note   pDestをNULL(0)にすると、圧縮後のファイルサイズが取得可能です
        */
        KsULong Encode( void *pDest, void *pSrc, KsULong SrcSize );

        /**
        @brief  伸張関数
        @author IZAYA
        @param  [out] pDest 演算結果を格納する配列アドレス
        @param  [in] pSrc 処理基となる配列アドレス
        @param  [in] SrcSize 処理基となる配列アドレスのサイズ
        @retval 成功 圧縮前のファイルサイズ  失敗　0

        @note   pDestをNULL(0)にすると、圧縮前のファイルサイズが取得可能です
        */
        KsULong Decode( void *pDest, void *pSrc, KsULong SrcSize );

    private:
        //  prototype definitions(private member functions)
        /**
        @brief  BPE圧縮メインルーチン
        @author IZAYA
        @param  [in] BufSize バッファサイズ
        @retval 圧縮後のバッファサイズ
        */
        KsULong EncodeSub( int BufSize );
};

ksNS_KS_END

#endif	/* __KSBPE_H__ */


