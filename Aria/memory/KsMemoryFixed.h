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
 * @file	KsMemoryFixed.h
 * @brief	固定メモリ管理（フリーリスト）
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/
#ifndef __KSMEMORYFIXED_H__
#define __KSMEMORYFIXED_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsMemoryFixedBlock.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class		KsMemoryFixed
 * @brief		固定メモリーマネージャ(4バイト以上でないとダメ)
 * @since		2005/03/04
 * @author		A567W
 */
/************************************************************************************************/
class ksENGINE_API KsMemoryFixed
{
	private:
		/**
		 * フリーリスト
		 */
		class KsFreeList
		{
			public:
				KsFreeList*				m_pNext;	/**< リストのポインタ		*/
		};

	public:
		/**
		 * コンストラクタ
		 */
										KsMemoryFixed();

		/**
		 * コンストラクタ
		 * @param		elementSize		要素のサイズ
		 * @param		numElement		要素数
		 * @param		numBlock		ブロック数
		 */
										KsMemoryFixed( KsUInt32 elementSize, KsUInt32 numElement, KsUInt32 numBlock=0 );

		/**
		 * デストラクタ
		 */
										~KsMemoryFixed();

		/**
		 * 生成する
		 * @param		elementSize		要素のサイズ
		 * @param		numElement		要素数
		 * @param		numBlock		ブロック数
		 */
		void							create( KsUInt32 elementSize, KsUInt32 numElement, KsUInt32 numBlock );

		/**
		 * クリアーする
		 */
		void							clear();
	
		/**
		 * 破棄する
		 */
		void							destroy();

		/**
		 * メモリー確保
		 * @return						確保したメモリー
		 */
		void*							KsAlloc();

		/**
		 * メモリー開放 
		 * @param		ptr				ポインタ
		 */
		void							KsFree( void* ptr );

		/**
		 * このリストで確保されたメモリーかのチェック
		 * @retval		ksTRUE			これで確保されたメモリ
		 * @retval		ksFALSE			これ以外で確保されたメモリ
		 */
		KsBool							isMemory( void* ptr );

	private:
		KsMemoryFixedBlock				m_memoryBlockList;		/**< メモリーブロックリスト		*/
		KsFreeList*						m_pFreeList;			/**< フリーリストの先頭		*/
};

ksNS_KS_END

#endif		/* __KSMEMORYFIXED_H__ */

