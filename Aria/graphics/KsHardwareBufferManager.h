/************************************************************************************************/
/** 
 * @file		KsHardwareBufferManager.h
 * @brief		バッファマネージャ
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/
#ifndef __KSHARDWAREBUFFERMANAGER_H__
#define __KSHARDWAREBUFFERMANAGER_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                           */
/*==============================================================================================*/
#include "KsGraphicsCommon.h"
#include "KsEffect.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class		KsHardwareBufferManager
 * @brief		バッファマネージャ
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 */
/************************************************************************************************/
class ksENGINE_API KsHardwareBufferManager : public KsSingleton< KsHardwareBufferManager >
{
	public:
		/**
		 * コンストラクタ
		 */
											KsHardwareBufferManager(){}

		/**
		 * デストラクタ
		 */
		virtual								~KsHardwareBufferManager(){}

		/**
		 * 頂点バッファを生成する
		 * @param		vertexSize			頂点サイズ
		 * @param		numVertex			頂点数
		 * @param		vertexFormat		頂点フォーマット
		 * @param		flags				フラグ
		 * @return							頂点バッファのポインタ
		 */
		virtual KsVertexBuffer*				createVertexBuffer( KsUInt32 vertexSize, KsUInt32 numVertex, KsUInt32 vertexFormat, KsUInt32 flags ) = 0;

		/**
		 * 頂点バッファを生成する
		 * @param		vertexSize			[in] 頂点サイズ
		 * @param		numVertex			[in] 頂点数
		 * @param		vertexFormat		[in] 頂点フォーマット
		 * @param		flags				[in] フラグ
		 * @return							頂点バッファのポインタ
		 */
		virtual KsVertexBuffer*				createVertexBuffer( void* pData, KsUInt32 vertexSize, KsUInt32 numVertex, KsUInt32 vertexFormat, KsUInt32 flags ) = 0;

		/**
		 * インデックスバッファを生成する
		 * @param		numIndex			インデックス数
		 * @param		flags				フラグ
		 * @return							インデックスバッファのポインタ
		 */
		virtual KsIndexBuffer*				createIndexBuffer( KsUInt32 numIndex, KsUInt32 indexFormat, KsUInt32 flags ) = 0;

		/**
		 * インデックスバッファを生成する
		 * @param	pData					[in] データ読み込み用のポインタ
		 * @param	size					[in] データサイズ
		 * @param	numIndex				[in] インデックスの数
		 * @param	indexFormat				[in] インデックスフォーマット
		 * @param	flags					[in] フラグ
		 * @return							インデックスバッファのポインタ
		 */
		virtual KsIndexBuffer*				createIndexBuffer( void* pData, KsUInt32 size, KsUInt32 numIndex, KsUInt32 indexFormat, KsUInt32 flags ) = 0;

		/**
		 * 定数バッファを生成する
		 * @param	pData				    [in] データ読み込み用のポインタ
		 * @param	size				    [in] データサイズ
		 * @param	flags				    [in] フラグ
		 * @return						    定数バッファのポインタ
		 */
		virtual KsConstantBuffer*		    createConstantBuffer( KsUInt32 size, KsUInt32 flags ) = 0;

		/**
		 * 定数バッファを生成する
		 * @param	size				    [in] バッファサイズ
		 * @param	flags				    [in] フラグ
		 * @return						    定数バッファのポインタ
		 */
		virtual KsConstantBuffer*		    createConstantBuffer( void* pData, KsUInt32 size, KsUInt32 flags ) = 0;

		/**
		 * シングルトンの参照を取得
		 * @return							シングルトンの参照
		 */
		static KsHardwareBufferManager&		getInstance();
		
		/**
		 * シングルトンのポインタを取得
		 * @return							シングルトンのポインタ
		 */
		static KsHardwareBufferManager*		getInstancePtr();
};

ksNS_KS_END

#endif		/* __KSHARDWAREBUFFERMANAGER_H__ */



