/************************************************************************************************/
/** 
 * @file		KsColorReal.h
 * @brief		カラー
 * @author		A567W
 * @date		2008/02/06
 * @since		2008/02/06
 * @version		1.0.0
 */
/************************************************************************************************/
#ifndef __KSCOLORREAL_H__
#define __KSCOLORREAL_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                           */
/*==============================================================================================*/
#include "KsBase.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

class KsColor;

/************************************************************************************************/
/**
 * @class		KsColorReal
 * @brief		カラークラス
 * @author		A567W
 * @date		2008/02/06
 * @since		2008/02/06
 * @version		1.0.0
 */
/************************************************************************************************/
class ksENGINE_API KsColorReal
{
	public:
		union{
			struct{
				KsReal					m_red;			/**< レッド		*/
				KsReal					m_green;		/**< グリーン	*/
				KsReal					m_blue;			/**< ブルー		*/
				KsReal					m_alpha;		/**< アルファ	*/
			};
			KsReal						m_data[ 4 ];	/**< データ		*/
		};

		/**
		 * コンストラクタ
		 */
										KsColorReal() : m_red( 0.0f ), m_green( 0.0f ), m_blue( 0.0f ), m_alpha( 1.0f ) {}

		/**
		 * カラーをセットする
		 * @param	fArray				データ
		 */
										KsColorReal( const KsReal* fArray ) : m_red( fArray[ 0 ] ), m_green( fArray[ 1 ] ), m_blue( fArray[ 2 ] ), m_alpha( fArray[ 3 ] ) {}

		/**
		 * カラーをセットする
		 * @param	red					レッド
		 * @param	blue				ブルー
		 * @param	green				グリーン
		 * @param	alpha				アルファ
		 */
										KsColorReal( KsReal red, KsReal green, KsReal blue, KsReal alpha ) : m_red( red ), m_green( green ), m_blue( blue ), m_alpha( alpha ) {}

		/**
		 * カラーをセットする
		 * @param	pColor				カラー
		 */
										KsColorReal( const KsColorReal* pColor ) : m_red( pColor->m_red ), m_green( pColor->m_green ), m_blue( pColor->m_blue ), m_alpha( pColor->m_alpha ) {}

		/**
		 * カラーをセットする
		 * @param	refColor			カラー
		 */
										KsColorReal( const KsColorReal& refColor ) : m_red( refColor.m_red ), m_green( refColor.m_green ), m_blue( refColor.m_blue ), m_alpha( refColor.m_alpha ) {}

		/**
		 * レッドを取得
		 * @return						レッド
		 */
		KsReal							getRed() const { return m_red; }

		/**
		 * グリーンを取得
		 * @return						グリーン
		 */
		KsReal							getGreen() const { return m_green; }

		/**
		 * ブルーを取得
		 * @return						ブルー
		 */
		KsReal							getBlue() const { return m_blue; }

		/**
		 * アルファを取得
		 * @return						アルファ
		 */
		KsReal							getAlpha() const { return m_alpha; }

		/**
		 * データを取得
		 * @return						データ
		 */
		KsReal*							getData() { return &m_data[ 0 ]; }
		
		/**
		 * レッドをセットする
		 * @param	red					レッド
		 */
		void							setRed( KsReal red ) { m_red = red; }

		/**
		 * グリーンをセットする
		 * @param	green				グリーン
		 */
		void							setGreen( KsReal green ) { m_green = green; }

		/**
		 * グリーンをセットする
		 * @param	blue				ブルー
		 */
		void							setBlue( KsReal blue ) { m_blue = blue; }

		/**
		 * アルファをセットする
		 * @param	alpha				アルファ
		 */
		void							setAlpha( KsReal alpha ) { m_alpha = alpha; }
		
		/**
		 * カラーをセットする
		 * @param	red					レッド
		 * @param	blue				ブルー
		 * @param	green				グリーン
		 * @param	alpha				アルファ
		 */
		void							set( KsReal red, KsReal green, KsReal blue, KsReal alpha ) { m_red = red; m_green = green; m_blue = blue; m_alpha = alpha; }

		/**
		 * カラーをセットする
		 * @param	fArray				データ
		 */
		void							set( const KsReal* fArray ) { m_red = fArray[ 0 ]; m_green = fArray[ 1 ]; m_blue = fArray[ 2 ]; m_alpha = fArray[ 3 ]; }

		/**
		 * カラーをセットする
		 * @param	pColor				カラー
		 */
		void							set( const KsColorReal* pColor )  { m_red = pColor->getRed(); m_green = pColor->getGreen(); m_blue = pColor->getBlue(); m_alpha = pColor->getAlpha(); }

		/**
		 * カラーをセットする
		 * @param	refColor			カラー
		 */
		void							set( const KsColorReal& refColor )  { m_red = refColor.getRed(); m_green = refColor.getGreen(); m_blue = refColor.getBlue(); m_alpha = refColor.getAlpha(); }
		
		/**
		 * KsRealのポインタに変換してで取得できるようにする
		 */
		KsReal*							operator [] ( KsInt32 index ) { return &m_data[ index ]; }

		/**
		 * KsRealのポインタに変換してで取得できるようにする
		 */
		const KsReal*					operator [] ( KsInt32 index ) const { return &m_data[ index ]; }

		KsBool							operator == ( const KsColorReal& refColor ) const	{ return ( 0 == memcmp( this, &refColor, sizeof(KsColorReal) ) ); }
		KsBool							operator != ( const KsColorReal& refColor ) const	{ return ( 0 != memcmp( this, &refColor, sizeof(KsColorReal) ) ); }
		KsColorReal&					operator  = ( const KsColorReal& refColor )		{ memcpy( &m_data[ 0 ], &refColor, sizeof(KsColorReal) ); return ( *this ); }
		KsColorReal&					operator  = ( const KsColor& refColor );

		static const KsColorReal		RED;
		static const KsColorReal		GREEN;
		static const KsColorReal		BLUE;
		static const KsColorReal		YELLOW;
		static const KsColorReal		WHITE;
		static const KsColorReal		BLACK;
};

ksNS_KS_END

#endif		/* __KSCOLORREAL_H__ */

