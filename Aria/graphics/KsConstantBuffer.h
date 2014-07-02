/************************************************************************************************/
/** 
 * @file		KsConstantBuffer.h
 * @brief		定数バッファ
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/
#ifndef __KSCONSTANTBUFFER_H__
#define __KSCONSTANTBUFFER_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsBufferObject.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

class KsRenderContext;

/************************************************************************************************/
/**
 * @class		KsConstantBuffer
 * @brief		定数バッファ
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 */
/************************************************************************************************/
class ksENGINE_API KsConstantBuffer : public KsBufferObject
{
	public:
		/**
		 * コンストラクタ
		 */
									KsConstantBuffer();

		/**
		 * デストラクタ
		 */
		virtual						~KsConstantBuffer();

		/**
		 * 破棄処理
		 */
		virtual void				destroy() = 0;

		/**
		 * リソースを取得する
		 * @return					 リソース
		 */
		virtual void*				getBufferResource() = 0;

		/**
		 * インデックスバッファをロックする
		 * @param	pContext		描画コンテキスト
		 * @param	flags			ロックフラグ
		 * @return					ロックしたバッファの先頭ポインタ
		 */
		virtual void*				lock( const KsRenderContext* pContext, KsUInt32 flags ) = 0;

		/**
		 * インデックスバッファのロックを解除する
		 * @param	pContext		描画コンテキスト
		 */
		virtual void				unlock( const KsRenderContext* pContext ) = 0;

		/**
		 * インデックスバッファからの読み込み
		 * @param	pContext		描画コンテキスト
		 * @param	pData			データ読み込み用のポインタ
		 * @param	size			データサイズ
		 */
		virtual void				read( const KsRenderContext* pContext, void* pData, KsUInt32 size ) = 0;

		/**
		 * インデックスバッファへの書き込み
		 * @param	pContext		描画コンテキスト
		 * @param	pData			データ読み込み用のポインタ
		 * @param	size			データサイズ
		 */
		virtual void				write( const KsRenderContext* pContext, void* pData, KsUInt32 size ) = 0;

		/**
		 * バッファサイズを取得する
		 * @return					バッファサイズ
		 */
		KsUInt32					getBufferSize() const { return m_bufferSize; }

	protected:
		KsUInt32					m_bufferSize;		/**< バッファサイズ		*/
};

ksNS_KS_END

#endif		/* __KSCONSTANTBUFFER_H__ */



