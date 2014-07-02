/************************************************************************************************/
/** 
 * @file		KsModelParameter.h
 * @brief		���f���p�����[�^
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/
#ifndef __KSMODELPARAMETER_H__
#define __KSMODELPARAMETER_H__

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                            */
/*==============================================================================================*/
#include "KsBase.h"

/*==============================================================================================*/
/*                                     << ��` >>                                               */
/*==============================================================================================*/
#define MAX_BONES						256

/*==============================================================================================*/
/*                                     << �錾 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN


/************************************************************************************************/
/**
 * @class		KsGBufferParameter
 * @brief		���f��
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
 * @brief		���f��
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
 * @brief		���f��
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



