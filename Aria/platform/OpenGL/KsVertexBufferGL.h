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
#ifndef __KSVERTEXBUFFERGL_H__
#define __KSVERTEXBUFFERGL_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                           */
/*==============================================================================================*/
#include "KsCommonGL.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

class KsRenderSystemGL;

/************************************************************************************************/
/**
 * @class		KsVertexBufferGL
 * @brief		頂点バッファ
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 */
/************************************************************************************************/
class ksENGINE_API KsVertexBufferGL : public KsVertexBuffer
{
		friend class KsRenderContextGL;
	public:
		/**
		 * 頂点バッファを生成する
		 * @param	pRenderSystem	描画システム
		 * @param	pData			データ読み込み用のポインタ
		 * @param	vertexSize		頂点サイズ
		 * @param	numVertex		頂点数
		 * @param	vertexFormat	頂点フォーマット
		 * @param	flags			フラグ
		 */
									KsVertexBufferGL( KsRenderSystemGL* pRenderSystem, void* pData, KsUInt32 vertexSize, KsUInt32 numVertex, KsUInt32 vertexFormat, KsUInt32 flags );

		/**
		 * デストラクタ
		 */
		virtual						~KsVertexBufferGL();

		/**
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
		virtual KsBool				create( KsRenderSystemGL* pRenderSystem, void* pData, KsUInt32 vertexSize, KsUInt32 numVertex, KsUInt32 vertexFormat, KsUInt32 flags );

		/**
		 * 破棄処理
		 */
		virtual void				destroy();

		/**
		 * リソースを取得する
		 * @return					 リソース
		 */
		virtual void*				getBufferResource();

		/**
		 * 頂点バッファをロックする
		 * @param	pContext		描画コンテキスト
		 * @param	flags			ロックフラグ
		 * @return					ロックしたバッファの先頭ポインタ
		 */
		virtual void*				lock( const KsRenderContext* pContext, KsUInt32 flags );

		/**
		 * 頂点バッファのロックを解除する
		 * @param	pContext		描画コンテキスト
		 */
		virtual void				unlock( const KsRenderContext* pContext );

		/**
		 * インデックスバッファからの読み込み
		 * @param	pContext		描画コンテキスト
		 * @param	pData			データ読み込み用のポインタ
		 * @param	size			データサイズ
		 */
		virtual void				read( const KsRenderContext* pContext, void* pData, KsUInt32 size );

		/**
		 * インデックスバッファへの書き込み
		 * @param	pContext		描画コンテキスト
		 * @param	pData			データ読み込み用のポインタ
		 * @param	size			データサイズ
		 */
		virtual void				write( const KsRenderContext* pContext, void* pData, KsUInt32 size );

	private:
		KsRenderSystemGL*			m_pRenderSystem;	/**< 描画システム			*/
        GLuint                      m_vertexBuffer;     /**< 頂点バッファID       */
};

ksNS_KS_END

#endif		/* __KSVERTEXBUFFERGL_H__ */


