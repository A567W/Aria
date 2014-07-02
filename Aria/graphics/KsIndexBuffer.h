/************************************************************************************************/
/** 
 * @file		KsIndexBuffer.h
 * @brief		インデックスバッファ
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/
#ifndef __KSINDEXBUFFER_H__
#define __KSINDEXBUFFER_H__

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
 * @class		KsIndexBuffer
 * @brief		インデックスバッファ
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 */
/************************************************************************************************/
class ksENGINE_API KsIndexBuffer : public KsBufferObject
{
	public:
		/**
		 * コンストラクタ
		 */
									KsIndexBuffer();

		/**
		 * デストラクタ
		 */
		virtual						~KsIndexBuffer();

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
		 * インデックス数を取得する
		 * @return					インデックス数
		 */
		KsUInt32					getNumIndex() const { return m_numIndex; }

		/**
		 * インデックスのフォーマットタイプを取得する
		 */
		KsUInt32					getIndexFormatType() const { return m_indexFormatType; }

	protected:
		KsUInt32					m_numIndex;			/**< インデックス数					*/
		KsUInt32					m_indexFormatType;	/**< インデックスのフォーマットタイプ	*/
};

ksNS_KS_END

#endif		/* __KSINDEXBUFFER_H__ */



