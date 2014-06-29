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
 * @file	KsMD5.cpp
 * @brief	MD5
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
/************************************************************************************************/

/*==============================================================================================*/
/*                                 << インクルード >>                                           */
/*==============================================================================================*/
#include "KsMD5.h"

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/
#define ksMD5_SIZE	( 16 )

#define F1(x, y, z) (z ^ (x & (y ^ z)))
#define F2(x, y, z) F1(z, x, y)
#define F3(x, y, z) (x ^ y ^ z)
#define F4(x, y, z) (y ^ (x | ~z))


#define ksMD5STEP( f, w, x, y, z, data, s ) ( w += f(x, y, z) + data,  w = w<<s | w>>(32-s),  w += x )

/************************************************************************************************/
/*
 * MD5コンテキストの初期化
 * @param		pContext		コンテキスト
 */
/************************************************************************************************/
#ifndef ksBIGENDIAN
	#define KsByteReverse(buf, len)	/* Nothing */
#else
	static void KsByteReverse( KsUInt8 *buf, KsUInt32 longs)
	{
	    KsUInt32	t;

	    do
		{
			t = (KsUInt32) ((KsUInt32) buf[3] << 8 | buf[2]) << 16 |
		    ((KsUInt32) buf[1] << 8 | buf[0]);
			*(KsUInt32*) buf = t;
			buf += 4;
	    }while( --longs );
	}
#endif

/************************************************************************************************/
/*
 * MD5コンテキストの初期化
 * @param		pContext		コンテキスト
 */
/************************************************************************************************/
void KsMD5Init( KsMD5Context* pContext )
{
    pContext->buf[ 0 ] = 0x67452301;
    pContext->buf[ 1 ] = 0xefcdab89;
    pContext->buf[ 2 ] = 0x98badcfe;
    pContext->buf[ 3 ] = 0x10325476;

    pContext->bits[ 0 ] = 0;
    pContext->bits[ 1 ] = 0;
}

/*
 * Update context to reflect the concatenation of another buffer full
 * of bytes.
 */
void KsMD5Update( KsMD5Context* pContext, const KsUInt8 *buf, KsUInt32 len )
{
    register KsUInt32	t;

    /* bit Count の更新 */
    t = pContext->bits[0];

    if( (pContext->bits[0] = t + ((KsUInt32) len << 3)) < t )

	pContext->bits[ 1 ]++;
    pContext->bits[ 1 ] += len >> 29;

    t = (t >> 3) & 0x3f;

    if( t )
	{
		KsUInt8 *p = (KsUInt8*) pContext->in + t;

		t = 64 - t;
		if( len < t )
		{
			memmove(p, buf, len);
			return;
		}
		memmove( p, buf, t );
		KsByteReverse( pContext->in, 16 );
		KsMD5Transform( pContext->buf, (KsUInt32*)pContext->in );
		buf += t;
		len -= t;
    }
    while( len >= 64 )
	{
		memmove( pContext->in, buf, 64 );
		KsByteReverse( pContext->in, 16 );
		KsMD5Transform( pContext->buf, reinterpret_cast<KsUInt32*>( pContext->in ) );
		buf += 64;
		len -= 64;
    }

    memmove( pContext->in, buf, len );
}



/*
 * Final wrapup - pad to 64-byte boundary with the bit pattern 
 * 1 0* (64-bit count of bits processed, MSB-first)
 */
void KsMD5Final( KsUInt8 digest[16], KsMD5Context* ctx )
{
    KsUInt32 count;
    KsUInt8 *p;

    /* Compute number of bytes mod 64 */
    count = (ctx->bits[0] >> 3) & 0x3F;

    /* Set the first char of padding to 0x80.  This is safe since there is
       always at least one byte free */
    p = ctx->in + count;
    *p++ = 0x80;

    /* Bytes of padding needed to make 64 bytes */
    count = 64 - 1 - count;

    /* Pad out to 56 mod 64 */
    if (count < 8) {
	/* Two lots of padding:  Pad the first block to 64 bytes */
	memset(p, 0, count);
	KsByteReverse(ctx->in, 16);
	KsMD5Transform(ctx->buf, (KsUInt32 *) ctx->in);

	/* Now fill the next block with 56 bytes */
	memset(ctx->in, 0, 56);
    } else {
	/* Pad block to 56 bytes */
	memset(p, 0, count - 8);
    }
    KsByteReverse(ctx->in, 14);

    /* Append length in bits and transform */
    ((KsUInt32 *) ctx->in)[14] = ctx->bits[0];
    ((KsUInt32 *) ctx->in)[15] = ctx->bits[1];

    KsMD5Transform(ctx->buf, (KsUInt32 *) ctx->in);
    KsByteReverse((KsUInt8 *) ctx->buf, 4);
    memmove(digest, ctx->buf, 16);
    memset(ctx, 0, sizeof(ctx));	/* In case it's sensitive */
}



/*
 * The core of the MD5 algorithm, this alters an existing MD5 hash to
 * reflect the addition of 16 longwords of new data.  MD5Update blocks
 * the data and converts bytes into longwords for this routine.
 */
void KsMD5Transform( KsUInt32 buf[4], KsUInt32 in[16])
{
    register KsUInt32 a, b, c, d;

    a = buf[0];
    b = buf[1];
    c = buf[2];
    d = buf[3];

    ksMD5STEP(F1, a, b, c, d, in[ 0] + 0xd76aa478,  7);
    ksMD5STEP(F1, d, a, b, c, in[ 1] + 0xe8c7b756, 12);
    ksMD5STEP(F1, c, d, a, b, in[ 2] + 0x242070db, 17);
    ksMD5STEP(F1, b, c, d, a, in[ 3] + 0xc1bdceee, 22);
    ksMD5STEP(F1, a, b, c, d, in[ 4] + 0xf57c0faf,  7);
    ksMD5STEP(F1, d, a, b, c, in[ 5] + 0x4787c62a, 12);
    ksMD5STEP(F1, c, d, a, b, in[ 6] + 0xa8304613, 17);
    ksMD5STEP(F1, b, c, d, a, in[ 7] + 0xfd469501, 22);
    ksMD5STEP(F1, a, b, c, d, in[ 8] + 0x698098d8,  7);
    ksMD5STEP(F1, d, a, b, c, in[ 9] + 0x8b44f7af, 12);
    ksMD5STEP(F1, c, d, a, b, in[10] + 0xffff5bb1, 17);
    ksMD5STEP(F1, b, c, d, a, in[11] + 0x895cd7be, 22);
    ksMD5STEP(F1, a, b, c, d, in[12] + 0x6b901122,  7);
    ksMD5STEP(F1, d, a, b, c, in[13] + 0xfd987193, 12);
    ksMD5STEP(F1, c, d, a, b, in[14] + 0xa679438e, 17);
    ksMD5STEP(F1, b, c, d, a, in[15] + 0x49b40821, 22);

    ksMD5STEP(F2, a, b, c, d, in[ 1] + 0xf61e2562,  5);
    ksMD5STEP(F2, d, a, b, c, in[ 6] + 0xc040b340,  9);
    ksMD5STEP(F2, c, d, a, b, in[11] + 0x265e5a51, 14);
    ksMD5STEP(F2, b, c, d, a, in[ 0] + 0xe9b6c7aa, 20);
    ksMD5STEP(F2, a, b, c, d, in[ 5] + 0xd62f105d,  5);
    ksMD5STEP(F2, d, a, b, c, in[10] + 0x02441453,  9);
    ksMD5STEP(F2, c, d, a, b, in[15] + 0xd8a1e681, 14);
    ksMD5STEP(F2, b, c, d, a, in[ 4] + 0xe7d3fbc8, 20);
    ksMD5STEP(F2, a, b, c, d, in[ 9] + 0x21e1cde6,  5);
    ksMD5STEP(F2, d, a, b, c, in[14] + 0xc33707d6,  9);
    ksMD5STEP(F2, c, d, a, b, in[ 3] + 0xf4d50d87, 14);
    ksMD5STEP(F2, b, c, d, a, in[ 8] + 0x455a14ed, 20);
    ksMD5STEP(F2, a, b, c, d, in[13] + 0xa9e3e905,  5);
    ksMD5STEP(F2, d, a, b, c, in[ 2] + 0xfcefa3f8,  9);
    ksMD5STEP(F2, c, d, a, b, in[ 7] + 0x676f02d9, 14);
    ksMD5STEP(F2, b, c, d, a, in[12] + 0x8d2a4c8a, 20);

    ksMD5STEP(F3, a, b, c, d, in[ 5] + 0xfffa3942,  4);
    ksMD5STEP(F3, d, a, b, c, in[ 8] + 0x8771f681, 11);
    ksMD5STEP(F3, c, d, a, b, in[11] + 0x6d9d6122, 16);
    ksMD5STEP(F3, b, c, d, a, in[14] + 0xfde5380c, 23);
    ksMD5STEP(F3, a, b, c, d, in[ 1] + 0xa4beea44,  4);
    ksMD5STEP(F3, d, a, b, c, in[ 4] + 0x4bdecfa9, 11);
    ksMD5STEP(F3, c, d, a, b, in[ 7] + 0xf6bb4b60, 16);
    ksMD5STEP(F3, b, c, d, a, in[10] + 0xbebfbc70, 23);
    ksMD5STEP(F3, a, b, c, d, in[13] + 0x289b7ec6,  4);
    ksMD5STEP(F3, d, a, b, c, in[ 0] + 0xeaa127fa, 11);
    ksMD5STEP(F3, c, d, a, b, in[ 3] + 0xd4ef3085, 16);
    ksMD5STEP(F3, b, c, d, a, in[ 6] + 0x04881d05, 23);
    ksMD5STEP(F3, a, b, c, d, in[ 9] + 0xd9d4d039,  4);
    ksMD5STEP(F3, d, a, b, c, in[12] + 0xe6db99e5, 11);
    ksMD5STEP(F3, c, d, a, b, in[15] + 0x1fa27cf8, 16);
    ksMD5STEP(F3, b, c, d, a, in[ 2] + 0xc4ac5665, 23);

    ksMD5STEP(F4, a, b, c, d, in[ 0] + 0xf4292244,  6);
    ksMD5STEP(F4, d, a, b, c, in[ 7] + 0x432aff97, 10);
    ksMD5STEP(F4, c, d, a, b, in[14] + 0xab9423a7, 15);
    ksMD5STEP(F4, b, c, d, a, in[ 5] + 0xfc93a039, 21);
    ksMD5STEP(F4, a, b, c, d, in[12] + 0x655b59c3,  6);
    ksMD5STEP(F4, d, a, b, c, in[ 3] + 0x8f0ccc92, 10);
    ksMD5STEP(F4, c, d, a, b, in[10] + 0xffeff47d, 15);
    ksMD5STEP(F4, b, c, d, a, in[ 1] + 0x85845dd1, 21);
    ksMD5STEP(F4, a, b, c, d, in[ 8] + 0x6fa87e4f,  6);
    ksMD5STEP(F4, d, a, b, c, in[15] + 0xfe2ce6e0, 10);
    ksMD5STEP(F4, c, d, a, b, in[ 6] + 0xa3014314, 15);
    ksMD5STEP(F4, b, c, d, a, in[13] + 0x4e0811a1, 21);
    ksMD5STEP(F4, a, b, c, d, in[ 4] + 0xf7537e82,  6);
    ksMD5STEP(F4, d, a, b, c, in[11] + 0xbd3af235, 10);
    ksMD5STEP(F4, c, d, a, b, in[ 2] + 0x2ad7d2bb, 15);
    ksMD5STEP(F4, b, c, d, a, in[ 9] + 0xeb86d391, 21);

    buf[0] += a;
    buf[1] += b;
    buf[2] += c;
    buf[3] += d;
}

void KsCryptTo64( KsInt8* s, KsUInt32 v, KsInt32 n )
{
	/* 0 ... 63 => ascii - 64 */
	static KsUInt8 itoa64[] = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	
	while( --n >= 0 )
	{
		*s++ = itoa64[ v & 0x3f ];
		v >>= 6;
	}
}

KsInt8* KsCryptMD5( const KsInt8* pw, const KsInt8* salt)	
{
	static KsInt8	*magic = "$1$";	/*
					 * This string is magic for
					 * this algorithm.  Having
					 * it this way, we can get
					 * get better later on
					 */
	static KsInt8     passwd[120], *p;
	static const KsInt8 *sp,*ep;
	KsUInt8	final[ksMD5_SIZE];
	KsInt32 sl,pl,i;
	KsMD5Context	ctx,ctx1;
	KsUInt32 l;

	/* Refine the Salt first */
	sp = salt;

	/* If it starts with the magic string, then skip that */
	if(!strncmp(sp,magic,strlen(magic)))
		sp += strlen(magic);

	/* It stops at the first '$', max 8 chars */
	for( ep=sp; *ep && *ep != '$' && ep < (sp+8); ep++ ){
		continue;
	}

	/* get the length of the true salt */
	sl = static_cast<KsInt32>(ep - sp);

	KsMD5Init( &ctx );

	/* The password first, since that is what is most unknown */
	KsMD5Update(&ctx,reinterpret_cast<const KsUInt8*>(pw),static_cast<KsUInt32>( strlen(pw)));

	/* Then our magic string */
	KsMD5Update(&ctx,reinterpret_cast<const KsUInt8*>(magic),static_cast<KsUInt32>( strlen(magic)));

	/* Then the raw salt */
	KsMD5Update(&ctx,reinterpret_cast<const KsUInt8*>(sp),sl);

	/* Then just as many characters of the MD5(pw,salt,pw) */
	KsMD5Init(&ctx1);
	KsMD5Update(&ctx1,reinterpret_cast<const KsUInt8*>(pw), static_cast<KsUInt32>( strlen(pw)));
	KsMD5Update(&ctx1,reinterpret_cast<const KsUInt8*>(sp),sl);
	KsMD5Update(&ctx1,reinterpret_cast<const KsUInt8*>(pw), static_cast<KsUInt32>( strlen(pw)));
	KsMD5Final(final,&ctx1);
	
	for(pl = static_cast<KsUInt32>( strlen(pw)); pl > 0; pl -= ksMD5_SIZE){
		KsMD5Update(&ctx,final,pl>ksMD5_SIZE ? ksMD5_SIZE : pl);
	}

	/* Don't leave anything around in vm they could use. */
	memset(final,0,sizeof final);

	/* Then something really weird... */
	for (i = static_cast<KsUInt32>( strlen(pw) ); i ; i >>= 1)
		if(i&1)
		    KsMD5Update(&ctx, reinterpret_cast<const KsUInt8*>(final), 1);
		else
		    KsMD5Update(&ctx, reinterpret_cast<const KsUInt8*>(pw), 1);

	/* Now make the output string */
	strcpy(passwd,magic);
	strncat(passwd,sp,sl);
	strcat(passwd,"$");

	KsMD5Final(final,&ctx);

	/*
	 * and now, just to make sure things don't run too fast
	 * On a 60 Mhz Pentium this takes 34 msec, so you would
	 * need 30 seconds to build a 1000 entry dictionary...
	 */
	for( i=0; i<1000; i++ )
	{
		KsMD5Init(&ctx1);

		if(i & 1)
		{
			KsMD5Update(&ctx1,reinterpret_cast<const KsUInt8*>(pw), static_cast<KsUInt32>( strlen(pw)));
		}
		else
		{
			KsMD5Update(&ctx1,reinterpret_cast<const KsUInt8*>(final),ksMD5_SIZE);
		}

		if(i % 3)
		{
			KsMD5Update(&ctx1,reinterpret_cast<const KsUInt8*>(sp),sl);
		}
		if(i % 7)
		{
			KsMD5Update(&ctx1,reinterpret_cast<const KsUInt8*>(pw), static_cast<KsUInt32>( strlen(pw)) );
		}
		if(i & 1)
		{
			KsMD5Update(&ctx1,final,ksMD5_SIZE);
		}
		else
		{
			KsMD5Update(&ctx1, reinterpret_cast<const KsUInt8*>(pw), static_cast<KsUInt32>( strlen(pw) ) );
		}

		KsMD5Final(final,&ctx1);
	}

	p = passwd + strlen(passwd);

	l = (final[ 0]<<16) | (final[ 6]<<8) | final[12];
	KsCryptTo64(p,l,4); p += 4;
	l = (final[ 1]<<16) | (final[ 7]<<8) | final[13];
	KsCryptTo64(p,l,4); p += 4;
	l = (final[ 2]<<16) | (final[ 8]<<8) | final[14];
	KsCryptTo64(p,l,4); p += 4;
	l = (final[ 3]<<16) | (final[ 9]<<8) | final[15];
	KsCryptTo64(p,l,4); p += 4;
	l = (final[ 4]<<16) | (final[10]<<8) | final[ 5];
	KsCryptTo64(p,l,4); p += 4;
	l =                    final[11]                ;
	KsCryptTo64(p,l,2); p += 2;
	*p = '\0';

	/* Don't leave anything around in vm they could use. */
	memset(final,0,sizeof(final));

	return passwd;
}





