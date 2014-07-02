/************************************************************************************************/
/** 
 * @file		KsRasterizerState.h
 * @brief		DirectX用深度ステンシルステート
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0
 */
/************************************************************************************************/
#ifndef __KSRASTERIZERSTATE_H__
#define __KSRASTERIZERSTATE_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                           */
/*==============================================================================================*/
#include "KsRenderType.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/
#define KS_DEFAULT_BLEND_FACTOR_ALPHA			( 1.0f )
#define KS_DEFAULT_BLEND_FACTOR_BLUE			( 1.0f )
#define KS_DEFAULT_BLEND_FACTOR_GREEN			( 1.0f )
#define KS_DEFAULT_BLEND_FACTOR_RED				( 1.0f )
#define KS_DEFAULT_BORDER_COLOR_COMPONENT		( 0.0f )
#define	KS_DEFAULT_DEPTH_BIAS					( 0 )
#define KS_DEFAULT_DEPTH_BIAS_CLAMP				( 0.0f )
#define KS_DEFAULT_MAX_ANISOTROPY				( 16 )
#define KS_DEFAULT_MIP_LOD_BIAS					( 0.0f )
#define	KS_DEFAULT_RENDER_TARGET_ARRAY_INDEX	( 0 )
#define KS_DEFAULT_BLEND_FACTOR_ALPHA			( 1.0f )
#define KS_DEFAULT_SLOPE_SCALED_DEPTH_BIAS		( 0.0f )
#define	KS_DEFAULT_STENCIL_READ_MASK			( 0xff )

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

typedef enum KS_FILL_MODE
{	
	KS_FILL_WIREFRAME	= 2,
	KS_FILL_SOLID	= 3

}KS_FILL_MODE;

typedef enum KS_CULL_MODE
{
	KS_CULL_NONE	= 1,
	KS_CULL_FRONT	= 2,
	KS_CULL_BACK	= 3

}KS_CULL_MODE;


typedef struct KS_RASTERIZER_DESC
{
	KS_FILL_MODE FillMode;
	KS_CULL_MODE CullMode;
	KsBool FrontCounterClockwise;
	KsInt32 DepthBias;
	KsReal DepthBiasClamp;
	KsReal SlopeScaledDepthBias;
	KsBool DepthClipEnable;
	KsBool ScissorEnable;
	KsBool MultisampleEnable;
	KsBool AntialiasedLineEnable;

}KS_RASTERIZER_DESC;

/************************************************************************************************/
/**
 * @class		KsRasterizerState
 * @brief		深度ステンシルステート
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @note		参照カウンタつき
 */
/************************************************************************************************/
class ksENGINE_API KsRasterizerState
{
	public:
		/**
		 * コンストラクタ
		 */
											KsRasterizerState();

		/**
		 * コンストラクタ
		 */
											KsRasterizerState( const KS_RASTERIZER_DESC* pRasterizerState );

		/**
		 * コンストラクタ
		 */
											KsRasterizerState( const KS_RASTERIZER_DESC& pRasterizerState );

		/**
		 * デストラクタ
		 */
		virtual								~KsRasterizerState();

		/**
		 * テクスチャの破棄
		 */
		virtual void						destroy() = 0;

		/**
		 * リソースを取得する
		 * @return							 リソース
		 */
		virtual void*						getRenderResource() = 0;

	protected:
		KS_RASTERIZER_DESC					m_rasterizerState;

	public:
		static const KS_RASTERIZER_DESC		DEFAULT;
};

ksNS_KS_END

#endif		/* __KSRASTERIZERSTATE_H__ */

