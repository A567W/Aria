/************************************************************************************************/
/** 
 * @file		KsShaderManagerDX11.cpp
 * @brief		シェーダーマネージャー
 * @author		Tsukasa Kato
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsDevDX11/KsDevDX11PreCompile.h"
#include "KsDevDX11/shader/hlsl/KsShaderManagerDX11.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/

/************************************************************************************************/
/*
 * コンストラクタ
 * @param	pRenderSystem		描画システム
 */
/************************************************************************************************/
KsShaderManagerDX11::KsShaderManagerDX11( KsRenderSystemDX11* pRenderSystem )
	: m_pRenderSystem( pRenderSystem )
{
}

/************************************************************************************************/
/*
 * デストラクタ
 */
/************************************************************************************************/
KsShaderManagerDX11::~KsShaderManagerDX11()
{
}

/************************************************************************************************/
/*
 * ファイルからシェーダーを生成
 * @param	pFileName			ファイル名
 * @param	pEntryPoint			エントリーポイント
 * @param	shaderModel			シェーダーモデル
 * @param	shaderType			シェーダータイプ
 * @return						シェーダープログラムのポインタ
 */
/************************************************************************************************/
KsShaderProgram* KsShaderManagerDX11::createFromFile( const KsChar* pFileName, const KsChar* pEntryPoint, ksSHADER_MODEL_TYPE shaderModel, ksSHADER_TYPE shaderType )
{
	KsShaderProgram*		pShader = findRefInc( pFileName );

	if( pShader )
	{
		return pShader;
	}

	switch( shaderType )
	{
		case ksVERTEX_SHADER:
		{
			// 頂点シェーダー
			KsVertexShaderDX11*	pShader = new KsVertexShaderDX11( m_pRenderSystem );
			pShader->createFromFile( pFileName, pEntryPoint, shaderModel );
			return pShader;
		}
		case ksPIXEL_SHADER:
		{
			// ピクセルシェーダー
			KsPixelShaderDX11*	pShader = new KsPixelShaderDX11( m_pRenderSystem );
			pShader->createFromFile( pFileName, pEntryPoint, shaderModel );
			return pShader;
		}
		case ksGEOMETRY_SHADER:
		{
			// ジオメトリシェーダー
			return NULL;
		}
		case ksCOMPUTE_SHADER:
		{
			// コンピュートシェーダー
			KsComputeShaderDX11*	pShader = new KsComputeShaderDX11( m_pRenderSystem );
			pShader->createFromFile( pFileName, pEntryPoint, shaderModel );
			return pShader;
		}
		default:
			break;
	}

	return NULL;
}

/************************************************************************************************/
/*
 * ファイルからシェーダーを生成
 * @param	pFileName			ファイル名
 * @param	pEntryPoint			エントリーポイント
 * @param	shaderModel			シェーダーモデル
 * @param	shaderType			シェーダータイプ
 * @return						シェーダープログラムのポインタ
 */
/************************************************************************************************/
KsShaderProgram* KsShaderManagerDX11::createFromMemory( const KsChar* pFileName, const KsChar* pEntryPoint, ksSHADER_MODEL_TYPE shaderModel, ksSHADER_TYPE shaderType )
{
	KsShaderProgram*		pShader = findRefInc( pFileName );

	if( pShader )
	{
		return pShader;
	}

	switch( shaderType )
	{
		case ksVERTEX_SHADER:
		{
			// 頂点シェーダー
			KsVertexShaderDX11*	pShader = new KsVertexShaderDX11( m_pRenderSystem );
			pShader->createFromFile( pFileName, pEntryPoint, shaderModel );
			return pShader;
		}
		case ksPIXEL_SHADER:
		{
			// ピクセルシェーダー
			KsPixelShaderDX11*	pShader = new KsPixelShaderDX11( m_pRenderSystem );
			pShader->createFromFile( pFileName, pEntryPoint, shaderModel );
			return pShader;
		}
		case ksGEOMETRY_SHADER:
		{
			// ジオメトリシェーダー
			return NULL;
		}
		case ksCOMPUTE_SHADER:
		{
			// コンピュートシェーダー
			KsComputeShaderDX11*	pShader = new KsComputeShaderDX11( m_pRenderSystem );
			pShader->createFromFile( pFileName, pEntryPoint, shaderModel );
			return pShader;
		}
		default:
			break;
	}

	return NULL;
}

/************************************************************************************************/
/*
 * ファイルからシェーダーを生成
 * @param	pFileName			ファイル名
 * @param	pEntryPoint			エントリーポイント
 * @param	shaderModel			シェーダーモデル
 * @param	shaderType			シェーダータイプ
 * @return						シェーダープログラムのポインタ
 */
/************************************************************************************************/
KsShaderProgram* KsShaderManagerDX11::createFromResource( const KsChar* pFileName, const KsChar* pEntryPoint, ksSHADER_MODEL_TYPE shaderModel, ksSHADER_TYPE shaderType )
{
	KsShaderProgram*		pShader = findRefInc( pFileName );

	if( pShader )
	{
		return pShader;
	}

	switch( shaderType )
	{
		case ksVERTEX_SHADER:
		{
			// 頂点シェーダー
			KsVertexShaderDX11*	pShader = new KsVertexShaderDX11( m_pRenderSystem );
			pShader->createFromFile( pFileName, pEntryPoint, shaderModel );
			return pShader;
		}
		case ksPIXEL_SHADER:
		{
			// ピクセルシェーダー
			KsPixelShaderDX11*	pShader = new KsPixelShaderDX11( m_pRenderSystem );
			pShader->createFromFile( pFileName, pEntryPoint, shaderModel );
			return pShader;
		}
		case ksGEOMETRY_SHADER:
		{
			// ジオメトリシェーダー
			return NULL;
		}
		case ksCOMPUTE_SHADER:
		{
			// コンピュートシェーダー
			KsComputeShaderDX11*	pShader = new KsComputeShaderDX11( m_pRenderSystem );
			pShader->createFromFile( pFileName, pEntryPoint, shaderModel );
			return pShader;
		}
		default:
			break;
	}

	return NULL;
}

