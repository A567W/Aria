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
 * @file	KsUpdateList.h
 * @brief	更新リスト処理
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/
#ifndef __KSUPDATELIST_H__
#define __KSUPDATELIST_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsTaskCommon.h"
#include "KsUpdate.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class		KsUpdateList
 * @brief		描画タスクリスト
 * @date		2011/10/17
 * @since		2011/10/17
 * @version		1.0.0
 */
/************************************************************************************************/
class ksENGINE_API KsUpdateList
{
		friend class KsUpdate;
		friend class KsUpdateThread;

	public:
		/**
		 * コンストラクタ
		 * @brief	0で初期化される
		 */
											KsUpdateList();

		/**
		 * デストラクタ
		 */
		virtual								~KsUpdateList();

		/**
		 * 描画するかどうかをセットする
		 * @param		drawActive		描画するかどうかをセットする
		 */
		void								setActive( KsBool isActive ) { m_isActive = isActive; }

		/**
		 * 描画するかどうかを取得する
		 * @return		描画するかどうかを取得する
		 */
		KsBool								isActive() const { return m_isActive; }
		
		/**
		 * 描画タスクを追加する
		 * @param		pUpdate				描画タスク
		 */
		void								add( KsUpdate* pUpdate );

		/**
		 * 描画タスクを取り除く
		 * @param		pUpdate				描画タスク
		 */
		void								remove( KsUpdate* pUpdate );

		/**
		 * タスクを追加する
		 * @param		pUpdate				描画タスク
		 */
		void								update( void* pParam );

	protected:
		KsBool								m_isActive;			/**< 更新アクティブフラグ		*/
		KsUpdate*							m_pUpdateRoot;		/**< 更新ルート				*/
		KsUpdate*							m_pUpdateLast;		/**< 更新ラスト				*/
		KsUpdateThread*						m_pUpdateThread;	/**< 更新スレッド				*/
};

ksNS_KS_END

#endif /* __KSUPDATELIST_H__ */

