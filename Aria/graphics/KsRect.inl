

inline KsRect::KsRect()
	:
	m_origin( 0, 0 ),
	m_size( 0, 0 )
{
}


inline KsRect::KsRect( KsInt32 originX, KsInt32 originY, KsInt32 sizeX, KsInt32 sizeY ) :
	m_origin( KsPoint( originX, originY ) ),
	m_size( KsPoint( sizeX, sizeY ) )
{
}


inline KsRect::KsRect( KsReal originX, KsReal originY, KsReal sizeX, KsReal sizeY ) :
	m_origin( KsPoint( originX, originY ) ),
	m_size( KsPoint( sizeX, sizeY ) )
{
}


inline KsRect::KsRect( const KsPoint& origin, const KsPoint& size ) :
	m_origin( origin ),
	m_size( size )
{
}


inline void KsRect::set( KsInt32 originX, KsInt32 originY, KsInt32 sizeX, KsInt32 sizeY )
{
	m_origin.set( originX, originY );
	m_size.set ( sizeX, sizeY );
}


inline void KsRect::set( KsReal originX, KsReal originY, KsReal sizeX, KsReal sizeY )
{
	m_origin.set( originX, originY );
	m_size.set ( sizeX, sizeY );
}


inline void KsRect::set( const KsPoint &origin, const KsPoint &dim )
{
	m_origin = origin;
	m_size   = dim;
}


inline KsBool KsRect::isEmpty() const
{
	return( ( m_size.x <= 0 ) || ( m_size.y <= 0 ) );
}


inline void KsRect::setOrigin( const KsPoint& origin )
{
	m_origin = origin;
}


inline void KsRect::setSize( const KsPoint& size )
{
	m_size = size;
}


inline const KsPoint& KsRect::getOrigin() const
{
	return m_origin;
}


inline const KsPoint& KsRect::getSize() const
{
	return m_size;
}

