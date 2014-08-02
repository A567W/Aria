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
 * @file	KsFileObject.h
 * @brief	ファイル操作クラス
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
/************************************************************************************************/
#ifndef __KSFILEOBJECT_H__
#define __KSFILEOBJECT_H__

/*===============================================================================================*/
/*                                 << インクルード >>                                            */
/*===============================================================================================*/
#include "KsFileCommon.h"

/*===============================================================================================*/
/*                                     << 定義 >>                                                */
/*===============================================================================================*/
#define ksSEEK_SET		( SEEK_SET )
#define ksSEEK_CUR		( SEEK_CUR )
#define ksSEEK_END		( SEEK_END )

/*===============================================================================================*/
/*                                     << 宣言 >>                                                */
/*===============================================================================================*/
ksNS_KS_BEGIN

/*************************************************************************************************/
/**
 * @enum	ksFILE_FLAG
 * @brief	ファイルを開くときのフラグ
 */
/*************************************************************************************************/
enum ksFILE_FLAG
{
	ksNONE    = 0,								/**< 定義されてない	*/
	ksREAD    = 0x00000001,						/**< 読み込み用		*/
	ksWRITE   = 0x00000002,						/**< 書き込み用		*/
	ksAPPEND  = 0x00000004,						/**< 追加処理用		*/
	ksBINARY  = 0x00000008,						/**< バイナリ用		*/
	ksCOMMIT  = 0x00000016,						/**< コミット用		*/
	ksFILE_FLAG_DEFAULT = ( ksREAD | ksBINARY )	/**< デフォルト		*/
};

/*************************************************************************************************/
/**
 * @enum	ksFILE_STATE
 * @brief	ファイルの状態
 */
/*************************************************************************************************/
enum ksFILE_STATE
{
	ksINVALID,			/**< 無効な値				*/
	ksOPEN,				/**< ファイルは開かれている	*/
	ksCLOSED,			/**< ファイルは閉られている	*/
};

/*************************************************************************************************/
/**
 * @enum	ksBYTE_OERDER
 * @brief	リトルエンディアンかビックエンディアンかのモード
 */
/*************************************************************************************************/
enum ksBYTE_ORDER
{
	ksLITTLEENDIAN,		/**< リトルエンディアン		*/
	ksBIGENDIAN,		/**< ビックエンディアン		*/
};

/*************************************************************************************************/
/**
 * ファイル操作用 共用体(32bit)
 */
/*************************************************************************************************/
typedef union _KS_DATA4
{
	KsReal				f;
	KsInt32				i32;
	KsUInt32			u32;
	KsByte				byte[ 4 ];
}KS_DATA4;

/*************************************************************************************************/
/**
 * ファイル操作用 共用体(16bit)
 */
/*************************************************************************************************/
typedef union _KS_DATA2
{
	KsInt16				s16;
	KsUInt16			u16;
	KsByte				byte[ 2 ];
}KS_DATA2;

/*************************************************************************************************/
/**
 * @class	KsFile
 * @brief	ファイルクラス
 * @author	A567W
 * @date	2003/11/30
 * @version	1.0.0
 */
/*************************************************************************************************/
class ksENGINE_API KsFileObject
{
	protected:
		ksFILE_STATE					m_state;			/**< ファイルの状態		*/
		ksBYTE_ORDER					m_byteOrder;		/**< バイトの並び順		*/
		KsUInt32						m_flags;			/**< フラグ				*/
		KsInt32							m_size;				/**< ファイルサイズ		*/
		KsString						m_path;				/**< ファイルのパス		*/
		KsString						m_name;				/**< ファイル名			*/
	public:
		/**
		 * コンストラクタ
		 */
										KsFileObject() : m_state( ksINVALID ), m_byteOrder( ksLITTLEENDIAN ), m_flags( 0 ), m_size( 0 ) {}

		/**
		 * デストラクタ
		 * @brief						ファイルが開かれていたら閉じる
		 */
		virtual							~KsFileObject(){}
	
		/**
		 * ファイルパスを取得する
		 * @return						ファイルのパス
		 */
		const KsString&					getPath() const { return m_path; }

		/**
		 * ファイル名を取得する
		 * @return						ファイル名
		 */
		const KsString&					getName() const { return m_name; }

		/**
		 * リトルエンディアンかビックエンディアンかを取得する
		 * @return						リトルエンディアンかビックエンディアンかのフラグ
		 */
		ksBYTE_ORDER					getByteOrder() const { return m_byteOrder; }

		/**
		 * ファイルパスをセットする
		 * @param	path				ファイルのパス
		 */
		void							setPath( const KsString& path ) { m_path = path; }
		
		/**
		 * ファイル名をセットする
		 * @param	name				ファイル名
		 */
		void							setName( const KsString& name ) { m_name = name; }

		/**
		 * リトルエンディアンかビックエンディアンかをセットする
		 * @param	byteOrder			リトルエンディアンかビックエンディアンかのフラグ
		 */
		void							setByteOrder( ksBYTE_ORDER byteOrder ) { m_byteOrder = byteOrder; }
		
		/**
		 * ファイルサイズを取得する
		 * @return						ファイルサイズ
		 */
		virtual KsInt32					getSize() const { return m_size; }

		/**
		 * ファイルを開く
 		 * @param	fullPath			ファイルのフルパス
		 * @param	flags				ファイルのオープンフラグ
		 * @retval	ksTRUE				成功
		 * @retval	ksFALSE				失敗
		 */
		virtual KsBool					open( const KsString& fullPath, KsInt32 flags, ksBYTE_ORDER byteOrder=ksLITTLEENDIAN ) = 0;

		/**
		 * ファイルを開く
		 * @param	path				ファイルのパス
		 * @param	fileName			ファイル名
		 * @param	flags				ファイルのオープンフラグ
		 * @retval	ksTRUE				成功
		 * @retval	ksFALSE				失敗
		 */
		virtual KsBool					open( const KsString& path = ksT(""), const KsString& fileName = ksT(""), KsInt32 flags = ksNONE ) = 0;

		/**
		 * ファイルを閉じる
		 */
		virtual void					close() = 0;

		/**
		 * ファイルポインタを取得する
		 * @return						ファイルポインタ
		 */
		virtual const void*				getFilePtr() const = 0;

		/**
		 * ファイルが開かれて有効になっているかをチェックする
		 * @retval	ksTRUE				ファイルは開かれている
		 * @retval	ksFALSE				ファイルは開かれていない
		 */
		virtual KsBool					isValid() = 0;

		/**
		 * ファイル ポインタの現在位置を取得する
		 * @return						ファイル先頭から現在位置までのオフセットアドレス
		 */
		virtual KsInt32					tell() = 0;

		/**
		 * 指定された位置にファイル ポインタを移動する
		 * @param	offset				指定位置からのバイト数
		 * @param	mode				指定位置
		 * @return						正常に処理された場合、0 を返します。それ以外の場合は 0 以外の値を返します
		 */
		virtual KsInt32					seek( KsInt32 offset, KsInt32 mode ) = 0;

		/**
		 * ファイルから浮動小数点の値を読み込む
		 * @return						浮動小数点の値
		 */
		virtual KsReal					readReal() = 0;

		/**
		 * ファイルから32bit整数値を読み込む
		 * @return					32bit整数値
		 */
		virtual KsInt32					readInt32() = 0;

		/**
		 * ファイルから符号なし32bit整数値を読み込む
		 * @return						符号なし32bit整数値
		 */
		virtual KsUInt32				readUInt32() = 0;

		/**
		 * ファイルから16bit整数値を読み込む
		 * @return						16bit整数値
		 */
		virtual KsInt16					readInt16() = 0;

		/**
		 * ファイルから符号なし16bit整数値を読み込む
		 * @return						符号なし16bit整数値
		 */
		virtual KsUInt16				readUInt16() = 0;

		/**
		 * ファイルから8bit整数値を読み込む
		 * @return						8bit整数値
		 */
		virtual KsInt8					readInt8() = 0;

		/**
		 * ファイルから符号なし8bit整数値を読み込む
		 * @return						符号なし8bit整数値
		 */
		virtual KsUInt8					readUInt8() = 0;

		/**
		 * ファイルから一文字を読み込む
		 * @return						一文字分の値
		 */
		virtual KsChar					readChar() = 0;

		/**
		 * ファイルから符号なし8bit整数値を読み込む
		 * @return						整数値
		 */
		virtual KsInt32					readByte() = 0;

		/**
		 * ファイルから文字列を読み込む
		 * @return						文字列
		 */
		virtual KsString				readString() = 0;

		/**
		 * エンコードされた整数分を読み込む
		 * @return						可変長サイズのエンコードされた 32-bit 符号無し整数
		 */
		virtual KsUInt32				readEncodedU32() = 0;

		/**
		 * バッファに指定バイト数分読み込む
		 * @param	pBuffer				(OUT)読み込むためのバッファ
		 * @param	count				読み込むバイト数
		 * @return						読み込んだバイト数
		 */
		virtual KsSize					read( void *pBuffer, KsInt32 count ) = 0;

		/**
		 * ファイルに値を書き込む
		 * @param	val					書き込む値
		 * @return						書き込んだバイト数
		 */
		virtual KsSize					writeReal( KsReal val ) = 0;

		/**
		 * ファイルに値を書き込む
		 * @param	val					書き込む値
		 * @return						書き込んだバイト数
		 */
		virtual KsSize					writeInt32( KsInt32 val ) = 0;

		/**
		 * ファイルに値を書き込む
		 * @param	val					書き込む値
		 * @return						書き込んだバイト数
		 */
		virtual KsSize					writeUInt32( KsUInt32 val ) = 0;

		/**
		 * ファイルに値を書き込む
		 * @param	val					書き込む値
		 * @return						書き込んだバイト数
		 */
		virtual KsSize					writeInt16( KsInt16 val ) = 0;

		/**
		 * ファイルに値を書き込む
		 * @param	val					書き込む値
		 * @return						書き込んだバイト数
		 */
		virtual KsSize					writeUInt16( KsUInt16 val ) = 0;

		/**
		 * ファイルに値を書き込む
		 * @param	val					書き込む値
		 * @return						書き込んだバイト数
		 */
		virtual KsSize					writeInt8( KsInt8 val ) = 0;

		/**
		 * ファイルに値を書き込む
		 * @param	val					書き込む値
		 * @return						書き込んだバイト数
		 */
		virtual KsSize					writeUInt8( KsUInt8 val ) = 0;

		/**
		 * ファイルに値を書き込む
		 * @param	val					書き込む値
		 * @return						書き込んだバイト数
		 */
		virtual KsSize					writeChar( KsChar val ) = 0;

		/**
		 * ファイルに値を書き込む
		 * @param	val					書き込む値
		 * @return						書き込んだバイト数
		 */
		virtual KsSize					writeByte( KsInt32 val ) = 0;

		/**
		 * バッファからファイルに値を書き込む
		 * @param	pBuffer				書き込むバッファ
		 * @param	count				書き込むバイト数
		 * @return						書き込んだバイト数
		 */
		virtual KsSize					write( const void *pBuffer, KsInt32 count ) = 0;
};

ksNS_KS_END

#endif /* __KSFILEOBJECT_H__ */


