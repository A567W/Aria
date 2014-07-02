/************************************************************************************************/
/** 
 * @file		KsBlendState.cpp
 * @brief		DirectX用深度ステンシルステート
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0
 */
/************************************************************************************************/

/*==============================================================================================*/
/*                                 << インクルード >>                                           */
/*==============================================================================================*/
#include "KsBlendState.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/*
 * デフォルトブレンドステート
 */
/************************************************************************************************/
const KS_BLEND_DESC KsBlendState::DEFAULT = 
{
	ksFALSE,
	ksFALSE,
	{
		{ ksFALSE, KS_BLEND_ONE, KS_BLEND_ZERO, KS_BLEND_OP_ADD, KS_BLEND_ONE, KS_BLEND_ZERO, KS_BLEND_OP_ADD, KS_COLOR_WRITE_ENABLE_ALL },
		{ ksFALSE, KS_BLEND_ONE, KS_BLEND_ZERO, KS_BLEND_OP_ADD, KS_BLEND_ONE, KS_BLEND_ZERO, KS_BLEND_OP_ADD, KS_COLOR_WRITE_ENABLE_ALL },
		{ ksFALSE, KS_BLEND_ONE, KS_BLEND_ZERO, KS_BLEND_OP_ADD, KS_BLEND_ONE, KS_BLEND_ZERO, KS_BLEND_OP_ADD, KS_COLOR_WRITE_ENABLE_ALL },
		{ ksFALSE, KS_BLEND_ONE, KS_BLEND_ZERO, KS_BLEND_OP_ADD, KS_BLEND_ONE, KS_BLEND_ZERO, KS_BLEND_OP_ADD, KS_COLOR_WRITE_ENABLE_ALL },
		{ ksFALSE, KS_BLEND_ONE, KS_BLEND_ZERO, KS_BLEND_OP_ADD, KS_BLEND_ONE, KS_BLEND_ZERO, KS_BLEND_OP_ADD, KS_COLOR_WRITE_ENABLE_ALL },
		{ ksFALSE, KS_BLEND_ONE, KS_BLEND_ZERO, KS_BLEND_OP_ADD, KS_BLEND_ONE, KS_BLEND_ZERO, KS_BLEND_OP_ADD, KS_COLOR_WRITE_ENABLE_ALL },
		{ ksFALSE, KS_BLEND_ONE, KS_BLEND_ZERO, KS_BLEND_OP_ADD, KS_BLEND_ONE, KS_BLEND_ZERO, KS_BLEND_OP_ADD, KS_COLOR_WRITE_ENABLE_ALL },
		{ ksFALSE, KS_BLEND_ONE, KS_BLEND_ZERO, KS_BLEND_OP_ADD, KS_BLEND_ONE, KS_BLEND_ZERO, KS_BLEND_OP_ADD, KS_COLOR_WRITE_ENABLE_ALL }
	}
};

/************************************************************************************************/
/*
 * デフォルトブレンドステート
 */
/************************************************************************************************/
const KS_BLEND_DESC KsBlendState::SPRITE = 
{
	ksTRUE,
	ksFALSE,
	{
		{ ksTRUE, KS_BLEND_SRC_ALPHA, KS_BLEND_INV_SRC_ALPHA, KS_BLEND_OP_ADD, KS_BLEND_SRC_ALPHA, KS_BLEND_INV_SRC_ALPHA, KS_BLEND_OP_ADD, KS_COLOR_WRITE_ENABLE_ALL },
		{ ksTRUE, KS_BLEND_SRC_ALPHA, KS_BLEND_INV_SRC_ALPHA, KS_BLEND_OP_ADD, KS_BLEND_SRC_ALPHA, KS_BLEND_INV_SRC_ALPHA, KS_BLEND_OP_ADD, KS_COLOR_WRITE_ENABLE_ALL },
		{ ksTRUE, KS_BLEND_SRC_ALPHA, KS_BLEND_INV_SRC_ALPHA, KS_BLEND_OP_ADD, KS_BLEND_SRC_ALPHA, KS_BLEND_INV_SRC_ALPHA, KS_BLEND_OP_ADD, KS_COLOR_WRITE_ENABLE_ALL },
		{ ksTRUE, KS_BLEND_SRC_ALPHA, KS_BLEND_INV_SRC_ALPHA, KS_BLEND_OP_ADD, KS_BLEND_SRC_ALPHA, KS_BLEND_INV_SRC_ALPHA, KS_BLEND_OP_ADD, KS_COLOR_WRITE_ENABLE_ALL },
		{ ksTRUE, KS_BLEND_SRC_ALPHA, KS_BLEND_INV_SRC_ALPHA, KS_BLEND_OP_ADD, KS_BLEND_SRC_ALPHA, KS_BLEND_INV_SRC_ALPHA, KS_BLEND_OP_ADD, KS_COLOR_WRITE_ENABLE_ALL },
		{ ksTRUE, KS_BLEND_SRC_ALPHA, KS_BLEND_INV_SRC_ALPHA, KS_BLEND_OP_ADD, KS_BLEND_SRC_ALPHA, KS_BLEND_INV_SRC_ALPHA, KS_BLEND_OP_ADD, KS_COLOR_WRITE_ENABLE_ALL },
		{ ksTRUE, KS_BLEND_SRC_ALPHA, KS_BLEND_INV_SRC_ALPHA, KS_BLEND_OP_ADD, KS_BLEND_SRC_ALPHA, KS_BLEND_INV_SRC_ALPHA, KS_BLEND_OP_ADD, KS_COLOR_WRITE_ENABLE_ALL },
		{ ksTRUE, KS_BLEND_SRC_ALPHA, KS_BLEND_INV_SRC_ALPHA, KS_BLEND_OP_ADD, KS_BLEND_SRC_ALPHA, KS_BLEND_INV_SRC_ALPHA, KS_BLEND_OP_ADD, KS_COLOR_WRITE_ENABLE_ALL }
	}
};

/************************************************************************************************/
/*
 * Accumブレンドステート
 */
/************************************************************************************************/
const KS_BLEND_DESC KsBlendState::ACCUMULATE = 
{
	ksFALSE,
	ksFALSE,
	{
		{ ksTRUE,  KS_BLEND_ONE, KS_BLEND_ONE,  KS_BLEND_OP_ADD, KS_BLEND_ONE, KS_BLEND_ONE,  KS_BLEND_OP_ADD, KS_COLOR_WRITE_ENABLE_ALL },
		{ ksFALSE, KS_BLEND_ONE, KS_BLEND_ZERO, KS_BLEND_OP_ADD, KS_BLEND_ONE, KS_BLEND_ZERO, KS_BLEND_OP_ADD, KS_COLOR_WRITE_ENABLE_ALL },
		{ ksFALSE, KS_BLEND_ONE, KS_BLEND_ZERO, KS_BLEND_OP_ADD, KS_BLEND_ONE, KS_BLEND_ZERO, KS_BLEND_OP_ADD, KS_COLOR_WRITE_ENABLE_ALL },
		{ ksFALSE, KS_BLEND_ONE, KS_BLEND_ZERO, KS_BLEND_OP_ADD, KS_BLEND_ONE, KS_BLEND_ZERO, KS_BLEND_OP_ADD, KS_COLOR_WRITE_ENABLE_ALL },
		{ ksFALSE, KS_BLEND_ONE, KS_BLEND_ZERO, KS_BLEND_OP_ADD, KS_BLEND_ONE, KS_BLEND_ZERO, KS_BLEND_OP_ADD, KS_COLOR_WRITE_ENABLE_ALL },
		{ ksFALSE, KS_BLEND_ONE, KS_BLEND_ZERO, KS_BLEND_OP_ADD, KS_BLEND_ONE, KS_BLEND_ZERO, KS_BLEND_OP_ADD, KS_COLOR_WRITE_ENABLE_ALL },
		{ ksFALSE, KS_BLEND_ONE, KS_BLEND_ZERO, KS_BLEND_OP_ADD, KS_BLEND_ONE, KS_BLEND_ZERO, KS_BLEND_OP_ADD, KS_COLOR_WRITE_ENABLE_ALL },
		{ ksFALSE, KS_BLEND_ONE, KS_BLEND_ZERO, KS_BLEND_OP_ADD, KS_BLEND_ONE, KS_BLEND_ZERO, KS_BLEND_OP_ADD, KS_COLOR_WRITE_ENABLE_ALL }
	}
};


/************************************************************************************************/
/*
 * コンストラクタ
 */
/************************************************************************************************/
KsBlendState::KsBlendState()
{
	KsZeroMemory( &m_blendStateDesc, sizeof(KS_BLEND_DESC) );
}

/************************************************************************************************/
/*
 * コンストラクタ
 */
/************************************************************************************************/
KsBlendState::KsBlendState( const KS_BLEND_DESC* pBlendStateDesc )
{
	KsMemCopy( &m_blendStateDesc, pBlendStateDesc, sizeof(KS_BLEND_DESC) );
}

/************************************************************************************************/
/*
 * コンストラクタ
 */
/************************************************************************************************/
KsBlendState::KsBlendState( const KS_BLEND_DESC& refBlendStateDesc )
	: m_blendStateDesc( refBlendStateDesc )
{
}


/************************************************************************************************/
/*
 * デストラクタ
 */
/************************************************************************************************/
KsBlendState::~KsBlendState()
{
}

ksNS_KS_END

