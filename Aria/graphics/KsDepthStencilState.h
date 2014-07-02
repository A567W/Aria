/************************************************************************************************/
/** 
 * @file		KsDepthStencilState.h
 * @brief		�[�x�X�e���V���X�e�[�g
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0
 */
/************************************************************************************************/
#ifndef __KSDEPTHSTENCILSTATE_H__
#define __KSDEPTHSTENCILSTATE_H__

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                           */
/*==============================================================================================*/
#include "KsRenderType.h"

/*==============================================================================================*/
/*                                     << ��` >>                                               */
/*==============================================================================================*/
#define	KS_DEFAULT_STENCIL_READ_MASK	( 0xff )
#define	KS_DEFAULT_STENCIL_WRITE_MASK	( 0xff )

/*==============================================================================================*/
/*                                     << �錾 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class		KsDepthStencilState
 * @brief		�[�x�X�e���V���X�e�[�g
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @note		�Q�ƃJ�E���^��
 */
/************************************************************************************************/
class ksENGINE_API KsDepthStencilState
{
	public:
		/**
		 * �R���X�g���N�^
		 */
											KsDepthStencilState();

		/**
		 * �R���X�g���N�^
		 */
											KsDepthStencilState( const KS_DEPTH_STENCIL_DESC* pDepthStencilDesc );

		/**
		 * �R���X�g���N�^
		 */
											KsDepthStencilState( const KS_DEPTH_STENCIL_DESC& refDepthStencilDesc );

		/**
		 * �f�X�g���N�^
		 */
		virtual								~KsDepthStencilState();

		/**
		 * �e�N�X�`���̔j��
		 */
		virtual void						destroy() = 0;

		/**
		 * ���\�[�X���擾����
		 * @return							���\�[�X
		 */
		virtual void*						getRenderResource() = 0;

	protected:
		KS_DEPTH_STENCIL_DESC				m_depthStencilDesc;

	public:
		static const KS_DEPTH_STENCIL_DESC	DEFAULT;
		//static KS_BLEND_DESC				ACCUMULATE;
		
};

ksNS_KS_END

#endif		/* __KSDEPTHSTENCILSTATE_H__ */



