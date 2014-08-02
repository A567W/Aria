/************************************************************************************************/
/** 
 * @file		KsDepthStencilStateGL.h
 * @brief		DirectX�p�[�x�X�e���V���X�e�[�g
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0
 */
/************************************************************************************************/
#ifndef __KSDEPTHSTENCILSTATEGL_H__
#define __KSDEPTHSTENCILSTATEGL_H__

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

/************************************************************************************************/
/**
 * @class		KsDepthStencilStateGL
 * @brief		�[�x�X�e���V���X�e�[�g
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @note		�Q�ƃJ�E���^��
 */
/************************************************************************************************/
class ksENGINE_API KsDepthStencilStateGL : public KsDepthStencilState
{
		friend class KsRenderSystemGL;
		friend class KsRenderContextGL;
	public:
		/**
		 * �R���X�g���N�^
		 */
											KsDepthStencilStateGL( KsRenderSystemGL* pRenderSystem, const KS_DEPTH_STENCIL_DESC* pDepthStencilDesc );

		/**
		 * �f�X�g���N�^
		 */
		virtual								~KsDepthStencilStateGL();

		/**
		 * �e�N�X�`���̔j��
		 */
		virtual void						destroy();

		/**
		 * ���\�[�X���擾����
		 * @return							���\�[�X
		 */
		virtual void*						getRenderResource();
};

ksNS_KS_END

#endif		/* __KSDEPTHSTENCILSTATEGL_H__ */

