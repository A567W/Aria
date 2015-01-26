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
 * @file	KsActor.cpp
 * @brief	アクターオブジェクト
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
/************************************************************************************************/

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsActor.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * コンストラクタ
 */
/************************************************************************************************/
KsActor::KsActor()
	: m_pModel( 0 )
	, m_pSkeleton( 0 )
	, m_pCurrentAnim( 0 )
	, m_pHumanIK( 0 )
	//, m_pPhysics( 0 )
{
}

/************************************************************************************************/
/**
 * コンストラクタ
 */
/************************************************************************************************/
KsActor::KsActor( KsModel* pModel )
	: m_pModel( pModel )
	, m_pSkeleton( 0 )
	, m_pCurrentAnim( 0 )
	, m_pHumanIK( 0 )
	//, m_pPhysics( 0 )
{
	pModel->updateBoneMatrix();
	pModel->updateWorldMatrix();

	m_pSkeleton = ksNew KsSkeleton( pModel );

	//m_humanIK      = KsHumanIK.FromModel( model );
}

/************************************************************************************************/
/*
 * デストラクタ
 */
/************************************************************************************************/
KsActor::~KsActor()
{
	//ksDELETE( m_pPhysics );
	ksDELETE( m_pHumanIK );
	ksDELETE( m_pSkeleton );
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsActor::update( KsReal gameTime )
{
	// アニメーションを更新する
	if( NULL != m_pCurrentAnim )
	{
		m_pCurrentAnim->update( 1.0f );

		for( KsUInt32 i=1; i<m_pModel->getBoneCount(); i++ )
		{
			KsBone*	pBone = m_pModel->m_vpBones[ i ];

			pBone->m_animationTransform = m_pCurrentAnim->getCurrentBoneTransform( pBone );
		}
	}

	// ボーン情報を更新する
	//m_pSkeleton->update( gameTime );

	// モデル用事の更新する
	m_pModel->update();

#if 0
	// 物理計算処理を反映する
	if( NULL != m_pPhysics )
	{
		m_pPhysics->update( gameTime );
	}
#endif

	// マトリックス更新
	m_pModel->updateSkinMatrix();

	// IK更新
	if( NULL != m_pHumanIK )
	{
		m_pHumanIK->update();
	}
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsActor::draw( KsRenderContext* pRenderContext )
{
	m_pModel->draw( pRenderContext );

	//if( null != m_humanPhysics )
	//{
		//m_humanPhysics.DebugDraw();
	//}
}


/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsActor::setAnimation( KsAnimationController* pCurrentAnim )
{
	m_pCurrentAnim = pCurrentAnim;
}

/************************************************************************************************/
/*
 * IKデータをセットする
 * @param	pHumanIK			IKデータ
 */
/************************************************************************************************/
void KsActor::setHumanIK( KsHumanIK* pHumanIK )
{
	m_pHumanIK = pHumanIK;
}
#if 0
/************************************************************************************************/
/*
 * 物理演算データをセットする
 * @param	pPhysics			物理演算データ
 */
/************************************************************************************************/
void KsActor::setPhysics( KsPhysicsController* pPhysics )
{
	m_pPhysics = pPhysics;
}
#endif

ksNS_KS_END

