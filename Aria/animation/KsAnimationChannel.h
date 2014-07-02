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
 * @file	KsAnimationChannel.h
 * @brief	アニメーションチャンネルクラス
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
/************************************************************************************************/
#ifndef __KSANIMATIONCHANNEL_H__
#define __KSANIMATIONCHANNEL_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsAnimationCommon.h"
#include "KsKeyFrameCollection.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class		KsAnimationChannel
 * @brief		アニメーションチャンネルクラス
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 */
/************************************************************************************************/
class ksENGINE_API KsAnimationChannel
{
	private:
		KsHashTable<KsKeyFrameCollection*>		m_dict;
		KsArray<KsKeyFrameCollection*>			m_fames;
		KsUInt32								m_numCollection;
		KsArray<KsString>						m_affectedBones;
			
	public:
		/**
		 * コンストラクタ
		 */
		KsAnimationChannel();

		/**
		 * コンストラクタ
		 */
		KsAnimationChannel( KsKeyFrameCollection* pKeyFrameCollection, KsUInt32 numCollection );

		/**
		 * デストラクタ
		 */
		~KsAnimationChannel();

		void					addKeyFrameCollection( const KsString& boneName, KsKeyFrameCollection* pKeyFrameCollection )
		{
			m_dict.add( boneName, pKeyFrameCollection );
			m_fames.push_back( pKeyFrameCollection );
			++m_numCollection;
		}

		KsKeyFrameCollection*	getKeyFrameCollection( const KsString& boneName )
		{
			KsHashTable<KsKeyFrameCollection*>::KsHashNodeType*	pNode = m_dict.find( boneName );

			if( pNode )
			{
				return pNode->m_pData;
			}

			return NULL;
		}

		KsBool hasAffectsBone( const KsString& boneName )
		{
			return ( NULL != m_dict.find( boneName ) );
		}


		KsArray<KsString>&		getAffectedBones()
		{
			return m_affectedBones;
		}

		const KsString&			getAffectedBone( KsUInt32 index )
		{
			return m_affectedBones[ index ];
		}

		KsKeyFrameCollection*	getKeyFrameCollection( KsUInt32 index )
		{
			return m_fames[ index ];
		}

		KsUInt32				getNumCollection() const { return m_fames.size(); }
};

ksNS_KS_END

#endif /* __KSANIMATIONCHANNEL_H__ */

