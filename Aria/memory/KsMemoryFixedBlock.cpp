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
 * @file	KsMemoryFixedBlock.cpp
 * @brief	�Œ胁�����Ǘ��i�t���[���X�g�j
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                            */
/*==============================================================================================*/
#include "KsMemoryFixedBlock.h"

/*==============================================================================================*/
/*                                     << ��` >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << �錾 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/*
 * �R���X�g���N�^
 */
/************************************************************************************************/
KsMemoryFixedBlock::KsMemoryFixedBlock()
	: m_pTopBlock( 0 )
	, m_pCurrentBlock( 0 )
	, m_elementSize( 0 )
	, m_blockSize( 0 )
{
}

/************************************************************************************************/
/*
 * �R���X�g���N�^(�u���b�N���X�g�𐶐�����)
 * @param		elementSize		�v�f�̃T�C�Y
 * @param		numElement		�v�f��
 * @param		numBlock		�u���b�N��
 */
/************************************************************************************************/
KsMemoryFixedBlock::KsMemoryFixedBlock( KsUInt32 elementSize, KsUInt32 numElement, KsUInt32 numBlock )
{
	m_elementSize   = elementSize;
	m_blockSize     = elementSize * numElement;
	m_pTopBlock     = NULL;
	m_pCurrentBlock = NULL;

	for( KsUInt32 i=0; i<numBlock; i++ )
	{
		KsChar*			pMemory = new KsChar[ sizeof(KsMemoryFixedUnit) + m_blockSize ];
		KsMemoryFixedUnit*	pBlock  = (KsMemoryFixedUnit*)pMemory;

		/* �������[�u���b�N��� */
		pBlock->m_pStartAddr    = pMemory + sizeof( KsMemoryFixedUnit );
		pBlock->m_pEndAddr      = (void*)((KsUInt32)pBlock->m_pStartAddr + m_blockSize );
		pBlock->m_pCurrentAddr  = pBlock->m_pStartAddr;

		pBlock->m_pPrev = m_pTopBlock;
		pBlock->m_pNext = NULL;

		if( m_pCurrentBlock ){
			m_pCurrentBlock->m_pNext = pBlock;
		}

		if( !m_pTopBlock ){
			m_pTopBlock = pBlock;
		}

		m_pCurrentBlock = pBlock;
	}
}
/************************************************************************************************/
/*
 * �u���b�N���X�g�𐶐�����
 * @param		elementSize		�v�f�̃T�C�Y
 * @param		numElement		�v�f��
 * @param		numBlock		�u���b�N��
 */
/************************************************************************************************/
void KsMemoryFixedBlock::create( KsUInt32 elementSize, KsUInt32 numElement, KsUInt32 numBlock )
{
	clear();

	m_elementSize   = elementSize;
	m_blockSize     = elementSize * numElement;

	for( KsUInt32 i=0; i<numBlock; i++ )
	{
		KsChar*			pMemory = new KsChar[ sizeof(KsMemoryFixedUnit) + m_blockSize ];
		KsMemoryFixedUnit*	pBlock  = (KsMemoryFixedUnit*)pMemory;

		/* �������[�u���b�N��� */
		pBlock->m_pStartAddr    = pMemory + sizeof( KsMemoryFixedUnit );
		pBlock->m_pEndAddr      = (void*)((KsUInt32)pBlock->m_pStartAddr + m_blockSize );
		pBlock->m_pCurrentAddr  = pBlock->m_pStartAddr;

		pBlock->m_pPrev = m_pTopBlock;
		pBlock->m_pNext = NULL;

		if( m_pCurrentBlock ){
			m_pCurrentBlock->m_pNext = pBlock;
		}

		if( !m_pTopBlock ){
			m_pTopBlock = pBlock;
		}

		m_pCurrentBlock = pBlock;
	}
}

/************************************************************************************************/
/*
 * �f�X�g���N�^
 */
/************************************************************************************************/
KsMemoryFixedBlock::~KsMemoryFixedBlock()
{
	clear();
}
/************************************************************************************************/
/*
 * �j������
 */
/************************************************************************************************/
void KsMemoryFixedBlock::destroy()
{
	while( m_pTopBlock )
	{
		KsChar*		pPtr = (KsChar*)m_pTopBlock;

		m_pTopBlock = m_pTopBlock->m_pNext;

		delete [] pPtr;
	}

	m_pTopBlock     = NULL;
	m_pCurrentBlock = NULL;
}

/************************************************************************************************/
/*
 * �������[�u���b�N�𐶐�����
 */
/************************************************************************************************/
void KsMemoryFixedBlock::createMemoryBlock()
{
	if( m_pCurrentBlock && m_pCurrentBlock->m_pNext )
	{
		/* ���łɃu���b�N�̃��X�g������ꍇ */
		m_pCurrentBlock->m_pNext->m_pCurrentAddr = m_pCurrentBlock->m_pNext->m_pStartAddr;    
		m_pCurrentBlock                          = m_pCurrentBlock->m_pNext;
	}
	else
	{
		KsChar*			pMemory = new KsChar[ sizeof(KsMemoryFixedUnit) + m_blockSize ];
		KsMemoryFixedUnit*	pBlock  = (KsMemoryFixedUnit*)pMemory;

		/* �������[�u���b�N��� */
		pBlock->m_pStartAddr    = pMemory + sizeof( KsMemoryFixedUnit );
		pBlock->m_pEndAddr      = (void*)((KsUInt32)pBlock->m_pStartAddr + m_blockSize );
		pBlock->m_pCurrentAddr  = pBlock->m_pStartAddr;

		pBlock->m_pPrev = m_pTopBlock;
		pBlock->m_pNext = NULL;

		if( m_pCurrentBlock ){
			m_pCurrentBlock->m_pNext = pBlock;
		}

		if( !m_pTopBlock ){
			m_pTopBlock = pBlock;
		}

		m_pCurrentBlock = pBlock;
	}
}

/************************************************************************************************/
/*
 * �������[���u���b�N����m�ۂ���
 */
/************************************************************************************************/
void* KsMemoryFixedBlock::alloc()
{
	void*		pAddress;

	if( !m_pTopBlock ){
		createMemoryBlock();
	}

	if( ( (KsUInt32)m_pCurrentBlock->m_pCurrentAddr + m_elementSize ) > (KsUInt32)m_pCurrentBlock->m_pEndAddr ){
		/* �m�ۂł��Ȃ��̂ŐV�����u���b�N����� */
		createMemoryBlock();
	}

	pAddress = m_pCurrentBlock->m_pCurrentAddr;
	m_pCurrentBlock->m_pCurrentAddr = (void*)( (KsUInt32)m_pCurrentBlock->m_pCurrentAddr + m_elementSize );

	return pAddress;
}
/************************************************************************************************/
/*
 * �v�f�����N���A����
 */
/************************************************************************************************/
void KsMemoryFixedBlock::clear()
{
	if( m_pTopBlock ){
		m_pTopBlock->m_pCurrentAddr  = m_pTopBlock->m_pStartAddr;
	}

	m_pCurrentBlock = m_pTopBlock;
}

/************************************************************************************************/
/*
 * ���̃��X�g�Ŋm�ۂ��ꂽ�������[���̃`�F�b�N
 * @retval		ksTRUE			����Ŋm�ۂ��ꂽ������
 * @retval		ksFALSE			����ȊO�Ŋm�ۂ��ꂽ������
 */
/************************************************************************************************/
KsBool KsMemoryFixedBlock::isBlockListMemory( void* ptr )
{
	KsMemoryFixedUnit*	pTemp = m_pTopBlock;
	KsUInt32		addr  = (KsUInt32)ptr;

	while( pTemp )
	{
		KsUInt32	top = (KsUInt32)pTemp->m_pStartAddr;
		KsUInt32	end = top + m_blockSize;

		if( top<= addr && addr < end ){
			return ksTRUE;
		}

		pTemp = pTemp->m_pNext;
	}

	return ksFALSE;
}


ksNS_KS_END

