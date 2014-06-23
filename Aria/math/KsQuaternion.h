/************************************************************************************************/
/** 
 * @file		KsQuaternion.h
 * @brief		クォータニオン操作
 * @author		A567W
 * @version		1.0.0
 */
/************************************************************************************************/
#ifndef __KSQUATERNION_H__
#define __KSQUATERNION_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsMathBase.h"
#include "KsVector.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

class KsMatrix3x3;
class KsMatrix4x4;

/************************************************************************************************/
/**
 *	@class	KsQuaternion
 *	@brief	クォータニオン操作クラス
 *	@autor	A567W
 */
/************************************************************************************************/
class ksENGINE_API KsQuaternion
{
	public:
		/**
		 * マトリックスの要素成分
		 */
		KsReal							x, y, z, w;

		/**
		 * コンストラクタ					 単位行列で初期化されます
		 */
										KsQuaternion() : x( 0.0f ), y( 0.0f ), z( 0.0f ), w( 1.0f ) {}

		/**
		 * コンストラクタ
		 * @param	farray				初期化する値, この配列の順に 要素を初期化します
		 */
										KsQuaternion( const KsReal* fArray ) : x( fArray[0] ), y( fArray[1] ), z( fArray[2] ), w( fArray[3] ) {}

		/**
		 * コンストラクタ
		 * @param	farray				初期化する値, この配列の順に 要素を初期化します
		 */
										KsQuaternion( KsReal qx, KsReal qy, KsReal qz, KsReal qw ) : x( qx ), y( qy ), z( qz ), w( qw ) {}

										KsQuaternion( const KsMatrix3x3& refMatrix );

										//KsQuaternion( const KsMatrix4x4& refMatrix );
		/**
		 * KsRealのポインタに変換してで取得できるようにする
		 */
										operator KsReal* () { return &x; }

		/**
		 * KsRealのポインタに変換してで取得できるようにする
		 */
										operator const KsReal* () const { return &x; }

		/**
		 *
		 */
		KsQuaternion&					operator = ( const KsQuaternion& refQuat );
		//KsQuaternion&					operator = ( const KsMatrix4x4& refMatrix );

		KsQuaternion&					operator += ( const KsQuaternion& refQuat );
		KsQuaternion&					operator -= ( const KsQuaternion& refQuat );
		KsQuaternion&					operator *= ( const KsQuaternion& refQuat );
		KsQuaternion&					operator *= ( KsReal s );
		KsQuaternion&					operator /= ( KsReal s );
	
		KsQuaternion					operator ~ () const;
		KsQuaternion					operator + () const;
		KsQuaternion					operator - () const;
	
		KsQuaternion					operator + ( const KsQuaternion& refQuat ) const;
		KsQuaternion					operator - ( const KsQuaternion& refQuat ) const;
		KsQuaternion					operator * ( const KsQuaternion& refQuat ) const;
		KsQuaternion					operator * ( KsReal s ) const;
		KsQuaternion					operator / ( KsReal s ) const;

		KsBool							operator == ( const KsQuaternion& refQuat ) const;
		KsBool							operator != ( const KsQuaternion& refQuat ) const;


		friend KsQuaternion				operator * ( KsReal s, const KsQuaternion& v ) { return v * s; }

		//逆行列
	

		KsReal							length() const;

		KsReal							length2() const;

		//Dot

		/**
		 * 正規化する
		 */
		void							normalize();

		/**
		 * 逆クォータニオン
		 */
		void							inverse();

		void							fromAxisRotation( const KsVector3d& refAxis, KsReal angle );
		void							fromEulerAngles( KsReal angleX, KsReal angleY, KsReal angleZ );

		//void							convertToMatrix( KsMatrix4x4* pMatrix );
		void							convertToAxisRotation( KsVector3d* pAxis, KsReal* pAngle );
		//void							convertToEuler( KsVector3d* pOut );

		static const KsQuaternion		IDENTITY;

};


/*************************************************************************************************/
/*---------------------------<< インライン部分ヘッダーファイル >>------------------------------------*/
								#include "KsQuaternion.inl"
/*-----------------------------------------------------------------------------------------------*/
/*************************************************************************************************/

ksNS_KS_END

#endif /* __KSQUATERNION_H__ */

