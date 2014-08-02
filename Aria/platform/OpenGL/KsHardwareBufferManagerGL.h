/************************************************************************************************/
/** 
 * @file		KsHardwareBufferManagerGL.h
 * @brief		�o�b�t�@�}�l�[�W��
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/
#ifndef __KSBUFFERMANAGERGL_H__
#define __KSBUFFERMANAGERGL_H__

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
 * @class		KsBufferManager
 * @brief		�o�b�t�@�}�l�[�W��
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 */
/************************************************************************************************/
class ksENGINE_API KsHardwareBufferManagerGL : public KsHardwareBufferManager
{
	public:
		/**
		 * �R���X�g���N�^
		 * @param	pRenderSystem		�`��V�X�e��
		 */
										KsHardwareBufferManagerGL( KsRenderSystemGL* pRenderSystem );

		/**
		 * �f�X�g���N�^
		 */
		virtual							~KsHardwareBufferManagerGL();

		/**
		 * ���_�o�b�t�@�𐶐�����
		 * @param		vertexSize		[in] ���_�T�C�Y
		 * @param		numVertex		[in] ���_��
		 * @param		vertexFormat	[in] ���_�t�H�[�}�b�g
		 * @param		flags			[in] �t���O
		 * @return						���_�o�b�t�@�̃|�C���^
		 */
		virtual KsVertexBuffer*			createVertexBuffer( KsUInt32 vertexSize, KsUInt32 numVertex, KsUInt32 vertexFormat, KsUInt32 flags );

		/**
		 * ���_�o�b�t�@�𐶐�����
		 * @param		vertexSize		[in] ���_�T�C�Y
		 * @param		numVertex		[in] ���_��
		 * @param		vertexFormat	[in] ���_�t�H�[�}�b�g
		 * @param		flags			[in] �t���O
		 * @return						���_�o�b�t�@�̃|�C���^
		 */
		virtual KsVertexBuffer*			createVertexBuffer( void* pData, KsUInt32 vertexSize, KsUInt32 numVertex, KsUInt32 vertexFormat, KsUInt32 flags );

		/**
		 * �C���f�b�N�X�o�b�t�@�𐶐�����
		 * @param	numIndex			[in] �C���f�b�N�X�̐�
		 * @param	indexFormat			[in] �C���f�b�N�X�t�H�[�}�b�g
		 * @param	flags				[in] �t���O
		 * @return						�C���f�b�N�X�o�b�t�@�̃|�C���^
		 */
		virtual KsIndexBuffer*			createIndexBuffer( KsUInt32 numIndex, KsUInt32 indexFormat, KsUInt32 flags );

		/**
		 * �C���f�b�N�X�o�b�t�@�𐶐�����
		 * @param	pData				[in] �f�[�^�ǂݍ��ݗp�̃|�C���^
		 * @param	size				[in] �f�[�^�T�C�Y
		 * @param	numIndex			[in] �C���f�b�N�X�̐�
		 * @param	indexFormat			[in] �C���f�b�N�X�t�H�[�}�b�g
		 * @param	flags				[in] �t���O
		 * @return						�C���f�b�N�X�o�b�t�@�̃|�C���^
		 */
		virtual KsIndexBuffer*			createIndexBuffer( void* pData, KsUInt32 size, KsUInt32 numIndex, KsUInt32 indexFormat, KsUInt32 flags );

		/**
		 * �萔�o�b�t�@�𐶐�����
		 * @param	pData				[in] �f�[�^�ǂݍ��ݗp�̃|�C���^
		 * @param	size				[in] �f�[�^�T�C�Y
		 * @param	flags				[in] �t���O
		 * @return						�萔�o�b�t�@�̃|�C���^
		 */
		virtual KsConstantBuffer*		createConstantBuffer( KsUInt32 size, KsUInt32 flags );

		/**
		 * �萔�o�b�t�@�𐶐�����
		 * @param	size				[in] �o�b�t�@�T�C�Y
		 * @param	flags				[in] �t���O
		 * @return						�萔�o�b�t�@�̃|�C���^
		 */
		virtual KsConstantBuffer*		createConstantBuffer( void* pData, KsUInt32 size, KsUInt32 flags );

	protected:
		KsRenderSystemGL*				m_RenderSystem;		/**< �`��V�X�e��	*/

};

ksNS_KS_END

#endif		/* __KSBUFFERMANAGERGL_H__ */



