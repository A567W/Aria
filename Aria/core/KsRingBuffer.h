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
 * @file	KsRingBuffer.h
 * @brief	リングバッファ
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/
#ifndef __KSRINGBUFFER_H__
#define __KSRINGBUFFER_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                           */
/*==============================================================================================*/
#include "KsCoreCommon.h"

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
* @class		KsRingBuffer
* @brief		リングバッファのクラス
* @since		2008/02/06
* @author		A567W
*/
/************************************************************************************************/
template < typename T, KsInt32 order > class KsRingBuffer
{
	public:
		/**
		 * データを格納します
		 * @param  T		格納するデータ
		 */
		void						push( T data )
		{
			m_buffer[ m_pos ] = data;
			if( ++m_pos > order-1 )
			{
				m_pos = 0;
			}
		};
	
		/**
		 * データを取り出します
		 * @return 一つ前格納したデータ
		 */
		T							pop()
		{
			if( --m_pos < 0 )
			{
				m_pos = order-1;
			}		
			return m_buffer[ m_pos ];
		};

		/**
		 * 指定番号に強制的にデータを格納する
		 * @param  num		データを入れる指定番号
		 * @retval ksTRUE	成功
		 * @retval ksFALSE	失敗
		 */
		KsBool						insert( KsInt32 num, T data )
		{
			if( num < order )
			{
				m_buffer[ num ] = data;
				return ksTRUE;
			}
			return ksFALSE;
		};
	
		/**
		 * 過去のデータを取得します。
		 * @param  num 過去の何番目かのデータ番号
		 * @return 過去のデータ
		 */
		T							getData( KsInt32 num )
		{
			if( num < order )
			{
				KsInt32 index = m_pos - num -1;
				if( index < 0 )
				{
					index += order;
				}
				return m_buffer[ m_pos ];
			}
			return m_buffer[ 0 ];
		};
	
		/**
		 * コンストラクタ
		 */
									KsRingBuffer() : m_pos( 0 ) {}
	
		/**
		 * デストラクタ
		 */
									~KsRingBuffer() {}
	
		/**
		 * 現在のデータ挿入位置を取得する
		 * @return					挿入位置を返す
		 */
		KsInt32						getPos() { return m_pos; }

	private:
		T							m_buffer[ order ];		/**< バッファ		*/
		KsInt32						m_pos;					/**< データ位置	*/
};

ksNS_KS_END

#endif		/* __KSRINGBUFFER_H__ */




