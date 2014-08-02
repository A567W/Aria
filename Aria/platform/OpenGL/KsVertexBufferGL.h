/************************************************************************************************/
/** 
 * @file		KsVertexBufferGL.h
 * @brief		���_�o�b�t�@
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/
#ifndef __KSVERTEXBUFFERGL_H__
#define __KSVERTEXBUFFERGL_H__

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
 * @class		KsVertexBufferGL
 * @brief		���_�o�b�t�@
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 */
/************************************************************************************************/
class ksENGINE_API KsVertexBufferGL : public KsVertexBuffer
{
		friend class KsRenderContextGL;
	public:
		/**
		 * ���_�o�b�t�@�𐶐�����
		 * @param	pRenderSystem	�`��V�X�e��
		 * @param	pData			�f�[�^�ǂݍ��ݗp�̃|�C���^
		 * @param	vertexSize		���_�T�C�Y
		 * @param	numVertex		���_��
		 * @param	vertexFormat	���_�t�H�[�}�b�g
		 * @param	flags			�t���O
		 */
									KsVertexBufferGL( KsRenderSystemGL* pRenderSystem, void* pData, KsUInt32 vertexSize, KsUInt32 numVertex, KsUInt32 vertexFormat, KsUInt32 flags );

		/**
		 * �f�X�g���N�^
		 */
		virtual						~KsVertexBufferGL();

		/**
		 * ���_�o�b�t�@�𐶐�����
		 * @param	pRenderSystem	�`��V�X�e��
		 * @param	pData			�f�[�^�ǂݍ��ݗp�̃|�C���^
		 * @param	vertexSize		���_�T�C�Y
		 * @param	numVertex		���_��
		 * @param	vertexFormat	���_�t�H�[�}�b�g
		 * @param	flags			�t���O
		 * @retval	ksTRUE			��������
		 * @retval	ksFALSE			�������s
		 */
		virtual KsBool				create( KsRenderSystemGL* pRenderSystem, void* pData, KsUInt32 vertexSize, KsUInt32 numVertex, KsUInt32 vertexFormat, KsUInt32 flags );

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
		 * ���_�o�b�t�@�����b�N����
		 * @param	pContext		�`��R���e�L�X�g
		 * @param	flags			���b�N�t���O
		 * @return					���b�N�����o�b�t�@�̐擪�|�C���^
		 */
		virtual void*				lock( const KsRenderContext* pContext, KsUInt32 flags );

		/**
		 * ���_�o�b�t�@�̃��b�N����������
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
		KsRenderSystemGL*			m_pRenderSystem;	/**< �`��V�X�e��			*/
        GLuint                      m_vertexBuffer;     /**< ���_�o�b�t�@ID       */
};

ksNS_KS_END

#endif		/* __KSVERTEXBUFFERGL_H__ */


