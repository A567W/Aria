/************************************************************************************************/
/** 
 * @file		KsCamera.h
 * @brief		カメラ
 * @author		A567W
 * @date		2004/10/17
 * @since		2004/10/17
 * @version		0.1
 */
/************************************************************************************************/
#ifndef __KSCAMERA_H__
#define __KSCAMERA_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                           */
/*==============================================================================================*/
#include "KsCameraObject.h"
#include "KsColor.h"
#include "KsViewport.h"
#include "KsFrustum.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

class KsRenderSystem;

/************************************************************************************************/
/**
 * @class		KsCamera
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 */
/************************************************************************************************/
class ksENGINE_API KsCamera : public KsCameraObject
{
	public:
		/** 
		 * プロジェクションのタイプ
		 */
		enum ksPROJECTION_TYPE
		{
			ksORTHOGRAPHIC,		/**< 正射影		*/
			ksPERSPECTIVE,		/**< 透視射影	*/
		};

		/** 
		 * 座標系
		 */
		enum ksCOORDINATE_TYPE
		{
			ksCOORD_RIGHT,		/**< 右手系		*/
			ksCOORD_LEFT,		/**< 左手系		*/
		};

	protected:
		/**
		 * 更新フラグ
		 */
		enum ksCAMERA_UPDATE_FLAG
		{
			ksNONE_UPDATE       = ( 0 ),
			ksVIEWPORT_UPDATE   = ( 1 << 0 ),
			ksPROJECTION_UPDATE = ( 1 << 1 ),
			ksVIEWMATRIX_UPDATE = ( 1 << 2 ),
			ksFRUSUM_UPDATE     = ( 1 << 3 ),
			ksUPDATE_FORCE32    = ( 0x7fffffff ),
		};

	public:
		/**
		 * コンストラクタ
		 */
									KsCamera();

		/**
		 * コンストラクタ
		 * @param	pRenderSystem	描画システム
		 */
									KsCamera( KsRenderSystem* pRenderSystem );

		/** 
		 * デストラクタ
		 */
		virtual						~KsCamera();

		/**
		 * カメラのクローン生成
		 * @return					クローンされたカメラ
		 */
		//virtual KsCamera*			clone();

		/**
		 * 座標系のタイプをセットする
		 * @param	type			座標系のタイプ
		 */
		void						setCoordinateType( ksCOORDINATE_TYPE type );

		/**
		 * カメラの更新処理
		 */
		virtual void				update();

		/**
		 * 描画開始
		 */
		virtual void				beginRender();

		/**
		 * 描画終了
		 */
		virtual void				endRender();

		/**
		 * 透視射影行列を生成する
		 * @param		fovy		視野角
		 * @param		aspect		アスペクト比
		 * @param		zNear		近距離値
		 * @param		zFar		遠距離値
		 */
		void						setPerspective( KsReal fovy, KsReal aspect, KsReal zNear, KsReal zFar );

		/**
		 * 正射影行列を生成する
		 * @param		projMatrix	プロジェクションマトリックス保存用
		 * @param		left		レフト
		 * @param		right		ライト
		 * @param		bottom		ボトム
		 * @param		top			トップ
		 * @param		aspect		アスペクト比
		 * @param		zNear		近距離値
		 * @param		zFar		遠距離値
		 */
		void						setOrtho( KsReal left, KsReal right, KsReal bottom, KsReal top, KsReal zNear, KsReal zFar );

		/**
		 * ビューポートのセット
		 * @param		x			X座標
		 * @param		y			X座標
		 * @param		w			幅
		 * @param		h			高さ
 		 * @param		near		nearクリップ値
		 * @param		far			farクリップ値
		 */
		void						setViewport( KsInt32 x, KsInt32 y, KsInt32 w, KsInt32 h, KsReal minZ, KsReal maxZ );

		/**
		 * ビューポートのセット
		 * @param		viewport	ビューポート
		 */
		void						setViewport( const KsViewport& viewport );

		/**
		 * ビューポートのを取得
		 * @return					ビューポートの
		 */
		const KsViewport&			getViewport() { return m_viewport; }

		/**
		 * カメラ描画
		 * @param	pFrustum		フラスタム(錐台)チェック(NULLなら自分のフラスタムを使用する)
		 * @param	bForce			強制描画フラグ
		 * @return					true if successful, false if error
		 */
//		KsBool						render( KsFrustum* pFrustum = 0, KsBool bForce = ksFALSE );

		/**
		 * カメラのLook-Atをセットする
		 * @param	eye				視点位置
		 * @param	target			ターゲット
		 * @param	up				up ベクトル
		 * @note					カメラの更新はbeginRenderのときまたはupdateを呼び出さないと更新されません。
		 */
		void						lookAt( const KsVector3d& eye, const KsVector3d& target, const KsVector3d& up );

		/**
		 * ビューマトリックスをセットする
		 * @param	viewMatrix		ビューマトリックス
		 */
		void						setViewMatrix( const KsMatrix4x4& viewMatrix ) { m_viewMatrix = viewMatrix; m_updateFlag |= ksVIEWMATRIX_UPDATE; }

		/**
		 * このカメラのプロジェクションマトリックスを取得
		 * @return					プロジェクションマトリックス
		 */
		const KsMatrix4x4&			getProjMatrix() { return m_projMatrix; }

		/**
		 * このカメラのプロジェクションマトリックスの逆行列を取得
		 * @return					プロジェクションマトリックスの逆行列
		 */
		KsMatrix4x4					getInverseProjMatrix() { return m_projMatrix.inverse(); }

		/**
		 * このカメラのビューマトリックスを取得
		 * @return					ビューマトリックス
		 */
		const KsMatrix4x4&			getViewMatrix() { return m_viewMatrix; }

		/**
		 * このカメラのビューマトリックスの逆行列を取得
		 * @return					ビューマトリックスの逆行列
		 */
		KsMatrix4x4					getInverseViewMatrix() { return m_viewMatrix.inverse(); }

		/**
		 * このカメラのビュープロジェクションマトリックスを取得
		 * @return					ビュープロジェクションマトリックス
		 */
		const KsMatrix4x4&			getViewProjMatrix() { return m_viewProjMatrix; }

		/**
		 * このカメラのビュープロジェクションマトリックスの逆行列を取得
		 * @return					ビュープロジェクションマトリックスの逆行列
		 */
		KsMatrix4x4					getInverseViewProjMatrix() { return m_viewProjMatrix.inverse(); }

		/**
		 * 自分のカメラをアクティブカメラにセットする
		 */
		void						setActive() { s_pActiveCamera = this; }

		/**
		 * アクティブカメラを取得する
		 * @return					アクティブカメラ
		 */
		static KsCamera*			getActive() { return s_pActiveCamera; }

		/**
		 * アスペクト比を取得する
		 * @return					アスペクト比
		 */
		KsReal						getAspect() const { return m_aspect; }

		/**
		 * プロジェクションのNearを取得する
		 * @return					プロジェクションのNear
		 */
		KsReal						getNear() const { return m_zNear; }

		/**
		 * プロジェクションのFarを取得する
		 * @return					プロジェクションのFar
		 */
		KsReal						getFar() const { return m_zFar; }

	protected:
		KsUInt32					m_updateFlag;		/**< カメラの更新が必要かどうか			*/
		ksCOORDINATE_TYPE			m_coordinateType;	/**< 座標系のタイプ					*/
		ksPROJECTION_TYPE			m_projectionType;	/**< プロジェクションのタイプ			*/
		KsUInt32					m_clearFlags;		/**< クリアフラグ						*/
		KsColor						m_clearColor;		/**< クリアーカラー					*/
		KsReal						m_clearDepth;		/**< クリアーする深度値				*/
		KsUInt32					m_clearSstencil;	/**< クリアーするステンシル値			*/
		KsViewport					m_viewport;			/**< ビューポート						*/
		KsReal						m_fovy;				/**< 視野角							*/
		KsReal						m_aspect;			/**< アスペクト比						*/
		KsReal						m_right;			/**< right(正射影用)					*/
		KsReal						m_left;				/**< left(正射影用)					*/
		KsReal						m_top;				/**< top(正射影用)					*/
		KsReal						m_bottom;			/**< bottom(正射影用)					*/
		KsReal						m_zNear;			/**< プロジェクションのNear			*/
		KsReal						m_zFar;				/**< プロジェクションのFar				*/
		KsMatrix4x4					m_projMatrix;		/**< プロジェクションマトリックス		*/
		KsMatrix4x4					m_viewMatrix;		/**< ビューマトリックス				*/
		KsMatrix4x4					m_viewProjMatrix;	/**< ビュープロジェクションマトリックス	*/
		KsFrustum					m_frustum;			/**< フラスタム						*/
		KsRenderSystem*				m_pRenderSystem;	/**< 描画システムのポインタ				*/
		static KsCamera*			s_pActiveCamera;	/**< 現在のアクティブカメラ				*/
};

ksNS_KS_END

#endif		/* __KSCAMERA_H__ */

