/************************************************************************************************/
/** 
 * @file		KsTexture.h
 * @brief		テクスチャ
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0
 */
/************************************************************************************************/
#ifndef __KSTEXTURE_H__
#define __KSTEXTURE_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                           */
/*==============================================================================================*/
#include "KsShaderResource.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/
/* 0から15ビットまでは共通フラグで16ビット以降は固有で拡張用 */
#define ksTEXTURE_FLAG_USE_MANAGER		( 1 << 0 )		/**< テクスチャマネージャを使用する	*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class		KsTexture
 * @brief		テクスチャ
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @note		参照カウンタつき
 */
/************************************************************************************************/
class ksENGINE_API KsTexture : public KsShaderResource
{
		friend class KsTextureManager;

	protected:
		KsUInt32					m_numMipmap;	/**< ミップマップ数				*/
		KsUInt32					m_mipLevels;	/**< ミップマップレベル			*/
		KsUInt16					m_width;		/**< 幅							*/
		KsUInt16					m_height;		/**< 高さ						*/
		KsTexture*					m_pNext;		/**< テクスチャのリスト			*/

	public:
		/**
		 * コンストラクタ
		 */
									KsTexture();

		/**
		 * デストラクタ
		 */
		virtual						~KsTexture();

		/**
		 * テクスチャの破棄
		 */
		virtual void				destroy() = 0;

		/**
		 * テクスチャをアクティブにする
		 */
		virtual void				active() = 0;

		/**
		 * リソースを取得する
		 * @return					 リソース
		 */
		virtual void*				getBufferResource() = 0;

		/**
		 * リソースを取得する
		 * @return					 リソース
		 */
		virtual void*				getTextureResource() = 0;

		/**
		 * バッファをロックする
		 * @param	pContext		描画コンテキスト
		 * @param	flags			ロックフラグ
		 * @return					ロックしたバッファの先頭ポインタ
		 */
		virtual void*				lock( const KsRenderContext* pContext, KsUInt32 flags ) = 0;

		/**
		 * バッファのロックを解除する
		 * @param	pContext		描画コンテキスト
		 */
		virtual void				unlock( const KsRenderContext* pContext ) = 0;

		/**
		 * バッファからの読み込み
		 * @param	pContext		描画コンテキスト
		 * @param	pData			データ読み込み用のポインタ
		 * @param	size			データサイズ
		 */
		virtual void				read( const KsRenderContext* pContext, void* pData, KsUInt32 size ) = 0;

		/**
		 * バッファへの書き込み
		 * @param	pContext		描画コンテキスト
		 * @param	pData			データ読み込み用のポインタ
		 * @param	size			データサイズ
		 */
		virtual void				write( const KsRenderContext* pContext, void* pData, KsUInt32 size ) = 0;

		/**
		 * テクスチャの幅を取得する
		 * @return					テクスチャの幅
		 */
		KsUInt16					getWidth() const { return m_width; }

		/**
		 * テクスチャの高さを取得する
		 * @return					テクスチャの高さ
		 */
		KsUInt16					getHeight() const { return m_height; }

		/**
		 * ミップマップの数を取得
		 * @return					持っているミップマップ数
		 */
		KsUInt32					getNumMipmap() const { return m_numMipmap; }

		/**
		 * ミップマップを持っているかどうか?
		 * @retval	ksTRUE			持っている
		 * @retval	ksFALSE			持っていない
		 */
		KsBool						hasMipmap() { return ( m_numMipmap > 0 ); }

		/**
		 * ミップマップレベルを取得する
		 * @return					ミップマップレベル
		 */
		KsBool						getMipLevels() { return m_mipLevels; }
		
};

/************************************************************************************************/
/**
 * テクスチャリスト
 */
/************************************************************************************************/
typedef KsArray<KsTexture*>	KsTextureArray;

ksNS_KS_END

#endif		/* __KSTEXTURE_H__ */



