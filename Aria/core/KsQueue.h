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
 * @file	KsQueue.h
 * @brief	キュー
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/
#ifndef __KSQUEUE_H__
#define __KSQUEUE_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                           */
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
 * @class		KsQueue
 * @brief		キュー
 * @author		A567W
 * @date		2004/03/30
 * @version		1.0.0
 */
/************************************************************************************************/
template < typename T, KsInt32 max > class KsQueue
{
	public:
		typedef T					valueType;

	public:
		/**
		 * コンストラクタ
		 */
									KsQueue() : m_top( 0 ), m_end( 0 ), m_size( 0 ) {}
	
		/**
		 * デストラクタ
		 */
									~KsQueue() {}

		/**
 		 * スタックが空かどうかをチェックする
		 * @retval		ksTRUE			空です
		 * @retval		ksFALSE			空じゃない
		 */
		KsBool						empty() const { return ( m_size == 0 ); }

		/**
		 * データを格納します
		 * @param		T				格納するデータ
		 */
		void						push( const T& data )
		{
			if( m_size < max ){
				m_data[ m_end ] = data;
				if( ++m_end > max-1 ){
					m_end = 0;
				}
				m_size++;
			}	
		}
	
		/**
		 * データを取り出します
		 * @return						一つ前格納したデータ
		 */
		T&							pop() 
		{
			if( m_size > 0 ){
				KsInt32		top = m_top;
				if( ++m_top > max-1 ){
					m_top = 0;
				}
				m_size--;
				return m_data[ top ];
			}
			return m_data[ 0 ];
		}

		/**
		 * データを取り出します
		 * @return						一つ前格納したデータ
		 */
		const T&					pop() const 
		{
			if( m_size > 0 ){
				KsInt32		top = m_top;
				if( ++m_top > max-1 ){
					m_top = 0;
				}
				m_size--;
				return m_data[ top ];
			}
			return m_data[ 0 ];
		}

		/**
		 * データを取り出します
		 * @return						一つ前格納したデータ
		 */
		T&							top() { return m_data[ m_top ]; }

		/**
		 * データを取り出します
		 * @return						一つ前格納したデータ
		 */
		const T&					top() const { return m_data[ m_top ]; }

		/**
		 * データを取り出します
		 * @return						一つ前格納したデータ
		 */
		T&							end()
		{
			if( m_end ){
				return m_data[ m_end-1 ];
			}
			return m_data[ 0 ];
		}

		/**
		 * データを取り出します
		 * @return						一つ前格納したデータ
		 */
		const T&					end() const
		{
			if( m_end ){
				return m_data[ m_end-1 ];
			}
			return m_data[ 0 ];
		}

		/**
		 * 指定データを取得します。
		 * @param  		num				先頭からのデータ番号
		 * @return						データ
		 */
		T&							getData( KsInt32 num ) 
		{
			if( num < max ){
				KsInt32	index = m_top + num;
				if( index > max-1 ){
					index = 0;
				}
				return m_data[ index ];
			}
			return m_data[ 0 ];
		}

		/**
		 * 指定データを取得します。
		 * @param  		num				先頭からのデータ番号
		 * @return						データ
		 */
		const T&					getData( KsInt32 num ) const 
		{
			if( num < max ){
				KsInt32	index = m_top + num;
				if( index > max-1 ){
					index = 0;
				}
				return m_data[ index ];
			}
			return m_data[ 0 ];
		}
	
		/**
		 * 値を変える
		 * @param		index			書き換えるデータのインデックス
		 * @param		data			データ
		 */
		void						swap( KsInt32 index, const T& data )
		{
			m_data[ index ] = data;
		}

		/**
		 * クリアーする
		 */
		void						clear() { m_top = 0; m_end = 0; m_size = 0; }

		/**
		 * 現在格納されているデータの数を取得
		 * @return						格納されているデータの数
		 */
		KsInt32						size()	const { return m_size;	}
	
		/**
		 * 格納できるデータの数を取得
		 * @return						格納できるデータの数
		 */
		KsInt32						getMax()	const { return max;	}

	private:
		T							m_data[ max ];		/**< データ						*/
		KsInt32						m_top;				/**< キュー内データの先頭位置		*/
		KsInt32						m_end;				/**< キュー内データの最後位置		*/
		KsInt32						m_size;				/**< 格納されているデータの数		*/
};


ksNS_KS_END

#endif	/* __KSQUEUE_H__ */


