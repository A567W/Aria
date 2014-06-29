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
 * @file	KsUpdate.h
 * @brief	�X�V����
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/
#ifndef __KSUPDATE_H__
#define __KSUPDATE_H__

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                            */
/*==============================================================================================*/
#include "KsTaskCommon.h"
#include "KsUpdateThread.h"

/*==============================================================================================*/
/*                                     << ��` >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << �錾 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

class KsUpdateThread;

/*************************************************************************************************/
/**
 * @class	KsUpdate
 * @brief	�X�V�����^�X�N
 * @author	A567W
 */
/*************************************************************************************************/
class ksENGINE_API KsUpdate
{
		friend class KsUpdateList;
		friend class KsUpdateThread;
	
	public:
		/**
		 * �R���X�g���N�^
		 * @brief	0�ŏ����������
		 */
											KsUpdate();

		/**
		 * �R���X�g���N�^
		 * @param	order					�X�V�I�[�_�[
		 */
											KsUpdate( KsUInt32 order );

		/**
		 * �f�X�g���N�^
		 */
		virtual								~KsUpdate();

		/**
		 * �^�X�N�̎���ID���擾����
		 * @return		�^�X�N��ID���擾����
		 */
		KsUInt32							getUpdateID() const { return m_updateID; }

		/**
		 * �I�[�_�[���擾����
		 * @return		�X�V�I�[�_�[���擾����
		 */
		KsUInt32							getUpdateOrder() const { return m_updateOrder; }

		/**
		 * �X�V���邩�ǂ������Z�b�g����
		 * @param		updateActive		�X�V���邩�ǂ������Z�b�g����
		 */
		void								setActiveUpdate( KsBool updateActive ) { m_updateActive = updateActive; }

		/**
		 * �X�V���邩�ǂ������擾����
		 * @return		�X�V���邩�ǂ������擾����
		 */
		KsBool								isActiveUpdate() const { return m_updateActive; }

		/**
		 * �X�V�v���C�I���e�B���擾����
		 * @return		�X�V�v���C�I���e�B���擾����
		 */
		KsUInt32							getUpdatePriority() const { return m_updatePriority; }

	protected:
		/**
		 * ����������(�}�l�[�W���ɓo�^���ꂽ�Ƃ��ɓo�^)
		 * @param		pParam				�p�����[�^
		 */
		virtual void*						initialize( void* pParam ) = 0;

		/**
		 * �X�V����
		 * @param		pParam				�p�����[�^
		 */
		virtual void*						update( void* pParam ) = 0;

		/**
		 * �㏈���֐��Ń������[����폜�����Ƃ��ɌĂ΂��
		 * @param		pParam				�p�����[�^
		 */
		virtual void*						terminate( void* pParam ) = 0;

		/**
		 * �j������(�}�l�[�W�����ō폜����)
		 */
		virtual void						destroyUpdate();

	protected:
		KsUInt32							m_updateID;			/**< �^�X�N����ID(�����I�Ɋ���U��?)	*/
		KsUInt32							m_updateOrder;		/**< �X�V�I�[�_�[						*/
		KsUInt32							m_updatePriority;	/**< �X�V�v���C�I���e�B				*/
		KsBool								m_updateActive;		/**< �X�V�A�N�e�B�u�t���O				*/
		KsBool								m_updateFlags;		/**< �X�V�t���O						*/
		KsUpdate*							m_pUpdatePrev;		/**< �X�V�O�����X�g					*/
		KsUpdate*							m_pUpdateNext;		/**< �X�V������X�g					*/
		KsUpdateThread*						m_pUpdateThread;	/**< �X�V�X���b�h						*/
};

ksNS_KS_END

#endif /* __KSUPDATE_H__ */

