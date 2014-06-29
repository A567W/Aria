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
 * @file	KsTransform.cpp
 * @brief	座標変換の操作
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
/************************************************************************************************/

/*==============================================================================================*/
/*                                 << インクルード >>                                           */
/*==============================================================================================*/
#include "KsTransform.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

const KsTransform KsTransform::IDENTITY( KsMatrix3x3::IDENTITY, KsVector3d::ZERO );

/************************************************************************************************/
/*
 * コンストラクタ
 */
/************************************************************************************************/
KsTransform::KsTransform()
{
}

KsTransform::KsTransform( const KsQuaternion& q, const KsVector3d& c ) 
 : m_basis(q)
 , m_origin(c)
{}

KsTransform::KsTransform( const KsMatrix3x3& b, const KsVector3d& c )
 : m_basis(b)
 , m_origin(c)
{}
	  

KsTransform::KsTransform( const KsTransform& other )
 : m_basis(other.m_basis)
 , m_origin(other.m_origin)
{
}

KsTransform KsTransform::operator*(const KsTransform& t) const
{
	return KsTransform(m_basis * t.m_basis, (*this)(t.m_origin));
}

ksNS_KS_END

