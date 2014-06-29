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
 * @file	KsMemoryFixedBlock.h
 * @brief	固定メモリ管理（フリーリスト）
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/
#ifndef __KSMEMORYFIXEDBLOCK_H__
#define __KSMEMORYFIXEDBLOCK_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsMemoryFixedUnit.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class		KsMemoryFixedBlock
 * @brief		固定メモリーマネージャ(4バイト以上でないとダメ)
 * @since		2005/03/04
 * @author		A567W
 */
/************************************************************************************************/
class ksENGINE_API KsMemoryFixedBlock
{
	public:
		/**
		 * コンストラクタ
		 */
										KsMemoryFixedBlock();

		/**
		 * コンストラクタ(ブロックリストを生成する)
		 * @param		elementSize		要素のサイズ
		 * @param		numElement		要素数
		 * @param		numBlock		ブロック数
		 */
										KsMemoryFixedBlock( KsUInt32 elementSize, KsUInt32 numElement, KsUInt32 numBlock=0 );

		/**
		 * デストラクタ
		 */
										~KsMemoryFixedBlock();

		/**
		 * ブロックリストを生成する
		 * @param		elementSize		要素のサイズ
		 * @param		numElement		要素数
		 * @param		numBlock		ブロック数
		 */
		void							create( KsUInt32 elementSize, KsUInt32 numElement, KsUInt32 numBlock=0 );

		/**
		 * 要素ををクリアする
		 */
		void							clear();
	
		/**
		 * 破棄する
		 */
		void							destroy();
	
		/**
		 * メモリーブロックを生成する
		 */
		void							createMemoryBlock();
	
		/**
		 * メモリーをブロックから確保する
		 */
		void*							alloc();
	
		/**
		 * このリストで確保されたメモリーかのチェック
		 * @retval		ksTRUE			これで確保されたメモリ
		 * @retval		ksFALSE			これ以外で確保されたメモリ
		 */
		KsBool							isBlockListMemory( void* ptr );

	public:
		KsMemoryFixedUnit*				m_pTopBlock;		/**< 先頭ブロックのポインタ		*/
		KsMemoryFixedUnit*				m_pCurrentBlock;	/**< 現在のブロックのポインタ	*/
		KsUInt32						m_elementSize;		/**< 要素のサイズ				*/
		KsUInt32						m_blockSize;		/**< ブロックサイズ			*/
};

ksNS_KS_END


#endif		/* __KSMEMORYFIXEDBLOCK_H__ */

