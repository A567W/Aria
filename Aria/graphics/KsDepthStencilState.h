/************************************************************************************************/
/** 
 * @file		KsDepthStencilState.h
 * @brief		深度ステンシルステート
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0
 */
/************************************************************************************************/
#ifndef __KSDEPTHSTENCILSTATE_H__
#define __KSDEPTHSTENCILSTATE_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                           */
/*==============================================================================================*/
#include "KsRenderType.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/
#define	KS_DEFAULT_STENCIL_READ_MASK	( 0xff )
#define	KS_DEFAULT_STENCIL_WRITE_MASK	( 0xff )

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class		KsDepthStencilState
 * @brief		深度ステンシルステート
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @note		参照カウンタつき
 */
/************************************************************************************************/
class ksENGINE_API KsDepthStencilState
{
	public:
		/**
		 * コンストラクタ
		 */
											KsDepthStencilState();

		/**
		 * コンストラクタ
		 */
											KsDepthStencilState( const KS_DEPTH_STENCIL_DESC* pDepthStencilDesc );

		/**
		 * コンストラクタ
		 */
											KsDepthStencilState( const KS_DEPTH_STENCIL_DESC& refDepthStencilDesc );

		/**
		 * デストラクタ
		 */
		virtual								~KsDepthStencilState();

		/**
		 * テクスチャの破棄
		 */
		virtual void						destroy() = 0;

		/**
		 * リソースを取得する
		 * @return							リソース
		 */
		virtual void*						getRenderResource() = 0;

	protected:
		KS_DEPTH_STENCIL_DESC				m_depthStencilDesc;

	public:
		static const KS_DEPTH_STENCIL_DESC	DEFAULT;
		//static KS_BLEND_DESC				ACCUMULATE;
		
};

ksNS_KS_END

#endif		/* __KSDEPTHSTENCILSTATE_H__ */



