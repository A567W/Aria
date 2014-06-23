/************************************************************************************************/
/** 
 * @file		KsQuaternion.h
 * @brief		�N�H�[�^�j�I������
 * @author		A567W
 * @version		1.0.0
 */
/************************************************************************************************/
#ifndef __KSQUATERNION_H__
#define __KSQUATERNION_H__

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                            */
/*==============================================================================================*/
#include "KsMathBase.h"
#include "KsVector.h"

/*==============================================================================================*/
/*                                     << ��` >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << �錾 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

class KsMatrix3x3;
class KsMatrix4x4;

/************************************************************************************************/
/**
 *	@class	KsQuaternion
 *	@brief	�N�H�[�^�j�I������N���X
 *	@autor	A567W
 */
/************************************************************************************************/
class ksENGINE_API KsQuaternion
{
	public:
		/**
		 * �}�g���b�N�X�̗v�f����
		 */
		KsReal							x, y, z, w;

		/**
		 * �R���X�g���N�^					 �P�ʍs��ŏ���������܂�
		 */
										KsQuaternion() : x( 0.0f ), y( 0.0f ), z( 0.0f ), w( 1.0f ) {}

		/**
		 * �R���X�g���N�^
		 * @param	farray				����������l, ���̔z��̏��� �v�f�����������܂�
		 */
										KsQuaternion( const KsReal* fArray ) : x( fArray[0] ), y( fArray[1] ), z( fArray[2] ), w( fArray[3] ) {}

		/**
		 * �R���X�g���N�^
		 * @param	farray				����������l, ���̔z��̏��� �v�f�����������܂�
		 */
										KsQuaternion( KsReal qx, KsReal qy, KsReal qz, KsReal qw ) : x( qx ), y( qy ), z( qz ), w( qw ) {}

										KsQuaternion( const KsMatrix3x3& refMatrix );

										//KsQuaternion( const KsMatrix4x4& refMatrix );
		/**
		 * KsReal�̃|�C���^�ɕϊ����ĂŎ擾�ł���悤�ɂ���
		 */
										operator KsReal* () { return &x; }

		/**
		 * KsReal�̃|�C���^�ɕϊ����ĂŎ擾�ł���悤�ɂ���
		 */
										operator const KsReal* () const { return &x; }

		/**
		 *
		 */
		KsQuaternion&					operator = ( const KsQuaternion& refQuat );
		//KsQuaternion&					operator = ( const KsMatrix4x4& refMatrix );

		KsQuaternion&					operator += ( const KsQuaternion& refQuat );
		KsQuaternion&					operator -= ( const KsQuaternion& refQuat );
		KsQuaternion&					operator *= ( const KsQuaternion& refQuat );
		KsQuaternion&					operator *= ( KsReal s );
		KsQuaternion&					operator /= ( KsReal s );
	
		KsQuaternion					operator ~ () const;
		KsQuaternion					operator + () const;
		KsQuaternion					operator - () const;
	
		KsQuaternion					operator + ( const KsQuaternion& refQuat ) const;
		KsQuaternion					operator - ( const KsQuaternion& refQuat ) const;
		KsQuaternion					operator * ( const KsQuaternion& refQuat ) const;
		KsQuaternion					operator * ( KsReal s ) const;
		KsQuaternion					operator / ( KsReal s ) const;

		KsBool							operator == ( const KsQuaternion& refQuat ) const;
		KsBool							operator != ( const KsQuaternion& refQuat ) const;


		friend KsQuaternion				operator * ( KsReal s, const KsQuaternion& v ) { return v * s; }

		//�t�s��
	

		KsReal							length() const;

		KsReal							length2() const;

		//Dot

		/**
		 * ���K������
		 */
		void							normalize();

		/**
		 * �t�N�H�[�^�j�I��
		 */
		void							inverse();

		void							fromAxisRotation( const KsVector3d& refAxis, KsReal angle );
		void							fromEulerAngles( KsReal angleX, KsReal angleY, KsReal angleZ );

		//void							convertToMatrix( KsMatrix4x4* pMatrix );
		void							convertToAxisRotation( KsVector3d* pAxis, KsReal* pAngle );
		//void							convertToEuler( KsVector3d* pOut );

		static const KsQuaternion		IDENTITY;

};


/*************************************************************************************************/
/*---------------------------<< �C�����C�������w�b�_�[�t�@�C�� >>------------------------------------*/
								#include "KsQuaternion.inl"
/*-----------------------------------------------------------------------------------------------*/
/*************************************************************************************************/

ksNS_KS_END

#endif /* __KSQUATERNION_H__ */

