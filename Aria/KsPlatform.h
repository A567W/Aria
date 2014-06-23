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
 * @file	KsPlatform.h
 * @brief	プラットフォームの設定
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
/************************************************************************************************/
#ifndef __KSPLATFORM_H__
#define __KSPLATFORM_H__

/*===============================================================================================*/
/*                                     << 定義 >>                                                */
/*===============================================================================================*/
#define ksPLATFORM_UNKNOWN				0
#define ksPLATFORM_WIN32				1
#define ksPLATFORM_ANDROID				2
#define ksPLATFORM_IOS					3

#if defined(WIN32) && defined(_WINDOWS)
	// win32
    #define ksPLATFORM_TARGET			ksPLATFORM_WIN32
#elif defined(ANDROID)
	// android
    #define ksPLATFORM_TARGET			ksPLATFORM_ANDROID
#elif defined(IPHONE)
	// iPhone
    #define ksPLATFORM_TARGET			ksPLATFORM_IOS
#else
	// unknown
    #define ksPLATFORM_TARGET			ksPLATFORM_UNKNOWN
#endif

/*===============================================================================================*/
/*								<< インクルードファイル >>											*/
/*===============================================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <tchar.h>
#include <string.h>
#include <stdarg.h>
#include <malloc.h>
#include <math.h>
#include <time.h>


#if defined(ksPLATFORM_WIN32)
#  include <crtdefs.h>
#endif // #if defined(ksPLATFORM_WIN32)

// C++11
// theading
#include <mutex>
#include <thread>
#include <future>

#endif	/* __KSPLATFORM_H__ */


