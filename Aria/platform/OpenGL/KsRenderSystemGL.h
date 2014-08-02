/************************************************************************************************/
/** 
 * @file		KsRenderSystemGL.h
 * @brief		OpenGL�`��V�X�e��
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0
 */
/************************************************************************************************/
#ifndef __KSRENDERSYSTEMGL_H__
#define __KSRENDERSYSTEMGL_H__

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
 * @class		KsRenderSystemGL
 * @brief		DirectX�p�̕`��V�X�e��
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 */
/************************************************************************************************/
class ksENGINE_API KsRenderSystemGL : public KsRenderSystem
{
	public:
		/**
		 * �R���X�g���N�^
		 */
											KsRenderSystemGL();

		/**
		 * �R���X�g���N�^
		 * @param		pParam				�����p�����[�^
		 */
											KsRenderSystemGL( void* pParam );

		/**
		 * �f�X�g���N�^
		 */
		virtual								~KsRenderSystemGL();

		/**
		 * ����������
		 * @param		hWnd				�E�C���h�E�̃n���h��
		 * @retval		ksTRUE				����������
		 * @retval		ksFALSE				���������s
		 */
		virtual KsBool						initialize( void* pParam );

		/**
		 * �㏈��
		 * @retval		ksTRUE				�㏈������
		 * @retval		ksFALSE				�㏈�����s
		 */
		virtual KsBool						terminate();

		/**
		 * �V�[�����N���A����
		 * @param		flags				�`��t���O
		 * @param		color				�N���A�[�J���[
		 * @param		depth				�f�B�v�X�N���A����l
		 * @param		stencil				�X�e���V���N���A����l
		 */
        virtual void						clearScene( KsUInt32 flags, KsColor color, KsReal depth, KsUInt32 stencil ){}

		/**
		 * �V�[���`��J�n
		 * @param		flags				�`��t���O
		 * @param		color				�N���A�[�J���[
		 * @param		depth				�f�B�v�X�N���A����l
		 * @param		stencil				�X�e���V���N���A����l
		 */
		virtual void						beginScene( KsUInt32 flags, KsColor color, KsReal depth, KsUInt32 stencil ){}

		/**
		 * �V�[���`��I��
		 */
		virtual void						endScene(){}

		/**
		 * �`��o�b�t�@�ƕ\���o�b�t�@�����ւ�
		 */
		virtual void						present();

        virtual KsBool                      isMessageLoop();

		/*-------------------------------------<< �v���~�e�B�u�`��@�\�֌W >>--------------------------------------------------*/


		/*------------------------------------------<< �e�N�X�`���֌W >>------------------------------------------------------*/
		/**
		 * �e�N�X�`���𐶐�����
		 * @param		pFileName			�t�@�C����
		 * @param		flags				�����t���O
		 * @return							�e�N�X�`���̃|�C���^
		 */
		virtual KsTexture*					createTextureFromFile( const KsChar* pFileName, KsUInt32 flags );

		/**
		 * �e�N�X�`���𐶐�����
		 * @param		pData				�C���[�W�f�[�^�̃|�C���^
		 * @param		width				�e�N�X�`���̕�
		 * @param		height				�e�N�X�`���̍���
		 * @param		format				�e�N�X�`���t�H�[�}�b�g
		 * @param		flags				�����t���O
		 * @return							�e�N�X�`���̃|�C���^
		 */
		virtual KsTexture*					createTexture( const KS_SUBRESOURCE_DATA* pData, KsUInt32 width, KsUInt32 height, KsUInt32 format, KsUInt32 flags, KsUInt32 usage );
		/**
		 * �C���[�W�f�[�^����e�N�X�`���𐶐�����
		 * @param		pImage				�C���[�W�f�[�^�̃|�C���^
		 * @param		flags				�����t���O
		 * @return							�e�N�X�`���̃|�C���^
		 */
		//virtual KsTexture*					createTexture( KsImage* pImage, KsUInt32 flags );


		virtual KsRenderTarget*				createRenderTarget( KsUInt32 width, KsUInt32 height, ksPIXEL_FORMAT format, KsUInt32 flags ){ return NULL; }
		virtual KsRenderTarget*				createOffscreenTarget( KsUInt32 width, KsUInt32 height, ksPIXEL_FORMAT format, KsUInt32 flags ){ return NULL; }
		virtual KsRenderTargetTexture*		createRenderTargetTexture( KsUInt32 width, KsUInt32 height, ksPIXEL_FORMAT format, KsUInt32 flags ){ return NULL; }
		virtual KsRenderTarget*				createRenderTargetFromFile( KsUInt32 width, KsUInt32 height, ksPIXEL_FORMAT format, const KsChar* pFileName, KsColor color ){ return NULL; }
		virtual KsVertexDeclaration*		createVertexDeclaration( KS_VERTEX_ELEMENT* pVertexElements ){ return NULL; }
		virtual KsRenderTarget*				createRenderTextureView( KsUInt32 width, KsUInt32 height, KsUInt32 format );
		virtual KsRenderTarget*				createDepthStencilView( KsUInt32 width, KsUInt32 height, KsUInt32 textureFormat, KsUInt32 viewFormat, KsUInt32 resFormat );
		virtual KsUnorderedAccessView*		createUnorderedAccessView( KsUInt32 elementSize, KsUInt32 numElements, KsUInt32 format, KsUInt32 flags );
		virtual KsStructuredBuffer*			createStructuredBuffer( KsUInt32 elementSize, KsUInt32 numElements, KsUInt32 format, KsUInt32 flags );
		virtual KsSamplerState*				createSamplerState( const KS_SAMPLER_DESC* pSamplerStateDesc );
		virtual KsBlendState*				createBlendState( const KS_BLEND_DESC* pBlendStateDesc );
		virtual KsRasterizerState*			createRasterizerState( const KS_RASTERIZER_DESC* pRasterizerState );
		virtual KsDepthStencilState*		createDepthStencilState( const KS_DEPTH_STENCIL_DESC* pDepthStencilDesc );
		virtual KsRenderContext*			createDeferredContext();
		//virtual KsCommandList*				createCommandList();

	private:
		KsRenderTarget*						createRenderTargetView();
		KsRenderTarget*						createDepthStencilView();

	private:
        GLFWwindow*                         m_pWindow;
        GLFWmonitor*                        m_pMonitor;
};

ksNS_KS_END

#endif		/* __KSRENDERSYSTEMGL_H__ */


