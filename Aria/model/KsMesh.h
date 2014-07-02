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
 * @file	KsMesh.h
 * @brief	メッシュクラス
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
/************************************************************************************************/
#ifndef __KSMESH_H__
#define __KSMESH_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsModelCommon.h"
#include "KsMeshPartCollection.h"
#include "KsModelParameter.h"


/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class		KsMeshPart
 * @brief		メッシュパーツ
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 */
/************************************************************************************************/
class ksENGINE_API KsMesh
{
	private:
		KsString					m_name;				/// このメッシュの名前を取得します。
		//KsBoundingSphere			m_boundingSphere;	/// このメッシュが含まれている BoundingSphere を取得します。
		KsMeshPartCollection		m_vpMeshParts;		/// このメッシュを構成する ModelMeshPart オブジェクトを取得します。メッシュの各パーツは、同じマテリアルを共有するプリミティブの集合で構成されています。
		//KsEffectCollection			m_vpEffects;		/// このメッシュに関連付けられているエフェクトのコレクションを取得します。
		//KsUserData*				m_pUserData;		/// ユーザーデータ

		//     このメッシュに関連付けられているエフェクトのコレクションを取得します。
		//ModelEffectCollection		Effects

		//     このメッシュの親ボーンを取得します。メッシュの親ボーンにはモデルで親メッシュに関連したメッシュを配置する方法を記述する変換行列が含まれます。
		//ModelBone					ParentBone

	public:
		/**
		 * コンストラクタ
		 */
									KsMesh();

		/**
		 * デストラクタ
		 */
		virtual						~KsMesh();

		/** 
		 * 描画処理
		 * @param	pRenderContext	描画コンテキスト
		 */
		virtual void				draw( KsRenderContext* pRenderContext, KsModelParameter* pParameter=NULL );

		//     現在の Effect 設定を使用して、このメッシュ内のすべての ModelMeshPart オブジェクトを描画します。
		KsMeshPart*					getMeshPart( KsUInt32 index ) { return m_vpMeshParts[ index ]; }
		KsUInt32					getMeshPartCount() const { return m_vpMeshParts.size(); }

	public:
		void						addMeshParts( KsMeshPart* pMeshPart ) { m_vpMeshParts.push_back( pMeshPart ); }
};

ksNS_KS_END

#endif		/* __KSMESH_H__ */



