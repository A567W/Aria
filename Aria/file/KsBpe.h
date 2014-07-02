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
 * @file	KsBpe.h
 * @brief	BPE(Byte Pair Encoding:�o�C�g�Ε�����)���k
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
/************************************************************************************************/
#ifndef __KSBPE_H__
#define __KSBPE_H__

#include "KsCoreCommon.h"


ksNS_KS_BEGIN

/**
@class  CBPE
@brief  BPE���k�N���X
@author IZAYA
*/
class CBPE
{
    private:
        //  member variable definitions
        enum
        {
            BPE_WORKBUFFERSIZE = 2048,
            BPE_PAIRBUFFERSIZE = 768,
        };

        KsInt32     m_BufSize;
        KsInt32     m_PairCnt;
        KsByte*     m_WorkBuf;
        KsByte*     m_PairBuf;

    public:
        //  prototype definitions(public member functions)
        /**
        @brief  �R���X�g���N�^
        @author IZAYA
        */
        CBPE();

        /**
        @brief  �f�X�g���N�^
        @author IZAYA
        */
        ~CBPE();

        /**
        @brief  ���k�֐�
        @author IZAYA
        @param  [out] pDest ���Z���ʂ��i�[����z��A�h���X
        @param  [in] pSrc ������ƂȂ�z��A�h���X
        @param  [in] SrcSize ������ƂȂ�z��A�h���X�̃T�C�Y
        @retval ���� ���k��̃t�@�C���T�C�Y  ���s�@0

        @note   pDest��NULL(0)�ɂ���ƁA���k��̃t�@�C���T�C�Y���擾�\�ł�
        */
        KsULong Encode( void *pDest, void *pSrc, KsULong SrcSize );

        /**
        @brief  �L���֐�
        @author IZAYA
        @param  [out] pDest ���Z���ʂ��i�[����z��A�h���X
        @param  [in] pSrc ������ƂȂ�z��A�h���X
        @param  [in] SrcSize ������ƂȂ�z��A�h���X�̃T�C�Y
        @retval ���� ���k�O�̃t�@�C���T�C�Y  ���s�@0

        @note   pDest��NULL(0)�ɂ���ƁA���k�O�̃t�@�C���T�C�Y���擾�\�ł�
        */
        KsULong Decode( void *pDest, void *pSrc, KsULong SrcSize );

    private:
        //  prototype definitions(private member functions)
        /**
        @brief  BPE���k���C�����[�`��
        @author IZAYA
        @param  [in] BufSize �o�b�t�@�T�C�Y
        @retval ���k��̃o�b�t�@�T�C�Y
        */
        KsULong EncodeSub( int BufSize );
};

ksNS_KS_END

#endif	/* __KSBPE_H__ */


