/************************************************************************************************/
/** 
 * @file		KsStructuredBufferDX11.h
 * @brief		UAVクラス
 * @author		Tsukasa Kato
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/
#ifndef __KSSTRUCTUREBUFFERDX11_H__
#define __KSSTRUCTUREBUFFERDX11_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                           */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/

/************************************************************************************************/
/**
 * @class		KsStructuredBuffer
 * @brief		UAVクラス
 * @author		Tsukasa Kato
 * @date		----/--/--
 * @since		----/--/--
 * @note		参照カウンタつき
 */
/************************************************************************************************/
class ksDEVDX11_API KsStructuredBufferDX11 : public KsStructuredBuffer
{
		friend class KsRenderContextDX11;
	public:
		/**
		 * コンストラクタ( UAVバッファを生成する )
		 * @param	pRenderSystem	描画システム
		 * @param	elementSize		要素サイズ
		 * @param	numElements		要素数
		 * @param	format			フォーマット
		 * @param	flags			フラグ
		 */
									KsStructuredBufferDX11( KsRenderSystemDX11* pRenderSystem, KsUInt32 elementSize, KsUInt32 numElements, KsUInt32 format, KsUInt32 flags );

		/**
		 * デストラクタ
		 */
		virtual						~KsStructuredBufferDX11();

		/**
		 * UAVバッファを生成する
		 * @param	pRenderSystem	描画システム
		 * @param	elementSize		要素サイズ
		 * @param	numElements		要素数
		 * @param	format			フォーマット
		 * @param	flags			フラグ
		 * @retval	ksTRUE			生成成功
		 * @retval	ksFALSE			生成失敗
		 */
		virtual KsBool				create( KsRenderSystemDX11* pRenderSystem, KsUInt32 elementSize, KsUInt32 numElements, KsUInt32 format, KsUInt32 flags );

		/**
		 * 破棄処理
		 */
		virtual void				destroy();

		/**
		 * テクスチャをアクティブにする
		 */
		virtual void				active();

		/**
		 * リソースを取得する
		 * @return					 リソース
		 */
		virtual void*				getBufferResource();

		/**
		 * リソースを取得する
		 * @return					リソース
		 */
		virtual void*				getTextureResource() { return m_pShaderResourceView; }

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
		KsUInt32					m_elementSize;
		KsUInt32					m_numElements;
		KsUInt32					m_format;
		ID3D11Buffer*				m_pBuffer;
		ID3D11ShaderResourceView*	m_pShaderResourceView;
		ID3D11UnorderedAccessView*	m_pUnorderedAccessView;
};

#endif		/* __KSSTRUCTUREBUFFERDX11_H__ */



