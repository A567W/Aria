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
 * @file	KsFile.cpp
 * @brief	ファイル操作クラス
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
/************************************************************************************************/

/*===============================================================================================*/
/*                                 << インクルード >>                                            */
/*===============================================================================================*/
#include "KsFile.h"

/*===============================================================================================*/
/*                                     << 定義 >>                                                */
/*===============================================================================================*/

/*===============================================================================================*/
/*                                     << 宣言 >>                                                */
/*===============================================================================================*/
ksNS_KS_BEGIN

//===============================================================================================//
// コンストラクタ
//===============================================================================================//
KsFile::KsFile( const KsString& path, const KsString& fileName, KsInt32 flags, KsBool bOpen )//, KsDirectory *pDirectory )
{
	m_name        = fileName;
	m_path        = path;
	m_pFile       = 0;
	m_byteOrder   = ksLITTLEENDIAN;
	m_state       = ksINVALID;
	m_flags       = flags;
	m_size        = 0;
	
	if( bOpen ){
		open();
	}
}

//===============================================================================================//
// コンストラクタ
//===============================================================================================//
KsFile::KsFile( const KsString& fullPath, KsInt32 flags )
{
	m_pFile       = 0;
	m_byteOrder   = ksLITTLEENDIAN;
	m_state       = ksINVALID;
	m_flags       = flags;
	m_size        = 0;
	
	open( fullPath, flags );
}

//===============================================================================================//
// デストラクタ
//===============================================================================================//
KsFile::~KsFile()
{
	close();
}

//===============================================================================================//
// フラグからファイルモードに変換する
//===============================================================================================//
KsString KsFile::getFileMode( KsUInt32 flags )
{
	KsString	mode;

	if( (flags & ksAPPEND) && (flags & ksWRITE) ) { flags ^= ksWRITE; }

	     if( (flags & ksREAD) && (flags & ksAPPEND) ) { mode = ksT("a+"); }
	else if( (flags & ksREAD) && (flags & ksWRITE ) ) { mode = ksT("w+"); }
	else if(  flags & ksAPPEND ) { mode = ksT("a"); }
	else if(  flags & ksREAD   ) { mode = ksT("r"); }
	else if(  flags & ksWRITE  ) { mode = ksT("w"); }
	else                         { return ksT(""); }

	//
	if( flags & ksBINARY ) { mode += ksT("b"); }

	//
	if( flags & ksCOMMIT ) { mode += ksT("c"); }

	return	mode;
}

//===============================================================================================//
// ファイル ポインタの現在位置を取得する
//===============================================================================================//
KsInt32 KsFile::tell()
{
	return ftell( m_pFile );
}

//===============================================================================================//
// 指定された位置にファイル ポインタを移動する
//===============================================================================================//
KsInt32 KsFile::seek( KsInt32 offset, KsInt32 mode )
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
		fseek( m_pFile, offset, mode );
	}
	
	return ( tell() - pos );
}


//===============================================================================================//
// ファイルオープン
//===============================================================================================//
KsBool KsFile::open( const KsString& fullPath, KsInt32 flags, ksBYTE_ORDER byteOrder )
{
	KsChar		drive[ _MAX_DRIVE ];
	KsChar		dir[ _MAX_DIR ];
	KsChar		fname[ _MAX_FNAME ];
	KsChar		ext[ _MAX_EXT ];

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
	
		if( !( m_pFile = ks_fopen( fullPath.c_str(), mode.c_str() ) ) )
		{
			return ksFALSE;
		}
	}
	else if( !( m_pFile = ks_fopen( m_name.c_str(), mode.c_str() ) ) )
	{
		return ksFALSE;
	}
	
	m_state     = ksOPEN;
	m_byteOrder = byteOrder;
	
	seek( 0, SEEK_END );

	m_size = tell();

	seek( 0, SEEK_SET );
	
	return ksTRUE;
}


//===============================================================================================//
// ファイルオープン
//===============================================================================================//
KsBool KsFile::open( const KsString& path, const KsString& fileName, KsInt32 flags )
{
	close();
	
	if( fileName.length() ){
		m_name = fileName;
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
	
		if( !( m_pFile = ks_fopen( fullPath.c_str(), mode.c_str() ) ) )
		{
			return ksFALSE;
		}
	}
	else if( !( m_pFile = ks_fopen( m_name.c_str(), mode.c_str() ) ) )
	{
		return ksFALSE;
	}
	
	m_state = ksOPEN;
	
	seek( 0, SEEK_END );

	m_size = tell();

	seek( 0, SEEK_SET );
	
	return ksTRUE;
}

//===============================================================================================//
// ファイルを閉じる
//===============================================================================================//
void KsFile::close()
{
	if( m_pFile ){
		fclose( m_pFile );
		m_pFile = NULL;
	}
	
	m_state = ksCLOSED;
}

//===============================================================================================//
// ファイルから読み込む
//===============================================================================================//
KsSize KsFile::read( void* pBuffer, KsInt32 count )
{
	KsSize		size;

	if( pBuffer ){
		//size = fread( pBuffer, 1, count, m_pFile );
		size = fread( pBuffer, count, 1, m_pFile );
	}
	else{
		KsSize pos = tell();

		seek( count, SEEK_CUR );

		size = tell() - pos;
	}

	return size;
}

//===============================================================================================//
// ファイルから読み込む
//===============================================================================================//
KsString KsFile::readString()
{
	KsString		str;
	KsChar			buf[ 4*1024 ];
	
	// 有効かどうかのチェック
	if( !isValid() )
	{
		return str;
	}

	// 読み込む
	ks_fgets( buf, 4*1024, m_pFile );
	str = buf;
	
	return str;
}

//===============================================================================================//
// ファイルから読み込む
//===============================================================================================//
KsChar KsFile::readChar()
{
	KsChar val;

	// 有効かどうかのチェック
	if( !isValid() )
	{
		return 0;
	}

	// 読み込む
	fread( &val, 1, sizeof(KsChar), m_pFile );
	//val = fgetc( m_pFile );

	return val;
}

//===============================================================================================//
// ファイルから読み込む
//===============================================================================================//
KsInt8 KsFile::readInt8()
{
	KsInt8 val;

	// 有効かどうかのチェック
	if( !isValid() )
	{
		return 0;
	}

	// 読み込む
	fread( &val, 1, sizeof(KsInt8), m_pFile );

	return val;
}

//===============================================================================================//
// ファイルから読み込む
//===============================================================================================//
KsUInt8 KsFile::readUInt8()
{
	KsUInt8 val;

	// 有効かどうかのチェック
	if( !isValid() )
	{
		return 0;
	}

	// 読み込む
	fread( &val, 1, sizeof(KsUInt8), m_pFile );

	return val;
}

//===============================================================================================//
// ファイルから読み込む
//===============================================================================================//
KsInt32 KsFile::readByte()
{
	KsInt32 val;

	// 有効かどうかのチェック
	if( !isValid() )
	{
		return 0;
	}

	// 読み込む
	fread( &val, 1, sizeof(KsUInt8), m_pFile );

	return val;
}

//===============================================================================================//
// ファイルから読み込む
//===============================================================================================//
KsInt16 KsFile::readInt16()
{
	KS_DATA2	val;
	KS_DATA2	data;

	// 有効かどうかのチェック
	if( !isValid() )
	{
		return 0;
	}

	// 読み込む
	fread( &val, 1, sizeof(KS_DATA2), m_pFile );

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

//===============================================================================================//
// ファイルから読み込む
//===============================================================================================//
KsUInt16 KsFile::readUInt16()
{
	KS_DATA2	val;
	KS_DATA2	data;

	// 有効かどうかのチェック
	if( !isValid() )
	{
		return 0;
	}

	// 読み込む
	fread( &val, 1, sizeof(KS_DATA2), m_pFile );

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


//===============================================================================================//
// ファイルから読み込む
//===============================================================================================//
KsInt32 KsFile::readInt32()
{
	KS_DATA4	val;
	KS_DATA4	data;

	// 有効かどうかのチェック
	if( !isValid() )
	{
		return 0;
	}

	// 読み込む
	fread( &val, 1, sizeof(KS_DATA4), m_pFile );

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

//===============================================================================================//
// ファイルから読み込む
//===============================================================================================//
KsUInt32 KsFile::readUInt32()
{
	KS_DATA4	val;
	KS_DATA4	data;

	// 有効かどうかのチェック
	if( !isValid() )
	{
		return 0;
	}

	// 読み込む
	fread( &val, 1, sizeof(KS_DATA4), m_pFile );

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

//===============================================================================================//
// ファイルから読み込む
//===============================================================================================//
KsReal KsFile::readReal()
{
	KS_DATA4	val;
	KS_DATA4	data;

	// 有効かどうかのチェック
	if( !isValid() )
	{
		return 0;
	}

	// 読み込む
	fread( &val, 1, sizeof(KS_DATA4), m_pFile );

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
 * エンコードされた整数分を読み込む
 * @return					可変長サイズのエンコードされた 32-bit 符号無し整数
 */
/************************************************************************************************/
KsUInt32 KsFile::readEncodedU32()
{
	KsByte	data = 0;

	fread( &data, 1, sizeof(KsByte), m_pFile );

	KsUInt32 val = (KsUInt32)data;

	if( !(val & 0x00000080) )
	{
		return val;
	}

	fread( &data, 1, sizeof(KsByte), m_pFile );

	val = (val & 0x0000007f) | (KsUInt32)data << 7;

	if( !(val & 0x00004000) )
	{
		return val;
	}

	fread( &data, 1, sizeof(KsByte), m_pFile );

	val = (val & 0x00003fff) | (KsUInt32)data << 14;

	if( !(val & 0x00200000) )
	{
		return val;
	}

	fread( &data, 1, sizeof(KsByte), m_pFile );

	val = (val & 0x001fffff) | (KsUInt32)data << 21;

	if( !(val & 0x10000000) )
	{
		return val;
	}

	fread( &data, 1, sizeof(KsByte), m_pFile );

	val = (val & 0x0fffffff) | (KsUInt32)data << 28;

	return val;
}

/************************************************************************************************/
/*
 * ファイルに値を書き込む
 * @param	val				書き込む値
 * @return					書き込んだバイト数
 */
/************************************************************************************************/
KsSize KsFile::writeInt16( KsInt16 val )
{
	// 有効かどうかのチェック
	if( !isValid() )
	{
		return 0;
	}

	// エンディアンかのチェック
	if( ksLITTLEENDIAN == m_byteOrder )
	{
		// リトルエンディアン
		return fwrite( &val, 1, sizeof(KsInt16), m_pFile );
	}

	KS_DATA2	temp;
	KS_DATA2	data;

	temp.s16 = val;

	// ビックエンディアン
	data.byte[ 0 ] = temp.byte[ 1 ];
	data.byte[ 1 ] = temp.byte[ 0 ];

	return fwrite( &data.s16, 1, sizeof(KsInt16), m_pFile );
}

/************************************************************************************************/
/*
 * ファイルに値を書き込む
 * @param	val				書き込む値
 * @return					書き込んだバイト数
 */
/************************************************************************************************/
KsSize KsFile::writeUInt16( KsUInt16 val )
{
	// 有効かどうかのチェック
	if( !isValid() ){
		return 0;
	}

	// エンディアンかのチェック
	if( ksLITTLEENDIAN == m_byteOrder ){
		// リトルエンディアン
		return fwrite( &val, 1, sizeof(KsUInt16), m_pFile );
	}

	KS_DATA2	temp;
	KS_DATA2	data;

	temp.u16 = val;

	// ビックエンディアン
	data.byte[ 0 ] = temp.byte[ 1 ];
	data.byte[ 1 ] = temp.byte[ 0 ];

	return fwrite( &data.u16, 1, sizeof(KsUInt16), m_pFile );
}

/************************************************************************************************/
/*
 * ファイルに値を書き込む
 * @param	val				書き込む値
 * @return					書き込んだバイト数
 */
/************************************************************************************************/
KsSize KsFile::writeInt32( KsInt32 val )
{
	// 有効かどうかのチェック
	if( !isValid() ){
		return 0;
	}

	// エンディアンかのチェック
	if( ksLITTLEENDIAN == m_byteOrder ){
		// リトルエンディアン
		return fwrite( &val, 1, sizeof(KsInt32), m_pFile );
	}

	KS_DATA4	temp;
	KS_DATA4	data;

	temp.i32 = val;

	// ビックエンディアン
	data.byte[ 0 ] = temp.byte[ 3 ];
	data.byte[ 1 ] = temp.byte[ 2 ];
	data.byte[ 2 ] = temp.byte[ 1 ];
	data.byte[ 3 ] = temp.byte[ 0 ];

	return fwrite( &data.i32, 1, sizeof(KsInt32), m_pFile );
}

/************************************************************************************************/
/*
 * ファイルに値を書き込む
 * @param	val				書き込む値
 * @return					書き込んだバイト数
 */
/************************************************************************************************/
KsSize KsFile::writeUInt32( KsUInt32 val )
{
	// 有効かどうかのチェック
	if( !isValid() ){
		return 0;
	}

	// エンディアンかのチェック
	if( ksLITTLEENDIAN == m_byteOrder ){
		// リトルエンディアン
		return fwrite( &val, 1, sizeof(KsUInt32), m_pFile );
	}

	KS_DATA4	temp;
	KS_DATA4	data;

	temp.u32 = val;

	// ビックエンディアン
	data.byte[ 0 ] = temp.byte[ 3 ];
	data.byte[ 1 ] = temp.byte[ 2 ];
	data.byte[ 2 ] = temp.byte[ 1 ];
	data.byte[ 3 ] = temp.byte[ 0 ];

	return fwrite( &data.u32, 1, sizeof(KsUInt32), m_pFile );
}

/************************************************************************************************/
/*
 * ファイルに値を書き込む
 * @param	val				書き込む値
 * @return					書き込んだバイト数
 */
/************************************************************************************************/
KsSize KsFile::writeReal( KsReal val )
{
	// 有効かどうかのチェック
	if( !isValid() ){
		return 0;
	}

	// エンディアンかのチェック
	if( ksLITTLEENDIAN == m_byteOrder ){
		// リトルエンディアン
		return fwrite( &val, 1, sizeof(KsReal), m_pFile );
	}

	KS_DATA4	temp;
	KS_DATA4	data;

	temp.f = val;

	// ビックエンディアン
	data.byte[ 0 ] = temp.byte[ 3 ];
	data.byte[ 1 ] = temp.byte[ 2 ];
	data.byte[ 2 ] = temp.byte[ 1 ];
	data.byte[ 3 ] = temp.byte[ 0 ];

	return fwrite( &data.f, 1, sizeof(KsReal), m_pFile );
}

/************************************************************************************************/
/*
 * ファイルに値を書き込む
 * @param	val				書き込む値
 * @return					書き込んだバイト数
 */
/************************************************************************************************/
KsSize KsFile::writeInt8( KsInt8 val )
{
	// 有効かどうかのチェック
	if( !isValid() ){
		return 0;
	}

	// リトルエンディアン
	return fwrite( &val, 1, sizeof(KsInt8), m_pFile );
}

/************************************************************************************************/
/*
 * ファイルに値を書き込む
 * @param	val				書き込む値
 * @return					書き込んだバイト数
 */
/************************************************************************************************/
KsSize KsFile::writeUInt8( KsUInt8 val )
{
	// 有効かどうかのチェック
	if( !isValid() ){
		return 0;
	}

	// リトルエンディアン
	return fwrite( &val, 1, sizeof(KsUInt8), m_pFile );
}

/************************************************************************************************/
/*
 * ファイルに値を書き込む
 * @param	val				書き込む値
 * @return					書き込んだバイト数
 */
/************************************************************************************************/
KsSize KsFile::writeChar( KsChar val )
{
	// 有効かどうかのチェック
	if( !isValid() ){
		return 0;
	}

	// リトルエンディアン
	return fwrite( &val, 1, sizeof(KsChar), m_pFile );
}

/************************************************************************************************/
/*
 * ファイルに値を書き込む
 * @param	val				書き込む値
 * @return					書き込んだバイト数
 */
/************************************************************************************************/
KsSize KsFile::writeByte( KsInt32 val )
{
	// 有効かどうかのチェック
	if( !isValid() ){
		return 0;
	}

	// リトルエンディアン
	return fwrite( &val, 1, sizeof(KsInt8), m_pFile );
}

/************************************************************************************************/
/*
 * バッファからファイルに値を書き込む
 * @param	pBuffer			書き込むバッファ
 * @param	count			書き込むバイト数
 * @return					書き込んだバイト数
 */
/************************************************************************************************/
KsSize KsFile::write( const void *pBuffer, KsInt32 count )
{
	if( !isValid() || ( count <= 0 ) ){
		return 0;
	}

	KsSize size = 0;
	
	if( pBuffer ){
		size = fwrite( pBuffer, 1, count, m_pFile );
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
