/*************************************************************************************************/
/** 
 * @file	KsWindowGL.cpp
 * @brief	�E�C���h�E
 * @author	A567W
 * @date	2003/03/22
 * @since	----/--/--
 * @version	1.0.0
 */
/*************************************************************************************************/

/*===============================================================================================*/
/*                                 << �C���N���[�h >>                                             */
/*===============================================================================================*/
#include "KsWindowGL.h"

/*===============================================================================================*/
/*                                     << ��` >>                                                */
/*===============================================================================================*/

ksNS_KS_BEGIN

/*
 * �R���X�g���N�^(�E�C���h�E����)
 * @param		param			�E�C���h�E�����̂��߂̃p�����[�^
 * @param		hParent			�e�E�C���h�E�̃n���h��
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
	wc.cbWndExtra		= 4;									// ���[�U�[�f�[�^�p��4�o�C�g�m�ۂ��Ă���
	wc.hInstance		= KsAppInstance::m_hInstance;			// �C���X�^���X
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

	// �N���C�A���g�̃T�C�Y����E�B���h�E�̃T�C�Y�𓾂�
	AdjustWindowRectEx( &rect, param.m_style ,FALSE, 0 );		//���j���[�Ȃ�
	//AdjustWindowRectEx( &rect, param.m_style ,TRUE, 0 );		//���j���[����

	//.....�E�C���h�E�쐬
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
	//.....�`��
	ShowWindow( m_hWnd, KsAppInstance::m_nCmdShow );
	//.....�X�V
	UpdateWindow( m_hWnd );

	return ksTRUE;
}

ksNS_KS_END

