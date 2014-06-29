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
 * @file	KsArray.h
 * @brief	可変長配列
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/
#ifndef __KSARRAY_H__
#define __KSARRAY_H__

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
* @class		KsArray
* @brief		可変長配列
* @since		2008/02/06
* @author		A567W
*/
/************************************************************************************************/
template <typename T> class KsArray
{
	public:
		/**
		 * コンストラクタ
		 */
									KsArray() : m_data( 0 ), m_allocSize( 0 ), m_size( 0 ) {}
	
		/**
		 * コンストラクタ
		 * @param	size			確保するサイズ
		 */
									KsArray( KsUInt32 size ) : m_data( 0 ), m_allocSize( 0 ), m_size( 0 ){ this->arrayRalloc( size ); }
				
		/**
		 * デストラクタ
		 */
									~KsArray(){ if( m_data ){ delete [] m_data; }	}

		/**
		 * 代入( operator )
		 * @param	other			代入する配列
		 */
		void						operator = ( const KsArray< T >& other )
		{
			if( m_data ){ delete [] m_data; }

			// サイズチェック
			if( other.m_allocSize == 0 )	{ m_data = 0; }
			else							{ m_data = new T[ other.m_allocSize ]; }

			// カウント
			m_size = other.m_size;
		
			// 確保サイズ
			m_allocSize = other.m_allocSize;

			for( KsUInt32 i=0; i<other.m_size; ++i ){ m_data[ i ] = other.m_data[ i ]; }
		}

		/**
		 * 配列内の要素を取得する( operator )
		 * @param	index			取得するインデックス
		 */
		T&							operator []( KsUInt32 index )		{ return m_data[ index ]; }
	
		/**
		 * 配列内の要素を取得する( operator )
		 * @param	index			取得するインデックス
		 */
		const T&					operator []( KsUInt32 index ) const { return m_data[ index ]; }

		/**
		 * 新しくメモリーを確保しなおす
		 * @param	size			新しく確保するサイズ
		 */
		void						arrayRalloc( KsUInt32 size )
		{
			T*	temp = m_data;
		
			m_data		= new T[ size ];
			m_allocSize = size;
		
			KsUInt32 end = m_size < size ? m_size : size;

			if( m_allocSize < m_size ){ m_size = m_allocSize; }

			if( temp )
			{
				for( KsUInt32 i=0; i<end; ++i ){
					m_data[ i ] = temp[ i ];
				}

				delete [] temp;
			}
		}
	
		/**
		 * 配列に後ろから要素を追加する
		 * @param	data			追加する要素
		 */
		void						push_back( const T& data )
		{
			if( m_size + 1 > m_allocSize )
			{
				this->arrayRalloc( m_size * 2 + 1 ); 
			}

			m_data[ m_size++ ] = data;
		}
	
		/**
		 * 配列に後ろから要素を追加する
		 * @param	index			追加データのインデックス
		 * @param	data			追加する要素
		 */
		void						insert( KsUInt32 index, const T& data )
		{
			if( index + 1 > m_allocSize )
			{
				this->arrayRalloc( m_size * 2 + 1 ); 
			}

			if( m_size + 1 > m_allocSize )
			{
				this->arrayRalloc( m_size * 2 + 1 ); 
			}

			if( m_size > 0 )
			{
				// 指定インデックスのデータを消してデータを詰める
				for ( KsUInt32 i=m_size-1; i>=index; i-- )
				{
					m_data[ i+1 ] = m_data[ i ];	
				}
			}
			
			m_data[ index ] = data;

			//if( m_size >= index )
			//{
				++m_size;
			//}
			//else
			//{
				//m_size = index + 1;
			//}
		}

		/**
		 * 配列から削除する
		 * @param	index			消すデータのインデックス
		 */
		void						erase( KsUInt32 index )
		{
			// 指定インデックスのデータを消してデータを詰める
			for ( KsUInt32 i=index+1; i<m_size; ++i )
			{
				m_data[ i-1 ] = m_data[ i ];
			}

			--m_size;
		}

		/**
		 * 配列から削除する
		 * @param	index			消すデータのインデックス
		 * @param	count			指定インデックスから消す個数
		 */
		void						erase( KsUInt32 index, KsUInt32 count )
		{
			for( KsUInt32 i=(index + count); i<m_size; ++i ){
				m_data[ i-count ] = m_data[ i ];
			}

			m_size -= count;
		}
	
		/**
		 * リセットする
		 */
		void						reset()
		{
			m_size = 0;
		}

		/**
		 * 配列をクリアーする
		 */
		void						clear()
		{
			if( m_data ){ delete [] m_data; }
			m_data      = 0;
			m_allocSize = 0;
			m_size		= 0;
		}
	
		/**
		 * ポインタを取得する
		 * @return					配列のポインタ
		 */
		T*							pointer()				{ return m_data;			}
	
		/**
		 * 配列が空かどうかをチェックする
		 * @retval	ksTRUE			配列は空
		 * @retval	ksFALSE			空じゃない
		 */
		KsBool						empty()			const	{ return ( m_size == 0 );	}
	
		/**
		 * 確保するサイズ
		 * @return					確保されている配列の数
		 */
		KsUInt32					getAllocSize()	const	{ return m_allocSize;		}

		/**
		 * カウント数を取得する
		 * @return					使われている配列の数
		 */
		KsUInt32					size()			const	{ return m_size;			}

	private:
		T*							m_data;			/**< データを取得する			*/
		KsUInt32					m_allocSize;	/**< 確保サイズを取得する		*/
		KsUInt32					m_size;			/**< 配列の要素数を取得する		*/
};

ksNS_KS_END

#endif	/* __KSARRAY_H__ */

