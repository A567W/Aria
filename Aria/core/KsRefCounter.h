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
 * @file	KsRefCounter.h
 * @brief	参照カウンタ
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/
#ifndef __KSREFCOUNTER_H__
#define __KSREFCOUNTER_H__

/*===============================================================================================*/
/*								<< インクルードファイル >>											 */
/*===============================================================================================*/
#include "KsCoreCommon.h"

/*===============================================================================================*/
/*										<< 定義 >>												 */
/*===============================================================================================*/
ksNS_KS_BEGIN

/*************************************************************************************************/
/**
 * @class	KsRefCounter
 * @brief	参照カウンタクラス
 * @author	A567W
 * @since   2005/06/27
 * @note	継承して使用します。
 */
/*************************************************************************************************/
class ksENGINE_API KsRefCounter
{
	public:
		/**
		 * コンストラクタ
		 */
									KsRefCounter() : m_refCount( 1 ) {}
		/**
		 * デストラクタ
		 */
		virtual						~KsRefCounter() { m_refCount = 0; }
	
		/**
		 * 参照カウント
		 */
		KsInt32						getRefCount() const { return m_refCount; }

		/**
		 * 参照カウントをあげる
		 */
		void						inc() { ++m_refCount; }

		/**
		 * 参照カウントを減らす
		 * @note					参照カウントが0になったら削除される
		 */
		void						dec() { if( !(--m_refCount) ) { delete this; } }

	private:
		KsInt32						m_refCount;		/**< 参照カウント	*/
};

ksNS_KS_END

#endif	/* __KSREFCOUNTER_H__ */

