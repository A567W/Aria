/************************************************************************************************/
/** 
 * @file		KsInputLayoutManager.h
 * @brief		入力レイアウトマネージャ
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/
#ifndef __KSINPUTLAYOUTMANAGER_H__
#define __KSINPUTLAYOUTMANAGER_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsGraphicsCommon.h"
#include "KsGIFormat.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/
#define	KS_APPEND_ALIGNED_ELEMENT	( 0xffffffff )

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

class KsRenderContext;
class KsVertexShader;
class KsInputLayout;

/************************************************************************************************/
/**
 * @struct		KS_INPUT_CLASSIFICATION
 * @brief		入力要素DESC
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 */
/************************************************************************************************/
typedef enum KS_INPUT_CLASSIFICATION
{
    KS_INPUT_PER_VERTEX_DATA   = 0,		// 入力データは頂点単位のデータです。
    KS_INPUT_PER_INSTANCE_DATA = 1,		// 入力データはインスタンス単位のデータです。

} KS_INPUT_CLASSIFICATION;

/************************************************************************************************/
/**
 * @struct		KS_INPUT_ELEMENT_DESC
 * @brief		入力要素DESC
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 */
/************************************************************************************************/
typedef struct KS_INPUT_ELEMENT_DESC
{
    const KsChar*				SemanticName;
    KsUInt32					SemanticIndex;
    KS_GI_FORMAT				Format;
    KsUInt32					InputSlot;
    KsUInt32					AlignedByteOffset;
    KS_INPUT_CLASSIFICATION		InputSlotClass;
    KsUInt32					InstanceDataStepRate;

} KS_INPUT_ELEMENT_DESC;


/************************************************************************************************/
/**
 * @class		KsInputLayoutManager
 * @brief		入力レイアウトマネージャ
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 */
/************************************************************************************************/
class ksENGINE_API KsInputLayoutManager : public KsSingleton< KsInputLayoutManager >
{
	public:
		/**
		 * コンストラクタ
		 */
											KsInputLayoutManager();

		/**
		 * デストラクタ
		 */
		virtual								~KsInputLayoutManager();

		/**
		 * インプットレイアウトを生成する
		 * @param		numIndex			インデックス数
		 * @param		flags				フラグ
		 * @return							インプットレイアウトのポインタ
		 */
		virtual KsInputLayout*				createInputLayout( const KS_INPUT_ELEMENT_DESC* pInputElementDescs, KsUInt32 numElements, const KsVertexShader* pVertexShader ) = 0;

		/**
		 * シングルトンの参照を取得
		 * @return							シングルトンの参照
		 */
		static KsInputLayoutManager&		getInstance();
		
		/**
		 * シングルトンのポインタを取得
		 * @return							シングルトンのポインタ
		 */
		static KsInputLayoutManager*		getInstancePtr();

};

ksNS_KS_END

#endif		/* __KSINPUTLAYOUTMANAGER_H__ */



