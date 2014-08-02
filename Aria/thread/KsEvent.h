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
 * @file	KsEvent.h
 * @brief	�X���b�h�C�x���g
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/
#ifndef __KSEVENT_H__
#define __KSEVENT_H__

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                            */
/*==============================================================================================*/
#include "KsThreadCommon.h"

/*==============================================================================================*/
/*                                     << ��` >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << �錾 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class		KsEvent
 * @brief		�X���b�h�C�x���g����
 * @author		A567W
 * @date		2004/03/30
 */
/************************************************************************************************/
class ksENGINE_API KsEvent
{
	public:
		/**
		 * �R���X�g���N�^
		 */
                        KsEvent();

		/**
		 * �f�X�g���N�^
		 */
                        ~KsEvent();

        /**
         * �C�x���g�I�u�W�F�N�g���V�O�i����Ԃɂ���B
         * @param	hEvent		�C�x���g�I�u�W�F�N�g�������n���h���B
         * @retval	ksTRUE		����
         * @retval	ksFALSE		���s
         */
        KsBool          signale();

        /**
         * �C�x���g�I�u�W�F�N�g���V�O�i����Ԃɂ���B
         * @param	hEvent		�C�x���g�I�u�W�F�N�g�������n���h���B
         * @retval	ksTRUE		����
         * @retval	ksFALSE		���s
         */
        KsBool          reset();

        /**
         * �w�肳�ꂽ�J�[�l���I�u�W�F�N�g���V�O�i����ԂɂȂ邩�A
         * �w�肳�ꂽ���Ԃ��o�߂���܂ŃX���b�h���X���[�v�����܂��B
         */
        KsUInt32        wait();

	private:
		KsHandle        m_handle;		/**< �C�x���g�n���h��   */
};

ksNS_KS_END

#endif		/* __KSEVENT_H__ */

