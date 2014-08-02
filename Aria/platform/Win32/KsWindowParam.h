/*************************************************************************************************/
/** 
 * @file	KsWindowParam.h
 * @brief	ウインドウパラメータ
 * @author	A567W
 * @date	2003/03/22
 * @since	----/--/--
 * @version	1.0.0
 */
/*************************************************************************************************/
#ifndef __KSWINDOWSPARAM_H__
#define __KSWINDOWSPARAM_H__

/*===============================================================================================*/
/*                                 << インクルード >>                                             */
/*===============================================================================================*/
#include "KsWindowsCommon.h"

/*===============================================================================================*/
/*                                     << 定義 >>                                                */
/*===============================================================================================*/
#define ksWINDOW_DEFAULT_SIZE_X	( 1280 )		/**< ウインドウのデフォルトの幅	*/
#define ksWINDOW_DEFAULT_SIZE_Y	(  720 )		/**< ウインドウのデフォルトの高さ	*/
#define ksWINDOW_DEFAULT_STYLE	( WS_VISIBLE | WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU )

ksNS_KS_BEGIN

/*************************************************************************************************/
/**
 * ウインドウアプリケーションのパラメータクラス<BR>
 * @author  A567W
 * @since   2003/03/22
 * @version ----/--/--
 */
/*************************************************************************************************/
class ksENGINE_API KsWindowParam
{
	public:
		KsString						m_caption;		/**< キャプション				*/
		KsString						m_className;	/**< クラス名					*/
		KsInt32							m_posX;			/**< ウインドウのX座標			*/
		KsInt32							m_posY;			/**< ウインドウのY座標			*/
		KsInt32							m_sizeX;		/**< ウインドウの幅				*/
		KsInt32							m_sizeY;		/**< ウインドウの高さ				*/
		KsUInt32						m_style;		/**< ウインドウのスタイル			*/
		KsUInt32						m_styleEx;		/**< 拡張ウインドウスタイル		*/
		//WNDPROC						m_pCallback;	/**< プロシージャ				*/

	public:
		/**
		 * コンストラクタ
		 */
										KsWindowParam();

		/**
		 * 引数付きコンストラクタ
		 * @param		caption			キャプション
		 * @param		className		登録するクラスネーム
		 * @param		sizeX			ウインドウの幅
		 * @param		sizeY			ウインドウの高さ
		 * @param		style			ウインドウのスタイル
		 */
										KsWindowParam( const KsString& caption, const KsString& className, KsInt32 posX, KsInt32 posY, KsInt32 sizeX, KsInt32 sizeY, KsUInt32 style, KsUInt32 styeleEx=0 );

		/**
		 * デストラクタ
		 */
		virtual							~KsWindowParam();

		/**
		 * パラメータをセットする
		 * @param		caption			キャプション
		 * @param		className		登録するクラスネーム
		 * @param		sizeX			ウインドウの幅
		 * @param		sizeY			ウインドウの高さ
		 * @param		style			ウインドウのスタイル
		 */
		void							setParam( const KsString& caption, const KsString& className, KsInt32 posX, KsInt32 posY, KsInt32 sizeX, KsInt32 sizeY, KsUInt32 style, KsUInt32 styleEx=0 );
};

ksNS_KS_END

#endif	/* __KSWINDOWSPARAM_H__ */

