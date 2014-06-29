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
 * @file	KsTask.h
 * @brief	タスク
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/
#ifndef __KSTASK_H__
#define __KSTASK_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsTaskCommon.h"
#include "KsUpdate.h"
#include "KsDraw.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class	KsTask
 * @brief	更新処理タスク
 * @author	A567W
 */
/************************************************************************************************/
class ksENGINE_API KsTask : public KsUpdate, public KsDraw
{
		friend class KsTaskManager;
	
	public:
		/**
		 * コンストラクタ
		 * @brief	0で初期化される
		 */
									KsTask();

		/**
		 * コンストラクタ
		 * @param	updateOrder		更新オーダー
		 * @param	drawOrder		描画オーダー
		 */
									KsTask( KsUInt32 updateOrder, KsUInt32 drawOrder );

		/**
		 * デストラクタ
		 */
		virtual						~KsTask();

		/**
		 * 破棄する(マネージャ側で削除する)
		 */
		virtual void				destroy();

	protected:
		/**
		 * 初期化処理(マネージャに登録されたときに登録)
		 * @param		pParam		パラメータ
		 */
		virtual void*				initialize( void* pParam );

		/**
		 * 後処理関数でメモリーから削除されるときに呼ばれる
		 * @param		pParam		パラメータ
		 */
		virtual void*				terminate( void* pParam );

		/**
		 * 初期化処理(マネージャに登録されたときに登録)
		 * @param		pParam		パラメータ
		 */
		virtual void*				initializeGraphics( void* pParam );

		/**
		 * 後処理関数でメモリーから削除されるときに呼ばれる
		 * @param		pParam		パラメータ
		 */
		virtual void*				terminateGraphics( void* pParam );

};

ksNS_KS_END

#endif /* __KSTASK_H__ */

