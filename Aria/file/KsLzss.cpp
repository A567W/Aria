/************************************************************************************************/
/**
 * @file		KsLzss.cpp
 * @brief		スライド辞書圧縮(LZSS法)
 * @author		A567W
 * @date		2004/03/30
 * @version		1.0.0
 */
/************************************************************************************************/

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsLzss.h"
#include "KsBitIO.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/*
 * 初期化する
 */
/************************************************************************************************/
void KsLzss::initTree( KsInt32 node )
{
	/* 初期化 */
	memset( (void*)&m_tree, 0, sizeof( KsTree )*ksTREE_SIZE );

	m_tree[ ksTREE_ROOT ].largeChild = node;
	m_tree[ node ].parent            = ksTREE_ROOT;
	m_tree[ node ].largeChild        = ksUNUSED;
	m_tree[ node ].smallChild        = ksUNUSED;
}

/************************************************************************************************/
/*
 * 短縮
 */
/************************************************************************************************/
void KsLzss::contractNode( KsInt32 oldNode, KsInt32 newNode )
{
	KsInt32		oldNodeParent = m_tree[ oldNode ].parent;

	/* 新しいノードの親をセットする */
	m_tree[ newNode ].parent = oldNodeParent;

	/* 古いノードは親のどちらに設定されていたかを調べる */
	if( m_tree[ oldNodeParent ].largeChild == oldNode )
	{
		m_tree[ oldNodeParent ].largeChild = newNode;
	}
	else{
		m_tree[ oldNodeParent ].smallChild = newNode;
	}

	/* 古いノードは、空状態にする */
	m_tree[ oldNode ].parent = ksUNUSED;
}
/************************************************************************************************/
/*
 * ノードの置換処理
 */
/************************************************************************************************/
void KsLzss::replaceNode( KsInt32 oldNode, KsInt32 newNode )
{
	KsInt32		oldNodeParent     = m_tree[ oldNode ].parent;

	/* 古いノードは親のどちらに設定されていたかを調べる */
	if( m_tree[ oldNodeParent ].smallChild == oldNode )
	{
		m_tree[ oldNodeParent ].smallChild = newNode;
	}
	else
	{
		m_tree[ oldNodeParent ].largeChild = newNode;
	}

	/* 新しいノードを追加する */
	m_tree[ newNode ]                  = m_tree[ oldNode ];
	m_tree[ m_tree[ newNode ].smallChild ].parent = newNode;
	m_tree[ m_tree[ newNode ].largeChild ].parent = newNode;

	/* 古いノードは、空状態にする */
	m_tree[ oldNode ].parent = ksUNUSED;
}
/************************************************************************************************/
/*
 * 次のノードを取得
 */
/************************************************************************************************/
KsInt32 KsLzss::nextNode( KsInt32 node )
{
	KsInt32		next = m_tree[ node ].smallChild;
	
	// 次のノードを検索
	while( m_tree[ next ].largeChild != ksUNUSED )
	{
		next = m_tree[ next ].largeChild;
	}

	return	next;
}

/************************************************************************************************/
/*
 * ノードを追加する
 */
/************************************************************************************************/
KsInt32 KsLzss::addNode( KsInt32 newNode, KsInt32* matchPos )
{
	KsInt32		i;
	KsInt32		node;
	KsInt32		delta;
	KsInt32		matchLength = 0;
	KsInt32*		pChild;

	if( newNode == ksEND ){
		return 0;
	}

	node = m_tree[ ksTREE_ROOT ].largeChild;

	while( ksTRUE )
	{
		for( i=0; i<ksMATCH_LENGTH_MAX; i++ )
		{
			delta = m_buffer[ ksHASH( newNode + i ) ] - m_buffer[ ksHASH( node + i ) ];

			if( delta != 0 )
			{
				break;
			}
		}
		
		if( i >= matchLength )
		{
			matchLength = i;
			*matchPos = node;
			
			if( matchLength >= ksMATCH_LENGTH_MAX )
			{
			
				replaceNode( node, newNode );
				
				return matchLength;
			}
		}

		if ( delta >= 0 )
		{
			pChild = &m_tree[ node ].largeChild;
		}
		else
		{
			pChild = &m_tree[ node ].smallChild;
		}

		if( *pChild == ksUNUSED )
		{
			*pChild                      = newNode;
			m_tree[ newNode ].parent     = node;
			m_tree[ newNode ].largeChild = ksUNUSED;
			m_tree[ newNode ].smallChild = ksUNUSED;
			
			return matchLength;
		}
		
		node = *pChild;
	}

	return matchLength;
}
/************************************************************************************************/
/*
 * ノードを削除する
 */
/************************************************************************************************/
void KsLzss::delNode( KsInt32 p )
{
	int  replacement;

	if( m_tree[ p ].parent == ksUNUSED )
	{
		return;
	}

	if ( m_tree[ p ].largeChild == ksUNUSED )
	{
		contractNode( p, m_tree[ p ].smallChild );
	}
	else if( m_tree[ p ].smallChild == ksUNUSED )
	{
		contractNode( p, m_tree[ p ].largeChild );
	}
	else 
	{
		replacement = nextNode( p );
		delNode( replacement );
		replaceNode( p, replacement );
	}
}
/************************************************************************************************/
/*
 * エンコード
 */
/************************************************************************************************/
KsUInt32 KsLzss::encode( KsByte* pInputBuffer, KsByte* pOutputBuffer )
{
	KsInt32			replaceCount;
	KsInt32			currentPos  = 1;
	KsInt32			matchLength = 0;
	KsInt32			matchPos    = 0;
	KsInt32			length		= 0;
	KsInt32			c;
	KsBitIO				bitIO( pOutputBuffer );

	// 最初だけ指定サイズ分バッファに読み込む(最大一致長16文字)
	for( length=0 ; length < ksMATCH_LENGTH_MAX; length++ )
	{
		if( ( c = *(pInputBuffer++) ) == EOF )
		{
			break;
		}
		m_buffer[ currentPos + length ] = (KsByte)c;
	}

	/* ツリーの初期化 */
	initTree( currentPos );

	while( length > 0 )
	{
		// 一致長
		if( matchLength > length ){ matchLength = length; }

		// 一致長が短いときそのまま書き出す(2文字以下のとき)
		if ( matchLength <= ksMATCH_LENGTH_MIN )
		{
			// そのまま書き出す
			replaceCount = 1;
			// 圧縮ビットを出力する(1バイト分たまったらファイルに出力される)
			bitIO.pushFlag( 1 );
			// 圧縮データをセットする( 圧縮ビットがいっぱいになったら出力される )
			bitIO.pushData( (KsByte)m_buffer[ currentPos ] );
			bitIO.output();
		}
		else
		{
			//-------------------------------------------------------------------------
			// 圧縮書き出し
			// 18byte読み込む 4bitなので16文字までだが,一致長が2文字だと普通に書き出すので３文字
			// からなので2を引いて18文字までになる
			// +----------------+------+
			// | 0000 0000 0000 | 0000 |
			// +----------------+------+
			// | オフセット位置 |一致長|
			// +----------------+------+
			// |                | 18-2 |
			// +----------------+------+
			// 圧縮ビットを出力する(1バイト分たまったらファイルに出力される)
			bitIO.pushFlag( 0 );
			// 圧縮データをセットする( 圧縮ビットがいっぱいになったら出力される )
			bitIO.pushData( (KsByte)matchPos ); // offset
			bitIO.pushData( (KsByte)( ( (matchPos >> 4) & 0xf0) | (matchLength - 3) ) ); // 
			bitIO.output();

			replaceCount = matchLength;
		}

		for( KsInt32 i=0; i<replaceCount; i++ )
		{
			// 削除処理
			delNode( ksHASH( currentPos + ksMATCH_LENGTH_MAX ) );
			
			if( ( c = *(pInputBuffer++) ) == EOF )
			{
				length--;
			}
			else
			{
				m_buffer[ ksHASH( currentPos + ksMATCH_LENGTH_MAX ) ] = (KsByte)c;
			}
			
			currentPos = ksHASH( currentPos + 1 );

			if( length )
			{
				matchLength = addNode( currentPos, &matchPos );
			}
		}
	}

	// 残っているものを書き出す
	// 終了コードを書き出す
	// 圧縮データで
	// 一致長が0だったら終了
	bitIO.outputAll();

	return bitIO.getSize();
}
/************************************************************************************************/
/*
 * エンコード
 */
/************************************************************************************************/
KsUInt32 KsLzss::encode( KsByte* pInputBuffer, FILE* pOutputFile )
{
	KsInt32			replaceCount;
	KsInt32			currentPos  = 1;
	KsInt32			matchLength = 0;
	KsInt32			matchPos    = 0;
	KsInt32			length		= 0;
	KsInt32			c;
	KsBitIO			bitIO( pOutputFile );

	// 最初だけ指定サイズ分バッファに読み込む(最大一致長16文字)
	for( length=0 ; length < ksMATCH_LENGTH_MAX; length++ )
	{
		if( ( c = *(pInputBuffer++) ) == EOF )
		{
			break;
		}
		m_buffer[ currentPos + length ] = (KsByte)c;
	}

	/* ツリーの初期化 */
	initTree( currentPos );

	while( length > 0 )
	{
		// 一致長
		if( matchLength > length ){ matchLength = length; }

		// 一致長が短いときそのまま書き出す(2文字以下のとき)
		if ( matchLength <= ksMATCH_LENGTH_MIN )
		{
			// そのまま書き出す
			replaceCount = 1;
			// 圧縮ビットを出力する(1バイト分たまったらファイルに出力される)
			bitIO.pushFlag( 1 );
			// 圧縮データをセットする( 圧縮ビットがいっぱいになったら出力される )
			bitIO.pushData( (KsByte)m_buffer[ currentPos ] );
			bitIO.output();
		}
		else
		{
			//-------------------------------------------------------------------------
			// 圧縮書き出し
			// 18byte読み込む 4bitなので16文字までだが,一致長が2文字だと普通に書き出すので３文字
			// からなので2を引いて18文字までになる
			// +----------------+------+
			// | 0000 0000 0000 | 0000 |
			// +----------------+------+
			// | オフセット位置 |一致長|
			// +----------------+------+
			// |                | 18-2 |
			// +----------------+------+
			// 圧縮ビットを出力する(1バイト分たまったらファイルに出力される)
			bitIO.pushFlag( 0 );
			// 圧縮データをセットする( 圧縮ビットがいっぱいになったら出力される )
			bitIO.pushData( (KsByte)matchPos ); // offset
			bitIO.pushData( (KsByte)( ( (matchPos >> 4) & 0xf0) | (matchLength - 3) ) ); // 
			bitIO.output();

			replaceCount = matchLength;
		}

		for( KsInt32 i=0; i<replaceCount; i++ )
		{
			// 削除処理
			delNode( ksHASH( currentPos + ksMATCH_LENGTH_MAX ) );
			
			if( ( c = *(pInputBuffer++) ) == EOF )
			{
				length--;
			}
			else
			{
				m_buffer[ ksHASH( currentPos + ksMATCH_LENGTH_MAX ) ] = (KsByte)c;
			}
			
			currentPos = ksHASH( currentPos + 1 );

			if( length )
			{
				matchLength = addNode( currentPos, &matchPos );
			}
		}
	}

	// 残っているものを書き出す
	// 終了コードを書き出す
	// 圧縮データで
	// 一致長が0だったら終了
	bitIO.outputAll();

	return bitIO.getSize();
}
/************************************************************************************************/
/*
 * エンコード
 */
/************************************************************************************************/
KsUInt32 KsLzss::encode( FILE* pInputFile, KsByte* pOutputBuffer )
{
	KsInt32			replaceCount;
	KsInt32			currentPos  = 1;
	KsInt32			matchLength = 0;
	KsInt32			matchPos    = 0;
	KsInt32			length		= 0;
	KsInt32			c;
	KsBitIO			bitIO( pOutputBuffer );

	// 最初だけ指定サイズ分バッファに読み込む(最大一致長16文字)
	for( length=0 ; length < ksMATCH_LENGTH_MAX; length++ )
	{
		if( ( c = getc( pInputFile ) ) == EOF )
		{
			break;
		}
		m_buffer[ currentPos + length ] = (KsByte)c;
	}

	/* ツリーの初期化 */
	initTree( currentPos );

	while( length > 0 )
	{
		// 一致長
		if( matchLength > length ){ matchLength = length; }

		// 一致長が短いときそのまま書き出す(2文字以下のとき)
		if ( matchLength <= ksMATCH_LENGTH_MIN )
		{
			// そのまま書き出す
			replaceCount = 1;
			// 圧縮ビットを出力する(1バイト分たまったらファイルに出力される)
			bitIO.pushFlag( 1 );
			// 圧縮データをセットする( 圧縮ビットがいっぱいになったら出力される )
			bitIO.pushData( (KsByte)m_buffer[ currentPos ] );
			bitIO.output();
		}
		else
		{
			//-------------------------------------------------------------------------
			// 圧縮書き出し
			// 18byte読み込む 4bitなので16文字までだが,一致長が2文字だと普通に書き出すので３文字
			// からなので2を引いて18文字までになる
			// +----------------+------+
			// | 0000 0000 0000 | 0000 |
			// +----------------+------+
			// | オフセット位置 |一致長|
			// +----------------+------+
			// |                | 18-2 |
			// +----------------+------+
			// 圧縮ビットを出力する(1バイト分たまったらファイルに出力される)
			bitIO.pushFlag( 0 );
			// 圧縮データをセットする( 圧縮ビットがいっぱいになったら出力される )
			bitIO.pushData( (KsByte)matchPos ); // offset
			bitIO.pushData( (KsByte)( ( (matchPos >> 4) & 0xf0) | (matchLength - 3) ) ); // 
			bitIO.output();

			replaceCount = matchLength;
		}

		for( KsInt32 i=0; i<replaceCount; i++ )
		{
			// 削除処理
			delNode( ksHASH( currentPos + ksMATCH_LENGTH_MAX ) );
			
			if( ( c = getc( pInputFile ) ) == EOF )
			{
				length--;
			}
			else
			{
				m_buffer[ ksHASH( currentPos + ksMATCH_LENGTH_MAX ) ] = (KsByte)c;
			}
			
			currentPos = ksHASH( currentPos + 1 );

			if( length )
			{
				matchLength = addNode( currentPos, &matchPos );
			}
		}
	}

	// 残っているものを書き出す
	// 終了コードを書き出す
	// 圧縮データで
	// 一致長が0だったら終了
	bitIO.outputAll();

	return bitIO.getSize();
}
/************************************************************************************************/
/*
 * エンコード
 */
/************************************************************************************************/
KsUInt32 KsLzss::encode( FILE* pInputFile, FILE* pOutputFile )
{
	KsInt32			replaceCount;
	KsInt32			currentPos  = 1;
	KsInt32			matchLength = 0;
	KsInt32			matchPos    = 0;
	KsInt32			length		= 0;
	KsInt32			c;
	KsBitIO			bitIO( pOutputFile );

	// 最初だけ指定サイズ分バッファに読み込む(最大一致長16文字)
	for( length=0 ; length < ksMATCH_LENGTH_MAX; length++ )
	{
		if( ( c = getc( pInputFile ) ) == EOF )
		{
			break;
		}

		m_buffer[ currentPos + length ] = (KsByte)c;
	}

	/* ツリーの初期化 */
	initTree( currentPos );

	while( length > 0 )
	{
		// 一致長
		if( matchLength > length ){ matchLength = length; }

		// 一致長が短いときそのまま書き出す(2文字以下のとき)
		if ( matchLength <= ksMATCH_LENGTH_MIN )
		{
			// そのまま書き出す
			replaceCount = 1;
			// 圧縮ビットを出力する(1バイト分たまったらファイルに出力される)
			bitIO.pushFlag( 1 );
			// 圧縮データをセットする( 圧縮ビットがいっぱいになったら出力される )
			bitIO.pushData( (KsByte)m_buffer[ currentPos ] );
			bitIO.output();
		}
		else
		{
			//-------------------------------------------------------------------------
			// 圧縮書き出し
			// 18byte読み込む 4bitなので16文字までだが,一致長が2文字だと普通に書き出すので３文字
			// からなので2を引いて18文字までになる
			// +----------------+------+
			// | 0000 0000 0000 | 0000 |
			// +----------------+------+
			// | オフセット位置 |一致長|
			// +----------------+------+
			// |                | 18-2 |
			// +----------------+------+
			// 圧縮ビットを出力する(1バイト分たまったらファイルに出力される)
			bitIO.pushFlag( 0 );
			// 圧縮データをセットする( 圧縮ビットがいっぱいになったら出力される )
			bitIO.pushData( (KsByte)matchPos ); // offset
			bitIO.pushData( (KsByte)( ( (matchPos >> 4) & 0xf0) | (matchLength - 3) ) ); // 
			bitIO.output();

			replaceCount = matchLength;
		}

		for( KsInt32 i=0; i<replaceCount; i++ )
		{
			// 削除処理
			delNode( ksHASH( currentPos + ksMATCH_LENGTH_MAX ) );
			
			if( ( c = getc( pInputFile ) ) == EOF )
			{
				length--;
			}
			else
			{
				m_buffer[ ksHASH( currentPos + ksMATCH_LENGTH_MAX ) ] = (KsByte)c;
			}
			
			currentPos = ksHASH( currentPos + 1 );

			if( length )
			{
				matchLength = addNode( currentPos, &matchPos );
			}
		}
	}

	// 残っているものを書き出す
	// 終了コードを書き出す
	// 圧縮データで
	// 一致長が0だったら終了
	bitIO.outputAll();

	return bitIO.getSize();
}
/************************************************************************************************/
/*
 * デコード
 */
/************************************************************************************************/
void KsLzss::decode( FILE* pInputFile, FILE* pOutputFile )
{
	KsInt32		currentPos = 1;
	KsInt32		matchLength;
	KsInt32		matchPos;
	KsInt32		data;
	KsInt32		data1;
	KsInt32		data2;
	KsInt32		flags = 0;
	KsUInt32	size  = 0;

	while( 1 )
	{
		flags >>= 1;

		if( !( flags & 0x0100 ) )
		{
			data  = getc( pInputFile );
			flags = ( 0xff00 | data );
		}

		// データ読み込み
		if( flags & 1 )
		{
			/* 非圧縮のデータ */
			data = getc( pInputFile );
            //*( pOutBuffer++ ) = data1;
			putc( data, pOutputFile );

            m_buffer[ currentPos ] = (KsByte)data;

            currentPos = ksHASH( currentPos + 1 );
		}
		else
		{
			/* 圧縮データ */
			data1       = getc( pInputFile );
			data2       = getc( pInputFile );
			matchPos    = ( ( data2 & 0xf0 ) << 4 ) | data1;	/* 位置取得			*/
			matchLength = ( data2 & 0x0f );
			
			//if( !matchLength ){
			//if( data1 == 0 && data2 ==0 ){
			if( !matchPos )
			{
				/* 終了コード */
				break;
			}

			matchLength += 2;		/* 一致長を求める	*/

			for( KsInt32 i=0; i<=matchLength; i++ )
            {
                data = m_buffer[ ksHASH( matchPos + i ) ];
                
				//*(pOutBuffer++) = c;
				putc( data, pOutputFile );

                m_buffer[ currentPos ] = (KsByte)data;

                currentPos = ksHASH( currentPos + 1 );
            }
		}
	}
}

/************************************************************************************************/
/*
 * デコード
 */
/************************************************************************************************/
void KsLzss::decode( KsByte* pInputBuffer, KsByte* pOutputBuffer )
{
	KsInt32		currentPos = 1;
	KsInt32		matchLength;
	KsInt32		matchPos;
	KsInt32		data;
	KsInt32		data1;
	KsInt32		data2;
	KsInt32		flags = 0;
	KsUInt32	size  = 0;

	while( 1 )
	{
		flags >>= 1;

		if( !( flags & 0x0100 ) )
		{
			data  = *( pInputBuffer++ );
			flags = ( 0xff00 | data );
		}

		// データ読み込み
		if( flags & 1 )
		{
			/* 非圧縮のデータ */
			data = *( pInputBuffer++ );
            *( pOutputBuffer++ ) = data;

            m_buffer[ currentPos ] = (KsByte)data;

            currentPos = ksHASH( currentPos + 1 );
		}
		else
		{
			/* 圧縮データ */
			data1       = *( pInputBuffer++ );
			data2       = *( pInputBuffer++ );
			matchPos    = ( ( data2 & 0xf0 ) << 4 ) | data1;	/* 位置取得			*/
			matchLength = ( data2 & 0x0f );
			
			//if( !matchLength ){
			//if( data1 == 0 && data2 ==0 ){
			if( !matchPos )
			{
				/* 終了コード */
				break;
			}

			matchLength += 2;					/* 一致長を求める	*/

			for( KsInt32 i=0; i<=matchLength; i++ )
            {
                data = m_buffer[ ksHASH( matchPos + i ) ];
                
				*(pOutputBuffer++) = data;

                m_buffer[ currentPos ] = (KsByte)data;

                currentPos = ksHASH( currentPos + 1 );
            }
		}
	}
}

/************************************************************************************************/
/*
 * デコード
 */
/************************************************************************************************/
void KsLzss::decode( KsByte* pInputBuffer, FILE* pOutputFile )
{
	KsInt32		currentPos = 1;
	KsInt32		matchLength;
	KsInt32		matchPos;
	KsInt32		data;
	KsInt32		data1;
	KsInt32		data2;
	KsInt32		flags = 0;
	KsUInt32	size  = 0;

	while( 1 )
	{
		flags >>= 1;

		if( !( flags & 0x0100 ) )
		{
			data  = *( pInputBuffer++ );
			flags = ( 0xff00 | data );
		}

		// データ読み込み
		if( flags & 1 )
		{
			/* 非圧縮のデータ */
			data = *( pInputBuffer++ );
			putc( data, pOutputFile );

            m_buffer[ currentPos ] = (KsByte)data;

            currentPos = ksHASH( currentPos + 1 );
		}
		else
		{
			/* 圧縮データ */
			data1       = *( pInputBuffer++ );
			data2       = *( pInputBuffer++ );
			matchPos    = ( ( data2 & 0xf0 ) << 4 ) | data1;	/* 位置取得	*/
			matchLength = ( data2 & 0x0f );
			
			//if( !matchLength ){
			//if( data1 == 0 && data2 ==0 ){
			if( !matchPos )
			{
				/* 終了コード */
				break;
			}

			matchLength += 2;		/* 一致長を求める	*/

			for( KsInt32 i=0; i<=matchLength; i++ )
            {
                data = m_buffer[ ksHASH( matchPos + i ) ];
                
				putc( data, pOutputFile );

                m_buffer[ currentPos ] = (KsByte)data;

                currentPos = ksHASH( currentPos + 1 );
            }
		}
	}
}

/************************************************************************************************/
/*
 * デコード
 */
/************************************************************************************************/
void KsLzss::decode( FILE* pInputFile, KsByte* pOutputBuffer )
{
	KsInt32		currentPos = 1;
	KsInt32		matchLength;
	KsInt32		matchPos;
	KsInt32		data;
	KsInt32		data1;
	KsInt32		data2;
	KsInt32		flags = 0;
	KsUInt32	size  = 0;

	while( 1 )
	{
		flags >>= 1;

		if( !( flags & 0x0100 ) )
		{
			data  = getc( pInputFile );
			flags = ( 0xff00 | data );
		}

		// データ読み込み
		if( flags & 1 )
		{
			/* 非圧縮のデータ */
			data = getc( pInputFile );
            *( pOutputBuffer++ ) = data;

            m_buffer[ currentPos ] = (KsByte)data;

            currentPos = ksHASH( currentPos + 1 );
		}
		else
		{
			/* 圧縮データ */
			data1       = getc( pInputFile );
			data2       = getc( pInputFile );
			matchPos    = ( ( data2 & 0xf0 ) << 4 ) | data1;	/* 位置取得	*/
			matchLength = ( data2 & 0x0f );
			
			//if( !matchLength ){
			//if( data1 == 0 && data2 ==0 ){
			if( !matchPos )
			{
				/* 終了コード */
				break;
			}

			matchLength += 2;					/* 一致長を求める	*/

			for( KsInt32 i=0; i<=matchLength; i++ )
            {
                data = m_buffer[ ksHASH( matchPos + i ) ];
                
				*(pOutputBuffer++) = data;

                m_buffer[ currentPos ] = (KsByte)data;

                currentPos = ksHASH( currentPos + 1 );
            }
		}
	}
}


ksNS_KS_END

