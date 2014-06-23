

//===============================================================================================//
// 平面のセット
//===============================================================================================//
ksINLINE void KsPlane::set( const KsVector3d& refNormal, KsReal distance )
{
	m_normal   = refNormal;
	m_distance = distance;
}

//===============================================================================================//
// 平面のセット
//===============================================================================================//
ksINLINE void KsPlane::set( const KsVector3d& refPointA, const KsVector3d& refPointB, const KsVector3d& refPointC )
{
	KsVector3d		abVector = refPointB - refPointA;
	KsVector3d		acVector = refPointC - refPointA;
	
	m_normal = acVector.crossProduct( abVector );
	m_normal.normalize();
	
	m_distance = -m_normal.dotProduct( refPointA );
}

//===============================================================================================//
// 平面のセット
//===============================================================================================//
ksINLINE void KsPlane::set( const KsVector3d& refNormal, const KsVector3d& refPoint )
{
	m_normal   =  refNormal;
	m_distance = -m_normal.dotProduct( refPoint );
}

//===============================================================================================//
// YZ平面から垂線を伸ばして交差した場所のX座標を取得する
//===============================================================================================//
ksINLINE KsReal KsPlane::getX( KsReal y, KsReal z )
{
	if( KsFabs( m_normal.x ) < ksTOLERANCE ){
		return 0.0f;
	}
	
	return ( -( m_normal.y*y + m_normal.z*z + m_distance )/m_normal.x );
}

//===============================================================================================//
// XZ平面から垂線を伸ばして交差した場所のY座標を取得する
//===============================================================================================//
ksINLINE KsReal KsPlane::getY( KsReal x, KsReal z )
{
	if( KsFabs( m_normal.y ) < ksTOLERANCE ){
		return 0.0f;
	}
	
	return ( -( m_normal.x*x + m_normal.z*z + m_distance )/m_normal.y );
}

//===============================================================================================//
// XY平面から垂線を伸ばして交差した場所のZ座標を取得する
//===============================================================================================//
ksINLINE KsReal KsPlane::getZ( KsReal x, KsReal y )
{
	if( KsFabs( m_normal.y ) < ksTOLERANCE ){
		return 0.0f;
	}

	return ( -( m_normal.x*x + m_normal.y*y + m_distance )/m_normal.z );
}

//===============================================================================================//
// YZ平面から垂線を伸ばして交差した座標を取得する
//===============================================================================================//
ksINLINE KsVector3d KsPlane::getPointX( KsReal y, KsReal z )
{
	if( KsFabs( m_normal.x ) < ksTOLERANCE ){
		return KsVector3d( 0.0f, y, z );
	}
	
	return  KsVector3d( ( -( m_normal.y*y + m_normal.z*z + m_distance )/m_normal.x ), y, z );
}

//===============================================================================================//
// XZ平面から垂線を伸ばして交差した座標を取得する
//===============================================================================================//
ksINLINE KsVector3d KsPlane::getPointY( KsReal x, KsReal z )
{
	if( KsFabs( m_normal.y ) < ksTOLERANCE ){
		return KsVector3d( x, 0.0f, z );
	}
	
	return KsVector3d( x, ( -( m_normal.x*x + m_normal.z*z + m_distance )/m_normal.y ), z );
}

//===============================================================================================//
// XY平面から垂線を伸ばして交差した座標を取得する
//===============================================================================================//
ksINLINE KsVector3d KsPlane::getPointZ( KsReal x, KsReal y )
{
	if( KsFabs( m_normal.y ) < ksTOLERANCE ){
		return KsVector3d( x, y, 0.0f );
	}

	return KsVector3d( x, y, ( -( m_normal.x*x + m_normal.y*y + m_distance )/m_normal.z ) );
}

//===============================================================================================//
// 平面上の1点を取得する
//===============================================================================================//
ksINLINE KsVector3d KsPlane::getOnPoint() const
{
	return	( m_normal*( -m_distance ) ); 
}

//===============================================================================================//
// 点と平面の距離を求める
//===============================================================================================//
ksINLINE KsReal KsPlane::distance( const KsVector3d& refPoint ) const 
{
	return ( m_normal.dotProduct( refPoint ) + m_distance ); 
}

//===============================================================================================//
// 平面を代入します
//===============================================================================================//
ksINLINE KsPlane& KsPlane::operator = ( const KsPlane& refPlane )
{
	m_normal   = refPlane.m_normal;
	m_distance = refPlane.m_distance;
	
	return ( *this );
}

//===============================================================================================//
// 平面が等しいかどうかを判定する
//===============================================================================================//
ksINLINE KsBool KsPlane::operator == ( const KsPlane& refPlane ) const 
{
	return ( ( KsFabs( refPlane.m_distance - m_distance ) < ksTOLERANCE ) &&  ( refPlane.m_normal == m_normal ) );
}

//===============================================================================================//
// 平面が等しくないかどうかを判定する
//===============================================================================================//
ksINLINE KsBool KsPlane::operator != ( const KsPlane& refPlane ) const 
{
	return ( ( KsFabs( refPlane.m_distance - m_distance ) > ksTOLERANCE ) ||  ( refPlane.m_normal != m_normal ) );
}


