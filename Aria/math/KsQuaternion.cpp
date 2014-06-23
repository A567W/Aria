/************************************************************************************************/
/** 
 * @file		KsQuaternion.cpp
 * @brief		クォータニオン操作
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/

/*==============================================================================================*/
/*                                 << インクルード >>                                           */
/*==============================================================================================*/
#include "KsQuaternion.h"
#include "KsMatrix3x3.h"
#include "KsMatrix4x4.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
// 単位行列
/************************************************************************************************/
const KsQuaternion KsQuaternion::IDENTITY( 0.0f, 0.0f, 0.0f, 1.0f );


/*************************************************************************************************/
/*
 * コンストラクタ
 * @param	refMatrix		値をコピーするマトリックス
 */
/*************************************************************************************************/
KsQuaternion::KsQuaternion( const KsMatrix3x3& refMatrix )
{
	KsReal			trace = refMatrix.m11 + refMatrix.m22 + refMatrix.m33;

	if( trace > 0.0f )
	{
		KsReal	root = KsSqrt( trace + 1.0f );

		w = 0.5f * root;

		root = 0.5f / root;

		x = ( refMatrix.m23 - refMatrix.m32 ) * root;
		y = ( refMatrix.m31 - refMatrix.m13 ) * root;
		z = ( refMatrix.m12 - refMatrix.m21 ) * root;
		
		return;
	}
	
	if( (refMatrix.m11 >= refMatrix.m22) && (refMatrix.m11 >= refMatrix.m33) )
	{
		const KsReal num7 = KsSqrt( (((1.0f + refMatrix.m11) - refMatrix.m22) - refMatrix.m33) );
		const KsReal num4 = 0.5f / num7;
		x = 0.5f * num7;
		y = (refMatrix.m12 + refMatrix.m21) * num4;
		z = (refMatrix.m13 + refMatrix.m31) * num4;
		w = (refMatrix.m23 - refMatrix.m32) * num4;

		return;
	}
	
	if(refMatrix.m22 > refMatrix.m33 )
	{
		const KsReal num6 = KsSqrt( (((1.0f + refMatrix.m22) - refMatrix.m11) - refMatrix.m33) );
		const KsReal num3 = 0.5f / num6;
		x = (refMatrix.m21 + refMatrix.m12) * num3;
		y = 0.5f * num6;
		z = (refMatrix.m32 + refMatrix.m23) * num3;
		w = (refMatrix.m31 - refMatrix.m13) * num3;
		
		return;
	}
	const KsReal num5 = KsSqrt( (((1.0f + refMatrix.m33) - refMatrix.m11) - refMatrix.m22) );
	const KsReal num2 = 0.5f / num5;
	x = (refMatrix.m31 + refMatrix.m13) * num2;
	y = (refMatrix.m32 + refMatrix.m23) * num2;
	z = 0.5f * num5;
	w = (refMatrix.m12 - refMatrix.m21) * num2;
}
#if 0
/*************************************************************************************************/
/*
 * コンストラクタ
 * @param	refMatrix		値をコピーするマトリックス
 */
/*************************************************************************************************/
KsQuaternion::KsQuaternion( const KsMatrix4x4& refMatrix )
{
	KsReal			trace = refMatrix.m11 + refMatrix.m22 + refMatrix.m33;

	if( trace > 0.0f )
	{
		KsReal	root = KsSqrt( trace + 1.0f );

		w = 0.5f * root;

		root = 0.5f / root;

		x = ( refMatrix.m23 - refMatrix.m32 ) * root;
		y = ( refMatrix.m31 - refMatrix.m13 ) * root;
		z = ( refMatrix.m12 - refMatrix.m21 ) * root;
		
		return;
	}
	
	if( (refMatrix.m11 >= refMatrix.m22) && (refMatrix.m11 >= refMatrix.m33) )
	{
		const KsReal num7 = KsSqrt( (((1.0f + refMatrix.m11) - refMatrix.m22) - refMatrix.m33) );
		const KsReal num4 = 0.5f / num7;
		x = 0.5f * num7;
		y = (refMatrix.m12 + refMatrix.m21) * num4;
		z = (refMatrix.m13 + refMatrix.m31) * num4;
		w = (refMatrix.m23 - refMatrix.m32) * num4;

		return;
	}
	
	if(refMatrix.m22 > refMatrix.m33 )
	{
		const KsReal num6 = KsSqrt( (((1.0f + refMatrix.m22) - refMatrix.m11) - refMatrix.m33) );
		const KsReal num3 = 0.5f / num6;
		x = (refMatrix.m21 + refMatrix.m12) * num3;
		y = 0.5f * num6;
		z = (refMatrix.m32 + refMatrix.m23) * num3;
		w = (refMatrix.m31 - refMatrix.m13) * num3;
		
		return;
	}
	const KsReal num5 = KsSqrt( (((1.0f + refMatrix.m33) - refMatrix.m11) - refMatrix.m22) );
	const KsReal num2 = 0.5f / num5;
	x = (refMatrix.m31 + refMatrix.m13) * num2;
	y = (refMatrix.m32 + refMatrix.m23) * num2;
	z = 0.5f * num5;
	w = (refMatrix.m12 - refMatrix.m21) * num2;
}

/************************************************************************************************/
//
/************************************************************************************************/
KsQuaternion& KsQuaternion::operator = ( const KsMatrix4x4& refMatrix )
{
	KsReal	trace = refMatrix.m11 + refMatrix.m[ 1 ][ 1 ] + refMatrix.m[ 2 ][ 2 ];
	KsReal	root;

	if( trace > 0.0f )
	{
		root = KsSqrt( trace + 1.0f );

		w = 0.5f * root;

		root = 0.5f / root;

		x = ( refMatrix[ 2 ][ 1 ] - refMatrix[ 1 ][ 2 ] ) * root;
		y = ( refMatrix[ 0 ][ 2 ] - refMatrix[ 2 ][ 0 ] ) * root;
		z = ( refMatrix[ 1 ][ 0 ] - refMatrix[ 0 ][ 1 ] ) * root;
	}
	else
	{
		KsInt32 next[ 3 ] = { 1, 2, 0 };
		KsInt32 i = 0;
	
		if( refMatrix[ 1 ][ 1 ] > refMatrix[ 0 ][ 0 ] ) { i = 1; }
		if( refMatrix[ 2 ][ 2 ] > refMatrix[ i ][ i ] ) { i = 2; }

		KsInt32 j = next[ i ];
		KsInt32 k = next[ j ];

		root = KsSqrt( refMatrix[ i ][ i ] - refMatrix[ j ][ j ] - refMatrix[ k ][ k ] + 1.0f );

		KsReal*		pQuat[ 3 ] = { &x, &y, &z };

		*(pQuat[ i ]) = 0.5f * root;

		root = 0.5f / root;

		w = ( refMatrix[ k ][ j ] - refMatrix[ j ][ k ] ) * root;

		*(pQuat[ j ]) = ( refMatrix[ j ][ i ] + refMatrix[ i ][ j ] ) * root;
		*(pQuat[ k ]) = ( refMatrix[ k ][ i ] + refMatrix[ i ][ k ] ) * root;
	}

	normalize();

	return (*this);
}
#endif

/************************************************************************************************/
// 
/************************************************************************************************/
void KsQuaternion::fromAxisRotation( const KsVector3d& refAxis, KsReal angle )
{
	if( KsFabs( angle ) < 0.0001f )
	{
		x = y = z = 0.0f;
		w = 1.0f;
	}
	else
	{
		KsReal	ang = 0.5f * angle;
		KsReal	sin = KsSin( ang );

		x = sin * refAxis.x;
		y = sin * refAxis.y;
		z = sin * refAxis.z;
		w = KsCos( ang );

		normalize();
	}
}


/************************************************************************************************/
// 
/************************************************************************************************/
void KsQuaternion::fromEulerAngles( KsReal angleX, KsReal angleY, KsReal angleZ )
{
	KsReal		angle;
	KsReal		sr, sp, sy, cr, cp, cy;
	KsReal		cpcy, spcy, cpsy, spsy;

	/* Yaw */
	angle = 0.5f * angleZ;
	sy = KsSin( angle );
	cy = KsCos( angle );

	/* Pitch */
	angle = 0.5f * angleY;
	sp = KsSin( angle );
	cp = KsCos( angle );

	/* Roll */
	angle = 0.5f * angleX;
	sr = KsSin( angle );
	cr = KsCos( angle );

	cpcy = cp * cy;
	spcy = sp * cy;
	cpsy = cp * sy;
	spsy = sp * sy;

	x = sr * cpcy - cr * spsy;
	y = cr * spcy + sr * cpsy;
	z = cr * cpsy - sr * spcy;
	w = cr * cpcy + sr * spsy;

	normalize();
}

/************************************************************************************************/
// 
/************************************************************************************************/
void KsQuaternion::convertToAxisRotation( KsVector3d* pAxis, KsReal* pAngle )
{
	KsReal length = x*x + y*y + z*z;

	if ( length > 0.0 )
	{
		*pAngle = 2.0f * KsACos( w );

		KsReal invLength = 1.0f / KsLogE( length );

		pAxis->x = x * invLength;
		pAxis->y = y * invLength;
		pAxis->z = z * invLength;
	}
	else
	{
		*pAngle = 0.0f;

		pAxis->x = 0.0f;
		pAxis->y = 0.0f;
		pAxis->z = 1.0f;
	}
}

#if 0
/************************************************************************************************/
// 
/************************************************************************************************/
KsMatrix4x4 KsQuaternion::convertToMatrix()
{
	KsMatrix4x4 matrix;

	convertToMatrix( &matrix );

	return matrix;
}


KsVector3d KsQuaternion::convertToEuler()
{
	KsVector3d angle;

	// XYZ軸回転の取得
	// Y回転を求める
	KsReal	x2 = x + x;
	KsReal	y2 = y + y;
	KsReal	z2 = z + z;
	KsReal	xz2 = x * z2;
	KsReal	wy2 = w * y2;
	KsReal	temp = -(xz2 - wy2);

	// 誤差対策
	if( temp >= 1.0f ){ temp = 1.0f; }
	else if( temp <= -1.0f ){ temp = -1.0f; }

	KsReal	yRadian = KsASin( temp );

	// 他の回転を求める
	KsReal	xx2 = x * x2;
	KsReal	xy2 = x * y2;
	KsReal	zz2 = z * z2;
	KsReal	wz2 = w * z2;

	if( yRadian < 3.1415926f * 0.5f )
	{
		if( yRadian > -3.1415926f * 0.5f )
		{
			KsReal	yz2 = y * z2;
			KsReal	wx2 = w * x2;
			KsReal	yy2 = y * y2;
			angle.x = KsATan2( yz2 + wx2, 1.0f - (xx2 + yy2) );
			angle.y = yRadian;
			angle.z = KsATan2( xy2 + wz2, 1.0f - (yy2 + zz2) );
		}
		else
		{
			angle.x = -KsATan2( xy2 - wz2, 1.0f - (xx2 + zz2) );
			angle.y = yRadian;
			angle.z = 0.0f;
		}
	}
	else
	{
		angle.x = KsATan2( xy2 - wz2, 1.0f - (xx2 + zz2) );
		angle.y = yRadian;
		angle.z = 0.0f;
	}

	return angle;
}

#endif

#if 0
/************************************************************************************************/
// 
/************************************************************************************************/
void KsQuaternion::convertToMatrix( KsMatrix4x4* pMatrix )
{
	//--------------------------------------------------------//
	//                << 行列への変換 >>                      //
	//                                                        //
	//      | 1-2*y*y-2*z*z, 2*x*y-2*w*z,   2*x*z+2*w*y   |   //
	// Rq = | 2*x*y+2*w*z,   1-2*x*x-2*z*z, 2*y*z-2*w*x   |   //
	//      | 2*x*z-2*w*y,   2*y*z+2*w*x,   1-2*x*x-2*y*y |   //
	//                                                        //
	//--------------------------------------------------------//

	pMatrix->m11 = 1.0f - 2.0f*y*y - 2.0f*z*z; pMatrix->m12 = 2.0f*x*y - 2.0f*w*z;        pMatrix->m13 = 2.0f*x*z + 2.0f*w*y;        pMatrix->m14 = 0.0f;
	pMatrix->m21 = 2.0f*x*y + 2.0f*w*z;        pMatrix->m22 = 1.0f - 2.0f*x*x - 2.0f*z*z; pMatrix->m23 = 2.0f*y*z - 2.0f*w*x;        pMatrix->m24 = 0.0f;
	pMatrix->m31 = 2.0f*x*z - 2.0f*w*y;        pMatrix->m32 = 2.0f*y*z + 2.0f*w*x;        pMatrix->m33 = 1.0f - 2.0f*x*x - 2.0f*y*y; pMatrix->m34 = 0.0f;
	pMatrix->m41 = 0.0f;                       pMatrix->m42 = 0.0f;                       pMatrix->m43 = 0.0f;                       pMatrix->m44 = 1.0f;
}

KsQuaternion KsQuaternion::CreateFromYawPitchRoll( KsReal yaw, KsReal pitch, KsReal roll )
{
	KsQuaternion quat;

	KsReal num9 = roll * 0.5f;
	KsReal num6 = KsSin(num9);
	KsReal num5 = KsCos(num9);
	KsReal num8 = pitch * 0.5f;
	KsReal num4 = KsSin(num8);
	KsReal num3 = KsCos(num8);
	KsReal num7 = yaw * 0.5f;
	KsReal num2 = KsSin(num7);
	KsReal num1 = KsCos(num7);

	quat.x = ((num1 * num4) * num5) + ((num2 * num3) * num6);
	quat.y = ((num2 * num3) * num5) - ((num1 * num4) * num6);
	quat.z = ((num1 * num3) * num6) - ((num2 * num4) * num5);
	quat.w = ((num1 * num3) * num5) + ((num2 * num4) * num6);

	return quat;
}

KsQuaternion KsQuaternion::CreateFromAxisAngle( const KsVector3d& refAxis, KsReal angle )
{
	if( KsFabs( angle ) < 0.0001f )
	{
		return KsQuaternion::IDENTITY;
	}


	KsReal	ang = 0.5f * angle;
	KsReal	sin = KsSin( ang );

	return KsQuaternion( sin * refAxis.x, sin * refAxis.y, sin * refAxis.z, KsCos( ang ) );
}

KsQuaternion KsQuaternion::CreateFromRotationMatrix( const KsMatrix4x4& refMatrix )
{
	KsQuaternion	quat;
	KsReal			trace = refMatrix.m11 + refMatrix.m22 + refMatrix.m33;

	if( trace > 0.0f )
	{
		KsReal	root = KsSqrt( trace + 1.0f );

		quat.w = 0.5f * root;

		root = 0.5f / root;

		quat.x = ( refMatrix.m23 - refMatrix.m32 ) * root;
		quat.y = ( refMatrix.m31 - refMatrix.m13 ) * root;
		quat.z = ( refMatrix.m12 - refMatrix.m21 ) * root;
		
		return quat;
	}
	
	if( (refMatrix.m11 >= refMatrix.m22) && (refMatrix.m11 >= refMatrix.m33) )
	{
		const KsReal num7 = KsSqrt( (((1.0f + refMatrix.m11) - refMatrix.m22) - refMatrix.m33) );
		const KsReal num4 = 0.5f / num7;
		quat.x = 0.5f * num7;
		quat.y = (refMatrix.m12 + refMatrix.m21) * num4;
		quat.z = (refMatrix.m13 + refMatrix.m31) * num4;
		quat.w = (refMatrix.m23 - refMatrix.m32) * num4;

		return quat;
	}
	
	if(refMatrix.m22 > refMatrix.m33 )
	{
		const KsReal num6 = KsSqrt( (((1.0f + refMatrix.m22) - refMatrix.m11) - refMatrix.m33) );
		const KsReal num3 = 0.5f / num6;
		quat.x = (refMatrix.m21 + refMatrix.m12) * num3;
		quat.y = 0.5f * num6;
		quat.z = (refMatrix.m32 + refMatrix.m23) * num3;
		quat.w = (refMatrix.m31 - refMatrix.m13) * num3;
		
		return quat;
	}
	const KsReal num5 = KsSqrt( (((1.0f + refMatrix.m33) - refMatrix.m11) - refMatrix.m22) );
	const KsReal num2 = 0.5f / num5;
	quat.x = (refMatrix.m31 + refMatrix.m13) * num2;
	quat.y = (refMatrix.m32 + refMatrix.m23) * num2;
	quat.z = 0.5f * num5;
	quat.w = (refMatrix.m12 - refMatrix.m21) * num2;

	return quat;
}


KsQuaternion KsQuaternion::CreateFromRotationMatrix( const KsMatrix3x3& refMatrix )
{
	KsQuaternion	quat;
	KsReal			trace = refMatrix.m11 + refMatrix.m22 + refMatrix.m33;

	if( trace > 0.0f )
	{
		KsReal	root = KsSqrt( trace + 1.0f );

		quat.w = 0.5f * root;

		root = 0.5f / root;

		quat.x = ( refMatrix.m23 - refMatrix.m32 ) * root;
		quat.y = ( refMatrix.m31 - refMatrix.m13 ) * root;
		quat.z = ( refMatrix.m12 - refMatrix.m21 ) * root;
		
		return quat;
	}
	
	if( (refMatrix.m11 >= refMatrix.m22) && (refMatrix.m11 >= refMatrix.m33) )
	{
		const KsReal num7 = KsSqrt( (((1.0f + refMatrix.m11) - refMatrix.m22) - refMatrix.m33) );
		const KsReal num4 = 0.5f / num7;
		quat.x = 0.5f * num7;
		quat.y = (refMatrix.m12 + refMatrix.m21) * num4;
		quat.z = (refMatrix.m13 + refMatrix.m31) * num4;
		quat.w = (refMatrix.m23 - refMatrix.m32) * num4;

		return quat;
	}
	
	if(refMatrix.m22 > refMatrix.m33 )
	{
		const KsReal num6 = KsSqrt( (((1.0f + refMatrix.m22) - refMatrix.m11) - refMatrix.m33) );
		const KsReal num3 = 0.5f / num6;
		quat.x = (refMatrix.m21 + refMatrix.m12) * num3;
		quat.y = 0.5f * num6;
		quat.z = (refMatrix.m32 + refMatrix.m23) * num3;
		quat.w = (refMatrix.m31 - refMatrix.m13) * num3;
		
		return quat;
	}
	const KsReal num5 = KsSqrt( (((1.0f + refMatrix.m33) - refMatrix.m11) - refMatrix.m22) );
	const KsReal num2 = 0.5f / num5;
	quat.x = (refMatrix.m31 + refMatrix.m13) * num2;
	quat.y = (refMatrix.m32 + refMatrix.m23) * num2;
	quat.z = 0.5f * num5;
	quat.w = (refMatrix.m12 - refMatrix.m21) * num2;

	return quat;
}

KsQuaternion KsQuaternion::Multiply( const KsQuaternion& refA, const KsQuaternion& refB ) 
{
	return KsQuaternion(
					refB.w * refA.x + refB.x * refA.w + refB.y * refA.z - refB.z * refA.y,
					refB.w * refA.y + refB.y * refA.w + refB.z * refA.x - refB.x * refA.z,
					refB.w * refA.z + refB.z * refA.w + refB.x * refA.y - refB.y * refA.x,
					refB.w * refA.w - refB.w * refA.x - refB.y * refA.y - refB.z * refA.z
				);
}

/************************************************************************************************/
// 
/************************************************************************************************/
KsQuaternion KsQuaternion::Slerp( const KsQuaternion& refSrc, const KsQuaternion& refDest, KsReal t )
{
	KsQuaternion	retQuat;

	KsQuaternionSlerp( &retQuat, &refSrc, &refDest, t );

	return retQuat; 
}

/************************************************************************************************/
// 
/************************************************************************************************/
KsQuaternion KsQuaternion::Lerp( const KsQuaternion& refSrc, const KsQuaternion& refDest, KsReal t )
{
	KsQuaternion	retQuat;

	KsQuaternionLerp( &retQuat, &refSrc, &refDest, t );

	return retQuat; 
}

/************************************************************************************************/
// 
/************************************************************************************************/
void KsQuaternionSlerp( KsQuaternion* pOut, const KsQuaternion* pSrc, const KsQuaternion* pDest, KsReal t )
{
	/* cosθ = q1・q2  */
	KsReal		cos = pSrc->x * pDest->x + pSrc->y * pDest->y + pSrc->z * pDest->z + pSrc->w * pDest->w;
	KsReal		angle;

	if( -1.0f < cos )
	{
		if( cos < 1.0 ){
			angle = KsACos( cos );
		}
		else{
			angle = 0.0f;
		}
	}
	else
	{
		angle = ksPI;
	}

	if( KsFabs( angle ) < 0.001f ){
		if( pOut != pSrc ){
			*pOut = *pSrc;
		}
		return;
	}

	KsReal		sin    = KsSin( angle );
	KsReal		invSin = 1.0f / sin;
	KsReal		val1   = KsSin( ( 1.0f - t ) * angle ) * invSin;
	KsReal		val2   = KsSin( t * angle ) * invSin;

	pOut->x = pSrc->x * val1 + pDest->x * val2;
	pOut->y = pSrc->y * val1 + pDest->y * val2;
	pOut->z = pSrc->z * val1 + pDest->z * val2;
	pOut->w = pSrc->w * val1 + pDest->w * val2;
}


/************************************************************************************************/
// 
/************************************************************************************************/
void KsQuaternionLerp( KsQuaternion* pOut, const KsQuaternion* pSrc, const KsQuaternion* pDest, KsReal t )
{
	// Qlerp
	KsReal	qr = pSrc->x * pDest->x + pSrc->y * pDest->y + pSrc->z * pDest->z + pSrc->w * pDest->w;
	KsReal	t0 = 1.0f - t;

	if( qr < 0.0f )
	{
		pOut->x = pSrc->x * t0 - pDest->x * t;
		pOut->y = pSrc->y * t0 - pDest->y * t;
		pOut->z = pSrc->z * t0 - pDest->z * t;
		pOut->w = pSrc->w * t0 - pDest->w * t;
	}
	else
	{
		pOut->x = pSrc->x * t0 + pDest->x * t;
		pOut->y = pSrc->y * t0 + pDest->y * t;
		pOut->z = pSrc->z * t0 + pDest->z * t;
		pOut->w = pSrc->w * t0 + pDest->w * t;
	}
	pOut->normalize();
}


/************************************************************************************************/
// 
/************************************************************************************************/
void KsQuaternionToMatrix( KsQuaternion* pQuat, KsMatrix4x4* pMatrix )
{
	pMatrix->m11 = 1.0f - 2.0f * pQuat->y * pQuat->y - 2.0f * pQuat->z * pQuat->z;
	pMatrix->m21 = 2.0f * pQuat->x * pQuat->y + 2.0f * pQuat->w * pQuat->z;
	pMatrix->m31 = 2.0f * pQuat->x * pQuat->z - 2.0f * pQuat->w * pQuat->y;
	pMatrix->m41 = 0.0f;

	pMatrix->m12 = 2.0f * pQuat->x * pQuat->y - 2.0f * pQuat->w * pQuat->z;
	pMatrix->m22 = 1.0f - 2.0f * pQuat->x * pQuat->x - 2.0f * pQuat->z * pQuat->z;
	pMatrix->m32 = 2.0f * pQuat->y * pQuat->z + 2.0f * pQuat->w * pQuat->x;
	pMatrix->m42 = 0.0f;

	pMatrix->m13 = 2.0f * pQuat->x * pQuat->z + 2.0f * pQuat->w * pQuat->y;
	pMatrix->m23 = 2.0f * pQuat->y * pQuat->z - 2.0f * pQuat->w * pQuat->x;
	pMatrix->m33 = 1.0f - 2.0f * pQuat->x * pQuat->x - 2.0f * pQuat->y * pQuat->y;
	pMatrix->m43 = 0.0f;

	pMatrix->m14 = 0.0f;
	pMatrix->m24 = 0.0f;
	pMatrix->m34 = 0.0f;
	pMatrix->m44 = 1.0f;
}

#if 0
/*************************************************************************************************/
/**
 * あるベクトルからあるベクトルへのクォータニオンを求める（最小弧クォータニオン）
 * @param		pQuat		クォータニオン
 * @param		pV0			変換前の行列
 * @param		pV1			変換後の行列
 * @note		フォーミングなどの外積が０に近いときおかしくなるための対処
 */
/*************************************************************************************************/
const void KsRotationArc( KsQuaternion& quat, const KsVector3d& refV0, const KsVector3d refV1 )
{
	KsVector3d	v0 = refV0;
	KsVector3d	v1 = refV1;
	KsVector3d	v2;

	v0.normalize();
	v1.normalize();

	v2 = v0.crossProduct( v1 );

	KsReal	d = v0.dotProduct( v1 );
	KsReal	s = KsSqrt( ( 1.0f + d ) * 2.0f );

	quat.x = v2.x / s;
	quat.y = v2.y / s;
	quat.z = v2.z / s;
	quat.w = s / 2.0f;


	return quat.( v2.x/s,  );

/*
	if( RwV3dLength(v0)>0 )RwV3dNormalize(v0,v0);
	if( RwV3dLength(v1)>0 )RwV3dNormalize(v1,v1);

	RwV3d  vec2;

	RwV3dCrossProduct(&vec2,v0,v1);
	RwReal  d = RwV3dDotProduct(v0,v1);
	RwReal  s = 0.0f;
	rwSqrt(&s,(1+d)*2);
	RtQuatInit(q,vec2.x/s,vec2.y/s,vec2.z/s,s/2.0f);
	*/
}
#endif

#endif


ksNS_KS_END

