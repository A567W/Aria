/*************************************************************************************************/
/** 
 * @file	KsWindowGL.h
 * @brief	OpenGL ウインドウ
 * @author	A567W
 * @date	2003/03/22
 * @since	----/--/--
 * @version	1.0.0
 */
/*************************************************************************************************/
#ifndef __KSWINDOWSGL_H__
#define __KSWINDOWSGL_H__

/*===============================================================================================*/
/*                                 << インクルード >>                                             */
/*===============================================================================================*/
#include "KsCommonGL.h"

/*===============================================================================================*/
/*                                     << 定義 >>                                                */
/*===============================================================================================*/
ksNS_KS_BEGIN

/*************************************************************************************************/
/**
 * ウインドウクラス
 * @author  A567W
 * @since   2003/03/22
 * @version ----/--/--
 */
/*************************************************************************************************/
class ksENGINE_API KsWindowGL
{
	protected:
        GLFWwindow*                     m_pWindow;
        GLFWmonitor*                    m_pMonitor;

	public:
		/**
		 * コンストラクタ(ウインドウ生成)
		 * @param		param			ウインドウ生成のためのパラメータ
		 * @param		hParent			親ウインドウのハンドル
		 * @retval		ksTRUE			成功
		 * @retval		ksFALSE			失敗
		 */
										KsWindowGL( const KsWindowParam& param );

		/**
		 * デストラクタ
		 */
		virtual							~KsWindowGL() {}

		/**
		 * ウインドウのパラメータを取得する
		 * @return						ウインドウパラメータ
		 */
		const KsWindowParam&			getWindowParam()				{ return m_windowParam; }

		/**
		 * ウインドウの幅を取得する
		 * @return						ウインドウの幅
		 */
		KsInt32							getWidth()				const	{ return m_windowParam.m_sizeX;	 }

		/**
		 * ウインドウの高さを取得する
		 * @return						ウインドウの高さ
		 */
		KsInt32							getHeight()				const	{ return m_windowParam.m_sizeY;	 }

		/**
		 * ウインドウが最小化されているかをチェックする
		 * @retval		ksTRUE			最小化されている
		 * @retval		ksTRUE			最小化されてない
		 */
		KsBool							isMinmimized()			const	{ return m_bMinimized; }

		/**
		 * フルスクリーン化されているかをチェックする
		 * @retval		ksTRUE			フルスクリーン化されている
		 * @retval		ksTRUE			フルスクリーン化されてない
		 */
		KsBool							isFullScreen()			const	{ return m_bFullScreen; }

		/**
		 * ウインドウ生成
		 * @param		param			ウインドウ生成のためのパラメータ
		 * @param		hParent			親ウインドウのハンドル
		 * @retval		ksTRUE			成功
		 * @retval		ksFALSE			失敗
		 */
		KsBool							create( const KsWindowParam& param );

		/**
		 * メッセージループ
		 * @return		メッセージ要求
		 */
		KsInt32							messageLoop();

		/**
		 * ウインドウ位置をセット
		 * @param		x				ウインドウをセットするX座標
		 * @param		y				ウインドウをセットするY座標
		 */
		void							setPos( KsInt32 x, KsInt32 y );

		/**
		* ウインドウを中央にセット
		*/
		void							setCenter();
};

ksNS_KS_END

#endif	/* __KSWINDOWSGL_H__ */

