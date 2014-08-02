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
 * @file	KsEvent.cpp
 * @brief	スレッドイベント
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/

/*==============================================================================================*/
/*                                 << インクルード >>                                             */
/*==============================================================================================*/
#include "KsEvent.h"

/*===============================================================================================*/
/*                                     << 定義 >>                                                */
/*===============================================================================================*/
ksNS_KS_BEGIN


/************************************************************************************************/
/*
 * コンストラクタ
 */
/************************************************************************************************/
KsEvent::KsEvent()
{
#if ( ksPLATFORM_TARGET == ksPLATFORM_WIN32 )
    m_handle = ::CreateEvent( NULL, ksTRUE, ksFALSE, NULL );
#endif
}


/************************************************************************************************/
/*
 * デストラクタ
 */
/************************************************************************************************/
KsEvent::~KsEvent()
{
#if ( ksPLATFORM_TARGET == ksPLATFORM_WIN32 )
    ::CloseHandle( m_handle );
#endif
}

/*************************************************************************************************/
/*
 * イベントオブジェクトをシグナル状態にする。
 * @param	hEvent		イベントオブジェクトを示すハンドル。
 * @retval	ksTRUE		成功
 * @retval	ksFALSE		失敗
 */
/*************************************************************************************************/
KsBool KsEvent::signale()
{
#if ( ksPLATFORM_TARGET == ksPLATFORM_WIN32 )
	return ::SetEvent( m_handle );
#endif
}

/*************************************************************************************************/
/*
 * イベントオブジェクトを非シグナル状態にする。
 * @param	hEvent		イベントオブジェクトを示すハンドル。
 * @retval	ksTRUE		成功
 * @retval	ksFALSE		失敗
 */
/*************************************************************************************************/
KsBool KsEvent::reset()
{
#if ( ksPLATFORM_TARGET == ksPLATFORM_WIN32 )
	return ::ResetEvent( m_handle );
#endif
}

/*************************************************************************************************/
/*
 * 指定されたカーネルオブジェクトがシグナル状態になるか、
 * 指定された時間が経過するまでスレッドをスリープさせます。
 * @param	handle			オブジェクトハンドル
 * @param	milliseconds	待ち時間をミリ秒単位
 * @return					状態
 */
/*************************************************************************************************/
KsUInt32 KsEvent::wait()
{
#if ( ksPLATFORM_TARGET == ksPLATFORM_WIN32 )
	return s_cast<KsUInt32>( ::WaitForSingleObject( m_handle, INFINITE ) );
#endif
}

ksNS_KS_END

