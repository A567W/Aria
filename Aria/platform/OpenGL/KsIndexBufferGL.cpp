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

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                            */
/*==============================================================================================*/
#include "KsIndexBufferGL.h"

/*==============================================================================================*/
/*                                     << ��` >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << �錾 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/*
 * �C���f�b�N�X�o�b�t�@�𐶐�����
 * @param	pDevice			�f�o�C�X
 * @param	numIndex		�C���f�b�N�X�̐�
 * @param	flags			�t���O
 */
/************************************************************************************************/
KsIndexBufferGL::KsIndexBufferGL( KsRenderSystemGL* pRenderSystem, void* pData, KsUInt32 size, KsUInt32 numIndex, KsUInt32 indexFormat, KsUInt32 flags )
	: m_pRenderSystem( pRenderSystem )
    , m_indexBuffer( 0 )
{
	create( pRenderSystem, pData, size, numIndex, indexFormat, flags );
}

/************************************************************************************************/
/*
 * �f�X�g���N�^
 */
/************************************************************************************************/
KsIndexBufferGL::~KsIndexBufferGL()
{
    if( m_indexBuffer )
    {
        glDeleteBuffers( 1, &m_indexBuffer );
        m_indexBuffer = 0;
    }
}

/************************************************************************************************/
/*
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
/************************************************************************************************/
KsBool KsIndexBufferGL::create( KsRenderSystemGL* pRenderSystem, void* pData, KsUInt32 size, KsUInt32 numIndex, KsUInt32 indexFormat, KsUInt32 flags )
{
	m_numIndex = numIndex;

	//�@���_�o�b�t�@�̍쐬
    glGenBuffers( 1, &m_indexBuffer );
    glBindBuffer( GL_ARRAY_BUFFER, m_indexBuffer );
    glBufferData( GL_ARRAY_BUFFER, numIndex * indexFormat, pData, GL_STATIC_DRAW );
    glBindBuffer( GL_ARRAY_BUFFER, 0 );

	return ksTRUE;
}

/************************************************************************************************/
/*
 * �j������
 */
/************************************************************************************************/
void KsIndexBufferGL::destroy()
{
	delete this;
}

/************************************************************************************************/
/*
 * �C���f�b�N�X�o�b�t�@�����b�N����
 * @param	pContext		�`��R���e�L�X�g
 * @param	flags			���b�N�t���O
 * @return					���b�N�����o�b�t�@�̐擪�|�C���^
 */
/************************************************************************************************/
void* KsIndexBufferGL::lock( const KsRenderContext* pContext, KsUInt32 flags )
{
	return NULL;
}

/************************************************************************************************/
/*
 * �C���f�b�N�X�o�b�t�@�̃��b�N����������
 */
/************************************************************************************************/
void KsIndexBufferGL::unlock( const KsRenderContext* pContext )
{
}

/************************************************************************************************/
/*
 * �C���f�b�N�X�o�b�t�@����̓ǂݍ���
 * @param	pContext		�`��R���e�L�X�g
 * @param	pData			�f�[�^�ǂݍ��ݗp�̃|�C���^
 * @param	size			�f�[�^�T�C�Y
 */
/************************************************************************************************/
void KsIndexBufferGL::read( const KsRenderContext* pContext, void* pData, KsUInt32 size )
{
}

/************************************************************************************************/
/*
 * �C���f�b�N�X�o�b�t�@�ւ̏�������
 * @param	pContext		�`��R���e�L�X�g
 * @param	pData			�f�[�^�ǂݍ��ݗp�̃|�C���^
 * @param	size			�f�[�^�T�C�Y
 */
/************************************************************************************************/
void KsIndexBufferGL::write( const KsRenderContext* pContext, void* pData, KsUInt32 size )
{
}

ksNS_KS_END

