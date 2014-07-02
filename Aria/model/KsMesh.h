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
 * @file	KsMesh.h
 * @brief	���b�V���N���X
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
/************************************************************************************************/
#ifndef __KSMESH_H__
#define __KSMESH_H__

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                            */
/*==============================================================================================*/
#include "KsModelCommon.h"
#include "KsMeshPartCollection.h"
#include "KsModelParameter.h"


/*==============================================================================================*/
/*                                     << ��` >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << �錾 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class		KsMeshPart
 * @brief		���b�V���p�[�c
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 */
/************************************************************************************************/
class ksENGINE_API KsMesh
{
	private:
		KsString					m_name;				/// ���̃��b�V���̖��O���擾���܂��B
		//KsBoundingSphere			m_boundingSphere;	/// ���̃��b�V�����܂܂�Ă��� BoundingSphere ���擾���܂��B
		KsMeshPartCollection		m_vpMeshParts;		/// ���̃��b�V�����\������ ModelMeshPart �I�u�W�F�N�g���擾���܂��B���b�V���̊e�p�[�c�́A�����}�e���A�������L����v���~�e�B�u�̏W���ō\������Ă��܂��B
		//KsEffectCollection			m_vpEffects;		/// ���̃��b�V���Ɋ֘A�t�����Ă���G�t�F�N�g�̃R���N�V�������擾���܂��B
		//KsUserData*				m_pUserData;		/// ���[�U�[�f�[�^

		//     ���̃��b�V���Ɋ֘A�t�����Ă���G�t�F�N�g�̃R���N�V�������擾���܂��B
		//ModelEffectCollection		Effects

		//     ���̃��b�V���̐e�{�[�����擾���܂��B���b�V���̐e�{�[���ɂ̓��f���Őe���b�V���Ɋ֘A�������b�V����z�u������@���L�q����ϊ��s�񂪊܂܂�܂��B
		//ModelBone					ParentBone

	public:
		/**
		 * �R���X�g���N�^
		 */
									KsMesh();

		/**
		 * �f�X�g���N�^
		 */
		virtual						~KsMesh();

		/** 
		 * �`�揈��
		 * @param	pRenderContext	�`��R���e�L�X�g
		 */
		virtual void				draw( KsRenderContext* pRenderContext, KsModelParameter* pParameter=NULL );

		//     ���݂� Effect �ݒ���g�p���āA���̃��b�V�����̂��ׂĂ� ModelMeshPart �I�u�W�F�N�g��`�悵�܂��B
		KsMeshPart*					getMeshPart( KsUInt32 index ) { return m_vpMeshParts[ index ]; }
		KsUInt32					getMeshPartCount() const { return m_vpMeshParts.size(); }

	public:
		void						addMeshParts( KsMeshPart* pMeshPart ) { m_vpMeshParts.push_back( pMeshPart ); }
};

ksNS_KS_END

#endif		/* __KSMESH_H__ */



