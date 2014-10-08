/************************************************************************************************/
/** 
 * @file		KsShaderProgram.h
 * @brief		�V�F�[�_�[�I�u�W�F�N�g
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0.0
 */
/************************************************************************************************/
#ifndef __KSSHADERPROGRAM_H__
#define __KSSHADERPROGRAM_H__

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                           */
/*==============================================================================================*/
#include "KsGraphicsCommon.h"
#include "KsShaderType.h"

/*==============================================================================================*/
/*                                     << ��` >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << �錾 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class		KsShaderProgram
 * @brief		�V�F�[�_�[
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
		 * �R���X�g���N�^
		 */
									KsShaderProgram();

		/**
		 * �R���X�g���N�^
		 */
									KsShaderProgram( ksSHADER_TYPE type );

		/**
		 * �f�X�g���N�^
		 */
		virtual						~KsShaderProgram();

		/**
		 * �f�[�^����V�F�[�_�[�𐶐�����
		 * @param	pData			�f�[�^
		 * @param	dataSize		�f�[�^�T�C�Y
		 * @retval	ksTRUE			��������
		 * @retval	ksFALSE			�������s
		 */
		virtual KsBool				createFromMemory( const void* pData, KsUInt32 dataSize ) = 0;

		/**
		 * �V�F�[�_�[ID���擾����
		 * @return					�V�F�[�_�[ID
		 */
		KsUInt32					getID() const { return m_id; }

		/**
		 * �V�F�[�_�[�����擾����
		 * @return					�V�F�[�_�[��
		 */
		const KsString&				getName() { return m_name; }

		/**
		 * �V�F�[�_�[�^�C�v���擾����
		 * @return					�V�F�[�_�[�^�C�v
		 */
		ksSHADER_TYPE				getType() const { return m_type; }

		/**
		 * �V�F�[�_�[�v���O�������擾����
		 * @return					�V�F�[�_�[�v���O����
		 */
		virtual KsUInt32			getProgram() { return 0; }

	protected:
		KsUInt32					m_id;				/**< �V�F�[�_�[ID		*/
		KsString					m_name;				/**< �V�F�[�_�[��		*/
		ksSHADER_TYPE				m_type;				/**< �V�F�[�_�[�^�C�v	*/
};

ksNS_KS_END

#endif		/* __KSSHADERPROGRAM_H__ */

