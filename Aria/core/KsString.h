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
 * @file	KsString.h
 * @brief	文字列操作
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/
#ifndef __KSSTRING_H__
#define __KSSTRING_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsCoreCommon.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class		KsString
 * @brief		文字列操作
 * @author		A567W
 * @date		2004/03/30
 */
/************************************************************************************************/
class ksENGINE_API KsString
{
	public:
		/**
		 * コンストラクタ
		 */
									KsString();

		/**
		 * コンストラクタ
		 * @param		string		文字列クラスの参照
		 */
									KsString( const KsString& string );

		/**
		 * コンストラクタ
		 * @param		pString		文字列のポインタ
		 */
									KsString( const KsSChar* pString );

		/**
		 * コンストラクタ
		 * @param		pString		文字列のポインタ
		 */
									KsString( const KsWChar* pString );

		/**
		 * デストラクタ
		 */
									~KsString();

		/**
		 * 文字列の長さを取得する
		 * @return					文字列の長さ
		 */
		KsUInt32					length() const { return m_length; }

		/**
		 * 文字列のバッファサイズを取得する
		 * @return					バッファサイズ
		 */
		KsUInt32					size() const { return m_size; }

		/**
		 * 文字列のバッファ取得
		 * @return					文字列の先頭ポインタ
		 */
		const KsChar*				c_str() const { return m_pString; }

		/**
		 * 空かどうかをチェックする
		 * @retval		ksTRUE		空です
		 * @retval		ksFALSE		空でない
		 */
		KsBool						empty() const { return ( NULL == m_pString ); }

		/**
		 * 指定範囲の文字を削除する
		 * @param		top			消す文字列の先頭
		 * @param		num			消す文字列の数
		 */
		void						erase( KsUInt32 top, KsUInt32 num );

		/**
		 * 文字列をクリア
		 */
		void						clear();

		/**
		 * 指定インデックスの文字を取得する( operator )
		 * @param	index			取得するインデックス
		 * @return					文字
		 */
		KsChar						operator []( KsUInt32 index )		{ return m_pString[ index ]; }
	
		/**
		 * 指定インデックスの文字を取得する( operator )
		 * @param	index			取得するインデックス
		 * @return					文字
		 */
		const KsChar				operator []( KsUInt32 index ) const { return m_pString[ index ]; }

		KsString&					operator=(const KsString& string );
		KsString&					operator=(const KsSChar* string );
		KsString&					operator=(const KsWChar* string );
		KsString&					operator=(const KsChar c );

		KsString&					operator+=(const KsString& string );
		KsString&					operator+=(const KsChar* string );
		KsString&					operator+=(const KsChar c );

		KsString					operator+(const KsString& string );
		KsString					operator+(const KsChar* pString );
		KsString					operator+(const KsChar c );

		KsBool						operator==( const KsChar* pString ) const { return ( 0 == ks_strcmp( m_pString, pString ) ); }
		KsBool						operator==( const KsString& string ) const { return ( 0 == ks_strcmp( m_pString, string.c_str() ) ); }
	
		KsBool						operator!=( const KsChar* pString ) const { return ks_strcmp( m_pString, pString ); }
		KsBool						operator!=( const KsString& string ) const { return ks_strcmp( m_pString, string.c_str() ); }

	private:
		KsChar*						m_pString;		/**< 文字列					*/
		KsUInt32					m_length;		/**< 文字列の長さ				*/
		KsUInt32					m_size;			/**< 文字列バッファのサイズ		*/
};

/************************************************************************************************/
/*
 * ワイド文字列(WCHAR*)をマルチバイト文字列(char*)に変換
 * @param	wStrW		変換前文字列
 * @param	pOut		変換文字列格納バッファ
 */
/************************************************************************************************/
ksENGINE_API KsUInt32 ks_wcstombs( const KsWChar* wStrW, KsSChar* pOut, KsUInt32 len );

/************************************************************************************************/
/*
 * マルチバイト文字列(char*)をワイド文字列(WCHAR*)に変換
 * @param	wStrW		変換前文字列
 * @param	pOut		変換文字列格納バッファ
 */
/************************************************************************************************/
ksENGINE_API KsUInt32 ks_mbstowcs( const KsSChar* sStr, KsWChar* pOut, KsUInt32 len );

ksNS_KS_END

#endif		/* __KSSTRING_H__ */

