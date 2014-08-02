/************************************************************************************************/
/** 
 * @file		KsRenderSystemGL.h
 * @brief		OpenGL描画システム
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0
 */
/************************************************************************************************/
#ifndef __KSRENDERSYSTEMGL_H__
#define __KSRENDERSYSTEMGL_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsCommonGL.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class		KsRenderSystemGL
 * @brief		DirectX用の描画システム
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 */
/************************************************************************************************/
class ksENGINE_API KsRenderSystemGL : public KsRenderSystem
{
	public:
		/**
		 * コンストラクタ
		 */
											KsRenderSystemGL();

		/**
		 * コンストラクタ
		 * @param		pParam				生成パラメータ
		 */
											KsRenderSystemGL( void* pParam );

		/**
		 * デストラクタ
		 */
		virtual								~KsRenderSystemGL();

		/**
		 * 初期化処理
		 * @param		hWnd				ウインドウのハンドル
		 * @retval		ksTRUE				初期化成功
		 * @retval		ksFALSE				初期化失敗
		 */
		virtual KsBool						initialize( void* pParam );

		/**
		 * 後処理
		 * @retval		ksTRUE				後処理成功
		 * @retval		ksFALSE				後処理失敗
		 */
		virtual KsBool						terminate();

		/**
		 * シーンをクリアする
		 * @param		flags				描画フラグ
		 * @param		color				クリアーカラー
		 * @param		depth				ディプスクリアする値
		 * @param		stencil				ステンシルクリアする値
		 */
        virtual void						clearScene( KsUInt32 flags, KsColor color, KsReal depth, KsUInt32 stencil ){}

		/**
		 * シーン描画開始
		 * @param		flags				描画フラグ
		 * @param		color				クリアーカラー
		 * @param		depth				ディプスクリアする値
		 * @param		stencil				ステンシルクリアする値
		 */
		virtual void						beginScene( KsUInt32 flags, KsColor color, KsReal depth, KsUInt32 stencil ){}

		/**
		 * シーン描画終了
		 */
		virtual void						endScene(){}

		/**
		 * 描画バッファと表示バッファを入れ替え
		 */
		virtual void						present();

        virtual KsBool                      isMessageLoop();

		/*-------------------------------------<< プリミティブ描画機能関係 >>--------------------------------------------------*/


		/*------------------------------------------<< テクスチャ関係 >>------------------------------------------------------*/
		/**
		 * テクスチャを生成する
		 * @param		pFileName			ファイル名
		 * @param		flags				生成フラグ
		 * @return							テクスチャのポインタ
		 */
		virtual KsTexture*					createTextureFromFile( const KsChar* pFileName, KsUInt32 flags );

		/**
		 * テクスチャを生成する
		 * @param		pData				イメージデータのポインタ
		 * @param		width				テクスチャの幅
		 * @param		height				テクスチャの高さ
		 * @param		format				テクスチャフォーマット
		 * @param		flags				生成フラグ
		 * @return							テクスチャのポインタ
		 */
		virtual KsTexture*					createTexture( const KS_SUBRESOURCE_DATA* pData, KsUInt32 width, KsUInt32 height, KsUInt32 format, KsUInt32 flags, KsUInt32 usage );
		/**
		 * イメージデータからテクスチャを生成する
		 * @param		pImage				イメージデータのポインタ
		 * @param		flags				生成フラグ
		 * @return							テクスチャのポインタ
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


