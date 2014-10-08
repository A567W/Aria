/************************************************************************************************/
/** 
 * @file		KsShader.h
 * @brief		シェーダーデータ
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/
#ifndef __KSSHADER_H__
#define __KSSHADER_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                           */
/*==============================================================================================*/
#include "KsGraphicsCommon.h"
#include "KsShaderType.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

enum ksVERTEX_SHADER_UNIFORM_TYPE
{
    ksVERTEX_SHADER_UNIFORM_MVP,
    ksVERTEX_SHADER_UNIFORM_TIME,
    ksVERTEX_SHADER_UNIFORM_MAX,
};


enum ksPIXEL_SHADER_UNIFORM_TYPE
{
    ksPIXEL_SHADER_UNIFORM_COLOR,
    ksPIXEL_SHADER_UNIFORM_TIME,
    ksPIXEL_SHADER_UNIFORM_MAX,
};

enum ksINPUT_LAYOUT_TYPE
{
    ksINPUT_LAYOUT_P4F32,
    ksINPUT_LAYOUT_MAX
};

/************************************************************************************************/
/**
 * @class		KsShader
 * @brief		シェーダーデータ
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @note		
 */
/************************************************************************************************/
class ksENGINE_API KsShader
{
        friend class KsShaderManager;
    public:
        /**
         * コンストラクタ
         */
        KsShader();

        /**
         * デストラクタ
         */
        virtual                 ~KsShader();

        /**
         * シェーダーをセットする。
         */
        virtual void            setShader() = 0;

        /**
         * インプットレイアウトをセットする。
         */
        virtual void            setInputLayout( ksINPUT_LAYOUT_TYPE type ) = 0;

        /**
         * シェーダーをパラメータセットする。
         */
        virtual void            setParameterVS( KsUInt32 type, const KsVector4d* pVector ) = 0;
        virtual void            setParameterVS( KsUInt32 type, const KsMatrix4x4* pMatrix ) = 0;

        /**
         * シェーダーをパラメータセットする。
         */
        virtual void            setParameterPS( KsUInt32 type, const KsVector4d* pVector ) = 0;
        virtual void            setParameterPS( KsUInt32 type, const KsMatrix4x4* pMatrix ) = 0;
};

ksNS_KS_END

#endif		/* __KSSHADER_H__ */

