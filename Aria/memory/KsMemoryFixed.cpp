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
 * @brief	�Œ胁�����Ǘ��i�t���[���X�g�j
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                            */
/*==============================================================================================*/
#include "KsMemoryFixed.h"

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
KsMemoryFixed::KsMemoryFixed()
 : m_pFreeList( 0 )
{
}

/************************************************************************************************/
/*
 * �R���X�g���N�^
 * @param		elementSize		�v�f�̃T�C�Y
 * @param		numElement		�v�f��
 * @param		numBlock		�u���b�N��
 */
/************************************************************************************************/
KsMemoryFixed::KsMemoryFixed( KsUInt32 elementSize, KsUInt32 numElement, KsUInt32 numBlock )
 : m_memoryBlockList( elementSize, numElement, numBlock )
 , m_pFreeList( 0 )
{
}

/************************************************************************************************/
/*
 * �N���A�[����
 */
/************************************************************************************************/
void KsMemoryFixed::clear()
{
	m_pFreeList = NULL;
	m_memoryBlockList.clear();
}

/************************************************************************************************/
/*
 * �j������
 */
/************************************************************************************************/
void KsMemoryFixed::destroy()
{
	m_pFreeList = NULL;
	m_memoryBlockList.destroy();
}

/************************************************************************************************/
/*
 * �������[�m��
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
 * �������[�J�� 
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
 * ��������
 * @param		elementSize		�v�f�̃T�C�Y
 * @param		numElement		�v�f��
 * @param		numBlock		�u���b�N��
 */
/************************************************************************************************/
void KsMemoryFixed::create( KsUInt32 elementSize, KsUInt32 numElement, KsUInt32 numBlock )
{
	m_memoryBlockList.create( elementSize, numElement, numBlock );
}
/************************************************************************************************/
/*
 * �f�X�g���N�^
 */
/************************************************************************************************/
KsMemoryFixed::~KsMemoryFixed()
{
	destroy();
}

/************************************************************************************************/
/*
 * ���̃��X�g�Ŋm�ۂ��ꂽ�������[���̃`�F�b�N
 * @retval		ksTRUE			����Ŋm�ۂ��ꂽ������
 * @retval		ksFALSE			����ȊO�Ŋm�ۂ��ꂽ������
 */
/************************************************************************************************/
KsBool KsMemoryFixed::isMemory( void* ptr )
{
	return m_memoryBlockList.isBlockListMemory( ptr );
}

ksNS_KS_END
