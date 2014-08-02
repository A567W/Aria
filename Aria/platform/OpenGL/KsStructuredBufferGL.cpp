/************************************************************************************************/
/** 
 * @file		KsStructuredBufferDX11.h
 * @brief		UAVバッファ
 * @author		Tsukasa Kato
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/

/*==============================================================================================*/
/*                                 << インクルード >>                                           */
/*==============================================================================================*/
#include "KsDevDX11/KsDevDX11PreCompile.h"
#include "KsDevDX11/device/KsStructuredBufferDX11.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/

/************************************************************************************************/
/*
 * コンストラクタ(UAVバッファを生成する)
 * @param	pRenderSystem	描画システム
 * @param	elementSize		要素サイズ
 * @param	numElements		要素数
 * @param	format			フォーマット
 * @param	flags			フラグ
 */
/************************************************************************************************/
KsStructuredBufferDX11::KsStructuredBufferDX11( KsRenderSystemDX11* pRenderSystem, KsUInt32 elementSize, KsUInt32 numElements, KsUInt32 format, KsUInt32 flags )
	: m_elementSize( 0 )
	, m_numElements( 0 )
	, m_format( 0 )
	, m_pBuffer( 0 )
	, m_pShaderResourceView( 0 )
	, m_pUnorderedAccessView( 0 )
{
	create( pRenderSystem, elementSize, numElements, format, flags );
}

/************************************************************************************************/
/*
 * デストラクタ
 */
/************************************************************************************************/
KsStructuredBufferDX11::~KsStructuredBufferDX11()
{
	ksRELEASE( m_pUnorderedAccessView )
	ksRELEASE( m_pShaderResourceView );
	ksRELEASE( m_pBuffer );
}

/************************************************************************************************/
/*
 * UAVバッファを生成する
 * @param	pRenderSystem	描画システム
 * @param	elementSize		要素サイズ
 * @param	numElements		要素数
 * @param	format			フォーマット
 * @param	flags			フラグ
 * @retval	ksTRUE			生成成功
 * @retval	ksFALSE			生成失敗
 */
/************************************************************************************************/
KsBool KsStructuredBufferDX11::create( KsRenderSystemDX11* pRenderSystem, KsUInt32 elementSize, KsUInt32 numElements, KsUInt32 format, KsUInt32 flags )
{
	m_elementSize = elementSize;
	m_numElements = numElements;
	m_format      = format;

	// 頂点バッファを作成する
	// バッファ情報の設定
	D3D11_BUFFER_DESC	desc;

	// ゼロクリアする
	KsZeroMemory( &desc, sizeof(desc) );

	desc.ByteWidth           = m_elementSize * m_numElements;
	desc.BindFlags           = flags;
	desc.Usage               = format ? D3D11_USAGE_DYNAMIC : D3D11_USAGE_DEFAULT;
	desc.CPUAccessFlags      = format ? D3D11_CPU_ACCESS_WRITE : 0;
	desc.MiscFlags           = D3D11_RESOURCE_MISC_BUFFER_STRUCTURED;
	desc.StructureByteStride = m_elementSize;

	ID3D11Device*	pDevice = pRenderSystem->getD3DDevice();

	HRESULT hr = E_FAIL;

	hr = pDevice->CreateBuffer( &desc, 0, &m_pBuffer );

	if( ksFAILED( hr ) )
	{
		return ksFALSE;
	}

	if( flags & D3D11_BIND_UNORDERED_ACCESS )
	{
		hr = pDevice->CreateUnorderedAccessView( m_pBuffer, 0, &m_pUnorderedAccessView );
	}

	if( flags & D3D11_BIND_SHADER_RESOURCE )
	{
		hr = pDevice->CreateShaderResourceView( m_pBuffer, 0, &m_pShaderResourceView );
	}

	if( ksFAILED( hr ) )
	{
		return ksFALSE;
	}

	return ksTRUE;
}

/************************************************************************************************/
/*
 * 破棄処理
 */
/************************************************************************************************/
void KsStructuredBufferDX11::destroy()
{
	delete this;
}

/************************************************************************************************/
/*
 * テクスチャをアクティブにする
 */
/************************************************************************************************/
void KsStructuredBufferDX11::active()
{
}

/************************************************************************************************/
/*
 * リソースを取得する
 * @return					 リソース
 */
/************************************************************************************************/
void* KsStructuredBufferDX11::getBufferResource()
{
	return m_pBuffer;
}

/************************************************************************************************/
/*
 * インデックスバッファをロックする
 * @param	pContext		描画コンテキスト
 * @param	flags			ロックフラグ
 * @return					ロックしたバッファの先頭ポインタ
 */
/************************************************************************************************/
void* KsStructuredBufferDX11::lock( const KsRenderContext* pContext, KsUInt32 flags )
{
#if 0
	void*		pBuffer;

	m_pIndexBuffer->Lock( startIndex*m_indexSize, numIndex*m_indexSize, &pBuffer, flags );

	// データ設定
	
	hr = g_pContext->Map( m_pIndexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &m_resource );
	if( ksSUCCEEDED(hr) )
	{
		USHORT*	p = reinterpret_cast<USHORT*>(resource.pData);
		p[0] = 0; p[1] = 1; p[2] = 2; p[3] = 3;
		
	}

	return pBuffer;
#endif
	return NULL;
}

/************************************************************************************************/
/*
 * インデックスバッファのロックを解除する
 */
/************************************************************************************************/
void KsStructuredBufferDX11::unlock( const KsRenderContext* pContext )
{
	//g_pContext->Unmap( m_pIndexBuffer, 0 );

	//m_pIndexBuffer->Unlock();
}

/************************************************************************************************/
/*
 * インデックスバッファからの読み込み
 * @param	pContext		描画コンテキスト
 * @param	pData			データ読み込み用のポインタ
 * @param	size			データサイズ
 */
/************************************************************************************************/
void KsStructuredBufferDX11::read( const KsRenderContext* pContext, void* pData, KsUInt32 size )
{
#if 0
	void*		pBuffer;
	KsUInt32	length = numIndex*m_indexSize;

	m_pIndexBuffer->Lock( startIndex*m_indexSize, length, &pBuffer, D3DLOCK_READONLY );

	memcpy( pData, pBuffer, length );
	
	m_pIndexBuffer->Unlock();
#endif

}

/************************************************************************************************/
/*
 * インデックスバッファへの書き込み
 * @param	pContext		描画コンテキスト
 * @param	pData			データ読み込み用のポインタ
 * @param	size			データサイズ
 */
/************************************************************************************************/
void KsStructuredBufferDX11::write( const KsRenderContext* pContext, void* pData, KsUInt32 size )
{
#if 0
	D3D11_MAPPED_SUBRESOURCE	mappedResource;

	pContext->->Map( m_pBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource );

	memcpy( mappedResource.pData, pData, size );

	pContext->Unmap( m_pBuffer, 0 );
#endif
}

