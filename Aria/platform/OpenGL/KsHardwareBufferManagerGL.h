/************************************************************************************************/
/** 
 * @file		KsHardwareBufferManagerGL.h
 * @brief		バッファマネージャ
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/
#ifndef __KSBUFFERMANAGERGL_H__
#define __KSBUFFERMANAGERGL_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                           */
/*==============================================================================================*/
#include "KsCommonGL.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

class KsRenderSystemGL;

/************************************************************************************************/
/**
 * @class		KsBufferManager
 * @brief		バッファマネージャ
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 */
/************************************************************************************************/
class ksENGINE_API KsHardwareBufferManagerGL : public KsHardwareBufferManager
{
	public:
		/**
		 * コンストラクタ
		 * @param	pRenderSystem		描画システム
		 */
										KsHardwareBufferManagerGL( KsRenderSystemGL* pRenderSystem );

		/**
		 * デストラクタ
		 */
		virtual							~KsHardwareBufferManagerGL();

		/**
		 * 頂点バッファを生成する
		 * @param		vertexSize		[in] 頂点サイズ
		 * @param		numVertex		[in] 頂点数
		 * @param		vertexFormat	[in] 頂点フォーマット
		 * @param		flags			[in] フラグ
		 * @return						頂点バッファのポインタ
		 */
		virtual KsVertexBuffer*			createVertexBuffer( KsUInt32 vertexSize, KsUInt32 numVertex, KsUInt32 vertexFormat, KsUInt32 flags );

		/**
		 * 頂点バッファを生成する
		 * @param		vertexSize		[in] 頂点サイズ
		 * @param		numVertex		[in] 頂点数
		 * @param		vertexFormat	[in] 頂点フォーマット
		 * @param		flags			[in] フラグ
		 * @return						頂点バッファのポインタ
		 */
		virtual KsVertexBuffer*			createVertexBuffer( void* pData, KsUInt32 vertexSize, KsUInt32 numVertex, KsUInt32 vertexFormat, KsUInt32 flags );

		/**
		 * インデックスバッファを生成する
		 * @param	numIndex			[in] インデックスの数
		 * @param	indexFormat			[in] インデックスフォーマット
		 * @param	flags				[in] フラグ
		 * @return						インデックスバッファのポインタ
		 */
		virtual KsIndexBuffer*			createIndexBuffer( KsUInt32 numIndex, KsUInt32 indexFormat, KsUInt32 flags );

		/**
		 * インデックスバッファを生成する
		 * @param	pData				[in] データ読み込み用のポインタ
		 * @param	size				[in] データサイズ
		 * @param	numIndex			[in] インデックスの数
		 * @param	indexFormat			[in] インデックスフォーマット
		 * @param	flags				[in] フラグ
		 * @return						インデックスバッファのポインタ
		 */
		virtual KsIndexBuffer*			createIndexBuffer( void* pData, KsUInt32 size, KsUInt32 numIndex, KsUInt32 indexFormat, KsUInt32 flags );

		/**
		 * 定数バッファを生成する
		 * @param	pData				[in] データ読み込み用のポインタ
		 * @param	size				[in] データサイズ
		 * @param	flags				[in] フラグ
		 * @return						定数バッファのポインタ
		 */
		virtual KsConstantBuffer*		createConstantBuffer( KsUInt32 size, KsUInt32 flags );

		/**
		 * 定数バッファを生成する
		 * @param	size				[in] バッファサイズ
		 * @param	flags				[in] フラグ
		 * @return						定数バッファのポインタ
		 */
		virtual KsConstantBuffer*		createConstantBuffer( void* pData, KsUInt32 size, KsUInt32 flags );

	protected:
		KsRenderSystemGL*				m_RenderSystem;		/**< 描画システム	*/

};

ksNS_KS_END

#endif		/* __KSBUFFERMANAGERGL_H__ */



