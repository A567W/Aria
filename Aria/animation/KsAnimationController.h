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
 * @file	KsAnimationController.h
 * @brief	アニメーションコントローラー
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
/************************************************************************************************/
#ifndef __KSANIMATIONCONTROLLER_H__
#define __KSANIMATIONCONTROLLER_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsAnimationCommon.h"
#include "KsAnimation.h"
#include "KsIAnimationController.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

class KsAnimation;

/************************************************************************************************/
/**
 * @class		KsAnimationController
 * @brief		モデルボーンクラス
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 */
/************************************************************************************************/
class ksENGINE_API KsAnimationController : public KsIAnimationController
{
		friend class KsModel;
	public:
		/**
		 * コンストラクタ
		 */
								KsAnimationController( KsAnimation* pAnimation );

		/**
		 * デストラクタ
		 */
		virtual					~KsAnimationController();


		virtual void			update( KsReal gameTime );

		virtual KsMatrix4x4		getCurrentBoneTransform( const KsBone* pBone );
	
		
		virtual KsBool			containsAnimationTrack( const KsBone* pBone );

		KsReal					getDuration() const { return m_pAnimation->getDuration(); }

		void					setSpeedFactor( KsReal speedFactor ) { m_speedFactor = speedFactor; }
		KsReal					getSpeedFactor() const { return m_speedFactor; }
	private:
		KsAnimation*			m_pAnimation;
		KsReal					m_speedFactor;
		KsReal					m_elapsedTime;
		KsReal					m_elapsed;
		KsBool					m_isLooping;
};

ksNS_KS_END

#endif		/* __KSANIMATIONCONTROLLER_H__ */



