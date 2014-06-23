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
 * @file	KsPlane.h
 * @brief	���ʂ̑���
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
/************************************************************************************************/
#ifndef __KSPLANE_H__
#define __KSPLANE_H__

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                             */
/*==============================================================================================*/
#include "KsMath.h"

/*==============================================================================================*/
/*                                     << ��` >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << �錾 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class	KsPlane
 * @brief	���ʂ̃N���X
 * @author	A567W
 */
/*************************************************************************************************/
class ksENGINE_API KsPlane
{
	public:
		KsVector3d					m_normal;		/**< �ʂ̖@���x�N�g��		*/
		KsReal						m_distance;		/**< �ʂ̍���				*/
	
		/**
		 * �R���X�g���N�^				0�ŏ���������܂�
		 */
									KsPlane() : m_normal( 0.0f, 0.0f, 0.0f ), m_distance( 0.0f ){};

		/**
		 * �R���X�g���N�^(copy)
		 * @param	refPlane		�R�s�[���̕���	
		 */											
									KsPlane( const KsPlane& refPlane ) : m_normal( refPlane.m_normal ), m_distance( refPlane.m_distance ){};
	
		/**
		 * �R���X�g���N�^				�@���ƍ������畽�ʂ𐶐�
		 * @param	refNormal		���ʂ̖@���x�N�g��
		 * @param	distance		���ʂ̍���
		 */
									KsPlane( const KsVector3d& refNormal, KsReal distance ) : m_normal( refNormal ), m_distance( distance ){};
	
		/**
		 * �R���X�g���N�^				3�_��ʂ镽�ʃZ�b�g���Đ������܂�
		 * @param	refPointA		��1���_
		 * @param	refPointB		��2���_
		 * @param	refPointC		��3���_
		 */
									KsPlane( const KsVector3d& refPointA, const KsVector3d& refPointB, const KsVector3d& refPointC ){ set( refPointA, refPointB, refPointC ); };
	
		/**
		 * �R���X�g���N�^				�ʂ̖@���x�N�g���Ɩʏ�̓_���獂�������߂Đ������܂�
		 * @param	refNormal		���ʂ̖@���x�N�g��
		 * @param	refPoint		�ʏ�̒��_
		 */
									KsPlane( const KsVector3d& refNormal, const KsVector3d& refPoint ){ set( refNormal, refPoint ); };
	
		/**
		 * ���ʂ̃Z�b�g				�@���ƍ������畽�ʂ𐶐�
		 * @param	refNormal		���ʂ̖@���x�N�g��
		 * @param	distance		���ʂ̍���
		 */
		void						set( const KsVector3d& refNormal, KsReal distance );
	
		/**
		 * ���ʂ̃Z�b�g				3�_��ʂ镽�ʃZ�b�g���Đ������܂�
		 * @param	refPointA		��1���_
		 * @param	refPointB		��2���_
		 * @param	refPointC		��3���_
		 */
		void						set( const KsVector3d& refPointA, const KsVector3d& refPointB, const KsVector3d& refPointC );
	
		/**
		 * ���ʂ̃Z�b�g				�ʂ̖@���x�N�g���Ɩʏ�̓_���獂�������߂Đ������܂�
		 * @param	refNormal		���ʂ̖@���x�N�g��
		 * @param	refPoint		�ʏ�̒��_
		 */
		void						set( const KsVector3d& refNormal, const KsVector3d& refPoint );

		/**
		 * YZ���ʂ��琂����L�΂��Č��������ꏊ��X���W���擾����
		 * @param	y				y���W
		 * @param	z				z���W
		 * @return					x���W
		 */
		KsReal						getX( KsReal y, KsReal z );
	
		/**
		 * XZ���ʂ��琂����L�΂��Č��������ꏊ��Y���W���擾����
		 * @param	x				x���W
		 * @param	z				z���W
		 * @return					y���W
		 */
		KsReal						getY( KsReal x, KsReal z );
	
		/**
		 * XY���ʂ��琂����L�΂��Č��������ꏊ��Z���W���擾����
		 * @param	x				x���W
		 * @param	y				y���W
		 * @return					z���W
		 */
		KsReal						getZ( KsReal x, KsReal y );
	 
		/**
		 * YZ���ʂ��琂����L�΂��Č����������W���擾����
		 * @param	y				y���W
		 * @param	z				z���W
		 * @return					���ʏ�̓_
		 */
		KsVector3d					getPointX( KsReal y, KsReal z );
	
		/**
		 * XZ���ʂ��琂����L�΂��Č����������W���擾����
		 * @param	x				x���W
		 * @param	z				z���W
		 * @return					���ʏ�̓_
		 */
		KsVector3d					getPointY( KsReal x, KsReal z );
	
		/**
		 * XY���ʂ��琂����L�΂��Č����������W���擾����
		 * @param	x				x���W
		 * @param	y				y���W
		 * @return					���ʏ�̓_
		 */
		KsVector3d					getPointZ( KsReal x, KsReal y );
	
		/**
		 * ���ʏ��1�_���擾����
		 * @return					���ʏ�̃|�C���g
		 */
		KsVector3d					getOnPoint() const;
	
		/**
		 * �_�ƕ��ʂ̋��������߂�
		 * @param	refPoint		�|�C���g
		 */
		KsReal						distance( const KsVector3d& refPoint ) const;
	
		/**
		 * ���ʂ������܂�
		 * @param	refPlane		���ʂ̃R�s�[��
		 */
		KsPlane&					operator = ( const KsPlane& refPlane );
	
		/**
		 * ���ʂ����������ǂ����𔻒肷��
		 * @param	refPlane		���肷�镽��
		 * @retval	ksTRUE			������
		 * @retval	ksFALSE			�������Ȃ�
		 */
		KsBool						operator == ( const KsPlane& refPlane ) const;
	
		/**
		 * ���ʂ��������Ȃ����ǂ����𔻒肷��
		 * @param	refPlane		���肷�镽��
		 * @retval	ksTRUE			�������Ȃ�
		 * @retval	ksFALSE			������
		 */
		KsBool						operator != ( const KsPlane& refPlane ) const;
};

/*************************************************************************************************/
/*---------------------------<< �C�����C�������w�b�_�[�t�@�C�� >>------------------------------------*/
								#include "KsPlane.inl"
/*-----------------------------------------------------------------------------------------------*/
/*************************************************************************************************/

ksNS_KS_END

#endif /* __KSPLANE_H__ */

