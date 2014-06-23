/*************************************************************************************************/
/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2014 A567W
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 * 
 * @file	KsPlane.h
 * @brief	平面の操作
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
/************************************************************************************************/
#ifndef __KSPLANE_H__
#define __KSPLANE_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                             */
/*==============================================================================================*/
#include "KsMath.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class	KsPlane
 * @brief	平面のクラス
 * @author	A567W
 */
/*************************************************************************************************/
class ksENGINE_API KsPlane
{
	public:
		KsVector3d					m_normal;		/**< 面の法線ベクトル		*/
		KsReal						m_distance;		/**< 面の高さ				*/
	
		/**
		 * コンストラクタ				0で初期化されます
		 */
									KsPlane() : m_normal( 0.0f, 0.0f, 0.0f ), m_distance( 0.0f ){};

		/**
		 * コンストラクタ(copy)
		 * @param	refPlane		コピー元の平面	
		 */											
									KsPlane( const KsPlane& refPlane ) : m_normal( refPlane.m_normal ), m_distance( refPlane.m_distance ){};
	
		/**
		 * コンストラクタ				法線と高さから平面を生成
		 * @param	refNormal		平面の法線ベクトル
		 * @param	distance		平面の高さ
		 */
									KsPlane( const KsVector3d& refNormal, KsReal distance ) : m_normal( refNormal ), m_distance( distance ){};
	
		/**
		 * コンストラクタ				3点を通る平面セットして生成します
		 * @param	refPointA		第1頂点
		 * @param	refPointB		第2頂点
		 * @param	refPointC		第3頂点
		 */
									KsPlane( const KsVector3d& refPointA, const KsVector3d& refPointB, const KsVector3d& refPointC ){ set( refPointA, refPointB, refPointC ); };
	
		/**
		 * コンストラクタ				面の法線ベクトルと面上の点から高さを求めて生成します
		 * @param	refNormal		平面の法線ベクトル
		 * @param	refPoint		面上の頂点
		 */
									KsPlane( const KsVector3d& refNormal, const KsVector3d& refPoint ){ set( refNormal, refPoint ); };
	
		/**
		 * 平面のセット				法線と高さから平面を生成
		 * @param	refNormal		平面の法線ベクトル
		 * @param	distance		平面の高さ
		 */
		void						set( const KsVector3d& refNormal, KsReal distance );
	
		/**
		 * 平面のセット				3点を通る平面セットして生成します
		 * @param	refPointA		第1頂点
		 * @param	refPointB		第2頂点
		 * @param	refPointC		第3頂点
		 */
		void						set( const KsVector3d& refPointA, const KsVector3d& refPointB, const KsVector3d& refPointC );
	
		/**
		 * 平面のセット				面の法線ベクトルと面上の点から高さを求めて生成します
		 * @param	refNormal		平面の法線ベクトル
		 * @param	refPoint		面上の頂点
		 */
		void						set( const KsVector3d& refNormal, const KsVector3d& refPoint );

		/**
		 * YZ平面から垂線を伸ばして交差した場所のX座標を取得する
		 * @param	y				y座標
		 * @param	z				z座標
		 * @return					x座標
		 */
		KsReal						getX( KsReal y, KsReal z );
	
		/**
		 * XZ平面から垂線を伸ばして交差した場所のY座標を取得する
		 * @param	x				x座標
		 * @param	z				z座標
		 * @return					y座標
		 */
		KsReal						getY( KsReal x, KsReal z );
	
		/**
		 * XY平面から垂線を伸ばして交差した場所のZ座標を取得する
		 * @param	x				x座標
		 * @param	y				y座標
		 * @return					z座標
		 */
		KsReal						getZ( KsReal x, KsReal y );
	 
		/**
		 * YZ平面から垂線を伸ばして交差した座標を取得する
		 * @param	y				y座標
		 * @param	z				z座標
		 * @return					平面上の点
		 */
		KsVector3d					getPointX( KsReal y, KsReal z );
	
		/**
		 * XZ平面から垂線を伸ばして交差した座標を取得する
		 * @param	x				x座標
		 * @param	z				z座標
		 * @return					平面上の点
		 */
		KsVector3d					getPointY( KsReal x, KsReal z );
	
		/**
		 * XY平面から垂線を伸ばして交差した座標を取得する
		 * @param	x				x座標
		 * @param	y				y座標
		 * @return					平面上の点
		 */
		KsVector3d					getPointZ( KsReal x, KsReal y );
	
		/**
		 * 平面上の1点を取得する
		 * @return					平面上のポイント
		 */
		KsVector3d					getOnPoint() const;
	
		/**
		 * 点と平面の距離を求める
		 * @param	refPoint		ポイント
		 */
		KsReal						distance( const KsVector3d& refPoint ) const;
	
		/**
		 * 平面を代入します
		 * @param	refPlane		平面のコピー元
		 */
		KsPlane&					operator = ( const KsPlane& refPlane );
	
		/**
		 * 平面が等しいかどうかを判定する
		 * @param	refPlane		判定する平面
		 * @retval	ksTRUE			等しい
		 * @retval	ksFALSE			等しくない
		 */
		KsBool						operator == ( const KsPlane& refPlane ) const;
	
		/**
		 * 平面が等しくないかどうかを判定する
		 * @param	refPlane		判定する平面
		 * @retval	ksTRUE			等しくない
		 * @retval	ksFALSE			等しい
		 */
		KsBool						operator != ( const KsPlane& refPlane ) const;
};

/*************************************************************************************************/
/*---------------------------<< インライン部分ヘッダーファイル >>------------------------------------*/
								#include "KsPlane.inl"
/*-----------------------------------------------------------------------------------------------*/
/*************************************************************************************************/

ksNS_KS_END

#endif /* __KSPLANE_H__ */

