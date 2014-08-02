/*************************************************************************************************/
/** 
 * @file	KsWindowUtility.cpp
 * @brief	Windows関係ユーティリティ
 * @author	A567W
 * @date	2003/03/22
 * @since	----/--/--
 * @version	1.0.0
 */
/*************************************************************************************************/


/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsWindowUtility.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/*************************************************************************************************/
/*
 * タスクバーを除いたデスクトップのサイズを取得する
 * @param		pRect		(OUT)サイズを取得する構造体のポインタ
 */
/*************************************************************************************************/
void KsWindowUtility::getDeskTopClientRect( RECT* pRect )
{
	// タスクバーを除いたサイズを取得する
	::SystemParametersInfo( SPI_GETWORKAREA, 0, pRect, 0 );
}

/*************************************************************************************************/
/*
 * デスクトップのサイズを取得する
 * @param		pRect		(OUT)サイズを取得する構造体のポインタ
 */
/*************************************************************************************************/
void KsWindowUtility::getDeskTopWindowRect( RECT* pRect )
{
	::GetWindowRect( GetDesktopWindow(), pRect );
}

/*************************************************************************************************/
/*
 * GetNativeSystemInfoラッパー関数
 * @parm	lpSystemInfo	(OUT)システム情報を取得する構造体のポインタ
 * @retval	ksTRUE			取得成功
 * @retval	ksFALSE			取得失敗
 * @note GetNativeSystemInfoはWindows XP以降でサポートされている。
 *		 そのためWindows 2000以前ではksFALSEが返る
 */
/*************************************************************************************************/
KsBool KsWindowUtility::getNativeSystemInfo( LPSYSTEM_INFO lpSystemInfo )
{
	HMODULE	hDLL;
	void	(CALLBACK* pfnGetNativeSystemInfo)(LPSYSTEM_INFO);

	if( lpSystemInfo == NULL )
	{
		return ksFALSE;
	}

	KsZeroMemory( lpSystemInfo, sizeof(SYSTEM_INFO) );

	hDLL = ::LoadLibrary( ksT("Kernel32.dll") );

	if( hDLL == NULL )
	{
		return ksFALSE;
	}

	(*(FARPROC*)&pfnGetNativeSystemInfo) = ::GetProcAddress( hDLL, "GetNativeSystemInfo" );

	if( pfnGetNativeSystemInfo == NULL )
	{
		::FreeLibrary( hDLL );
		return	ksFALSE;
	}

	pfnGetNativeSystemInfo( lpSystemInfo );

	::FreeLibrary( hDLL );

	return	ksTRUE;
}

/*************************************************************************************************/
/*
 * プロセッサの数を取得する
 * @return	プロセッサの数
 */
/*************************************************************************************************/
KsUInt32 KsWindowUtility::getNumProcessor()
{
	SYSTEM_INFO	sysInfo;

	if( getNativeSystemInfo( &sysInfo ) )
	{
		return s_cast<KsUInt32>( sysInfo.dwNumberOfProcessors );
	}

	return 1;
}

/*************************************************************************************************/
/*
 * 見つけたウインドウをアクティブにする
 */
/*************************************************************************************************/
KsBool KsWindowUtility::activeFindWindow( const KsChar* pClassName, const KsChar* pWindowName )
{
	/* ウィンドウのタイトルが常に同じ場合は、第２引数にタイトルを指定 */
	HWND	hWnd = FindWindow( pClassName, pWindowName );

	if( hWnd )
	{
		/* 発見 */
		/* アイコン化されているのであれば、元のサイズに戻す */
		if( IsIconic( hWnd ) )
		{
			ShowWindow( hWnd, SW_RESTORE );
		}

		/* 見つかったウィンドウをフォアグラウンドウィンドウにする */
		SetForegroundWindow( ::GetLastActivePopup( hWnd ) );
		//::SetForegroundWindow(hWnd);

		SetActiveWindow( hWnd );

		InvalidateRect( hWnd, NULL, false );

		return ksTRUE;
	}

	return ksFALSE;
}

ksNS_KS_END

