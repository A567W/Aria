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
 * @file	KsString.cpp
 * @brief	文字列操作
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/

/*==============================================================================================*/
/*                                 << インクルード >>                                             */
/*==============================================================================================*/
#include "KsString.h"

/*===============================================================================================*/
/*                                     << 定義 >>                                                */
/*===============================================================================================*/
ksNS_KS_BEGIN


/************************************************************************************************/
/*
 * コンストラクタ
 */
/************************************************************************************************/
KsString::KsString()
 : m_pString( 0 )
 , m_length( 0 )
 , m_size( 0 )
{
}

/************************************************************************************************/
/*
 * コンストラクタ
 * @param		string		文字列クラスの参照
 */
/************************************************************************************************/
KsString::KsString( const KsString& string )
 : m_pString( 0 )
 , m_length( 0 )
 , m_size( 0 )
{
	/* 長さを取得 */
	m_length = string.length();
	
	/* バッファサイズを取得 */
	m_size = string.size();
	
	/* メモリーを確保しなおす */
	ksDELETEARRAY( m_pString );

	m_pString = new KsChar[ m_size ];

	/* コピーする */
	KsMemCopy( m_pString, string.c_str(), m_size );
}

/************************************************************************************************/
/*
 * コンストラクタ
 * @param		pString		文字列のポインタ
 */
/************************************************************************************************/
KsString::KsString( const KsSChar* pString )
 : m_pString( 0 )
 , m_length( 0 )
 , m_size( 0 )
{
#ifdef UNICODE
	/* 長さを取得 */
	m_length = static_cast<KsUInt32>( strlen(pString) );

	/* バッファサイズを取得 */
	m_size = m_length + 1;

	/* メモリーを確保しなおす */
	ksDELETEARRAY( m_pString );

	m_pString = new KsChar[ m_size ];

	//ロケール指定
	setlocale(LC_ALL,"japanese");

	//変換
	size_t	convLen = 0;
	mbstowcs_s( &convLen, m_pString, m_size, pString, _TRUNCATE );
	m_pString[ m_length ] = '\0';
#else
	/* 長さを取得 */
	m_length = static_cast<KsUInt32>( ks_strlen(pString) );

	/* バッファサイズを取得 */
	m_size = m_length + 1;

	/* メモリーを確保しなおす */
	ksDELETEARRAY( m_pString );

	m_pString = new KsChar[ m_size ];

	/* コピーする */
	KsMemCopy( m_pString, pString, m_size );

	m_pString[ m_length ] = '\0';
#endif // UNICODE
}

/************************************************************************************************/
/*
 * コンストラクタ
 * @param		pString		文字列のポインタ
 */
/************************************************************************************************/
KsString::KsString( const KsWChar* pString )
 : m_pString( 0 )
 , m_length( 0 )
 , m_size( 0 )
{
#ifdef UNICODE
	/* 長さを取得 */
	m_length = static_cast<KsUInt32>( ks_strlen(pString) );

	/* バッファサイズを取得 */
	m_size = 2*(m_length + 1);

	/* メモリーを確保しなおす */
	ksDELETEARRAY( m_pString );

	m_pString = new KsChar[ m_size ];

	/* メモリーをクリアーする */
	KsZeroMemory( m_pString, m_size );

	/* コピーする */
	KsMemCopy( m_pString, pString, m_size );
#else
	/* 長さを取得 */
	m_length = static_cast<KsUInt32>( wcslen(pString) );

	/* バッファサイズを取得 */
	m_size = 2*(m_length + 1);

	/* メモリーを確保しなおす */
	ksDELETEARRAY( m_pString );

	m_pString = new KsChar[ m_size ];

	/* メモリーをクリアーする */
	KsZeroMemory( m_pString, m_size );

	//ロケール指定
	setlocale(LC_ALL,"japanese");

	//変換
	KsUInt32	convLen = 0;
	wcstombs_s( &convLen, m_pString, m_size, pString, _TRUNCATE );
#endif // UNICODE
}

/************************************************************************************************/
/*
 * デストラクタ
 */
/************************************************************************************************/
KsString::~KsString()
{
	ksDELETEARRAY( m_pString );
}

/************************************************************************************************/
/*
 * 指定範囲の文字を削除する
 * @param		top			消す文字列の先頭
 * @param		num			消す文字列の数
 */
/************************************************************************************************/
void KsString::erase( KsUInt32 top, KsUInt32 num )
{
	KsUInt32	length = m_length - num + 1;

	KsChar*		pBuf = new KsChar[ length ];

	if( pBuf )
	{
		ks_strncpy( pBuf, &m_pString[ top ], num );
		pBuf[ length ] = '\0';
	
		ksDELETEARRAY( m_pString );

		m_pString = pBuf;
		m_length  = length;
	}
}

/************************************************************************************************/
/*
 * 文字列をクリア
 */
/************************************************************************************************/
void KsString::clear()
{
	ksDELETEARRAY( m_pString );
	m_length  = 0;
	m_pString = 0;
}

/************************************************************************************************/
/*
 * 文字列をクリア
 */
/************************************************************************************************/
KsString& KsString::operator=( const KsString& string )
{
	/* 長さを取得 */
	m_length = string.length();

	/* バッファサイズを取得 */
	m_size = string.size();
	
	/* メモリーを確保しなおす */
	ksDELETEARRAY( m_pString );

	m_pString = new KsChar[ m_size ];

	/* コピーする */
	KsMemCopy( m_pString, string.c_str(), m_size );

	return	(*this);
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
KsString& KsString::operator=( const KsSChar* pString )
{
#ifdef UNICODE
	/* 長さを取得 */
	m_length = static_cast<KsUInt32>( strlen(pString) );

	/* バッファサイズを取得 */
	m_size = m_length + 1;

	/* メモリーを確保しなおす */
	ksDELETEARRAY( m_pString );

	m_pString = new KsChar[ m_size ];

	//ロケール指定
	setlocale(LC_ALL,"japanese");

	//変換
	size_t	convLen = 0;
	mbstowcs_s( &convLen, m_pString, m_size, pString, _TRUNCATE );
	m_pString[ m_length ] = '\0';
#else
	/* 長さを取得 */
	m_length = static_cast<KsUInt32>( ks_strlen(pString) );

	/* バッファサイズを取得 */
	m_size = m_length + 1;

	/* メモリーを確保しなおす */
	ksDELETEARRAY( m_pString );

	m_pString = new KsChar[ m_size ];

	/* コピーする */
	KsMemCopy( m_pString, pString, m_size );

	m_pString[ m_length ] = '\0';
#endif // UNICODE

	return	(*this);
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
KsString& KsString::operator=( const KsWChar* pString )
{
#ifdef UNICODE
	/* 長さを取得 */
	m_length = static_cast<KsUInt32>( ks_strlen(pString) );

	/* バッファサイズを取得 */
	m_size = 2*(m_length + 1);

	/* メモリーを確保しなおす */
	ksDELETEARRAY( m_pString );

	m_pString = new KsChar[ m_size ];

	/* メモリーをクリアーする */
	KsZeroMemory( m_pString, m_size );

	/* コピーする */
	KsMemCopy( m_pString, pString, m_size );
#else
	/* 長さを取得 */
	m_length = static_cast<KsUInt32>( wcslen(pString) );

	/* バッファサイズを取得 */
	m_size = 2*(m_length + 1);

	/* メモリーを確保しなおす */
	ksDELETEARRAY( m_pString );

	m_pString = new KsChar[ m_size ];

	/* メモリーをクリアーする */
	KsZeroMemory( m_pString, m_size );

	//ロケール指定
	setlocale(LC_ALL,"japanese");

	//変換
	KsUInt32	convLen = 0;
	wcstombs_s( &convLen, m_pString, m_size, pString, _TRUNCATE );
#endif // UNICODE

	return	(*this);
}


/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
KsString& KsString::operator=( const KsChar c )
{
	/* 長さを取得 */
	m_length = 1;

	/* バッファサイズを取得 */
	m_size = 2;

	/* メモリーを確保しなおす */
	ksDELETEARRAY( m_pString );

	m_pString = new KsChar[ 2 ];
	m_pString[ 1 ] = '\0';

	return	(*this);
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
KsString& KsString::operator+=( const KsString& string )
{
	const KsUInt32 len = string.length();

	/* 長さを取得 */
	m_length += len;

	/* バッファサイズを取得 */
	m_size += string.length();

	/* メモリーを確保しなおす */
	KsChar*		pTemp = new KsChar[ m_length+1 ];

	ks_strncpy( pTemp, m_pString, len );
	ks_strcat( pTemp, string.c_str() );

	ksDELETEARRAY( m_pString );

	m_pString = pTemp;

	return	(*this);
}
/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
KsString& KsString::operator+=( const KsChar* pString )
{
	const KsUInt32 len = static_cast<KsUInt32>( ks_strlen(pString) );

	/* 長さを取得 */
	m_length += len;

	/* バッファサイズを取得 */
	m_size += len;

	/* メモリーを確保しなおす */
	KsChar*		pTemp = new KsChar[ m_length+1 ];

	ks_strncpy( pTemp, m_pString, len );
	ks_strcat( pTemp, pString );

	ksDELETEARRAY( m_pString );

	m_pString = pTemp;

	return	(*this);
}
/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
KsString& KsString::operator+=( const KsChar c )
{
	/* メモリーを確保しなおす */
	KsChar*		pTemp = new KsChar[ m_length+2 ];

	ks_strncpy( pTemp, m_pString, m_length );
	pTemp[ m_length   ] = c;
	pTemp[ m_length+1 ] = '\0';

	/* 長さを取得 */
	m_length++;
	m_size++;

	ksDELETEARRAY( m_pString );

	m_pString = pTemp;

	return	(*this);
}
/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
KsString KsString::operator+(const KsString& string )
{
	KsString		temp;

	temp  = (*this);
	temp += string;

	return temp;
}
/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
KsString KsString::operator+(const KsChar* pString )
{
	KsString		temp;

	temp  = (*this);
	temp += pString;

	return temp;
}
/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
KsString KsString::operator+(const KsChar c )
{
	KsString		temp;

	temp  = (*this);
	temp += c;

	return temp;
}

/************************************************************************************************/
/*
 * ワイド文字列(WCHAR*)をマルチバイト文字列(char*)に変換
 * @param	wStrW		変換前文字列
 * @param	pOut		変換文字列格納バッファ
 */
/************************************************************************************************/
KsUInt32 ks_wcstombs( const KsWChar* wStrW, KsSChar* pOut, KsUInt32 len )
{
	KsUInt32	wLen = 0;

	//ロケール指定
	setlocale( LC_ALL,"japanese" );

	//変換
	wcstombs_s( &wLen, pOut, len, wStrW, _TRUNCATE );

	return wLen;
}

/************************************************************************************************/
/*
 * マルチバイト文字列(char*)をワイド文字列(WCHAR*)に変換
 */
/************************************************************************************************/
KsUInt32 ks_mbstowcs( const KsSChar* sStr, KsWChar* pOut, KsUInt32 len )
{
	KsUInt32	wLen = 0;

	//ロケール指定
	setlocale( LC_ALL,"japanese" );

	//変換
	mbstowcs_s( &wLen, pOut, len, sStr, _TRUNCATE );

	return wLen;
}

ksNS_KS_END

