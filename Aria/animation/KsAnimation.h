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
 * @file	KsAnimation.h
 * @brief	アニメーションクラス
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
/************************************************************************************************/
#ifndef __KSANIMATION_H__
#define __KSANIMATION_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsAnimationCommon.h"
#include "KsAnimationChannel.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class		KsAnimation
 * @brief		アニメーション
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 */
/************************************************************************************************/
class ksENGINE_API KsAnimation
{
	private:
		KsReal					m_duration;			/**< アニメーション時間					*/
		KsString				m_animationName;	/**< アニメーション名						*/
		KsAnimationChannel*		m_boneAnimations;	/**< ボーンアニメーションチャンネル		*/

	public:
		/**
		 * コンストラクタ
		 */
		KsAnimation();

		/**
		 * コンストラクタ
		 * @param	animationName		アニメーションの名前
		 * @param	pAnimationChannel	アニメーションチャンネル
		 */
		KsAnimation( const KsString& animationName, KsAnimationChannel* pAnimationChannel );

		/**
		 * デストラクタ
		 */
		virtual					~KsAnimation();

		/**
		 * アニメーションの経過時間を取得する
		 * @return				アニメーションの経過時間
		 */
		KsReal					getDuration() const { return m_duration; }

		/**
		 * アニメーション名前を取得する
		 * @return				アニメーションの名前
		 */
		const KsString&			getName() { return m_animationName; }

		/**
		 * アニメーションチャンネルを取得する
		 * @return				アニメーションチャンネル
		 */
		KsAnimationChannel*		getAnimationChannels() { return m_boneAnimations; }

		/**
		 * 影響ボーンの名前を取得する
		 * @param	index		インデックス
		 * @return				影響ボーンの名前
		 */
		const KsString&			getAffectedBone( KsUInt32 index ) { return m_boneAnimations->getAffectedBone( index );}

		/**
		 * 影響ボーンあるかどうかをチェックする
		 * @param	boneName	ボーンの名前
		 * @retval	ksTRUE		影響ボーンを持っている
		 * @retval	ksFALSE		影響ボーンを持ってない
		 */
		KsBool					hasAffectsBone( const KsString& boneName ) { return m_boneAnimations->hasAffectsBone( boneName ); }
};

ksNS_KS_END

#endif /* __KSANIMATION_H__ */

