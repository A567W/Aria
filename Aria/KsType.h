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
 * @file	KsType.h
 * @brief	�^�C�v��`
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/
#ifndef __KSTYPE_H__
#define __KSTYPE_H__

/*===============================================================================================*/
/*                                 << �C���N���[�h >>                                             */
/*===============================================================================================*/

/*===============================================================================================*/
/*                                     << ��` >>                                                */
/*===============================================================================================*/

#define ksTRUE                  ( 1 )							/**< �^						*/
#define ksFALSE                 ( 0 )							/**< �U						*/

/* �����^ �ő�l/�ŏ��l */
#define KsInt8MAXVAL            ( 0x7F )						/**< max value  127			*/
#define KsInt8MINVAL            ( 0x80 )						/**< min value -128			*/
#define KsUInt8MAXVAL           ( 0xFF )						/**< max value  256			*/
#define KsUInt8MINVAL           ( 0x00 )						/**< min value    0			*/
#define KsInt16MAXVAL           ( 0x7FFF )						/**< */
#define KsInt16MINVAL           ( 0x8000 )						/**< */
#define KsUInt16MAXVAL          ( 0xFFFF )						/**< */
#define KsUInt16MINVAL          ( 0x0000 )						/**< */
#define KsInt32MAXVAL           ( 0x7FFFFFFF )					/**< */
#define KsInt32MINVAL           ( 0x80000000 )					/**< */
#define KsUInt32MAXVAL          ( 0xFFFFFFFF )					/**< */
#define KsUInt32MINVAL          ( 0x00000000 )					/**< */
/* ���������^ �ő�l/�ŏ��l */
#define KsRealMAXVAL            ( 0x7f7fc99e )					/**<  3.4 * 10^38					*/
#define KsRealMINVAL            ( 0xff7fc99e )					/**< -3.4 * 10^38					*/
#define ksFLOAT32_MAX           ( 3.402823466e+38f )
#define ksFLOAT32_MIN           (-3.402823466e+38f )

#define ksFLT_DIG               6								/* # of decimal digits of precision */
#define ksFLT_EPSILON           1.192092896e-07F				/* smallest such that 1.0+FLT_EPSILON != 1.0 */
#define ksFLT_GUARD             0
#define ksFLT_MANT_DIG          24								/* # of bits in mantissa */
#define ksFLT_MAX               3.402823466e+38F				/* max value */
#define ksFLT_MAX_10_EXP        38								/* max decimal exponent */
#define ksFLT_MAX_EXP           128								/* max binary exponent */
#define ksFLT_MIN               1.175494351e-38F				/* min positive value */
#define ksFLT_MIN_10_EXP        (-37)							/**< min decimal exponent */
#define ksFLT_MIN_EXP           (-125)							/**< min binary exponent */
#define ksFLT_NORMALIZE         0
#define ksFLT_RADIX             2								/**< exponent radix */
#define ksFLT_ROUNDS            1								/**< addition rounding: near */

#define ksALIGNED_CLASS16(a)    __declspec(align(16)) a
#define ksATTRIBUTE_ALIGN16     __declspec(align(16))

#define ksALIGN2(x)             (((x)+ 1) & ~1)					/**<  2 bytes alignment				*/
#define ksALIGN4(x)             (((x)+ 3) & ~3)					/**<  4 bytes alignment				*/
#define ksALIGN8(x)             (((x)+ 7) & ~7)					/**<  8 bytes alignment				*/
#define ksALIGN16(x)            (((x)+15) & ~15)				/**< 16 bytes alignment				*/

typedef         int				KsBool;							/**< �u�[���l							*/
typedef         float			KsReal;							/**< ���������_�^						*/
typedef         float			KsReal32;						/**< ���������_�^						*/
typedef         double			KsReal64;						/**< �{���x���������_�^				*/
typedef         long			KsLong;							/**< 32 �r�b�g�̕����t������			*/
typedef         int				KsInt32;						/**< 32 �r�b�g�̕����t������			*/
typedef         short			KsInt16;						/**< 16 �r�b�g�̕����t������			*/
typedef         char			KsInt8;							/**<  8 �r�b�g�̕����t������			*/
#ifdef UNICODE
typedef         wchar_t			KsChar;							/**<  8 �r�b�g�̕����t������			*/
#else
typedef         char			KsChar;							/**<  8 �r�b�g�̕����t������			*/
#endif // #ifdef UNICODE
typedef         char			KsSChar;						/**<  8 �r�b�g�̕����t������			*/
typedef         wchar_t			KsWChar;						/**< 16 �r�b�g�̕����t������			*/
typedef unsigned long			KsULong;						/**< 32 �r�b�g�̕����Ȃ�����			*/
typedef unsigned int			KsUInt32;						/**< 32 �r�b�g�̕����Ȃ�����			*/
typedef unsigned short			KsUInt16;						/**< 16 �r�b�g�̕����Ȃ�����			*/
typedef unsigned char			KsUInt8;						/**<  8 �r�b�g�̕����Ȃ�����			*/
typedef unsigned char			KsByte;							/**<  8 �r�b�g�̕����Ȃ�����			*/
typedef unsigned short			KsWord;							/**< 16 �r�b�g�̕����Ȃ�����			*/
typedef unsigned long			KsDWord;						/**< 32 �r�b�g�̕����Ȃ�����			*/
typedef size_t					KsSize;							/**< �T�C�Y�p							*/
typedef void*					KsHandle;						/**< �n���h��							*/

#ifdef _MSC_VER					// Visual Studio C
typedef __int64					KsInt64;						/**< 64 �r�b�g�̕����t������			*/
typedef unsigned __int64		KsUInt64;						/**< 64 �r�b�g�̕����Ȃ�����			*/
#else
typedef long long				KsInt64;						/**< 64 �r�b�g�̕����t������			*/
typedef unsigned long long		KsUInt64;						/**< 64 �r�b�g�̕����Ȃ�����			*/
#endif

//typedef intptr_t              KsIntPtr;						/**< �|�C���^�̕����t������				*/
//typedef uintptr_t             KsUIntPtr;						/**< �|�C���^�̕����Ȃ�����				*/

/* ���w�֐� */
#define KsSin(_x)               sinf(_x)						/**< sin							*/
#define KsSinh(_x)              sinhf(_x)						/**< �n�C�p�[�{���b�Nsin				*/
#define KsCos(_x)               cosf(_x)						/**< cos							*/
#define KsCosh(_x)              coshf(_x)						/**< �n�C�p�[�{���b�Ncos				*/
#define KsTan(_x)               tanf(_x)						/**< tan							*/
#define KsTanh(_x)              tanhf(_x)						/**< �n�C�p�[�{���b�Ntan				*/
#define KsASin(_x)              asinf(_x)						/**< asin							*/
#define KsASinh(_x)             asinhf(_x)						/**< �n�C�p�[�{���b�Nasin				*/
#define KsACos(_x)              acosf(_x)						/**< acos							*/
#define KsACosh(_x)             acoshf(_x)						/**< �n�C�p�[�{���b�Nacos				*/
#define KsATan(_x)              atanf(_x)						/**< atan							*/
#define KsATan2(_x,_y)          atan2f(_x,_y)					/**< atan2							*/
#define KsAbs(_x)               abs(_x)							/**< abs							*/
#define KsFabs(_x)              fabsf(_x)						/**< fabs							*/
#define KsExp(_x)               expf(_x)						/**< exp(�w�����v�Z)					*/
#define KsFmod(_x,_y)           fmodf(_x,_y)					/**< fmod(���������_���̏�]���v�Z)		*/
#define KsLogE(_x)              logf(_x)						/**< log							*/
#define KsLog10(_x)             log10f(_x)						/**< log10							*/
#define KsModf(_x,_y)           modf(_x,_y)						/**< modf							*/
#define KsPow(_x,_y)            pow(_x,_y)						/**< pow(x �� y ����v�Z����)			*/
#define KsSqrt(_x)              sqrtf(_x)						/**< ������							*/
#define KsRsqrt(_x)             rsqrtf(_x)						/**< �������̋t��						*/

#define KsFloor(_x)             s_cast<KsReal>(s_cast<KsInt32>(_x))

#define ksPI					(3.14159265358979323846264338f)	/**< �~����(��)						*/
#define ksHALF_PI				(1.57079632679489661923132169f)	/**< �~����(��/�Q)						*/
#define ksTWO_PI				(6.28318530717958647692528676f)	/**< �~����(�Q��)						*/
#define ksTOLERANCE				(0.0001f)						/**< �ł��؂�덷						*/
#define ksTOLERANCE2			(0.00000001f)					/**< �ł��؂�덷�Q					*/
#define ksPATH_MAX              ( 512 )							/**< �ő�p�X��						*/

#define ksNULLPTR				nullptr							/**< NULL�|�C���^						*/

#ifdef _MSC_VER					// Visual Studio C
#  define ksINLINE				inline
#  define ksFORCE_INLINE		__forceinline
#else 
#  ifdef __GNUC__				// GCC
#    define ksINLINE			inline
#    define ksFORCE_INLINE		inline __attribute__((always_inline))
#  else
#    define ksINLINE			inline
#    define ksFORCE_INLINE		inline
#  endif
#endif

#endif	/* __KSTYPE_H__ */

