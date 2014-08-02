/*************************************************************************************************/
/** 
 * @file	KsWindow.h
 * @brief	ウインドウ
 * @author	A567W
 * @date	2003/03/22
 * @since	----/--/--
 * @version	1.0.0
 */
/*************************************************************************************************/
#ifndef __KSWINDOWS_H__
#define __KSWINDOWS_H__

/*===============================================================================================*/
/*                                 << インクルード >>                                             */
/*===============================================================================================*/
#include "KsWindowsCommon.h"
#include "KsWindowParam.h"
#include "KsAppInstance.h"

/*===============================================================================================*/
/*                                     << 定義 >>                                                */
/*===============================================================================================*/
ksNS_KS_BEGIN

/*************************************************************************************************/
/**
 * ウインドウクラス<BR>
 * @author  A567W
 * @since   2003/03/22
 * @version ----/--/--
 */
/*************************************************************************************************/
class ksENGINE_API KsWindow
{
	protected:
		KsWindowParam					m_windowParam;		/**< ウインドウの生成パラメータ		*/
		WNDPROC							m_pWndProc;			/**< ウインドプロシー				*/
		HWND							m_hWnd;				/**< ウインドウハンドル				*/
		HMENU							m_hMenu;			/**< メニューのハンドル				*/
		KsBool							m_bMinimized;		/**< ウインドウの最小化のフラグ		*/
		KsBool							m_bFullScreen;		/**< フルスクリーンかどうかのフラグ	*/
		KsBool							m_bCenter;			/**< */
		KsUInt32						m_flags;			/**< ウインドウの状態フラグ			*/
	
		//KsHookList					m_hookList;

	public:
		/**
		 * コンストラクタ
		 */
										KsWindow() {}

		/**
		 * コンストラクタ(ウインドウ生成)
		 * @param		param			ウインドウ生成のためのパラメータ
		 * @param		hParent			親ウインドウのハンドル
		 * @retval		ksTRUE			成功
		 * @retval		ksFALSE			失敗
		 */
										KsWindow( const KsWindowParam& param, HWND hParent = NULL, void* pUserData = NULL );

		/**
		 * デストラクタ
		 */
		virtual							~KsWindow() {}

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
		 * ウインドウのハンドルを取得する
		 * @return						ウインドウのハンドル
		 */
		HWND							getHWnd()				const	{ return m_hWnd; }

		/**
		 * メニューのハンドルを取得する
		 * @return						メニューのハンドル
		 */
		HMENU							getHMenu()				const	{ return m_hMenu; }

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
		 * メニューのハンドルをセットする
		 * @param		hMenu			メニューのハンドル
		 */
		void							setHMenu( HMENU hMenu )	{ m_hMenu = hMenu; }

		/**
		 * ウインドウ生成
		 * @param		param			ウインドウ生成のためのパラメータ
		 * @param		hParent			親ウインドウのハンドル
		 * @retval		ksTRUE			成功
		 * @retval		ksFALSE			失敗
		 */
		KsBool							create( const KsWindowParam& param, HWND hParent = NULL, void* pUserData = NULL );

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

	protected:
		/**
		 * ウインドウプロシージャ
		 * @param		hWnd			ウインドウのハンドル
		 * @param		uMsg			ウインドウのメッセージ
		 * @param		wParam			パラメータ
		 * @param		lParam			パラメータ
		 * @return						コールバック
		 */
		static LRESULT CALLBACK			wndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );
};

ksNS_KS_END

#endif	/* __KSWINDOW_H__ */

