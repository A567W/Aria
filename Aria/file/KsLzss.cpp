/************************************************************************************************/
/**
 * @file		KsLzss.cpp
 * @brief		�X���C�h�������k(LZSS�@)
 * @author		A567W
 * @date		2004/03/30
 * @version		1.0.0
 */
/************************************************************************************************/

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                            */
/*==============================================================================================*/
#include "KsLzss.h"
#include "KsBitIO.h"

/*==============================================================================================*/
/*                                     << ��` >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << �錾 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/*
 * ����������
 */
/************************************************************************************************/
void KsLzss::initTree( KsInt32 node )
{
	/* ������ */
	memset( (void*)&m_tree, 0, sizeof( KsTree )*ksTREE_SIZE );

	m_tree[ ksTREE_ROOT ].largeChild = node;
	m_tree[ node ].parent            = ksTREE_ROOT;
	m_tree[ node ].largeChild        = ksUNUSED;
	m_tree[ node ].smallChild        = ksUNUSED;
}

/************************************************************************************************/
/*
 * �Z�k
 */
/************************************************************************************************/
void KsLzss::contractNode( KsInt32 oldNode, KsInt32 newNode )
{
	KsInt32		oldNodeParent = m_tree[ oldNode ].parent;

	/* �V�����m�[�h�̐e���Z�b�g���� */
	m_tree[ newNode ].parent = oldNodeParent;

	/* �Â��m�[�h�͐e�̂ǂ���ɐݒ肳��Ă������𒲂ׂ� */
	if( m_tree[ oldNodeParent ].largeChild == oldNode )
	{
		m_tree[ oldNodeParent ].largeChild = newNode;
	}
	else{
		m_tree[ oldNodeParent ].smallChild = newNode;
	}

	/* �Â��m�[�h�́A���Ԃɂ��� */
	m_tree[ oldNode ].parent = ksUNUSED;
}
/************************************************************************************************/
/*
 * �m�[�h�̒u������
 */
/************************************************************************************************/
void KsLzss::replaceNode( KsInt32 oldNode, KsInt32 newNode )
{
	KsInt32		oldNodeParent     = m_tree[ oldNode ].parent;

	/* �Â��m�[�h�͐e�̂ǂ���ɐݒ肳��Ă������𒲂ׂ� */
	if( m_tree[ oldNodeParent ].smallChild == oldNode )
	{
		m_tree[ oldNodeParent ].smallChild = newNode;
	}
	else
	{
		m_tree[ oldNodeParent ].largeChild = newNode;
	}

	/* �V�����m�[�h��ǉ����� */
	m_tree[ newNode ]                  = m_tree[ oldNode ];
	m_tree[ m_tree[ newNode ].smallChild ].parent = newNode;
	m_tree[ m_tree[ newNode ].largeChild ].parent = newNode;

	/* �Â��m�[�h�́A���Ԃɂ��� */
	m_tree[ oldNode ].parent = ksUNUSED;
}
/************************************************************************************************/
/*
 * ���̃m�[�h���擾
 */
/************************************************************************************************/
KsInt32 KsLzss::nextNode( KsInt32 node )
{
	KsInt32		next = m_tree[ node ].smallChild;
	
	// ���̃m�[�h������
	while( m_tree[ next ].largeChild != ksUNUSED )
	{
		next = m_tree[ next ].largeChild;
	}

	return	next;
}

/************************************************************************************************/
/*
 * �m�[�h��ǉ�����
 */
/************************************************************************************************/
KsInt32 KsLzss::addNode( KsInt32 newNode, KsInt32* matchPos )
{
	KsInt32		i;
	KsInt32		node;
	KsInt32		delta;
	KsInt32		matchLength = 0;
	KsInt32*		pChild;

	if( newNode == ksEND ){
		return 0;
	}

	node = m_tree[ ksTREE_ROOT ].largeChild;

	while( ksTRUE )
	{
		for( i=0; i<ksMATCH_LENGTH_MAX; i++ )
		{
			delta = m_buffer[ ksHASH( newNode + i ) ] - m_buffer[ ksHASH( node + i ) ];

			if( delta != 0 )
			{
				break;
			}
		}
		
		if( i >= matchLength )
		{
			matchLength = i;
			*matchPos = node;
			
			if( matchLength >= ksMATCH_LENGTH_MAX )
			{
			
				replaceNode( node, newNode );
				
				return matchLength;
			}
		}

		if ( delta >= 0 )
		{
			pChild = &m_tree[ node ].largeChild;
		}
		else
		{
			pChild = &m_tree[ node ].smallChild;
		}

		if( *pChild == ksUNUSED )
		{
			*pChild                      = newNode;
			m_tree[ newNode ].parent     = node;
			m_tree[ newNode ].largeChild = ksUNUSED;
			m_tree[ newNode ].smallChild = ksUNUSED;
			
			return matchLength;
		}
		
		node = *pChild;
	}

	return matchLength;
}
/************************************************************************************************/
/*
 * �m�[�h���폜����
 */
/************************************************************************************************/
void KsLzss::delNode( KsInt32 p )
{
	int  replacement;

	if( m_tree[ p ].parent == ksUNUSED )
	{
		return;
	}

	if ( m_tree[ p ].largeChild == ksUNUSED )
	{
		contractNode( p, m_tree[ p ].smallChild );
	}
	else if( m_tree[ p ].smallChild == ksUNUSED )
	{
		contractNode( p, m_tree[ p ].largeChild );
	}
	else 
	{
		replacement = nextNode( p );
		delNode( replacement );
		replaceNode( p, replacement );
	}
}
/************************************************************************************************/
/*
 * �G���R�[�h
 */
/************************************************************************************************/
KsUInt32 KsLzss::encode( KsByte* pInputBuffer, KsByte* pOutputBuffer )
{
	KsInt32			replaceCount;
	KsInt32			currentPos  = 1;
	KsInt32			matchLength = 0;
	KsInt32			matchPos    = 0;
	KsInt32			length		= 0;
	KsInt32			c;
	KsBitIO				bitIO( pOutputBuffer );

	// �ŏ������w��T�C�Y���o�b�t�@�ɓǂݍ���(�ő��v��16����)
	for( length=0 ; length < ksMATCH_LENGTH_MAX; length++ )
	{
		if( ( c = *(pInputBuffer++) ) == EOF )
		{
			break;
		}
		m_buffer[ currentPos + length ] = (KsByte)c;
	}

	/* �c���[�̏����� */
	initTree( currentPos );

	while( length > 0 )
	{
		// ��v��
		if( matchLength > length ){ matchLength = length; }

		// ��v�����Z���Ƃ����̂܂܏����o��(2�����ȉ��̂Ƃ�)
		if ( matchLength <= ksMATCH_LENGTH_MIN )
		{
			// ���̂܂܏����o��
			replaceCount = 1;
			// ���k�r�b�g���o�͂���(1�o�C�g�����܂�����t�@�C���ɏo�͂����)
			bitIO.pushFlag( 1 );
			// ���k�f�[�^���Z�b�g����( ���k�r�b�g�������ς��ɂȂ�����o�͂���� )
			bitIO.pushData( (KsByte)m_buffer[ currentPos ] );
			bitIO.output();
		}
		else
		{
			//-------------------------------------------------------------------------
			// ���k�����o��
			// 18byte�ǂݍ��� 4bit�Ȃ̂�16�����܂ł���,��v����2�������ƕ��ʂɏ����o���̂łR����
			// ����Ȃ̂�2��������18�����܂łɂȂ�
			// +----------------+------+
			// | 0000 0000 0000 | 0000 |
			// +----------------+------+
			// | �I�t�Z�b�g�ʒu |��v��|
			// +----------------+------+
			// |                | 18-2 |
			// +----------------+------+
			// ���k�r�b�g���o�͂���(1�o�C�g�����܂�����t�@�C���ɏo�͂����)
			bitIO.pushFlag( 0 );
			// ���k�f�[�^���Z�b�g����( ���k�r�b�g�������ς��ɂȂ�����o�͂���� )
			bitIO.pushData( (KsByte)matchPos ); // offset
			bitIO.pushData( (KsByte)( ( (matchPos >> 4) & 0xf0) | (matchLength - 3) ) ); // 
			bitIO.output();

			replaceCount = matchLength;
		}

		for( KsInt32 i=0; i<replaceCount; i++ )
		{
			// �폜����
			delNode( ksHASH( currentPos + ksMATCH_LENGTH_MAX ) );
			
			if( ( c = *(pInputBuffer++) ) == EOF )
			{
				length--;
			}
			else
			{
				m_buffer[ ksHASH( currentPos + ksMATCH_LENGTH_MAX ) ] = (KsByte)c;
			}
			
			currentPos = ksHASH( currentPos + 1 );

			if( length )
			{
				matchLength = addNode( currentPos, &matchPos );
			}
		}
	}

	// �c���Ă�����̂������o��
	// �I���R�[�h�������o��
	// ���k�f�[�^��
	// ��v����0��������I��
	bitIO.outputAll();

	return bitIO.getSize();
}
/************************************************************************************************/
/*
 * �G���R�[�h
 */
/************************************************************************************************/
KsUInt32 KsLzss::encode( KsByte* pInputBuffer, FILE* pOutputFile )
{
	KsInt32			replaceCount;
	KsInt32			currentPos  = 1;
	KsInt32			matchLength = 0;
	KsInt32			matchPos    = 0;
	KsInt32			length		= 0;
	KsInt32			c;
	KsBitIO			bitIO( pOutputFile );

	// �ŏ������w��T�C�Y���o�b�t�@�ɓǂݍ���(�ő��v��16����)
	for( length=0 ; length < ksMATCH_LENGTH_MAX; length++ )
	{
		if( ( c = *(pInputBuffer++) ) == EOF )
		{
			break;
		}
		m_buffer[ currentPos + length ] = (KsByte)c;
	}

	/* �c���[�̏����� */
	initTree( currentPos );

	while( length > 0 )
	{
		// ��v��
		if( matchLength > length ){ matchLength = length; }

		// ��v�����Z���Ƃ����̂܂܏����o��(2�����ȉ��̂Ƃ�)
		if ( matchLength <= ksMATCH_LENGTH_MIN )
		{
			// ���̂܂܏����o��
			replaceCount = 1;
			// ���k�r�b�g���o�͂���(1�o�C�g�����܂�����t�@�C���ɏo�͂����)
			bitIO.pushFlag( 1 );
			// ���k�f�[�^���Z�b�g����( ���k�r�b�g�������ς��ɂȂ�����o�͂���� )
			bitIO.pushData( (KsByte)m_buffer[ currentPos ] );
			bitIO.output();
		}
		else
		{
			//-------------------------------------------------------------------------
			// ���k�����o��
			// 18byte�ǂݍ��� 4bit�Ȃ̂�16�����܂ł���,��v����2�������ƕ��ʂɏ����o���̂łR����
			// ����Ȃ̂�2��������18�����܂łɂȂ�
			// +----------------+------+
			// | 0000 0000 0000 | 0000 |
			// +----------------+------+
			// | �I�t�Z�b�g�ʒu |��v��|
			// +----------------+------+
			// |                | 18-2 |
			// +----------------+------+
			// ���k�r�b�g���o�͂���(1�o�C�g�����܂�����t�@�C���ɏo�͂����)
			bitIO.pushFlag( 0 );
			// ���k�f�[�^���Z�b�g����( ���k�r�b�g�������ς��ɂȂ�����o�͂���� )
			bitIO.pushData( (KsByte)matchPos ); // offset
			bitIO.pushData( (KsByte)( ( (matchPos >> 4) & 0xf0) | (matchLength - 3) ) ); // 
			bitIO.output();

			replaceCount = matchLength;
		}

		for( KsInt32 i=0; i<replaceCount; i++ )
		{
			// �폜����
			delNode( ksHASH( currentPos + ksMATCH_LENGTH_MAX ) );
			
			if( ( c = *(pInputBuffer++) ) == EOF )
			{
				length--;
			}
			else
			{
				m_buffer[ ksHASH( currentPos + ksMATCH_LENGTH_MAX ) ] = (KsByte)c;
			}
			
			currentPos = ksHASH( currentPos + 1 );

			if( length )
			{
				matchLength = addNode( currentPos, &matchPos );
			}
		}
	}

	// �c���Ă�����̂������o��
	// �I���R�[�h�������o��
	// ���k�f�[�^��
	// ��v����0��������I��
	bitIO.outputAll();

	return bitIO.getSize();
}
/************************************************************************************************/
/*
 * �G���R�[�h
 */
/************************************************************************************************/
KsUInt32 KsLzss::encode( FILE* pInputFile, KsByte* pOutputBuffer )
{
	KsInt32			replaceCount;
	KsInt32			currentPos  = 1;
	KsInt32			matchLength = 0;
	KsInt32			matchPos    = 0;
	KsInt32			length		= 0;
	KsInt32			c;
	KsBitIO			bitIO( pOutputBuffer );

	// �ŏ������w��T�C�Y���o�b�t�@�ɓǂݍ���(�ő��v��16����)
	for( length=0 ; length < ksMATCH_LENGTH_MAX; length++ )
	{
		if( ( c = getc( pInputFile ) ) == EOF )
		{
			break;
		}
		m_buffer[ currentPos + length ] = (KsByte)c;
	}

	/* �c���[�̏����� */
	initTree( currentPos );

	while( length > 0 )
	{
		// ��v��
		if( matchLength > length ){ matchLength = length; }

		// ��v�����Z���Ƃ����̂܂܏����o��(2�����ȉ��̂Ƃ�)
		if ( matchLength <= ksMATCH_LENGTH_MIN )
		{
			// ���̂܂܏����o��
			replaceCount = 1;
			// ���k�r�b�g���o�͂���(1�o�C�g�����܂�����t�@�C���ɏo�͂����)
			bitIO.pushFlag( 1 );
			// ���k�f�[�^���Z�b�g����( ���k�r�b�g�������ς��ɂȂ�����o�͂���� )
			bitIO.pushData( (KsByte)m_buffer[ currentPos ] );
			bitIO.output();
		}
		else
		{
			//-------------------------------------------------------------------------
			// ���k�����o��
			// 18byte�ǂݍ��� 4bit�Ȃ̂�16�����܂ł���,��v����2�������ƕ��ʂɏ����o���̂łR����
			// ����Ȃ̂�2��������18�����܂łɂȂ�
			// +----------------+------+
			// | 0000 0000 0000 | 0000 |
			// +----------------+------+
			// | �I�t�Z�b�g�ʒu |��v��|
			// +----------------+------+
			// |                | 18-2 |
			// +----------------+------+
			// ���k�r�b�g���o�͂���(1�o�C�g�����܂�����t�@�C���ɏo�͂����)
			bitIO.pushFlag( 0 );
			// ���k�f�[�^���Z�b�g����( ���k�r�b�g�������ς��ɂȂ�����o�͂���� )
			bitIO.pushData( (KsByte)matchPos ); // offset
			bitIO.pushData( (KsByte)( ( (matchPos >> 4) & 0xf0) | (matchLength - 3) ) ); // 
			bitIO.output();

			replaceCount = matchLength;
		}

		for( KsInt32 i=0; i<replaceCount; i++ )
		{
			// �폜����
			delNode( ksHASH( currentPos + ksMATCH_LENGTH_MAX ) );
			
			if( ( c = getc( pInputFile ) ) == EOF )
			{
				length--;
			}
			else
			{
				m_buffer[ ksHASH( currentPos + ksMATCH_LENGTH_MAX ) ] = (KsByte)c;
			}
			
			currentPos = ksHASH( currentPos + 1 );

			if( length )
			{
				matchLength = addNode( currentPos, &matchPos );
			}
		}
	}

	// �c���Ă�����̂������o��
	// �I���R�[�h�������o��
	// ���k�f�[�^��
	// ��v����0��������I��
	bitIO.outputAll();

	return bitIO.getSize();
}
/************************************************************************************************/
/*
 * �G���R�[�h
 */
/************************************************************************************************/
KsUInt32 KsLzss::encode( FILE* pInputFile, FILE* pOutputFile )
{
	KsInt32			replaceCount;
	KsInt32			currentPos  = 1;
	KsInt32			matchLength = 0;
	KsInt32			matchPos    = 0;
	KsInt32			length		= 0;
	KsInt32			c;
	KsBitIO			bitIO( pOutputFile );

	// �ŏ������w��T�C�Y���o�b�t�@�ɓǂݍ���(�ő��v��16����)
	for( length=0 ; length < ksMATCH_LENGTH_MAX; length++ )
	{
		if( ( c = getc( pInputFile ) ) == EOF )
		{
			break;
		}

		m_buffer[ currentPos + length ] = (KsByte)c;
	}

	/* �c���[�̏����� */
	initTree( currentPos );

	while( length > 0 )
	{
		// ��v��
		if( matchLength > length ){ matchLength = length; }

		// ��v�����Z���Ƃ����̂܂܏����o��(2�����ȉ��̂Ƃ�)
		if ( matchLength <= ksMATCH_LENGTH_MIN )
		{
			// ���̂܂܏����o��
			replaceCount = 1;
			// ���k�r�b�g���o�͂���(1�o�C�g�����܂�����t�@�C���ɏo�͂����)
			bitIO.pushFlag( 1 );
			// ���k�f�[�^���Z�b�g����( ���k�r�b�g�������ς��ɂȂ�����o�͂���� )
			bitIO.pushData( (KsByte)m_buffer[ currentPos ] );
			bitIO.output();
		}
		else
		{
			//-------------------------------------------------------------------------
			// ���k�����o��
			// 18byte�ǂݍ��� 4bit�Ȃ̂�16�����܂ł���,��v����2�������ƕ��ʂɏ����o���̂łR����
			// ����Ȃ̂�2��������18�����܂łɂȂ�
			// +----------------+------+
			// | 0000 0000 0000 | 0000 |
			// +----------------+------+
			// | �I�t�Z�b�g�ʒu |��v��|
			// +----------------+------+
			// |                | 18-2 |
			// +----------------+------+
			// ���k�r�b�g���o�͂���(1�o�C�g�����܂�����t�@�C���ɏo�͂����)
			bitIO.pushFlag( 0 );
			// ���k�f�[�^���Z�b�g����( ���k�r�b�g�������ς��ɂȂ�����o�͂���� )
			bitIO.pushData( (KsByte)matchPos ); // offset
			bitIO.pushData( (KsByte)( ( (matchPos >> 4) & 0xf0) | (matchLength - 3) ) ); // 
			bitIO.output();

			replaceCount = matchLength;
		}

		for( KsInt32 i=0; i<replaceCount; i++ )
		{
			// �폜����
			delNode( ksHASH( currentPos + ksMATCH_LENGTH_MAX ) );
			
			if( ( c = getc( pInputFile ) ) == EOF )
			{
				length--;
			}
			else
			{
				m_buffer[ ksHASH( currentPos + ksMATCH_LENGTH_MAX ) ] = (KsByte)c;
			}
			
			currentPos = ksHASH( currentPos + 1 );

			if( length )
			{
				matchLength = addNode( currentPos, &matchPos );
			}
		}
	}

	// �c���Ă�����̂������o��
	// �I���R�[�h�������o��
	// ���k�f�[�^��
	// ��v����0��������I��
	bitIO.outputAll();

	return bitIO.getSize();
}
/************************************************************************************************/
/*
 * �f�R�[�h
 */
/************************************************************************************************/
void KsLzss::decode( FILE* pInputFile, FILE* pOutputFile )
{
	KsInt32		currentPos = 1;
	KsInt32		matchLength;
	KsInt32		matchPos;
	KsInt32		data;
	KsInt32		data1;
	KsInt32		data2;
	KsInt32		flags = 0;
	KsUInt32	size  = 0;

	while( 1 )
	{
		flags >>= 1;

		if( !( flags & 0x0100 ) )
		{
			data  = getc( pInputFile );
			flags = ( 0xff00 | data );
		}

		// �f�[�^�ǂݍ���
		if( flags & 1 )
		{
			/* �񈳏k�̃f�[�^ */
			data = getc( pInputFile );
            //*( pOutBuffer++ ) = data1;
			putc( data, pOutputFile );

            m_buffer[ currentPos ] = (KsByte)data;

            currentPos = ksHASH( currentPos + 1 );
		}
		else
		{
			/* ���k�f�[�^ */
			data1       = getc( pInputFile );
			data2       = getc( pInputFile );
			matchPos    = ( ( data2 & 0xf0 ) << 4 ) | data1;	/* �ʒu�擾			*/
			matchLength = ( data2 & 0x0f );
			
			//if( !matchLength ){
			//if( data1 == 0 && data2 ==0 ){
			if( !matchPos )
			{
				/* �I���R�[�h */
				break;
			}

			matchLength += 2;		/* ��v�������߂�	*/

			for( KsInt32 i=0; i<=matchLength; i++ )
            {
                data = m_buffer[ ksHASH( matchPos + i ) ];
                
				//*(pOutBuffer++) = c;
				putc( data, pOutputFile );

                m_buffer[ currentPos ] = (KsByte)data;

                currentPos = ksHASH( currentPos + 1 );
            }
		}
	}
}

/************************************************************************************************/
/*
 * �f�R�[�h
 */
/************************************************************************************************/
void KsLzss::decode( KsByte* pInputBuffer, KsByte* pOutputBuffer )
{
	KsInt32		currentPos = 1;
	KsInt32		matchLength;
	KsInt32		matchPos;
	KsInt32		data;
	KsInt32		data1;
	KsInt32		data2;
	KsInt32		flags = 0;
	KsUInt32	size  = 0;

	while( 1 )
	{
		flags >>= 1;

		if( !( flags & 0x0100 ) )
		{
			data  = *( pInputBuffer++ );
			flags = ( 0xff00 | data );
		}

		// �f�[�^�ǂݍ���
		if( flags & 1 )
		{
			/* �񈳏k�̃f�[�^ */
			data = *( pInputBuffer++ );
            *( pOutputBuffer++ ) = data;

            m_buffer[ currentPos ] = (KsByte)data;

            currentPos = ksHASH( currentPos + 1 );
		}
		else
		{
			/* ���k�f�[�^ */
			data1       = *( pInputBuffer++ );
			data2       = *( pInputBuffer++ );
			matchPos    = ( ( data2 & 0xf0 ) << 4 ) | data1;	/* �ʒu�擾			*/
			matchLength = ( data2 & 0x0f );
			
			//if( !matchLength ){
			//if( data1 == 0 && data2 ==0 ){
			if( !matchPos )
			{
				/* �I���R�[�h */
				break;
			}

			matchLength += 2;					/* ��v�������߂�	*/

			for( KsInt32 i=0; i<=matchLength; i++ )
            {
                data = m_buffer[ ksHASH( matchPos + i ) ];
                
				*(pOutputBuffer++) = data;

                m_buffer[ currentPos ] = (KsByte)data;

                currentPos = ksHASH( currentPos + 1 );
            }
		}
	}
}

/************************************************************************************************/
/*
 * �f�R�[�h
 */
/************************************************************************************************/
void KsLzss::decode( KsByte* pInputBuffer, FILE* pOutputFile )
{
	KsInt32		currentPos = 1;
	KsInt32		matchLength;
	KsInt32		matchPos;
	KsInt32		data;
	KsInt32		data1;
	KsInt32		data2;
	KsInt32		flags = 0;
	KsUInt32	size  = 0;

	while( 1 )
	{
		flags >>= 1;

		if( !( flags & 0x0100 ) )
		{
			data  = *( pInputBuffer++ );
			flags = ( 0xff00 | data );
		}

		// �f�[�^�ǂݍ���
		if( flags & 1 )
		{
			/* �񈳏k�̃f�[�^ */
			data = *( pInputBuffer++ );
			putc( data, pOutputFile );

            m_buffer[ currentPos ] = (KsByte)data;

            currentPos = ksHASH( currentPos + 1 );
		}
		else
		{
			/* ���k�f�[�^ */
			data1       = *( pInputBuffer++ );
			data2       = *( pInputBuffer++ );
			matchPos    = ( ( data2 & 0xf0 ) << 4 ) | data1;	/* �ʒu�擾	*/
			matchLength = ( data2 & 0x0f );
			
			//if( !matchLength ){
			//if( data1 == 0 && data2 ==0 ){
			if( !matchPos )
			{
				/* �I���R�[�h */
				break;
			}

			matchLength += 2;		/* ��v�������߂�	*/

			for( KsInt32 i=0; i<=matchLength; i++ )
            {
                data = m_buffer[ ksHASH( matchPos + i ) ];
                
				putc( data, pOutputFile );

                m_buffer[ currentPos ] = (KsByte)data;

                currentPos = ksHASH( currentPos + 1 );
            }
		}
	}
}

/************************************************************************************************/
/*
 * �f�R�[�h
 */
/************************************************************************************************/
void KsLzss::decode( FILE* pInputFile, KsByte* pOutputBuffer )
{
	KsInt32		currentPos = 1;
	KsInt32		matchLength;
	KsInt32		matchPos;
	KsInt32		data;
	KsInt32		data1;
	KsInt32		data2;
	KsInt32		flags = 0;
	KsUInt32	size  = 0;

	while( 1 )
	{
		flags >>= 1;

		if( !( flags & 0x0100 ) )
		{
			data  = getc( pInputFile );
			flags = ( 0xff00 | data );
		}

		// �f�[�^�ǂݍ���
		if( flags & 1 )
		{
			/* �񈳏k�̃f�[�^ */
			data = getc( pInputFile );
            *( pOutputBuffer++ ) = data;

            m_buffer[ currentPos ] = (KsByte)data;

            currentPos = ksHASH( currentPos + 1 );
		}
		else
		{
			/* ���k�f�[�^ */
			data1       = getc( pInputFile );
			data2       = getc( pInputFile );
			matchPos    = ( ( data2 & 0xf0 ) << 4 ) | data1;	/* �ʒu�擾	*/
			matchLength = ( data2 & 0x0f );
			
			//if( !matchLength ){
			//if( data1 == 0 && data2 ==0 ){
			if( !matchPos )
			{
				/* �I���R�[�h */
				break;
			}

			matchLength += 2;					/* ��v�������߂�	*/

			for( KsInt32 i=0; i<=matchLength; i++ )
            {
                data = m_buffer[ ksHASH( matchPos + i ) ];
                
				*(pOutputBuffer++) = data;

                m_buffer[ currentPos ] = (KsByte)data;

                currentPos = ksHASH( currentPos + 1 );
            }
		}
	}
}


ksNS_KS_END

