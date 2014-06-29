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
 * @file	KsMemoryFixed.cpp
 * @brief	固定メモリ管理（フリーリスト）
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsMemoryFixed.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/*
 * コンストラクタ
 */
/************************************************************************************************/
KsMemoryFixed::KsMemoryFixed()
 : m_pFreeList( 0 )
{
}

/************************************************************************************************/
/*
 * コンストラクタ
 * @param		elementSize		要素のサイズ
 * @param		numElement		要素数
 * @param		numBlock		ブロック数
 */
/************************************************************************************************/
KsMemoryFixed::KsMemoryFixed( KsUInt32 elementSize, KsUInt32 numElement, KsUInt32 numBlock )
 : m_memoryBlockList( elementSize, numElement, numBlock )
 , m_pFreeList( 0 )
{
}

/************************************************************************************************/
/*
 * クリアーする
 */
/************************************************************************************************/
void KsMemoryFixed::clear()
{
	m_pFreeList = NULL;
	m_memoryBlockList.clear();
}

/************************************************************************************************/
/*
 * 破棄する
 */
/************************************************************************************************/
void KsMemoryFixed::destroy()
{
	m_pFreeList = NULL;
	m_memoryBlockList.destroy();
}

/************************************************************************************************/
/*
 * メモリー確保
 */
/************************************************************************************************/
void* KsMemoryFixed::KsAlloc()
{
	if( m_pFreeList ){
		KsFreeList*		pTemp = m_pFreeList;
		m_pFreeList = pTemp->m_pNext;
		return pTemp;
	}

	return m_memoryBlockList.alloc();
}

/************************************************************************************************/
/*
 * メモリー開放 
 */
/************************************************************************************************/
void KsMemoryFixed::KsFree( void* ptr )
{
	KsFreeList*		pList = (KsFreeList*)ptr;

	pList->m_pNext = m_pFreeList;
	m_pFreeList    = pList;
}

/************************************************************************************************/
/*
 * 生成する
 * @param		elementSize		要素のサイズ
 * @param		numElement		要素数
 * @param		numBlock		ブロック数
 */
/************************************************************************************************/
void KsMemoryFixed::create( KsUInt32 elementSize, KsUInt32 numElement, KsUInt32 numBlock )
{
	m_memoryBlockList.create( elementSize, numElement, numBlock );
}
/************************************************************************************************/
/*
 * デストラクタ
 */
/************************************************************************************************/
KsMemoryFixed::~KsMemoryFixed()
{
	destroy();
}

/************************************************************************************************/
/*
 * このリストで確保されたメモリーかのチェック
 * @retval		ksTRUE			これで確保されたメモリ
 * @retval		ksFALSE			これ以外で確保されたメモリ
 */
/************************************************************************************************/
KsBool KsMemoryFixed::isMemory( void* ptr )
{
	return m_memoryBlockList.isBlockListMemory( ptr );
}

ksNS_KS_END
