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
 * @file	KsBone.h
 * @brief	ボーン関係
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
/************************************************************************************************/
#ifndef __KSBONE_H__
#define __KSBONE_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsModelCommon.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class		KsBone
 * @brief		モデルボーンクラス
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 */
/************************************************************************************************/
class ksENGINE_API KsBone
{
		friend class KsModel;
	public:
		/**
		 * コンストラクタ
		 */
									KsBone();

		/**
		 * デストラクタ
		 */
		virtual						~KsBone();

		/**
		 * ボーン名を取得する
		 * @return					ボーン名
		 */
		const KsString&				getName() const { return m_name; }


		/**
		 * ボーンインデックスを取得する
		 * @return					ボーンインデックス
		 */
		KsInt32						getIndex() const { return m_index; }

		/**
		 * 親ボーンインデックスを取得する
		 * @return					親ボーンインデックス
		 */
		KsInt32						getParentIndex() const { return m_parent; }

		/**
		 * 親ボーンを取得する
		 * @return					親ボーン
		 */
		KsBone*						getParent() { return m_pParent; }


		/**
		 * 子供のボーンの数を取得する
		 * @return					子供の数
		 */
		KsUInt32					getNumChild() const { return m_vpChildren.size(); }

		/**
		 * 子供のボーンを取得する
		 * @return					子供のボーン
		 */
		KsBone*						getChild( KsInt32 index ) { return m_vpChildren[ index ]; }

		/**
		 *
		 */
		KsMatrix4x4&				getDefaultTransform() { return m_defaultTransform; }

		/**
		 *
		 */
		KsMatrix4x4&				getBoneTransform() { return m_boneTransform; }

		/**
		 *
		 */
		KsMatrix4x4&				getAnimationTransform() { return m_animationTransform; }

		/**
		 *
		 */
		KsMatrix4x4&				getInverseTransform() { return m_inverseTransform; }

		/**
		 *
		 */
		KsMatrix4x4&				getWorldTransform() { return m_worldTransform; }

		/**
		 *
		 */
		KsMatrix4x4&				getSkinTransform() { return m_skinTransform; }

		/**
		 * ボーンを描画する
		 */
		void						draw();

	public:
		KsInt32						m_index;				/// Bones コレクション内の、このボーンのインデックスを取得します。
		KsString					m_name;					/// このボーンの名前を取得します。
		KsInt32						m_parent;				/// 親ボーンのインデックス
		KsBone*						m_pParent;				/// このボーンの親を取得します。
		KsArray<KsBone*>			m_vpChildren;			/// このボーンの子であるボーンのコレクションを取得します。
		KsMatrix4x4					m_defaultTransform;		/// 親ボーンを基準としてこのボーンをトランスフォームするために使用される行列を取得または設定します。
		KsMatrix4x4					m_animationTransform;	/// 親ボーンを基準としてこのボーンをトランスフォームするために使用される行列を取得または設定します。
		KsMatrix4x4					m_inverseTransform;
		KsMatrix4x4					m_boneTransform;
		KsMatrix4x4					m_worldTransform;
		KsMatrix4x4					m_skinTransform;
};

ksNS_KS_END

#endif		/* __KSBONE_H__ */



