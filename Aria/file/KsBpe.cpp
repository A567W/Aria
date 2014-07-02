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
 * @file	KsBpe.cpp
 * @brief	BPE(Byte Pair Encoding:バイト対符号化)圧縮
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
/************************************************************************************************/

/*===============================================================================================*/
/*                                 << インクルード >>                                            */
/*===============================================================================================*/
#include "KsBpe.h"

/*===============================================================================================*/
/*                                     << 定義 >>                                                */
/*===============================================================================================*/

/*===============================================================================================*/
/*                                     << 宣言 >>                                                */
/*===============================================================================================*/
ksNS_KS_BEGIN

//-------------------------------------------------------------------
//-------------------------------------------------------------------

//-------------------------------------------------------------------
//  Constructor and Destructor
//-------------------------------------------------------------------

CBPE::CBPE() : m_BufSize (0x00), m_PairCnt (0x00)
{
  m_WorkBuf = ksNew KsByte[ CBPE::BPE_WORKBUFFERSIZE ];
  m_PairBuf = ksNew KsByte[ CBPE::BPE_PAIRBUFFERSIZE ];
}

CBPE::~CBPE()
{
  ksDELETEARRAY( m_WorkBuf );
  ksDELETEARRAY( m_PairBuf );
}

KsULong CBPE::Encode( void *pDest, void *pSrc, KsULong SrcSize )
{
  unsigned char *SrcAddr = (unsigned char*)pSrc;
  unsigned char *DestAddr = (unsigned char*)pDest;

  unsigned int DestSize = 0, SrcPos = 0, DestPos = 0;

  while( SrcPos < SrcSize ){
    m_BufSize = CBPE::BPE_WORKBUFFERSIZE;
    if( SrcPos + m_BufSize < SrcSize ){
      memcpy( m_WorkBuf, &SrcAddr[ SrcPos ], m_BufSize );
      SrcPos += m_BufSize;
    } // if( SrcPos + m_BufSize < SrcSize )
    else{
      m_BufSize = SrcSize - SrcPos;
      memcpy( m_WorkBuf, &SrcAddr[ SrcPos ], m_BufSize );
      SrcPos += m_BufSize;
    } // else

    m_PairCnt = 0;
    DestSize = EncodeSub( m_BufSize );

    if( !m_PairCnt ){
      if( DestAddr ){
        DestAddr[ DestPos + 0 ] = 0x00;
        DestAddr[ DestPos + 1 ] = ( DestSize & 0xff );
        DestAddr[ DestPos + 2 ] = (char)( DestSize >> 8 );
        memcpy( &DestAddr[DestPos+3], m_WorkBuf, DestSize );
      }
      DestPos += ( DestSize + 3 );
    } // if( !m_PairCnt )
    else{
      if( DestAddr ){
        DestAddr[ DestPos + 0 ] = 0x80;
        DestAddr[ DestPos + 1 ] = ( DestSize & 0xff );
        DestAddr[ DestPos + 2 ] = (char)( DestSize >> 8 );
        DestAddr[ DestPos + 3 ] = (unsigned char)m_PairCnt;
        memcpy( &DestAddr[DestPos+4], m_PairBuf, m_PairCnt*3 );
        memcpy( &DestAddr[DestPos+4+(m_PairCnt*3)], m_WorkBuf, DestSize );
      }
      DestPos += ( 4 + (m_PairCnt*3) + DestSize );
    } // else
  } // while( SrcPos < SrcSize )

  return DestPos;
}

KsULong CBPE::Decode( void *pDest, void *pSrc, KsULong SrcSize )
{
  unsigned char *SrcAddr = (unsigned char*)pSrc;
  unsigned char *DestAddr = (unsigned char*)pDest;

  int i = 0, c1, c2, c3, c4, size, rpos, DestPos = 0;
  unsigned int SrcPos = 0;
  unsigned char stackBuf[256], stackHead = 0x00, pair1[256], pair2[256];

  while( SrcPos < SrcSize ){
    c1 = SrcAddr[SrcPos++];
    c2 = SrcAddr[SrcPos++];
    c3 = SrcAddr[SrcPos++];
    size = c2 | (c3 << 8);
    rpos = 0;

    if( c1 == 0x00 ){
      while( rpos < size ){
        rpos++;
        DestAddr ? DestAddr[ DestPos++ ] = static_cast<unsigned char>(c1) : DestPos++;
      }
      continue;
    } // if( c1 == 0x00 )

    for( i = 0; i < 256; i++ ){
      pair1[i] = static_cast<unsigned char>(i);
      pair2[i] = 0x00;
    } // for( i = 0; i < 256; i++ )

    c1 = SrcAddr[ SrcPos++ ];
    for( i = 0; i < c1; i++ ){
      c2 = SrcAddr[ SrcPos++ ];
      c3 = SrcAddr[ SrcPos++ ];
      c4 = SrcAddr[ SrcPos++ ];
      pair1[c2] = static_cast<unsigned char>(c3);
      pair2[c2] = static_cast<unsigned char>(c4);
    } // for( i = 0; i < c1; i++ )

    while( rpos < size || stackHead > 0 ){
      if( !stackHead ){
        c1 = SrcAddr[ SrcPos++ ];
        rpos++;
      }
      else{
        c1 = stackBuf[ --stackHead ];
      }

      for(;;){
        if( pair1[c1] == c1 ){
          DestAddr ? DestAddr[ DestPos++ ] = static_cast<unsigned char>(c1) : DestPos++;
          break;
        }
        stackBuf[ stackHead++ ] = pair2[c1];
        c1 = pair1[c1];
      } // for(;;)
    } // while( rpos < size || stackHead > 0 )
  } // while( SrcPos < SrcSize )

  return DestPos;
}

//  begin private functions
//-------------------------------------------------------------------
//-------------------------------------------------------------------

KsULong CBPE::EncodeSub( int BufSize )
{
  int i, rpos, wpos, tmpCnt, maxCnt, tmpBufSize = BufSize - 1;
  unsigned char ch, c1, c2, maxC1, maxC2, pairMap2[ 256 * 256 ];
  bool pairMap1[ 256 ] = { 0x00 };

  for( i = 0; i < 256; i++ )
    pairMap1[ m_WorkBuf[i] ] = 0x01;

  for(;;){
    for( i = 0; i < 256; i++ ){
      if( pairMap1[i] == 0 ) break;
    } // for( i = 0; i < 256; i++ )
    if( i == 256 ) break;
    ch = static_cast<unsigned char>(i);

    memset( pairMap2, 0, sizeof( pairMap2 ) );
    for( i = 0, maxCnt = 0; i < BufSize - 1; i += 2 ){
      c1 = m_WorkBuf[ i+0 ];
      c2 = m_WorkBuf[ i+1 ];

      tmpCnt = ++pairMap2[ c1 | (c2 << 8) ];
      if( maxCnt < tmpCnt ){
        maxCnt = tmpCnt;
        maxC1 = c1;
        maxC2 = c2;
      } // if( maxCnt < tmpCnt )
    } // for( i = 0, maxCnt = 0; i < BufSize - 1; i += 2 )

    if( maxCnt < 4 ) break;
    rpos = wpos = 0;

    while( rpos < tmpBufSize ){
      if( m_WorkBuf[ rpos ] == maxC1 && m_WorkBuf[ rpos+1 ] == maxC2 ){
        m_WorkBuf[ wpos++ ] = ch;
        rpos += 2;
      }
      else{
        m_WorkBuf[ wpos++ ] = m_WorkBuf[ rpos++ ];
      }
    } // while( rpos < tmpBufSize )

    if( rpos == tmpBufSize ) m_WorkBuf[ wpos++ ] = m_WorkBuf[ rpos++ ];
    BufSize = wpos;

    m_PairBuf[ m_PairCnt*3 + 0 ] = ch;
    m_PairBuf[ m_PairCnt*3 + 1 ] = maxC1;
    m_PairBuf[ m_PairCnt*3 + 2 ] = maxC2;
    m_PairCnt++;
    pairMap1[ch] = 0x01;
  } // for(;;)
  return BufSize;
}

ksNS_KS_END

//  end of CBPE.cpp
