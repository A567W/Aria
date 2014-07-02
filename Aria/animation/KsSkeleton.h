/************************************************************************************************/
/** 
 * @file		KsSkeleton.h
 * @brief		スケルトンクラス
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/
#ifndef __KSSKELETON_H__
#define __KSSKELETON_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsAnimationCommon.h"
#include "KsBonePose.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN


/************************************************************************************************/
/**
 * @class		KsSkeleton
 * @brief		スケルトンクラス
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 */
/************************************************************************************************/
class ksENGINE_API KsSkeleton
{
	protected:
		KsString					m_boneName;			/**< ボーン名			*/
		KsInt32						m_boneIndex;		/**< ボーンインデックス	*/
		KsString					m_parentName;		/**< 親ボーン名			*/
		KsInt32						m_parentIndex;		/**< 親ボーンインデックス	*/
		KsArray<KsSkeleton*>		m_vpChildren;		/**< 子スケルトン		*/
		KsArray<KsBonePose*>		m_vpBonePose;		/**< ボーンポーズ		*/

	public:
		/**
		 * コンストラクタ
		 */
									KsSkeleton();

		/**
		 * コンストラクタ
		 */
									KsSkeleton( KsModel* pModel );

		/**
		 * デストラクタ
		 */
		virtual						~KsSkeleton();

		/**
		 * 更新処理
		 * @param	gameTime			更新時間
		 */
		virtual void				update( KsReal gameTime );

#if 0
		const KsString&				getBoneName() { return m_boneName };
		KsInt32						getBoneIndex() const { return m_boneIndex; }
		const KsString&				getParentName() { return m_parentName };
		KsInt32						getParentIndex;() const { return m_parentIndex;; }
		KsSkeleton*					getChild( KsInt32 index ) { return m_vpChildren[ index ]; }
		KsUInt32					getChildCount() const { return m_vpChildren.size(); }
		KsBonePose*					getBonePose() { return m_bonePose; }


		static void	bindBone( KsSkeleton* pSkeleton, KsBonePoseCollection* pBonePoseCollection )
		{
			if( -1 != pSkeleton->m_boneIndex )
			{
				pSkeleton->m_bonePose = bones[ pSkeleton->m_boneIndex ];
			}

			for( KsUInt32 i=0; i<pSkeleton->getChildCount; i++ )
			{
				bindBone( pSkeleton->getChild( i ), pBonePoseCollection );
			}
		}
#endif
};

ksNS_KS_END

#endif		/* __KSSKELETON_H__ */



