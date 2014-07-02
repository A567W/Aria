/************************************************************************************************/
/** 
 * @file		KsColor.h
 * @brief		カラー
 * @author		A567W
 * @date		2008/02/06
 * @since		2008/02/06
 * @version		1.0.0
 */
/************************************************************************************************/
#ifndef __KSCOLOR_H__
#define __KSCOLOR_H__

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

class KsColorReal;

/************************************************************************************************/
/**
 * @class		KsColor
 * @brief		カラークラス
 * @date		2008/02/06
 * @since		2008/02/06
 * @version		1.0.0
 */
/************************************************************************************************/
class ksENGINE_API KsColor
{
	public:
		union
		{
			struct
			{
				KsByte					m_red;			/**< レッド		*/
				KsByte					m_green;		/**< グリーン		*/
				KsByte					m_blue;			/**< ブルー		*/
				KsByte					m_alpha;		/**< アルファ		*/
			};
			KsByte						m_data[ 4 ];	/**< データ		*/
			KsUInt32					m_RGBA;			/**< 値*			*/			
		};

		/**
		 * コンストラクタ
		 */
										KsColor() : m_red( 0 ), m_green( 0 ), m_blue( 0 ), m_alpha( 0 ) {}

		/**
		 * カラーをセットする
		 * @param	fArray				データ
		 */
										KsColor( const KsByte* fArray ) : m_red( fArray[ 0 ] ), m_green( fArray[ 1 ] ), m_blue( fArray[ 2 ] ), m_alpha( fArray[ 3 ] ) {}

		/**
		 * カラーをセットする
		 * @param	red					レッド
		 * @param	blue				ブルー
		 * @param	green				グリーン
		 * @param	alpha				アルファ
		 */
										KsColor( KsByte red, KsByte green, KsByte blue, KsByte alpha ) : m_red( red ), m_green( green ), m_blue( blue ), m_alpha( alpha ) {}

		/**
		 * カラーをセットする
		 * @param	pColor				カラー
		 */
										KsColor( const KsColor* pColor ) : m_red( pColor->m_red ), m_green( pColor->m_green ), m_blue( pColor->m_blue ), m_alpha( pColor->m_alpha ) {}

		/**
		 * カラーをセットする
		 * @param	refColor			カラー
		 */
										KsColor( const KsColor& refColor ) : m_red( refColor.m_red ), m_green( refColor.m_green ), m_blue( refColor.m_blue ), m_alpha( refColor.m_alpha ) {}

		/**
		 * レッドを取得
		 * @return						レッド
		 */
		KsByte							getRed() const { return m_red; }

		/**
		 * グリーンを取得
		 * @return						グリーン
		 */
		KsByte							getGreen() const { return m_green; }

		/**
		 * ブルーを取得
		 * @return						ブルー
		 */
		KsByte							getBlue() const { return m_blue; }

		/**
		 * アルファを取得
		 * @return						アルファ
		 */
		KsByte							getAlpha() const { return m_alpha; }

		/**
		 * データを取得
		 * @return						データ
		 */
		const KsByte*					getData() { return &m_data[ 0 ]; }
		
		/**
		 * レッドをセットする
		 * @param	red					レッド
		 */
		void							setRed( KsByte red ) { m_red = red; }

		/**
		 * グリーンをセットする
		 * @param	green				グリーン
		 */
		void							setGreen( KsByte green ) { m_green = green; }

		/**
		 * グリーンをセットする
		 * @param	blue				ブルー
		 */
		void							setBlue( KsByte blue ) { m_blue = blue; }

		/**
		 * アルファをセットする
		 * @param	alpha				アルファ
		 */
		void							setAlpha( KsByte alpha ) { m_alpha = alpha; }
		
		/**
		 * カラーをセットする
		 * @param	red					レッド
		 * @param	blue				ブルー
		 * @param	green				グリーン
		 * @param	alpha				アルファ
		 */
		void							set( KsByte red, KsByte green, KsByte blue, KsByte alpha ) { m_red = red; m_green = green; m_blue = blue; m_alpha = alpha; }

		/**
		 * カラーをセットする
		 * @param	fArray				データ
		 */
		void							set( const KsByte* fArray ) { m_red = fArray[ 0 ]; m_green = fArray[ 1 ]; m_blue = fArray[ 2 ]; m_alpha = fArray[ 3 ]; }

		/**
		 * カラーをセットする
		 * @param	pColor				カラー
		 */
		void							set( const KsColor* pColor )  { m_red = pColor->getRed(); m_green = pColor->getGreen(); m_blue = pColor->getBlue(); m_alpha = pColor->getAlpha(); }

		/**
		 * カラーをセットする
		 * @param	refColor			カラー
		 */
		void							set( const KsColor& refColor )  { m_red = refColor.getRed(); m_green = refColor.getGreen(); m_blue = refColor.getBlue(); m_alpha = refColor.getAlpha(); }
		
		/**
		 * KsRealのポインタに変換してで取得できるようにする
		 */
		KsByte*							operator [] ( KsInt32 index ) { return &m_data[ index ]; }

		/**
		 * KsRealのポインタに変換してで取得できるようにする
		 */
		const KsByte*					operator [] ( KsInt32 index ) const { return &m_data[ index ]; }

		KsBool							operator == ( const KsColor& refColor ) const	{ return m_RGBA == refColor.m_RGBA; }
		KsBool							operator != ( const KsColor& refColor ) const	{ return m_RGBA != refColor.m_RGBA; }
		KsColor&						operator  = ( const KsColor& refColor )			{ m_RGBA = refColor.m_RGBA; return ( *this ); }
		KsColor&						operator  = ( const KsColorReal& refColor );

		static const KsColor			RED;
		static const KsColor			GREEN;
		static const KsColor			BLUE;
		static const KsColor			YELLOW;
		static const KsColor			WHITE;
		static const KsColor			BLACK;
};

ksNS_KS_END

#endif		/* __KSCOLOR_H__ */

