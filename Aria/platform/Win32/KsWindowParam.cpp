/*************************************************************************************************/
/** 
 * @file	KsWindowParam.cpp
 * @brief	ウインドウパラメータ
 * @author	A567W
 * @date	2003/03/22
 * @since	----/--/--
 * @version	1.0.0
 */
/*************************************************************************************************/

/*===============================================================================================*/
/*                                 << インクルード >>                                             */
/*===============================================================================================*/
#include "KsWindowParam.h"

/*===============================================================================================*/
/*                                     << 定義 >>                                                */
/*===============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/*
 * コンストラクタ
 */
/************************************************************************************************/
KsWindowParam::KsWindowParam()
	: m_caption( ksT("KsSystem") )
	, m_className( ksT("KsDefault") )
	, m_posX( 0 )
	, m_posY( 0 )
	, m_sizeX( ksWINDOW_DEFAULT_SIZE_X )
	, m_sizeY( ksWINDOW_DEFAULT_SIZE_Y )
	, m_style( ksWINDOW_DEFAULT_STYLE )
	, m_styleEx( 0 )
{
}

/************************************************************************************************/
/*
 * 引数付きコンストラクタ
 * @param		caption			キャプション
 * @param		className		登録するクラスネーム
 * @param		sizeX			ウインドウの幅
 * @param		sizeY			ウインドウの高さ
 * @param		style			ウインドウのスタイル
 */
/************************************************************************************************/
KsWindowParam::KsWindowParam( const KsString& caption, const KsString& className, KsInt32 posX, KsInt32 posY, KsInt32 sizeX, KsInt32 sizeY, KsUInt32 style, KsUInt32 styeleEx )
	: m_caption( caption )
	, m_className( className )
	, m_posX( posX )
	, m_posY( posY )
	, m_sizeX( sizeX )
	, m_sizeY( sizeY )
	, m_style( style )
	, m_styleEx( styeleEx )
{
}

/************************************************************************************************/
/*
 * デストラクタ
 */
/************************************************************************************************/
KsWindowParam::~KsWindowParam()
{
}

/************************************************************************************************/
/*
 * パラメータをセットする
 * @param		caption			キャプション
 * @param		className		登録するクラスネーム
 * @param		sizeX			ウインドウの幅
 * @param		sizeY			ウインドウの高さ
 * @param		style			ウインドウのスタイル
 */
/************************************************************************************************/
void KsWindowParam::setParam( const KsString& caption, const KsString& className, KsInt32 posX, KsInt32 posY, KsInt32 sizeX, KsInt32 sizeY, KsUInt32 style, KsUInt32 styleEx  )
{
	m_caption   = caption;
	m_className = className;
	m_posX      = posX;
	m_posY      = posY;
	m_sizeX     = sizeX;
	m_sizeY     = sizeY;
	m_style     = style;
	m_styleEx   = styleEx;
}


ksNS_KS_END

