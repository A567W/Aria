/*************************************************************************************************/
/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2014 A567W
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 * 
 * @file	KsBone.h
 * @brief	�{�[���֌W
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
/************************************************************************************************/
#ifndef __KSBONE_H__
#define __KSBONE_H__

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                            */
/*==============================================================================================*/
#include "KsModelCommon.h"

/*==============================================================================================*/
/*                                     << ��` >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << �錾 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class		KsBone
 * @brief		���f���{�[���N���X
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 */
/************************************************************************************************/
class ksENGINE_API KsBone
{
		friend class KsModel;
	public:
		/**
		 * �R���X�g���N�^
		 */
									KsBone();

		/**
		 * �f�X�g���N�^
		 */
		virtual						~KsBone();

		/**
		 * �{�[�������擾����
		 * @return					�{�[����
		 */
		const KsString&				getName() const { return m_name; }


		/**
		 * �{�[���C���f�b�N�X���擾����
		 * @return					�{�[���C���f�b�N�X
		 */
		KsInt32						getIndex() const { return m_index; }

		/**
		 * �e�{�[���C���f�b�N�X���擾����
		 * @return					�e�{�[���C���f�b�N�X
		 */
		KsInt32						getParentIndex() const { return m_parent; }

		/**
		 * �e�{�[�����擾����
		 * @return					�e�{�[��
		 */
		KsBone*						getParent() { return m_pParent; }


		/**
		 * �q���̃{�[���̐����擾����
		 * @return					�q���̐�
		 */
		KsUInt32					getNumChild() const { return m_vpChildren.size(); }

		/**
		 * �q���̃{�[�����擾����
		 * @return					�q���̃{�[��
		 */
		KsBone*						getChild( KsInt32 index ) { return m_vpChildren[ index ]; }

		/**
		 *
		 */
		KsMatrix4x4&				getDefaultTransform() { return m_defaultTransform; }

		/**
		 *
		 */
		KsMatrix4x4&				getBoneTransform() { return m_boneTransform; }

		/**
		 *
		 */
		KsMatrix4x4&				getAnimationTransform() { return m_animationTransform; }

		/**
		 *
		 */
		KsMatrix4x4&				getInverseTransform() { return m_inverseTransform; }

		/**
		 *
		 */
		KsMatrix4x4&				getWorldTransform() { return m_worldTransform; }

		/**
		 *
		 */
		KsMatrix4x4&				getSkinTransform() { return m_skinTransform; }

		/**
		 * �{�[����`�悷��
		 */
		void						draw();

	public:
		KsInt32						m_index;				/// Bones �R���N�V�������́A���̃{�[���̃C���f�b�N�X���擾���܂��B
		KsString					m_name;					/// ���̃{�[���̖��O���擾���܂��B
		KsInt32						m_parent;				/// �e�{�[���̃C���f�b�N�X
		KsBone*						m_pParent;				/// ���̃{�[���̐e���擾���܂��B
		KsArray<KsBone*>			m_vpChildren;			/// ���̃{�[���̎q�ł���{�[���̃R���N�V�������擾���܂��B
		KsMatrix4x4					m_defaultTransform;		/// �e�{�[������Ƃ��Ă��̃{�[�����g�����X�t�H�[�����邽�߂Ɏg�p�����s����擾�܂��͐ݒ肵�܂��B
		KsMatrix4x4					m_animationTransform;	/// �e�{�[������Ƃ��Ă��̃{�[�����g�����X�t�H�[�����邽�߂Ɏg�p�����s����擾�܂��͐ݒ肵�܂��B
		KsMatrix4x4					m_inverseTransform;
		KsMatrix4x4					m_boneTransform;
		KsMatrix4x4					m_worldTransform;
		KsMatrix4x4					m_skinTransform;
};

ksNS_KS_END

#endif		/* __KSBONE_H__ */



