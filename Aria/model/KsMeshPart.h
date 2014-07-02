/************************************************************************************************/
/** 
 * @file		KsMeshPart.h
 * @brief		メッシュパーツ
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/
#ifndef __KSMESHPART_H__
#define __KSMESHPART_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsModelCommon.h"
#include "KsBoneCollection.h"
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
class ksENGINE_API KsMeshPart
{
	public:
		/**
		 * コンストラクタ
		 */
									KsMeshPart();

		/**
		 * コンストラクタ( メッシュパーツを生成します。)
		 * @param	pEffect			使用するエフェクトデータ
		 * @param	pIndexBuffer	メッシュ部分のインデックス バッファー
		 * @param	pVertexBuffer	メッシュ パーツの頂点バッファー
		 * @param	pInputLayout	インプットレイアウト
		 * @param	numVertices		描画呼び出し中に使用される頂点の数
		 * @param	primitiveCount	レンダリングするプリミティブの数
		 * @param	startIndex		インデックス配列の中で頂点の読み取りを開始する位置
		 * @param	vertexOffset	頂点バッファーの最上部からのオフセット
		 */
									KsMeshPart( KsEffect*		pEffect,
												KsIndexBuffer*	pIndexBuffer,
												KsVertexBuffer*	pVertexBuffer,
												KsInputLayout*	pInputLayout,
												KsInt32	numVertices,
												KsInt32	primitiveCount,
												KsInt32	startIndex,
												KsInt32 vertexOffset );

		/**
		 * デストラクタ
		 */
		virtual						~KsMeshPart();

		/**
		 * メッシュパーツを生成します。
		 * @param	pEffect			使用するエフェクトデータ
		 * @param	pIndexBuffer	メッシュ部分のインデックス バッファー
		 * @param	pVertexBuffer	メッシュ パーツの頂点バッファー
		 * @param	pInputLayout	インプットレイアウト
		 * @param	numVertices		描画呼び出し中に使用される頂点の数
		 * @param	primitiveCount	レンダリングするプリミティブの数
		 * @param	startIndex		インデックス配列の中で頂点の読み取りを開始する位置
		 * @param	vertexOffset	頂点バッファーの最上部からのオフセット
		 */
		void						create( KsEffect*		pEffect,
											KsIndexBuffer*	pIndexBuffer,
											KsVertexBuffer*	pVertexBuffer,
											KsInputLayout*	pInputLayout,
											KsInt32	numVertices,
											KsInt32	primitiveCount,
											KsInt32	startIndex,
											KsInt32 vertexOffset );

		/**
		 * マトリックスパレットを生成します。
		 * @param	numPallet		マトリックスパレット数
		 * @param	pPallet			マトリックスパレット
		 */
		void						createPallet( KsInt32 numPallet, KsInt32* pPallet );

		/**
		 * メッシュパーツを破棄します。
		 */
		void						destroy();

		/** 
		 * 描画処理
		 * @param	pRenderContext	描画コンテキスト
		 */
		void						draw( KsRenderContext* pRenderContext, KsModelParameter* pParameter=NULL );

		/**
		 * このメッシュ部分のインデックス バッファーを取得します。
		 * @return	メッシュ部分のインデックス バッファー	
		 */
		KsIndexBuffer*				getIndexBuffer() { return  m_pIndexBuffer; }

		/**
		 * このメッシュ パーツの頂点バッファーを取得します。
		 * @return	メッシュ パーツの頂点バッファー
		 */
		KsVertexBuffer*				getVertexBuffer() { return m_pVertexBuffer; }

		/**
		 * 描画呼び出し中に使用される頂点の数を取得します。
		 * @return	頂点の数
		 */
		KsInt32						getNumVertices() const { return m_numVertices; }

		/**
		 * レンダリングするプリミティブの数を取得します。
		 * @return	プリミティブの数
		 */
		KsInt32						getPrimitiveCount() const { return m_primitiveCount; }

		/**
		 * インデックス配列の中で頂点の読み取りを開始する位置を取得します。
		 * @return	インデックス配列の中で頂点の読み取りを開始する位置
		 */
		KsInt32						getStartIndex() const { return m_startIndex; }

		/**
		 * 頂点バッファーの最上部からのオフセットを (頂点数単位で) 取得します。
		 * @return	頂点バッファーの最上部からのオフセット
		 */
		KsInt32						getVertexOffset() const { return m_vertexOffset; }

		/**
		 * 使用マトリックスパレット
		 */
		KsInt32						getNumMatrixPallet() const { return m_numPallet; }

		/**
		 * 使用マトリックスパレット
		 */
		KsInt32						getMatrixPallet( KsInt32 index ) { return m_pPallet[ index ]; }

		/**
		 * エフェクトIDを取得します。
		 * @return	エフェクト
		 */
		KsUInt32					getEffectID() const { return m_effectID; }

		/**
		 * エフェクトIDをセットします。
		 * @return	エフェクト
		 */
		void						setEffectID( KsUInt32 effectID ) { m_effectID = effectID; }

		/**
		 * エフェクトを取得します。
		 * @return	エフェクト
		 */
		KsEffect*					getEffect() { return m_pEffect; }

		/**
		 * エフェクトをセットします。
		 * @param	pEffect			エフェクト
		 */
		void						setEffect( KsEffect* pEffect ) { m_pEffect = pEffect; }

		/**
		 * ボーンと追加する
		 * @param	pBone			ボーン
		 */
		void						addBone( KsBone* pBone ) { m_vpBones.push_back( pBone ); }

		/**
		 * ボーン数を取得します。
		 * @return	ボーン数
		 */
		KsInt32						getNumBone() const { return (KsInt32)m_vpBones.size(); }

		/**
		 * ボーン数を取得します。
		 * @return	ボーン数
		 */
		KsBone*						getBone( KsUInt32 index ) { return m_vpBones[ index ]; }

		/**
		 * パラメーターを更新する
		 */
		void						updateParameter( KsModelParameter* pParameter );

	private:
		KsUInt32					m_effectID;			/// 使用エフェクトID
		KsEffect*					m_pEffect;			/// 使用エフェクト
		KsIndexBuffer*				m_pIndexBuffer;		/// メッシュ部分のインデックス バッファー
		KsVertexBuffer*				m_pVertexBuffer;	/// メッシュ パーツの頂点バッファー
		KsInputLayout*				m_pInputLayout;		/// インプットレイアウト
		KsInt32						m_numVertices;		/// 描画呼び出し中に使用される頂点の数
		KsInt32						m_primitiveCount;	/// レンダリングするプリミティブの数
		KsInt32						m_startIndex;		/// インデックス配列の中で頂点の読み取りを開始する位置
		KsInt32						m_vertexOffset;		/// 頂点バッファーの最上部からのオフセット
		KsInt32						m_numPallet;		/// 使用マトリックスパレット数
		KsInt32*					m_pPallet;			/// 使用マトリックスパレット
		KsBoneCollection			m_vpBones;			/// ボーンコレクション
		//KsUserData*				m_pUserData;		/// ユーザーデータ
};

ksNS_KS_END

#endif		/* __KSMESHPART_H__ */



