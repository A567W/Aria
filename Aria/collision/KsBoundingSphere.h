/************************************************************************************************/
/** 
 * @file		KsBoundingSphere.h
 * @brief		バウンディングスフィア
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/
#ifndef __KSBOUNDINGSPHERE_H__
#define __KSBOUNDINGSPHERE_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsCollisionCommon.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN


/************************************************************************************************/
/**
 * @class		KsBoundingSphere
 * @brief		バウンディングスフィア
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 */
/************************************************************************************************/
class ksENGINE_API KsBoundingSphere
{
	private:
		KsVector3d				m_center;	/**< 球の中心点。	*/
		KsReal					m_radius;	/**< 球の半径		*/

	public:
		/**
		 * コンストラクタ
		 */
		KsBoundingSphere();

		/**
		 * コンストラクタ
		 * @brief	KsBoundingSphere の新しいインスタンスを作成します。
		 * @param	center		球の中心点。
		 * @param	radius		球の半径。
		 */
		KsBoundingSphere( const KsVector3d& center, KsReal radius );

		/**
		 * コンストラクタ
		 * @brief	KsBoundingSphere の新しいインスタンスを作成します。
		 * @param	cx			球の中心点のX座標。
		 * @param	cy			球の中心点のX座標。
		 * @param	cz			球の中心点のX座標。
		 * @param	radius		球の半径。
		 */
		KsBoundingSphere( KsReal cx, KsReal cy, KsReal cz, KsReal radius );

		/**
		 * 描画呼び出し中に使用される頂点の数を取得します。
		 * @return	球の中心点
		 */
		const KsVector3d&		getCenter() { return m_center; }

		/**
		 * レンダリングするプリミティブの数を取得します。
		 * @return	球の半径
		 */
		KsReal					getRadius() const { return m_radius; }

		/**
		 * KsBoundingSphere をセットします。
		 * @param	center		球の中心点。
		 * @param	radius		球の半径。
		 */
		void					set( const KsVector3d& center, KsReal radius );

		/**
		 * KsBoundingSphere をセットします。
		 * @param	cx			球の中心点のX座標。
		 * @param	cy			球の中心点のX座標。
		 * @param	cz			球の中心点のX座標。
		 * @param	radius		球の半径。
		 */
		void					set( KsReal cx, KsReal cy, KsReal cz, KsReal radius );

		/**
		 * 球の中心点をセットします。
		 * @param	center		球の中心点。
		 */
		void					setCenter( const KsVector3d& center ) { m_center = center; }

		/**
		 * 球の中心点をセットします。
		 * @param	cx			球の中心点のX座標。
		 * @param	cy			球の中心点のX座標。
		 * @param	cz			球の中心点のX座標。
		 */
		void					setCenter( KsReal cx, KsReal cy, KsReal cz ) { m_center.set( cx, cy, cz ); }

		/**
		 * レンダリングするプリミティブの数をセットします。
		 * @param	radius		球の半径
		 */
		void					setRadius( KsReal radius ) { m_radius = radius; }
};

ksNS_KS_END

#endif		/* __KSBOUNDINGSPHERE_H__ */



