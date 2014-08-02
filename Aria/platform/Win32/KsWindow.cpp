/*************************************************************************************************/
/** 
 * @file	KsWindow.cpp
 * @brief	ウインドウ
 * @author	A567W
 * @date	2003/03/22
 * @since	----/--/--
 * @version	1.0.0
 */
/*************************************************************************************************/

/*************************************************************************************************/
/*                                 << インクルード >>                                             */
/*************************************************************************************************/
#include "KsWindow.h"


ksNS_KS_BEGIN

/*
 * コンストラクタ(ウインドウ生成)
 * @param		param			ウインドウ生成のためのパラメータ
 * @param		hParent			親ウインドウのハンドル
 */
KsWindow::KsWindow( const KsWindowParam& param, HWND hParent, void* pUserData )
{
	create( param, hParent, pUserData );
	//KsAssert( ksTRUE == create( param, hParent, pUserData ), "ウインドウを生成できません。" );
}

//=================================================================================================
//
//=================================================================================================
KsBool KsWindow::create( const KsWindowParam &param, HWND hParent, void* pUserData )
{
	m_windowParam = param;

	WNDCLASSEX			wc;
	wc.cbSize			= sizeof( WNDCLASSEX );
	wc.style			= CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc		= wndProc;
	wc.cbClsExtra		= 0;
	wc.cbWndExtra		= 4;									// ユーザーデータ用に4バイト確保しておく
	wc.hInstance		= KsAppInstance::m_hInstance;			// インスタンス
	wc.hIcon			= LoadIcon( NULL, IDI_APPLICATION );	//LoadIcon( KsAppInstance::m_hInstance, MAKEINTRESOURCE( IDI_ICON_MAIN ) );
	wc.hIconSm			= LoadIcon( NULL, IDI_APPLICATION );	//LoadIcon( KsAppInstance::m_hInstance, MAKEINTRESOURCE( IDI_ICON_SUB  ) );
	wc.lpszMenuName		= NULL;									//MAKEINTRESOURCE( IDR_MENU_MAIN );
	wc.hCursor			= LoadCursor( NULL,IDC_ARROW );
	wc.hbrBackground	= ( HBRUSH )GetStockObject( BLACK_BRUSH );
	wc.lpszClassName	= param.m_className.c_str();

	if( !::RegisterClassEx( &wc ) ) {
		return ksFALSE;
	}

	RECT	rect;

	rect.left   = 0;
	rect.top    = 0;
	rect.right  = param.m_sizeX;
	rect.bottom = param.m_sizeY;

	// クライアントのサイズからウィンドウのサイズを得る
	AdjustWindowRectEx( &rect, param.m_style ,FALSE, 0 );		//メニューなし
	//AdjustWindowRectEx( &rect, param.m_style ,TRUE, 0 );		//メニューあり

	//.....ウインドウ作成
	m_hWnd = CreateWindowEx(
							param.m_styleEx,
							param.m_className.c_str(),
							param.m_caption.c_str(),
							param.m_style,
							param.m_posX,
							param.m_posY,
							rect.right  - rect.left,
							rect.bottom - rect.top,
							hParent,
							NULL,
							KsAppInstance::m_hInstance,
							pUserData
							);
	//.....描画
	ShowWindow( m_hWnd, KsAppInstance::m_nCmdShow );
	//.....更新
	UpdateWindow( m_hWnd );

	return ksTRUE;
}
//=================================================================================================
//
//=================================================================================================
void KsWindow::setPos( int x, int y )
{
	if(m_hWnd==NULL) return;
	//
	SetWindowPos( m_hWnd, HWND_TOP, x, y, NULL, NULL, SWP_NOSIZE|SWP_NOZORDER );
}
//=================================================================================================
//
//=================================================================================================
void KsWindow::setCenter()
{
	HWND		hDeskWnd;
	RECT		deskrc,	rc;
	KsInt32	x, y;

	if( m_hWnd )
	{
		hDeskWnd = GetDesktopWindow();
		GetWindowRect( hDeskWnd, (LPRECT)&deskrc );
		GetWindowRect( m_hWnd, (LPRECT)&rc );
		x = ( deskrc.right  - ( rc.right-rc.left ) )/2;
		y = ( deskrc.bottom - ( rc.bottom-rc.top ) )/2;
		SetWindowPos( m_hWnd, HWND_TOP, x, y, (rc.right-rc.left), (rc.bottom-rc.top), SWP_SHOWWINDOW );
	}
}
//=================================================================================================
//
//=================================================================================================
KsInt32 KsWindow::messageLoop()
{
	MSG		msg;

	//if( PeekMessage( &msg, m_hWnd, 0, 0, PM_REMOVE ) )
	if( PeekMessage( &msg, 0, 0, 0, PM_REMOVE ) )
	{
		if( msg.message == WM_QUIT )
		{
			return 0;
		}

		TranslateMessage( &msg );
		DispatchMessage( &msg );
	}

	return 1;
}
//=================================================================================================
//
//=================================================================================================
LRESULT CALLBACK KsWindow::wndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
	/*LPCREATESTRUCT lpcs;
		D3D9RenderWindow* win;

	if( WM_CREATE != uMsg )
	{
			// Get window pointer
			win = (D3D9RenderWindow*)GetWindowLong( hWnd, 0 );
	}*/

	switch( uMsg )
	{
		case WM_CREATE:
		{
			LPCREATESTRUCT	lpcs = (LPCREATESTRUCT)lParam;
			//win = (D3D9RenderWindow*)(lpcs->lpCreateParams);
			if( lpcs->lpCreateParams ){
				// Store pointer in window user data area
				//SetWindowLong( hWnd, 0, (KsInt32)win );
			}
			else{
				//win->mActive = true;
			}
			break;
		}
		/*case WM_CREATE:
		{
		lpcs = (LPCREATESTRUCT)lParam;
			win = (D3D9RenderWindow*)(lpcs->lpCreateParams);
			// Store pointer in window user data area
			SetWindowLong( hWnd, 0, (KsInt32)win );
			win->mActive = true;
			break;
		}*/
		case WM_KEYDOWN:
		{
			switch( wParam )
			{	//強制終了
				case VK_ESCAPE:
				case VK_F12:
					//WINDOW::m_AppEndReq = TRUE;
					//メッセージWM_CLOASEをWindowsに送る
					// ウインドウ状態の時だけ
					if( IDYES == MessageBoxA( hWnd, "終了しますか？", "終了チェック", MB_YESNO | MB_ICONQUESTION ) )
					{
						PostMessage( hWnd, WM_CLOSE, 0, 0 );
					}
				break;
			}
			break;
		}
		case WM_DESTROY:
		{
			//::ShowWindow( hWnd, SW_HIDE );
			//::SetWindowLong( hWnd, GWL_STYLE, WS_POPUP );
			//::SetWindowPos( hWnd, (HWND)HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE );
	//		::ShowWindow( hWnd, SW_HIDE );
			PostQuitMessage(0);
			//PostMessage( hWnd, WM_CLOSE, 0, 0 );
			break;
		}
		/*case WM_NCDESTROY:
		{
			hWnd = NULL;
			break;
		}*/
		default:
		{
			return DefWindowProc( hWnd, uMsg, wParam, lParam );
		}

	}
	return 0;
}

ksNS_KS_END

