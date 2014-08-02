/*************************************************************************************************/
/** 
 * @file	KsWindowGL.cpp
 * @brief	ウインドウ
 * @author	A567W
 * @date	2003/03/22
 * @since	----/--/--
 * @version	1.0.0
 */
/*************************************************************************************************/

/*===============================================================================================*/
/*                                 << インクルード >>                                             */
/*===============================================================================================*/
#include "KsWindowGL.h"

/*===============================================================================================*/
/*                                     << 定義 >>                                                */
/*===============================================================================================*/

ksNS_KS_BEGIN

/*
 * コンストラクタ(ウインドウ生成)
 * @param		param			ウインドウ生成のためのパラメータ
 * @param		hParent			親ウインドウのハンドル
 */
KsWindowGL::KsWindowGL( const KsWindowGLParam& param, HWND hParent, void* pUserData )
{
	create( param, hParent, pUserData );
}

KsWindowGL::~KsWindowGL()
{
    GLFWEventHandler::setGLView( ksNULLPTR );
    glfwTerminate();
}

//=================================================================================================
//
//=================================================================================================
KsBool KsWindowGL::create( const KsWindowGLParam &param, HWND hParent, void* pUserData )
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

ksNS_KS_END

