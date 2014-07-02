/************************************************************************************************/
/**
 * @file		KsLzss.h
 * @brief		�X���C�h�������k(LZSS�@)
 * @author		A567W
 * @date		2004/03/30
 * @version		1.0.0
 */
/************************************************************************************************/
#ifndef __KSLZSS_H__
#define __KSLZSS_H__

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                            */
/*==============================================================================================*/
#include "KsCoreCommon.h"

/*==============================================================================================*/
/*                                     << ��` >>                                               */
/*==============================================================================================*/
#define ksBUFFER_SIZE			( 4096 )					/**< �o�b�t�@�T�C�Y					*/
#define ksTREE_SIZE			( 4096 + 1 )				/**< �c���[�T�C�Y					*/
#define ksTREE_ROOT			( 4096 )					/**< 2���؃c���[�̃��[�g			*/
#define ksUNUSED				( 0 )						/**< �c���[�̖��g�p��`				*/
#define ksEND					( 0 )						/**< �I��							*/
#define ksMATCH_LENGTH_MIN		( 2 )						/**< �ŒZ��v��						*/
#define ksMATCH_LENGTH_MAX		( 18 )						/**< �Œ���v��						*/
#define ksHASH( x )			( (x) & (ksBUFFER_SIZE-1) )	/**< �w��͈͓�						*/

/*==============================================================================================*/
/*                                     << �錾 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class	KsLzss
 * @brief	�X���C�h�������k(LZSS�@)
 * @author	A567W
 * @date	2003/11/30
 * @version	1.0.0
 * @note ���k�\���́A1byte�Ɉ��k�r�b�g���(3�������爳�k�����)
 */
/************************************************************************************************/
class ksENGINE_API KsLzss
{
	public:
		/**
		 * ���k�p�c���[�\����
		 */
		typedef struct _KsTree
		{
			KsInt32						parent;			/**< �e�m�[�h	*/
			KsInt32						smallChild;		/**< �Z��m�[�h	*/
			KsInt32						largeChild;		/**< �Z��m�[�h	*/
		}KsTree;
	
	public:
	
		/**
		 * �R���X�g���N�^
		 */
											KsLzss(){}
	
		/**
		 * �f�X�g���N�^
		 */
		virtual							~KsLzss(){}
		
		/**
		 * ���k����(�o�b�t�@���o�b�t�@)
		 * @param		pInputBuffer		���̓o�b�t�@
		 * @param		pOutputBuffer		�o�̓o�b�t�@
		 * @return							���k��̃t�@�C���T�C�Y
		 */
		KsUInt32							encode( KsByte* pInputBuffer, KsByte* pOutputBuffer );

		/**
		 * ���k����(�o�b�t�@���t�@�C��)
		 * @param		pInputBuffer		���̓o�b�t�@
		 * @param		pOutputFile			�o�̓t�@�C��
		 * @return							���k��̃t�@�C���T�C�Y
		 */
		KsUInt32							encode( KsByte* pInputBuffer, FILE* pOutputFile );

		/**
		 * ���k����(�t�@�C�����o�b�t�@)
		 * @param		pInputFile			���̓t�@�C��
		 * @param		pOutputBuffer		�o�̓o�b�t�@
		 * @return							���k��̃t�@�C���T�C�Y
		 */
		KsUInt32							encode( FILE* pInputFile, KsByte* pOutputBuffer );

		/**
		 * ���k����(�t�@�C�����t�@�C��)
		 * @param		pInputFile			���̓t�@�C��
		 * @param		pOutputFile			�o�̓t�@�C��
		 * @return							���k��̃t�@�C���T�C�Y
		 */
		KsUInt32							encode( FILE* pInputFile, FILE* pOutputFile );

		/**
		 * �𓀂���(�o�b�t�@���o�b�t�@)
		 * @param		pInputBuffer		���̓o�b�t�@
		 * @param		pOutputBuffer		�o�̓o�b�t�@
		 */
		void								decode( KsByte* pInputBuffer, KsByte* pOutputBuffer );

		/**
		 * �𓀂���(�o�b�t�@���t�@�C��)
		 * @param		pInputBuffer		���̓o�b�t�@
		 * @param		pOutputFile			�o�̓t�@�C��
		 */
		void								decode( KsByte* pInputBuffer, FILE* pOutputFile );

		/**
		 * �𓀂���(�t�@�C�����o�b�t�@)
		 * @param		pInputFile			���̓t�@�C��
		 * @param		pOutputBuffer		�o�̓o�b�t�@
		 */
		void								decode( FILE* pInputFile, KsByte* pOutputBuffer );

		/**
		 * �𓀂���(�t�@�C�����t�@�C��)
		 * @param		pInputFile			���̓t�@�C��
		 * @param		pOutputFile			�o�̓t�@�C��
		 */
		void								decode( FILE* pInputFile, FILE* pOutputFile );

	private:
		/**
		 * �c���[������������
		 * @param		node				�m�[�h
		 */
		void								initTree( KsInt32 node=0 );
		
		/**
		 *
		 * @param		oldNode				�Â��m�[�h
		 * @param		newNode				�V�����m�[�h
		 */
		void								contractNode( KsInt32 oldNode, KsInt32 newNode );
		
		/**
		 * �m�[�h��u������
		 * @param		oldNode				�Â��m�[�h
		 * @param		newNode				�V�����m�[�h
		 */
		void								replaceNode( KsInt32 oldNode, KsInt32 newNode );
		
		/**
		 * �m�[�h��u������
		 * @param		oldNode				�Â��m�[�h
		 * @param		newNode				�V�����m�[�h
		 */
		KsInt32							addNode( KsInt32 newNode, KsInt32* matchPos );
		
		/**
		 * �m�[�h��u������
		 * @param		oldNode				�Â��m�[�h
		 */
		void								delNode( KsInt32 p );
		
		/**
		 * �w��m�[�h�̎��̃m�[�h���擾����
		 * @param		node				�w��m�[�h
		 * @return							���̃m�[�h
		 */
		KsInt32							nextNode( KsInt32 node );
	
	private:
		KsByte								m_buffer[ ksBUFFER_SIZE ];		/**< ��o�b�t�@	*/
		KsTree								m_tree[ ksTREE_SIZE ];			/**< �c���[			*/
};

ksNS_KS_END

#endif		/* __KSLZSS_H__ */
