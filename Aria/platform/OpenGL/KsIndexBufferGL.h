/************************************************************************************************/
/** 
 * @file		KsIndexBufferGL.h
 * @brief		�C���f�b�N�X�o�b�t�@
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/
#ifndef __KSINDEXBUFFERGL_H__
#define __KSINDEXBUFFERGL_H__

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                           */
/*==============================================================================================*/
#include "KsCommonGL.h"

/*==============================================================================================*/
/*                                     << ��` >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << �錾 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

class KsRenderSystemGL;

/************************************************************************************************/
/**
 * @class		KsIndexBufferDX
 * @brief		�C���f�b�N�X�o�b�t�@
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 */
/************************************************************************************************/
class ksENGINE_API KsIndexBufferGL : public KsIndexBuffer
{
		friend class KsRenderContextGL;
	public:
		/**
		 * �R���X�g���N�^
		 * @param	pRenderSystem	�`��V�X�e��
		 * @param	pData			�f�[�^�ǂݍ��ݗp�̃|�C���^
		 * @param	size			�f�[�^�T�C�Y
		 * @param	numIndex		�C���f�b�N�X�̐�
		 * @param	indexFormat		�C���f�b�N�X�t�H�[�}�b�g
		 * @param	flags			�t���O
		 */
									KsIndexBufferGL( KsRenderSystemGL* pRenderSystem, void* pData, KsUInt32 size, KsUInt32 numIndex, KsUInt32 indexFormat, KsUInt32 flags );

		/**
		 * �f�X�g���N�^
		 */
		virtual						~KsIndexBufferGL();

		/**
		 * �C���f�b�N�X�o�b�t�@�𐶐�����
		 * @param	pRenderSystem	�`��V�X�e��
		 * @param	pData			�f�[�^�ǂݍ��ݗp�̃|�C���^
		 * @param	size			�f�[�^�T�C�Y
		 * @param	numIndex		�C���f�b�N�X�̐�
		 * @param	indexFormat		�C���f�b�N�X�t�H�[�}�b�g
		 * @param	flags			�t���O
		 * @retval	ksTRUE			��������
		 * @retval	ksFALSE			�������s
		 */
		virtual KsBool				create( KsRenderSystemGL* pRenderSystem, void* pData, KsUInt32 size, KsUInt32 numIndex, KsUInt32 indexFormat, KsUInt32 flags );

		/**
		 * �j������
		 */
		virtual void				destroy();

		/**
		 * ���\�[�X���擾����
		 * @return					 ���\�[�X
		 */
		virtual void*				getBufferResource();

		/**
		 * �C���f�b�N�X�o�b�t�@�����b�N����
		 * @param	pContext		�`��R���e�L�X�g
		 * @param	flags			���b�N�t���O
		 * @return					���b�N�����o�b�t�@�̐擪�|�C���^
		 */
		virtual void*				lock( const KsRenderContext* pContext, KsUInt32 flags );

		/**
		 * �C���f�b�N�X�o�b�t�@�̃��b�N����������
		 * @param	pContext		�`��R���e�L�X�g
		 */
		virtual void				unlock( const KsRenderContext* pContext );

		/**
		 * �C���f�b�N�X�o�b�t�@����̓ǂݍ���
		 * @param	pContext		�`��R���e�L�X�g
		 * @param	pData			�f�[�^�ǂݍ��ݗp�̃|�C���^
		 * @param	size			�f�[�^�T�C�Y
		 */
		virtual void				read( const KsRenderContext* pContext, void* pData, KsUInt32 size );

		/**
		 * �C���f�b�N�X�o�b�t�@�ւ̏�������
		 * @param	pContext		�`��R���e�L�X�g
		 * @param	pData			�f�[�^�ǂݍ��ݗp�̃|�C���^
		 * @param	size			�f�[�^�T�C�Y
		 */
		virtual void				write( const KsRenderContext* pContext, void* pData, KsUInt32 size );

	private:
		KsRenderSystemGL*			m_pRenderSystem;	/**< �`��V�X�e��				*/
        GLuint                      m_indexBuffer;      /**< ���_�o�b�t�@ID       */
		KsUInt32					m_indexSize;		/**< �C���f�b�N�X�T�C�Y		*/
};

ksNS_KS_END

#endif		/* __KSINDEXBUFFERGL_H__ */


