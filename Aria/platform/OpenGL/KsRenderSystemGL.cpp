/************************************************************************************************/
/** 
 * @file		KsRenderSystemGL.cpp
 * @brief		OpenGL用の描画システム
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/

/*==============================================================================================*/
/*                                 << インクルード >>                                           */
/*==============================================================================================*/
#include "KsRenderSystemGL.h"
#include "KsDepthStencilStateGL.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

#if 0

class KsGLFWEventHandler
{
public:
    static void onGLFWError(int errorID, const char* errorDesc)
    {
        if (_view)
            _view->onGLFWError(errorID, errorDesc);
    }

    static void onGLFWMouseCallBack(GLFWwindow* window, int button, int action, int modify)
    {
        if (_view)
            _view->onGLFWMouseCallBack(window, button, action, modify);
    }

    static void onGLFWMouseMoveCallBack(GLFWwindow* window, double x, double y)
    {
        if (_view)
            _view->onGLFWMouseMoveCallBack(window, x, y);
    }

    static void onGLFWMouseScrollCallback(GLFWwindow* window, double x, double y)
    {
        if (_view)
            _view->onGLFWMouseScrollCallback(window, x, y);
    }

    static void onGLFWKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        if (_view)
            _view->onGLFWKeyCallback(window, key, scancode, action, mods);
    }

    static void onGLFWCharCallback(GLFWwindow* window, unsigned int character)
    {
        if (_view)
            _view->onGLFWCharCallback(window, character);
    }

    static void onGLFWWindowPosCallback(GLFWwindow* windows, int x, int y)
    {
        if (_view)
            _view->onGLFWWindowPosCallback(windows, x, y);
    }

    static void onGLFWframebuffersize(GLFWwindow* window, int w, int h)
    {
        if (_view)
            _view->onGLFWframebuffersize(window, w, h);
    }

    static void onGLFWWindowSizeFunCallback(GLFWwindow *window, int width, int height)
    {
        if (_view)
            _view->onGLFWWindowSizeFunCallback(window, width, height);
    }

    static void setGLView(GLView* view)
    {
        _view = view;
    }

private:
    static GLView* _view;
};

#endif

/************************************************************************************************/
/*
 * コンストラクタ
 * @param		hWnd				ウインドウのハンドル
 */
/************************************************************************************************/
KsRenderSystemGL::KsRenderSystemGL( void* pParam )
{
	/* 初期化する */
	initialize( pParam );
}

/************************************************************************************************/
/*
 * デストラクタ
 */
/************************************************************************************************/
KsRenderSystemGL::~KsRenderSystemGL()
{
	/* 後処理 */
	terminate();
}

/************************************************************************************************/
/*
 * 初期化処理
 * @param		hWnd				ウインドウのハンドル
 * @retval		ksTRUE				初期化成功
 * @retval		ksFALSE				初期化失敗
 */
/************************************************************************************************/
KsBool KsRenderSystemGL::initialize( void* pParam )
{
    if( !glfwInit() )
    {
        return ksFALSE;
    }

    m_pMonitor = glfwGetPrimaryMonitor();

    if( !m_pMonitor )
    {
        return ksFALSE;
    }

    m_pWindow = glfwCreateWindow(1280, 720, "Hello World", NULL, NULL);

    if( !m_pWindow )
    {
        glfwTerminate();
        return ksFALSE;
    }

    glfwMakeContextCurrent( m_pWindow );

	return ksTRUE;
}

/************************************************************************************************/
/*
 * 後処理
 * @retval		ksTRUE				後処理成功
 * @retval		ksFALSE				後処理失敗
 */
/************************************************************************************************/
KsBool KsRenderSystemGL::terminate()
{
    //GLFWEventHandler::setGLView( ksNULLPTR );
    glfwTerminate();

	return ksTRUE;
}

/************************************************************************************************/
/*
 * 描画バッファと表示バッファを入れ替え
 */
/************************************************************************************************/
void KsRenderSystemGL::present()
{
    /* Swap front and back buffers */
    glfwSwapBuffers( m_pWindow );

    /* Poll for and process events */
    glfwPollEvents();
}

/************************************************************************************************/
/*
 * 描画バッファと表示バッファを入れ替え
 */
/************************************************************************************************/
KsBool KsRenderSystemGL::isMessageLoop()
{
    return !glfwWindowShouldClose( m_pWindow );
}




/*------------------------------------------<< テクスチャ関係 >>------------------------------------------------------*/
/************************************************************************************************/
/*
 * テクスチャを生成する
 * @param		pFileName			ファイル名
 * @param		flags				生成フラグ
 * @return							テクスチャのポインタ
 */
/************************************************************************************************/
KsTexture* KsRenderSystemGL::createTextureFromFile( const KsChar* pFileName, KsUInt32 flags )
{
    return NULL;
}

/************************************************************************************************/
/*
 * テクスチャを生成する
 * @param		pData				イメージデータのポインタ
 * @param		width				テクスチャの幅
 * @param		height				テクスチャの高さ
 * @param		format				テクスチャフォーマット
 * @param		flags				生成フラグ
 * @return							テクスチャのポインタ
 */
/************************************************************************************************/
KsTexture* KsRenderSystemGL::createTexture( const KS_SUBRESOURCE_DATA* pData, KsUInt32 width, KsUInt32 height, KsUInt32 format, KsUInt32 flags, KsUInt32 usage )
{
	return NULL;
}


//! レンダリングターゲットを作成する
/*!
スワップチェインはバックバッファを持っていますが、レンダリングターゲットは持っていません。
バックバッファをレンダリングターゲットとして使用する場合、別途ターゲットを作成する必要があります。
この関数では作成済みのスワップチェインからバックバッファを取得し、それを利用してターゲットを作成しています。
*/
KsRenderTarget* KsRenderSystemGL::createRenderTargetView()
{
	return NULL;
}


//! レンダリングターゲットを作成する
/*!
スワップチェインはバックバッファを持っていますが、レンダリングターゲットは持っていません。
バックバッファをレンダリングターゲットとして使用する場合、別途ターゲットを作成する必要があります。
この関数では作成済みのスワップチェインからバックバッファを取得し、それを利用してターゲットを作成しています。
*/
KsRenderTarget* KsRenderSystemGL::createRenderTextureView( KsUInt32 width, KsUInt32 height, KsUInt32 format )
{
		return NULL;
}

KsRenderTarget* KsRenderSystemGL::createDepthStencilView( KsUInt32 width, KsUInt32 height, KsUInt32 format, KsUInt32 viewFormat, KsUInt32 resFormat )
{
    return NULL;
}

//! 深度バッファを作成する
/*!
深度バッファはスワップチェインには含まれていないため、バッファとなるテクスチャから作成します。
テクスチャ作成時に深度バッファとして使用する旨を通知する必要があります。
また、レンダリングターゲットと同様にバッファと別にターゲットを作成する必要があります。
*/
KsRenderTarget* KsRenderSystemGL::createDepthStencilView()
{
    return NULL;
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
KsUnorderedAccessView* KsRenderSystemGL::createUnorderedAccessView( KsUInt32 elementSize, KsUInt32 numElements, KsUInt32 format, KsUInt32 flags )
{
    return NULL;
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
KsStructuredBuffer* KsRenderSystemGL::createStructuredBuffer( KsUInt32 elementSize, KsUInt32 numElements, KsUInt32 format, KsUInt32 flags )
{
    return NULL;
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
KsRasterizerState* KsRenderSystemGL::createRasterizerState( const KS_RASTERIZER_DESC* pRasterizerState )
{
    return NULL;
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
KsSamplerState* KsRenderSystemGL::createSamplerState( const KS_SAMPLER_DESC* pSamplerStateDesc )
{
    return NULL;
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
KsBlendState* KsRenderSystemGL::createBlendState( const KS_BLEND_DESC* pBlendStateDesc )
{
    return NULL;
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
KsDepthStencilState* KsRenderSystemGL::createDepthStencilState( const KS_DEPTH_STENCIL_DESC* pDepthStencilDesc )
{
    return ksNew KsDepthStencilStateGL( this, pDepthStencilDesc );
}

/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
KsRenderContext* KsRenderSystemGL::createDeferredContext()
{
    return NULL;
}

#if 0
/************************************************************************************************/
/*
 *
 */
/************************************************************************************************/
KsCommandList* KsRenderSystemGL::createCommandList()
{
    return NULL;
}
#endif

ksNS_KS_END

