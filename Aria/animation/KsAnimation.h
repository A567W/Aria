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
 * @file	KsAnimation.h
 * @brief	�A�j���[�V�����N���X
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
/************************************************************************************************/
#ifndef __KSANIMATION_H__
#define __KSANIMATION_H__

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                            */
/*==============================================================================================*/
#include "KsAnimationCommon.h"
#include "KsAnimationChannel.h"

/*==============================================================================================*/
/*                                     << ��` >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << �錾 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class		KsAnimation
 * @brief		�A�j���[�V����
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 */
/************************************************************************************************/
class ksENGINE_API KsAnimation
{
	private:
		KsReal					m_duration;			/**< �A�j���[�V��������					*/
		KsString				m_animationName;	/**< �A�j���[�V������						*/
		KsAnimationChannel*		m_boneAnimations;	/**< �{�[���A�j���[�V�����`�����l��		*/

	public:
		/**
		 * �R���X�g���N�^
		 */
		KsAnimation();

		/**
		 * �R���X�g���N�^
		 * @param	animationName		�A�j���[�V�����̖��O
		 * @param	pAnimationChannel	�A�j���[�V�����`�����l��
		 */
		KsAnimation( const KsString& animationName, KsAnimationChannel* pAnimationChannel );

		/**
		 * �f�X�g���N�^
		 */
		virtual					~KsAnimation();

		/**
		 * �A�j���[�V�����̌o�ߎ��Ԃ��擾����
		 * @return				�A�j���[�V�����̌o�ߎ���
		 */
		KsReal					getDuration() const { return m_duration; }

		/**
		 * �A�j���[�V�������O���擾����
		 * @return				�A�j���[�V�����̖��O
		 */
		const KsString&			getName() { return m_animationName; }

		/**
		 * �A�j���[�V�����`�����l�����擾����
		 * @return				�A�j���[�V�����`�����l��
		 */
		KsAnimationChannel*		getAnimationChannels() { return m_boneAnimations; }

		/**
		 * �e���{�[���̖��O���擾����
		 * @param	index		�C���f�b�N�X
		 * @return				�e���{�[���̖��O
		 */
		const KsString&			getAffectedBone( KsUInt32 index ) { return m_boneAnimations->getAffectedBone( index );}

		/**
		 * �e���{�[�����邩�ǂ������`�F�b�N����
		 * @param	boneName	�{�[���̖��O
		 * @retval	ksTRUE		�e���{�[���������Ă���
		 * @retval	ksFALSE		�e���{�[���������ĂȂ�
		 */
		KsBool					hasAffectsBone( const KsString& boneName ) { return m_boneAnimations->hasAffectsBone( boneName ); }
};

ksNS_KS_END

#endif /* __KSANIMATION_H__ */

