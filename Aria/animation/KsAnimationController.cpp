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
 * @file	KsAnimationController.cpp
 * @brief	アニメーションコントローラー
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
/************************************************************************************************/

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsAnimationController.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN


/************************************************************************************************/
/*
 * コンストラクタ
 */
/************************************************************************************************/
KsAnimationController::KsAnimationController( KsAnimation* pAnimation )
	: m_pAnimation( pAnimation )
	, m_speedFactor( 1.0f )
	, m_elapsedTime( 0.0f )
	, m_elapsed( 0.0f )
	, m_isLooping( ksTRUE )
{
}

/************************************************************************************************/
/*
 * デストラクタ
 */
/************************************************************************************************/
KsAnimationController::~KsAnimationController()
{
}

/************************************************************************************************/
/*
 * アニメーション更新
 */
/************************************************************************************************/
void KsAnimationController::update( KsReal gameTime )
{
	m_elapsed = m_speedFactor * gameTime;

	if( m_isLooping )
	{
		if( m_elapsed > 0.0f )
		{
			m_elapsedTime += m_elapsed;

			if( m_elapsedTime > m_pAnimation->getDuration() )
			{
				//OnAnimationEnded(null);
				m_elapsedTime -= m_pAnimation->getDuration();
			}
		}
	}
	else if( m_elapsedTime != m_pAnimation->getDuration() )
	{
		if( m_elapsed > 0.0f )
		{
			m_elapsedTime += m_elapsed;

			if( m_elapsedTime >= m_pAnimation->getDuration() || m_elapsedTime < 0.0f )
			{
				m_elapsedTime = m_pAnimation->getDuration();

				//OnAnimationEnded(null);
			}
		}
	}

	
	static float xxx = 80.0f;
	{
		//m_elapsedTime = xxx;
	}
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
KsMatrix4x4 KsAnimationController::getCurrentBoneTransform( const KsBone* pBone )
{
	KsAnimationChannel*		channels   = m_pAnimation->getAnimationChannels();
	KsKeyFrameCollection*	channel    = channels->getKeyFrameCollection( pBone->getName() );
	KsMatrix4x4				poseMatrix;

	if( channel )
	{
		poseMatrix = channel->getPoseMatrix( m_elapsedTime );
	}

	return poseMatrix;
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
KsBool KsAnimationController::containsAnimationTrack( const KsBone* pBone )
{
	return m_pAnimation->getAnimationChannels()->hasAffectsBone( pBone->getName() );
}

ksNS_KS_END

