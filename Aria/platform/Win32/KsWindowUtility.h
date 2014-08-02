/*************************************************************************************************/
/** 
 * @file	KsWindowUtility.h
 * @brief	Windows関係ユーティリティ
 * @author	A567W
 * @date	2003/03/22
 * @since	----/--/--
 * @version	1.0.0
 */
/*************************************************************************************************/
#ifndef __KSWINDOWUTILITY_H__
#define __KSWINDOWUTILITY_H__

/*===============================================================================================*/
/*                                 << インクルード >>                                            */
/*===============================================================================================*/
#include "KsWindowsCommon.h"

/*===============================================================================================*/
/*                                     << 定義 >>                                                */
/*===============================================================================================*/
ksNS_KS_BEGIN

/*************************************************************************************************/
/**
 * ウインドウユーティリティークラス<BR>
 * @author  A567W
 * @since   2003/03/22
 * @version ----/--/--
 */
/*************************************************************************************************/
class ksENGINE_API KsWindowUtility
{
	public:
		/**
		 * タスクバーを除いたデスクトップのサイズを取得する
		 * @param		pRect		(OUT)サイズを取得する構造体のポインタ
		 */
		static void			getDeskTopClientRect( RECT* pRect );

		/**
		 * デスクトップのサイズを取得する
		 * @param		pRect		(OUT)サイズを取得する構造体のポインタ
		 */
		static void			getDeskTopWindowRect( RECT* pRect );

		/**
		 * GetNativeSystemInfoラッパー関数
		 * @parm	lpSystemInfo	(OUT)システム情報を取得する構造体のポインタ
		 * @retval	ksTRUE			取得成功
		 * @retval	ksFALSE			取得失敗
		 * @note GetNativeSystemInfoはWindows XP以降でサポートされている。
		 *		 そのためWindows 2000以前ではksFALSEが返る
		 */
		static KsBool		getNativeSystemInfo( LPSYSTEM_INFO lpSystemInfo );

		/**
		 * プロセッサの数を取得する
		 * @return	プロセッサの数
		 */
		static KsUInt32		getNumProcessor();

		/**
		 * 見つけたウインドウをアクティブにする
		 */
		static KsBool		activeFindWindow( const KsChar* pClassName, const KsChar* pWindowName );
};

ksNS_KS_END

#endif /* __KSWINDOWUTILITY_H__ */

