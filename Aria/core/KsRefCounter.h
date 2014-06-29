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
 * @brief	�Q�ƃJ�E���^
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/
#ifndef __KSREFCOUNTER_H__
#define __KSREFCOUNTER_H__

/*===============================================================================================*/
/*								<< �C���N���[�h�t�@�C�� >>											 */
/*===============================================================================================*/
#include "KsCoreCommon.h"

/*===============================================================================================*/
/*										<< ��` >>												 */
/*===============================================================================================*/
ksNS_KS_BEGIN

/*************************************************************************************************/
/**
 * @class	KsRefCounter
 * @brief	�Q�ƃJ�E���^�N���X
 * @author	A567W
 * @since   2005/06/27
 * @note	�p�����Ďg�p���܂��B
 */
/*************************************************************************************************/
class ksENGINE_API KsRefCounter
{
	public:
		/**
		 * �R���X�g���N�^
		 */
									KsRefCounter() : m_refCount( 1 ) {}
		/**
		 * �f�X�g���N�^
		 */
		virtual						~KsRefCounter() { m_refCount = 0; }
	
		/**
		 * �Q�ƃJ�E���g
		 */
		KsInt32						getRefCount() const { return m_refCount; }

		/**
		 * �Q�ƃJ�E���g��������
		 */
		void						inc() { ++m_refCount; }

		/**
		 * �Q�ƃJ�E���g�����炷
		 * @note					�Q�ƃJ�E���g��0�ɂȂ�����폜�����
		 */
		void						dec() { if( !(--m_refCount) ) { delete this; } }

	private:
		KsInt32						m_refCount;		/**< �Q�ƃJ�E���g	*/
};

ksNS_KS_END

#endif	/* __KSREFCOUNTER_H__ */

