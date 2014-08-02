/************************************************************************************************/
/** 
 * @file		KsInputLayoutManagerGL.h
 * @brief		���̓��C�A�E�g�}�l�[�W��(DirectX11)
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/
#ifndef __KSINPUTLAYOUTMANAGERGL_H__
#define __KSINPUTLAYOUTMANAGERGL_H__

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                            */
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
 * @class		KsInputLayoutManagerGL
 * @brief		���̓��C�A�E�g�}�l�[�W��(DirectX11)
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 */
/************************************************************************************************/
class ksENGINE_API KsInputLayoutManagerGL : public KsInputLayoutManager
{
	public:
		/**
		 * �R���X�g���N�^
		 */
											KsInputLayoutManagerGL( KsRenderSystemGL* pRenderSystem );

		/**
		 * �f�X�g���N�^
		 */
		virtual								~KsInputLayoutManagerGL();

		/**
		 * �C���v�b�g���C�A�E�g�𐶐�����
		 * @param		numIndex			�C���f�b�N�X��
		 * @param		flags				�t���O
		 * @return							�C���v�b�g���C�A�E�g�̃|�C���^
		 */
		virtual KsInputLayout*				createInputLayout( const KS_INPUT_ELEMENT_DESC* pInputElementDescs, KsUInt32 numElements, const KsVertexShader* pVertexShader );

	protected:
		 KsRenderSystemGL*				m_pRenderSystem;
};

ksNS_KS_END

#endif		/* __KSINPUTLAYOUTMANAGERGL_H__ */



