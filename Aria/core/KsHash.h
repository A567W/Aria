/*************************************************************************************************/
/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2014 A567W
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 * 
 * @file	KsHash.h
 * @brief	�n�b�V��
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/
#ifndef __KSHASH_H__
#define __KSHASH_H__

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                            */
/*==============================================================================================*/
#include "KsCoreCommon.h"
#include "KsCrc32.h"
#include "KsString.h"

/*==============================================================================================*/
/*                                     << ��` >>                                               */
/*==============================================================================================*/
#define ksHASH_DEFAULT_SIZE		( 256 )		/**< �f�t�H���g�̃n�b�V���T�C�Y	*/

/*==============================================================================================*/
/*                                     << �錾 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class		KsHashNode
 * @brief		�n�b�V���m�[�h
 * @date		2008/02/06
 * @since		2008/02/06
 * @version		1.0.0
 */
/************************************************************************************************/
template < typename T > class KsHashNode
{
	public:
		typedef KsHashNode< T >	KsHashNodeType;

	public:
		KsUInt32					m_key;			/**< �n�b�V���L�[				*/
		KsString					m_string;		/**< ������					*/
		T							m_pData;		/**< �f�[�^					*/
		KsHashNodeType*				m_pNext;		/**< ���̃m�[�h�̃|�C���^		*/
};

/************************************************************************************************/
/**
 *	@class		KsHashTable
 *	@brief		�n�b�V���e�[�u��
 *	@since		2005/10/25
 *	@author		tukasa kato
 */
/************************************************************************************************/
template < typename T > class KsHashTable
{
	public:
		typedef KsHashNode< T >			KsHashNodeType;

	protected:
		KsInt32							m_size;		/**< �e�[�u���T�C�Y		*/
		KsHashNodeType**				m_pTbl;		/**< �n�b�V���e�[�u��		*/

	public:
		/**
		 * �R���X�g���N�^
		 * @param	size		�n�b�V���T�C�Y
		 */
		KsHashTable( KsInt32 size=ksHASH_DEFAULT_SIZE )
		{
			m_size = size;
			m_pTbl = new KsHashNodeType* [ m_size ];

			for( KsInt32 i=0; i<m_size; i++ ){
				m_pTbl[ i ] = NULL;
			}
		}
	
		/**
		 * �f�X�g���N�^
		 */
		virtual							~KsHashTable()
		{
			clear();
			delete [] m_pTbl;
		}

		/**
		 * @param	size		�n�b�V���T�C�Y
		 */
		void							create( KsInt32 size=ksHASH_DEFAULT_SIZE )
		{
			destory();

			m_size = size;
			m_pTbl = new KsHashNodeType* [ m_size ];

			for( KsInt32 i=0; i<m_size; i++ ){
				m_pTbl[ i ] = NULL;
			}
		}

		/**
		 * �j������
		 */
		void							destory()
		{
			clear();
			ksDELETEARRAY( m_pTbl );
			m_size = 0;
			m_pTbl = 0;
		}

		/**
		 * �n�b�V���m�[�h����������
		 * @param	pString		��������
		 * @return				�n�b�V���m�[�h
		 */
		KsHashNodeType*					find( const KsChar* pString )
		{
			KsChar*				pStr  = const_cast<KsChar*>(pString);
			KsUInt32			key   = KsCrc32( (KsUInt8*)pStr );
			KsUInt32			idx   = key % m_size;
			KsHashNodeType*		pNode = m_pTbl[ idx  ];

			while( pNode ){
				if( pNode->m_key == key ){
					if( pNode->m_string == pString ){
						return pNode;
					}
				}
				pNode = pNode->m_pNext;
			}

			return NULL;
		}

		/**
		 * �n�b�V���m�[�h����������
		 * @param	pString		��������
		 * @return				�n�b�V���m�[�h
		 */
		KsHashNodeType*					find( const KsString& refString )
		{
			KsChar*				pStr  = const_cast<KsChar*>(refString.c_str());
			KsUInt32			key   = KsCrc32( (KsUInt8*)pStr );
			KsUInt32			idx   = key % m_size;
			KsHashNodeType*		pNode = m_pTbl[ idx  ];

			while( pNode )
			{
				if( pNode->m_key == key )
				{
					if( pNode->m_string == refString )
					{
						return pNode;
					}
				}
				pNode = pNode->m_pNext;
			}

			return NULL;
		}

		/**
		 * �n�b�V���m�[�h����������
		 * @param	key			�����L�[
		 * @param	idx			�����C���f�b�N�X
		 * @param	pString		��������
		 * @return				�n�b�V���m�[�h
		 */
		KsHashNodeType*					find( KsUInt32 key, KsUInt32 idx, const KsChar* pString )
		{
			KsHashNodeType*		pNode = m_pTbl[ idx ];

			while( pNode ){
				if( pNode->m_key == key ){
					if( pNode->m_string == pString ){
						return pNode;
					}
				}
				pNode = pNode->m_pNext;
			}

			return NULL;
		}

		/**
		 * �n�b�V���m�[�h����������
		 * @param	key			�����L�[
		 * @param	idx			�����C���f�b�N�X
		 * @param	pString		��������
		 * @return				�n�b�V���m�[�h
		 */
		KsHashNodeType*					find( KsUInt32 key, KsUInt32 idx, const KsString& refString )
		{
			KsHashNodeType*		pNode = m_pTbl[ idx ];

			while( pNode ){
				if( pNode->m_key == key ){
					if( pNode->m_string == refString ){
						return pNode;
					}
				}
				pNode = pNode->m_pNext;
			}

			return NULL;
		}

		/**
		 * �m�[�h��ǉ�����
		 * @param	pString		��������
		 * @param	pData		�f�[�^
		 * @retval	ksTRUE		����
		 * @retval	ksTRUE		���s
		 */
		KsBool							add( const KsChar* pString, T pData )
		{
			KsChar*				pStr  = const_cast<KsChar*>(pString);
			KsUInt32			key   = KsCrc32( (KsUInt8*)pStr );
			KsUInt32			idx   = key % m_size;
			KsHashNodeType*		pNode = find( key, idx, pString );

			if( !pNode )
			{
				pNode = new KsHashNodeType();
				pNode->m_key    = key;
				pNode->m_string = pString;
				pNode->m_pData  = pData;
				pNode->m_pNext  = m_pTbl[ idx ];
				m_pTbl[ idx ]   = pNode;

				return ksTRUE;
			}
		
			/* �l��ς��� */

			return ksFALSE;
		}

		/**
		 * �m�[�h��ǉ�����
		 * @param	pString		��������
		 * @param	pData		�f�[�^
		 * @retval	ksTRUE		����
		 * @retval	ksTRUE		���s
		 */
		KsBool							add( const KsString& refString, T pData )
		{
			KsChar*				pStr  = const_cast<KsChar*>(refString.c_str());
			KsUInt32			key   = KsCrc32( (KsUInt8*)pStr );
			KsUInt32			idx   = key % m_size;
			KsHashNodeType*		pNode = find( key, idx, refString );

			if( !pNode )
			{
				pNode = new KsHashNodeType();
				pNode->m_key    = key;
				pNode->m_string = refString;
				pNode->m_pData  = pData;
				pNode->m_pNext  = m_pTbl[ idx ];
				m_pTbl[ idx ]   = pNode;

				return ksTRUE;
			}
		
			/* �l��ς��� */

			return ksFALSE;
		}

		/**
		 * �폜
		 * @param	pString		��������
		 * @return				�f�[�^
		 */
		T								destroy( const KsChar* pString )
		{
			KsChar*				pStr  = const_cast<KsChar*>(pString);
			KsUInt32			key   = KsCrc32( (KsUInt8*)pStr );
			KsUInt32			idx   = key % m_size;
			KsHashNodeType*		pNode = m_pTbl[ idx ];

			if( pNode )
			{
				/* �擪�����`�F�b�N */
				if( key == pNode->m_key ){
					if( pNode->m_string == pString ){
						T					pData = pNode->m_pData;
						m_pTbl[ idx  ] = pNode->m_pNext;
						delete pNode;
						return pData;
					}
				}
			
				while( pNode->m_pNext )
				{
					if( key == pNode->m_pNext->m_key )
					{
						if( pNode->m_string == pString )
						{
							KsHashNodeType*		pTemp = pNode->m_pNext;
							T					pData = pTemp->m_pData;
							pNode->m_pNext = pTemp->m_pNext;
							delete pTemp;
							return pData;
						}
					}
					pNode = pNode->m_pNext;
				}
			}

			return NULL;
		}

		/**
		 * �N���A
		 */
		void							clear()
		{
			for( KsInt32 i=0; i<m_size; i++ )
			{
				KsHashNodeType*		pNode = m_pTbl[ i ];
				KsHashNodeType*		pTemp;

				while( pNode )
				{
					pTemp = pNode;
					pNode = pNode->m_pNext;
					delete pTemp;
				}
			}
		}
};

ksNS_KS_END

#endif		/* __KSHASH_H__	*/

