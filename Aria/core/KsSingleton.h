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
 * @brief	シングルトン
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/
#ifndef __KSSINGLETON_H__
#define __KSSINGLETON_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsCoreCommon.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/*************************************************************************************************/
/**
 * @class	KsSingleton
 * @brief	シングルトンクラス
 * @author	A567W
 */
/*************************************************************************************************/
template< typename T > class KsSingleton
{
	protected:
		static	T*					m_pInstance;		/**< インスタンス	*/
	
	public:
    	/**
			* コンストラクタ
			*/
									KsSingleton() { m_pInstance = static_cast< T* >( this ); }

    	/**
    		* デストラクタ
    		*/
		virtual						~KsSingleton() { m_pInstance = 0; }
		
		/**
			* シングルトンの参照を取得
			* @return					シングルトンの参照
			*/
		static T&					getInstance() { return ( *m_pInstance );  }
		
		/**
			* シングルトンのポインタを取得
			* @return					シングルトンのポインタ
			*/
		static T*					getInstancePtr() {  return ( m_pInstance );  }
};

/*************************************************************************************************/
/**
 * @class	KsSingletonDeclare
 * @brief	シングルトンクラス
 * @author	A567W
 */
/*************************************************************************************************/
template< typename T > class KsSingletonDeclare
{
	protected:
		static	T*					m_pInstance;		/**< インスタンス	*/
	
	protected:
    	/**
			* コンストラクタ
			*/
									KsSingletonDeclare(){}

    	/**
    		* デストラクタ
    		*/
		virtual						~KsSingletonDeclare(){}
		
	public:

		/**
			* インスタンスの生成
			* @return					生成されたインスタンス
			*/
		static T*					createInstance() { if( !m_pInstance ) m_pInstance = new T; return m_pInstance; }


		/**
			* インスタンスの破棄
			*/
		static void					destoryInstance() { ksDELETE( m_pInstance ); }

		/**
			* シングルトンの参照を取得
			* @return					シングルトンの参照
			*/
		static T&					getInstance() { return ( *m_pInstance );  }
		
		/**
			* シングルトンのポインタを取得
			* @return					シングルトンのポインタ
			*/
		static T*					getInstancePtr() {  return ( m_pInstance );  }
};

ksNS_KS_END

#endif		/* __KSSINGLETON_H__ */


