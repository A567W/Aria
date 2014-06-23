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
 * @file	KsMacro.h
 * @brief	�}�N����`
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
/************************************************************************************************/
#ifndef __KSMACRO_H__
#define __KSMACRO_H__

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                           */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << ��` >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << �錾 >>                                               */
/*==============================================================================================*/

#define ksNew new

#ifdef __cplusplus
	#define ksNS_KS_BEGIN			namespace ks {
	#define ksNS_KS_END				}
	#define ksUSING_NS_KS			using namespace ks
#else
	#define ksNS_KS_BEGIN 
	#define ksNS_KS_END 
	#define ksUSING_NS_KS 
#endif 


#define ksBIT( X )	( 1 << (X) )

/* �L���X�g */
#define s_cast	static_cast			/**< */
#define c_cast	const_cast			/**< */
#define r_cast	reinterpret_cast	/**< */
#define d_cast	dynamic_cast		/**< */

/*************************************************************************************************/
/**
 * �������[�̃[���N���A
 * @param[in]	p		�N���A���郁�����[�̐擪�A�h���X
 * @param[in]	size	�N���A����T�C�Y
 */
/*************************************************************************************************/
ksINLINE void KsZeroMemory( void* p, KsSize size )
{
	memset( p, 0, size );
}

/*************************************************************************************************/
/**
 * �������[�̃[���N���A
 * @param	p		�N���A���郁�����[�̐擪�A�h���X
 * @param	size	�N���A����T�C�Y
 */
/*************************************************************************************************/
ksINLINE void KsMemset( void* p, KsInt32 val, KsSize size )
{
	memset( p, val, size );
}

/*************************************************************************************************/
/**
 * �������[�̃[���N���A
 * @param	p		�N���A���郁�����[�̐擪�A�h���X
 * @param	size	�N���A����T�C�Y
 */
/*************************************************************************************************/
ksINLINE void KsMemCopy( void* dst, const void* src, KsSize size )
{
	memcpy( dst, src, size );
}

/*************************************************************************************************/
/**
 * �z��̃T�C�Y���擾����
 * @param	dataArray		�z��
 */
/*************************************************************************************************/
#define ksARRAYSIZE( dataArray )	( sizeof(dataArray)/sizeof(dataArray[ 0 ]) )

/*************************************************************************************************/
/**
 * �p�x�ϊ��i�x���烉�W�A���ɕϊ��j
 * @param	degree		�p�x
 */
/*************************************************************************************************/
#define ksDEG( degree )				( (degree) * ( ksPI / 180.0f) )

/*************************************************************************************************/
/**
 * �p�x�ϊ��i���W�A������x�ɕϊ��j
 * @param	radian		���W�A��
 */
/*************************************************************************************************/
#define ksRAD( radian )				( (radian) * ( 180.0f / ksPI) )

/*************************************************************************************************/
/**
 * 32bit�J���[�l
 * @param	r		���b�h
 * @param	g		�O���[��
 * @param	b		�u���[
 * @param	a		�A���t�@
 */
/*************************************************************************************************/
#define ksRGBA32( r, g, b, a )		( (KsUInt32)(a<<24) | (KsUInt32)(b<<16) | (KsUInt32)(g<<8) | (KsUInt32)r )

/*************************************************************************************************/
/**
 * 32bit�J���[�l
 */
/*************************************************************************************************/
#define ksRGB32( r, g, b )			( (KsUInt32)(b<<16) | (KsUInt32)(g<<8) | (KsUInt32)r )

/*************************************************************************************************/
/**
 * ���[�h�l�ɂ���
 */
/*************************************************************************************************/
#define ksMAKE_WORD( a, b )		( (KsWord)(b<<8) | (KsWord)a )

/*************************************************************************************************/
/**
 * �_�u�����[�h�l�ɂ���
 */
/*************************************************************************************************/
#define ksMAKE_DWORD( a, b, c, d ) ( (KsDWord)(d<<24) | (KsDWord)(c<<16) | (KsDWord)(b<<8) | (KsDWord)a )

/* delete �}�N�� */
/*************************************************************************************************/
/**
 * new �Ŋm�ۂ����������[�̉��������
 * @param		p					�J�����郁�����[�̃|�C���^
 */
/*************************************************************************************************/
#define ksDELETE( p )				if( p ){ delete p; p = NULL; }

/*************************************************************************************************/
/**
 * new [] �Ŋm�ۂ����������[�̉��������
 * @param		p					�J�����郁�����[�̃|�C���^
 */
/*************************************************************************************************/
#define ksDELETEARRAY( p )		if( p ){ delete [] p; p = NULL; }

/*************************************************************************************************/
/**
 * �J���}�N��
 */
/*************************************************************************************************/
#define ksRELEASE( p )			if( p ){ (p)->Release(); p = NULL; }

/*************************************************************************************************/
/**
 * �J���}�N��
 */
/*************************************************************************************************/
#define ksFREE( p )				if( p ){ free( p ); p = NULL; }

/*************************************************************************************************/
/**
 * DirectX�p,�J���}�N��
 */
/*************************************************************************************************/
#define ksDESTROY( p )			if( p ){ (p)->destroy(); p = NULL; }

#define ksDELETEOBJECT( p )		if( p ){ ::DeleteObject(p); p = NULL; }

#define ksSUCCEEDED( x )			( (HRESULT)(x) >= 0 )
#define ksFAILED( x )				( (HRESULT)(x)  < 0 )

#define ksDELETEARRAYTEMPLATE( _arrayData )			\
{													\
	for( KsUInt32 i=0; i<_arrayData.size(); i++ )	\
	{												\
		ksDELETE( _arrayData[ i ] );				\
	}												\
	_arrayData.clear();								\
}


/*************************************************************************************************/
/**
 * 
 */
/*************************************************************************************************/
ksINLINE KsChar* ks_strcpy( KsChar* _Str1, const KsChar* _Str2 )
{
#ifdef  UNICODE
	return wcscpy( _Str1, _Str2 );
#else
	return strcpy( _Str1, _Str2 );
#endif // #ifdef  UNICODE
}

/*************************************************************************************************/
/**
 * 
 */
/*************************************************************************************************/
ksINLINE KsChar* ks_strncpy( KsChar* _Str1, const KsChar* _Str2, KsInt32 _Count )
{
#ifdef  UNICODE
	return wcsncpy( _Str1, _Str2, _Count );
#else
	return strncpy( _Str1, _Str2, _Count );
#endif // #ifdef  UNICODE
}

/*************************************************************************************************/
/**
 * 
 */
/*************************************************************************************************/
ksINLINE KsInt32 ks_strcmp( const KsChar* _Str1, const KsChar* _Str2 )
{
#ifdef  UNICODE
	return wcscmp( _Str1, _Str2 );
#else
	return strcmp( _Str1, _Str2 );
#endif // #ifdef  UNICODE
}

/*************************************************************************************************/
/**
 * 
 */
/*************************************************************************************************/
ksINLINE KsInt32 ks_strncmp( const KsChar* _Str1, const KsChar* _Str2, KsInt32 _Count )
{
#ifdef  UNICODE
	return wcsncmp( _Str1, _Str2, _Count );
#else
	return strncmp( _Str1, _Str2, _Count );
#endif // #ifdef  UNICODE
}

/*************************************************************************************************/
/**
 * 
 */
/*************************************************************************************************/
ksINLINE KsInt32 ks_strlen( const KsChar* _Str )
{
#ifdef  UNICODE
	return s_cast<KsInt32>(wcslen( _Str ));
#else
	return strlen( _Str );
#endif // #ifdef  UNICODE
}

/*************************************************************************************************/
/**
 * 
 */
/*************************************************************************************************/
ksINLINE KsChar* ks_strcat( KsChar* _Dest, const KsChar* _Source )
{
#ifdef  UNICODE
	return wcscat( _Dest, _Source );
#else
	return strcat( _Dest, _Source );
#endif // #ifdef  UNICODE
}

/*************************************************************************************************/
/**
 * 
 */
/*************************************************************************************************/
ksINLINE FILE* ks_fopen( const KsChar* filename, const KsChar* mode )
{
#ifdef  UNICODE
	return _wfopen( filename, mode );
#else
	return fopen( filename, mode );
#endif // #ifdef  UNICODE
}

/*************************************************************************************************/
/**
 * 
 */
/*************************************************************************************************/
ksINLINE KsChar* ks_fgets( KsChar* str, KsInt32 n, FILE* stream )
{
#ifdef  UNICODE
	return fgetws( str, n, stream );
#else
	return fgets( str, n, stream );
#endif // #ifdef  UNICODE
}

/*************************************************************************************************/
/**
 * 
 */
/*************************************************************************************************/
ksINLINE void ks_vsprintf( KsChar* buffer, KsInt32 count, const KsChar* format, va_list argptr )
{
#ifdef  UNICODE
	vswprintf( buffer, count, format, argptr );
#else
	vsprintf( buffer, format, argptr );
#endif // #ifdef  UNICODE
}

/*************************************************************************************************/
/**
 * 
 */
/*************************************************************************************************/
ksINLINE void ks_splitpath( const KsChar* path, KsChar* drive, KsChar* dir, KsChar* fname, KsChar* ext )
{
#ifdef  UNICODE
	_wsplitpath( path, drive, dir, fname, ext );
#else
	_splitpath( path, drive, dir, fname, ext );
#endif // #ifdef  UNICODE
}

#endif /* __KSMACRO_H__ */


