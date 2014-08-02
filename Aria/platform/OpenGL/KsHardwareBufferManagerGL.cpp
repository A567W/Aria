/************************************************************************************************/
/** 
 * @file		KsHardwareBufferManagerGL.cpp
 * @brief		バッファマネージャ
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/

/*==============================================================================================*/
/*                                 << インクルード >>                                           */
/*==============================================================================================*/
#include "KsRenderSystemGL.h"
#include "KsHardwareBufferManagerGL.h"
#include "KsConstantBufferGL.h"
#include "KsIndexBufferGL.h"
#include "KsVertexBufferGL.h"

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
KsHardwareBufferManagerGL::KsHardwareBufferManagerGL( KsRenderSystemGL* _RenderSystem )
	: m_RenderSystem( _RenderSystem )
{
}

/************************************************************************************************/
/*
 * デストラクタ
 */
/************************************************************************************************/
KsHardwareBufferManagerGL::~KsHardwareBufferManagerGL()
{
}

/************************************************************************************************/
/*
 * 頂点バッファを生成する
 * @param		vertexSize		頂点サイズ
 * @param		numVertex		頂点数
 * @param		vertexFormat	頂点フォーマット
 * @param		flags			フラグ
 * @return						頂点バッファのポインタ
 */
/************************************************************************************************/
KsVertexBuffer* KsHardwareBufferManagerGL::createVertexBuffer( KsUInt32 vertexSize, KsUInt32 numVertex, KsUInt32 vertexFormat, KsUInt32 flags )
{
	return ksNew KsVertexBufferGL( m_RenderSystem, NULL, vertexSize, numVertex, vertexFormat, flags );
}

/************************************************************************************************/
/*
 * 頂点バッファを生成する
 * @param		vertexSize		頂点サイズ
 * @param		numVertex		頂点数
 * @param		vertexFormat	頂点フォーマット
 * @param		flags			フラグ
 * @return						頂点バッファのポインタ
 */
/************************************************************************************************/
KsVertexBuffer* KsHardwareBufferManagerGL::createVertexBuffer( void* pData, KsUInt32 vertexSize, KsUInt32 numVertex, KsUInt32 vertexFormat, KsUInt32 flags )
{
	return ksNew KsVertexBufferGL( m_RenderSystem, pData, vertexSize, numVertex, vertexFormat, flags );
}

/************************************************************************************************/
/*
 * インデックスバッファを生成する
 * @param		numIndex		インデックス数
 * @param		flags			フラグ
 * @return						インデックスバッファのポインタ
 */
/************************************************************************************************/
KsIndexBuffer* KsHardwareBufferManagerGL::createIndexBuffer( KsUInt32 numIndex, KsUInt32 indexFormat, KsUInt32 flags )
{
	return ksNew KsIndexBufferGL( m_RenderSystem, NULL, 0, numIndex, indexFormat, flags );
}

/************************************************************************************************/
/*
 * インデックスバッファを生成する
 * @param		numIndex		インデックス数
 * @param		flags			フラグ
 * @return						インデックスバッファのポインタ
 */
/************************************************************************************************/
KsIndexBuffer* KsHardwareBufferManagerGL::createIndexBuffer( void* pData, KsUInt32 size, KsUInt32 numIndex, KsUInt32 indexFormat, KsUInt32 flags )
{
	return ksNew KsIndexBufferGL( m_RenderSystem, pData, size, numIndex, indexFormat, flags );
}

/************************************************************************************************/
/*
 * 定数バッファを生成する
 * @param	pData				[in] データ読み込み用のポインタ
 * @param	size				[in] データサイズ
 * @param	flags				[in] フラグ
 * @return						定数バッファのポインタ
 */
 /************************************************************************************************/
KsConstantBuffer* KsHardwareBufferManagerGL::createConstantBuffer( KsUInt32 size, KsUInt32 flags )
{
	return ksNew KsConstantBufferGL( m_RenderSystem, NULL, size, flags );
}

/************************************************************************************************/
/*
 * 定数バッファを生成する
 * @param	size				[in] バッファサイズ
 * @param	flags				[in] フラグ
 * @return						定数バッファのポインタ
 */
 /************************************************************************************************/
KsConstantBuffer* KsHardwareBufferManagerGL::createConstantBuffer( void* pData, KsUInt32 size, KsUInt32 flags )
{
	return ksNew KsConstantBufferGL( m_RenderSystem, pData, size, flags );
}


ksNS_KS_END

