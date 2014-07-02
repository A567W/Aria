/************************************************************************************************/
/** 
 * @file		KsGIFormat.h
 * @brief		入力レイアウト
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/
#ifndef __KSGIFORMAT_H__
#define __KSGIFORMAT_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsBase.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @enum		KS_GI_FORMAT
 * @brief		GI フォーマット
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 */
/************************************************************************************************/
typedef enum KS_GI_FORMAT
{
    KS_GI_FORMAT_UNKNOWN = 0,
    KS_GI_FORMAT_R32G32B32A32_TYPELESS = 1,
    KS_GI_FORMAT_R32G32B32A32_FLOAT = 2,
    KS_GI_FORMAT_R32G32B32A32_UINT = 3,
    KS_GI_FORMAT_R32G32B32A32_SINT = 4,
    KS_GI_FORMAT_R32G32B32_TYPELESS = 5,
    KS_GI_FORMAT_R32G32B32_FLOAT = 6,
    KS_GI_FORMAT_R32G32B32_UINT = 7,
    KS_GI_FORMAT_R32G32B32_SINT = 8,
    KS_GI_FORMAT_R16G16B16A16_TYPELESS = 9,
    KS_GI_FORMAT_R16G16B16A16_FLOAT = 10,
    KS_GI_FORMAT_R16G16B16A16_UNORM = 11,
    KS_GI_FORMAT_R16G16B16A16_UINT = 12,
    KS_GI_FORMAT_R16G16B16A16_SNORM = 13,
    KS_GI_FORMAT_R16G16B16A16_SINT = 14,
    KS_GI_FORMAT_R32G32_TYPELESS = 15,
    KS_GI_FORMAT_R32G32_FLOAT = 16,
    KS_GI_FORMAT_R32G32_UINT = 17,
    KS_GI_FORMAT_R32G32_SINT = 18,
    KS_GI_FORMAT_R32G8X24_TYPELESS = 19,
    KS_GI_FORMAT_D32_FLOAT_S8X24_UINT = 20,
    KS_GI_FORMAT_R32_FLOAT_X8X24_TYPELESS = 21,
    KS_GI_FORMAT_X32_TYPELESS_G8X24_UINT = 22,
    KS_GI_FORMAT_R10G10B10A2_TYPELESS = 23,
    KS_GI_FORMAT_R10G10B10A2_UNORM = 24,
    KS_GI_FORMAT_R10G10B10A2_UINT = 25,
    KS_GI_FORMAT_R11G11B10_FLOAT = 26,
    KS_GI_FORMAT_R8G8B8A8_TYPELESS = 27,
    KS_GI_FORMAT_R8G8B8A8_UNORM = 28,
    KS_GI_FORMAT_R8G8B8A8_UNORM_SRGB = 29,
    KS_GI_FORMAT_R8G8B8A8_UINT = 30,
    KS_GI_FORMAT_R8G8B8A8_SNORM = 31,
    KS_GI_FORMAT_R8G8B8A8_SINT = 32,
    KS_GI_FORMAT_R16G16_TYPELESS = 33,
    KS_GI_FORMAT_R16G16_FLOAT = 34,
    KS_GI_FORMAT_R16G16_UNORM = 35,
    KS_GI_FORMAT_R16G16_UINT = 36,
    KS_GI_FORMAT_R16G16_SNORM = 37,
    KS_GI_FORMAT_R16G16_SINT = 38,
    KS_GI_FORMAT_R32_TYPELESS = 39,
    KS_GI_FORMAT_D32_FLOAT = 40,
    KS_GI_FORMAT_R32_FLOAT = 41,
    KS_GI_FORMAT_R32_UINT = 42,
    KS_GI_FORMAT_R32_SINT = 43,
    KS_GI_FORMAT_R24G8_TYPELESS = 44,
    KS_GI_FORMAT_D24_UNORM_S8_UINT = 45,
    KS_GI_FORMAT_R24_UNORM_X8_TYPELESS = 46,
    KS_GI_FORMAT_X24_TYPELESS_G8_UINT = 47,
    KS_GI_FORMAT_R8G8_TYPELESS = 48,
    KS_GI_FORMAT_R8G8_UNORM = 49,
    KS_GI_FORMAT_R8G8_UINT = 50,
    KS_GI_FORMAT_R8G8_SNORM = 51,
    KS_GI_FORMAT_R8G8_SINT = 52,
    KS_GI_FORMAT_R16_TYPELESS = 53,
    KS_GI_FORMAT_R16_FLOAT = 54,
    KS_GI_FORMAT_D16_UNORM = 55,
    KS_GI_FORMAT_R16_UNORM = 56,
    KS_GI_FORMAT_R16_UINT = 57,
    KS_GI_FORMAT_R16_SNORM = 58,
    KS_GI_FORMAT_R16_SINT = 59,
    KS_GI_FORMAT_R8_TYPELESS = 60,
    KS_GI_FORMAT_R8_UNORM = 61,
    KS_GI_FORMAT_R8_UINT = 62,
    KS_GI_FORMAT_R8_SNORM = 63,
    KS_GI_FORMAT_R8_SINT = 64,
    KS_GI_FORMAT_A8_UNORM = 65,
    KS_GI_FORMAT_R1_UNORM = 66,
    KS_GI_FORMAT_R9G9B9E5_SHAREDEXP = 67,
    KS_GI_FORMAT_R8G8_B8G8_UNORM = 68,
    KS_GI_FORMAT_G8R8_G8B8_UNORM = 69,
    KS_GI_FORMAT_BC1_TYPELESS = 70,
    KS_GI_FORMAT_BC1_UNORM = 71,
    KS_GI_FORMAT_BC1_UNORM_SRGB = 72,
    KS_GI_FORMAT_BC2_TYPELESS = 73,
    KS_GI_FORMAT_BC2_UNORM = 74,
    KS_GI_FORMAT_BC2_UNORM_SRGB = 75,
    KS_GI_FORMAT_BC3_TYPELESS = 76,
    KS_GI_FORMAT_BC3_UNORM = 77,
    KS_GI_FORMAT_BC3_UNORM_SRGB = 78,
    KS_GI_FORMAT_BC4_TYPELESS = 79,
    KS_GI_FORMAT_BC4_UNORM = 80,
    KS_GI_FORMAT_BC4_SNORM = 81,
    KS_GI_FORMAT_BC5_TYPELESS = 82,
    KS_GI_FORMAT_BC5_UNORM = 83,
    KS_GI_FORMAT_BC5_SNORM = 84,
    KS_GI_FORMAT_B5G6R5_UNORM = 85,
    KS_GI_FORMAT_B5G5R5A1_UNORM = 86,
    KS_GI_FORMAT_B8G8R8A8_UNORM = 87,
    KS_GI_FORMAT_B8G8R8X8_UNORM = 88,
    KS_GI_FORMAT_FORCE_UINT = 0xffffffffUL,

} KS_GI_FORMAT;

ksNS_KS_END

#endif		/* __KSGIFORMAT_H__ */



