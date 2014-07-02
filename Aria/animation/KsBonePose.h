/************************************************************************************************/
/** 
 * @file		KsBonePose.h
 * @brief		ボーンポーズ
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/
#ifndef __KSBONEPOSE_H__
#define __KSBONEPOSE_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsAnimationCommon.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

class KsSkeleton;
class KsIAnimationController;

/************************************************************************************************/
/**
 * @class		KsBonePose
 * @brief		ボーンポーズクラス
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 */
/************************************************************************************************/
class ksENGINE_API KsBonePose
{
		friend class KsModel;
		friend class KsSkeleton;

	public:
		/**
		 * コンストラクタ
		 */
										KsBonePose();

		/**
		 * デストラクタ
		 */
		virtual							~KsBonePose();

		/**
		 * ボーン名を取得する
		 * @return						ボーン名
		 */
		const KsString&					getName() const { return m_name; }

		/**
		 * ボーンIDを取得する
		 * @return						ボーンID
		 */
		KsInt32							getID() const { return m_id; }

		/**
		 * ボーンのフラグを取得する
		 * @return						ボーンの各種フラグ
		 */
		KsUInt32						getFlags()	const { return m_flags; }

		/**
		 * 親ボーンを取得する
		 * @return						親ボーン
		 */
		KsBonePose*						getParent() { return m_pParent; }

		/**
		 * 子供のボーンを取得する
		 * @return						子供のボーン
		 */
		KsBonePose*						getChild( KsInt32 index ) { return m_vpChildren[ index ]; }

	protected:
		KsInt32							m_index;					/**< インデックス番号				*/
		KsString						m_name;						/**< 名前						*/
		KsBonePose*						m_pParent;					/**< 親のID						*/
		KsInt32							m_parent;					/**< 親のインデックス				*/
		KsArray<KsBonePose*>			m_vpChildren;				/**< 子ボーンポーズ				*/
		KsReal							m_blendFactor;				/**< ブレンドファクター			*/
		KsIAnimationController*			m_pCurrentAnimation;		/**< 現在のアニメーション			*/
		KsIAnimationController*			m_pCurrentBlendAnimation;	/**< 現在のブレンドアニメーション	*/
		KsInt32							m_id;						/**< ボーンID					*/
		KsUInt32						m_flags;					/**< 各種フラグ					*/
		KsVector3d						m_initPivot;				/**< 初期の基点					*/
		KsVector3d						m_initTranslate;			/**< 初期の位置					*/
		KsQuaternion					m_initRotate;				/**< 初期の回転					*/
		KsVector3d						m_initScale;				/**< 初期のスケール				*/
		KsVector3d						m_pivot;					/**< 基点						*/
		KsVector3d						m_translate;				/**< 位置						*/
		KsQuaternion					m_rotate;					/**< 回転						*/
		KsVector3d						m_scale;					/**< スケール						*/
		KsMatrix4x4						m_defaultMatrix;			/**< デフォルトマトリックス			*/
		KsMatrix4x4						m_localMatrix;				/**< ローカルマトリックス			*/
		KsMatrix4x4						m_worldMatrix;				/**< ワールドマトリックス			*/
		KsMatrix4x4						m_stackMatrix;				/**< マトリックススタック			*/
		KsVector3d						m_stackScale;				/**< スケールスタック				*/
		KsSkeleton*						m_pSkeleton;				/**< スケルトンのポインタ			*/
//		KsBone*							m_pParent;					/**< 親のID						*/
//		KsBoneArray						m_pChildren;				/**< 子供のIDリスト				*/
		void*							m_pUserData;				/**< ユーザーデータ				*/
};

ksNS_KS_END

#endif		/* __KSBONEPOSE_H__ */



