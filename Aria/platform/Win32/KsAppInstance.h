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
 * @file	KsAppInstance.h
 * @brief	ウインドウアプリケーションのインスタンスクラス
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
/************************************************************************************************/
#ifndef __KSAPPINSTANCE_H__
#define __KSAPPINSTANCE_H__

/*===============================================================================================*/
/*                                 << インクルード >>                                             */
/*===============================================================================================*/
#include "KsWindowsCommon.h"

/*===============================================================================================*/
/*                                     << 定義 >>                                                */
/*===============================================================================================*/
ksNS_KS_BEGIN

/*************************************************************************************************/
/**
 * @class	KsAppInstance
 * @brief	ウインドウアプリケーションのインスタンスクラス
 * @author  A567W
 * @since   2003/03/22
 * @version ----/--/--
 */
/*************************************************************************************************/
class ksENGINE_API KsAppInstance
{
	public:
		static HINSTANCE				m_hInstance;		/**< ウィンドウ生成のパラメータ	*/
		static HINSTANCE				m_hPrevInstance;	/**< ウィンドウ生成のパラメータ	*/
		static LPSTR					m_lpCmdLine;		/**< ウィンドウ生成のパラメータ	*/
		static KsInt32					m_nCmdShow;			/**< ウィンドウ生成のパラメータ	*/

		/**
		 * パラメータをセットする
		 */
		static void						setup( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, KsInt32 nCmdShow );

		/**
		 * デストラクタ
		 */
										~KsAppInstance(){}

	private:
		/**
		 * コンストラクタ
		 */
										KsAppInstance(){}
};

ksNS_KS_END


#endif	/* __KSAPPINSTANCE_H__ */

