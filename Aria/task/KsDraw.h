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
 * @file	KsDraw.h
 * @brief	�`��^�X�N
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/
#ifndef __KSDRAW_H__
#define __KSDRAW_H__

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                            */
/*==============================================================================================*/
#include "KsTaskCommon.h"

/*==============================================================================================*/
/*                                     << ��` >>                                               */
/*==============================================================================================*/
#define ksDRAW_DESTROY_FLAG		( 0x80000000 )

/*==============================================================================================*/
/*                                     << �錾 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

class KsDrawThread;

/************************************************************************************************/
/**
 * @class	KsDraw
 * @brief	�`��^�X�N
 * @author	A567W
 */
/************************************************************************************************/
class ksENGINE_API KsDraw
{
		friend class KsDrawList;
		friend class KsDrawThread;

	public:
		/**
		 * �R���X�g���N�^
		 * @brief	0�ŏ����������
		 */
											KsDraw();

		/**
		 * �R���X�g���N�^
		 * @param	order					�`��I�[�_�[
		 */
											KsDraw( KsUInt32 order );

		/**
		 * �f�X�g���N�^
		 */
		virtual								~KsDraw();

		/**
		 * �^�X�N�̎���ID���擾����
		 * @return		�^�X�N��ID���擾����
		 */
		KsUInt32							getDrawID() const { return m_drawID; }

		/**
		 * �I�[�_�[���擾����
		 * @return		�`��I�[�_�[���擾����
		 */
		KsUInt32							getDrawOrder() const { return m_drawOrder; }

		/**
		 * �`�悷�邩�ǂ������Z�b�g����
		 * @param		drawActive		�`�悷�邩�ǂ������Z�b�g����
		 */
		void								setActiveDraw( KsBool drawActive ) { m_drawActive = drawActive; }

		/**
		 * �`�悷�邩�ǂ������擾����
		 * @return		�`�悷�邩�ǂ������擾����
		 */
		KsBool								isActiveDraw() const { return m_drawActive; }

		/**
		 * �`��v���C�I���e�B���擾����
		 * @return		�`��v���C�I���e�B���擾����
		 */
		KsUInt32							getDrawPriority() const { return m_drawPriority; }

	protected:
		/**
		 * ����������(�}�l�[�W���ɓo�^���ꂽ�Ƃ��ɓo�^)
		 * @param		pRenderContext		�`��R���e�L�X�g
		 */
		virtual void*						initializeGraphics( KsRenderContext* pRenderContext ) = 0;

		/**
		 * �`�揈��
		 * @param		pRenderContext		�`��R���e�L�X�g
		 */
		virtual void*						draw( KsRenderContext* pRenderContext ) = 0;

		/**
		 * �㏈���֐��Ń������[����폜�����Ƃ��ɌĂ΂��
		 * @param		pRenderContext		�`��R���e�L�X�g
		 */
		virtual void*						terminateGraphics( KsRenderContext* pRenderContext ) = 0;

		/**
		 * �j������(�}�l�[�W�����ō폜����)
		 */
		virtual void						destroyDraw();

	protected:
		KsUInt32							m_drawID;		/**< �`�掯��ID(�����I�Ɋ���U��?)		*/
		KsUInt32							m_drawOrder;	/**< �`��I�[�_�[						*/
		KsUInt32							m_drawPriority;	/**< �`��v���C�I���e�B				*/
		KsBool								m_drawActive;	/**< �`��A�N�e�B�u�t���O				*/
		KsUInt32							m_drawFlags;	/**< �`��t���O						*/
		KsDraw*								m_pDrawPrev;	/**< �`��O�����X�g					*/
		KsDraw*								m_pDrawNext;	/**< �`�������X�g					*/
		KsDrawThread*						m_pDrawThread;	/**< �`��X���b�h						*/
};

ksNS_KS_END

#endif /* __KSDRAW_H__ */

