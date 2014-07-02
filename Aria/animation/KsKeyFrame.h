/************************************************************************************************/
/** 
 * @file		KsKeyFrame.h
 * @brief		キーフレームデータ
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/
#ifndef __KSKEYFRAME_H__
#define __KSKEYFRAME_H__

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

/************************************************************************************************/
/**
 * @class		KsKeyFrame
 * @brief		キーフレームデータ
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 */
/************************************************************************************************/
class ksENGINE_API KsKeyFrame
{
	private:
		KsInt32						m_time;				/**< 時間			*/
		KsVector3d					m_scale;			/**< スケール値		*/
		KsVector3d					m_translate;		/**< 移動値			*/
		KsQuaternion				m_rotation;			/**< 回転値			*/
		KsMatrix4x4					m_transform;		/**< 変換行列		*/
		KsBezier					m_bezierX;			/**< X軸移動補間		*/
		KsBezier					m_bezierY;			/**< Y軸移動補間		*/
		KsBezier					m_bezierZ;			/**< Z軸移動補間		*/
		KsBezier					m_bezierAngle;		/**< 回転補間		*/

	public:
		/**
		 * コンストラクタ
		 */
		KsKeyFrame();

		/**
		 * コンストラクタ
		 */
		KsKeyFrame( const KsVector3d& translate, KsInt32 time );

		/**
		 * コンストラクタ
		 */
		KsKeyFrame( const KsQuaternion& rotation, KsInt32 time );

		/**
		 * コンストラクタ
		 */
		KsKeyFrame( const KsVector3d& translate, const KsQuaternion& rotation, const KsVector3d& scale, KsInt32 time );

		/**
		 * コンストラクタ
		 */
		KsKeyFrame( const KsVector3d& translate, const KsQuaternion& rotation, KsInt32 time );

		/**
		 * コンストラクタ
		 */
		KsKeyFrame( const KsMatrix4x4& transform, KsInt32 time );

		/**
		 * デストラクタ
		 */
		~KsKeyFrame();

		void						setBezierX( KsReal val0, KsReal val1, KsReal val2, KsReal val3 );
		void						setBezierY( KsReal val0, KsReal val1, KsReal val2, KsReal val3 );
		void						setBezierZ( KsReal val0, KsReal val1, KsReal val2, KsReal val3 );
		void						setBezierAngle( KsReal val0, KsReal val1, KsReal val2, KsReal val3 );

		KsInt32						getTime() const { return m_time; }

		const KsVector3d&			getScale() { return m_scale; }

		const KsVector3d&			getTranslate() { return m_translate; }

		const KsQuaternion&			getRotation() { return m_rotation; }

		const KsBezier&				getBezierX() { return m_bezierX; }
		const KsBezier&				getBezierY() { return m_bezierY; }
		const KsBezier&				getBezierZ() { return m_bezierZ; }
		const KsBezier&				getBezierAngle() { return m_bezierAngle; }
};

ksNS_KS_END

#endif /* __KSKEYFRAME_H__ */

