/************************************************************************************************/
/** 
 * @file		KsShaderResource.h
 * @brief		�e�N�X�`��
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0
 */
/************************************************************************************************/
#ifndef __KSSHADERRESOURCE_H__
#define __KSSHADERRESOURCE_H__

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                            */
/*==============================================================================================*/
#include "KsGraphicsCommon.h"
#include "KsBufferObject.h"

/*==============================================================================================*/
/*                                     << ��` >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << �錾 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class		KsShaderResource
 * @brief		�e�N�X�`��
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @note		�Q�ƃJ�E���^��
 */
/************************************************************************************************/
class ksENGINE_API KsShaderResource : public KsBufferObject
{
		friend class KsTextureManager;

	protected:
		KsString					m_name;			/**< �e�N�X�`����					*/
		KsUInt32					m_id;			/**< �e�N�X�`��ID					*/
		KsUInt32					m_flags;		/**< �e��t���O					*/

	public:
		/**
		 * �R���X�g���N�^
		 */
									KsShaderResource();

		/**
		 * �f�X�g���N�^
		 */
		virtual						~KsShaderResource();

		/**
		 * �e�N�X�`���̔j��
		 */
		virtual void				destroy() = 0;

		/**
		 * ���\�[�X���擾����
		 * @return					 ���\�[�X
		 */
		virtual void*				getBufferResource() = 0;

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
		 * �e�N�X�`�������Z�b�g����
		 * @param	pFileName		�e�N�X�`����
		 */
		void						setName( const KsChar* pFileName );

		/**
		 * �t���O�擾
		 * @param	flags			�e�N�X�`���̊e��t���O
		 */
		void						setFlags( KsUInt32 flags ) { m_flags = flags; }

		/**
		 * �t���O�擾
		 * @return					�e�N�X�`���̊e��t���O
		 */
		KsUInt32					getFlags() const { return m_flags; }

		/**
		 * �e�N�X�`�������擾����
		 * @return					�e�N�X�`����
		 */
		const KsChar*				getName() { return m_name.c_str(); }

		/**
		 * �e�N�X�`��ID���擾����
		 * @return					�e�N�X�`��ID
		 */
		KsUInt32					getID() const { return m_id; }		
};

ksNS_KS_END

#endif		/* __KSSHADERRESOURCE_H__ */



