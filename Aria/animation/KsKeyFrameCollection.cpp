/************************************************************************************************/
/** 
 * @file		KsKeyFrameCollection.h
 * @brief		ボーンポーズ
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsKeyFrameCollection.h"

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
KsKeyFrameCollection::KsKeyFrameCollection()
	: m_duration( 0 )
	, m_hasTranslation( ksFALSE )
	, m_hasRotation( ksFALSE )
	, m_hasScale( ksFALSE )
{
}


/************************************************************************************************/
/**
 * コンストラクタ
 */
/************************************************************************************************/
KsKeyFrameCollection::KsKeyFrameCollection( const KsString& boneName, KsKeyFrame* pKeyFrames, KsInt32 keyFrameCount,
								KsInt32 duration, KsBool hasTranslation, KsBool hasRotation, KsBool hasScale )
{
	m_boneName       = boneName;
	m_duration       = duration;
	m_hasTranslation = hasTranslation;
	m_hasRotation    = hasRotation;
	m_hasScale       = hasScale;
}

/************************************************************************************************/
/*
 * デストラクタ
 */
/************************************************************************************************/
KsInt32 KsKeyFrameCollection::getIndexByTime( KsReal ticks )
{
	KsInt32		firstFrameIndexToCheck = (KsInt32)(ticks);
	KsInt32		nunFrame = getKeyFrameCount();

	if( firstFrameIndexToCheck >= nunFrame )
	{
		firstFrameIndexToCheck = nunFrame - 1;
	}

	while( firstFrameIndexToCheck < nunFrame- 1 && (KsReal)m_vKeyFrames[firstFrameIndexToCheck+1].getTime() < ticks )
	{
		++firstFrameIndexToCheck;
	}

	while( firstFrameIndexToCheck >= 0 && (KsReal)m_vKeyFrames[firstFrameIndexToCheck].getTime() > ticks )
	{
		--firstFrameIndexToCheck;
	}

	return firstFrameIndexToCheck;
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
KsMatrix4x4 KsKeyFrameCollection::getPoseMatrix( KsReal ticks )
{
	KsMatrix4x4		pose       = KsMatrix4x4::IDENTITY;
	KsUInt32		frameIndex = getIndexByTime( ticks );
	KsKeyFrame		keyFrame   = m_vKeyFrames[ frameIndex ];

	KsReal		amount     = 0.0f;
	KsUInt32	nextIndex  = frameIndex + 1;
	KsKeyFrame	keyNext;

	if( 0 == getKeyFrameCount() )
	{
		KsMatrix4x4	scaleMat;
		KsMatrix4x4	rotationMat( keyFrame.getRotation() );
		KsMatrix4x4	translateMat;

		scaleMat.setScale( keyFrame.getScale() );
		scaleMat.setTranslate( keyFrame.getTranslate() );

		pose *= scaleMat;
		pose *= rotationMat;
		pose *= translateMat;
	}
	else
	{
		amount     = 0.0f;
		nextIndex  = frameIndex + 1;

		if( nextIndex < getKeyFrameCount() )
		{
			keyNext = m_vKeyFrames[ nextIndex ];

			const KsReal	nowFrame  = (KsReal)keyFrame.getTime();
			const KsReal	nextFrame = (KsReal)keyNext.getTime();

			amount  = (KsReal)( ticks - nowFrame )/(KsReal)( nextFrame - nowFrame );
		}
		else
		{
			keyNext = keyFrame;
			amount  = 0.0f;
		}

		if( m_hasScale )
		{
			KsVector3d scale = KsVector3d::Lerp( keyFrame.getScale(), keyNext.getScale(), amount );
			pose *= KsMatrix4x4::CreateScale( scale );
		}

		if( m_hasRotation )
		{
#if 1
			//KsQuaternion rotation = KsQuaternion::Slerp( keyFrame.getRotation(), keyNext.getRotation(), amount );
			KsQuaternion rotation = KsQuaternion::Lerp( keyFrame.getRotation(), keyNext.getRotation(), amount );
#else
			const KsReal	rotLerpValueX = keyNext.getBezierAngle().getInterValue( amount );
			KsQuaternion rotation = KsQuaternion::Lerp( keyFrame.getRotation(), keyNext.getRotation(), rotLerpValueX );
#endif

			pose *= KsMatrix4x4::CreateFromQuaternion( rotation );
		}

		if( m_hasTranslation )
		{
#if 1
			KsVector3d translate = KsVector3d::Lerp( keyFrame.getTranslate(), keyNext.getTranslate(), amount );
#else
			KsVector3d translate;
			const KsReal	posLerpValueX = keyNext.getBezierX().getInterValue( amount );
			translate.x = keyFrame.getTranslate().x * (1.0f - posLerpValueX) + keyNext.getTranslate().x * posLerpValueX;

			const KsReal	posLerpValueY = keyNext.getBezierY().getInterValue( amount );
			translate.y = keyFrame.getTranslate().y * (1.0f - posLerpValueY) + keyNext.getTranslate().y * posLerpValueY;

			const KsReal	posLerpValueZ = keyNext.getBezierZ().getInterValue( amount );
			translate.z = keyFrame.getTranslate().z * (1.0f - posLerpValueZ) + keyNext.getTranslate().z * posLerpValueZ;
#endif
			pose *= KsMatrix4x4::CreateTranslation( translate );
		}
	}

	return pose;
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsKeyFrameCollection::addSortedKeyFrame( const KsKeyFrame& keyFrame )
{
	KsInt32   count = m_vKeyFrames.size();
    KsInt32   idx   = m_vKeyFrames.size();
    KsBool    last  = ksTRUE;

    for( KsInt32 i=count-1; 0<=i; i-- )
    {
		if( m_vKeyFrames[ i ].getTime() > keyFrame.getTime() )
        {
            last = ksFALSE;
            idx = i;
        }
        else
        {
            break;
        }
    }

    if( last )
    {
		m_vKeyFrames.push_back( keyFrame );
    }
    else
    {
        m_vKeyFrames.insert( idx, keyFrame );
    }
}

ksNS_KS_END

