

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE KsMatrix4x4& KsMatrix4x4::operator = ( const KsMatrix4x4& refMatrix )
{
	memcpy( &m, &refMatrix, sizeof(KsMatrix4x4) );

	return ( *this );
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE KsMatrix4x4& KsMatrix4x4::operator *= ( const KsMatrix4x4& refMatrix )
{
	KsReal	tmp[ 16 ];

    tmp[  0 ] = m11*refMatrix.m11 + m12*refMatrix.m21 + m13*refMatrix.m31 + m14*refMatrix.m41;
	tmp[  1 ] = m11*refMatrix.m12 + m12*refMatrix.m22 + m13*refMatrix.m32 + m14*refMatrix.m42;
	tmp[  2 ] = m11*refMatrix.m13 + m12*refMatrix.m23 + m13*refMatrix.m33 + m14*refMatrix.m43;
	tmp[  3 ] = m11*refMatrix.m14 + m12*refMatrix.m24 + m13*refMatrix.m34 + m14*refMatrix.m44;

	tmp[  4 ] = m21*refMatrix.m11 + m22*refMatrix.m21 + m23*refMatrix.m31 + m24*refMatrix.m41;
	tmp[  5 ] = m21*refMatrix.m12 + m22*refMatrix.m22 + m23*refMatrix.m32 + m24*refMatrix.m42;
	tmp[  6 ] = m21*refMatrix.m13 + m22*refMatrix.m23 + m23*refMatrix.m33 + m24*refMatrix.m43;
	tmp[  7 ] = m21*refMatrix.m14 + m22*refMatrix.m24 + m23*refMatrix.m34 + m24*refMatrix.m44,

	tmp[  8 ] = m31*refMatrix.m11 + m32*refMatrix.m21 + m33*refMatrix.m31 + m34*refMatrix.m41;
	tmp[  9 ] = m31*refMatrix.m12 + m32*refMatrix.m22 + m33*refMatrix.m32 + m34*refMatrix.m42;
	tmp[ 10 ] = m31*refMatrix.m13 + m32*refMatrix.m23 + m33*refMatrix.m33 + m34*refMatrix.m43;
	tmp[ 11 ] = m31*refMatrix.m14 + m32*refMatrix.m24 + m33*refMatrix.m34 + m34*refMatrix.m44;

	tmp[ 12 ] = m41*refMatrix.m11 + m42*refMatrix.m21 + m43*refMatrix.m31 + m44*refMatrix.m41;
	tmp[ 13 ] = m41*refMatrix.m12 + m42*refMatrix.m22 + m43*refMatrix.m32 + m44*refMatrix.m42;
	tmp[ 14 ] = m41*refMatrix.m13 + m42*refMatrix.m23 + m43*refMatrix.m33 + m44*refMatrix.m43;
	tmp[ 15 ] = m41*refMatrix.m14 + m42*refMatrix.m24 + m43*refMatrix.m34 + m44*refMatrix.m44;

	memcpy( &m[ 0 ][ 0 ], &tmp[ 0 ], sizeof(tmp) );

    return ( *this );
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE KsMatrix4x4& KsMatrix4x4::operator += ( const KsMatrix4x4& refMatrix )
{
	m11 += refMatrix.m11; m12 += refMatrix.m12; m13 += refMatrix.m13; m14 += refMatrix.m14;
	m21 += refMatrix.m21; m22 += refMatrix.m22; m23 += refMatrix.m23; m24 += refMatrix.m24;
	m31 += refMatrix.m31; m32 += refMatrix.m32; m33 += refMatrix.m33; m34 += refMatrix.m34;
	m41 += refMatrix.m41; m42 += refMatrix.m42; m43 += refMatrix.m43; m44 += refMatrix.m44;
	
	return ( *this );
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE KsMatrix4x4& KsMatrix4x4::operator -= ( const KsMatrix4x4& refMatrix )
{
    m11 -= refMatrix.m11; m12 -= refMatrix.m12; m13 -= refMatrix.m13; m14 -= refMatrix.m14;
    m21 -= refMatrix.m21; m22 -= refMatrix.m22; m23 -= refMatrix.m23; m24 -= refMatrix.m24;
    m31 -= refMatrix.m31; m32 -= refMatrix.m32; m33 -= refMatrix.m33; m34 -= refMatrix.m34;
    m41 -= refMatrix.m41; m42 -= refMatrix.m42; m43 -= refMatrix.m43; m44 -= refMatrix.m44;
	
	return ( *this );
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE KsMatrix4x4& KsMatrix4x4::operator *= ( KsReal s )
{
	m11 *= s; m12 *= s; m13 *= s; m14 *= s;
	m21 *= s; m22 *= s; m23 *= s; m24 *= s;
	m31 *= s; m32 *= s; m33 *= s; m34 *= s;
	m41 *= s; m42 *= s; m43 *= s; m44 *= s;
	
	return ( *this );
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE KsMatrix4x4& KsMatrix4x4::operator /= ( KsReal s )
{
	KsReal inv = 1.0f / s;
	
	m11 *= inv; m12 *= inv; m13 *= inv; m14 *= inv;
	m21 *= inv; m22 *= inv; m23 *= inv; m24 *= inv;
	m31 *= inv; m32 *= inv; m33 *= inv; m34 *= inv;
	m41 *= inv; m42 *= inv; m43 *= inv; m44 *= inv;

	return ( *this );
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE KsMatrix4x4 KsMatrix4x4::operator + () const
{
	return ( *this );
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE KsMatrix4x4 KsMatrix4x4::operator - () const
{
	return KsMatrix4x4( -m11, -m12, -m13, -m14,
					 -m21, -m22, -m23, -m24,
					 -m31, -m32, -m33, -m34,
					 -m41, -m42, -m43, -m44 );
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE KsMatrix4x4 KsMatrix4x4::operator * ( const KsMatrix4x4& refMatrix ) const
{
	return KsMatrix4x4(	m11*refMatrix.m11 + m12*refMatrix.m21 + m13*refMatrix.m31 + m14*refMatrix.m41, m11*refMatrix.m12 + m12*refMatrix.m22 + m13*refMatrix.m32 + m14*refMatrix.m42, m11*refMatrix.m13 + m12*refMatrix.m23 + m13*refMatrix.m33 + m14*refMatrix.m43, m11*refMatrix.m14 + m12*refMatrix.m24 + m13*refMatrix.m34 + m14*refMatrix.m44, 
						m21*refMatrix.m11 + m22*refMatrix.m21 + m23*refMatrix.m31 + m24*refMatrix.m41, m21*refMatrix.m12 + m22*refMatrix.m22 + m23*refMatrix.m32 + m24*refMatrix.m42, m21*refMatrix.m13 + m22*refMatrix.m23 + m23*refMatrix.m33 + m24*refMatrix.m43, m21*refMatrix.m14 + m22*refMatrix.m24 + m23*refMatrix.m34 + m24*refMatrix.m44,
						m31*refMatrix.m11 + m32*refMatrix.m21 + m33*refMatrix.m31 + m34*refMatrix.m41, m31*refMatrix.m12 + m32*refMatrix.m22 + m33*refMatrix.m32 + m34*refMatrix.m42, m31*refMatrix.m13 + m32*refMatrix.m23 + m33*refMatrix.m33 + m34*refMatrix.m43, m31*refMatrix.m14 + m32*refMatrix.m24 + m33*refMatrix.m34 + m34*refMatrix.m44,
						m41*refMatrix.m11 + m42*refMatrix.m21 + m43*refMatrix.m31 + m44*refMatrix.m41, m41*refMatrix.m12 + m42*refMatrix.m22 + m43*refMatrix.m32 + m44*refMatrix.m42, m41*refMatrix.m13 + m42*refMatrix.m23 + m43*refMatrix.m33 + m44*refMatrix.m43, m41*refMatrix.m14 + m42*refMatrix.m24 + m43*refMatrix.m34 + m44*refMatrix.m44 );
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE KsMatrix4x4 KsMatrix4x4::operator + ( const KsMatrix4x4& refMatrix ) const
{
	return KsMatrix4x4(	m11 + refMatrix.m11, m12 + refMatrix.m12, m13 + refMatrix.m13, m14 + refMatrix.m14,
						m21 + refMatrix.m21, m22 + refMatrix.m22, m23 + refMatrix.m23, m24 + refMatrix.m24,
						m31 + refMatrix.m31, m32 + refMatrix.m32, m33 + refMatrix.m33, m34 + refMatrix.m34,
						m41 + refMatrix.m41, m42 + refMatrix.m42, m43 + refMatrix.m43, m44 + refMatrix.m44 );
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE KsMatrix4x4 KsMatrix4x4::operator - ( const KsMatrix4x4& refMatrix ) const
{
	return KsMatrix4x4(	m11 - refMatrix.m11, m12 - refMatrix.m12, m13 - refMatrix.m13, m14 + refMatrix.m14,
						m21 - refMatrix.m21, m22 - refMatrix.m22, m23 - refMatrix.m23, m24 + refMatrix.m24,
						m31 - refMatrix.m31, m32 - refMatrix.m32, m33 - refMatrix.m33, m34 + refMatrix.m34,
						m41 - refMatrix.m41, m42 - refMatrix.m42, m43 - refMatrix.m43, m44 + refMatrix.m44 );

}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE KsMatrix4x4 KsMatrix4x4::operator * ( KsReal s ) const
{
	return KsMatrix4x4(	m11 * s, m12 * s, m13 * s, m14 * s,
						m21 * s, m22 * s, m23 * s, m24 * s,
						m31 * s, m32 * s, m33 * s, m34 * s,
						m41 * s, m42 * s, m43 * s, m44 * s );
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE KsMatrix4x4 KsMatrix4x4::operator / ( KsReal s ) const
{
	KsReal inv = 1.0f / s;

	return KsMatrix4x4(	m11 * inv, m12 * inv, m13 * inv, m14 * inv,
						m21 * inv, m22 * inv, m23 * inv, m24 * inv,
						m31 * inv, m32 * inv, m33 * inv, m34 * inv,
						m41 * inv, m42 * inv, m43 * inv, m44 * inv );
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE KsBool KsMatrix4x4::operator == ( const KsMatrix4x4& refMatrix ) const
{
	return ( 0 == memcmp( this, &refMatrix, sizeof(KsMatrix4x4) ) );
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE KsBool KsMatrix4x4::operator != ( const KsMatrix4x4& refMatrix ) const
{
	return ( 0 != memcmp( this, &refMatrix, sizeof(KsMatrix4x4) ) );
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE KsMatrix4x4 operator * ( KsReal s, const KsMatrix4x4& refMatrix )
{
	return KsMatrix4x4(	s * refMatrix.m11, s * refMatrix.m12, s * refMatrix.m13, s * refMatrix.m14,
						s * refMatrix.m21, s * refMatrix.m22, s * refMatrix.m23, s * refMatrix.m24,
						s * refMatrix.m31, s * refMatrix.m32, s * refMatrix.m33, s * refMatrix.m34,
						s * refMatrix.m41, s * refMatrix.m42, s * refMatrix.m43, s * refMatrix.m44 );
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE const KsMatrix4x4&	 KsMatrix4x4::set( const KsReal* fArray )
{
	m11 = fArray[ 0]; m12 = fArray[ 1]; m13 = fArray[ 2]; m14 = fArray[ 3];
	m21 = fArray[ 4]; m22 = fArray[ 5]; m23 = fArray[ 6]; m24 = fArray[ 7];
	m31 = fArray[ 8]; m32 = fArray[ 9]; m33 = fArray[10]; m34 = fArray[11];
	m41 = fArray[12]; m42 = fArray[13]; m43 = fArray[14]; m44 = fArray[15];

	return ( *this );
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE KsVector3d KsMatrix4x4::getTranslate()
{
#if 0
	return KsVector3d( m[ 0 ][ 3 ], m[ 1 ][ 3 ], m[ 2 ][ 3 ] );
#else
	return KsVector3d( m[ 3 ][ 0 ], m[ 3 ][ 1 ], m[ 3 ][ 2 ] );
#endif
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE void KsMatrix4x4::setTranslate( KsReal x, KsReal y, KsReal z )
{
#if 0
    m[ 0 ][ 3 ] = x;
    m[ 1 ][ 3 ] = y;
    m[ 2 ][ 3 ] = z;
#else
	m[ 3 ][ 0 ] = x;
    m[ 3 ][ 1 ] = y;
    m[ 3 ][ 2 ] = z;
#endif

}
/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE void KsMatrix4x4::setTranslate( const KsVector3d& v )
{
	setTranslate( v.x, v.y, v.z );
}
/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE void KsMatrix4x4::setTranslate( const KsVector3d* v )
{
	setTranslate( v->x, v->y, v->z );
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE void KsMatrix4x4::setScaleX( KsReal sx )
{
	m[ 0 ][ 0 ] = sx;
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE void KsMatrix4x4::setScaleY( KsReal sy )
{
    m[ 1 ][ 1 ] = sy;
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE void KsMatrix4x4::setScaleZ( KsReal sz )
{
    m[ 2 ][ 2 ] = sz;
}

/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE void KsMatrix4x4::setScale( KsReal scale )
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
ksINLINE void KsMatrix4x4::setScale( KsReal sx, KsReal sy, KsReal sz )
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
ksINLINE void KsMatrix4x4::setScale( const KsVector3d& refScale )
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
ksINLINE void KsMatrix4x4::setScale( const KsVector3d* pScale )
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
ksINLINE void KsMatrix4x4::setRotateX( KsReal angle )
{
    m[ 1 ][ 1 ] = KsCos( angle ); m[ 1 ][ 2 ] = -KsSin( angle );
    m[ 2 ][ 1 ] = KsSin( angle ); m[ 2 ][ 2 ] =  KsCos( angle ); 
}
/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE void KsMatrix4x4::setRotateY( KsReal angle )
{
	m[ 0 ][ 0 ] =  KsCos( angle ); m[ 0 ][ 2 ] = KsSin( angle );
    m[ 2 ][ 0 ] = -KsSin( angle ); m[ 2 ][ 2 ] = KsCos( angle ); 
}
/*************************************************************************************************/
/*
 *
 */
/*************************************************************************************************/
ksINLINE void KsMatrix4x4::setRotateZ( KsReal angle )
{
	m[ 0 ][ 0 ] = KsCos( angle ); m[ 0 ][ 1 ] = -KsSin( angle );
    m[ 1 ][ 0 ] = KsSin( angle ); m[ 1 ][ 1 ] =  KsCos( angle ); 
}


#if 0

	f64 cr = cos( rotation.X );
		f64 sr = sin( rotation.X );
		f64 cp = cos( rotation.Y );
		f64 sp = sin( rotation.Y );
		f64 cy = cos( rotation.Z );
		f64 sy = sin( rotation.Z );

		M[0] = (f32)( cp*cy );
		M[1] = (f32)( cp*sy );
		M[2] = (f32)( -sp );

		f64 srsp = sr*sp;
		f64 crsp = cr*sp;

		M[4] = (f32)( srsp*cy-cr*sy );
		M[5] = (f32)( srsp*sy+cr*cy );
		M[6] = (f32)( sr*cp );

		M[8] = (f32)( crsp*cy+sr*sy );
		M[9] = (f32)( crsp*sy-sr*cy );
		M[10] = (f32)( cr*cp );
	}

	//! Returns the rotation, as set by setRotation(). This code was sent
	//! in by Chev.
	ksINLINE core::vector3df matrix4::getRotationDegrees() const
	{
		const matrix4 &mat = *this;
		
		f32 Y = -asinf(mat(2,0)); 
		f32 D = Y;
		f32 C = cosf(Y); 
		Y *= 180.000f/PI; 

		f32 rotx, roty, X, Z;
 
		if (fabs(Y)>0.0005f) 
		{ 
			rotx = mat(2,2) / C; 
			roty = mat(2,1)  / C; 
			X = atan2f( roty, rotx ) * (f32)GRAD_PI; 
			rotx =  mat(0,0) / C; 
			roty = mat(1,0) / C; 
			Z = atan2f( roty, rotx ) * (f32)GRAD_PI; 
		} 
		else 
		{
			X  = 0.0f; 
			rotx = -mat(1,1); 
			roty = mat(1,0); 
			Z  = atan2f( roty, rotx ) * (f32)GRAD_PI; 
		} 
 
		if (fabs(X)>=360.00f) X=0.00f; 
		if (fabs(Y)>=360.00f) Y=0.00f; 
		if (fabs(Z)>=360.00f) Z=0.00f; 
 
		return vector3df(X,Y,Z); 
	}

	ksINLINE void matrix4::setInverseRotationRadians( const vector3df& rotation )
	{
		f64 cr = cos( rotation.X );
		f64 sr = sin( rotation.X );
		f64 cp = cos( rotation.Y );
		f64 sp = sin( rotation.Y );
		f64 cy = cos( rotation.Z );
		f64 sy = sin( rotation.Z );

		M[0] = (f32)( cp*cy );
		M[4] = (f32)( cp*sy );
		M[8] = (f32)( -sp );

		f64 srsp = sr*sp;
		f64 crsp = cr*sp;

		M[1] = (f32)( srsp*cy-cr*sy );
		M[5] = (f32)( srsp*sy+cr*cy );
		M[9] = (f32)( sr*cp );

		M[2] = (f32)( crsp*cy+sr*sy );
		M[6] = (f32)( crsp*sy-sr*cy );
		M[10] = (f32)( cr*cp );
	}
#endif


