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
 * @file	KsFileBuffer.cpp
 * @brief	ファイル操作クラス
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
/************************************************************************************************/

/*==============================================================================================*/
/*                                 << インクルード >>                                           */
/*==============================================================================================*/
#include "KsFileBuffer.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/*
 * コンストラクタ
 * @param	path			ファイルのパス
 * @param	fileName		ファイル名
 * @param	flags			ファイルのオープンフラグ
 * @param	bOpen			オープンするかどうかのフラグ
 *							(ksTRUE:だとオープンする, ksFALSE:だとパスとファイル名をセットするだけ)
 */
/************************************************************************************************/
KsFileBuffer::KsFileBuffer( const KsString& path, const KsString& fileName, KsInt32 flags, KsBool bOpen )
{
	m_name        = fileName;
	m_path        = path;
	m_pBuffer     = 0;
	m_byteOrder   = ksLITTLEENDIAN;
	m_state       = ksINVALID;
	m_flags       = flags;
	m_size        = 0;
	m_pos         = 0;
	
	if( bOpen )
	{
		open();
	}
}

/************************************************************************************************/
/*
 * コンストラクタ
 * @param	fullPath		ファイルのフルパス
 * @param	flags			ファイルのオープンフラグ
 */
/************************************************************************************************/
KsFileBuffer::KsFileBuffer( const KsString& fullPath, KsInt32 flags )
{
	m_pBuffer     = 0;
	m_byteOrder   = ksLITTLEENDIAN;
	m_state       = ksINVALID;
	m_flags       = flags;
	m_size        = 0;
	m_pos         = 0;
	
	open( fullPath, flags );
}

/************************************************************************************************/
/*
 * コンストラクタ
 * @param	pBuffer			データの実体のバッファ
 * @param	size			データサイズ
 * @param	bAlloc			内部で新たに確保するかどうかのフラグ
 */
/************************************************************************************************/
KsFileBuffer::KsFileBuffer( KsByte* pBuffer, KsInt32 size, KsInt32 flags, KsBool bAlloc )
{
	if( bAlloc )
	{
		m_pBuffer = new KsByte[ size ];
	}
	else
    {
		m_pBuffer = pBuffer;
	}
	
	m_byteOrder   = ksLITTLEENDIAN;
	m_state       = ksOPEN;
	m_flags       = flags;
	m_size        = size;
	m_pos         = 0;
	m_bAlloc      = bAlloc;
}

/************************************************************************************************/
/*
 * デストラクタ
 */
/************************************************************************************************/
KsFileBuffer::~KsFileBuffer()
{
	close();
}

/************************************************************************************************/
/*
 * フラグからファイルモードを取得する
 * @param	flags			ファイルを開くモードフラグ
 * @return					ファイルを開く文字列のモード
 */
/************************************************************************************************/
KsString KsFileBuffer::getFileMode( KsUInt32 flags )
{
	KsString	mode;

	if( (flags & ksAPPEND) && (flags & ksWRITE) ) { flags ^= ksWRITE; }

	     if( (flags & ksREAD) && (flags & ksAPPEND) ) { mode = ksT("a+"); }
	else if( (flags & ksREAD) && (flags & ksWRITE ) ) { mode = ksT("w+"); }
	else if(  flags & ksAPPEND ) { mode = ksT("a"); }
	else if(  flags & ksREAD   ) { mode = ksT("r"); }
	else if(  flags & ksWRITE  ) { mode = ksT("w"); }
	else                         { return ksT("");  }

	if( flags & ksBINARY ) { mode += ksT("b"); }
	if( flags & ksCOMMIT ) { mode += ksT("c"); }

	return	mode;
}

/************************************************************************************************/
/*
 * ファイルを開く
 * @param	fullPath		ファイルのフルパス
 * @param	flags			ファイルのオープンフラグ
 * @retval	ksTRUE			成功
 * @retval	ksFALSE			失敗
 */
/************************************************************************************************/
KsBool KsFileBuffer::open( const KsString& fullPath, KsInt32 flags, ksBYTE_ORDER byteOrder )
{
	KsChar		drive[ _MAX_DRIVE ];
	KsChar		dir[ _MAX_DIR ];
	KsChar		fname[ _MAX_FNAME ];
	KsChar		ext[ _MAX_EXT ];
	FILE*		fp = NULL;

	ks_splitpath( fullPath.c_str(), drive, dir, fname, ext );

	KsString		path( drive );
	KsString		name( fname );

	path += dir;	// パス
	name += ext;	// ファイル名

	close();

	if( name.length() ){
		m_name = name;
	}
	
	if( path.length() ){
		m_path = path;
	}

	if( flags != ksNONE ){
		m_flags = flags;
	}

	KsString mode = getFileMode( m_flags );
	
	if( m_path.length() )
	{
		KsString fullPath = m_path;
		
		if( fullPath[ fullPath.length() - 1 ] != '/' && fullPath[ fullPath.length() - 1 ] != '\\' ){
			fullPath += '\\';
		}
	
		fullPath += m_name;
	
		if( !( fp = ks_fopen( fullPath.c_str(), mode.c_str() ) ) )
		{
			return ksFALSE;
		}
	}
	else if( !( fp = ks_fopen( m_name.c_str(), mode.c_str() ) ) )
	{
		return ksFALSE;
	}
	
	m_state     = ksOPEN;
	m_byteOrder = byteOrder;
	
	fseek( fp, 0, SEEK_END );

	m_size = ftell( fp );

	fseek( fp, 0, SEEK_SET );

	m_pBuffer = new KsByte[ m_size ];

	if( m_pBuffer == NULL ){
		fclose( fp );
		return ksFALSE;
	}

	m_bAlloc = ksTRUE;

	fread( m_pBuffer, 1, m_size, fp );

	fclose( fp );

	return ksTRUE;
}

/************************************************************************************************/
/*
 * ファイルを開く
 * @param	path			ファイルのパス
 * @param	fileName		ファイル名
 * @param	flags			ファイルのオープンフラグ
 * @retval	ksTRUE			成功
 * @retval	ksFALSE			失敗
 */
/************************************************************************************************/
KsBool KsFileBuffer::open( const KsString& path, const KsString& fileName, KsInt32 flags )
{
	FILE*		fp = NULL;

	close();

	if( fileName.length() )
	{
		m_name = fileName;
	}
	
	if( path.length() )
	{
		m_path = path;
	}

	if( flags != ksNONE ){
		m_flags = flags;
	}

	KsString mode = getFileMode( m_flags );
	
	if( m_path.length() )
	{
		KsString fullPath = m_path;
		
		if( fullPath[ fullPath.length() - 1 ] != '/' && fullPath[ fullPath.length() - 1 ] != '\\' )
		{
			fullPath += '\\';
		}
	
		fullPath += m_name;
	
		if( !( fp = ks_fopen( fullPath.c_str(), mode.c_str() ) ) )
		{
			return ksFALSE;
		}
	}
	else if( !( fp = ks_fopen( m_name.c_str(), mode.c_str() ) ) )
	{
		return ksFALSE;
	}
	
	m_state     = ksOPEN;
	
	fseek( fp, 0, SEEK_END );

	m_size = ftell( fp );

	fseek( fp, 0, SEEK_SET );

	m_pBuffer = new KsByte[ m_size ];

	if( m_pBuffer == NULL ){
		fclose( fp );
		return ksFALSE;
	}

	m_bAlloc = ksTRUE;

	fread( m_pBuffer, 1, m_size, fp );

	fclose( fp );

	return ksTRUE;
}

/************************************************************************************************/
/*
 * ファイルを閉じる
 */
/************************************************************************************************/
void KsFileBuffer::close()
{
	if( m_bAlloc )
	{
		ksDELETEARRAY( m_pBuffer );	
	}
	else
	{
		m_pBuffer = NULL;
	}

	m_state = ksCLOSED;
}

/************************************************************************************************/
/*
 * 指定された位置にファイル ポインタを移動する
 * @param	offset			指定位置からのバイト数
 * @param	mode			指定位置
 * @return					正常に処理された場合、0 を返します。それ以外の場合は 0 以外の値を返します
 */
/************************************************************************************************/
KsInt32 KsFileBuffer::seek( KsInt32 offset, KsInt32 mode )
{
	if( !isValid() ){
		return 0;
	}

	KsInt32 pos = tell();

	if( ( m_size <= 0 ) ||
	    ( ( mode == SEEK_SET ) && ( offset != pos ) ) ||
	    ( ( mode == SEEK_CUR ) && ( offset ) )        ||
		( ( mode == SEEK_END ) && ( m_size - offset != pos ) ) )
	{
		switch( mode )
		{
			case SEEK_SET:
			{
				m_pos = offset;
				break;
			}
			case SEEK_CUR:
			{
				m_pos += offset;
				break;
			}
			case SEEK_END:
			{
				m_pos = m_size;
				break;
			}
			default:
			{
				return 0;
			}
		}
	}
	
	return ( tell() - m_pos );
}

/************************************************************************************************/
/*
 * ファイルから浮動小数点の値を読み込む
 * @return					浮動小数点の値
 */
/************************************************************************************************/
KsReal KsFileBuffer::readReal()
{
	KS_DATA4	val;
	KS_DATA4	data;

	// 有効かどうかのチェック
	if( !isValid() )
	{
		return 0;
	}

	// 読み込む
	KsSize		size = sizeof(KS_DATA4);
	KsMemCopy( &val, &m_pBuffer[ m_pos ], size );
	m_pos += static_cast< KsInt32 >(size);

	// エンディアンかのチェック
	if( ksLITTLEENDIAN == m_byteOrder )
	{
		// リトルエンディアン
		return	( val.f );
	}
	
	// ビックエンディアン
	data.byte[ 0 ] = val.byte[ 3 ];
	data.byte[ 1 ] = val.byte[ 2 ];
	data.byte[ 2 ] = val.byte[ 1 ];
	data.byte[ 3 ] = val.byte[ 0 ];

	return ( data.f );
}

/************************************************************************************************/
/*
 * ファイルから32bit整数値を読み込む
 * @return					32bit整数値
 */
/************************************************************************************************/
KsInt32 KsFileBuffer::readInt32()
{
	KS_DATA4	val;
	KS_DATA4	data;

	// 有効かどうかのチェック
	if( !isValid() )
	{
		return 0;
	}

	KsSize		size = sizeof(KS_DATA4);
	KsMemCopy( &val, &m_pBuffer[ m_pos ], size );
	m_pos += static_cast< KsInt32 >(size);

	// エンディアンかのチェック
	if( ksLITTLEENDIAN == m_byteOrder )
	{
		// リトルエンディアン
		return	( val.i32 );
	}
	
	// ビックエンディアン
	data.byte[ 0 ] = val.byte[ 3 ];
	data.byte[ 1 ] = val.byte[ 2 ];
	data.byte[ 2 ] = val.byte[ 1 ];
	data.byte[ 3 ] = val.byte[ 0 ];

	return ( data.i32 );
}

/************************************************************************************************/
/*
 * ファイルから符号なし32bit整数値を読み込む
 * @return					符号なし32bit整数値
 */
/************************************************************************************************/
KsUInt32 KsFileBuffer::readUInt32()
{
	KS_DATA4	val;
	KS_DATA4	data;

	// 有効かどうかのチェック
	if( !isValid() )
	{
		return 0;
	}

	KsSize		size = sizeof(KS_DATA4);
	KsMemCopy( &val, &m_pBuffer[ m_pos ], size );
	m_pos += static_cast< KsInt32 >(size);

	// エンディアンかのチェック
	if( ksLITTLEENDIAN == m_byteOrder )
	{
		// リトルエンディアン
		return	( val.u32 );
	}
	
	// ビックエンディアン
	data.byte[ 0 ] = val.byte[ 3 ];
	data.byte[ 1 ] = val.byte[ 2 ];
	data.byte[ 2 ] = val.byte[ 1 ];
	data.byte[ 3 ] = val.byte[ 0 ];

	return ( data.u32 );
}

/************************************************************************************************/
/*
 * ファイルから16bit整数値を読み込む
 * @return					16bit整数値
 */
/************************************************************************************************/
KsInt16 KsFileBuffer::readInt16()
{
	KS_DATA2	val;
	KS_DATA2	data;

	// 有効かどうかのチェック
	if( !isValid() ){
		return 0;
	}

	KsSize		size = sizeof(KS_DATA2);
	KsMemCopy( &val, &m_pBuffer[ m_pos ], size );
	m_pos += static_cast< KsInt32 >(size);

	// エンディアンかのチェック
	if( ksLITTLEENDIAN == m_byteOrder )
	{
		// リトルエンディアン
		return	( val.s16 );
	}
	
	// ビックエンディアン
	data.byte[ 0 ] = val.byte[ 1 ];
	data.byte[ 1 ] = val.byte[ 0 ];

	return ( data.s16 );
}

/************************************************************************************************/
/*
 * ファイルから符号なし16bit整数値を読み込む
 * @return					符号なし16bit整数値
 */
/************************************************************************************************/
KsUInt16 KsFileBuffer::readUInt16()
{
	KS_DATA2	val;
	KS_DATA2	data;

	// 有効かどうかのチェック
	if( !isValid() )
	{
		return 0;
	}

	KsSize		size = sizeof(KS_DATA2);
	KsMemCopy( &val, &m_pBuffer[ m_pos ], size );
	m_pos += static_cast< KsInt32 >(size);

	// エンディアンかのチェック
	if( ksLITTLEENDIAN == m_byteOrder )
	{
		// リトルエンディアン
		return	( val.u16 );
	}
	
	// ビックエンディアン
	data.byte[ 0 ] = val.byte[ 1 ];
	data.byte[ 1 ] = val.byte[ 0 ];

	return ( data.u16 );
}

/************************************************************************************************/
/*
 * ファイルから8bit整数値を読み込む
 * @return					8bit整数値
 */
/************************************************************************************************/
KsChar KsFileBuffer::readChar()
{
	KsChar	val;

	// 有効かどうかのチェック
	if( !isValid() )
	{
		return 0;
	}

	// 読み込む
	KsMemCopy( &val, &m_pBuffer[ m_pos ], 1 );
	++m_pos;

	return val;
}

/************************************************************************************************/
/*
 * ファイルから符号なし8bit整数値を読み込む
 * @return					符号なし8bit整数値
 */
/************************************************************************************************/
KsInt8 KsFileBuffer::readInt8()
{
	KsInt8 val;

	// 有効かどうかのチェック
	if( !isValid() )
	{
		return 0;
	}

	// 読み込む
	KsMemCopy( &val, &m_pBuffer[ m_pos ], 1 );
	++m_pos;

	return val;
}

/************************************************************************************************/
/*
 * ファイルから一文字を読み込む
 * @return					一文字分の値
 */
/************************************************************************************************/
KsUInt8 KsFileBuffer::readUInt8()
{
	KsUInt8 val;

	// 有効かどうかのチェック
	if( !isValid() ){
		return 0;
	}

	// 読み込む
	KsMemCopy( &val, &m_pBuffer[ m_pos ], 1 );
	++m_pos;

	return val;
}

/************************************************************************************************/
/*
 * ファイルから符号なし8bit整数値を読み込む
 * @return					整数値
 */
/************************************************************************************************/
KsInt32 KsFileBuffer::readByte()
{
	KsInt32 val;

	// 有効かどうかのチェック
	if( !isValid() )
	{
		return 0;
	}

	// 読み込む
	KsMemCopy( &val, &m_pBuffer[ m_pos ], 1 );
	++m_pos;

	return val;
}

/************************************************************************************************/
/*
 * ファイルから文字列を読み込む
 * @return					文字列
 */
/************************************************************************************************/
KsString KsFileBuffer::readString()
{
	KsString		str;
	KsChar			buf[ 4*1024 ];
	KsInt32			count = 0;

	// 有効かどうかのチェック
	if( !isValid() )
	{
		return str;
	}

	// 読み込む
	for( KsInt32 i=0; m_pBuffer[ m_pos+i ] != '\0'; i++ )
	{
		++count;
		if( m_size < (count + m_pos) )
		{
			break;
		}
	}
	++count;

	KsMemCopy( buf, &m_pBuffer[ m_pos ], count );
	buf[ count ] = '\0';
	m_pos += count;

	str = buf;
	
	return str;
}

/************************************************************************************************/
/*
 * エンコードされた整数分を読み込む
 * @return					可変長サイズのエンコードされた 32-bit 符号無し整数
 */
/************************************************************************************************/
KsUInt32 KsFileBuffer::readEncodedU32()
{
	KsUInt32 val = (KsUInt32)m_pBuffer[ m_pos++ ];

	if( !(val & 0x00000080) )
	{
		return val;
	}

	val = (val & 0x0000007f) | (KsUInt32)m_pBuffer[ m_pos++ ] << 7;

	if( !(val & 0x00004000) )
	{
		return val;
	}

	val = (val & 0x00003fff) | (KsUInt32)m_pBuffer[ m_pos++ ] << 14;

	if( !(val & 0x00200000) )
	{
		return val;
	}

	val = (val & 0x001fffff) | (KsUInt32)m_pBuffer[ m_pos++ ] << 21;

	if( !(val & 0x10000000) )
	{
		return val;
	}

	val = (val & 0x0fffffff) | (KsUInt32)m_pBuffer[ m_pos++ ] << 28;

	return val;
}

/************************************************************************************************/
/*
 * バッファに指定バイト数分読み込む
 * @param	pBuffer			(OUT)読み込むためのバッファ
 * @param	count			読み込むバイト数
 * @return					読み込んだバイト数
 */
/************************************************************************************************/
KsSize KsFileBuffer::read( void* pBuffer, KsInt32 count )
{
	KsSize	readSize = 0;

	if( pBuffer )
	{
		if( m_pos + count > m_size )
		{
			readSize = m_size - m_pos;
		}
		else
		{
			readSize = count;
		}

		KsMemCopy( pBuffer, &m_pBuffer[ m_pos ], readSize );
		m_pos += count;
	}

	return readSize;
}

/************************************************************************************************/
/*
 * ファイルに値を書き込む
 * @param	val				書き込む値
 * @return					書き込んだバイト数
 */
/************************************************************************************************/
KsSize KsFileBuffer::writeInt16( KsInt16 val )
{
	// 有効かどうかのチェック
	if( !isValid() ){
		return 0;
	}

	KsSize	size = sizeof( KsUInt16 );

	// エンディアンかのチェック
	if( ksLITTLEENDIAN == m_byteOrder )
	{
		// リトルエンディアン
		KsMemCopy( &m_pBuffer[ m_pos ], &val, size );
		m_pos += static_cast< KsInt32 >(size);
	}
	else
	{
		KS_DATA2	temp;
		KS_DATA2	data;

		temp.s16 = val;

		// ビックエンディアン
		data.byte[ 0 ] = temp.byte[ 1 ];
		data.byte[ 1 ] = temp.byte[ 0 ];

		KsMemCopy( &m_pBuffer[ m_pos ], &data.s16, size );
		m_pos += static_cast< KsInt32 >(size);
	}

	return size;
}

/************************************************************************************************/
/*
 * ファイルに値を書き込む
 * @param	val				書き込む値
 * @return					書き込んだバイト数
 */
/************************************************************************************************/
KsSize KsFileBuffer::writeUInt16( KsUInt16 val )
{
	// 有効かどうかのチェック
	if( !isValid() ){
		return 0;
	}

	KsSize	size = sizeof( KsUInt16 );

	// エンディアンかのチェック
	if( ksLITTLEENDIAN == m_byteOrder )
	{
		// リトルエンディアン
		KsMemCopy( &m_pBuffer[ m_pos ], &val, size );
		m_pos += static_cast< KsInt32 >(size);
	}
	else
	{
		KS_DATA2	temp;
		KS_DATA2	data;

		temp.u16 = val;

		// ビックエンディアン
		data.byte[ 0 ] = temp.byte[ 1 ];
		data.byte[ 1 ] = temp.byte[ 0 ];

		KsMemCopy( &m_pBuffer[ m_pos ], &data.u16, size );
		m_pos += static_cast< KsInt32 >(size);
	}

	return size;
}

/************************************************************************************************/
/*
 * ファイルに値を書き込む
 * @param	val				書き込む値
 * @return					書き込んだバイト数
 */
/************************************************************************************************/
KsSize KsFileBuffer::writeInt32( KsInt32 val )
{
	// 有効かどうかのチェック
	if( !isValid() ){
		return 0;
	}

	KsSize	size = sizeof( KsInt32 );

	// エンディアンかのチェック
	if( ksLITTLEENDIAN == m_byteOrder )
	{
		// リトルエンディアン
		KsMemCopy( &m_pBuffer[ m_pos ], &val, size );
		m_pos += static_cast< KsInt32 >(size);
	}
	else
	{
		KS_DATA4	temp;
		KS_DATA4	data;

		temp.i32 = val;

		// ビックエンディアン
		data.byte[ 0 ] = temp.byte[ 3 ];
		data.byte[ 1 ] = temp.byte[ 2 ];
		data.byte[ 2 ] = temp.byte[ 1 ];
		data.byte[ 3 ] = temp.byte[ 0 ];

		KsMemCopy( &m_pBuffer[ m_pos ], &data.i32, size );
		m_pos += static_cast< KsInt32 >(size);
	}

	return size;
}

/************************************************************************************************/
/*
 * ファイルに値を書き込む
 * @param	val				書き込む値
 * @return					書き込んだバイト数
 */
/************************************************************************************************/
KsSize KsFileBuffer::writeUInt32( KsUInt32 val )
{
	// 有効かどうかのチェック
	if( !isValid() ){
		return 0;
	}

	KsSize	size = sizeof( KsUInt32 );

	// エンディアンかのチェック
	if( ksLITTLEENDIAN == m_byteOrder )
	{
		// リトルエンディアン
		KsMemCopy( &m_pBuffer[ m_pos ], &val, size );
		m_pos += static_cast< KsInt32 >(size);
	}
	else
	{
		KS_DATA4	temp;
		KS_DATA4	data;

		temp.u32 = val;

		// ビックエンディアン
		data.byte[ 0 ] = temp.byte[ 3 ];
		data.byte[ 1 ] = temp.byte[ 2 ];
		data.byte[ 2 ] = temp.byte[ 1 ];
		data.byte[ 3 ] = temp.byte[ 0 ];

		KsMemCopy( &m_pBuffer[ m_pos ], &data.u32, size );
		m_pos += static_cast< KsInt32 >(size);
	}

	return size;
}

/************************************************************************************************/
/*
 * ファイルに値を書き込む
 * @param	val				書き込む値
 * @return					書き込んだバイト数
 */
/************************************************************************************************/
KsSize KsFileBuffer::writeReal( KsReal val )
{
	// 有効かどうかのチェック
	if( !isValid() ){
		return 0;
	}

	KsSize	size = sizeof( KsReal );

	// エンディアンかのチェック
	if( ksLITTLEENDIAN == m_byteOrder )
	{
		// リトルエンディアン
		KsMemCopy( &m_pBuffer[ m_pos ], &val, size );
		m_pos += static_cast< KsInt32 >(size);
	}
	else
	{
		KS_DATA4	temp;
		KS_DATA4	data;

		temp.f = val;

		// ビックエンディアン
		data.byte[ 0 ] = temp.byte[ 3 ];
		data.byte[ 1 ] = temp.byte[ 2 ];
		data.byte[ 2 ] = temp.byte[ 1 ];
		data.byte[ 3 ] = temp.byte[ 0 ];

		KsMemCopy( &m_pBuffer[ m_pos ], &data.f, size );
		m_pos += static_cast< KsInt32 >(size);
	}

	return size;
}

/************************************************************************************************/
/*
 * ファイルに値を書き込む
 * @param	val				書き込む値
 * @return					書き込んだバイト数
 */
/************************************************************************************************/
KsSize KsFileBuffer::writeInt8( KsInt8 val )
{
	// 有効かどうかのチェック
	if( !isValid() ){
		return 0;
	}

	KsSize size = sizeof(KsInt8);

	KsMemCopy( m_pBuffer, &val, size );

	return size;
}

/************************************************************************************************/
/*
 * ファイルに値を書き込む
 * @param	val				書き込む値
 * @return					書き込んだバイト数
 */
/************************************************************************************************/
KsSize KsFileBuffer::writeUInt8( KsUInt8 val )
{
	// 有効かどうかのチェック
	if( !isValid() ){
		return 0;
	}

	KsSize size = sizeof(KsUInt8);

	KsMemCopy( &m_pBuffer[ m_pos ], &val, size );
	m_pos += static_cast< KsInt32 >(size);

	return size;
}

/************************************************************************************************/
/*
 * ファイルに値を書き込む
 * @param	val				書き込む値
 * @return					書き込んだバイト数
 */
/************************************************************************************************/
KsSize KsFileBuffer::writeChar( KsChar val )
{
	// 有効かどうかのチェック
	if( !isValid() )
	{
		return 0;
	}

	KsSize size = sizeof(KsChar);

	KsMemCopy( &m_pBuffer[ m_pos ], &val, size );
	m_pos += static_cast< KsInt32 >(size);

	return size;
}

/************************************************************************************************/
/*
 * ファイルに値を書き込む
 * @param	val				書き込む値
 * @return					書き込んだバイト数
 */
/************************************************************************************************/
KsSize KsFileBuffer::writeByte( KsInt32 val )
{
	// 有効かどうかのチェック
	if( !isValid() )
	{
		return 0;
	}

	KsSize size = sizeof(KsByte);

	KsMemCopy( &m_pBuffer[ m_pos ], &val, size );
	m_pos += static_cast< KsInt32 >(size);

	return size;
}

/************************************************************************************************/
/*
 * バッファからファイルに値を書き込む
 * @param	pBuffer			書き込むバッファ
 * @param	count			書き込むバイト数
 * @return					書き込んだバイト数
 */
/************************************************************************************************/
KsSize KsFileBuffer::write( const void *pBuffer, KsInt32 count )
{
	if( !isValid() || ( count <= 0 ) )
	{
		return 0;
	}

	KsSize size = 0;
	
	if( pBuffer )
	{
		if( m_size < ( m_pos + count )  )
		{
			size = m_size - m_pos;
		}
		else
		{
			size = count;
		}

		KsMemCopy( &m_pBuffer[ m_pos ], pBuffer, size );

		m_pos += count;
	}
	else
	{
		KsUInt32	pos = tell();
		seek( count, SEEK_CUR );
		size = tell() - pos;
	}

	return size;
}

ksNS_KS_END

