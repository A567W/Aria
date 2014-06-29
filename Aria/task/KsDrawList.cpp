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
 * @file	KsDrawList.cpp
 * @brief	�`�惊�X�g
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                            */
/*==============================================================================================*/
#include "KsDrawList.h"

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
KsDrawList::KsDrawList()
	: m_isActive( 0 )
	, m_pDrawRoot( ksNULLPTR )
	, m_pDrawLast( ksNULLPTR )
	, m_pDrawThread( ksNULLPTR )
{
}

/************************************************************************************************/
/*
 * �f�X�g���N�^
 */
/************************************************************************************************/
KsDrawList::~KsDrawList()
{
}

/************************************************************************************************/
/*
 * �`��^�X�N��ǉ�����
 * @param		pDraw				�`��^�X�N
 */
/************************************************************************************************/
void KsDrawList::add( KsDraw* pDraw )
{
	if( ksNULLPTR == m_pDrawRoot && ksNULLPTR == m_pDrawLast )
	{
		m_pDrawRoot = pDraw;
		m_pDrawLast = pDraw;
	}
	else
	{
		if( m_pDrawRoot->getDrawPriority() == m_pDrawLast->getDrawPriority() )
		{
			// �`��v���C�I���e�B���ꏏ�Ȃ̂Ń��X�g�ɒǉ�����
			m_pDrawLast->m_pDrawNext = pDraw;

			pDraw->m_pDrawPrev = m_pDrawLast;
			pDraw->m_pDrawNext = ksNULLPTR;

			m_pDrawLast = pDraw;
		}
		else
		{
			KsDraw* pTemp = m_pDrawLast;

			while( pTemp )
			{
				if( pTemp->getDrawPriority() <= pDraw->getDrawPriority() )
				{
					break;
				}
				pTemp = pTemp->m_pDrawPrev;
			}

			if( pTemp )
			{
				// ���X�g�ɒǉ�����
				if( pTemp == m_pDrawLast )
				{
					m_pDrawLast->m_pDrawNext = pDraw;

					pDraw->m_pDrawPrev = m_pDrawLast;
					pDraw->m_pDrawNext = ksNULLPTR;

					m_pDrawLast = pDraw;
				}
				else
				{
					// �r���ɒǉ�����
					pDraw->m_pDrawPrev = pTemp;
					pDraw->m_pDrawNext = pTemp->m_pDrawNext;
					pTemp->m_pDrawNext = pDraw;
				}

			}
			else
			{
				// �擪�ɒǉ�����
				m_pDrawRoot->m_pDrawPrev = pDraw;

				pDraw->m_pDrawPrev = ksNULLPTR;
				pDraw->m_pDrawNext = m_pDrawRoot;

				m_pDrawRoot = pDraw;

			}
		}
	}
}

/************************************************************************************************/
/*
 * �`��^�X�N����菜��
 * @param		pDraw				�`��^�X�N
 */
/************************************************************************************************/
void KsDrawList::remove( KsDraw* pDraw )
{
	if( pDraw == m_pDrawLast )
	{
		m_pDrawLast = ksNULLPTR;
	}
	else
	{
		pDraw->m_pDrawPrev->m_pDrawNext = pDraw->m_pDrawNext;

		if( pDraw->m_pDrawNext )
		{
			pDraw->m_pDrawNext->m_pDrawPrev = pDraw->m_pDrawPrev;
		}
	}

	pDraw->m_pDrawPrev = ksNULLPTR;
	pDraw->m_pDrawNext = ksNULLPTR;
}


/************************************************************************************************/
/*
 * �`�揈��
 * @param	pRenderContext	�`��R���e�L�X�g
 */
/************************************************************************************************/
void KsDrawList::draw( KsRenderContext* pRenderContext )
{
	KsDraw* pDraw = m_pDrawLast;

	while( pDraw )
	{
		pDraw->draw( pRenderContext );

		pDraw = pDraw->m_pDrawPrev;
	}
}
	

ksNS_KS_END

