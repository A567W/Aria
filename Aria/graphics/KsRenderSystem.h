/************************************************************************************************/
/** 
 * @file		KsRenderSystem.h
 * @brief		描画システム
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0
 */
/************************************************************************************************/
#ifndef __KSRENDERSYSTEM_H__
#define __KSRENDERSYSTEM_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                           */
/*==============================================================================================*/
#include "KsRect.h"
#include "KsColor.h"
#include "KsViewport.h"
#include "KsTexture.h"
#include "ksImage.h"
#include "KsVertexBuffer.h"
#include "KsStructuredBuffer.h"
#include "KsVertexDeclaration.h"
#include "KsIndexBuffer.h"
#include "KsTextureManager.h"
#include "KsRenderTarget.h"
#include "KsRenderTargetTexture.h"
#include "KsHardwareBufferManager.h"
#include "KsShaderManager.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class		KsRenderSystem
 * @brief		ベース描画システム
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @note		Windowsでマルチウインドウの場合は複数持つために、シングルトンには,しない
 */
/************************************************************************************************/
class ksENGINE_API KsRenderSystem : public KsSingleton< KsRenderSystem >
{
	public:
		/**
		 * シングルトンの参照を取得
		 * @return							シングルトンの参照
		 */
		static KsRenderSystem&				getInstance();
		
		/**
		 * シングルトンのポインタを取得
		 * @return							シングルトンのポインタ
		 */
		static KsRenderSystem*				getInstancePtr();

	public:
		/**
		 * コンストラクタ
		 */
											KsRenderSystem();

		/**
		 * デストラクタ
		 */
		virtual								~KsRenderSystem();

		/**
		 * 初期化処理
		 * @param		hWnd				ウインドウのハンドル
		 * @retval		ksTRUE				初期化成功
		 * @retval		ksFALSE				初期化失敗
		 */
		virtual KsBool						initialize( void* pParam ) = 0;

		/**
		 * 後処理
		 * @retval		ksTRUE				後処理成功
		 * @retval		ksFALSE				後処理失敗
		 */
		virtual KsBool						terminate() = 0;
		

		/**
		 * シーンをクリアする
		 * @param		flags				描画フラグ
		 * @param		color				クリアーカラー
		 * @param		depth				ディプスクリアする値
		 * @param		stencil				ステンシルクリアする値
		 */
		virtual void						clearScene( KsUInt32 flags, KsColor color, KsReal depth, KsUInt32 stencil ) = 0;

		/**
		 * シーン描画開始
		 * @param		flags				描画フラグ
		 * @param		color				クリアーカラー
		 * @param		depth				ディプスクリアする値
		 * @param		stencil				ステンシルクリアする値
		 */
		virtual void						beginScene( KsUInt32 flags, KsColor color, KsReal depth, KsUInt32 stencil ) = 0;

		/**
		 * シーン描画終了
		 */
		virtual void						endScene() = 0;

		/**
		 * 描画バッファと表示バッファを入れ替え
		 */
		virtual void						present() = 0;

		/**
		 * ビューポートをセットする
		 * @param		pViewport			ビューポート設定
		 */
		virtual void						setViewport( const KsViewport* pViewport ) = 0;

		/**
		 * フォグをセットする
		 */
		virtual void						setFog( ksFOG_MODE mode, KsColor color, KsReal start, KsReal end, KsReal density ) = 0;

		/*-------------------------------------<< プリミティブ描画機能関係 >>--------------------------------------------------*/
		/**
		 * ラインを描画(2D)
		 * @param		x					X座標
		 * @param		y					Y座標
		 * @param		color				色
		 */
		//virtual void						drawLine( KsInt16 x0, KsInt16 y0, KsInt16 x1, KsInt16 y1, KsUInt32 color ) = 0;

		/**
		 * 短形を描画
		 * @param		x					X座標
		 * @param		y					Y座標
		 * @param		w					幅
		 * @param		h					高さ
		 * @param		color				色
		 */
		virtual void						drawRect( KsReal x, KsReal y, KsReal w, KsReal h, KsColor color ) = 0;

		/**
		 * テクスチャ付き短形を描画
		 * @param		x					X座標
		 * @param		y					Y座標
		 * @param		w					幅
		 * @param		h					高さ
		 * @param		tx					X座標
		 * @param		ty					Y座標
		 * @param		tw					幅
		 * @param		th					高さ
		 * @param		color				色
		 * @param		pTexture			テクスチャ
		 */
		virtual void						drawRectEx( KsReal x, KsReal y, KsReal w, KsReal h, KsReal tx, KsReal ty, KsReal tw, KsReal th, KsColor color, KsTexture* pTexture ) = 0;

		/**
		 * 短形を描画
		 * @param		x					X座標
		 * @param		y					Y座標
		 * @param		w					幅
		 * @param		h					高さ
		 * @param		u0					テクスチャのX座標
		 * @param		v0					テクスチャのY座標
		 * @param		u1					テクスチャの幅
		 * @param		v1					テクスチャの高さ
		 * @param		color				色
		 * @param		pTexture			テクスチャ
		 */
		//virtual void						drawRectEx( KsInt16 x, KsInt16 y, KsInt16 w, KsInt16 h, KsUInt16 tx, KsUInt16 ty, KsUInt16 tw, KsUInt16 th, KsUInt32 color, KsTexture* pTexture ) = 0;

		/**
		 * スプライト描画
		 * @param		pSpritePrim			スプライトのプリミティブ(4つの頂点配列をわたさないとバグる)
		 */
		//virtual void						drawSprite( KS_SPRITE_PRIM* pSpritePrim ) = 0;

		/**
		 *
		 */
		virtual void						drawIndexedPrimitive( ksPRIMITIVE_TYPE type, KsUInt32 vertexStart, KsUInt32 indexStart, KsUInt32 primitiveCount, KsVertexBuffer* pVertexBuffer, KsIndexBuffer* pIndexBuffer ) = 0;

		virtual void						drawPrimitive( ksPRIMITIVE_TYPE type, KsUInt32 vertexStart, KsUInt32 primitiveCount, KsVertexBuffer* pVertexBuffer ) = 0;

		virtual void						drawPrimitiveUP( ksPRIMITIVE_TYPE type, KsUInt32 primitiveCount, const void* pVertexStreamZeroData, KsUInt32 vertexStreamZeroStride ) = 0;

		virtual void						copyRect( KsRenderTarget* pSrcTarget, const KsRect* pSrcRect, KsRenderTarget* pDstTarget, const KsRect* pDstRect ) = 0;

		/*------------------------------------------<< テクスチャ関係 >>------------------------------------------------------*/
		/**
		 * テクスチャを生成する
		 * @param		pFileName			ファイル名
		 * @param		flags				生成フラグ
		 * @return							テクスチャのポインタ
		 */
		virtual KsTexture*					createTextureFromFile( const KsChar* pFileName, KsUInt32 flags ) = 0;

		/**
		 * イメージデータからテクスチャを生成する
		 * @param		pImage				イメージデータのポインタ
		 * @param		flags				生成フラグ
		 * @return							テクスチャのポインタ
		 */
		//virtual KsTexture*					createTexture( KsImage* pImage, KsUInt32 flags ) = 0;

		/**
		 * テクスチャを生成する
		 * @param		pData				イメージデータのポインタ
		 * @param		width				テクスチャの幅
		 * @param		height				テクスチャの高さ
		 * @param		format				テクスチャフォーマット
		 * @param		flags				生成フラグ
		 * @return							テクスチャのポインタ
		 */
		virtual KsTexture*					createTexture( const KS_SUBRESOURCE_DATA* pData, KsUInt32 width, KsUInt32 height, KsUInt32 format, KsUInt32 flags, KsUInt32 usage ) = 0;

		/**
		 * テクスチャをセットする
		 * @param		statge				テクスチャステージ
		 * @param		pTexture			テクスチャ
		 */
		virtual void						setTexture( KsUInt32 stage, KsTexture* pTexture ) = 0;

		/* レンダーターゲット */
		virtual KsRenderTarget*				getRenderTarget() = 0;
		virtual void						setRenderTarget( KsRenderTarget* pRenderTarget ) = 0;
		virtual KsRenderTarget*				createRenderTarget( KsUInt32 width, KsUInt32 height, ksPIXEL_FORMAT format, KsUInt32 flags ) = 0;
		virtual KsRenderTarget*				createOffscreenTarget( KsUInt32 width, KsUInt32 height, ksPIXEL_FORMAT format, KsUInt32 flags ) = 0;
		virtual KsRenderTargetTexture*		createRenderTargetTexture( KsUInt32 width, KsUInt32 height, ksPIXEL_FORMAT format, KsUInt32 flags ) = 0;
		virtual KsRenderTarget*				createRenderTargetFromFile( KsUInt32 width, KsUInt32 height, ksPIXEL_FORMAT format, const KsChar* pFileName, KsColor color ) = 0;
		virtual KsVertexDeclaration*		createVertexDeclaration( KS_VERTEX_ELEMENT* pVertexElements ) = 0;
		virtual KsRenderTarget*				createRenderTextureView( KsUInt32 width, KsUInt32 height, KsUInt32 format ) = 0;
		virtual KsRenderTarget*				createDepthStencilView( KsUInt32 width, KsUInt32 height, KsUInt32 format, KsUInt32 viewFormat, KsUInt32 resFormat ) = 0;
		virtual KsUnorderedAccessView*		createUnorderedAccessView( KsUInt32 elementSize, KsUInt32 numElements, KsUInt32 format, KsUInt32 flags ) = 0;
		virtual KsStructuredBuffer*			createStructuredBuffer( KsUInt32 elementSize, KsUInt32 numElements, KsUInt32 format, KsUInt32 flags ) = 0;
		virtual void						setVertexDeclaration( KsVertexDeclaration* pVertexDeclaration ) = 0;

		virtual KsSamplerState*				createSamplerState( const KS_SAMPLER_DESC* pSamplerStateDesc ) = 0;
		virtual KsBlendState*				createBlendState( const KS_BLEND_DESC* pBlendStateDesc ) = 0;
		virtual KsRasterizerState*			createRasterizerState( const KS_RASTERIZER_DESC* pRasterizerState ) = 0;
		virtual KsDepthStencilState*		createDepthStencilState( const KS_DEPTH_STENCIL_DESC* pDepthStencilDesc ) = 0;
		virtual KsRenderContext*			createDeferredContext() = 0;
		virtual KsRenderCommandList*		createCommandList() = 0;
		
		/*-------------------------------------<< レンダーステート関係 >>--------------------------------------------------*/

		/**
		 * サンプラーステートをセットする
		 * @param		sampler				サンプラー番号
		 * @param		state				ステートの種類
		 * @param		value				ステートに対応する値
		 */
		virtual void						setSamplerState( KsUInt32 sampler, ksSAMPLER_STATE_TYPE state, KsUInt32 value ) = 0;

		/**
		 * トランスフォームする
		 * @param		state				トランスフォームのモード
		 * @param		pMatrix				変換マトリックス
		 */
		virtual void						setTransform( ksTRANSFORM_STATE state, const KsMatrix4x4* pMatrix ) = 0;

		/**
		 * 基本設定で3Dモードを初期化する
		 */
		virtual void						auto2DMode() = 0;

		/**
		 * 基本設定で3Dモードを初期化する
		 */
		virtual void						auto3DMode() = 0;

		/**
		 * 描画コンテキストを取得する
		 */
		KsRenderContext*					getRenderContex() { return m_pRenderContext; }

	protected:
		KsMatrix4x4							m_viewMatrix;					/**< ビューマトリックス				*/
		KsMatrix4x4							m_worldMatrix;					/**< ワールドマトリックス				*/
		KsMatrix4x4							m_textureMatrix;				/**< テクスチャマトリックス				*/
		KsTextureState						m_textureState;					/**< 現在のテクスチャステート			*/
		KsUInt32							m_clearFlags;					/**< クリアフラグ						*/
		KsColor								m_clearColor;					/**< バッファのクリアカラーセット		*/
		KsInt32								m_clearDepth;					/**< Zバッファのクリア値セット			*/
		KsInt32								m_clearStencil;					/**< ステンシルバッファのクリア値セット	*/
		KsRenderContext*					m_pRenderContext;				/**< 描画コンテキスト					*/
		KsTextureManager*					m_pTextureManager;				/**< テクスチャマネージャ				*/
		KsHardwareBufferManager*			m_pHardwareBufferManager;		/**< ハードウェアバッファマネージャ		*/
		KsShaderManager*					m_pShaderManager;				/**< シェーダーマネージャ				*/
};

ksNS_KS_END

#endif		/* __KSRENDERSYSTEM_H__ */

