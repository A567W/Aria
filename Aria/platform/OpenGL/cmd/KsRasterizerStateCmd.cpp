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
 * @file	KsRasterizerStateCmd.cpp
 * @brief	���X�^���C�Y�X�e�[�^�X�`��R�}���h
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
/************************************************************************************************/

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                           */
/*==============================================================================================*/
#include "KsRasterizerStateCmd.h"

/*==============================================================================================*/
/*                                     << ��` >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << �錾 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN


/************************************************************************************************/
/*
 * KsRasterizerState�̕`��R�}���h�����s����B
 * @param   pSrc    ���X�^���C�Y��r�p�X�e�[�g
 */
/************************************************************************************************/
void KsRasterizerStateCmd::execute( KS_RASTERIZER_DESC* pSrc )
{
    const KS_RASTERIZER_DESC*  pRasterizer = r_cast<KS_RASTERIZER_DESC*>( m_pState->getRenderResource() );
 
    //----------------------------------------------------------
    // Cull Mode
    //----------------------------------------------------------
    switch( pRasterizer->CullMode )
    {
        case KS_CULL_NONE:
            // ���ʂ�`��
            glDisable( GL_CULL_FACE );
            break;
	    case KS_CULL_FRONT:
            // ���ʂ݂̂�`��
            glEnable( GL_CULL_FACE );
            glCullFace( GL_FRONT );
            break;
	    case KS_CULL_BACK:
            // �\�ʂ݂̂�`��
            glEnable( GL_CULL_FACE ); 
            glCullFace( GL_BACK );
            break;
        default:
            break;
    }

    //----------------------------------------------------------
    // Fill Mode
    //----------------------------------------------------------
    switch( pRasterizer->FillMode )
    {
        case KS_FILL_WIREFRAME:
            glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
            break;
	    case KS_FILL_SOLID:
            glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
            break;
        default:
            break;

    }

    //----------------------------------------------------------
    // Bias
    //----------------------------------------------------------
    //glEnable(GL_POLYGON_OFFSET_FILL);
    //glDisable(GL_POLYGON_OFFSET_FILL);
    //glPolygonOffset( 0.0f, pRasterizer->DepthBias );

    //----------------------------------------------------------
    // Scissor
    //----------------------------------------------------------
    //glScissor( );
    if( pRasterizer->ScissorEnable )
    {
        glEnable( GL_SCISSOR_TEST );
    }
    else
    {
        glDisable( GL_SCISSOR_TEST );
    }

    //pRasterizer->DepthClipEnable
}




ksNS_KS_END

