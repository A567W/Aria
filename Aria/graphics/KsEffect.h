/************************************************************************************************/
/** 
 * @file		KsEffect.h
 * @brief		エフェクトファイル
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0
 */
/************************************************************************************************/
#ifndef __KSEFFECT_H__
#define __KSEFFECT_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                           */
/*==============================================================================================*/
#include "KsGraphicsCommon.h"
#include "KsVertexShader.h"
#include "KsPixelShader.h"
#include "KsGeometryShader.h"
#include "KsComputeShader.h"
#include "KsInputLayout.h"
#include "KsVertexBuffer.h"
#include "KsVertexBuffer.h"
#include "KsIndexBuffer.h"
#include "KsRenderContext.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class		KsEffect
 * @brief		エフェクトファイル
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @note		
 */
/************************************************************************************************/
class ksENGINE_API KsEffect
{
		friend class KsShaderManager;
	public:
		/**
		 * コンストラクタ
		 */
										KsEffect();

		/**
		 * デストラクタ
		 */
		virtual							~KsEffect();

		virtual	void					setShader( KsRenderContext* pRenderContext, void* pParameter );

		KsVertexShader*					getVertexShader( KsUInt32 index=0 );
		KsPixelShader*					getPixelShader( KsUInt32 index=0 );
		KsGeometryShader*				getGeometryShader( KsUInt32 index=0 );
		KsComputeShader*				getComputeShader( KsUInt32 index=0 );
		KsInputLayout*					getInputLayout( KsUInt32 index=0 );
		KsVertexBuffer*					getVertexBuffer( KsUInt32 index=0 );
		KsIndexBuffer*					getIndexBuffer( KsUInt32 index=0 );

		void							addVertexShader( KsVertexShader* pShader );
		void							addPixelShader( KsPixelShader* pShader );
		void							addGeometryShader( KsGeometryShader* pShader );
		void							addComputeShader( KsComputeShader* pShader );

		void							addInputLayout( KsInputLayout* pLayout );
		void							addVertexBuffer( KsVertexBuffer* pVertexBuffer );
		void							addIndexBuffer( KsIndexBuffer* pIndexBuffer );

		KsUInt32						getVertexShaderCount() const;
		KsUInt32						getPixelShaderCount() const;
		KsUInt32						getGeometryShaderCount() const;
		KsUInt32						getComputeShaderCount() const;
		KsUInt32						getInputLayoutCount() const;
		KsUInt32						getVertexBufferCount() const;
		KsUInt32						getIndexBufferCount() const;

	protected:
		KsArray<KsVertexShader*>		m_pVertexShaders;
		KsArray<KsPixelShader*>			m_pPixelShaders;
		KsArray<KsGeometryShader*>		m_pGeometryShaders;
		KsArray<KsComputeShader*>		m_pComputeShaders;

		KsArray<KsInputLayout*>			m_pInputLayouts;		/**< 頂点バッファ			*/
		KsArray<KsVertexBuffer*>		m_pVertexBuffers;		/**< インデックスバッファ		*/
		KsArray<KsIndexBuffer*>			m_pIndexBuffers;		/**< インプットレイアウト		*/
};

ksNS_KS_END


#endif		/* __KSEFFECT_H__ */

