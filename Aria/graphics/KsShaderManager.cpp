/************************************************************************************************/
/** 
 * @file		KsShaderManager.cpp
 * @brief		シェーダーマネージャー
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/

/*==============================================================================================*/
/*                                 << インクルード >>                                           */
/*==============================================================================================*/
#include "KsShaderManager.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

template<> KsShaderManager* KsSingleton< KsShaderManager >::m_pInstance = 0;

/************************************************************************************************/
/*
 * シングルトンの参照を取得
 * @return							シングルトンの参照
 */
/************************************************************************************************/
KsShaderManager& KsShaderManager::getInstance()
{  
	return (*m_pInstance);  
}
/************************************************************************************************/
/*
 * シングルトンのポインタを取得
 * @return							シングルトンのポインタ
 */
/************************************************************************************************/
KsShaderManager* KsShaderManager::getInstancePtr()
{
	return m_pInstance;
}


/************************************************************************************************/
/*
 * 指定した名前のテクスチャを検索する
 * 取得した後に参照カウントをあげる必要がある
 * @param	pFileName				ファイル名
 * @return							見つかったテクスチャのポインタ
 */
/************************************************************************************************/
KsShaderProgram* KsShaderManager::find( const KsChar* pFileName )
{
	KsHashNode<KsShaderProgram*>*		pNode;

	pNode = m_pShaders.find( pFileName );

	if( pNode )
	{
		return pNode->m_pData;
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
KsShaderProgram* KsShaderManager::findRefInc( const KsChar* pFileName )
{
	KsShaderProgram*	pShader = find( pFileName );

	if( pShader )
	{
		pShader->inc();
	}

	return pShader;
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
KsBool KsShaderManager::add( KsShaderProgram* pShader )
{
	KsHashNode<KsShaderProgram*>*		pNode;

	pNode = m_pShaders.find( pShader->getName().c_str() );

	if( !pNode )
	{
		m_pShaders.add( pShader->getName().c_str(), pShader );
	}

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
KsBool KsShaderManager::remove( KsShaderProgram* pShader )
{
	m_pShaders.destroy( pShader->getName().c_str() );

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
KsBool KsShaderManager::destroy( KsShaderProgram* pShader )
{
#ifdef _DEBUG
	if( pShader->getRefCount() < 1 )
	{
		//StPrintf("texture ref count(%d)\n", pTexture->getRefCount() );
		return ksFALSE;
	}
#endif

	/* 参照カウントが1だったらテクスチャマネージャから取り除く */
	if( pShader->getRefCount() == 1 )
	{
		if( !remove( pShader ) )
		{
			return ksFALSE;
		}
	}

	/* 参照カウントを下げる */
	pShader->dec();

	return ksTRUE;
}

/************************************************************************************************/
/*
 * すべてのテクスチャを破棄する(参照カウント関係なく破棄される)
 * @retval	ksTRUE					成功
 * @retval	ksFALSE					失敗
 */
/************************************************************************************************/
KsBool KsShaderManager::destroyAll()
{
#if 0
	KsTexture*		pTemp = m_pTop;
	KsTexture*		pTexture;

	while( pTemp )
	{
		pTexture = pTemp;
		pTemp    = pTemp->m_pNext;

		delete pTexture;
	}

	m_pTop = NULL;
#endif

	return ksTRUE;
}

ksNS_KS_END

