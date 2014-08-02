/************************************************************************************************/
/**
 * @file		KsFileSystem.h
 * @brief		ファイルシステム
 * @author		A567W
 * @date		2004/03/30
 * @version		1.0.0
 */
/************************************************************************************************/
#ifndef __KSFILESYSTEM_H__
#define __KSFILESYSTEM_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                           */
/*==============================================================================================*/
#include "KsFileCommon.h"
#include "KsReadRequest.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/
#define ksFILE_QUEUE_MAX		( 256 )		/**< ファイルキューの最大サイズ		*/
#define ksPACK_LIST_MAX			( 8 )		/**< パックファイルリストの最大数	*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

class KsReadRequest;
class KsFileAsyncReader;
class KsFileThread;

/************************************************************************************************/
/**
 * @class		KsFileSystem
 * @brief		ファイルsシステムオブジェクト
 * @author		A567W
 * @date		2004/03/30
 * @version		1.0.0
 */
/************************************************************************************************/
class ksENGINE_API KsFileSystem : public KsSingleton< KsFileSystem >
{
	public:
		typedef KsQueue< KsReadRequest*, ksFILE_QUEUE_MAX >	KsFileQueue;
		//typedef KsArray<KsPack*>							KsPackArray;

	public:
		/**
		 * シングルトンの参照を取得
		 * @return						シングルトンの参照
		 */
		static KsFileSystem&			getInstance();
		
		/**
		 * シングルトンのポインタを取得
		 * @return						シングルトンのポインタ
		 */
		static KsFileSystem*			getInstancePtr();

	public:
		/**
		 * コンストラクタ
		 */
										KsFileSystem( ksTHREAD_PRIORITY_TYPE priority=ksTHREAD_PRIORITY_NORMAL, KsUInt32 prosessor=0 );
		
		/**
		 * デストラクタ
		 */
		virtual							~KsFileSystem();

		/**
		 * ロックする
		 */
		void							lock() { m_mutex.lock(); }

		/**
		 * アンロックする
		 */
		void							unlock() { m_mutex.unlock(); }

		/**
		 * 非同期読み込み(読み込みリクエストをスタックにためておく)
		 * 読み込み用リクエストを追加する
		 * @param		pRequest		リクエスト
		 */
		virtual KsBool					pushRequest( KsReadRequest* pRequest );

		/**
		 * 非同期ファイルオープン
		 * @param		pRequest		リクエスト
		 * @return						ファイルハンドル
		 */
		virtual KsHandle				openAsync( KsReadRequest* pRequest );

		/**
		 * 非同期ファイルオープン
		 * @param		pRequest		リクエスト
		 * @return						ファイルハンドル
		 */
		virtual KsHandle				readAsync( KsReadRequest* pRequest );

		/**
		 * 読み取り中処理
		 * @param		pRequest		リクエスト
		 * @retval		ksTRUE			成功
		 * @retval		ksFALSE			失敗
		 */
		virtual KsBool					reading( KsReadRequest* pRequest );

		/**
		 * 非同期ファイルクローズ
		 * @param		pRequest		リクエスト
		 * @retval		ksTRUE			成功
		 * @retval		ksFALSE			失敗
		 */
		virtual KsBool					closeAsync( KsReadRequest* pRequest );

		/**
		 * メインから呼ぶコールバック処理
		 */
		virtual void					callback();

		/**
		 * 非同期ファイルオープン
		 * @param		fileName		ファイル名
		 * @param		callback		メイン側の読み込み終了コールバック
		 * @param		pUserData		ユーザーデータ
		 * @param		callbackTH		スレッド側の読み込み終了時に呼ばれる
		 * @param		pUserDataTH		スレッド側のユーザーデータ
		 * @return						ファイルハンドル
		 */
		virtual KsHandle				openAsync( const KsString& fileName, KsFileReadEndCB callback=0, void* pUserData=0, KsFileReadEndCB callbackTH=0, void* pUserDataTH=0 );

		/**
		 * 非同期ファイルオープン
		 * @param		fileName		ファイル名
		 * @param		pBuffer			バッファ
		 * @param		size			バッファサイズ
		 * @param		callback		メイン側の読み込み終了コールバック
		 * @param		pUserData		ユーザーデータ
		 * @param		callbackTH		スレッド側の読み込み終了時に呼ばれる
		 * @param		pUserDataTH		スレッド側のユーザーデータ
		 * @return						ファイルハンドル
		 */
		virtual KsHandle				openAsync( const KsString& fileName, KsByte* pBuffer, KsInt32 size, KsFileReadEndCB callback=0, void* pUserData=0, KsFileReadEndCB callbackTH=0, void* pUserDataTH=0 );

		/**
		 * 非同期読み込み処理(キューにたまっているリクエストを順番に処理していく)
		 * @return						読み込み状況
		 */
		virtual KsInt32					polling();

		/**
		 * 非同期ファイルクローズ
		 * @param		handle			ハンドル
		 * @retval		ksTRUE			成功
		 * @retval		ksFALSE			失敗
		 */
		virtual KsBool					closeAsync( KsHandle handle );

		/**
		 * 読み込みリクエストをセットする
		 * @param		pRequest		リクエストデータ
		 * @retval		ksTRUE			成功
		 * @retval		ksFALSE			失敗
		 */
		virtual KsBool					setRequest( KsReadRequest* pRequest );

		/**
		 * 非同期読み込み(読み込みリクエストをキューにためておく)
		 * @param		読み込みようキューにたまっているリクエストをクリアーする
		 */
		virtual void					cancelRequest(){ m_bCancel = ksTRUE; }

#if 0

		/**
		 * 同期読み込み(読み込みが終了するまで待つ)
		 * @param		pFileName		ファイル名
		 * @param		ppBuffer		データ受け取り用バッファのポインタ
		 * @param		pSize			バッファのサイズを受け取りようポインタ
		 * @return						読み込んだサイズ
		 */
		virtual KsUInt32				createRead( const KsChar* pFileName, KsUInt8** ppBuffer, KsUInt32* pSize );

		/**
		 * 同期読み込み(読み込みが終了するまで待つ)
		 * @param		pFileName		ファイル名
		 * @param		pBuffer			読み取り用バッファ
		 * @param		size			バッファのサイズ(バイト)
		 * @return						読み込んだサイズ
		 * @note		読み取り用バッファのサイズが６４の倍数じゃないとダメ
		 */
		virtual KsUInt32				read( const KsChar* pFileName, KsUInt8* pBuffer, KsUInt32 size );
		
		/**
		 * 非同期読み込み(読み込みリクエストをキューにためておく)
		 * @param		読み込みようキューにたまっているリクエストをクリアーする
		 */
		virtual void					clearRequest();
		
		/**
		 * 読み込みリクエストを生成する
		 * @param		pFileName		読み込みたいファイル名
		 * @param		flags			生成フラグ
		 * @return		読み込みリクエストのポインタ
		 * @note		固定バッファをしようしたい場合は、flags = 0にして生成してからsetBuffer()でセットしてください。
		 *				flags = 0でsetBuffer()しなかったときはpushRequestしとときに必要なバッファ分だけ確保されます。
		 *				pushRequest()で確保されたバッファはdestroyRequest()をすると開放されます。
		 *				flags = 1で生成したときは、createRequest()のときに必要なバッファが確保されます。
		 *				これで確保されたバッファは、destroyRequest()でも開放されないので各自開放する必要があります。
		 */
		virtual KsReadRequest*			createRequest( KsChar* pFileName, KsUInt32 flags=0 );

		/**
		 * 読み込みリクエストを破棄する
		 * @param		pReq			破棄したい読み込みリクエストのポインタ
		 */
		virtual void					destroyRequest( KsReadRequest* pRequest );
		
		/**
		 * 指定ファイルの読み込み状況をチェックする
		 * @retval						読み込み状況
		 */
		virtual ksREADING_STATE		checkReadState( const KsChar* pFileName );
		
		/**
		 * ファイルの存在をチェックす
		 * @param		pFileName		ファイル名
		 * @retval		ksTRUE			存在している
		 * @retval		ksFALSE			存在していない
		 */
		virtual KsBool					isExist( KsChar* pFileNamee );

		//virtual void					packEntry( KsChar* pPackName );
#endif

		static KsUInt32 __stdcall	KsFileSystem::KsWorkerThreadFunc( PVOID pv );
	protected:
		KsReadRequest*					m_pCurrentRequest;		/**< 現在のリクエスト					*/
		KsFileQueue						m_requestQueue;			/**< 読み込みリクエストのキュー			*/
		//KsPack						m_packList[ ksPACK_LIST_MAX ];	/**< パックファイルから読むとき			*/
		//KsArray<KsPack*>				m_vpPackes;
		KsUInt32						m_packIndex;			/**< 使用パックインデックス				*/
		KsBool							m_bCancel;				/**< キャンセル					*/
		KsMutex							m_mutex;
		KsFileThread*					m_pFileThread;			/**< ファイルスレッド		*/
};

ksNS_KS_END


#endif /* __KSFILESYSTEM_H__ */

