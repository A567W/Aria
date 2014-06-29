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
 * @file	KsMatrix4x4.h
 * @brief	マトリックス操作
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
/************************************************************************************************/
#ifndef __KSMATRIX4X4_H__
#define __KSMATRIX4X4_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                           */
/*==============================================================================================*/
#include "KsMathCommon.h"
#include "KsVector.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

class KsQuaternion;
class KsPlane;

/*************************************************************************************************/
/**
 * @class	KsMatrix4x4
 * @brief	マトリックス操作クラス
 * @author	A567W
 * @date	----/--/--
 * @since	----/--/--
 */
/*************************************************************************************************/
class ksENGINE_API KsMatrix4x4
{
	public:
		/**
		 * マトリックスの要素成分
		 */
		union
		{
			struct
			{
				KsReal	m11, m12, m13, m14;
				KsReal	m21, m22, m23, m24;
				KsReal	m31, m32, m33, m34;
				KsReal	m41, m42, m43, m44;
			};
			KsReal		m[ 4 ][ 4 ];
			KsReal		data[ 16 ];
		};

		/**
		 * コンストラクタ					単位行列で初期化されます
		 */
										KsMatrix4x4() :  m11(1.0f), m12(0.0f), m13(0.0f), m14(0.0f),
														 m21(0.0f), m22(1.0f), m23(0.0f), m24(0.0f),
														 m31(0.0f), m32(0.0f), m33(1.0f), m34(0.0f),
														 m41(0.0f), m42(0.0f), m43(0.0f), m44(1.0f) {}
		/**
		 * コンストラクタ
		 * @param	farray				初期化する値, この配列の順に 要素を初期化します
		 */
										KsMatrix4x4( const KsReal* fArray )
												:  m11( fArray[ 0] ), m12( fArray[ 1] ), m13( fArray[ 2] ), m14( fArray[ 3] ),
												   m21( fArray[ 4] ), m22( fArray[ 5] ), m23( fArray[ 6] ), m24( fArray[ 7] ),
												   m31( fArray[ 8] ), m32( fArray[ 9] ), m33( fArray[10] ), m34( fArray[11] ),
												   m41( fArray[12] ), m42( fArray[13] ), m43( fArray[14] ), m44( fArray[15] ) {}

		/**
		 * コンストラクタ(copy)
		 * @param	refMatrix			引数の値をコピーして初期化します
		 */
										KsMatrix4x4( const KsMatrix4x4& refMatrix )
												:  m11( refMatrix.m11 ), m12( refMatrix.m12 ), m13( refMatrix.m13 ), m14( refMatrix.m14 ),
												   m21( refMatrix.m21 ), m22( refMatrix.m22 ), m23( refMatrix.m23 ), m24( refMatrix.m24 ),
												   m31( refMatrix.m31 ), m32( refMatrix.m32 ), m33( refMatrix.m33 ), m34( refMatrix.m34 ),
												   m41( refMatrix.m41 ), m42( refMatrix.m42 ), m43( refMatrix.m43 ), m44( refMatrix.m44 ) {}


		/**
		 * コンストラクタ					それぞれの引数で要素を初期化します
		 */								
										KsMatrix4x4(  KsReal me11, KsReal me12, KsReal me13, KsReal me14,
												   KsReal me21, KsReal me22, KsReal me23, KsReal me24,
												   KsReal me31, KsReal me32, KsReal me33, KsReal me34,
												   KsReal me41, KsReal me42, KsReal me43, KsReal me44 )
												 : m11( me11 ), m12( me12 ), m13( me13 ), m14( me14 ),
												   m21( me21 ), m22( me22 ), m23( me23 ), m24( me24 ),
												   m31( me31 ), m32( me32 ), m33( me33 ), m34( me34 ),
												   m41( me41 ), m42( me42 ), m43( me43 ), m44( me44 ) {}

		/**
		 * コンストラクタ				 
		 */
										KsMatrix4x4( const KsQuaternion& refQuat );

		/**
		 * KsRealのポインタに変換してで取得できるようにする
		 */
										operator KsReal* () { return &m[ 0 ][ 0 ]; }
	
		/**
		 * KsRealのポインタに変換してで取得できるようにする
		 */
										operator const KsReal* () const { return &m[ 0 ][ 0 ]; }
	
		/**
		 * KsRealのポインタに変換してで取得できるようにする
		 */
		KsReal*							operator [] ( KsInt32 index ) { return &m[ index ][ 0 ]; }

		/**
		 * KsRealのポインタに変換してで取得できるようにする
		 */
		const KsReal*					operator [] ( KsInt32 index ) const { return &m[ index ][ 0 ]; }

		KsMatrix4x4&					operator = ( const KsMatrix4x4& refMatrix );
		KsMatrix4x4&					operator = ( const KsQuaternion& refMatrix );

		KsMatrix4x4&					operator *= ( const KsMatrix4x4& refMatrix );
		KsMatrix4x4&					operator += ( const KsMatrix4x4& refMatrix );
		KsMatrix4x4&					operator -= ( const KsMatrix4x4& refMatrix );
		KsMatrix4x4&					operator *= ( KsReal s );
		KsMatrix4x4&					operator /= ( KsReal s );

		//KsMatrix4x4					operator ~ () const;
		KsMatrix4x4						operator + () const;
		KsMatrix4x4						operator - () const;

		KsMatrix4x4						operator * ( const KsMatrix4x4& refMatrix ) const;
		KsMatrix4x4						operator + ( const KsMatrix4x4& refMatrix ) const;
		KsMatrix4x4						operator - ( const KsMatrix4x4& refMatrix ) const;

		KsMatrix4x4						operator * ( KsReal s ) const;
		KsMatrix4x4						operator / ( KsReal s ) const;

		KsBool							operator == ( const KsMatrix4x4& refMatrix ) const;
		KsBool							operator != ( const KsMatrix4x4& refMatrix ) const;

		friend KsMatrix4x4				operator * ( KsReal s, const KsMatrix4x4& refMatrix );
	
		/**
		 * 値をセットする
		 * @param	farray				初期化する値, この配列の順に 要素を初期化します
		 * @return						値がセットされたマトリックス
		 */
		const KsMatrix4x4&				set( const KsReal* fArray );

		/**
		 * クォータニオンから変換して値をセットする
		 * @param	refQuat				クォータニオン
		 * @return						値がセットされたマトリックス
		 */
		const KsMatrix4x4&				set( const KsQuaternion& refQuat );

		/**
		 * デタミナントを取得する
		 * @return						デタミナント
		 */
		KsReal							determinant() const;

		/**
		 * 転置する
		 */
		void							transpose();

		/**
		 * 小行列を取得する
		 * @return						小行列
		 */
		const KsReal					minor( KsInt32 x, KsInt32 y ) const;

		/**
		 * 随伴行列を取得する
		 * @return						随伴行列
		 */
		const KsMatrix4x4				adjoint() const;

		/**
		 * 逆行列を取得する
		 * A^-1 = 1/|A| * ~A (逆行列の公式を使う)
		 * デタミナントは余因子展開(|A| = Σ(-1)^(i+j) * a_ij*|A_ij| )
		 * @return						逆行列
		 */
		KsMatrix4x4						inverse() const;

		/*
		 * クォータニオンから偏微分行列を作る
		 */
		void							partialDifferential( const KsQuaternion &q, const KsQuaternion &dq );

		void							setTranslate( KsReal x, KsReal y, KsReal z );
		void							setTranslate( const KsVector3d& v );
		void							setTranslate( const KsVector3d* v );
		void							setScaleX( KsReal sx );
		void							setScaleY( KsReal sy );
		void							setScaleZ( KsReal sz );
		void							setScale( KsReal scale );
		void							setScale( KsReal sx, KsReal sy, KsReal sz );
		void							setScale( const KsVector3d& refScale );
		void							setScale( const KsVector3d* pScale );
		void							setRotateX( KsReal angle );
		void							setRotateY( KsReal angle );
		void							setRotateZ( KsReal angle );

		void							setEulerZYX( KsReal eulerX, KsReal eulerY, KsReal eulerZ );

		KsVector3d						getTranslate();
		KsQuaternion					getRotate();
		KsVector3d						getScale();

		//逆行列
	
		/**
		 * 単位行列
		 */
		static const KsMatrix4x4		IDENTITY;

		static KsMatrix4x4				CreateScale( const KsVector3d& refScale );
		static KsMatrix4x4				CreateFromQuaternion( const KsQuaternion& refQuat );
		static KsMatrix4x4				CreateTranslation( const KsVector3d& refTranslate );

		static const KsMatrix4x4		PerspectiveRH( KsReal fovy, KsReal aspect, KsReal zNear, KsReal zFar );

		/**
		 * クォータニオンから偏微分行列を作る
		 */
		static KsMatrix4x4				CreatePartialDifferential( const KsQuaternion &q, const KsQuaternion &dq );
};

/*************************************************************************************************/
/*---------------------------<< インライン部分ヘッダーファイル >>------------------------------------*/
								#include "KsMatrix4x4.inl"
/*-----------------------------------------------------------------------------------------------*/
/*************************************************************************************************/



/************************************************************************************************/
/**
 * 透視射影行列を生成する(右手系)
 * @param		projMatrix		プロジェクションマトリックス保存用
 * @param		fovy			視野角
 * @param		aspect			アスペクト比
 * @param		zNear			近距離値
 * @param		zFar			遠距離値
 */
/************************************************************************************************/
ksENGINE_API void KsMatrixPerspectiveRH( KsMatrix4x4& projMatrix, KsReal fovy, KsReal aspect, KsReal zNear, KsReal zFar );

/************************************************************************************************/
/**
 * 正射影行列を生成する(右手系)
 * @param		projMatrix		プロジェクションマトリックス保存用
 * @param		left			レフト
 * @param		right			ライト
 * @param		bottom			ボトム
 * @param		top				トップ
 * @param		aspect			アスペクト比
 * @param		zNear			近距離値
 * @param		zFar			遠距離値
 */
/************************************************************************************************/
ksENGINE_API void KsMatrixOrthoRH( KsMatrix4x4& projMatrix, KsReal left, KsReal right, KsReal bottom, KsReal top, KsReal zNear, KsReal zFar );

/************************************************************************************************/
/**
 * 視点を設定する(右手系)
 * @param		viewMatrix		ビューマトリックス保存用
 * @param		eye				視点
 * @param		at				注視点
 * @param		up				アップベクトル
 */
/************************************************************************************************/
ksENGINE_API void KsMatrixLookAtRH( KsMatrix4x4& viewMatrix, const KsVector3d& eye, const KsVector3d& at, const KsVector3d& up );

/************************************************************************************************/
/**
 * 透視射影行列を生成する(左手系)
 * @param		projMatrix		プロジェクションマトリックス保存用
 * @param		fovy			視野角
 * @param		aspect			アスペクト比
 * @param		zNear			近距離値
 * @param		zFar			遠距離値
 */
/************************************************************************************************/
ksENGINE_API void KsMatrixPerspectiveLH( KsMatrix4x4& projMatrix, KsReal fovy, KsReal aspect, KsReal zNear, KsReal zFar );

/************************************************************************************************/
/**
 * 正射影行列を生成する(左手系)
 * @param		projMatrix		プロジェクションマトリックス保存用
 * @param		left			レフト
 * @param		right			ライト
 * @param		bottom			ボトム
 * @param		top				トップ
 * @param		aspect			アスペクト比
 * @param		zNear			近距離値
 * @param		zFar			遠距離値
 */
/************************************************************************************************/
ksENGINE_API void KsMatrixOrthoLH( KsMatrix4x4& projMatrix, KsReal left, KsReal right, KsReal bottom, KsReal top, KsReal zNear, KsReal zFar );

/************************************************************************************************/
/**
 * 視点を設定する(左手系)
 * @param		viewMatrix		ビューマトリックス保存用
 * @param		eye				視点
 * @param		at				注視点
 * @param		up				アップベクトル
 */
/************************************************************************************************/
ksENGINE_API void KsMatrixLookAtLH( KsMatrix4x4& viewMatrix, const KsVector3d& eye, const KsVector3d& at, const KsVector3d& up );

/************************************************************************************************/
/**
 * ライトから影を射影するように,ジオメトリを平面に射影する。
 * @param		matrix			ビューマトリックス保存用
 * @param		eye				視点
 * @param		at				注視点
 * @param		up				アップベクトル
 * @note
 * <pre>
 * この関数が返す行列は、次の公式を使って計算する。 
 *	P = normalize(Plane);
 *	L = Light;
 *	d = dot(P, L)
 *
 *	P.a * L.x + d  P.a * L.y      P.a * L.z      P.a * L.w  
 *	P.b * L.x      P.b * L.y + d  P.b * L.z      P.b * L.w  
 *	P.c * L.x      P.c * L.y      P.c * L.z + d  P.c * L.w  
 *	P.d * L.x      P.d * L.y      P.d * L.z      P.d * L.w + d
 * </pre>
 */
/************************************************************************************************/
ksENGINE_API void KsMatrixShadow( KsMatrix4x4& shadowMatrix, const KsVector3d& light, const KsPlane& refPlane, KsReal point );

ksNS_KS_END

#endif /* __KSMATRIX4X4_H__ */

