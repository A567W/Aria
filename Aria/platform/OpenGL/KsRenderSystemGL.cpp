/************************************************************************************************/
/** 
 * @file		KsRenderSystemGL.cpp
 * @brief		OpenGL�p�̕`��V�X�e��
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                           */
/*==============================================================================================*/
#include "KsRenderSystemGL.h"
#include "KsDepthStencilStateGL.h"

/*==============================================================================================*/
/*                                     << ��` >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << �錾 >>                                               */
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
 * �R���X�g���N�^
 * @param		hWnd				�E�C���h�E�̃n���h��
 */
/************************************************************************************************/
KsRenderSystemGL::KsRenderSystemGL( void* pParam )
{
	/* ���������� */
	initialize( pParam );
}

/************************************************************************************************/
/*
 * �f�X�g���N�^
 */
/************************************************************************************************/
KsRenderSystemGL::~KsRenderSystemGL()
{
	/* �㏈�� */
	terminate();
}

/************************************************************************************************/
/*
 * ����������
 * @param		hWnd				�E�C���h�E�̃n���h��
 * @retval		ksTRUE				����������
 * @retval		ksFALSE				���������s
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
 * �㏈��
 * @retval		ksTRUE				�㏈������
 * @retval		ksFALSE				�㏈�����s
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
 * �`��o�b�t�@�ƕ\���o�b�t�@�����ւ�
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
 * �`��o�b�t�@�ƕ\���o�b�t�@�����ւ�
 */
/************************************************************************************************/
KsBool KsRenderSystemGL::isMessageLoop()
{
    return !glfwWindowShouldClose( m_pWindow );
}




/*------------------------------------------<< �e�N�X�`���֌W >>------------------------------------------------------*/
/************************************************************************************************/
/*
 * �e�N�X�`���𐶐�����
 * @param		pFileName			�t�@�C����
 * @param		flags				�����t���O
 * @return							�e�N�X�`���̃|�C���^
 */
/************************************************************************************************/
KsTexture* KsRenderSystemGL::createTextureFromFile( const KsChar* pFileName, KsUInt32 flags )
{
    return NULL;
}

/************************************************************************************************/
/*
 * �e�N�X�`���𐶐�����
 * @param		pData				�C���[�W�f�[�^�̃|�C���^
 * @param		width				�e�N�X�`���̕�
 * @param		height				�e�N�X�`���̍���
 * @param		format				�e�N�X�`���t�H�[�}�b�g
 * @param		flags				�����t���O
 * @return							�e�N�X�`���̃|�C���^
 */
/************************************************************************************************/
KsTexture* KsRenderSystemGL::createTexture( const KS_SUBRESOURCE_DATA* pData, KsUInt32 width, KsUInt32 height, KsUInt32 format, KsUInt32 flags, KsUInt32 usage )
{
	return NULL;
}


//! �����_�����O�^�[�Q�b�g���쐬����
/*!
�X���b�v�`�F�C���̓o�b�N�o�b�t�@�������Ă��܂����A�����_�����O�^�[�Q�b�g�͎����Ă��܂���B
�o�b�N�o�b�t�@�������_�����O�^�[�Q�b�g�Ƃ��Ďg�p����ꍇ�A�ʓr�^�[�Q�b�g���쐬����K�v������܂��B
���̊֐��ł͍쐬�ς݂̃X���b�v�`�F�C������o�b�N�o�b�t�@���擾���A����𗘗p���ă^�[�Q�b�g���쐬���Ă��܂��B
*/
KsRenderTarget* KsRenderSystemGL::createRenderTargetView()
{
	return NULL;
}


//! �����_�����O�^�[�Q�b�g���쐬����
/*!
�X���b�v�`�F�C���̓o�b�N�o�b�t�@�������Ă��܂����A�����_�����O�^�[�Q�b�g�͎����Ă��܂���B
�o�b�N�o�b�t�@�������_�����O�^�[�Q�b�g�Ƃ��Ďg�p����ꍇ�A�ʓr�^�[�Q�b�g���쐬����K�v������܂��B
���̊֐��ł͍쐬�ς݂̃X���b�v�`�F�C������o�b�N�o�b�t�@���擾���A����𗘗p���ă^�[�Q�b�g���쐬���Ă��܂��B
*/
KsRenderTarget* KsRenderSystemGL::createRenderTextureView( KsUInt32 width, KsUInt32 height, KsUInt32 format )
{
		return NULL;
}

KsRenderTarget* KsRenderSystemGL::createDepthStencilView( KsUInt32 width, KsUInt32 height, KsUInt32 format, KsUInt32 viewFormat, KsUInt32 resFormat )
{
    return NULL;
}

//! �[�x�o�b�t�@���쐬����
/*!
�[�x�o�b�t�@�̓X���b�v�`�F�C���ɂ͊܂܂�Ă��Ȃ����߁A�o�b�t�@�ƂȂ�e�N�X�`������쐬���܂��B
�e�N�X�`���쐬���ɐ[�x�o�b�t�@�Ƃ��Ďg�p����|��ʒm����K�v������܂��B
�܂��A�����_�����O�^�[�Q�b�g�Ɠ��l�Ƀo�b�t�@�ƕʂɃ^�[�Q�b�g���쐬����K�v������܂��B
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

