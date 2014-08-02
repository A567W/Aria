/************************************************************************************************/
/** 
 * @file		KsRenderContextGL.h
 * @brief		�`��R���e�L�X�g(GL�p)
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/
#ifndef __KSRENDERCONTEXTGL_H__
#define __KSRENDERCONTEXTGL_H__

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

/************************************************************************************************/
/**
 * @class		KsRenderContextGL
 * @brief		�`��R���e�L�X�g(GL�p)
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 */
/************************************************************************************************/
class ksENGINE_API KsRenderContextGL : public KsRenderContext
{
		friend class KsRenderSystemGL;

	public:
		static const KsUInt32		KS_RENDER_TARGET_COUNT = 16;

	public:
		/**
		 * �R���X�g���N�^
		 */
									KsRenderContextGL();

		/**
		 * �R���X�g���N�^
		 */
                                    KsRenderContextGL( KsUInt32 commandBufferSize );

		/**
		 * �f�X�g���N�^
		 */
		virtual						~KsRenderContextGL();

		/**
		 * �V�[�����N���A����
		 * @param		flags		�`��t���O
		 * @param		color		�N���A�[�J���[
		 * @param		depth		�f�B�v�X�N���A����l
		 * @param		stencil		�X�e���V���N���A����l
		 */
		virtual void				clearScene( KsUInt32 flags, KsColor color, KsReal depth, KsUInt32 stencil );

		/**
		 * �V�[�����N���A����
		 * @param	numViews		�N���A�[���郌���_�[ �^�[�Q�b�g�̐�
		 * @param	flags			�`��t���O
		 * @param	color			�N���A�[�J���[
		 * @param	depth			�f�B�v�X�N���A����l
		 * @param	stencil			�X�e���V���N���A����l
		 */
		virtual void				clearScenes( KsUInt32 numViews, KsUInt32 flags, KsColor color, KsReal depth, KsUInt32 stencil );

		/**
		 * �[�x�o�b�t�@���N���A����
		 * @param		flags		�N���A�t���O
		 * @param		depth		�f�B�v�X�N���A����l
		 * @param		stencil		�X�e���V���N���A����l
		 */
		virtual void				clearDepthStencil( KsRenderTarget* pTarget, KsUInt32 flags, KsReal depth, KsUInt32 stencil );

		/**
		 * �����_�[�^�[�Q�b�g���Z�b�g����
		 * @param	pRenderTargetView		�`��^�[�Q�b�g
		 * @param	pDepthStencilView		�[�x�X�e���V���^�[�Q�b�g
		 */
		virtual void				setRenderTarget( KsRenderTarget* pRenderTargetView, KsRenderTarget* pDepthStencilView );

		/**
		 * �����_�[�^�[�Q�b�g���Z�b�g����
		 * @param	numViews				�o�C���h���郌���_�[ �^�[�Q�b�g�̐�
		 * @param	pRenderTargetView		�����_�[ �^�[�Q�b�g�̔z��
		 * @param	pDepthStencilView		�[�x�X�e���V���^�[�Q�b�g
		 */
		virtual void				setRenderTargets( KsUInt32 numViews, KsRenderTarget** ppRenderTargetView, KsRenderTarget* pDepthStencilView );

		/**
		 * �r���[�|�[�g���Z�b�g����
		 * @param		pViewport	�r���[�|�[�g�ݒ�
		 */
		virtual void				setViewports( const KsViewport* pViewport );
		
		virtual void				setInputLayout( KsInputLayout* pInputLayout );

		virtual void				setVertexBuffer( const KsVertexBuffer* pBuffer );
		virtual void				setIndexBuffer( const KsIndexBuffer* pBuffer );

		virtual void				setVertexBuffers( KsUInt32 startSlot, KsUInt32 numBuffers, const KsVertexBuffer* pBuffer, const KsUInt32* pStride, const KsUInt32* pOffset );
		virtual void				setIndexBuffer( const KsIndexBuffer* pBuffer, KsUInt32 indexFormat, KsUInt32 offset );
		virtual void				setPrimitiveTopology( KS_PRIMITIVE_TOPOLOGY	type );
		virtual void				setVertexShader( KsVertexShader* pShader );
		virtual void				setPixelShader( KsPixelShader* pShader );
		virtual void				setComputeShader( KsComputeShader* pShader );
		virtual void				setVertexConstantBuffers( KsUInt32 startSlot, KsUInt32 numBuffers, const KsConstantBuffer* pConstantBuffers );
		virtual void				setPixelConstantBuffers( KsUInt32 startSlot, KsUInt32 numBuffers, const KsConstantBuffer* pConstantBuffers );
		virtual void				updateConstantBuffers( KsConstantBuffer* pConstantBuffers, const void* pSrcData );

		virtual void				setComputeConstantBuffer( KsUInt32 startSlot, const KsConstantBuffer* pConstantBuffers );
		virtual void				setComputeTexture( KsUInt32 startSlot, const KsTexture* pTexture );
		virtual void				setComputeTextures( KsUInt32 startSlot, KsUInt32 numTexture, const KsTexture** pTextures );
		virtual void				setComputeTextures( KsUInt32 startSlot, KsUInt32 numTexture, KsTexture** pTextures );

		virtual void				setVertexTexture( KsUInt32 startSlot, KsUInt32 numViews, const KsTexture* pTexture );
		virtual void				setVertexSamplers( KsUInt32 startSlot, KsUInt32 numViews, const KsSamplerState* pSampler );
		virtual void				setPixelTexture( KsUInt32 startSlot, KsUInt32 numViews, const KsTexture* pTexture );
		virtual void				setPixelSamplers( KsUInt32 startSlot, KsUInt32 numViews, const KsSamplerState* pSampler );
		virtual void				draw( KsUInt32 vertexCount, KsUInt32 startVertexLocation );
		virtual void				drawIndexed( KsUInt32 indexCount, KsUInt32 startIndexLocation, KsInt32 baseVertexLocation );

		virtual void				setRasterizerState( KsRasterizerState* pRasterizerState );
		virtual void				setBlendState( KsBlendState* pBlendState, const KsReal blendFactor[ 4 ], KsUInt32 sampleMask );
		virtual void				setDepthStencilState( KsDepthStencilState* pDepthStencilState, KsUInt32 stencilRef );

		virtual KsRenderTarget*		getRenderTarget() { return NULL; }
		virtual KsRenderTarget*		getDepthStencil() { return NULL; }
		virtual KsRenderTarget*		getRenderTarget( KsUInt32 index ) { return NULL; }

		virtual void				setUnorderedAccessViews( KsUInt32 startSlot, KsUInt32 numUAVs, KsUnorderedAccessView** ppUnorderedAccessViews, const KsUInt32* pUAVInitialCounts );
		virtual void				dispatch( KsUInt32 threadGroupCountX, KsUInt32 threadGroupCountY, KsUInt32 threadGroupCountZ );

		virtual void				read( KsBufferObject* pBuffer, void* pData, KsUInt32 size );
		virtual void				write( KsBufferObject* pBuffer, void* pData, KsUInt32 size, KsUInt32 flags );
		virtual void*				map( KsBufferObject* pBuffer, KsUInt32 flags );
		virtual void				unmap( KsBufferObject* pBuffer );

		virtual void				clearState();
		virtual KsBool				finishCommandList( KsBool restoreDeferredContextState, KsCommandList* pCommandList );
		virtual void				executeCommandList( KsCommandList* pCommandList, KsBool restoreDeferredContextState );
	public:
        KsByte*                     m_pCommandBuffer;
        KsUInt32                    m_commandBufferSize;
};

ksNS_KS_END

#endif		/* __KSRENDERCONTEXTGL_H__ */



