/*************************************************************************************************/
/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2014 A567W
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 * 
 * @file	KsRenderContext.h
 * @brief	描画コンテキスト
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/
#ifndef __KSRENDERCONTEXT_H__
#define __KSRENDERCONTEXT_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsColor.h"
#include "KsTexture.h"
#include "KsViewport.h"
#include "KsBlendState.h"
#include "KsDepthStencilState.h"
#include "KsRasterizerState.h"
#include "KsSamplerState.h"
#include "KsInputLayout.h"
#include "KsIndexBuffer.h"
#include "KsVertexBuffer.h"
#include "KsConstantBuffer.h"
#include "KsUnorderedAccessView.h"
#include "KsTexture.h"
#include "KsRenderTarget.h"
#include "KsRenderCommandList.h"
#include "KsEffect.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/*************************************************************************************************/
/**
 * @class	KsRenderContext
 * @brief	描画コンテキスト
 * @author	A567W
 */
/*************************************************************************************************/
class ksENGINE_API KsRenderContext
{
	public:
		/**
		 *  コンストラクタ
		 */
									KsRenderContext(){}

		/**
		 * デストラクタ
		 */
		virtual						~KsRenderContext(){}

		/**
		 * シーンをクリアする
		 * @param		flags		描画フラグ
		 * @param		color		クリアーカラー
		 * @param		depth		ディプスクリアする値
		 * @param		stencil		ステンシルクリアする値
		 */
		virtual void				clearScene( KsUInt32 flags, KsColor color, KsReal depth, KsUInt32 stencil ) = 0;

		/**
		 * シーンをクリアする
		 * @param	numViews		クリアーするレンダー ターゲットの数
		 * @param	flags			描画フラグ
		 * @param	color			クリアーカラー
		 * @param	depth			ディプスクリアする値
		 * @param	stencil			ステンシルクリアする値
		 */
		virtual void				clearScenes( KsUInt32 numViews, KsUInt32 flags, KsColor color, KsReal depth, KsUInt32 stencil ) = 0;

		/**
		 * 深度バッファをクリアする
		 * @param		flags		クリアフラグ
		 * @param		depth		ディプスクリアする値
		 * @param		stencil		ステンシルクリアする値
		 */
		virtual void				clearDepthStencil( KsRenderTarget* pTarget, KsUInt32 flags, KsReal depth, KsUInt32 stencil ) = 0;

		/**
		 * レンダーターゲットをセットする
		 * @param	pRenderTargetView		描画ターゲット
		 * @param	pDepthStencilView		深度ステンシルターゲット
		 */
		virtual void				setRenderTarget( KsRenderTarget* pRenderTargetView, KsRenderTarget* pDepthStencilView ) = 0;

		/**
		 * レンダーターゲットをセットする
		 * @param	pRenderTargetView		描画ターゲット
		 * @param	pDepthStencilView		深度ステンシルターゲット
		 */
		virtual void				setRenderTargets( KsUInt32 numViews, KsRenderTarget** ppRenderTargetView, KsRenderTarget* pDepthStencilView ) = 0;

		/**
		 * ビューポートをセットする
		 * @param		pViewport	ビューポート設定
		 */
		virtual void				setViewports( const KsViewport* pViewport ) = 0;
		virtual void				setInputLayout( KsInputLayout* pInputLayout ) = 0;

		virtual void				setVertexBuffer( const KsVertexBuffer* pBuffer ) = 0;
		virtual void				setIndexBuffer( const KsIndexBuffer* pBuffer ) = 0;

		virtual void				setVertexBuffers( KsUInt32 startSlot, KsUInt32 numBuffers, const KsVertexBuffer* pBuffer, const KsUInt32* pStride, const KsUInt32* pOffset ) = 0;
		virtual void				setIndexBuffer( const KsIndexBuffer* pBuffer, KsUInt32 indexFormat, KsUInt32 offset ) = 0;
		virtual void				setPrimitiveTopology( KS_PRIMITIVE_TOPOLOGY	type ) = 0;
		virtual void				setVertexShader( KsVertexShader* pShader ) = 0;
		virtual void				setPixelShader( KsPixelShader* pShader ) = 0;
		virtual void				setComputeShader( KsComputeShader* pShader ) = 0;

		virtual void				setVertexConstantBuffers( KsUInt32 startSlot, KsUInt32 numBuffers, const KsConstantBuffer* pConstantBuffers ) = 0;
		virtual void				setPixelConstantBuffers( KsUInt32 startSlot, KsUInt32 numBuffers, const KsConstantBuffer* pConstantBuffers ) = 0;

		virtual void				updateConstantBuffers( KsConstantBuffer* pConstantBuffers, const void* pSrcData ) = 0;

		virtual void				setComputeConstantBuffer( KsUInt32 startSlot, const KsConstantBuffer* pConstantBuffers ) = 0;
		virtual void				setComputeTexture( KsUInt32 startSlot, const KsTexture* pTexture ) = 0;
		virtual void				setComputeTextures( KsUInt32 startSlot, KsUInt32 numTexture, const KsTexture** pTextures ) = 0;
		virtual void				setComputeTextures( KsUInt32 startSlot, KsUInt32 numTexture, KsTexture** pTextures ) = 0;

		virtual void				setVertexTexture( KsUInt32 startSlot, KsUInt32 numViews, const KsTexture* pTexture ) = 0;
		virtual void				setVertexSamplers( KsUInt32 startSlot, KsUInt32 numViews, const KsSamplerState* pSampler ) = 0;
		virtual void				setPixelTexture( KsUInt32 startSlot, KsUInt32 numViews, const KsTexture* pTexture ) = 0;
		virtual void				setPixelSamplers( KsUInt32 startSlot, KsUInt32 numViews, const KsSamplerState* pSampler ) = 0;

		virtual void				setRasterizerState( KsRasterizerState* pRasterizerState ) = 0;
		virtual void				setBlendState( KsBlendState* pBlendState, const KsReal blendFactor[ 4 ], KsUInt32 sampleMask ) = 0;
		virtual void				setDepthStencilState( KsDepthStencilState* pDepthStencilState, KsUInt32 stencilRef ) = 0;

		virtual void				draw( KsUInt32 vertexCount, KsUInt32 startVertexLocation ) = 0;
		virtual void				drawIndexed( KsUInt32 indexCount, KsUInt32 startIndexLocation, KsInt32 baseVertexLocation ) = 0;


		virtual KsRenderTarget*		getRenderTarget() = 0;
		virtual KsRenderTarget*		getDepthStencil() = 0;

		virtual void				dispatch( KsUInt32 threadGroupCountX, KsUInt32 threadGroupCountY, KsUInt32 threadGroupCountZ ) = 0;

		virtual void				setUnorderedAccessViews( KsUInt32 startSlot, KsUInt32 numUAVs, KsUnorderedAccessView** ppUnorderedAccessViews, const KsUInt32* pUAVInitialCounts ) = 0;

		virtual void				read( KsBufferObject* pBuffer, void* pData, KsUInt32 size ) = 0;
		virtual void				write( KsBufferObject* pBuffer, void* pData, KsUInt32 size, KsUInt32 flags ) = 0;
		virtual void*				map( KsBufferObject* pBuffer, KsUInt32 flags ) = 0;
		virtual void				unmap( KsBufferObject* pBuffer ) = 0;


		virtual void				clearState() = 0;
		virtual KsBool				finishCommandList( KsBool restoreDeferredContextState, KsRenderCommandList* pCommandList ) = 0;
		virtual void				executeCommandList( KsRenderCommandList* pCommandList, KsBool restoreDeferredContextState ) = 0;
};

ksNS_KS_END

#endif		/* __KSRENDERCONTEXT_H__ */

