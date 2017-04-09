//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameClear.cpp
//!
//! @brief  �Q�[���N���A�����̃\�[�X�t�@�C��
//!
//! @date   2017/04/07		
//!
//! @author ���� ����	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include "GameMain.h"
#include "GameClear.h"
using namespace DirectX::SimpleMath;
using namespace DirectX;

//----------------------------------------------------------------------
//! @brief �Q�[���N���A�R���X�g���N�^
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
Clear::Clear()
{
	//	�N���A�摜�̏�����
	m_clear_image = new Texture(L"Resources\\Images\\clear.png");
	m_clear_image2 = new Texture(L"Resources\\Images\\clear2.png");

	//	�t�F�[�h�p�ϐ��̏�����
	m_fade_flag = false;
	m_alfa = 1.0f;

	//	�J�E���g�̏�����
	m_count = 0;
}

//----------------------------------------------------------------------
//! @brief �Q�[���N���A�f�X�g���N�^
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
Clear::~Clear()
{
}

//----------------------------------------------------------------------
//! @brief �Q�[���N���A����
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Clear::Update()
{
	if (g_init == 0)
	{
		g_init = 1;
		g_TimeCnt = 0;
	}

	//	Z�L�[����������^�C�g���V�[����
	if (g_keyTracker->pressed.Z)
	{
		ADX2Le::Play(CRI_CUESHEET_1_SE);
		m_fade_flag = true;
	}

	//	�t�F�[�h�t���O��true�Ȃ瓧���x���グ��
	if (m_fade_flag == true)
	{
		m_alfa -= 0.01f;
	}
	else
	{
		//	�J�E���g��i�߂�
		m_count++;
	}

	//	�J�E���g��40�𒴂�����0�ɖ߂�
	if (m_count > 40)
	{
		m_count = 0;
	}

	//	�����Ȃ�V�[����؂�ւ���
	if (m_alfa <= 0.0f)
	{
		g_NextScene = TITLE;
	}
}

//----------------------------------------------------------------------
//! @brief �Q�[���N���A�`�揈��
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Clear::Render()
{
	if (m_count <= 20)
	{
		//	�摜�̕`��
		g_spriteBatch->Draw(m_clear_image->m_pTexture, Vector2(0, 0), Color(1.0f, 1.0f, 1.0f, m_alfa));
	}
	else
	{
		//	�摜�̕`��
		g_spriteBatch->Draw(m_clear_image2->m_pTexture, Vector2(0, 0), Color(1.0f, 1.0f, 1.0f, m_alfa));
	}
}
