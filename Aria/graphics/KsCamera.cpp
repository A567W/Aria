/************************************************************************************************/
/** 
 * @file		StCamera.h
 * @brief		カメラ
 * @author		A567W
 * @date		2004/10/17
 * @since		2004/10/17
 * @version		0.1
 */
/************************************************************************************************/

/*==============================================================================================*/
/*                                 << インクルード >>                                           */
/*==============================================================================================*/
#include "KsCamera.h"
#include "KsRenderSystem.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

KsCamera* KsCamera::s_pActiveCamera = 0;

/*************************************************************************************************/
/*
 * コンストラクタ
 */
/*************************************************************************************************/
KsCamera::KsCamera()
{
	/* 描画設定 */
	m_coordinateType = ksCOORD_LEFT;

	/* タスクタイプをカメラにする */
//	m_type  = ksTASK_TYPE_CAMERA;

	/* 描画するオーダーを指定(とりあえず全指定) */
//	m_order = ksTASK_RENDER_ORDER_ALL;

	m_pRenderSystem = NULL;
}

/*************************************************************************************************/
/*
 * コンストラクタ
 * @param	pRenderSystem	描画システム
 */
/*************************************************************************************************/
KsCamera::KsCamera( KsRenderSystem* pRenderSystem )
{
	/* 描画設定 */
	m_coordinateType = ksCOORD_LEFT;

	/* タスクタイプをカメラにする */
//	m_type  = ksTASK_TYPE_CAMERA;

	/* 描画するオーダーを指定(とりあえず全指定) */
//	m_order = ksTASK_RENDER_ORDER_ALL;

	m_pRenderSystem = pRenderSystem;
}

/*************************************************************************************************/
/*
 * デストラクタ
 */
/*************************************************************************************************/
KsCamera::~KsCamera()
{
}

/*************************************************************************************************/
/*
 * 座標系のタイプをセットする
 * @param	type			座標系のタイプ
 */
/*************************************************************************************************/
void KsCamera::setCoordinateType( ksCOORDINATE_TYPE type )
{
	m_coordinateType = type;
}

/*************************************************************************************************/
/*
 * ビューポートのセット
 * @param		x		X座標
 * @param		y		X座標
 * @param		w		幅
 * @param		h		高さ
 * @param		near	nearクリップ値
 * @param		far		farクリップ値
 */
/*************************************************************************************************/
void KsCamera::setViewport( KsInt32 x, KsInt32 y, KsInt32 w, KsInt32 h, KsReal minZ, KsReal maxZ )
{
	m_viewport.set( x, y, w, h, minZ, maxZ );
	m_updateFlag |= ksVIEWPORT_UPDATE;
}

/*************************************************************************************************/
/*
 * ビューポートのセット
 * @param		viewport	ビューポート
 */
/*************************************************************************************************/
void KsCamera::setViewport( const KsViewport& viewport )
{
	m_viewport.set( viewport.m_x, viewport.m_y, viewport.m_w, viewport.m_h, viewport.m_minZ, viewport.m_maxZ );
	m_updateFlag |= ksVIEWPORT_UPDATE;
}

/*************************************************************************************************/
/*
 * 透視射影行列を生成する
 * @param		fovy		視野角
 * @param		aspect		アスペクト比
 * @param		zNear		近距離値
 * @param		zFar		遠距離値
 */
/*************************************************************************************************/
void KsCamera::setPerspective( KsReal fovy, KsReal aspect, KsReal zNear, KsReal zFar )
{
	m_fovy   = fovy;
	m_aspect = aspect;
	m_zNear  = zNear;
	m_zFar   = zFar;

	m_projectionType = ksPERSPECTIVE;

	if( m_coordinateType == ksCOORD_LEFT )
	{
		KsMatrixPerspectiveLH( m_projMatrix, m_fovy, m_aspect, m_zNear, m_zFar );
	}
	else
	{
		KsMatrixPerspectiveRH( m_projMatrix, m_fovy, m_aspect, m_zNear, m_zFar );
	}

	m_updateFlag |= ksPROJECTION_UPDATE;
}

/*************************************************************************************************/
/*
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
/*************************************************************************************************/
void KsCamera::setOrtho( KsReal left, KsReal right, KsReal bottom, KsReal top, KsReal zNear, KsReal zFar )
{
	m_left   = left;
	m_right  = right;
	m_bottom = bottom;
	m_top    = top;
	m_zNear  = zNear;
	m_zFar   = zFar;

	m_projectionType = ksORTHOGRAPHIC;
	m_updateFlag |= ksPROJECTION_UPDATE;
}

/*************************************************************************************************/
/*
 * カメラのLook-Atをセットする
 * @param	eye		視点位置
 * @param	target	ターゲット
 * @param	up		up ベクトル
 */
/*************************************************************************************************/
void KsCamera::lookAt( const KsVector3d& eye, const KsVector3d& target, const KsVector3d& up )
{
	if( m_coordinateType == ksCOORD_LEFT )
	{
		KsMatrixLookAtLH( m_viewMatrix, eye, target, up );
	}
	else
	{
		KsMatrixLookAtRH( m_viewMatrix, eye, target, up );
	}
	m_updateFlag |= ksVIEWMATRIX_UPDATE;
}

/*************************************************************************************************/
/*
 * 描画開始
 */
/*************************************************************************************************/
void KsCamera::beginRender()
{
//	KsAssert( m_pRenderSystem != NULL, "renderSystem null pointer\n" );

	if( !m_pRenderSystem )
	{
		return;
	}

	/* 更新処理 */
	update();

	/* 描画開始 */
	//m_pRenderSystem->beginScene( m_clearFlags, m_clearColor, m_clearDepth, m_clearSstencil );
}

/*************************************************************************************************/
/*
 * 描画終了
 */
/*************************************************************************************************/
void KsCamera::endRender()
{
	if( !m_pRenderSystem )
	{
		return;
	}

	/* 描画終了 */
	//m_pRenderSystem->endScene();
}

/*************************************************************************************************/
/*
 * 更新処理
 */
/*************************************************************************************************/
void KsCamera::update()
{
	if( m_updateFlag )
	{
		/* viewport */
		if( m_updateFlag & ksVIEWPORT_UPDATE )
		{

		}

		/* プロジェクション */
		if( m_updateFlag & ksPROJECTION_UPDATE )
		{
			if( m_coordinateType == ksCOORD_LEFT )
			{
				/* 左手系 */
				if( m_projectionType == ksPERSPECTIVE )
				{
					KsMatrixPerspectiveLH( m_projMatrix, m_fovy, m_aspect, m_zNear, m_zFar );
				}
				else if( m_projectionType == ksORTHOGRAPHIC )
				{
					KsMatrixOrthoLH( m_projMatrix, m_left, m_right, m_bottom, m_top, m_zNear, m_zFar );
				}
			}
			else if( m_coordinateType == ksCOORD_RIGHT )
			{
				/* 右手系 */
				if( m_projectionType == ksPERSPECTIVE )
				{
					KsMatrixPerspectiveRH( m_projMatrix, m_fovy, m_aspect, m_zNear, m_zFar );
				}
				else if( m_projectionType == ksORTHOGRAPHIC )
				{
					KsMatrixOrthoRH( m_projMatrix, m_left, m_right, m_bottom, m_top, m_zNear, m_zFar );
				}
			}
		}

		/* ビューマトリックス */
		if( m_updateFlag & ksVIEWMATRIX_UPDATE )
		{
		}

		/* フラスタム */
		if( m_updateFlag & ksFRUSUM_UPDATE )
		{
			
		}

		m_viewProjMatrix = m_viewMatrix * m_projMatrix;

		m_updateFlag = ksNONE_UPDATE;
	}

	if( !m_pRenderSystem )
	{
		return;
	}
}

ksNS_KS_END

