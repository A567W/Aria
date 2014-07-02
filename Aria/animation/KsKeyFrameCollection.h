/************************************************************************************************/
/** 
 * @file		KsKeyFrameCollection.h
 * @brief		キーフレームコレクション
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/
#ifndef __KSKEYFRAMECOLLECTION_H__
#define __KSKEYFRAMECOLLECTION_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsAnimationCommon.h"
#include "KsKeyFrame.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN


/************************************************************************************************/
/**
 * @class		KsKeyFrameCollection
 * @brief		キーフレームコレクションクラス
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 */
/************************************************************************************************/
class ksENGINE_API KsKeyFrameCollection
{
	private:
		KsString					m_boneName;
		KsInt32						m_duration;
		KsBool						m_hasTranslation;
		KsBool						m_hasRotation;
		KsBool						m_hasScale;
		KsArray<KsKeyFrame>			m_vKeyFrames;

	public:
		KsKeyFrameCollection();
		KsKeyFrameCollection( const KsString& boneName, KsKeyFrame* pKeyFrames, KsInt32 keyFrameCount,
								KsInt32 duration, KsBool hasTranslation, KsBool hasRotation, KsBool hasScale );



		KsInt32				getIndexByTime( KsReal ticks );

		KsMatrix4x4			getPoseMatrix( KsReal ticks );
	
		KsInt32				getDuration() const { return m_duration; }
		void				setDuration( KsInt32 duration ) { m_duration = duration; }

		const KsString&		getBoneName() { return m_boneName; }
		void				setBoneName( const KsString& boneName ) { m_boneName = boneName; }

		KsBool				getHasTranslation() const { return m_hasTranslation; }
		void				setHasTranslation( KsBool hasTranslation ) { m_hasTranslation = hasTranslation; }

		KsBool				getHasRotation() const { return m_hasRotation; }
		void				setHasRotation( KsBool hasRotation ) { m_hasRotation = hasRotation; }

		KsBool				getHasScale() const { return m_hasScale; }
		void				setHasScale( KsBool hasScale ) { m_hasScale = hasScale; }

        void				addSortedKeyFrame( const KsKeyFrame& keyFrame );

		KsUInt32			getKeyFrameCount() { return m_vKeyFrames.size(); }

		KsKeyFrame*			getKeyFrame( KsInt32 index ) { return &m_vKeyFrames[ index ]; }
};

ksNS_KS_END

#endif /* __KSKEYFRAMECOLLECTION_H__ */

