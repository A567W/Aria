/************************************************************************************************/
/** 
 * @file		KsActor.h
 * @brief		アクターオブジェクト
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/
#ifndef __KSACTOR_H__
#define __KSACTOR_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsActorCommon.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class		KsActor
 * @brief		アクターオブジェクトクラス
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 */
/************************************************************************************************/
class ksENGINE_API KsActor
{
	protected:
		KsModel*					m_pModel;			/**< モデルデータ			*/
		KsSkeleton*					m_pSkeleton;		/**< スケルトンデータ		*/
		KsAnimationController*		m_pCurrentAnim;		/**< 現在のアニメデータ	*/
		KsHumanIK*					m_pHumanIK;			/**< IK制御データ			*/
		KsPhysicsController*		m_pPhysics;			/**< 物理演算データ		*/

	public:
		/**
		 * コンストラクタ
		 */
		KsActor();

		/**
		 * コンストラクタ
		 */
		KsActor( KsModel* pModel );

		/**
		 * デストラクタ
		 */
		virtual ~KsActor();

		/**
		 * 更新処理
		 * @param	gameTime			更新時間
		 */
		virtual void update( KsReal gameTime );

		/**
		 * 描画処理
		 * @param	pRenderContext		描画コンテキスト
		 */
		virtual void draw( KsRenderContext* pRenderContext );

		/**
		 * アニメーションをセットする
		 * @param	pCurrentAnim		アニメーション
		 */
		void setAnimation( KsAnimationController* pCurrentAnim );

		/**
		 * アニメーションをセットする
		 * @return		現在のアニメーション
		 */
		KsAnimationController* getAnimation() { return m_pCurrentAnim; }

		/**
		 * モデルデータを取得する
		 * @return		モデルデータ
		 */
		KsModel*		getModel() { return m_pModel; }

		/**
		 * IKをセットする
		 * @param	pHumanIK			IK
		 */
		void setHumanIK( KsHumanIK* pHumanIK );

		/**
		 * 物理演算データをセットする
		 * @param	pPhysics			物理演算データ
		 */
		void setPhysics( KsPhysicsController* pPhysics );
};

ksNS_KS_END

#endif /* __KSACTOR_H__ */
