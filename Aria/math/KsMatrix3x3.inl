

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE KsMatrix3x3& KsMatrix3x3::operator = ( const KsMatrix3x3& refMatrix )
{
	memcpy( &m[ 0 ][ 0 ], &refMatrix, sizeof(KsMatrix3x3) );

	return ( *this );
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE KsMatrix3x3& KsMatrix3x3::operator *= ( const KsMatrix3x3& refMatrix )
{
	KsReal	tmp[ 9 ];

	tmp[ 0 ] = m11*refMatrix.m11 + m12*refMatrix.m21 + m13*refMatrix.m31;
	tmp[ 1 ] = m11*refMatrix.m12 + m12*refMatrix.m22 + m13*refMatrix.m32;
	tmp[ 2 ] = m11*refMatrix.m13 + m12*refMatrix.m23 + m13*refMatrix.m33;

	tmp[ 3 ] = m21*refMatrix.m11 + m22*refMatrix.m21 + m23*refMatrix.m31;
	tmp[ 4 ] = m21*refMatrix.m12 + m22*refMatrix.m22 + m23*refMatrix.m32;
	tmp[ 5 ] = m21*refMatrix.m13 + m22*refMatrix.m23 + m23*refMatrix.m33;

	tmp[ 6 ] = m31*refMatrix.m11 + m32*refMatrix.m21 + m33*refMatrix.m31;
	tmp[ 7 ] = m31*refMatrix.m12 + m32*refMatrix.m22 + m33*refMatrix.m32;
	tmp[ 8 ] = m31*refMatrix.m13 + m32*refMatrix.m23 + m33*refMatrix.m33;

	memcpy( &m[ 0 ][ 0 ], &tmp[ 0 ], sizeof(tmp) );

	return ( *this );
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE KsMatrix3x3& KsMatrix3x3::operator += ( const KsMatrix3x3& refMatrix )
{
	m11 += refMatrix.m11; m12 += refMatrix.m12; m13 += refMatrix.m13;
	m21 += refMatrix.m21; m22 += refMatrix.m22; m23 += refMatrix.m23;
	m31 += refMatrix.m31; m32 += refMatrix.m32; m33 += refMatrix.m33;
	
	return ( *this );
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE KsMatrix3x3& KsMatrix3x3::operator -= ( const KsMatrix3x3& refMatrix )
{
	m11 -= refMatrix.m11; m12 -= refMatrix.m12; m13 -= refMatrix.m13;
	m21 -= refMatrix.m21; m22 -= refMatrix.m22; m23 -= refMatrix.m23;
	m31 -= refMatrix.m31; m32 -= refMatrix.m32; m33 -= refMatrix.m33;
	
	return ( *this );
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE KsMatrix3x3& KsMatrix3x3::operator *= ( KsReal s )
{
	m11 *= s; m12 *= s; m13 *= s;
	m21 *= s; m22 *= s; m23 *= s;
	m31 *= s; m32 *= s; m33 *= s;
	
	return ( *this );
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE KsMatrix3x3& KsMatrix3x3::operator /= ( KsReal s )
{
	KsReal inv = 1.0f / s;
	
	m11 *= inv; m12 *= inv; m13 *= inv;
	m21 *= inv; m22 *= inv; m23 *= inv;
	m31 *= inv; m32 *= inv; m33 *= inv;

	return ( *this );
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE KsMatrix3x3 KsMatrix3x3::operator + () const
{
	return ( *this );
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE KsMatrix3x3 KsMatrix3x3::operator - () const
{
	return KsMatrix3x3( -m11, -m12, -m13,
					    -m21, -m22, -m23,
					    -m31, -m32, -m33 );
}


/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE KsVector3d KsMatrix3x3::operator * ( const KsVector3d& refVector ) const
{
	return KsVector3d( m11*refVector.x + m12*refVector.y + m13*refVector.z,
					   m21*refVector.x + m22*refVector.y + m23*refVector.z,
					   m31*refVector.x + m32*refVector.y + m33*refVector.z );
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE KsMatrix3x3 KsMatrix3x3::operator * ( const KsMatrix3x3& refMatrix ) const
{
	return KsMatrix3x3(	m11*refMatrix.m11 + m12*refMatrix.m21 + m13*refMatrix.m31, m11*refMatrix.m12 + m12*refMatrix.m22 + m13*refMatrix.m32, m11*refMatrix.m13 + m12*refMatrix.m23 + m13*refMatrix.m33, 
						m21*refMatrix.m11 + m22*refMatrix.m21 + m23*refMatrix.m31, m21*refMatrix.m12 + m22*refMatrix.m22 + m23*refMatrix.m32, m21*refMatrix.m13 + m22*refMatrix.m23 + m23*refMatrix.m33,
						m31*refMatrix.m11 + m32*refMatrix.m21 + m33*refMatrix.m31, m31*refMatrix.m12 + m32*refMatrix.m22 + m33*refMatrix.m32, m31*refMatrix.m13 + m32*refMatrix.m23 + m33*refMatrix.m33 );
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE KsMatrix3x3 KsMatrix3x3::operator + ( const KsMatrix3x3& refMatrix ) const
{
	return KsMatrix3x3(	m11 + refMatrix.m11, m12 + refMatrix.m12, m13 + refMatrix.m13, 
						m21 + refMatrix.m21, m22 + refMatrix.m22, m23 + refMatrix.m23, 
						m31 + refMatrix.m31, m32 + refMatrix.m32, m33 + refMatrix.m33 );
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE KsMatrix3x3 KsMatrix3x3::operator - ( const KsMatrix3x3& refMatrix ) const
{
	return KsMatrix3x3(	m11 - refMatrix.m11, m12 - refMatrix.m12, m13 - refMatrix.m13,
						m21 - refMatrix.m21, m22 - refMatrix.m22, m23 - refMatrix.m23,
						m31 - refMatrix.m31, m32 - refMatrix.m32, m33 - refMatrix.m33 );

}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE KsMatrix3x3 KsMatrix3x3::operator * ( KsReal s ) const
{
	return KsMatrix3x3(	m11 * s, m12 * s, m13 * s,
						m21 * s, m22 * s, m23 * s,
						m31 * s, m32 * s, m33 * s );
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE KsMatrix3x3 KsMatrix3x3::operator / ( KsReal s ) const
{
	KsReal inv = 1.0f / s;

	return KsMatrix3x3(	m11 * inv, m12 * inv, m13 * inv, 
						m21 * inv, m22 * inv, m23 * inv, 
						m31 * inv, m32 * inv, m33 * inv );
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE KsBool KsMatrix3x3::operator == ( const KsMatrix3x3& refMatrix ) const
{
	return ( 0 == memcmp( this, &refMatrix, sizeof(KsMatrix3x3) ) );
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE KsBool KsMatrix3x3::operator != ( const KsMatrix3x3& refMatrix ) const
{
	return ( 0 != memcmp( this, &refMatrix, sizeof(KsMatrix3x3) ) );
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE KsMatrix3x3 operator * ( KsReal s, const KsMatrix3x3& refMatrix )
{
	return KsMatrix3x3(	s * refMatrix.m11, s * refMatrix.m12, s * refMatrix.m13,
						s * refMatrix.m21, s * refMatrix.m22, s * refMatrix.m23,
						s * refMatrix.m31, s * refMatrix.m32, s * refMatrix.m33 );
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE const KsMatrix3x3& KsMatrix3x3::set( const KsReal* fArray )
{
	m11 = fArray[ 0]; m12 = fArray[ 1]; m13 = fArray[ 2];
	m21 = fArray[ 3]; m22 = fArray[ 4]; m23 = fArray[ 5];
	m31 = fArray[ 6]; m32 = fArray[ 7]; m33 = fArray[ 8];

	return ( *this );
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE void KsMatrix3x3::setScaleX( KsReal sx )
{
	m[ 0 ][ 0 ] = sx;
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE void KsMatrix3x3::setScaleY( KsReal sy )
{
	m[ 1 ][ 1 ] = sy;
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE void KsMatrix3x3::setScaleZ( KsReal sz )
{
	m[ 2 ][ 2 ] = sz;
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE void KsMatrix3x3::setScale( KsReal scale )
{
	m[ 0 ][ 0 ] = scale;
	m[ 1 ][ 1 ] = scale;
	m[ 2 ][ 2 ] = scale;
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE void KsMatrix3x3::setScale( KsReal sx, KsReal sy, KsReal sz )
{
	m[ 0 ][ 0 ] = sx;
	m[ 1 ][ 1 ] = sy;
	m[ 2 ][ 2 ] = sz;
}
/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE void KsMatrix3x3::setScale( const KsVector3d& refScale )
{
    m[ 0 ][ 0 ] = refScale.x;
    m[ 1 ][ 1 ] = refScale.y;
    m[ 2 ][ 2 ] = refScale.z;
}
/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE void KsMatrix3x3::setScale( const KsVector3d* pScale )
{
	m[ 0 ][ 0 ] = pScale->x;
	m[ 1 ][ 1 ] = pScale->y;
	m[ 2 ][ 2 ] = pScale->z;
}
/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE void KsMatrix3x3::setRotateX( KsReal angle )
{
	m[ 1 ][ 1 ] = KsCos( angle ); m[ 1 ][ 2 ] = -KsSin( angle );
	m[ 2 ][ 1 ] = KsSin( angle ); m[ 2 ][ 2 ] =  KsCos( angle ); 
}
/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE void KsMatrix3x3::setRotateY( KsReal angle )
{
	m[ 0 ][ 0 ] =  KsCos( angle ); m[ 0 ][ 2 ] = KsSin( angle );
	m[ 2 ][ 0 ] = -KsSin( angle ); m[ 2 ][ 2 ] = KsCos( angle ); 
}
/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE void KsMatrix3x3::setRotateZ( KsReal angle )
{
	m[ 0 ][ 0 ] = KsCos( angle ); m[ 0 ][ 1 ] = -KsSin( angle );
	m[ 1 ][ 0 ] = KsSin( angle ); m[ 1 ][ 1 ] =  KsCos( angle ); 
}


