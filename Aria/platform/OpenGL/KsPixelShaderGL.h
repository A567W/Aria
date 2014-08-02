/************************************************************************************************/
/** 
 * @file		KsPixelShaderGL.h
 * @brief		�s�N�Z���V�F�[�_�[
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0
 */
/************************************************************************************************/
#ifndef __KSPIXELSHADERGL_H__
#define __KSPIXELSHADERGL_H__

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                           */
/*==============================================================================================*/
#include "KsCommonGL.h"

/*==============================================================================================*/
/*                                     << ��` >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << �錾 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN


class KsRenderSystemGL;

/************************************************************************************************/
/**
 * @class		KsPixelShaderGL
 * @brief		���_�V�F�[�_�[
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @note		
 */
/************************************************************************************************/
class ksENGINE_API KsPixelShaderGL : public KsVertexShader
{
		friend class KsRenderContextGL;
	public:
		/**
		 * �R���X�g���N�^
		 */
									KsPixelShaderGL( KsRenderSystemGL* pRenderSystem );

		/**
		 * �f�X�g���N�^
		 */
		virtual						~KsPixelShaderGL();

		/**
		 * �t�@�C�����璸�_�V�F�[�_�[�𐶐�����
		 * @param	pFileName		�t�@�C����
		 * @param	shaderModel		�V�F�[�_�[���f��
		 * @retval	ksTRUE			��������
		 * @retval	ksFALSE			�������s
		 */
		virtual KsBool				createFromFile( const KsChar* pFileName, const KsChar* pEntryPoint, ksSHADER_MODEL_TYPE shaderModel );

		/**
		 * �j������
		 */
		virtual void				destroy();
	
		/**
		 * �o�b�t�@�̃|�C���^���擾����
		 * @return					�o�b�t�@�̃|�C���^
		 */
		virtual const void*			getBufferPointer();

		/**
		 * �o�b�t�@�̃T�C�Y���擾����
		 * @return					�o�b�t�@�̃T�C�Y
		 */
		virtual KsUInt32			getBufferSize();

	private:
        KsRenderSystemGL*           m_pRenderSystem;
        GLuint                      m_shaderID;
};

ksNS_KS_END

#endif		/* __KSPIXELSHADERGL_H__ */

