/************************************************************************************************/
/** 
 * @file		KsShader.h
 * @brief		�V�F�[�_�[�f�[�^
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/
#ifndef __KSSHADER_H__
#define __KSSHADER_H__

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                           */
/*==============================================================================================*/
#include "KsGraphicsCommon.h"
#include "KsShaderType.h"

/*==============================================================================================*/
/*                                     << ��` >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << �錾 >>                                               */
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
 * @brief		�V�F�[�_�[�f�[�^
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
         * �R���X�g���N�^
         */
        KsShader();

        /**
         * �f�X�g���N�^
         */
        virtual                 ~KsShader();

        /**
         * �V�F�[�_�[���Z�b�g����B
         */
        virtual void            setShader() = 0;

        /**
         * �C���v�b�g���C�A�E�g���Z�b�g����B
         */
        virtual void            setInputLayout( ksINPUT_LAYOUT_TYPE type ) = 0;

        /**
         * �V�F�[�_�[���p�����[�^�Z�b�g����B
         */
        virtual void            setParameterVS( KsUInt32 type, const KsVector4d* pVector ) = 0;
        virtual void            setParameterVS( KsUInt32 type, const KsMatrix4x4* pMatrix ) = 0;

        /**
         * �V�F�[�_�[���p�����[�^�Z�b�g����B
         */
        virtual void            setParameterPS( KsUInt32 type, const KsVector4d* pVector ) = 0;
        virtual void            setParameterPS( KsUInt32 type, const KsMatrix4x4* pMatrix ) = 0;
};

ksNS_KS_END

#endif		/* __KSSHADER_H__ */

