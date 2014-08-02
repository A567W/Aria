/************************************************************************************************/
/** 
 * @file		KsInputLayoutManagerGL.h
 * @brief		入力レイアウトマネージャ(DirectX11)
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/
#ifndef __KSINPUTLAYOUTMANAGERGL_H__
#define __KSINPUTLAYOUTMANAGERGL_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
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
 * @class		KsInputLayoutManagerGL
 * @brief		入力レイアウトマネージャ(DirectX11)
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 */
/************************************************************************************************/
class ksENGINE_API KsInputLayoutManagerGL : public KsInputLayoutManager
{
	public:
		/**
		 * コンストラクタ
		 */
											KsInputLayoutManagerGL( KsRenderSystemGL* pRenderSystem );

		/**
		 * デストラクタ
		 */
		virtual								~KsInputLayoutManagerGL();

		/**
		 * インプットレイアウトを生成する
		 * @param		numIndex			インデックス数
		 * @param		flags				フラグ
		 * @return							インプットレイアウトのポインタ
		 */
		virtual KsInputLayout*				createInputLayout( const KS_INPUT_ELEMENT_DESC* pInputElementDescs, KsUInt32 numElements, const KsVertexShader* pVertexShader );

	protected:
		 KsRenderSystemGL*				m_pRenderSystem;
};

ksNS_KS_END

#endif		/* __KSINPUTLAYOUTMANAGERGL_H__ */



