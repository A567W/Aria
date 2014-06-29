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
 * @file	KsTaskManager.h
 * @brief	タスク管理
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
/************************************************************************************************/
#ifndef __KSTASKMANAGER_H__
#define __KSTASKMANAGER_H__

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
 * @class		KsTaskManager
 * @brief		基本タスクマネージャクラス
 * @date		2004/10/17
 * @since		2004/10/17
 * @version		0.10
 * @note		なし
 */
/************************************************************************************************/
class ksENGINE_API KsTaskManager : public KsSingleton< KsTaskManager >
{
		friend class KsUpdate;
		friend class KsDraw;
		friend class KsTask;

	public:
		/**
		 * シングルトンの参照を取得
		 * @return							シングルトンの参照
		 */
		static KsTaskManager&				getInstance();
		
		/**
		 * シングルトンのポインタを取得
		 * @return							シングルトンのポインタ
		 */
		static KsTaskManager*				getInstancePtr();

	public:
		/**
		 * コンストラクタ
		 * @param		numUpdateList		更新リスト数
		 * @param		numDrawList			描画リスト数
		 */
											KsTaskManager( KsUInt32 numUpdateList, KsUInt32 numDrawList );

		/**
		 * デストラクタ
		 */
		virtual								~KsTaskManager();

#if 0
		/**
		 * すべての処理を実行
		 * @param		pParam				ここでわたしたパラメータがタスクのexecuteやrenderの引数に渡る
		 *									デフォルトでは、NULLが設定されている。
		 */
		virtual void						run( void* pParam=NULL );

		/**
		 * 更新処理
		 * @param		pParam				パラメータ
		 */
		virtual void						execute( void* pParam );

		/**
		 * 描画処理
		 * @param		pParam				パラメータ
		 */
		virtual void						render( void* pParam );

		/**
		 * 
		 */
		virtual void						addTask( KsTask* pTask );

		/**
		 * 
		 */
		virtual void						addUpdate( KsUpdate* pUpdate );

		/**
		 * 
		 */
		virtual void						addDraw( KsDraw* pDraw );


		virtual void						removeTask( KsTask* pTask );

		/**
		 * 
		 */
		virtual void						removeUpdate( KsUpdate* pUpdate );

		/**
		 * 
		 */
		virtual void						removeDraw( KsDraw* pDraw );

		virtual void						destroyTask( KsTask* pTask );

		/**
		 * 
		 */
		virtual void						destroyUpdate( KsUpdate* pUpdate );

		/**
		 * 
		 */
		virtual void						destroyDraw( KsDraw* pDraw );

		virtual void						destroyAll();
	protected:
		/**
		 * 描画開始
		 */
		virtual void						begineRender();

		/**
		 * 描画終了
		 */
		virtual void						endRender();

	protected:
		KsUpdateThreadManager*				m_pUpdateThreadManager;	/**< 更新リスト	*/
		KsDrawThreadManager*				m_pDrawThreadManager;	/**< 描画リスト	*/
#endif
};

ksNS_KS_END

#endif /* __KSTASKMANAGER_H__ */

