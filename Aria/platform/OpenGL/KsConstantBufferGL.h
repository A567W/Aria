/************************************************************************************************/
/** 
 * @file		KsConstantBufferGL.h
 * @brief		�萔�o�b�t�@
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/
#ifndef __KSCONSTANTBUFFERGL_H__
#define __KSCONSTANTBUFFERGL_H__

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                            */
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
 * @class		KsConstantBufferGL
 * @brief		�萔�o�b�t�@
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 */
/************************************************************************************************/
class ksENGINE_API KsConstantBufferGL : public KsConstantBuffer
{
		friend class KsRenderContextGL;
	public:
		/**
		 * �R���X�g���N�^
		 * @param	pRenderSystem	�`��V�X�e��
		 * @param	pData			�f�[�^�ǂݍ��ݗp�̃|�C���^
		 * @param	size			�f�[�^�T�C�Y
		 * @param	flags			�t���O
		 */
									KsConstantBufferGL( KsRenderSystemGL* pRenderSystem, void* pData, KsUInt32 size, KsUInt32 flags );

		/**
		 * �f�X�g���N�^
		 */
		virtual						~KsConstantBufferGL();

		/**
		 * �萔�o�b�t�@�𐶐�����
		 * @param	pRenderSystem	�`��V�X�e��
		 * @param	pData			�f�[�^�ǂݍ��ݗp�̃|�C���^
		 * @param	size			�f�[�^�T�C�Y
		 * @retval	ksTRUE			��������
		 * @retval	ksFALSE			�������s
		 */
		virtual KsBool				create( KsRenderSystemGL* pRenderSystem, void* pData, KsUInt32 size, KsUInt32 flags );


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
		 * �萔�o�b�t�@�����b�N����
		 * @param	pContext		�`��R���e�L�X�g
		 * @param	flags			���b�N�t���O
		 * @return					���b�N�����o�b�t�@�̐擪�|�C���^
		 */
		virtual void*				lock( const KsRenderContext* pContext, KsUInt32 flags );

		/**
		 * �萔�o�b�t�@�̃��b�N����������
		 * @param	pContext		�`��R���e�L�X�g
		 */
		virtual void				unlock( const KsRenderContext* pContext );

		/**
		 * �萔�o�b�t�@����̓ǂݍ���
		 * @param	pContext		�`��R���e�L�X�g
		 * @param	pData			�f�[�^�ǂݍ��ݗp�̃|�C���^
		 * @param	size			�f�[�^�T�C�Y
		 */
		virtual void				read( const KsRenderContext* pContext, void* pData, KsUInt32 size );

		/**
		 * �萔�o�b�t�@�ւ̏�������
		 * @param	pContext		�`��R���e�L�X�g
		 * @param	pData			�f�[�^�ǂݍ��ݗp�̃|�C���^
		 * @param	size			�f�[�^�T�C�Y
		 */
		virtual void				write( const KsRenderContext* pContext, void* pData, KsUInt32 size );

	protected:
		KsRenderSystemGL*			m_pRenderSystem;		/**< �`��V�X�e��			*/
};

ksNS_KS_END


#endif		/* __KSCONSTANTBUFFERGL_H__ */



