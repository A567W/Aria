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
 * @file	KsBezier.cpp
 * @brief	ベジェ曲線クラス
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
/************************************************************************************************/

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsBezier.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/

/************************************************************************************************/
/*
 * 初期化
 */
/************************************************************************************************/
void KsBezier::setup( KsReal fPointX1, KsReal fPointY1, KsReal fPointX2, KsReal fPointY2 )
{
	if( fPointX1 == fPointY1 && fPointX2 == fPointY2 )
	{
		m_bLinear = ksTRUE;
	}
	else
	{
		fPointX1 = (fPointX1 / 127.0f) * 3.0f;
		fPointY1 = (fPointY1 / 127.0f) * 3.0f;

		fPointX2 = (fPointX2 / 127.0f) * 3.0f;
		fPointY2 = (fPointY2 / 127.0f) * 3.0f;

		// 高速化のためテーブル化しておく
		m_value[0] = 0.0f;
		m_value[DIV_NUM] = 1.0f;

		KsReal	fAddX = 1.0f / (KsReal)DIV_NUM;

		for( KsInt32 i = 1 ; i < DIV_NUM ; i++ )
		{
			m_value[i] = getValue( fAddX * i, fPointX1, fPointY1, fPointX2, fPointY2 );
		}

		m_bLinear = ksFALSE;
	}
}

/************************************************************************************************/
/*
 * X値に対応するY値を返す
 */
/************************************************************************************************/
KsReal KsBezier::getValue( KsReal fX, KsReal fX1, KsReal fY1, KsReal fX2, KsReal fY2 )
{
	KsReal	fT = fX;
	KsReal	fInvT = 1.0f - fT;

	for( KsInt32 i = 0 ; i < 32 ; i++ )
	{
		KsReal	fTempX = fInvT*fInvT*fT*fX1 + fInvT*fT*fT*fX2 + fT*fT*fT;

		fTempX -= fX;
		if( fabsf( fTempX ) < 0.0001f )
		{
			break;
		}
		else
		{
			fT -= fTempX * 0.5f;
			fInvT = 1.0f - fT;
		}
	}

	return fInvT*fInvT*fT*fY1 + fInvT*fT*fT*fY2 + fT*fT*fT;
}

/************************************************************************************************/
/*
 * 曲線補間値を返す
 */
/************************************************************************************************/
KsReal KsBezier::getInterValue( KsReal fX ) const
{
	if( m_bLinear )
	{
		// 線形補間
		return fX;
	}

	// テーブルを線形補間する
	fX *= (KsReal)DIV_NUM;

	const KsInt32	iIdx = (KsInt32)fX;

	fX -= iIdx;

	return m_value[iIdx] * (1.0f - fX) + m_value[iIdx + 1] * fX;
}
