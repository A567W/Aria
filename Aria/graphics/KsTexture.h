/************************************************************************************************/
/** 
 * @file		KsTexture.h
 * @brief		�e�N�X�`��
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0
 */
/************************************************************************************************/
#ifndef __KSTEXTURE_H__
#define __KSTEXTURE_H__

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                           */
/*==============================================================================================*/
#include "KsShaderResource.h"

/*==============================================================================================*/
/*                                     << ��` >>                                               */
/*==============================================================================================*/
/* 0����15�r�b�g�܂ł͋��ʃt���O��16�r�b�g�ȍ~�͌ŗL�Ŋg���p */
#define ksTEXTURE_FLAG_USE_MANAGER		( 1 << 0 )		/**< �e�N�X�`���}�l�[�W�����g�p����	*/

/*==============================================================================================*/
/*                                     << �錾 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class		KsTexture
 * @brief		�e�N�X�`��
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @note		�Q�ƃJ�E���^��
 */
/************************************************************************************************/
class ksENGINE_API KsTexture : public KsShaderResource
{
		friend class KsTextureManager;

	protected:
		KsUInt32					m_numMipmap;	/**< �~�b�v�}�b�v��				*/
		KsUInt32					m_mipLevels;	/**< �~�b�v�}�b�v���x��			*/
		KsUInt16					m_width;		/**< ��							*/
		KsUInt16					m_height;		/**< ����						*/
		KsTexture*					m_pNext;		/**< �e�N�X�`���̃��X�g			*/

	public:
		/**
		 * �R���X�g���N�^
		 */
									KsTexture();

		/**
		 * �f�X�g���N�^
		 */
		virtual						~KsTexture();

		/**
		 * �e�N�X�`���̔j��
		 */
		virtual void				destroy() = 0;

		/**
		 * �e�N�X�`�����A�N�e�B�u�ɂ���
		 */
		virtual void				active() = 0;

		/**
		 * ���\�[�X���擾����
		 * @return					 ���\�[�X
		 */
		virtual void*				getBufferResource() = 0;

		/**
		 * ���\�[�X���擾����
		 * @return					 ���\�[�X
		 */
		virtual void*				getTextureResource() = 0;

		/**
		 * �o�b�t�@�����b�N����
		 * @param	pContext		�`��R���e�L�X�g
		 * @param	flags			���b�N�t���O
		 * @return					���b�N�����o�b�t�@�̐擪�|�C���^
		 */
		virtual void*				lock( const KsRenderContext* pContext, KsUInt32 flags ) = 0;

		/**
		 * �o�b�t�@�̃��b�N����������
		 * @param	pContext		�`��R���e�L�X�g
		 */
		virtual void				unlock( const KsRenderContext* pContext ) = 0;

		/**
		 * �o�b�t�@����̓ǂݍ���
		 * @param	pContext		�`��R���e�L�X�g
		 * @param	pData			�f�[�^�ǂݍ��ݗp�̃|�C���^
		 * @param	size			�f�[�^�T�C�Y
		 */
		virtual void				read( const KsRenderContext* pContext, void* pData, KsUInt32 size ) = 0;

		/**
		 * �o�b�t�@�ւ̏�������
		 * @param	pContext		�`��R���e�L�X�g
		 * @param	pData			�f�[�^�ǂݍ��ݗp�̃|�C���^
		 * @param	size			�f�[�^�T�C�Y
		 */
		virtual void				write( const KsRenderContext* pContext, void* pData, KsUInt32 size ) = 0;

		/**
		 * �e�N�X�`���̕����擾����
		 * @return					�e�N�X�`���̕�
		 */
		KsUInt16					getWidth() const { return m_width; }

		/**
		 * �e�N�X�`���̍������擾����
		 * @return					�e�N�X�`���̍���
		 */
		KsUInt16					getHeight() const { return m_height; }

		/**
		 * �~�b�v�}�b�v�̐����擾
		 * @return					�����Ă���~�b�v�}�b�v��
		 */
		KsUInt32					getNumMipmap() const { return m_numMipmap; }

		/**
		 * �~�b�v�}�b�v�������Ă��邩�ǂ���?
		 * @retval	ksTRUE			�����Ă���
		 * @retval	ksFALSE			�����Ă��Ȃ�
		 */
		KsBool						hasMipmap() { return ( m_numMipmap > 0 ); }

		/**
		 * �~�b�v�}�b�v���x�����擾����
		 * @return					�~�b�v�}�b�v���x��
		 */
		KsBool						getMipLevels() { return m_mipLevels; }
		
};

/************************************************************************************************/
/**
 * �e�N�X�`�����X�g
 */
/************************************************************************************************/
typedef KsArray<KsTexture*>	KsTextureArray;

ksNS_KS_END

#endif		/* __KSTEXTURE_H__ */



