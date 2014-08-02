/************************************************************************************************/
/** 
 * @file		KsIndexBufferGL.h
 * @brief		インデックスバッファ
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/
#ifndef __KSINDEXBUFFERGL_H__
#define __KSINDEXBUFFERGL_H__

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
 * @class		KsIndexBufferDX
 * @brief		インデックスバッファ
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 */
/************************************************************************************************/
class ksENGINE_API KsIndexBufferGL : public KsIndexBuffer
{
		friend class KsRenderContextGL;
	public:
		/**
		 * コンストラクタ
		 * @param	pRenderSystem	描画システム
		 * @param	pData			データ読み込み用のポインタ
		 * @param	size			データサイズ
		 * @param	numIndex		インデックスの数
		 * @param	indexFormat		インデックスフォーマット
		 * @param	flags			フラグ
		 */
									KsIndexBufferGL( KsRenderSystemGL* pRenderSystem, void* pData, KsUInt32 size, KsUInt32 numIndex, KsUInt32 indexFormat, KsUInt32 flags );

		/**
		 * デストラクタ
		 */
		virtual						~KsIndexBufferGL();

		/**
		 * インデックスバッファを生成する
		 * @param	pRenderSystem	描画システム
		 * @param	pData			データ読み込み用のポインタ
		 * @param	size			データサイズ
		 * @param	numIndex		インデックスの数
		 * @param	indexFormat		インデックスフォーマット
		 * @param	flags			フラグ
		 * @retval	ksTRUE			生成成功
		 * @retval	ksFALSE			生成失敗
		 */
		virtual KsBool				create( KsRenderSystemGL* pRenderSystem, void* pData, KsUInt32 size, KsUInt32 numIndex, KsUInt32 indexFormat, KsUInt32 flags );

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
		 * インデックスバッファをロックする
		 * @param	pContext		描画コンテキスト
		 * @param	flags			ロックフラグ
		 * @return					ロックしたバッファの先頭ポインタ
		 */
		virtual void*				lock( const KsRenderContext* pContext, KsUInt32 flags );

		/**
		 * インデックスバッファのロックを解除する
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
		KsRenderSystemGL*			m_pRenderSystem;	/**< 描画システム				*/
        GLuint                      m_indexBuffer;      /**< 頂点バッファID       */
		KsUInt32					m_indexSize;		/**< インデックスサイズ		*/
};

ksNS_KS_END

#endif		/* __KSINDEXBUFFERGL_H__ */


