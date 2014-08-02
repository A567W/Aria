/************************************************************************************************/
/** 
 * @file		KsShaderManagerDX11.h
 * @brief		シェーダーマネージャー
 * @author		Tsukasa Kato
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/
#ifndef __KSSHADERMANAGERDX11_H__
#define __KSSHADERMANAGERDX11_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                           */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
class KsRenderSystemDX;

/************************************************************************************************/
/**
 * @class		KsShaderManager
 * @brief		シェーダーマネージャー
 * @author		Tsukasa Kato
 * @date		----/--/--
 * @since		----/--/--
 * @note		本当は、ハッシュテーブルなどを使用したほうがいいがあまりテクスチャマテリアルは、
 *				あまり、使わないはずなので線形で探索する。
 */
/************************************************************************************************/
class ksDEVDX11_API KsShaderManagerDX11 : public KsShaderManager
{
	public:
		/**
		 * コンストラクタ
		 * @param	pRenderSystem		描画システム
		 */
										KsShaderManagerDX11( KsRenderSystemDX11* pRenderSystem );

		/**
		 * デストラクタ
		 */
		virtual							~KsShaderManagerDX11();

		/**
		 * ファイルからシェーダーを生成
		 * @param	pFileName			ファイル名
		 * @param	pEntryPoint			エントリーポイント
		 * @param	shaderModel			シェーダーモデル
		 * @param	shaderType			シェーダータイプ
		 * @return						シェーダープログラムのポインタ
		 */
		virtual KsShaderProgram*		createFromFile( const KsChar* pFileName, const KsChar* pEntryPoint, ksSHADER_MODEL_TYPE shaderModel, ksSHADER_TYPE shaderType );

		/**
		 * ファイルからシェーダーを生成
		 * @param	pFileName			ファイル名
		 * @param	pEntryPoint			エントリーポイント
		 * @param	shaderModel			シェーダーモデル
		 * @param	shaderType			シェーダータイプ
		 * @return						シェーダープログラムのポインタ
		 */
		virtual KsShaderProgram*		createFromMemory( const KsChar* pFileName, const KsChar* pEntryPoint, ksSHADER_MODEL_TYPE shaderModel, ksSHADER_TYPE shaderType );

		/**
		 * ファイルからシェーダーを生成
		 * @param	pFileName			ファイル名
		 * @param	pEntryPoint			エントリーポイント
		 * @param	shaderModel			シェーダーモデル
		 * @param	shaderType			シェーダータイプ
		 * @return						シェーダープログラムのポインタ
		 */
		virtual KsShaderProgram*		createFromResource( const KsChar* pFileName, const KsChar* pEntryPoint, ksSHADER_MODEL_TYPE shaderModel, ksSHADER_TYPE shaderType );

	private:
		KsRenderSystemDX11*				m_pRenderSystem;						/**< 描画システム	*/
};

#endif		/* __KSSHADERMANAGERDX11_H__ */

