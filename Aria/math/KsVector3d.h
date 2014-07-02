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
 * @file	KsVector3d.h
 * @brief	3D�x�N�g������
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
/************************************************************************************************/
#ifndef __KSVECTOR3D_H__
#define __KSVECTOR3D_H__

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                            */
/*==============================================================================================*/
#include "KsMathCommon.h"

/*==============================================================================================*/
/*                                     << ��` >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << �錾 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/*************************************************************************************************/
/**
 * @class	KsVector3d
 * @brief	3D�x�N�g������N���X
 * @author	A567W
 */
/*************************************************************************************************/
class ksENGINE_API KsVector3d
{
	public:
		/**
		 * �x�N�g���� x, y, z ����
		 */
		KsReal							x, y, z;

		/**
		 * �R���X�g���N�^					�[���ŏ���������܂�
		 */
										KsVector3d() : x( 0.0f ), y( 0.0f ), z( 0.0f ) {}

		/**
		 * �R���X�g���N�^
		 * @param	val					����������l, ���̒l��x, y, z �����������܂�
		 */
										KsVector3d( KsReal val ) : x( val ), y( val ), z( val ) {}

		/**
		 * �R���X�g���N�^
		 * @param	farray				����������l, ���̔z��̏��� x, y, z �����������܂�
		 */
										KsVector3d( const KsReal* fArray ) : x( fArray[ 0 ] ), y( fArray[ 1 ] ), z( fArray[ 2 ] ) {}
	
		/**
		 * �R���X�g���N�^(copy)
		 * @param	refVector			�����̒l���R�s�[���ď��������܂�
		 */
										KsVector3d( const KsVector3d& refVector ) : x( refVector.x ), y( refVector.y ), z( refVector.z ) {}
		/**
		 * �R���X�g���N�^
		 * @param	xf					����������x�̒l
		 * @param	yf					����������y�̒l
		 * @param	zf					����������z�̒l
		 */
										KsVector3d( KsReal xf, KsReal yf, KsReal zf ) : x( xf ), y( yf ), z( zf ) {}

		/**
		 * KsReal�̃|�C���^�ɕϊ����ĂŎ擾�ł���悤�ɂ���
		 */
										operator KsReal* () { return &x; }

		/**
		 * KsReal�̃|�C���^�ɕϊ����ĂŎ擾�ł���悤�ɂ���
		 */
										operator const KsReal* () const { return &x; }

		/**
		 * �z����̒l��Ԃ�
		 * @param	num					�Ԃ��z��̃i���o�[
		 * @return						�z����̐擪�̎Q��
		 */
		KsReal&							operator[]( KsInt32 index );

		/**
		 * �z����̒l��Ԃ�
		 * @param	num					�Ԃ��z��̃i���o�[
		 * @return						�z����̐擪�̎Q��
		 */
		const KsReal&					operator[]( KsInt32 index ) const;

		/**
		 * �x�N�g����( = )���Z�q
		 * @param	rkVector			�l���R�s�[����x�N�g��
		 * @return						�������g�̃x�N�g���Q��( *this )
		 */
		const KsVector3d&				operator = ( const KsVector3d& rkVector );
							
		/**
		 * �x�N�g����( += )���Z�q
		 * @param	rkVector			�l�𑫂��x�N�g��
		 * @return						�������g�̃x�N�g���Q��( *this )
		 */
		KsVector3d&						operator += ( const KsVector3d& refVector );

		/**
		 * �x�N�g����( += )���Z�q
		 * @param	rkVector			�l�𑫂��x�N�g��
		 * @return						�������g�̃x�N�g���Q��( *this )
		 */
		KsVector3d&						operator -= ( const KsVector3d& refVector );

		/**
		 * �x�N�g����( *= )���Z�q
		 * @param	s					�x�N�g���Ɋ|����l
		 * @return						�������g�̃x�N�g���Q��( *this )
		 */
		KsVector3d&						operator *= ( KsReal s );

		/**
		 * �x�N�g����( /= )���Z�q
		 * @param	s					�x�N�g��������l
		 * @return						�������g�̃x�N�g���Q��( *this )
		 */
		KsVector3d&						operator /= ( KsReal s );

		/**
		 * �x�N�g����( + )���Z�q
		 * @return						+ ���Z�q�̃x�N�g��
		 */
		KsVector3d						operator + () const;

		/**
		 * �x�N�g����( - )���Z�q
		 * @return						- ���Z�q�̃x�N�g��
		 */
		KsVector3d						operator - () const;

		/**
		 * �x�N�g����( + )���Z�q
		 * @param	refVector			�v�Z����x�N�g��
		 * @return						���ʂ̃x�N�g��
		 */
		KsVector3d						operator + ( const KsVector3d& refVector ) const;

		/**
		 * �x�N�g����( - )���Z�q
		 * @param	refVector			�v�Z����x�N�g��
		 */
		KsVector3d						operator - ( const KsVector3d& refVector ) const;
	
		/**
		 * �x�N�g����( * )���Z�q
		 * @param						�|����l
		 * @return						���ʂ̃x�N�g��
		 */
		KsVector3d						operator * ( KsReal s ) const;
	
		/**
		 * �x�N�g����( / )���Z�q
		 * @param	s					����l
		 * @return						���ʂ̃x�N�g��
		 */
		KsVector3d						operator / ( KsReal s ) const;

		/**
		 * �x�N�g�������������𔻒肷��
		 * @param	refVector			���肷��x�N�g��
		 * @retval	ksTRUE				������
		 * @retval	ksFALSE				�������Ȃ�
		 */
		KsBool							operator == ( const KsVector3d& refVector ) const;
	
		/**
		 * �x�N�g�����������Ȃ����𔻒肷��
		 * @param	refVector			���肷��x�N�g��
		 * @retval	ksTRUE				�������Ȃ�
		 * @retval	ksFALSE				������
		 */
		KsBool							operator != ( const KsVector3d& refVector ) const;

		/**
		 * �e�������Z�b�g����
		 * @param	xf					x����
		 * @param	yf					y����
		 * @param	zf					z����
		 */
		void							set( KsReal xf, KsReal yf, KsReal zf );
	
		/**
		 * �e�������Z�b�g����
		 * @param	fArray				�����̐擪�̃|�C���^
		 */
		void							set( const KsReal* fArray );
	
		/**
		 * �w�肵�������̃x�N�g���ɕύX����
		 * @param	len					�ύX���钷��
		 */
		void							scaleTo( KsReal len );
	
		/**
		 * �O�Ń��Z�b�g����
		 */
		void							reset();
	
		/**
		 * �x�N�g���̒������擾����
		 */
		KsReal							length();
	
		/**
		 * �x�N�g���̒����̂Q����擾����
		 */
		KsReal							length2();
	
		/**
		 * ���K������
		 */
		void							normalize();
	
		/**
		 * ����
		 * @param	refVector			���ς���x�N�g��
		 * @return						���ό��ʂ̃X�J���[�l
		 */
		KsReal							dotProduct( const KsVector3d& refVector ) const;

		/**
		 * �O��
		 * @param	refVector			�O�ς���x�N�g��
		 * @return						�O�ό��ʂ̃x�N�g��
		 */
		KsVector3d						crossProduct( const KsVector3d& refVector );

		/**
		 * �[���x�N�g��
		 */
		static const KsVector3d			ZERO;

		/**
		 * 0.5f�ŏ��������ꂽ�x�N�g��
		 */
		static const KsVector3d			HALF;

		/**
		 * 1.0f�ŏ��������ꂽ�x�N�g��
		 */
		static const KsVector3d			ONE;

		/**
		 * �ő�l
		 */
		static const KsVector3d			MAX;

		/**
		 * �ŏ��l
		 */
		static const KsVector3d			MIN;

    public:
        /**
         * �ŏ���2�̃x�N�g���̐ς��A3 �Ԗڂ̃x�N�g���ɉ��Z���܂��B
         * @param   V1      �x�N�g��1
         * @param   V2      �x�N�g��2
         * @param   V3      �x�N�g��3
         * @return          �ŏ��� 2 �̃x�N�g���̐ς��A3 �Ԗڂ̃x�N�g���ɉ��Z�����x�N�g��
         */
        static KsVector3d MultiplyAdd( const KsVector3d& V1, const KsVector3d& V2, const KsVector3d& V3 );

        /**
         * ���`��Ԃ��s���܂��B
         * @param   V1      �x�N�g��1
         * @param   V2      �x�N�g��2
         * @param   amount  V2 �̏d�݂����� 0.0f �` 1.0f �͈̔͂̒l�B
         * @return          2 �̃x�N�g������`��Ԃ����x�N�g��
         */
        static KsVector3d Lerp( const KsVector3d& V1, const KsVector3d& V2, KsReal amount );
};

/************************************************************************************************/
/*---------------------------<< �C�����C�������w�b�_�[�t�@�C�� >>-----------------------------------*/
								#include "KsVector3d.inl"
/*----------------------------------------------------------------------------------------------*/
/************************************************************************************************/

ksNS_KS_END

#endif /* __KSVECTOR3D_H__ */

