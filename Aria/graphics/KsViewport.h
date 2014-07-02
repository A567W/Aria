/************************************************************************************************/
/** 
 * @file		KsViewport.h
 * @brief		ビューポー
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0
 */
/************************************************************************************************/
#ifndef __KSVIEWPORT_H__
#define __KSVIEWPORT_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                           */
/*==============================================================================================*/
#include "KsBase.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class		KsViewport
 * @brief		ビューポートクラス
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 */
/************************************************************************************************/
class ksENGINE_API KsViewport
{
	public:
		KsInt32					m_x;		/**< X座標		*/
		KsInt32					m_y;		/**< Y座標		*/
		KsInt32					m_w;		/**< 幅			*/
		KsInt32					m_h;		/**< 高さ		*/
		KsReal					m_minZ;		/**< minZ値		*/
		KsReal					m_maxZ;		/**< maxZ値		*/
		
		/**
		 * コンストラクタ
		 * @note すべて 0で初期化
		 */
								KsViewport() : m_x( 0 ), m_y( 0 ), m_w( 0 ), m_h( 0 ), m_minZ( 0.0f ), m_maxZ( 0.0f ) {}
		
		/**
		 * コンストラクタ
		 * @param		x		X座標
		 * @param		y		X座標
		 * @param		w		幅
		 * @param		h		高さ
		 * @param		near	nearクリップ値
		 * @param		far		farクリップ値
		 */
								KsViewport( KsInt32 x, KsInt32 y, KsInt32 w, KsInt32 h, KsReal minZ, KsReal maxZ ) : m_x( x ), m_y( y ), m_w( w ), m_h( h ), m_minZ( minZ ), m_maxZ( maxZ ) {}
	
		/**
		 * セット
		 * @param		x		X座標
		 * @param		y		X座標
		 * @param		w		幅
		 * @param		h		高さ
 		 * @param		near	nearクリップ値
		 * @param		far		farクリップ値
		 */
		void					set( KsInt32 x, KsInt32 y, KsInt32 w, KsInt32 h, KsReal minZ, KsReal maxZ ) { m_x = x; m_y = y; m_w = w; m_h = h; m_minZ = minZ; m_maxZ = maxZ; }


		KsBool					operator == (const KsViewport& vp) const { return (m_x == vp.m_x) && (m_y == vp.m_y) && (m_w == vp.m_w) && (m_h == vp.m_h) && (m_minZ == vp.m_minZ) && (m_maxZ == vp.m_maxZ); }
		KsBool					operator != (const KsViewport& vp) const { return !operator == (vp); }
};

ksNS_KS_END

#endif		/* __KSVIEWPORT_H__ */



