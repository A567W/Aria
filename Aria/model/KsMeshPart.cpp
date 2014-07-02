/************************************************************************************************/
/** 
 * @file		KsMeshPart.cpp
 * @brief		メッシュパーツ
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsMeshPart.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/*
 * コンストラクタ
 */
/************************************************************************************************/
KsMeshPart::KsMeshPart()
	: m_pIndexBuffer( 0 )
	, m_pVertexBuffer( 0 )
	, m_numVertices( 0 )
	, m_primitiveCount( 0 )
	, m_startIndex( 0 )
	, m_vertexOffset( 0 )
	, m_pEffect( 0 )
	, m_numPallet( 0 )
	, m_pPallet( 0 )
{
}

/************************************************************************************************/
/*
 * コンストラクタ( メッシュパーツを生成します。)
 * @param	pEffect			使用するエフェクトデータ
 * @param	pIndexBuffer	メッシュ部分のインデックス バッファー
 * @param	pVertexBuffer	メッシュ パーツの頂点バッファー
 * @param	pInputLayout	インプットレイアウト
 * @param	numVertices		描画呼び出し中に使用される頂点の数
 * @param	primitiveCount	レンダリングするプリミティブの数
 * @param	startIndex		インデックス配列の中で頂点の読み取りを開始する位置
 * @param	vertexOffset	頂点バッファーの最上部からのオフセット
 */
/************************************************************************************************/
KsMeshPart::KsMeshPart( KsEffect*		pEffect,
						KsIndexBuffer*	pIndexBuffer,
						KsVertexBuffer*	pVertexBuffer,
						KsInputLayout*	pInputLayout,
						KsInt32	numVertices,
						KsInt32	primitiveCount,
						KsInt32	startIndex,
						KsInt32 vertexOffset )
	: m_pEffect( pEffect )
	, m_pIndexBuffer( pIndexBuffer )
	, m_pVertexBuffer( pVertexBuffer )
	, m_pInputLayout( pInputLayout )
	, m_numVertices( numVertices )
	, m_primitiveCount( primitiveCount )
	, m_startIndex( startIndex )
	, m_vertexOffset( vertexOffset )
	, m_numPallet( 0 )
	, m_pPallet( 0 )
{
}

/************************************************************************************************/
/*
 * デストラクタ
 */
/************************************************************************************************/
KsMeshPart::~KsMeshPart()
{
	destroy();
}

/************************************************************************************************/
/*
 * メッシュパーツを生成します。
 * @param	pEffect			使用するエフェクトデータ
 * @param	pIndexBuffer	メッシュ部分のインデックス バッファー
 * @param	pVertexBuffer	メッシュ パーツの頂点バッファー
 * @param	pInputLayout	インプットレイアウト
 * @param	numVertices		描画呼び出し中に使用される頂点の数
 * @param	primitiveCount	レンダリングするプリミティブの数
 * @param	startIndex		インデックス配列の中で頂点の読み取りを開始する位置
 * @param	vertexOffset	頂点バッファーの最上部からのオフセット
 */
/************************************************************************************************/
void KsMeshPart::create(  KsEffect* pEffect, KsIndexBuffer* pIndexBuffer, KsVertexBuffer* pVertexBuffer, KsInputLayout*	pInputLayout, KsInt32 numVertices, KsInt32 primitiveCount, KsInt32 startIndex, KsInt32 vertexOffset )
{
	m_pEffect        = pEffect;
	m_pIndexBuffer   = pIndexBuffer;	
	m_pVertexBuffer  = pVertexBuffer;
	m_pInputLayout   = pInputLayout;
	m_numVertices    = numVertices;
	m_primitiveCount = primitiveCount;
	m_startIndex     = startIndex;
	m_vertexOffset   = vertexOffset;	
}

/************************************************************************************************/
/*
 * マトリックスパレットを生成します。
 * @param	numPallet		マトリックスパレット数
 * @param	pPallet			マトリックスパレット
 */
/************************************************************************************************/
void KsMeshPart::createPallet( KsInt32 numPallet, KsInt32* pPallet )
{
	if( 0 < numPallet )
	{
		m_numPallet = numPallet;
		m_pPallet   = new KsInt32 [ numPallet ];

		KsMemCopy( m_pPallet, pPallet, m_numPallet * sizeof(KsInt32) );
	}
}

/************************************************************************************************/
/*
 * メッシュパーツを破棄します。
 */
 /************************************************************************************************/
void KsMeshPart::destroy()
{
	ksDELETE( m_pIndexBuffer );
	ksDELETE( m_pVertexBuffer );
	ksDELETE( m_pPallet );
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
void KsMeshPart::updateParameter( KsModelParameter* pParameter )
{
	for( KsUInt32 i=0; i<m_vpBones.size(); i++ )
	{
		const KsBone*	pBone = m_vpBones[ i ];

		pParameter->Model.MatrixPalette[ i ] = pBone->m_skinTransform;
		pParameter->Model.MatrixPalette[ i ].transpose();
	}
}

/************************************************************************************************/
/*
 * 描画処理
 * @param	pRenderContext	描画コンテキスト
 */
/************************************************************************************************/
void KsMeshPart::draw( KsRenderContext* pRenderContext, KsModelParameter* pParameter )
{
	updateParameter( pParameter );

	KsUInt32		stride = m_pVertexBuffer->getVertexSize();
	KsUInt32		offset = 0;

	pRenderContext->setInputLayout( m_pInputLayout );
	pRenderContext->setVertexBuffers( 0, 1, m_pVertexBuffer, &stride, &offset );
	pRenderContext->setIndexBuffer( m_pIndexBuffer, m_pIndexBuffer->getIndexFormatType(), 0 );
	pRenderContext->setPrimitiveTopology( KS_PRIMITIVE_TOPOLOGY_TRIANGLELIST );

	// シェダーをセットする
	m_pEffect->setShader( pRenderContext, pParameter );

	pRenderContext->drawIndexed( m_primitiveCount, 0, 0 );
}

ksNS_KS_END

