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
 * @file	KsAppInstance.h
 * @brief	�E�C���h�E�A�v���P�[�V�����̃C���X�^���X�N���X
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
/************************************************************************************************/
#ifndef __KSAPPINSTANCE_H__
#define __KSAPPINSTANCE_H__

/*===============================================================================================*/
/*                                 << �C���N���[�h >>                                             */
/*===============================================================================================*/
#include "KsWindowsCommon.h"

/*===============================================================================================*/
/*                                     << ��` >>                                                */
/*===============================================================================================*/
ksNS_KS_BEGIN

/*************************************************************************************************/
/**
 * @class	KsAppInstance
 * @brief	�E�C���h�E�A�v���P�[�V�����̃C���X�^���X�N���X
 * @author  A567W
 * @since   2003/03/22
 * @version ----/--/--
 */
/*************************************************************************************************/
class ksENGINE_API KsAppInstance
{
	public:
		static HINSTANCE				m_hInstance;		/**< �E�B���h�E�����̃p�����[�^	*/
		static HINSTANCE				m_hPrevInstance;	/**< �E�B���h�E�����̃p�����[�^	*/
		static LPSTR					m_lpCmdLine;		/**< �E�B���h�E�����̃p�����[�^	*/
		static KsInt32					m_nCmdShow;			/**< �E�B���h�E�����̃p�����[�^	*/

		/**
		 * �p�����[�^���Z�b�g����
		 */
		static void						setup( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, KsInt32 nCmdShow );

		/**
		 * �f�X�g���N�^
		 */
										~KsAppInstance(){}

	private:
		/**
		 * �R���X�g���N�^
		 */
										KsAppInstance(){}
};

ksNS_KS_END


#endif	/* __KSAPPINSTANCE_H__ */

