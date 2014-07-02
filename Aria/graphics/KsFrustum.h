/************************************************************************************************/
/** 
 * @file		KsFrustum.h
 * @brief		ビューポー
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0
 */
/************************************************************************************************/
#ifndef __KSFRUSTUM_H__
#define __KSFRUSTUM_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                           */
/*==============================================================================================*/
#include "KsGraphicsCommon.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * フラスタム
 * @class		KsFrustum
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 */
/************************************************************************************************/
class ksENGINE_API KsFrustum
{
	public:
		/**
		 * フラスタム構成の面
		 */
		enum ksFRUSTUM_PLANE_KIND
		{
			ksFRUSTUM_PLANE_NEAR   = 0,
			ksFRUSTUM_PLANE_FAR    = 1,
			ksFRUSTUM_PLANE_LEFT   = 2,
			ksFRUSTUM_PLANE_RIGHT  = 3,
			ksFRUSTUM_PLANE_TOP    = 4,
			ksFRUSTUM_PLANE_BOTTOM = 5,
			ksFRUSTUM_PLANE_NUM    = 6,
		};

	public:
		/**
		 * コンストラクタ
		 */
									KsFrustum();
		
		/**
		 * デストラクタ
		 */
		virtual					~KsFrustum();

		/**
		 * アウトラインの描画（デバック用）
		 */
		void						drawOutLine();

#if 0


		
		/**
		* Test if point is inside volume
		* \param rkPoint                Point to check
		* \return                       true if inside volume, false otherwise
		*/
		virtual KsBool				intersection( const NeVector3d &rkPoint );

		/**
		* Test if line intersects with volume
		* \param rkLine                 Line to check
		* \return                       true if intersection with volume, false otherwise
		*/
		virtual KsBool				intersection( const NeLine &rkLine );

		/**
		* Test if intersection with plane
		* \param rkPlane                Plane to check
		* \return                       true if intersection, false otherwise
		*/
		virtual KsBool				intersection( const NePlane &rkPlane );

		/**
		* Test if intersection with polygon
		* \param rkV0                   First corner
		* \param rkV1                   Second corner
		* \param rkV2                   Third corner
		* \param rkNormal               Optional precalculated normal
		* \return                       true if intersection, false otherwise
		*/
		virtual KsBool				intersection( const NeVector3d &rkV0, const NeVector3d &rkV1, const NeVector3d &rkV2, const NeVector3d &rkNormal = NeVector3d::ORIGO );

#endif

	public:
		KsUInt8						m_aiPVertexSign[ 6 ][ 3 ];	/**< Vertex signs. These indicate which box corner in the AA box should be used as near and far vertex when culling against frustum during rendering. 6 planes in frustum as first index. Second index is vertex component, 0 = x, 1 = y, 2 = z. A value of 0 is positive and 1 is negative */
		KsUInt8						m_aiNVertexSign[ 6 ][ 3 ];	/**< N is inverted P but precalculate to gain speed */
		KsMatrix4x4					m_viewMatrix;				/**< ビューマトリックス		*/
		KsVector3d					m_direction;				/**< View vector (which is -zvector of rotation of course)*/
		KsPlane						m_planes[ 6 ];				/**< Frustumを構成する平面	*/
		KsReal						m_near;						/**< ニアクリップ			*/
		KsReal						m_far;						/**< ファクリップ			*/
};

ksNS_KS_END

#endif		/* __KSFRUSTUM_H__ */


