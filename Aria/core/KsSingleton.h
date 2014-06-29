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
 * @file	KsSingleton.h
 * @brief	�V���O���g��
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/
#ifndef __KSSINGLETON_H__
#define __KSSINGLETON_H__

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                            */
/*==============================================================================================*/
#include "KsCoreCommon.h"

/*==============================================================================================*/
/*                                     << ��` >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << �錾 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/*************************************************************************************************/
/**
 * @class	KsSingleton
 * @brief	�V���O���g���N���X
 * @author	A567W
 */
/*************************************************************************************************/
template< typename T > class KsSingleton
{
	protected:
		static	T*					m_pInstance;		/**< �C���X�^���X	*/
	
	public:
    	/**
			* �R���X�g���N�^
			*/
									KsSingleton() { m_pInstance = static_cast< T* >( this ); }

    	/**
    		* �f�X�g���N�^
    		*/
		virtual						~KsSingleton() { m_pInstance = 0; }
		
		/**
			* �V���O���g���̎Q�Ƃ��擾
			* @return					�V���O���g���̎Q��
			*/
		static T&					getInstance() { return ( *m_pInstance );  }
		
		/**
			* �V���O���g���̃|�C���^���擾
			* @return					�V���O���g���̃|�C���^
			*/
		static T*					getInstancePtr() {  return ( m_pInstance );  }
};

/*************************************************************************************************/
/**
 * @class	KsSingletonDeclare
 * @brief	�V���O���g���N���X
 * @author	A567W
 */
/*************************************************************************************************/
template< typename T > class KsSingletonDeclare
{
	protected:
		static	T*					m_pInstance;		/**< �C���X�^���X	*/
	
	protected:
    	/**
			* �R���X�g���N�^
			*/
									KsSingletonDeclare(){}

    	/**
    		* �f�X�g���N�^
    		*/
		virtual						~KsSingletonDeclare(){}
		
	public:

		/**
			* �C���X�^���X�̐���
			* @return					�������ꂽ�C���X�^���X
			*/
		static T*					createInstance() { if( !m_pInstance ) m_pInstance = new T; return m_pInstance; }


		/**
			* �C���X�^���X�̔j��
			*/
		static void					destoryInstance() { ksDELETE( m_pInstance ); }

		/**
			* �V���O���g���̎Q�Ƃ��擾
			* @return					�V���O���g���̎Q��
			*/
		static T&					getInstance() { return ( *m_pInstance );  }
		
		/**
			* �V���O���g���̃|�C���^���擾
			* @return					�V���O���g���̃|�C���^
			*/
		static T*					getInstancePtr() {  return ( m_pInstance );  }
};

ksNS_KS_END

#endif		/* __KSSINGLETON_H__ */


