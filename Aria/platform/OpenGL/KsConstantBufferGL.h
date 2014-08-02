/************************************************************************************************/
/** 
 * @file		KsConstantBufferGL.h
 * @brief		定数バッファ
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/
#ifndef __KSCONSTANTBUFFERGL_H__
#define __KSCONSTANTBUFFERGL_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
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
 * @class		KsConstantBufferGL
 * @brief		定数バッファ
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 */
/************************************************************************************************/
class ksENGINE_API KsConstantBufferGL : public KsConstantBuffer
{
		friend class KsRenderContextGL;
	public:
		/**
		 * コンストラクタ
		 * @param	pRenderSystem	描画システム
		 * @param	pData			データ読み込み用のポインタ
		 * @param	size			データサイズ
		 * @param	flags			フラグ
		 */
									KsConstantBufferGL( KsRenderSystemGL* pRenderSystem, void* pData, KsUInt32 size, KsUInt32 flags );

		/**
		 * デストラクタ
		 */
		virtual						~KsConstantBufferGL();

		/**
		 * 定数バッファを生成する
		 * @param	pRenderSystem	描画システム
		 * @param	pData			データ読み込み用のポインタ
		 * @param	size			データサイズ
		 * @retval	ksTRUE			生成成功
		 * @retval	ksFALSE			生成失敗
		 */
		virtual KsBool				create( KsRenderSystemGL* pRenderSystem, void* pData, KsUInt32 size, KsUInt32 flags );


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
		 * 定数バッファをロックする
		 * @param	pContext		描画コンテキスト
		 * @param	flags			ロックフラグ
		 * @return					ロックしたバッファの先頭ポインタ
		 */
		virtual void*				lock( const KsRenderContext* pContext, KsUInt32 flags );

		/**
		 * 定数バッファのロックを解除する
		 * @param	pContext		描画コンテキスト
		 */
		virtual void				unlock( const KsRenderContext* pContext );

		/**
		 * 定数バッファからの読み込み
		 * @param	pContext		描画コンテキスト
		 * @param	pData			データ読み込み用のポインタ
		 * @param	size			データサイズ
		 */
		virtual void				read( const KsRenderContext* pContext, void* pData, KsUInt32 size );

		/**
		 * 定数バッファへの書き込み
		 * @param	pContext		描画コンテキスト
		 * @param	pData			データ読み込み用のポインタ
		 * @param	size			データサイズ
		 */
		virtual void				write( const KsRenderContext* pContext, void* pData, KsUInt32 size );

	protected:
		KsRenderSystemGL*			m_pRenderSystem;		/**< 描画システム			*/
};

ksNS_KS_END


#endif		/* __KSCONSTANTBUFFERGL_H__ */



