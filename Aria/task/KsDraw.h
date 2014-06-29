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
 * @file	KsDraw.h
 * @brief	描画タスク
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/
#ifndef __KSDRAW_H__
#define __KSDRAW_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsTaskCommon.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/
#define ksDRAW_DESTROY_FLAG		( 0x80000000 )

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

class KsDrawThread;

/************************************************************************************************/
/**
 * @class	KsDraw
 * @brief	描画タスク
 * @author	A567W
 */
/************************************************************************************************/
class ksENGINE_API KsDraw
{
		friend class KsDrawList;
		friend class KsDrawThread;

	public:
		/**
		 * コンストラクタ
		 * @brief	0で初期化される
		 */
											KsDraw();

		/**
		 * コンストラクタ
		 * @param	order					描画オーダー
		 */
											KsDraw( KsUInt32 order );

		/**
		 * デストラクタ
		 */
		virtual								~KsDraw();

		/**
		 * タスクの識別IDを取得する
		 * @return		タスクのIDを取得する
		 */
		KsUInt32							getDrawID() const { return m_drawID; }

		/**
		 * オーダーを取得する
		 * @return		描画オーダーを取得する
		 */
		KsUInt32							getDrawOrder() const { return m_drawOrder; }

		/**
		 * 描画するかどうかをセットする
		 * @param		drawActive		描画するかどうかをセットする
		 */
		void								setActiveDraw( KsBool drawActive ) { m_drawActive = drawActive; }

		/**
		 * 描画するかどうかを取得する
		 * @return		描画するかどうかを取得する
		 */
		KsBool								isActiveDraw() const { return m_drawActive; }

		/**
		 * 描画プライオリティを取得する
		 * @return		描画プライオリティを取得する
		 */
		KsUInt32							getDrawPriority() const { return m_drawPriority; }

	protected:
		/**
		 * 初期化処理(マネージャに登録されたときに登録)
		 * @param		pRenderContext		描画コンテキスト
		 */
		virtual void*						initializeGraphics( KsRenderContext* pRenderContext ) = 0;

		/**
		 * 描画処理
		 * @param		pRenderContext		描画コンテキスト
		 */
		virtual void*						draw( KsRenderContext* pRenderContext ) = 0;

		/**
		 * 後処理関数でメモリーから削除されるときに呼ばれる
		 * @param		pRenderContext		描画コンテキスト
		 */
		virtual void*						terminateGraphics( KsRenderContext* pRenderContext ) = 0;

		/**
		 * 破棄する(マネージャ側で削除する)
		 */
		virtual void						destroyDraw();

	protected:
		KsUInt32							m_drawID;		/**< 描画識別ID(自動的に割り振る?)		*/
		KsUInt32							m_drawOrder;	/**< 描画オーダー						*/
		KsUInt32							m_drawPriority;	/**< 描画プライオリティ				*/
		KsBool								m_drawActive;	/**< 描画アクティブフラグ				*/
		KsUInt32							m_drawFlags;	/**< 描画フラグ						*/
		KsDraw*								m_pDrawPrev;	/**< 描画前方リスト					*/
		KsDraw*								m_pDrawNext;	/**< 描画後方リスト					*/
		KsDrawThread*						m_pDrawThread;	/**< 描画スレッド						*/
};

ksNS_KS_END

#endif /* __KSDRAW_H__ */

