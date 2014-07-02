/************************************************************************************************/
/** 
 * @file		KsTextureManager.cpp
 * @brief		テクスチャマネージャ
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0
 */
/************************************************************************************************/

/*==============================================================================================*/
/*                                 << インクルード >>                                           */
/*==============================================================================================*/
#include "KsTextureManager.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

template<> KsTextureManager* KsSingleton< KsTextureManager >::m_pInstance = 0;

/************************************************************************************************/
/*
 * コンストラクタ
 */
/************************************************************************************************/
KsTextureManager::KsTextureManager() : m_pTop( 0 )
{
}

/************************************************************************************************/
/*
 * デストラクタ
 */
/************************************************************************************************/
KsTextureManager::~KsTextureManager()
{
}

/************************************************************************************************/
/*
 * 指定した名前のテクスチャを検索する
 * 取得した後に参照カウントをあげる必要がある
 * @param	pFileName				ファイル名
 * @return							見つかったテクスチャのポインタ
 */
/************************************************************************************************/
KsTexture* KsTextureManager::find( const KsChar* pFileName )
{
	KsTexture*		pTemp = m_pTop;
	KsUInt32		id    = KsCrc32( (KsUInt8*)pFileName );

	while( pTemp )
	{
		if( id == pTemp->m_id )
		{
			/* 文字列が等しいかをチェックする */
			if( ks_strcmp( pFileName, pTemp->m_name.c_str() ) == 0 )
			{
				return pTemp;
			}
		}

		pTemp = pTemp->m_pNext;
	}

	return NULL;
}

/************************************************************************************************/
/*
 * 検索して見つかったら参照カウントをアップする
 * @param	pFileName				ファイル名
 * @return							見つかったテクスチャのポインタ
 */
/************************************************************************************************/
KsTexture* KsTextureManager::findRefInc( const KsChar* pFileName )
{
	KsTexture*		pTexture = find( pFileName );

	if( pTexture )
	{
		pTexture->inc();
	}

	return pTexture;
}

/************************************************************************************************/
/*
 * テクスチャを追加する
 * DEBUGモードのときは、2重登録チェックをする
 * @param	pTexture				追加するテクスチャのポインタ
 * @retval	ksTRUE					成功
 * @retval	ksFALSE					失敗
 */
/************************************************************************************************/
KsBool KsTextureManager::add( KsTexture* pTexture )
{
	pTexture->m_pNext = m_pTop;
	m_pTop            = pTexture;

	pTexture->m_flags |= ksTEXTURE_FLAG_USE_MANAGER;

	return ksTRUE;
}

/************************************************************************************************/
/*
 * テクスチャをマネージャから取り除く
 * @param	pTexture				取り除くテクスチャのポインタ
 * @retval	ksTRUE					成功
 * @retval	ksFALSE					失敗
 */
/************************************************************************************************/
KsBool KsTextureManager::remove( KsTexture* pTexture )
{
	KsTexture*		pPrev;
	KsTexture*		pTemp;
	KsUInt32		id;

	if( m_pTop == NULL )
	{
		return ksFALSE;
	}

	if( pTexture == m_pTop )
	{
		m_pTop = m_pTop->m_pNext;
		return ksTRUE;
	}

	pPrev = m_pTop;
	pTemp = m_pTop->m_pNext;
	id    = KsCrc32( (KsUInt8*)(pTexture->m_name.c_str()) );

	while( pTemp )
	{
		if( id == pTemp->m_id )
		{
			/* 文字列が等しいかをチェックする */
			if( ks_strcmp( pTexture->m_name.c_str(), pTemp->m_name.c_str() ) == 0 )
			{
			//if( pTexture->m_name == pTemp->m_name ){
				pPrev->m_pNext = pTemp->m_pNext;
				return ksTRUE;
			}
		}

		pPrev = pTemp;
		pTemp = pTemp->m_pNext;

	}

	return ksFALSE;
}

/************************************************************************************************/
/*
 * テクスチャを削除する
 * @param	pTexture				削除するテクスチャのポインタ
 * @retval	ksTRUE					成功
 * @retval	ksFALSE					失敗
 */
/************************************************************************************************/
KsBool KsTextureManager::destroy( KsTexture* pTexture )
{
#ifdef _DEBUG
	if( pTexture->getRefCount() < 1 )
	{
		//StPrintf("texture ref count(%d)\n", pTexture->getRefCount() );
		return ksFALSE;
	}
#endif

	/* 参照カウントが1だったらテクスチャマネージャから取り除く */
	if( pTexture->getRefCount() == 1 )
	{
		if( !remove( pTexture ) )
		{
			return ksFALSE;
		}
	}

	/* 参照カウントを下げる */
	pTexture->dec();

	return ksTRUE;
}

/************************************************************************************************/
/*
 * すべてのテクスチャを破棄する(参照カウント関係なく破棄される)
 * @retval	ksTRUE					成功
 * @retval	ksFALSE					失敗
 */
/************************************************************************************************/
KsBool KsTextureManager::destroyAll()
{
	KsTexture*		pTemp = m_pTop;
	KsTexture*		pTexture;

	while( pTemp )
	{
		pTexture = pTemp;
		pTemp    = pTemp->m_pNext;

		delete pTexture;
	}

	m_pTop = NULL;

	return ksTRUE;
}


/************************************************************************************************/
/*
 * シングルトンの参照を取得
 * @return							シングルトンの参照
 */
/************************************************************************************************/
KsTextureManager& KsTextureManager::getInstance()
{  
	return (*m_pInstance);  
}

/************************************************************************************************/
/*
 * シングルトンのポインタを取得
 * @return							シングルトンのポインタ
 */
/************************************************************************************************/
KsTextureManager* KsTextureManager::getInstancePtr()
{
	return m_pInstance;
}

ksNS_KS_END

