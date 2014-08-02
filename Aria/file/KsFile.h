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
 * @file	KsFile.h
 * @brief	ファイル操作クラス
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
/************************************************************************************************/
#ifndef __KSFILE_H__
#define __KSFILE_H__

/*===============================================================================================*/
/*                                 << インクルード >>                                             */
/*===============================================================================================*/
#include "KsFileObject.h"

/*===============================================================================================*/
/*                                     << 定義 >>                                                */
/*===============================================================================================*/

/*===============================================================================================*/
/*                                     << 宣言 >>                                                */
/*===============================================================================================*/
ksNS_KS_BEGIN

/*************************************************************************************************/
/**
 * @class	KsFile
 * @brief	ファイルクラス
 * @author	A567W
 * @date	2003/11/30
 * @version	1.0.0
 */
/*************************************************************************************************/
class ksENGINE_API KsFile : public KsFileObject
{
	protected:
		FILE*						m_pFile;			/**< ファイルポインタ		*/

	public:

		/**
		 * コンストラクタ
		 * @param	fullPath		ファイルのフルパス
		 * @param	flags			ファイルのオープンフラグ
		 */
									KsFile( const KsString& fullPath, KsInt32 flags );
									
		/**
		 * コンストラクタ
		 * @param	path			ファイルのパス
		 * @param	fileName		ファイル名
		 * @param	flags			ファイルのオープンフラグ
		 * @param	bOpen			オープンするかどうかのフラグ(ksTRUE:だとオープンする, ksFALSE:だとパスとファイル名をセットするだけ)
		 */
									KsFile( const KsString& path = ksT(""), const KsString& fileName = ksT(""), KsInt32 flags = ksFILE_FLAG_DEFAULT, KsBool bOpen = ksFALSE );

		/**
		 * デストラクタ
		 * @brief					ファイルが開かれていたら閉じる
		 */
		virtual						~KsFile();
		
		/**
		 * ファイルを開く
 		 * @param	fullPath		ファイルのフルパス
		 * @param	flags			ファイルのオープンフラグ
		 * @retval	ksTRUE			成功
		 * @retval	ksFALSE			失敗
		 */
		virtual KsBool				open( const KsString& fullPath, KsInt32 flags, ksBYTE_ORDER byteOrder=ksLITTLEENDIAN );

		/**
		 * ファイルを開く
		 * @param	path			ファイルのパス
		 * @param	fileName		ファイル名
		 * @param	flags			ファイルのオープンフラグ
		 * @retval	ksTRUE			成功
		 * @retval	ksFALSE			失敗
		 */
		virtual KsBool				open( const KsString& path = ksT(""), const KsString& fileName = ksT(""), KsInt32 flags = ksNONE );

		/**
		 * ファイルを閉じる
		 */
		virtual void				close();

		/**
		 * ファイルポインタを取得する
		 * @return						ファイルポインタ
		 */
		virtual const void*			getFilePtr() const { return m_pFile; }

		/**
		 * ファイルが開かれて有効になっているかをチェックする
		 * @retval	ksTRUE			ファイルは開かれている
		 * @retval	ksFALSE			ファイルは開かれていない
		 */
		virtual KsBool				isValid() { return ( m_pFile && ( m_state == ksOPEN ) ); }

		/**
		 * ファイル ポインタの現在位置を取得する
		 * @return					ファイル先頭から現在位置までのオフセットアドレス
		 */
		virtual KsInt32				tell();

		/**
		 * 指定された位置にファイル ポインタを移動する
		 * @param	offset			指定位置からのバイト数
		 * @param	mode			指定位置
		 * @return					正常に処理された場合、0 を返します。それ以外の場合は 0 以外の値を返します
		 */
		virtual KsInt32				seek( KsInt32 offset, KsInt32 mode );

		/**
		 * ファイルから浮動小数点の値を読み込む
		 * @return					浮動小数点の値
		 */
		virtual KsReal				readReal();

		/**
		 * ファイルから32bit整数値を読み込む
		 * @return					32bit整数値
		 */
		virtual KsInt32				readInt32();

		/**
		 * ファイルから符号なし32bit整数値を読み込む
		 * @return					符号なし32bit整数値
		 */
		virtual KsUInt32			readUInt32();

		/**
		 * ファイルから16bit整数値を読み込む
		 * @return					16bit整数値
		 */
		virtual KsInt16				readInt16();

		/**
		 * ファイルから符号なし16bit整数値を読み込む
		 * @return					符号なし16bit整数値
		 */
		virtual KsUInt16			readUInt16();

		/**
		 * ファイルから8bit整数値を読み込む
		 * @return					8bit整数値
		 */
		virtual KsInt8				readInt8();

		/**
		 * ファイルから符号なし8bit整数値を読み込む
		 * @return					符号なし8bit整数値
		 */
		virtual KsUInt8				readUInt8();

		/**
		 * ファイルから一文字を読み込む
		 * @return					一文字分の値
		 */
		virtual KsChar				readChar();

		/**
		 * ファイルから符号なし8bit整数値を読み込む
		 * @return					整数値
		 */
		virtual KsInt32				readByte();

		/**
		 * ファイルから文字列を読み込む
		 * @return					文字列
		 */
		virtual KsString			readString();

		/**
		 * エンコードされた整数分を読み込む
		 * @return					可変長サイズのエンコードされた 32-bit 符号無し整数
		 */
		virtual KsUInt32			readEncodedU32();

		/**
		 * バッファに指定バイト数分読み込む
		 * @param	pBuffer			(OUT)読み込むためのバッファ
		 * @param	count			読み込むバイト数
		 * @return					読み込んだバイト数
		 */
		virtual KsSize				read( void *pBuffer, KsInt32 count );

		/**
		 * ファイルに値を書き込む
		 * @param	val				書き込む値
		 * @return					書き込んだバイト数
		 */
		virtual KsSize				writeReal( KsReal val );

		/**
		 * ファイルに値を書き込む
		 * @param	val				書き込む値
		 * @return					書き込んだバイト数
		 */
		virtual KsSize				writeInt32( KsInt32 val );

		/**
		 * ファイルに値を書き込む
		 * @param	val				書き込む値
		 * @return					書き込んだバイト数
		 */
		virtual KsSize				writeUInt32( KsUInt32 val );

		/**
		 * ファイルに値を書き込む
		 * @param	val				書き込む値
		 * @return					書き込んだバイト数
		 */
		virtual KsSize				writeInt16( KsInt16 val );

		/**
		 * ファイルに値を書き込む
		 * @param	val				書き込む値
		 * @return					書き込んだバイト数
		 */
		virtual KsSize				writeUInt16( KsUInt16 val );

		/**
		 * ファイルに値を書き込む
		 * @param	val				書き込む値
		 * @return					書き込んだバイト数
		 */
		virtual KsSize				writeInt8( KsInt8 val );

		/**
		 * ファイルに値を書き込む
		 * @param	val				書き込む値
		 * @return					書き込んだバイト数
		 */
		virtual KsSize				writeUInt8( KsUInt8 val );

		/**
		 * ファイルに値を書き込む
		 * @param	val				書き込む値
		 * @return					書き込んだバイト数
		 */
		virtual KsSize				writeChar( KsChar val );

		/**
		 * ファイルに値を書き込む
		 * @param	val				書き込む値
		 * @return					書き込んだバイト数
		 */
		virtual KsSize				writeByte( KsInt32 val );

		/**
		 * バッファからファイルに値を書き込む
		 * @param	pBuffer			書き込むバッファ
		 * @param	count			書き込むバイト数
		 * @return					書き込んだバイト数
		 */
		virtual KsSize				write( const void *pBuffer, KsInt32 count );

	protected:

		/**
		 * フラグからファイルモードを取得する
		 * @param	flags			ファイルを開くモードフラグ
		 * @return					ファイルを開く文字列のモード
		 */
		KsString					getFileMode( KsUInt32 flags );
};

ksNS_KS_END

#endif /* __KSFILE_H__ */


