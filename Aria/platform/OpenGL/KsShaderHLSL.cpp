/************************************************************************************************/
/** 
 * @file		KsShaderHLSL.h
 * @brief		シェーダーマネージャー
 * @author		Tsukasa Kato
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0
 */
/************************************************************************************************/


/*==============================================================================================*/
/*                                 << インクルード >>                                           */
/*==============================================================================================*/
#include "KsDevDX11/KsDevDX11PreCompile.h"
#include "KsDevDX11/shader/hlsl/KsShaderHLSL.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/

/************************************************************************************************/
/*
 * コンストラクタ
 */
/************************************************************************************************/
KsShaderHLSL::KsShaderHLSL( KsRenderSystemDX* pRenderSystem )
	: m_pRenderSystem( pRenderSystem )
	, m_pEffect( 0 )
	, m_hTechniques( 0 )
{
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
KsShaderHLSL::~KsShaderHLSL()
{
	ksDELETEARRAY( m_hTechniques );
	ksRELEASE( m_pEffect );
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsShaderHLSL::initialize( const KsChar* pName, LPD3DXEFFECT pEffect )
{
	m_name    = pName;
	m_pEffect = pEffect;

	KsUInt32	count = 0;

	while( 1 )
	{
		if( !m_pEffect->GetTechnique( count ) )
		{
			break;
		}

		++count;
	}

	if( count )
	{
		m_hTechniques  = new D3DXHANDLE [ count ];
		m_numTechnique = count;
		
		for( KsUInt32 idx = 0; idx < count; idx++ )
		{
			m_hTechniques[ idx ] = m_pEffect->GetTechnique( idx );
		}
	}
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsShaderHLSL::begine()
{
	m_pEffect->Begin( &m_numPass, 0 );
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsShaderHLSL::end()
{
	m_pEffect->End();
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsShaderHLSL::beginePass( KsUInt32 pass )
{
	m_pEffect->BeginPass( pass );
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsShaderHLSL::endPass()
{
	m_pEffect->EndPass();
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsShaderHLSL::setTechnique( KsUInt32 index )
{
	m_hCurrentTechnique = (KsHandle)m_hTechniques[ index ];
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsShaderHLSL::setTechnique( KsHandle hTechnique )
{
	m_hCurrentTechnique = hTechnique;
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsShaderHLSL::setTechnique( const KsChar* pTechniqueName )
{
	m_hCurrentTechnique = getTechnique( pTechniqueName );
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
KsHandle KsShaderHLSL::getTechnique( const KsChar* pTechniqueName )
{
	D3DXHANDLE	handle = m_pEffect->GetTechniqueByName( pTechniqueName );

	return (KsHandle)handle;
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsShaderHLSL::setVertexShaderConstantB( KsUInt32 startRegister, const KsBool* pConstantData, KsUInt32 count )
{
	m_pRenderSystem->getD3DDevice()->SetVertexShaderConstantB( startRegister, pConstantData, count );
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsShaderHLSL::setVertexShaderConstantF( KsUInt32 startRegister, const KsReal* pConstantData, KsUInt32 count )
{
	m_pRenderSystem->getD3DDevice()->SetVertexShaderConstantF( startRegister, pConstantData, count );
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsShaderHLSL::setVertexShaderConstantI( KsUInt32 startRegister, const KsInt32* pConstantData, KsUInt32 count )
{
	m_pRenderSystem->getD3DDevice()->SetVertexShaderConstantI( startRegister, pConstantData, count );
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsShaderHLSL::setPixelShaderConstantB( KsUInt32 startRegister, const KsBool*  pConstantData, KsUInt32 count )
{
	m_pRenderSystem->getD3DDevice()->SetPixelShaderConstantB( startRegister, pConstantData, count );
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsShaderHLSL::setPixelShaderConstantF( KsUInt32 startRegister, const KsReal*  pConstantData, KsUInt32 count )
{
	m_pRenderSystem->getD3DDevice()->SetPixelShaderConstantF( startRegister, pConstantData, count );
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsShaderHLSL::setPixelShaderConstantI( KsUInt32 startRegister, const KsInt32* pConstantData, KsUInt32 count )
{
	m_pRenderSystem->getD3DDevice()->SetPixelShaderConstantI( startRegister, pConstantData, count );
}
