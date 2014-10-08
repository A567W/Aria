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
 * @file	KsBlendStateCmd.cpp
 * @brief	ブレンドステータス描画コマンド
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
/************************************************************************************************/


/*==============================================================================================*/
/*                                 << インクルード >>                                           */
/*==============================================================================================*/
#include "KsBlendStateCmd.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/*
 * KsBlendStateの描画コマンドを実行する。
 * @param   pSrc    ブレンド比較用ステート
 */
/************************************************************************************************/
void KsBlendStateCmd::execute( KS_BLEND_DESC* pSrc )
{
    const KS_BLEND_DESC*  pBlend = r_cast<KS_BLEND_DESC*>( m_pState->getRenderResource() );

    //----------------------------------------------------------
    // アルファカバレッジ
    //----------------------------------------------------------
    if( pBlend->AlphaToCoverageEnable )
    {
        glEnable( GL_SAMPLE_ALPHA_TO_COVERAGE );
    }
    else
    {
        glDisable( GL_SAMPLE_ALPHA_TO_COVERAGE );
    }

    //----------------------------------------------------------
    // IndependentBlendEnable
    //----------------------------------------------------------
    //if( pBlend->IndependentBlendEnable )
    //{
    //}

    const KS_RENDER_TARGET_BLEND_DESC*    pTargetBlend = &pBlend->RenderTarget[ 0 ];

    //----------------------------------------------------------
    // アルファブレンド
    //----------------------------------------------------------
    if( pTargetBlend->BlendEnable )
    {
        glEnable( GL_BLEND );
    }
    else
    {
        glDisable( GL_BLEND );
    }

    //----------------------------------------------------------
    // ブレンドファンクション
    //----------------------------------------------------------
    const GLenum  srcBlend      = getBlendFactor( pTargetBlend->SrcBlend );
    const GLenum  dstBlend      = getBlendFactor( pTargetBlend->DestBlend );
    const GLenum  srcBlendAlpha = getBlendFactor( pTargetBlend->SrcBlendAlpha );
    const GLenum  dstBlendAlpha = getBlendFactor( pTargetBlend->DestBlendAlpha );

    glBlendFuncSeparate( srcBlend, dstBlend, srcBlendAlpha, dstBlendAlpha );

    //----------------------------------------------------------
    // ブレンドモード
    //----------------------------------------------------------
    const GLenum  modeRGB   = getBlendMode( pTargetBlend->BlendOp );
    const GLenum  modeAlpha = getBlendMode( pTargetBlend->BlendOpAlpha );

    glBlendEquationSeparate( modeRGB, modeAlpha );

    //----------------------------------------------------------
    // RenderTargetWriteMask
    //----------------------------------------------------------
    //pTargetBlend->RenderTargetWriteMask
}


GLenum KsBlendStateCmd::getBlendFactor( KS_BLEND value ) const
{
    switch( value )
    {
        case KS_BLEND_ZERO:
            return GL_ZERO;
        case KS_BLEND_ONE:
            return GL_ONE;
        case KS_BLEND_SRC_COLOR:
            return GL_SRC_COLOR;
        case KS_BLEND_INV_SRC_COLOR:
            return GL_ONE_MINUS_SRC_COLOR;
        case KS_BLEND_SRC_ALPHA:
            return GL_SRC_ALPHA;
        case KS_BLEND_INV_SRC_ALPHA:
            return GL_ONE_MINUS_SRC_ALPHA;
        case KS_BLEND_DEST_ALPHA:
            return GL_DST_ALPHA;
        case KS_BLEND_INV_DEST_ALPHA:
            return GL_ONE_MINUS_DST_ALPHA;
        case KS_BLEND_DEST_COLOR:
            return GL_DST_COLOR;
        case KS_BLEND_INV_DEST_COLOR:
            return GL_ONE_MINUS_DST_COLOR;
        case KS_BLEND_SRC_ALPHA_SAT:
            return GL_SRC_ALPHA_SATURATE;
        case KS_BLEND_SRC1_COLOR:
            return GL_SRC1_COLOR;
        case KS_BLEND_INV_SRC1_COLOR:
            return GL_ONE_MINUS_SRC1_COLOR;
        case KS_BLEND_SRC1_ALPHA:
            return GL_SRC1_ALPHA;
        case KS_BLEND_INV_SRC1_ALPHA:
            return GL_ONE_MINUS_SRC1_ALPHA;
        case KS_BLEND_BLEND_FACTOR:
        case KS_BLEND_INV_BLEND_FACTOR:
            //KsAssert( 0, "not support GL blend factor\n" );
        default:
            break;
    }

    return GL_ONE;
}

GLenum KsBlendStateCmd::getBlendMode( KS_BLEND_OP value ) const
{
    switch( value )
    {
        case KS_BLEND_OP_ADD:
            return GL_FUNC_ADD;
        case KS_BLEND_OP_SUBTRACT:
            return GL_FUNC_SUBTRACT;
        case KS_BLEND_OP_REV_SUBTRACT:
            return GL_FUNC_REVERSE_SUBTRACT;
        case KS_BLEND_OP_MIN:
            return GL_MIN;
        case KS_BLEND_OP_MAX:
            return GL_MAX;
        default:
            break;
    }

    return GL_FUNC_ADD;
}

ksNS_KS_END

