/************************************************************************************************/
/** 
 * @file		KsModelParameter.h
 * @brief		モデルパラメータ
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/
#ifndef __KSMODELPARAMETER_H__
#define __KSMODELPARAMETER_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsBase.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/
#define MAX_BONES						256

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN


/************************************************************************************************/
/**
 * @class		KsGBufferParameter
 * @brief		モデル
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 */
/************************************************************************************************/
class KsGBufferParameter
{
	public:
		static const KsUInt32	Size = sizeof(KsMatrix4x4)*(18);

	public:
		KsMatrix4x4				WorldViewProj;
		KsMatrix4x4				WorldView;
		KsMatrix4x4				ViewProj;
		KsMatrix4x4				Proj;
		KsMatrix4x4				World;
		KsVector4d				CameraNearFar;
		KsUInt32				FramebufferDimensionsX;
		KsUInt32				FramebufferDimensionsY;
		KsUInt32				FramebufferDimensionsZ;
		KsUInt32				FramebufferDimensionsW;
};

/************************************************************************************************/
/**
 * @class		KsMatrixPalletParameter
 * @brief		モデル
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 */
/************************************************************************************************/
class KsMatrixPalletParameter
{
	public:
		static const KsUInt32	Size = sizeof(KsMatrix4x4)*(MAX_BONES+10);
	
	public:
		KsMatrix4x4				MatrixPalette[ MAX_BONES ];
};

/************************************************************************************************/
/**
 * @class		KsModelParameter
 * @brief		モデル
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 */
/************************************************************************************************/
class KsModelParameter
{
	public:
		KsGBufferParameter				GBuffer;
		KsMatrixPalletParameter			Model;
};

ksNS_KS_END

#endif		/* __KSMODELPARAMETER_H__ */



