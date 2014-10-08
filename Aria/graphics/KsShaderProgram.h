/************************************************************************************************/
/** 
 * @file		KsShaderProgram.h
 * @brief		シェーダーオブジェクト
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/
#ifndef __KSSHADERPROGRAM_H__
#define __KSSHADERPROGRAM_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                           */
/*==============================================================================================*/
#include "KsGraphicsCommon.h"
#include "KsShaderType.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class		KsShaderProgram
 * @brief		シェーダー
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @note		
 */
/************************************************************************************************/
class ksENGINE_API KsShaderProgram : public KsRefCounter
{
		friend class KsShaderManager;
	public:
		/**
		 * コンストラクタ
		 */
									KsShaderProgram();

		/**
		 * コンストラクタ
		 */
									KsShaderProgram( ksSHADER_TYPE type );

		/**
		 * デストラクタ
		 */
		virtual						~KsShaderProgram();

		/**
		 * データからシェーダーを生成する
		 * @param	pData			データ
		 * @param	dataSize		データサイズ
		 * @retval	ksTRUE			生成成功
		 * @retval	ksFALSE			生成失敗
		 */
		virtual KsBool				createFromMemory( const void* pData, KsUInt32 dataSize ) = 0;

		/**
		 * シェーダーIDを取得する
		 * @return					シェーダーID
		 */
		KsUInt32					getID() const { return m_id; }

		/**
		 * シェーダー名を取得する
		 * @return					シェーダー名
		 */
		const KsString&				getName() { return m_name; }

		/**
		 * シェーダータイプを取得する
		 * @return					シェーダータイプ
		 */
		ksSHADER_TYPE				getType() const { return m_type; }

		/**
		 * シェーダープログラムを取得する
		 * @return					シェーダープログラム
		 */
		virtual KsUInt32			getProgram() { return 0; }

	protected:
		KsUInt32					m_id;				/**< シェーダーID		*/
		KsString					m_name;				/**< シェーダー名		*/
		ksSHADER_TYPE				m_type;				/**< シェーダータイプ	*/
};

ksNS_KS_END

#endif		/* __KSSHADERPROGRAM_H__ */

