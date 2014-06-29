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
 * @file	KsStack.h
 * @brief	スタック
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/
#ifndef __KSSTACK_H__
#define __KSSTACK_H__

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
 * @class		KsStack
 * @brief		スタック
 * @author		A567W
 * @date		2004/03/30
 * @version		1.0.0
 */
/************************************************************************************************/
template < typename T, KsUInt32 max > class KsStack
{
	public:
		typedef T						valueType;

	public:
		/**
		 * コンストラクタ
		 */
										KsStack() : m_size( 0 ) {}
	
		/**
		 * デストラクタ
		 */
										~KsStack() {}

		/**
 		 * スタックが空かどうかをチェックする
		 * @retval		ksTRUE			空です
		 * @retval		ksFALSE			空じゃない
		 */
		KsBool							empty() const { return ( m_size == 0 ); }

		/**
		 * データを格納します
		 * @param		T				格納するデータ
		 */
		void							push( const T& data )
		{
			if( m_size < max ){
				m_buffer[ m_size++ ] = data;
			}
		}
	
		/**
		 * データを取り出します
		 * @return						一つ前格納したデータ
		 */
		T&								pop()
		{
			if( m_size > 0 ){
				--m_size;
				return m_buffer[ m_size ];
			}
			return m_buffer[ 0 ];
		}

		/**
		 * データを取り出します
		 * @return						一つ前格納したデータ
		 */
		const T&						pop() const 
		{
			if( m_size > 0 ){
				--m_size;
				return m_buffer[ m_size ];
			}
			return m_buffer[ 0 ];
		}

		/**
		 * データを取り出します
		 * @return						一つ前格納したデータ
		 */
		T&								top() 
		{
			if( m_size ){
				m_buffer[ m_size-1 ];
			}
			return m_buffer[ 0 ];
		}

		/**
		 * データを取り出します
		 * @return						一つ前格納したデータ
		 */
		const T&						top() const
		{
			if( m_size ){
				m_buffer[ m_size-1 ];
			}
			return m_buffer[ 0 ];
		}

		/**
		 * 過去のデータを取得します。
		 * @param  		num				過去の何番目かのデータ番号
		 * @return						過去のデータ
		 */
		T&								getData( KsUInt32 num )
		{
			KsUInt32	index = m_size - num -1;
		
			if( index ){
				return m_buffer[ index ];
			}
			return m_buffer[ 0 ];
		}

		/**
		 * 過去のデータを取得します。
		 * @param  		num				過去の何番目かのデータ番号
		 * @return						過去のデータ
		 */
		const T&						getData( KsUInt32 num ) const 
		{
			KsUInt32	index = m_size - num -1;
		
			if( index ){
				return m_buffer[ index ];
			}
			return m_buffer[ 0 ];
		}
	
		/**
		 * 指定インデックスののデータを取得します。
		 * @param		index 			過去の何番目かのデータ番号
		 * @return 						過去のデータ
		 */
		T&								getDataIndex( KsUInt32 index )
		{
			if( index < max ){
				return m_buffer[ index ];
			}
			return m_buffer[ 0 ];
		}

		/**
		 * 指定インデックスののデータを取得します。
		 * @param		index 			過去の何番目かのデータ番号
		 * @return 						過去のデータ
		 */
		const T&						getDataIndex( KsUInt32 index ) const 
		{
			if( index < max ){
				return m_buffer[ index ];
			}
			return m_buffer[ 0 ];
		}
	
		/**
		 * 値を変える
		 * @param		index			書き換えるデータのインデックス
		 * @param		data			データ
		 */
		void							swap( KsUInt32 index, const T& data )
		{
			if( index < max ){
				m_buffer[ index ] = data;
			}
		}
	
		/**
		 * クリアーする
		 */
		void							clear() { m_pos = 0; m_size = 0; }

		/**
		 * 現在格納されているデータの数を取得
		 * @return						格納されているデータの数
		 */
		KsInt32							size()	const { return m_size;	}
	
		/**
		 * 格納できるデータの数を取得
		 * @return						格納できるデータの数
		 */
		KsInt32							getMax()	const { return max;	}

	private:
		T								m_buffer[ max ];	/**< バッファ					*/
		KsInt32							m_size;				/**< 格納されているデータの数	*/
};

ksNS_KS_END

#endif	/* __KSSTACK_H__ */
