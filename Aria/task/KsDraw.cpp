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
 * @file	KsDraw.cpp
 * @brief	描画タスク
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsDraw.h"

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
KsDraw::KsDraw()
	: m_drawID( 0 )
	, m_drawOrder( 0 )
	, m_drawPriority( 0 )
	, m_drawActive( 0 )
	, m_drawFlags( 0 )
	, m_pDrawPrev( ksNULLPTR )
	, m_pDrawNext( ksNULLPTR )
	, m_pDrawThread( ksNULLPTR )
{
}

/************************************************************************************************/
/*
 * コンストラクタ
 * @param	order	描画オーダー
 */
/************************************************************************************************/
KsDraw::KsDraw( KsUInt32 order )
	: m_drawID( 0 )
	, m_drawOrder( order )
	, m_drawPriority( 0 )
	, m_drawActive( 0 )
	, m_drawFlags( 0 )
	, m_pDrawPrev( ksNULLPTR )
	, m_pDrawNext( ksNULLPTR )
	, m_pDrawThread( ksNULLPTR )
{
}

/************************************************************************************************/
/*
 * デストラクタ
 */
/************************************************************************************************/
KsDraw::~KsDraw()
{
}

/************************************************************************************************/
/*
 * 破棄する(マネージャ側で削除する)
 */
/************************************************************************************************/
void KsDraw::destroyDraw()
{
	m_drawFlags |= ksDRAW_DESTROY_FLAG;
}

ksNS_KS_END

