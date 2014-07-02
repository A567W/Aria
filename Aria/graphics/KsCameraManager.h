/************************************************************************************************/
/** 
 * @file		KsCameraManager.h
 * @brief		カメラ管理
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/
#ifndef __KSCAMERAMANAGER_H__
#define __KSCAMERAMANAGER_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                           */
/*==============================================================================================*/
#include "KsGraphicsCommon.h"
#include "KsCamera.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class		KsCameraManager
 * @brief		カメラ管理クラス
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 */
/************************************************************************************************/
class ksENGINE_API KsCameraManager : public KsSingleton< KsCameraManager >
{
	public:
		/**
		 * シングルトンの参照を取得
		 * @return							シングルトンの参照
		 */
		static KsCameraManager&				getInstance();
		
		/**
		 * シングルトンのポインタを取得
		 * @return							シングルトンのポインタ
		 */
		static KsCameraManager*				getInstancePtr();

		/**
		 * コンストラクタ
		 */
											KsCameraManager();

		/**
		 * デストラクタ
		 */
		virtual								~KsCameraManager();

		/**
		 * 初期化処理(マネージャに登録されたときに登録)
		 * @param		pParam				パラメータ
		 * @return							ユーザーパラメータ
		 */
		virtual void*						initialize( void* pParam );

		/**
		 * タスクの実行
		 * @param		pParam				パラメータ
		 * @return							ユーザーパラメータ
		 */
		virtual void*						execute( void* pParam );

		/**
		 * 描画処理
		 * @param		pParam				パラメータ
		 * @return							ユーザーパラメータ
		 */
		virtual void*						render( void* pParam );

		/**
		 * 後処理関数でメモリーから削除されるときに呼ばれる
		 * @param		pParam				パラメータ
		 * @return							ユーザーパラメータ
		 */
		virtual void*						terminate( void* pParam );

		/**
		 * アクティブカメラをセットする
		 * @param							カメラ
		 */
		void								setActiveCamera( KsCamera* pCamera );

		/**
		 * アクティブカメラをセットする
		 * @param							カメラ
		 */
		void								setActiveCamera( KsUInt32 index ) { m_pActiveCamera = m_pCameras[ index ]; }

		/**
		 * アクティブカメラを取得する
		 * @return							アクティブカメラ
		 */
		KsCamera*							getActiveCamera() { return m_pActiveCamera; }

		/**
		 * カメラを取得する
		 * @return							カメラ
		 */
		KsCamera*							getCamera( KsUInt32 index ) { return m_pCameras[ index ]; }

		/**
		 * カメラをセットする
		 * @param							カメラ
		 */
		void								addCamera( KsCamera* pCamera );

		/**
		 * カメラを削除する
		 * @param							カメラ
		 */
		void								removeCamera( KsCamera* pCamera );

	protected:
		KsCamera*							m_pActiveCamera;	/**< アクティブカメラ		*/
		KsArray<KsCamera*>					m_pCameras;			/**< カメラリスト		*/
};

ksNS_KS_END

#endif		/* __KSCAMERAMANAGER_H__ */



