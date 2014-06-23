

//===============================================================================================//
// 
//===============================================================================================//
inline KsQuaternion& KsQuaternion::operator = ( const KsQuaternion& refQuat )
{
	x = refQuat.x;
	y = refQuat.y;
	z = refQuat.z;
	w = refQuat.w;

	return (*this);
}

//===============================================================================================//
//
//
//
//===============================================================================================//
inline KsQuaternion& KsQuaternion::operator += ( const KsQuaternion& refQuat )
{
	x += refQuat.x;
	y += refQuat.y;
	z += refQuat.z;
	w += refQuat.w;

	return	(*this);
}

//===============================================================================================//
//
//
//
//===============================================================================================//
inline KsQuaternion& KsQuaternion::operator -= ( const KsQuaternion& refQuat )
{
	x -= refQuat.x;
	y -= refQuat.y;
	z -= refQuat.z;
	w -= refQuat.w;

	return	(*this);
}
//===============================================================================================//
//
//
//
//===============================================================================================//
inline KsQuaternion& KsQuaternion::operator *= ( const KsQuaternion& refQuat )
{
	x = ( w * refQuat.x ) + ( x * refQuat.w ) + ( y * refQuat.z ) + ( z * refQuat.y );
	y = ( w * refQuat.y ) + ( y * refQuat.w ) + ( z * refQuat.x ) + ( x * refQuat.z );
	z = ( w * refQuat.z ) + ( z * refQuat.w ) + ( x * refQuat.y ) + ( y * refQuat.x );
	w = ( w * refQuat.w ) + ( x * refQuat.x ) + ( y * refQuat.y ) + ( z * refQuat.z );

	normalize();

	return	(*this);
}
//===============================================================================================//
//
//
//
//===============================================================================================//
inline KsQuaternion& KsQuaternion::operator *= ( KsReal s )
{
	x *= s;
	y *= s;
	z *= s;
	w *= s;

	return	(*this);
}

//===============================================================================================//
//
//
//
//===============================================================================================//
inline KsQuaternion& KsQuaternion::operator /= ( KsReal s )
{
	if( s < ksTOLERANCE ){
		return (*this);
	}

	x /= s;
	y /= s;
	z /= s;
	w /= s;

	return	(*this);
}


//===============================================================================================//
//
//
//
//===============================================================================================//
inline KsQuaternion KsQuaternion::operator ~ () const 
{
	/* 本当は、正規化する必要があるが生成したときに正規化してあるはずなのでしない？ */
	//Normalize();

	return KsQuaternion( -x, -y, -z, w );
}


//===============================================================================================//
//
//
//
//===============================================================================================//
inline KsQuaternion KsQuaternion::operator + () const 
{
	return ( *this );
}

//===============================================================================================//
//
//
//
//===============================================================================================//
inline KsQuaternion KsQuaternion::operator - () const 
{
	return KsQuaternion( -x, -y, -z, -w );
}


//===============================================================================================//
//
//===============================================================================================//
inline KsQuaternion KsQuaternion::operator + ( const KsQuaternion &refQuat ) const
{
	return KsQuaternion( x + refQuat.x, y + refQuat.y, z + refQuat.z, w + refQuat.w );
}

//===============================================================================================//
//
//===============================================================================================//
inline KsQuaternion KsQuaternion::operator - ( const KsQuaternion &refQuat ) const
{
	return KsQuaternion( x - refQuat.x, y - refQuat.y, z - refQuat.z, w - refQuat.w );
}

//===============================================================================================//
//
//===============================================================================================//
inline KsQuaternion KsQuaternion::operator * ( const KsQuaternion &refQuat ) const
{
	KsQuaternion quat;

	quat.x = ( w * refQuat.x ) + ( x * refQuat.w ) + ( y * refQuat.z ) + ( z * refQuat.y );
	quat.y = ( w * refQuat.y ) + ( y * refQuat.w ) + ( z * refQuat.x ) + ( x * refQuat.z );
	quat.z = ( w * refQuat.z ) + ( z * refQuat.w ) + ( x * refQuat.y ) + ( y * refQuat.x );
	quat.w = ( w * refQuat.w ) + ( x * refQuat.x ) + ( y * refQuat.y ) + ( z * refQuat.z );

	quat.normalize();

	return quat;
}

//===============================================================================================//
//
//
//
//===============================================================================================//
inline KsQuaternion KsQuaternion::operator * ( KsReal s ) const 
{
	return KsQuaternion( s*x, s*y, s*z, s*w );
}
//===============================================================================================//
//
//
//
//===============================================================================================//
inline KsQuaternion KsQuaternion::operator / ( KsReal s ) const 
{
	if( KsFabs( s ) < ksTOLERANCE ){
		KsQuaternion( x, y, z, w );
	}

	return KsQuaternion( x/s, y/s, z/s, w/s );
}

//===============================================================================================//
//
//===============================================================================================//
inline KsBool KsQuaternion::operator == ( const KsQuaternion &refQuat ) const
{
	return (	( KsFabs( x - refQuat.x ) < ksTOLERANCE ) &&
				( KsFabs( y - refQuat.y ) < ksTOLERANCE ) &&
				( KsFabs( z - refQuat.z ) < ksTOLERANCE ) &&
				( KsFabs( w - refQuat.w ) < ksTOLERANCE ) );
}

//===============================================================================================//
//
//===============================================================================================//
inline KsBool KsQuaternion::operator != ( const KsQuaternion &refQuat ) const
{
	return (	( KsFabs( x - refQuat.x ) > ksTOLERANCE ) || 
				( KsFabs( y - refQuat.y ) > ksTOLERANCE ) ||
				( KsFabs( z - refQuat.z ) > ksTOLERANCE ) ||
				( KsFabs( w - refQuat.w ) > ksTOLERANCE ) );
}

//===============================================================================================//
// 
//===============================================================================================//
inline KsReal KsQuaternion::length() const
{
	return	KsSqrt( ( x*x + y*y + z*z + w*w ) );
}

//===============================================================================================//
// 
//===============================================================================================//
inline KsReal KsQuaternion::length2() const
{
	return ( x*x + y*y + z*z + w*w );
}

//===============================================================================================//
// 
//===============================================================================================//
inline void KsQuaternion::normalize()
{
	const KsReal norm = x * x + y * y + z * z + w * w;

	if( norm > ksTOLERANCE2 )
	{
		const KsReal scale = 1.0f / KsSqrt( norm );

		x *= scale;
		y *= scale;
		z *= scale;
		w *= scale;
	}
    else
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
        w = 1.0f;
    }
}

//===============================================================================================//
// 
//===============================================================================================//
inline void KsQuaternion::inverse()
{
	normalize();

	x = -x;
	y = -y;
	z = -z;
}


