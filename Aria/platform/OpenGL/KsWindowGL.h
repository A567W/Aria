/*************************************************************************************************/
/** 
 * @file	KsWindowGL.h
 * @brief	OpenGL �E�C���h�E
 * @author	A567W
 * @date	2003/03/22
 * @since	----/--/--
 * @version	1.0.0
 */
/*************************************************************************************************/
#ifndef __KSWINDOWSGL_H__
#define __KSWINDOWSGL_H__

/*===============================================================================================*/
/*                                 << �C���N���[�h >>                                             */
/*===============================================================================================*/
#include "KsCommonGL.h"

/*===============================================================================================*/
/*                                     << ��` >>                                                */
/*===============================================================================================*/
ksNS_KS_BEGIN

/*************************************************************************************************/
/**
 * �E�C���h�E�N���X
 * @author  A567W
 * @since   2003/03/22
 * @version ----/--/--
 */
/*************************************************************************************************/
class ksENGINE_API KsWindowGL
{
	protected:
        GLFWwindow*                     m_pWindow;
        GLFWmonitor*                    m_pMonitor;

	public:
		/**
		 * �R���X�g���N�^(�E�C���h�E����)
		 * @param		param			�E�C���h�E�����̂��߂̃p�����[�^
		 * @param		hParent			�e�E�C���h�E�̃n���h��
		 * @retval		ksTRUE			����
		 * @retval		ksFALSE			���s
		 */
										KsWindowGL( const KsWindowParam& param );

		/**
		 * �f�X�g���N�^
		 */
		virtual							~KsWindowGL() {}

		/**
		 * �E�C���h�E�̃p�����[�^���擾����
		 * @return						�E�C���h�E�p�����[�^
		 */
		const KsWindowParam&			getWindowParam()				{ return m_windowParam; }

		/**
		 * �E�C���h�E�̕����擾����
		 * @return						�E�C���h�E�̕�
		 */
		KsInt32							getWidth()				const	{ return m_windowParam.m_sizeX;	 }

		/**
		 * �E�C���h�E�̍������擾����
		 * @return						�E�C���h�E�̍���
		 */
		KsInt32							getHeight()				const	{ return m_windowParam.m_sizeY;	 }

		/**
		 * �E�C���h�E���ŏ�������Ă��邩���`�F�b�N����
		 * @retval		ksTRUE			�ŏ�������Ă���
		 * @retval		ksTRUE			�ŏ�������ĂȂ�
		 */
		KsBool							isMinmimized()			const	{ return m_bMinimized; }

		/**
		 * �t���X�N���[��������Ă��邩���`�F�b�N����
		 * @retval		ksTRUE			�t���X�N���[��������Ă���
		 * @retval		ksTRUE			�t���X�N���[��������ĂȂ�
		 */
		KsBool							isFullScreen()			const	{ return m_bFullScreen; }

		/**
		 * �E�C���h�E����
		 * @param		param			�E�C���h�E�����̂��߂̃p�����[�^
		 * @param		hParent			�e�E�C���h�E�̃n���h��
		 * @retval		ksTRUE			����
		 * @retval		ksFALSE			���s
		 */
		KsBool							create( const KsWindowParam& param );

		/**
		 * ���b�Z�[�W���[�v
		 * @return		���b�Z�[�W�v��
		 */
		KsInt32							messageLoop();

		/**
		 * �E�C���h�E�ʒu���Z�b�g
		 * @param		x				�E�C���h�E���Z�b�g����X���W
		 * @param		y				�E�C���h�E���Z�b�g����Y���W
		 */
		void							setPos( KsInt32 x, KsInt32 y );

		/**
		* �E�C���h�E�𒆉��ɃZ�b�g
		*/
		void							setCenter();
};

ksNS_KS_END

#endif	/* __KSWINDOWSGL_H__ */

