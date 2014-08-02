/************************************************************************************************/
/** 
 * @file		KsHardwareBufferManagerGL.cpp
 * @brief		�o�b�t�@�}�l�[�W��
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                           */
/*==============================================================================================*/
#include "KsRenderSystemGL.h"
#include "KsHardwareBufferManagerGL.h"
#include "KsConstantBufferGL.h"
#include "KsIndexBufferGL.h"
#include "KsVertexBufferGL.h"

/*==============================================================================================*/
/*                                     << ��` >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << �錾 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/*
 * �R���X�g���N�^
 */
/************************************************************************************************/
KsHardwareBufferManagerGL::KsHardwareBufferManagerGL( KsRenderSystemGL* _RenderSystem )
	: m_RenderSystem( _RenderSystem )
{
}

/************************************************************************************************/
/*
 * �f�X�g���N�^
 */
/************************************************************************************************/
KsHardwareBufferManagerGL::~KsHardwareBufferManagerGL()
{
}

/************************************************************************************************/
/*
 * ���_�o�b�t�@�𐶐�����
 * @param		vertexSize		���_�T�C�Y
 * @param		numVertex		���_��
 * @param		vertexFormat	���_�t�H�[�}�b�g
 * @param		flags			�t���O
 * @return						���_�o�b�t�@�̃|�C���^
 */
/************************************************************************************************/
KsVertexBuffer* KsHardwareBufferManagerGL::createVertexBuffer( KsUInt32 vertexSize, KsUInt32 numVertex, KsUInt32 vertexFormat, KsUInt32 flags )
{
	return ksNew KsVertexBufferGL( m_RenderSystem, NULL, vertexSize, numVertex, vertexFormat, flags );
}

/************************************************************************************************/
/*
 * ���_�o�b�t�@�𐶐�����
 * @param		vertexSize		���_�T�C�Y
 * @param		numVertex		���_��
 * @param		vertexFormat	���_�t�H�[�}�b�g
 * @param		flags			�t���O
 * @return						���_�o�b�t�@�̃|�C���^
 */
/************************************************************************************************/
KsVertexBuffer* KsHardwareBufferManagerGL::createVertexBuffer( void* pData, KsUInt32 vertexSize, KsUInt32 numVertex, KsUInt32 vertexFormat, KsUInt32 flags )
{
	return ksNew KsVertexBufferGL( m_RenderSystem, pData, vertexSize, numVertex, vertexFormat, flags );
}

/************************************************************************************************/
/*
 * �C���f�b�N�X�o�b�t�@�𐶐�����
 * @param		numIndex		�C���f�b�N�X��
 * @param		flags			�t���O
 * @return						�C���f�b�N�X�o�b�t�@�̃|�C���^
 */
/************************************************************************************************/
KsIndexBuffer* KsHardwareBufferManagerGL::createIndexBuffer( KsUInt32 numIndex, KsUInt32 indexFormat, KsUInt32 flags )
{
	return ksNew KsIndexBufferGL( m_RenderSystem, NULL, 0, numIndex, indexFormat, flags );
}

/************************************************************************************************/
/*
 * �C���f�b�N�X�o�b�t�@�𐶐�����
 * @param		numIndex		�C���f�b�N�X��
 * @param		flags			�t���O
 * @return						�C���f�b�N�X�o�b�t�@�̃|�C���^
 */
/************************************************************************************************/
KsIndexBuffer* KsHardwareBufferManagerGL::createIndexBuffer( void* pData, KsUInt32 size, KsUInt32 numIndex, KsUInt32 indexFormat, KsUInt32 flags )
{
	return ksNew KsIndexBufferGL( m_RenderSystem, pData, size, numIndex, indexFormat, flags );
}

/************************************************************************************************/
/*
 * �萔�o�b�t�@�𐶐�����
 * @param	pData				[in] �f�[�^�ǂݍ��ݗp�̃|�C���^
 * @param	size				[in] �f�[�^�T�C�Y
 * @param	flags				[in] �t���O
 * @return						�萔�o�b�t�@�̃|�C���^
 */
 /************************************************************************************************/
KsConstantBuffer* KsHardwareBufferManagerGL::createConstantBuffer( KsUInt32 size, KsUInt32 flags )
{
	return ksNew KsConstantBufferGL( m_RenderSystem, NULL, size, flags );
}

/************************************************************************************************/
/*
 * �萔�o�b�t�@�𐶐�����
 * @param	size				[in] �o�b�t�@�T�C�Y
 * @param	flags				[in] �t���O
 * @return						�萔�o�b�t�@�̃|�C���^
 */
 /************************************************************************************************/
KsConstantBuffer* KsHardwareBufferManagerGL::createConstantBuffer( void* pData, KsUInt32 size, KsUInt32 flags )
{
	return ksNew KsConstantBufferGL( m_RenderSystem, pData, size, flags );
}


ksNS_KS_END

