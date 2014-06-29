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
 * @file	KsTaskManager.cpp
 * @brief	�^�X�N�Ǘ�
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
/************************************************************************************************/

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                            */
/*==============================================================================================*/
#include "KsTaskManager.h"

/*==============================================================================================*/
/*                                     << ��` >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << �錾 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

template<> KsTaskManager* KsSingleton< KsTaskManager >::m_pInstance = 0;

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
KsTaskManager& KsTaskManager::getInstance()
{  
	return (*m_pInstance);  
}
/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
KsTaskManager* KsTaskManager::getInstancePtr()
{
	return m_pInstance;
}

/************************************************************************************************/
/*
 * �R���X�g���N�^
 * @param		numUpdateList		�X�V���X�g��
 * @param		numDrawList			�`�惊�X�g��
 */
/************************************************************************************************/
KsTaskManager::KsTaskManager( KsUInt32 numUpdateList, KsUInt32 numDrawList )
{
}

/************************************************************************************************/
/*
 * �f�X�g���N�^
 */
/************************************************************************************************/
KsTaskManager::~KsTaskManager()
{
}

#if 0
/************************************************************************************************/
/*
 * 
 */
/************************************************************************************************/
void KsTaskManager::addTask( KsTask* pTask )
{
	addUpdate( pTask );
	addDraw( pTask );
}

/************************************************************************************************/
/*
 * 
 */
/************************************************************************************************/
void KsTaskManager::addUpdate( KsUpdate* pUpdate )
{
	const KsUInt32 order = pUpdate->getUpdateOrder();

	m_pUpdates[ order ].add( pUpdate );
}

/************************************************************************************************/
/*
 * 
 */
/************************************************************************************************/
void KsTaskManager::addDraw( KsDraw* pDraw )
{
	const KsUInt32 order = pDraw->getDrawOrder();

	m_pDraws[ order ].add( pDraw );
}

/************************************************************************************************/
/*
 * 
 */
/************************************************************************************************/
void KsTaskManager::removeTask( KsTask* pTask )
{
	removeUpdate( pTask );
	removeDraw( pTask );
}

/************************************************************************************************/
/*
 * 
 */
/************************************************************************************************/
void KsTaskManager::removeUpdate( KsUpdate* pUpdate )
{
	const KsUInt32 order = pUpdate->getUpdateOrder();

	m_pUpdates[ order ].remove( pUpdate );
}

/************************************************************************************************/
/*
 * 
 */
/************************************************************************************************/
void KsTaskManager::removeDraw( KsDraw* pDraw )
{
	const KsUInt32 order = pDraw->getDrawOrder();

	m_pDraws[ order ].remove( pDraw );
}

/************************************************************************************************/
/*
 * 
 */
/************************************************************************************************/
void KsTaskManager::destroyTask( KsTask* pTask )
{
}

/************************************************************************************************/
/*
 * 
 */
/************************************************************************************************/
void KsTaskManager::destroyUpdate( KsUpdate* pUpdate )
{
}

/************************************************************************************************/
/*
 * 
 */
/************************************************************************************************/
void KsTaskManager::destroyDraw( KsDraw* pDraw )
{
}


/************************************************************************************************/
/*
 * ���ׂč폜
 */
/************************************************************************************************/
void KsTaskManager::destroyAll()
{
}

/************************************************************************************************/
/*
 * �X�V����
 */
/************************************************************************************************/
void KsTaskManager::execute( void* pParam )
{
	// �ʃX���b�h�ŏ�������
	for( KsUInt32 order=0; order<m_numUpdateList; order++ )
	{
		m_pUpdates[ order ].update( pParam );
	}
}

/************************************************************************************************/
/*
 * �`�悷��
 */
/************************************************************************************************/
void KsTaskManager::render( void* pParam )
{
	/* �`�揈�� */
	begineRender();

	// �ʃX���b�h�ŏ�������
	for( KsUInt32 order=0; order<m_numDrawList; order++ )
	{
		m_pDraws[ order ].draw( pParam );
	}

	endRender();
}

/************************************************************************************************/
/*
 * �w��I�[�_�[�����X�g�b�v������Ƃ��̋@�\���ق���
 */
/************************************************************************************************/
void KsTaskManager::run( void* pParam )
{
	/* �X�V */
	execute( pParam );

	/* �`��(�J�����̕`��͂�������) */
	render( pParam );
}

/************************************************************************************************/
/*
 * �`��J�n
 */
/************************************************************************************************/
void KsTaskManager::begineRender()
{
}

/************************************************************************************************/
/*
 * �`��I��
 */
/************************************************************************************************/
void KsTaskManager::endRender()
{
}
#endif

ksNS_KS_END

