/************************************************************************************************/
/** 
 * @file		KsModel.h
 * @brief		モデル
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/
#ifndef __KSMODEL_H__
#define __KSMODEL_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsModelCommon.h"
#include "KsBoneCollection.h"
#include "KsMeshCollection.h"
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
 * @class		KsModel
 * @brief		モデル
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 */
/************************************************************************************************/
class ksENGINE_API KsModel
{
	public:
		KsString					m_modelName;	/// モデル名
		KsBone*						m_pRoot;		/// ルートボーン
		KsBoneCollection			m_vpBones;		/// ボーンコレクション
		KsMeshCollection			m_vpMeshes;		/// オブジェクトのコレクション
		KsTextureCollection			m_vpTextures;	/// テクスチャコレクション
		KsEffectCollection			m_vpEffects;	/// エフェクトコレクション
		KsModelParameter*			m_pParameter;	/// モデルパラメータ
		//KsUserData*				m_pUserData;	/// ユーザーデータ

	public:
		/**
		 * コンストラクタ
		 */
									KsModel();

		/**
		 * デストラクタ
		 */
		virtual						~KsModel();

		/***
		 * 更新処理
		 */
		void						update();

		/** 
		 * 描画処理
		 * @param	pRenderContext	描画コンテキスト
		 */
		void						draw( KsRenderContext* pRenderContext );

		KsBool						updateShaderParameter( const KsModelParameter* pParameter );
		void						updateBoneMatrix();
		void						updateWorldMatrix();
		void						updateSkinMatrix();

		/**
		 * 親子関係を構築する
		 */
		void						createHierarchy();

		/**
		 * マテリアルを構築する
		 */
		void						createMaterial();

	private:
		void						calculateAbsoluteTransforms( KsBone* pBone );

	public:
		const KsString&				getModelName() { return m_modelName; }
		KsModelParameter*			getParameter() { return m_pParameter; }
		KsInt32						getBoneIndex( const KsString& name );
		KsUInt32					getBoneCount() const { return m_vpBones.size(); }
		KsUInt32					getMeshCount() const { return m_vpMeshes.size(); }
		KsUInt32					getTextureCount() const { return m_vpTextures.size(); }
		KsUInt32					getEffectCount() const { return m_vpEffects.size(); }

		const KsBone*				getBone( KsUInt32 index ) { return m_vpBones[ index ]; }
		const KsMesh*				getMesh( KsUInt32 index ) { return m_vpMeshes[ index ]; }
		KsTexture*					getTexture( KsUInt32 index ) { return m_vpTextures[ index ]; }
		const KsEffect*				getEffect( KsUInt32 index ) { return m_vpEffects[ index ]; }
		KsEffect*					getEffectDirect( KsUInt32 index ) { return m_vpEffects[ index ]; }

		virtual void				setWorldMatrix( const KsMatrix4x4& worldMatrix );
		virtual void				setViewMatrix( const KsMatrix4x4& viewMatrix );
		virtual void				setProjectionMatrix( const KsMatrix4x4& projMatrix );

		KsTexture*					findTexture( KsChar* pName );
		

	public:
		void						setModelName( const KsString& modelName ) { m_modelName = modelName; }
		void						addBone( KsBone* pBone ) { m_vpBones.push_back( pBone ); }
		void						addMesh( KsMesh* pMesh ) { m_vpMeshes.push_back( pMesh ); }
		void						addTexture( KsTexture* pTexture );
		void						addEffect( KsEffect* pEffect );
};

ksNS_KS_END


#endif		/* __KSMODEL_H__ */



