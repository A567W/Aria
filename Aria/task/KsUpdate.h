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
 * @file	KsUpdate.h
 * @brief	更新処理
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/
#ifndef __KSUPDATE_H__
#define __KSUPDATE_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsTaskCommon.h"
#include "KsUpdateThread.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

class KsUpdateThread;

/*************************************************************************************************/
/**
 * @class	KsUpdate
 * @brief	更新処理タスク
 * @author	A567W
 */
/*************************************************************************************************/
class ksENGINE_API KsUpdate
{
		friend class KsUpdateList;
		friend class KsUpdateThread;
	
	public:
		/**
		 * コンストラクタ
		 * @brief	0で初期化される
		 */
											KsUpdate();

		/**
		 * コンストラクタ
		 * @param	order					更新オーダー
		 */
											KsUpdate( KsUInt32 order );

		/**
		 * デストラクタ
		 */
		virtual								~KsUpdate();

		/**
		 * タスクの識別IDを取得する
		 * @return		タスクのIDを取得する
		 */
		KsUInt32							getUpdateID() const { return m_updateID; }

		/**
		 * オーダーを取得する
		 * @return		更新オーダーを取得する
		 */
		KsUInt32							getUpdateOrder() const { return m_updateOrder; }

		/**
		 * 更新するかどうかをセットする
		 * @param		updateActive		更新するかどうかをセットする
		 */
		void								setActiveUpdate( KsBool updateActive ) { m_updateActive = updateActive; }

		/**
		 * 更新するかどうかを取得する
		 * @return		更新するかどうかを取得する
		 */
		KsBool								isActiveUpdate() const { return m_updateActive; }

		/**
		 * 更新プライオリティを取得する
		 * @return		更新プライオリティを取得する
		 */
		KsUInt32							getUpdatePriority() const { return m_updatePriority; }

	protected:
		/**
		 * 初期化処理(マネージャに登録されたときに登録)
		 * @param		pParam				パラメータ
		 */
		virtual void*						initialize( void* pParam ) = 0;

		/**
		 * 更新処理
		 * @param		pParam				パラメータ
		 */
		virtual void*						update( void* pParam ) = 0;

		/**
		 * 後処理関数でメモリーから削除されるときに呼ばれる
		 * @param		pParam				パラメータ
		 */
		virtual void*						terminate( void* pParam ) = 0;

		/**
		 * 破棄する(マネージャ側で削除する)
		 */
		virtual void						destroyUpdate();

	protected:
		KsUInt32							m_updateID;			/**< タスク識別ID(自動的に割り振る?)	*/
		KsUInt32							m_updateOrder;		/**< 更新オーダー						*/
		KsUInt32							m_updatePriority;	/**< 更新プライオリティ				*/
		KsBool								m_updateActive;		/**< 更新アクティブフラグ				*/
		KsBool								m_updateFlags;		/**< 更新フラグ						*/
		KsUpdate*							m_pUpdatePrev;		/**< 更新前方リスト					*/
		KsUpdate*							m_pUpdateNext;		/**< 更新後方リスト					*/
		KsUpdateThread*						m_pUpdateThread;	/**< 更新スレッド						*/
};

ksNS_KS_END

#endif /* __KSUPDATE_H__ */

