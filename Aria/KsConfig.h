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
 * @file	KsConfig.h
 * @brief	コンパイルなどの設定
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
/************************************************************************************************/
#ifndef __KSCONFIG_H__
#define __KSCONFIG_H__

/*===============================================================================================*/
/*                                 << インクルード >>                                             */
/*===============================================================================================*/

/*===============================================================================================*/
/*                                    << 定義 >>                                                 */
/*===============================================================================================*/

#define ksBUILD_STATIC	// プロジェクトで設定
//#define ksBUILD_DYNAMIC	// プロジェクトで設定
//#define ksENGINE_EXPORTS	// プロジェクトで設定

/* 出力形式 */
#ifdef ksBUILD_STATIC
    #define ksENGINE_API
    #define ksEXTERN
#else
    #ifdef ksENGINE_EXPORTS
        #define ksENGINE_API    __declspec( dllexport )
        #define ksEXTERN
    #else
        #define ksENGINE_API    __declspec( dllimport )
        #define ksEXTERN        extern
    #endif
#endif


#define ksCDECL __cdecl

#ifdef WIN32
    #include <vector>
    #include <map>
    #include <string>

    #ifdef _MSC_VER
        #pragma warning( disable : 4231 )
        #pragma warning( disable : 4251 )	/* テンプレートエクスポート時の警告		*/
        #pragma warning( disable : 4311 )	/* ポインタから整数値への変更				*/
        #pragma warning( disable : 4312 )	/* 整数値からポインタへの変更				*/
        #pragma warning( disable : 4333 )	/* 右シフトの回数が多すぎます。データが失われる可能性があります				*/
        #pragma warning( disable : 4661 )	/* 明示的なテンプレートのインスタンス生成要求に対して適切な定義がありません。 */
        #pragma warning( disable : 4819 )
        #pragma warning( disable : 4995 )
        #pragma warning( disable : 4996 )
    #endif
#endif

/*===============================================================================================*/
/*                                     << 宣言 >>                                                */
/*===============================================================================================*/


#endif	/* __KSCONFIG_H__ */


