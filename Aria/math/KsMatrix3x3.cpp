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
 * @file	KsMatrix3x3.cpp
 * @brief	マトリックス操作
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
/************************************************************************************************/

/*==============================================================================================*/
/*                                 << インクルード >>                                             */
/*==============================================================================================*/
#include "KsMatrix3x3.h"
#include "KsQuaternion.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/*************************************************************************************************/
/*
 * 単位行列
 */
/*************************************************************************************************/
const KsMatrix3x3 KsMatrix3x3::IDENTITY(	1.0f, 0.0f, 0.0f,
											0.0f, 1.0f, 0.0f,
											0.0f, 0.0f, 1.0f );



/*************************************************************************************************/
/*
 * コンストラクタ
 * @param	refQuaternion		値をコピーするクォータニオン
 */
/*************************************************************************************************/
KsMatrix3x3::KsMatrix3x3( const KsQuaternion& refQuat )
{
    const KsReal xx = refQuat.x * refQuat.x;
    const KsReal yy = refQuat.y * refQuat.y;
    const KsReal zz = refQuat.z * refQuat.z;
    const KsReal xy = refQuat.x * refQuat.y;
    const KsReal zw = refQuat.z * refQuat.w;
    const KsReal zx = refQuat.z * refQuat.x;
    const KsReal yw = refQuat.y * refQuat.w;
    const KsReal yz = refQuat.y * refQuat.z;
    const KsReal xw = refQuat.x * refQuat.w;

    m11 = 1.0f - (2.0f*(yy + zz));	m12 = 2.0f*(xy + zw);			m13 = 2.0f * (zx - yw);
    m21 = 2.0f * (xy - zw);			m22 = 1.0f - (2.0f*(zz + xx));	m23 = 2.0f * (yz + xw);
    m31 = 2.0f * (zx + yw);			m32 = 2.0f * (yz - xw);			m33 = 1.0f - (2.0f*(yy + xx));
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
KsMatrix3x3& KsMatrix3x3::operator = ( const KsQuaternion& refQuat )
{
	KsReal		wx, wy, wz, xx, yy, yz, xy, xz, zz, x2, y2, z2;

	x2 = refQuat.x + refQuat.x;
	y2 = refQuat.y + refQuat.y;
	z2 = refQuat.z + refQuat.z;

	xx = refQuat.x * x2;   xy = refQuat.x * y2;   xz = refQuat.x * z2;
	yy = refQuat.y * y2;   yz = refQuat.y * z2;   zz = refQuat.z * z2;
	wx = refQuat.w * x2;   wy = refQuat.w * y2;   wz = refQuat.w * z2;

	m11 = 1.0f - (yy + zz);	m12 = xy + wz;			m13 = xz - wy;
	m21 = xy - wz;			m22 = 1.0f - (xx + zz); m23 = yz + wx;
	m31 = xz + wy;			m32 = yz - wx;			m33 = 1.0f - (xx + yy);

	return ( *this );
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
const KsMatrix3x3& KsMatrix3x3::set( const KsQuaternion& refQuat )
{
	KsReal		wx, wy, wz, xx, yy, yz, xy, xz, zz, x2, y2, z2;

	x2 = refQuat.x + refQuat.x;
	y2 = refQuat.y + refQuat.y;
	z2 = refQuat.z + refQuat.z;

	xx = refQuat.x * x2;   xy = refQuat.x * y2;   xz = refQuat.x * z2;
	yy = refQuat.y * y2;   yz = refQuat.y * z2;   zz = refQuat.z * z2;
	wx = refQuat.w * x2;   wy = refQuat.w * y2;   wz = refQuat.w * z2;

	m11 = 1.0f - (yy + zz);	m12 = xy + wz;			m13 = xz - wy;
	m21 = xy - wz;			m22 = 1.0f - (xx + zz); m23 = yz + wx;
	m31 = xz + wy;			m32 = yz - wx;			m33 = 1.0f - (xx + yy);

	return ( *this );
}

/*************************************************************************************************/
/*
 * デタミナントを取得する
 * @return						デタミナント
 */
/*************************************************************************************************/
KsReal KsMatrix3x3::determinant() const
{
	return m11*m22*m33 + m21*m32*m13 + m31*m12*m23 - m11*m32*m23 - m31*m22*m13 - m21*m12*m33;
}

/*************************************************************************************************/
/*
 * 逆行列を取得する
 * @return						逆行列
 */
/*************************************************************************************************/
KsMatrix3x3 KsMatrix3x3::inverse()
{
	/* デタミナント */
	KsReal	d = determinant();

	if( d < ksTOLERANCE2 )
	{
		return KsMatrix3x3::IDENTITY;
	}

	d = 1.0f / d;

	return KsMatrix3x3( d * ( m22*m33 - m23*m32 ), d * ( m13*m32 - m12*m33 ), d * ( m12*m23 - m13*m22 ), 
						d * ( m23*m31 - m21*m33 ), d * ( m11*m33 - m13*m31 ), d * ( m13*m21 - m11*m23 ), 
						d * ( m21*m32 - m22*m31 ), d * ( m12*m31 - m11*m32 ), d * ( m11*m22 - m12*m21 ) );

}

/*************************************************************************************************/
/*
 * 転置する
 */
/*************************************************************************************************/
void KsMatrix3x3::transpose()
{
	KsReal	temp;
	
	temp = m[0][1]; m[0][1] = m[1][0]; m[1][0] = temp;
	temp = m[0][2]; m[0][2] = m[2][0]; m[2][0] = temp;
	temp = m[1][2]; m[1][2] = m[2][1]; m[2][1] = temp;
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
KsQuaternion KsMatrix3x3::getRotate() const
{
	return KsQuaternion( *this );
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
KsVector3d KsMatrix3x3::getScale() const
{
	return KsVector3d( m[ 0 ][ 0 ], m[ 1 ][ 1 ], m[ 2 ][ 2 ] );
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
void KsMatrix3x3::setEulerZYX( KsReal eulerX, KsReal eulerY, KsReal eulerZ )
{ 
	const KsReal ci = KsCos(eulerX); 
	const KsReal cj = KsCos(eulerY); 
	const KsReal ch = KsCos(eulerZ); 
	const KsReal si = KsSin(eulerX); 
	const KsReal sj = KsSin(eulerY); 
	const KsReal sh = KsSin(eulerZ); 
	const KsReal cc = ci * ch; 
	const KsReal cs = ci * sh; 
	const KsReal sc = si * ch; 
	const KsReal ss = si * sh;

	m11 = cj * ch; m12 = sj * sc - cs; m13 = sj * cc + ss;
	m21 = cj * sh; m22 = sj * ss + cc; m23 = sj * cs - sc;
	m31 = -sj;     m32 = cj * si;      m33 = cj * ci;
}

ksNS_KS_END

