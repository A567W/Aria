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
 * @file	KsUpdate.cpp
 * @brief	更新処理
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsUpdate.h"

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
KsUpdate::KsUpdate()
	: m_updateID( 0 )
	, m_updateOrder( 0 )
	, m_updatePriority( 0 )
	, m_updateActive( 0 )
	, m_updateFlags( 0 )
	, m_pUpdatePrev( 0 )
	, m_pUpdateNext( 0 )
	, m_pUpdateThread( 0 )
{
}

/************************************************************************************************/
/*
 * コンストラクタ
 * @param	order	描画オーダー
 */
/************************************************************************************************/
KsUpdate::KsUpdate( KsUInt32 order )
	: m_updateID( 0 )
	, m_updateOrder( order )
	, m_updatePriority( 0 )
	, m_updateActive( 0 )
	, m_updateFlags( 0 )
	, m_pUpdatePrev( 0 )
	, m_pUpdateNext( 0 )
	, m_pUpdateThread( 0 )
{
}

/************************************************************************************************/
/*
 * デストラクタ
 */
/************************************************************************************************/
KsUpdate::~KsUpdate()
{
}

/************************************************************************************************/
/*
 * 破棄する(マネージャ側で削除する)
 */
/************************************************************************************************/
void KsUpdate::destroyUpdate()
{

}

ksNS_KS_END
