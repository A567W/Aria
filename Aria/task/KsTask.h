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
 * @file	KsTask.h
 * @brief	�^�X�N
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/
#ifndef __KSTASK_H__
#define __KSTASK_H__

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                            */
/*==============================================================================================*/
#include "KsTaskCommon.h"
#include "KsUpdate.h"
#include "KsDraw.h"

/*==============================================================================================*/
/*                                     << ��` >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << �錾 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class	KsTask
 * @brief	�X�V�����^�X�N
 * @author	A567W
 */
/************************************************************************************************/
class ksENGINE_API KsTask : public KsUpdate, public KsDraw
{
		friend class KsTaskManager;
	
	public:
		/**
		 * �R���X�g���N�^
		 * @brief	0�ŏ����������
		 */
									KsTask();

		/**
		 * �R���X�g���N�^
		 * @param	updateOrder		�X�V�I�[�_�[
		 * @param	drawOrder		�`��I�[�_�[
		 */
									KsTask( KsUInt32 updateOrder, KsUInt32 drawOrder );

		/**
		 * �f�X�g���N�^
		 */
		virtual						~KsTask();

		/**
		 * �j������(�}�l�[�W�����ō폜����)
		 */
		virtual void				destroy();

	protected:
		/**
		 * ����������(�}�l�[�W���ɓo�^���ꂽ�Ƃ��ɓo�^)
		 * @param		pParam		�p�����[�^
		 */
		virtual void*				initialize( void* pParam );

		/**
		 * �㏈���֐��Ń������[����폜�����Ƃ��ɌĂ΂��
		 * @param		pParam		�p�����[�^
		 */
		virtual void*				terminate( void* pParam );

		/**
		 * ����������(�}�l�[�W���ɓo�^���ꂽ�Ƃ��ɓo�^)
		 * @param		pParam		�p�����[�^
		 */
		virtual void*				initializeGraphics( void* pParam );

		/**
		 * �㏈���֐��Ń������[����폜�����Ƃ��ɌĂ΂��
		 * @param		pParam		�p�����[�^
		 */
		virtual void*				terminateGraphics( void* pParam );

};

ksNS_KS_END

#endif /* __KSTASK_H__ */

