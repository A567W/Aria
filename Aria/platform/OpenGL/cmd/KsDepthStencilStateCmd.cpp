/************************************************************************************************/
/** 
 * @file		KsBlendStateGL.cpp
 * @brief		DirectX用深度ステンシルステート
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0
 */
/************************************************************************************************/

/*==============================================================================================*/
/*                                 << インクルード >>                                           */
/*==============================================================================================*/
#include "KsDepthStencilStateCmd.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/*
 * 
 */
/************************************************************************************************/


class KsRasterizerStateCmd : public KsRenderCmd
{
    public:
        KsRasterizerState*          m_pState;
};

class KsSamplerStateCmd : public KsRenderCmd
{
    public:
        KsSamplerState*             m_pState;
        KsUInt32                    m_slot;
        KsUInt32                    m_numView;
};




void KsDepthStencilStateCmd::execute( KS_DEPTH_STENCIL_DESC* pSrc )
{
    const KS_DEPTH_STENCIL_DESC*  pDesc = r_cast<KS_DEPTH_STENCIL_DESC*>( m_pState->getRenderResource() );

    //pDesc->FrontFace.StencilPassOp
    //glEnable(GL_CULL_FACE);
    //glDisable(GL_CULL_FACE);

    // 深度テスト
    if( pDesc->DepthEnable )
    {
        glEnable( GL_DEPTH_TEST );
    }
    else
    {
        glDisable( GL_DEPTH_TEST );
    }

    // 深度マスク
    if( pDesc->DepthWriteMask )
    {
        glDepthMask( GL_TRUE );
    }
    else
    {
        glDepthMask( GL_FALSE );	
    }

    // 深度ファンクション
    switch( pDesc->DepthFunc )
    {
        case KS_COMPARISON_NEVER:
            glDepthFunc( GL_NEVER );
            break;
        case KS_COMPARISON_LESS:
            glDepthFunc( GL_LESS );
            break;
        case KS_COMPARISON_EQUAL:
            glDepthFunc( GL_EQUAL );
            break;
        case KS_COMPARISON_LESS_EQUAL:
            glDepthFunc( GL_LEQUAL );
            break;
        case KS_COMPARISON_GREATER:
            glDepthFunc( GL_GREATER );
            break;
        case KS_COMPARISON_NOT_EQUAL:
            glDepthFunc( GL_NOTEQUAL );
            break;
        case KS_COMPARISON_GREATER_EQUAL:
            glDepthFunc( GL_GEQUAL );
            break;
        case KS_COMPARISON_ALWAYS:
            glDepthFunc( GL_ALWAYS );
            break;
        default:
            break;
    }

    // ステンシルテスト
    if( pDesc->StencilEnable )
    {
        glEnable( GL_STENCIL_TEST );
    }
    else
    {
        glDisable( GL_STENCIL_TEST );
    }

#if 0
    // ステンシルマスク
    glStencilMask( pDesc->StencilReadMask );

    // ステンシルファンクション
    switch( pDesc->StencilReadMask )
    {
        case KS_COMPARISON_NEVER:
            glStencilFunc( GL_NEVER, m_stencilRef );
            break;
        case KS_COMPARISON_LESS:
            glStencilFunc( GL_LESS );
            break;
        case KS_COMPARISON_EQUAL:
            glStencilFunc( GL_EQUAL );
            break;
        case KS_COMPARISON_LESS_EQUAL:
            glStencilFunc( GL_LEQUAL );
            break;
        case KS_COMPARISON_GREATER:
            glStencilFunc( GL_GREATER );
            break;
        case KS_COMPARISON_NOT_EQUAL:
            glStencilFunc( GL_NOTEQUAL );
            break;
        case KS_COMPARISON_GREATER_EQUAL:
            glStencilFunc( GL_GEQUAL );
            break;
        case KS_COMPARISON_ALWAYS:
            glStencilFunc( GL_ALWAYS );
            break;
        default:
            break;
    }
#endif
}


ksNS_KS_END

