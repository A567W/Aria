/************************************************************************************************/
/** 
 * @file		KsVertexBufferGL.h
 * @brief		頂点バッファ
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/

/*==============================================================================================*/
/*                                 << インクルード >>                                           */
/*==============================================================================================*/
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
 * コンストラクタ(頂点バッファを生成する)
 * @param	pRenderSystem	描画システム
 * @param	pData			データ読み込み用のポインタ
 * @param	vertexSize		頂点サイズ
 * @param	numVertex		頂点数
 * @param	vertexFormat	頂点フォーマット
 * @param	flags			フラグ
 */
/************************************************************************************************/
KsVertexBufferGL::KsVertexBufferGL( KsRenderSystemGL* pRenderSystem, void* pData, KsUInt32 vertexSize, KsUInt32 numVertex, KsUInt32 vertexFormat, KsUInt32 flags )
	: m_pRenderSystem( pRenderSystem )
    , m_vertexBuffer( 0 )
{
	create( pRenderSystem, pData, vertexSize, numVertex, vertexFormat, flags );
}

/************************************************************************************************/
/*
 * デストラクタ
 */
/************************************************************************************************/
KsVertexBufferGL::~KsVertexBufferGL()
{
    if( m_vertexBuffer )
    {
        glDeleteBuffers( 1, &m_vertexBuffer );
        m_vertexBuffer = 0;
    }
}

/************************************************************************************************/
/*
 * 頂点バッファを生成する
 * @param	pRenderSystem	描画システム
 * @param	pData			データ読み込み用のポインタ
 * @param	vertexSize		頂点サイズ
 * @param	numVertex		頂点数
 * @param	vertexFormat	頂点フォーマット
 * @param	flags			フラグ
 * @retval	ksTRUE			生成成功
 * @retval	ksFALSE			生成失敗
 */
/************************************************************************************************/
KsBool KsVertexBufferGL::create( KsRenderSystemGL* pRenderSystem, void* pData, KsUInt32 vertexSize, KsUInt32 numVertex, KsUInt32 vertexFormat, KsUInt32 flags )
{
	m_vertexSize   = vertexSize;
	m_numVertex    = numVertex;
	m_vertexFormat = vertexFormat;

	//　頂点バッファの作成
    glGenBuffers( 1, &m_vertexBuffer );
    glBindBuffer( GL_ARRAY_BUFFER, m_vertexBuffer );
    glBufferData( GL_ARRAY_BUFFER, numVertex * vertexSize, pData, GL_STATIC_DRAW );
    glBindBuffer( GL_ARRAY_BUFFER, 0 );

	return ksTRUE;
}

/************************************************************************************************/
/*
 * 破棄処理
 */
/************************************************************************************************/
void KsVertexBufferGL::destroy()
{
	delete this;
}

/************************************************************************************************/
/*
 * 頂点バッファをロックする
 * @param	pContext		描画コンテキスト
 * @param	flags			ロックフラグ
 * @return					ロックしたバッファの先頭ポインタ
 */
/************************************************************************************************/
void* KsVertexBufferGL::lock( const KsRenderContext* pContext, KsUInt32 flags )
{
	return NULL;
}

/************************************************************************************************/
/*
 * 頂点バッファのロックを解除する
 */
/************************************************************************************************/
void KsVertexBufferGL::unlock( const KsRenderContext* pContext )
{
}

/************************************************************************************************/
/*
 * 頂点バッファからの読み込み
 * @param	pContext		描画コンテキスト
 * @param	pData			データ読み込み用のポインタ
 * @param	size			データサイズ
 */
/************************************************************************************************/
void KsVertexBufferGL::read( const KsRenderContext* pContext, void* pData, KsUInt32 size )
{
}

/************************************************************************************************/
/*
 * 頂点バッファへの書き込み
 * @param	pContext		描画コンテキスト
 * @param	pData			データ読み込み用のポインタ
 * @param	size			データサイズ
 */
/************************************************************************************************/
void KsVertexBufferGL::write( const KsRenderContext* pContext, void* pData, KsUInt32 size )
{
}

ksNS_KS_END

