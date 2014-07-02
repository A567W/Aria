/************************************************************************************************/
/** 
 * @file		KsShaderResource.h
 * @brief		テクスチャ
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0
 */
/************************************************************************************************/
#ifndef __KSSHADERRESOURCE_H__
#define __KSSHADERRESOURCE_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsGraphicsCommon.h"
#include "KsBufferObject.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class		KsShaderResource
 * @brief		テクスチャ
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @note		参照カウンタつき
 */
/************************************************************************************************/
class ksENGINE_API KsShaderResource : public KsBufferObject
{
		friend class KsTextureManager;

	protected:
		KsString					m_name;			/**< テクスチャ名					*/
		KsUInt32					m_id;			/**< テクスチャID					*/
		KsUInt32					m_flags;		/**< 各種フラグ					*/

	public:
		/**
		 * コンストラクタ
		 */
									KsShaderResource();

		/**
		 * デストラクタ
		 */
		virtual						~KsShaderResource();

		/**
		 * テクスチャの破棄
		 */
		virtual void				destroy() = 0;

		/**
		 * リソースを取得する
		 * @return					 リソース
		 */
		virtual void*				getBufferResource() = 0;

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
		 * テクスチャ名をセットする
		 * @param	pFileName		テクスチャ名
		 */
		void						setName( const KsChar* pFileName );

		/**
		 * フラグ取得
		 * @param	flags			テクスチャの各種フラグ
		 */
		void						setFlags( KsUInt32 flags ) { m_flags = flags; }

		/**
		 * フラグ取得
		 * @return					テクスチャの各種フラグ
		 */
		KsUInt32					getFlags() const { return m_flags; }

		/**
		 * テクスチャ名を取得する
		 * @return					テクスチャ名
		 */
		const KsChar*				getName() { return m_name.c_str(); }

		/**
		 * テクスチャIDを取得する
		 * @return					テクスチャID
		 */
		KsUInt32					getID() const { return m_id; }		
};

ksNS_KS_END

#endif		/* __KSSHADERRESOURCE_H__ */



