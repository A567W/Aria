/************************************************************************************************/
/** 
 * @file		KsShaderHLSL.h
 * @brief		シェーダーマネージャー
 * @author		Tsukasa Kato
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0
 */
/************************************************************************************************/
#ifndef __KSSHADERHLSL_H__
#define __KSSHADERHLSL_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                           */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
class KsRenderSystemDX11;

/************************************************************************************************/
/**
 * @class		KsShaderHLSL
 * @brief		シェーダー
 * @author		Tsukasa Kato
 * @date		----/--/--
 * @since		----/--/--
 * @note		
 */
/************************************************************************************************/
class ksDEVDX11_API KsShaderHLSL : public KsShader
{
		friend class KsShaderManagerHLSL;

	public:
		/**
		 * コンストラクタ
		 */
									KsShaderHLSL( KsRenderSystemDX11* pRenderSystem );

		/**
		 * デストラクタ
		 */
		virtual						~KsShaderHLSL();

		/**
		 * シェーダ開始
		 */
		virtual void				begine();

		/**
		 * シェーダ終了
		 */
		virtual void				end();

		/**
		 * 指定パス開始
		 */
		virtual void				beginePass( KsUInt32 pass );

		/**
		 * パス終了
		 */
		virtual void				endPass();

		/**
		 * テクニックをセットする
		 * @param	index			テクニックインデックス
		 */
		virtual void				setTechnique( KsUInt32 index );

		/**
		 * テクニックをセットする
		 * @param	hTechnique		テクニックハンドル
		 */
		virtual void				setTechnique( KsHandle hTechnique );

		/**
		  * テクニックをセットする
		 * @param	pTechniqueName	テクニック名
		 */
		virtual void				setTechnique( const KsChar* pTechniqueName );

		/**
		 * テクニックのハンドル取得する
		 * @param	pTechniqueName	テクニック名
		 * @return					テクニックのハンドル
		 */
		virtual KsHandle			getTechnique( const KsChar* pTechniqueName );

		virtual void				setVertexShaderConstantB( KsUInt32 startRegister, const KsBool*  pConstantData, KsUInt32 count );
		virtual void				setVertexShaderConstantF( KsUInt32 startRegister, const KsReal*  pConstantData, KsUInt32 count );
		virtual void				setVertexShaderConstantI( KsUInt32 startRegister, const KsInt32* pConstantData, KsUInt32 count );

		virtual void				setPixelShaderConstantB( KsUInt32 startRegister, const KsBool*  pConstantData, KsUInt32 count );
		virtual void				setPixelShaderConstantF( KsUInt32 startRegister, const KsReal*  pConstantData, KsUInt32 count );
		virtual void				setPixelShaderConstantI( KsUInt32 startRegister, const KsInt32* pConstantData, KsUInt32 count );

#if 0
		KsHandle					getParameterByName( const KsChar* pName ) = 0;

		void						setVector( KsHandle handle, const KsVector4d* pValue ) = 0;
		void						setVectorArray( KsHandle handle, const KsVector4d* pValueArray, KsUInt32 count ) = 0;

		void						setInt( KsHandle handle, KsInt32 value ) = 0;
		void						setIntArray( KsHandle handle, const KsInt32* pValueArray, KsUInt32 count ) = 0;

		void						setBool( KsHandle handle, KsBool value ) = 0;
		void						setBoolArray( KsHandle handle, const KsBool* pValueArray, KsUInt32 count ) = 0;

		void						setFloat( KsHandle handle, KsReal value ) = 0;
		void						setFloatArray( KsHandle handle, const KsReal* pValueArray, KsUInt32 count ) = 0;

		void						setMatrix( KsHandle handle, const KsMatrix4x4* pValue ) = 0;
		void						setMatrixArray( KsHandle handle, const KsVector4d* pValueArray, KsUInt32 count ) = 0;

		void						setMatrixTranspose( KsHandle handle, const KsMatrix4x4* pValue ) = 0;
		void						setMatrixTransposeArray( KsHandle handle, const KsVector4d* pValueArray, KsUInt32 count ) = 0;
#endif

	private:
		void						initialize( const KsChar* pName, LPD3DXEFFECT pEffect );

	private:
		KsRenderSystemDX11*			m_pRenderSystem;		/**< 描画システム		*/
		LPD3DXEFFECT				m_pEffect;				/**< エフェクト			*/
		D3DXHANDLE*					m_hTechniques;			/**< テクニックハンドル	*/
};


#endif		/* __KSSHADERHLSL_H__ */




