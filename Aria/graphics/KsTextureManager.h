/************************************************************************************************/
/** 
 * @file		KsTextureManager.h
 * @brief		テクスチャマネージャ
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/
#ifndef __KSTEXTUREMANAGER_H__
#define __KSTEXTUREMANAGER_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                           */
/*==============================================================================================*/
#include "KsGraphicsCommon.h"
#include "KsTexture.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class		KsTextureManager
 * @brief		テクスチャマネージャ
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @note		本当は、ハッシュテーブルなどを使用したほうがいいがあまりテクスチャは、
 *				あまり、使わないはずなので線形で探索する。
 */
/************************************************************************************************/
class ksENGINE_API KsTextureManager : public KsSingleton< KsTextureManager >
{
	public:
		/**
		 * コンストラクタ
		 */
											KsTextureManager();

		/**
		 * デストラクタ
		 */
		virtual								~KsTextureManager();

		/**
		 * 指定した名前のテクスチャを検索する
		 * 取得した後に参照カウントをあげる必要がある
		 * @param	pFileName				ファイル名
		 * @return							見つかったテクスチャのポインタ
		 */
		virtual KsTexture*					find( const KsChar* pFileName );

		/**
		 * 検索して見つかったら参照カウントをアップする
		 * @param	pFileName				ファイル名
		 * @return							見つかったテクスチャのポインタ
		 */
		virtual KsTexture*					findRefInc( const KsChar* pFileName );

		/**
		 * テクスチャを追加する
		 * DEBUGモードのときは、2重登録チェックをする
		 * @param	pTexture				追加するテクスチャのポインタ
		 * @retval	ksTRUE					成功
		 * @retval	ksFALSE					失敗
		 */
		virtual KsBool						add( KsTexture* pTexture );

		/**
		 * テクスチャをマネージャから取り除く
		 * @param	pTexture				取り除くテクスチャのポインタ
		 * @retval	ksTRUE					成功
		 * @retval	ksFALSE					失敗
		 */
		virtual KsBool						remove( KsTexture* pTexture );

		/**
		 * テクスチャを削除する
		 * @param	pTexture				削除するテクスチャのポインタ
		 * @retval	ksTRUE					成功
		 * @retval	ksFALSE					失敗
		 */
		virtual KsBool						destroy( KsTexture* pTexture );

		/**
		 * すべてのテクスチャを破棄する(参照カウント関係なく破棄される)
		 * @retval	ksTRUE					成功
		 * @retval	ksFALSE					失敗
		 */
		virtual KsBool						destroyAll();

		/**
		 * シングルトンの参照を取得
		 * @return							シングルトンの参照
		 */
		static KsTextureManager&			getInstance();
		
		/**
		 * シングルトンのポインタを取得
		 * @return							シングルトンのポインタ
		 */
		static KsTextureManager*			getInstancePtr();

	protected:
		KsTexture*							m_pTop;		/**< リストの先頭ポインタ	*/
};

ksNS_KS_END

#endif		/* __KSTEXTUREMANAGER_H__ */




