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
 * @brief	描画リスト
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsDrawList.h"

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
KsDrawList::KsDrawList()
	: m_isActive( 0 )
	, m_pDrawRoot( ksNULLPTR )
	, m_pDrawLast( ksNULLPTR )
	, m_pDrawThread( ksNULLPTR )
{
}

/************************************************************************************************/
/*
 * デストラクタ
 */
/************************************************************************************************/
KsDrawList::~KsDrawList()
{
}

/************************************************************************************************/
/*
 * 描画タスクを追加する
 * @param		pDraw				描画タスク
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
			// 描画プライオリティが一緒なのでラストに追加する
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
				// ラストに追加する
				if( pTemp == m_pDrawLast )
				{
					m_pDrawLast->m_pDrawNext = pDraw;

					pDraw->m_pDrawPrev = m_pDrawLast;
					pDraw->m_pDrawNext = ksNULLPTR;

					m_pDrawLast = pDraw;
				}
				else
				{
					// 途中に追加する
					pDraw->m_pDrawPrev = pTemp;
					pDraw->m_pDrawNext = pTemp->m_pDrawNext;
					pTemp->m_pDrawNext = pDraw;
				}

			}
			else
			{
				// 先頭に追加する
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
 * 描画タスクを取り除く
 * @param		pDraw				描画タスク
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
 * 描画処理
 * @param	pRenderContext	描画コンテキスト
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

