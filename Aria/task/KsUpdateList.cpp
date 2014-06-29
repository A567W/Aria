/************************************************************************************************/
/** 
 * @file		KsUpdateList.cpp
 * @brief		描画処理
 * @author		A567W
 * @date		2011/10/17
 * @since		2011/10/17
 * @version		1.0.0
 */
/************************************************************************************************/

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsUpdateList.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/*
 * コンストラクタ
 */
/************************************************************************************************/
KsUpdateList::KsUpdateList()
	: m_isActive( 0 )
	, m_pUpdateRoot( 0 )
	, m_pUpdateLast( 0 )
	, m_pUpdateThread( 0 )
{
}

/************************************************************************************************/
/*
 * デストラクタ
 */
/************************************************************************************************/
KsUpdateList::~KsUpdateList()
{
}

/************************************************************************************************/
/*
 * 描画タスクを追加する
 * @param		pUpdate				描画タスク
 */
/************************************************************************************************/
void KsUpdateList::add( KsUpdate* pUpdate )
{
	if( NULL == m_pUpdateRoot && NULL == m_pUpdateLast )
	{
		m_pUpdateRoot = pUpdate;
		m_pUpdateLast = pUpdate;
	}
	else
	{
		if( m_pUpdateRoot->getUpdatePriority() == m_pUpdateLast->getUpdatePriority() )
		{
			// 描画プライオリティが一緒なのでラストに追加する
			m_pUpdateLast->m_pUpdateNext = pUpdate;

			pUpdate->m_pUpdatePrev = m_pUpdateLast;
			pUpdate->m_pUpdateNext = NULL;

			m_pUpdateLast = pUpdate;
		}
		else
		{
			KsUpdate* pTemp = m_pUpdateLast;

			while( pTemp )
			{
				if( pTemp->getUpdatePriority() <= pUpdate->getUpdatePriority() )
				{
					break;
				}
				pTemp = pTemp->m_pUpdatePrev;
			}

			if( pTemp )
			{
				// ラストに追加する
				if( pTemp == m_pUpdateLast )
				{
					m_pUpdateLast->m_pUpdateNext = pUpdate;

					pUpdate->m_pUpdatePrev = m_pUpdateLast;
					pUpdate->m_pUpdateNext = NULL;

					m_pUpdateLast = pUpdate;
				}
				else
				{
					// 途中に追加する
					pUpdate->m_pUpdatePrev = pTemp;
					pUpdate->m_pUpdateNext = pTemp->m_pUpdateNext;
					pTemp->m_pUpdateNext = pUpdate;
				}

			}
			else
			{
				// 先頭に追加する
				m_pUpdateRoot->m_pUpdatePrev = pUpdate;

				pUpdate->m_pUpdatePrev = NULL;
				pUpdate->m_pUpdateNext = m_pUpdateRoot;

				m_pUpdateRoot = pUpdate;

			}
		}
	}
}

/************************************************************************************************/
/*
 * 描画タスクを取り除く
 * @param		pUpdate				描画タスク
 */
/************************************************************************************************/
void KsUpdateList::remove( KsUpdate* pUpdate )
{
}

/************************************************************************************************/
/*
 * 描画タスクを取り除く
 * @param		pUpdate				描画タスク
 */
/************************************************************************************************/
void KsUpdateList::update( void* pParam )
{
	KsUpdate* pUpdate = m_pUpdateLast;

	while( pUpdate )
	{
		pUpdate->update( pParam );

		pUpdate = pUpdate->m_pUpdatePrev;
	}
}
	
ksNS_KS_END

