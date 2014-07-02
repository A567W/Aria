/************************************************************************************************/
/**
 * @file		KsLzss.h
 * @brief		スライド辞書圧縮(LZSS法)
 * @author		A567W
 * @date		2004/03/30
 * @version		1.0.0
 */
/************************************************************************************************/
#ifndef __KSLZSS_H__
#define __KSLZSS_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsCoreCommon.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/
#define ksBUFFER_SIZE			( 4096 )					/**< バッファサイズ					*/
#define ksTREE_SIZE			( 4096 + 1 )				/**< ツリーサイズ					*/
#define ksTREE_ROOT			( 4096 )					/**< 2分木ツリーのルート			*/
#define ksUNUSED				( 0 )						/**< ツリーの未使用定義				*/
#define ksEND					( 0 )						/**< 終了							*/
#define ksMATCH_LENGTH_MIN		( 2 )						/**< 最短一致長						*/
#define ksMATCH_LENGTH_MAX		( 18 )						/**< 最長一致長						*/
#define ksHASH( x )			( (x) & (ksBUFFER_SIZE-1) )	/**< 指定範囲内						*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class	KsLzss
 * @brief	スライド辞書圧縮(LZSS法)
 * @author	A567W
 * @date	2003/11/30
 * @version	1.0.0
 * @note 圧縮構造は、1byteに圧縮ビット情報(3文字から圧縮される)
 */
/************************************************************************************************/
class ksENGINE_API KsLzss
{
	public:
		/**
		 * 圧縮用ツリー構造体
		 */
		typedef struct _KsTree
		{
			KsInt32						parent;			/**< 親ノード	*/
			KsInt32						smallChild;		/**< 兄弟ノード	*/
			KsInt32						largeChild;		/**< 兄弟ノード	*/
		}KsTree;
	
	public:
	
		/**
		 * コンストラクタ
		 */
											KsLzss(){}
	
		/**
		 * デストラクタ
		 */
		virtual							~KsLzss(){}
		
		/**
		 * 圧縮する(バッファ→バッファ)
		 * @param		pInputBuffer		入力バッファ
		 * @param		pOutputBuffer		出力バッファ
		 * @return							圧縮後のファイルサイズ
		 */
		KsUInt32							encode( KsByte* pInputBuffer, KsByte* pOutputBuffer );

		/**
		 * 圧縮する(バッファ→ファイル)
		 * @param		pInputBuffer		入力バッファ
		 * @param		pOutputFile			出力ファイル
		 * @return							圧縮後のファイルサイズ
		 */
		KsUInt32							encode( KsByte* pInputBuffer, FILE* pOutputFile );

		/**
		 * 圧縮する(ファイル→バッファ)
		 * @param		pInputFile			入力ファイル
		 * @param		pOutputBuffer		出力バッファ
		 * @return							圧縮後のファイルサイズ
		 */
		KsUInt32							encode( FILE* pInputFile, KsByte* pOutputBuffer );

		/**
		 * 圧縮する(ファイル→ファイル)
		 * @param		pInputFile			入力ファイル
		 * @param		pOutputFile			出力ファイル
		 * @return							圧縮後のファイルサイズ
		 */
		KsUInt32							encode( FILE* pInputFile, FILE* pOutputFile );

		/**
		 * 解凍する(バッファ→バッファ)
		 * @param		pInputBuffer		入力バッファ
		 * @param		pOutputBuffer		出力バッファ
		 */
		void								decode( KsByte* pInputBuffer, KsByte* pOutputBuffer );

		/**
		 * 解凍する(バッファ→ファイル)
		 * @param		pInputBuffer		入力バッファ
		 * @param		pOutputFile			出力ファイル
		 */
		void								decode( KsByte* pInputBuffer, FILE* pOutputFile );

		/**
		 * 解凍する(ファイル→バッファ)
		 * @param		pInputFile			入力ファイル
		 * @param		pOutputBuffer		出力バッファ
		 */
		void								decode( FILE* pInputFile, KsByte* pOutputBuffer );

		/**
		 * 解凍する(ファイル→ファイル)
		 * @param		pInputFile			入力ファイル
		 * @param		pOutputFile			出力ファイル
		 */
		void								decode( FILE* pInputFile, FILE* pOutputFile );

	private:
		/**
		 * ツリーを初期化する
		 * @param		node				ノード
		 */
		void								initTree( KsInt32 node=0 );
		
		/**
		 *
		 * @param		oldNode				古いノード
		 * @param		newNode				新しいノード
		 */
		void								contractNode( KsInt32 oldNode, KsInt32 newNode );
		
		/**
		 * ノードを置換する
		 * @param		oldNode				古いノード
		 * @param		newNode				新しいノード
		 */
		void								replaceNode( KsInt32 oldNode, KsInt32 newNode );
		
		/**
		 * ノードを置換する
		 * @param		oldNode				古いノード
		 * @param		newNode				新しいノード
		 */
		KsInt32							addNode( KsInt32 newNode, KsInt32* matchPos );
		
		/**
		 * ノードを置換する
		 * @param		oldNode				古いノード
		 */
		void								delNode( KsInt32 p );
		
		/**
		 * 指定ノードの次のノードを取得する
		 * @param		node				指定ノード
		 * @return							次のノード
		 */
		KsInt32							nextNode( KsInt32 node );
	
	private:
		KsByte								m_buffer[ ksBUFFER_SIZE ];		/**< 環状バッファ	*/
		KsTree								m_tree[ ksTREE_SIZE ];			/**< ツリー			*/
};

ksNS_KS_END

#endif		/* __KSLZSS_H__ */
