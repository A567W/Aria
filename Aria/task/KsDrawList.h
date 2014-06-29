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
 * @file	KsDrawList.h
 * @brief	描画リスト
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/
#ifndef __KSDRAWLIST_H__
#define __KSDRAWLIST_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsTaskCommon.h"
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
 * @class	KsDrawList
 * @brief	描画タスクリスト
 * @author	A567W
 */
/************************************************************************************************/
class ksENGINE_API KsDrawList
{
		friend class KsDraw;
		friend class KsDrawThread;

	public:
		/**
		 * コンストラクタ
		 * @brief	0で初期化される
		 */
											KsDrawList();

		/**
		 * デストラクタ
		 */
		virtual								~KsDrawList();

		/**
		 * 描画タスクを追加する
		 * @param		pDraw				描画タスク
		 */
		void								add( KsDraw* pDraw );

		/**
		 * 描画タスクを取り除く
		 * @param		pDraw				描画タスク
		 */
		void								remove( KsDraw* pDraw );

		/**
		 * 描画処理
		 * @param		pRenderContext		描画コンテキスト
		 */
		void								draw( KsRenderContext* pRenderContext );

	protected:
		KsBool								m_isActive;		/**< 描画アクティブフラグ	*/
		KsDraw*								m_pDrawRoot;	/**< 描画ルート			*/
		KsDraw*								m_pDrawLast;	/**< 描画ラスト			*/
		KsDrawThread*						m_pDrawThread;	/**< 描画スレッド			*/
};

ksNS_KS_END

#endif /* __KSDRAWLIST_H__ */

