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
 * @file	KsEvent.h
 * @brief	スレッドイベント
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/
#ifndef __KSEVENT_H__
#define __KSEVENT_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsThreadCommon.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class		KsEvent
 * @brief		スレッドイベント操作
 * @author		A567W
 * @date		2004/03/30
 */
/************************************************************************************************/
class ksENGINE_API KsEvent
{
	public:
		/**
		 * コンストラクタ
		 */
                        KsEvent();

		/**
		 * デストラクタ
		 */
                        ~KsEvent();

        /**
         * イベントオブジェクトをシグナル状態にする。
         * @param	hEvent		イベントオブジェクトを示すハンドル。
         * @retval	ksTRUE		成功
         * @retval	ksFALSE		失敗
         */
        KsBool          signale();

        /**
         * イベントオブジェクトを非シグナル状態にする。
         * @param	hEvent		イベントオブジェクトを示すハンドル。
         * @retval	ksTRUE		成功
         * @retval	ksFALSE		失敗
         */
        KsBool          reset();

        /**
         * 指定されたカーネルオブジェクトがシグナル状態になるか、
         * 指定された時間が経過するまでスレッドをスリープさせます。
         */
        KsUInt32        wait();

	private:
		KsHandle        m_handle;		/**< イベントハンドル   */
};

ksNS_KS_END

#endif		/* __KSEVENT_H__ */

