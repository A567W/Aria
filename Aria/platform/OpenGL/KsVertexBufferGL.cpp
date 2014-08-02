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

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                           */
/*==============================================================================================*/
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
 * �R���X�g���N�^(���_�o�b�t�@�𐶐�����)
 * @param	pRenderSystem	�`��V�X�e��
 * @param	pData			�f�[�^�ǂݍ��ݗp�̃|�C���^
 * @param	vertexSize		���_�T�C�Y
 * @param	numVertex		���_��
 * @param	vertexFormat	���_�t�H�[�}�b�g
 * @param	flags			�t���O
 */
/************************************************************************************************/
KsVertexBufferGL::KsVertexBufferGL( KsRenderSystemGL* pRenderSystem, void* pData, KsUInt32 vertexSize, KsUInt32 numVertex, KsUInt32 vertexFormat, KsUInt32 flags )
	: m_pRenderSystem( pRenderSystem )
    , m_vertexBuffer( 0 )
{
	create( pRenderSystem, pData, vertexSize, numVertex, vertexFormat, flags );
}

/************************************************************************************************/
/*
 * �f�X�g���N�^
 */
/************************************************************************************************/
KsVertexBufferGL::~KsVertexBufferGL()
{
    if( m_vertexBuffer )
    {
        glDeleteBuffers( 1, &m_vertexBuffer );
        m_vertexBuffer = 0;
    }
}

/************************************************************************************************/
/*
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
/************************************************************************************************/
KsBool KsVertexBufferGL::create( KsRenderSystemGL* pRenderSystem, void* pData, KsUInt32 vertexSize, KsUInt32 numVertex, KsUInt32 vertexFormat, KsUInt32 flags )
{
	m_vertexSize   = vertexSize;
	m_numVertex    = numVertex;
	m_vertexFormat = vertexFormat;

	//�@���_�o�b�t�@�̍쐬
    glGenBuffers( 1, &m_vertexBuffer );
    glBindBuffer( GL_ARRAY_BUFFER, m_vertexBuffer );
    glBufferData( GL_ARRAY_BUFFER, numVertex * vertexSize, pData, GL_STATIC_DRAW );
    glBindBuffer( GL_ARRAY_BUFFER, 0 );

	return ksTRUE;
}

/************************************************************************************************/
/*
 * �j������
 */
/************************************************************************************************/
void KsVertexBufferGL::destroy()
{
	delete this;
}

/************************************************************************************************/
/*
 * ���_�o�b�t�@�����b�N����
 * @param	pContext		�`��R���e�L�X�g
 * @param	flags			���b�N�t���O
 * @return					���b�N�����o�b�t�@�̐擪�|�C���^
 */
/************************************************************************************************/
void* KsVertexBufferGL::lock( const KsRenderContext* pContext, KsUInt32 flags )
{
	return NULL;
}

/************************************************************************************************/
/*
 * ���_�o�b�t�@�̃��b�N����������
 */
/************************************************************************************************/
void KsVertexBufferGL::unlock( const KsRenderContext* pContext )
{
}

/************************************************************************************************/
/*
 * ���_�o�b�t�@����̓ǂݍ���
 * @param	pContext		�`��R���e�L�X�g
 * @param	pData			�f�[�^�ǂݍ��ݗp�̃|�C���^
 * @param	size			�f�[�^�T�C�Y
 */
/************************************************************************************************/
void KsVertexBufferGL::read( const KsRenderContext* pContext, void* pData, KsUInt32 size )
{
}

/************************************************************************************************/
/*
 * ���_�o�b�t�@�ւ̏�������
 * @param	pContext		�`��R���e�L�X�g
 * @param	pData			�f�[�^�ǂݍ��ݗp�̃|�C���^
 * @param	size			�f�[�^�T�C�Y
 */
/************************************************************************************************/
void KsVertexBufferGL::write( const KsRenderContext* pContext, void* pData, KsUInt32 size )
{
}

ksNS_KS_END

