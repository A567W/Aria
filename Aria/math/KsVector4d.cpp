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
 * @file	KsVector4d.cpp
 * @brief	4D�x�N�g������
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
/************************************************************************************************/

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                             */
/*==============================================================================================*/
#include "KsVector4d.h"

/*==============================================================================================*/
/*                                     << ��` >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << �錾 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

const KsVector4d KsVector4d::ZERO( 0.0f, 0.0f, 0.0f, 0.0f );
const KsVector4d KsVector4d::HALF( 0.5f, 0.5f, 0.5f, 0.5f );
const KsVector4d KsVector4d::ONE(  1.0f, 1.0f, 1.0f, 1.0f );
const KsVector4d KsVector4d::MAX(  ksREAL_MAX, ksREAL_MAX, ksREAL_MAX, ksREAL_MAX );
const KsVector4d KsVector4d::MIN(  ksREAL_MIN, ksREAL_MIN, ksREAL_MIN, ksREAL_MIN );


/************************************************************************************************/
/*
 * �ŏ���2�̃x�N�g���̐ς��A3 �Ԗڂ̃x�N�g���ɉ��Z���܂��B
 * @param   V1      �x�N�g��1
 * @param   V2      �x�N�g��2
 * @param   V3      �x�N�g��3
 * @return          �ŏ��� 2 �̃x�N�g���̐ς��A3 �Ԗڂ̃x�N�g���ɉ��Z�����x�N�g��
 */
/************************************************************************************************/
KsVector4d KsVector4d::MultiplyAdd( const KsVector4d& V1, const KsVector4d& V2, const KsVector4d& V3 )
{
	KsVector4d	ret;

	ret.x = V1.x * V2.x + V3.x;
	ret.y = V1.y * V2.y + V3.y;
	ret.z = V1.z * V2.z + V3.z;
	ret.w = V1.w * V2.w + V3.w;
	
	return ret;
}


ksNS_KS_END
