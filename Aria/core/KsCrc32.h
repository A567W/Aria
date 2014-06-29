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
 * @file	KsCrc32.h
 * @brief	CRC�`�F�b�N
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
/************************************************************************************************/
#ifndef __KSCRC32_H__
#define __KSCRC32_H__

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                           */
/*==============================================================================================*/
#include "KsCoreCommon.h"

/*==============================================================================================*/
/*                                     << ��` >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << �錾 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN


/************************************************************************************************/
/**
 * �o�b�t�@����CRC�̒l�����߂�
 * @param		pBuf		�o�b�t�@
 * @return					CRC�̒l
 */
/************************************************************************************************/
ksENGINE_API KsUInt32 KsCrc32( const KsUInt8* pBuf );

/************************************************************************************************/
/*
 * �o�b�t�@����CRC�̒l�����߂�
 * @param		pBuf		�o�b�t�@
 * @param		size		�ǂ��܂ŕϊ����邩
 * @return					CRC�̒l
 */
/************************************************************************************************/
ksENGINE_API KsUInt32 KsCrc32( const KsUInt8* pBuf, KsUInt32 size );

ksNS_KS_END


#endif /* __KSCRC32_H__ */

