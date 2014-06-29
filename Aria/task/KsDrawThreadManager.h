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
 * @file	KsDrawThreadManager.h
 * @brief	描画スレッド管理処理
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/
#ifndef __KSUPDATETHREADMANAGER_H__
#define __KSUPDATETHREADMANAGER_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsTaskCommon.h"
#include "KsDrawThread.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/*************************************************************************************************/
/**
 * @class	KsDrawThreadManager
 * @brief	描画スレッド管理
 * @author	A567W
 */
/*************************************************************************************************/
class ksENGINE_API KsDrawThreadManager
{
	public:
		/**
		 * コンストラクタ
		 * @param	numThread			描画スレッド数
		 * @param	numOrder			描画オーダー数
		 * @param	numObject			描画オブジェクト数
		 * @param	pCpuTbl				描画CPUテーブル
		 */
										KsDrawThreadManager( KsUInt32 numThread, KsUInt32 numOrder, KsUInt32 numObject, KsUInt32* pCpuTbl );

		/**
		 * デストラクタ
		 */
		virtual							~KsDrawThreadManager();

	protected:
		KsUInt32						m_numThread;	/**< 描画スレッド番号		*/
		KsArray<KsDrawThread*>			m_pThreads;		/**< 描画オブジェクト		*/
};

ksNS_KS_END

#endif /* __KSUPDATETHREADMANAGER_H__ */

