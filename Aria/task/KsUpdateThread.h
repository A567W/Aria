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
 * @file	KsUpdateThread.h
 * @brief	更新スレッド処理
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/
#ifndef __KSUPDATETHREAD_H__
#define __KSUPDATETHREAD_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsTaskCommon.h"
#include "KsUpdateList.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/*************************************************************************************************/
/**
 * @class	KsUpdateThread
 * @brief	更新スレッド処理
 * @author	A567W
 */
/*************************************************************************************************/
class ksENGINE_API KsUpdateThread
{
	public:
		/**
		 * コンストラクタ
		 * @param	threadNo			更新スレッド番号
		 * @param	numOrder			更新オーダー数
		 * @param	numObject			更新オブジェクト数
		 */
										KsUpdateThread( KsUInt32 threadNo, KsUInt32 numOrder, KsUInt32 numObject );

		/**
		 * デストラクタ
		 */
		virtual							~KsUpdateThread();

		/**
		 * 更新スレッド番号を取得する
		 * @return		更新スレッド番号
		 */
		KsUInt32						getThreadNo() const { return m_threadNo; }

	protected:
		KsUInt32						m_threadNo;		/**< 更新スレッド番号		*/
		//KsArray<KsUpdateList>			m_updates;		/**< 更新オブジェクト配列 */
};

ksNS_KS_END

#endif /* __KSUPDATETHREAD_H__ */

