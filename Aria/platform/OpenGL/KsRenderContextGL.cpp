/************************************************************************************************/
/** 
 * @file		KsRenderContextGL.cpp
 * @brief		�`��R���e�L�X�g(GL�p)
 * @author		A567W
 * @date		2004/08/17
 * @since		----/--/--
 * @version		1.0
 */
/************************************************************************************************/

/*==============================================================================================*/
/*                                 << �C���N���[�h >>											 */
/*==============================================================================================*/
#include "KsRenderContextGL.h"

#include "KsCommandListGL.h"

/*==============================================================================================*/
/*									  << �錾 >>										    		*/
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/*
 * �R���X�g���N�^
 */
/************************************************************************************************/
KsRenderContextGL::KsRenderContextGL()
    : m_pCommandBuffer( ksNULLPTR )
    , m_commandBufferSize( 0 )
{
}

/************************************************************************************************/
/*
 * �R���X�g���N�^
 */
/************************************************************************************************/
KsRenderContextGL::KsRenderContextGL( KsUInt32 commandBufferSize )
    : m_commandBufferSize( commandBufferSize )
{
    m_pCommandBuffer = ksNew KsByte[ commandBufferSize ];
}

/************************************************************************************************/
/*
 * �f�X�g���N�^
 */
/************************************************************************************************/
KsRenderContextGL::~KsRenderContextGL()
{
    ksDELETEARRAY( m_pCommandBuffer );
}

/************************************************************************************************/
/*
 * �V�[�����N���A����
 * @param		flags		�`��t���O
 * @param		color		�N���A�[�J���[
 * @param		depth		�f�B�v�X�N���A����l
 * @param		stencil		�X�e���V���N���A����l
 */
/************************************************************************************************/
void KsRenderContextGL::clearScene( KsUInt32 flags, KsColor color, KsReal depth, KsUInt32 stencil )
{
}

/************************************************************************************************/
/*
 * �[�x�o�b�t�@���N���A����
 * @param		flags		�N���A�t���O
 * @param		depth		�f�B�v�X�N���A����l
 * @param		stencil		�X�e���V���N���A����l
 */
/************************************************************************************************/
void KsRenderContextGL::clearDepthStencil( KsRenderTarget* pTarget, KsUInt32 flags, KsReal depth, KsUInt32 stencil )
{
}

/************************************************************************************************/
/*
 * �V�[�����N���A����
 * @param	numViews		�N���A�[���郌���_�[ �^�[�Q�b�g�̐�
 * @param	flags			�`��t���O
 * @param	color			�N���A�[�J���[
 * @param	depth			�f�B�v�X�N���A����l
 * @param	stencil			�X�e���V���N���A����l
 */
/************************************************************************************************/
void KsRenderContextGL::clearScenes( KsUInt32 numViews, KsUInt32 flags, KsColor color, KsReal depth, KsUInt32 stencil )
{
}

/************************************************************************************************/
/*
 * �����_�[�^�[�Q�b�g���Z�b�g����
 * @param	pRenderTargetView		�`��^�[�Q�b�g
 * @param	pDepthStencilView		�[�x�X�e���V���^�[�Q�b�g
 */
/************************************************************************************************/
void KsRenderContextGL::setRenderTarget( KsRenderTarget* pRenderTargetView, KsRenderTarget* pDepthStencilView )
{
}

/************************************************************************************************/
/*
 * @param	numViews				�o�C���h���郌���_�[ �^�[�Q�b�g�̐�
 * @param	pRenderTargetView		�����_�[ �^�[�Q�b�g�̔z��
 * @param	pDepthStencilView		�[�x�X�e���V���^�[�Q�b�g
 */
/************************************************************************************************/
void KsRenderContextGL::setRenderTargets( KsUInt32 numViews, KsRenderTarget** ppRenderTargetView, KsRenderTarget* pDepthStencilView )
{
}

/************************************************************************************************/
/*
 * �r���[�|�[�g���Z�b�g����
 * @param		pViewport			�r���[�|�[�g�ݒ�
 */
/************************************************************************************************/
void KsRenderContextGL::setViewports( const KsViewport* pViewport )
{
}

/************************************************************************************************/
/*
 * �C���f�b�N�X�o�b�t�@���Z�b�g����
 */
/************************************************************************************************/
void KsRenderContextGL::setVertexBuffer( const KsVertexBuffer* pBuffer )
{
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsRenderContextGL::setIndexBuffer( const KsIndexBuffer* pBuffer )
{
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsRenderContextGL::setVertexBuffers( KsUInt32 startSlot, KsUInt32 numBuffers, const KsVertexBuffer* pBuffer, const KsUInt32* pStride, const KsUInt32* pOffset )
{
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsRenderContextGL::setIndexBuffer( const KsIndexBuffer* pBuffer, KsUInt32 indexFormat, KsUInt32 offset )
{
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsRenderContextGL::setInputLayout( KsInputLayout* pInputLayout )
{
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsRenderContextGL::setPrimitiveTopology( KS_PRIMITIVE_TOPOLOGY type )
{
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsRenderContextGL::setVertexShader( KsVertexShader* pShader )
{
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsRenderContextGL::setPixelShader( KsPixelShader* pShader )
{
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsRenderContextGL::setComputeShader( KsComputeShader* pShader )
{
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsRenderContextGL::draw( KsUInt32 vertexCount, KsUInt32 startVertexLocation )
{
    //�@�`��
    //glDrawElements( GL_TRIANGLE_STRIP, sizeof(indexes), GL_UNSIGNED_SHORT, NULL );
    //glDrawElements( GL_TRIANGLE_STRIP, sizeof(indexes), GL_UNSIGNED_INT, NULL );
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsRenderContextGL::drawIndexed( KsUInt32 indexCount, KsUInt32 startIndexLocation, KsInt32 baseVertexLocation )
{
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsRenderContextGL::setVertexConstantBuffers( KsUInt32 startSlot, KsUInt32 numBuffers, const KsConstantBuffer* pConstantBuffers )
{
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsRenderContextGL::setPixelConstantBuffers( KsUInt32 startSlot, KsUInt32 numBuffers, const KsConstantBuffer* pConstantBuffers )
{
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsRenderContextGL::updateConstantBuffers( KsConstantBuffer* pConstantBuffers, const void* pSrcData )
{
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsRenderContextGL::setComputeConstantBuffer( KsUInt32 startSlot, const KsConstantBuffer* pConstantBuffers )
{
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsRenderContextGL::setComputeTexture( KsUInt32 startSlot, const KsTexture* pTexture )
{
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsRenderContextGL::setComputeTextures( KsUInt32 startSlot, KsUInt32 numTexture, const KsTexture** pTextures )
{
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsRenderContextGL::setComputeTextures( KsUInt32 startSlot, KsUInt32 numTexture, KsTexture** pTextures )
{
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsRenderContextGL::setVertexTexture( KsUInt32 startSlot, KsUInt32 numViews, const KsTexture* pTexture )
{
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsRenderContextGL::setVertexSamplers( KsUInt32 startSlot, KsUInt32 numViews, const KsSamplerState* pSampler )
{
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsRenderContextGL::setPixelTexture( KsUInt32 startSlot, KsUInt32 numViews, const KsTexture* pTexture )
{
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsRenderContextGL::setPixelSamplers( KsUInt32 startSlot, KsUInt32 numViews, const KsSamplerState* pSampler )
{
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsRenderContextGL::setRasterizerState( KsRasterizerState* pRasterizerState )
{
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsRenderContextGL::setBlendState( KsBlendState* pBlendState, const KsReal blendFactor[ 4 ], KsUInt32 sampleMask )
{
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsRenderContextGL::setDepthStencilState( KsDepthStencilState* pDepthStencilState, KsUInt32 stencilRef )
{
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsRenderContextGL::setUnorderedAccessViews( KsUInt32 startSlot, KsUInt32 numUAVs, KsUnorderedAccessView** ppUnorderedAccessViews, const KsUInt32* pUAVInitialCounts )
{
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsRenderContextGL::dispatch( KsUInt32 threadGroupCountX, KsUInt32 threadGroupCountY, KsUInt32 threadGroupCountZ )
{
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsRenderContextGL::read( KsBufferObject* pBuffer, void* pData, KsUInt32 size )
{
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsRenderContextGL::write( KsBufferObject* pBuffer, void* pData, KsUInt32 size, KsUInt32 flags )
{
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void* KsRenderContextGL::map( KsBufferObject* pBuffer, KsUInt32 flags )
{
	return NULL;
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsRenderContextGL::unmap( KsBufferObject* pBuffer )
{
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsRenderContextGL::clearState()
{
}


/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
KsBool KsRenderContextGL::finishCommandList( KsBool restoreDeferredContextState, KsCommandList* pCommandList )
{
    ksUNREFERENCED_PARAMETER( restoreDeferredContextState );
    ksUNREFERENCED_PARAMETER( pCommandList );

	return ksTRUE;
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsRenderContextGL::executeCommandList( KsCommandList* pCommandList, KsBool restoreDeferredContextState )
{
    ksUNREFERENCED_PARAMETER( restoreDeferredContextState );

    KsCommandListGL*    pCommandListGL = r_cast<KsCommandListGL*>( pCommandList );
}


ksNS_KS_END
