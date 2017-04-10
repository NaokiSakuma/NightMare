//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameOver.cpp
//!
//! @brief  �Q�[���I�[�o�[�����̃\�[�X�t�@�C��
//!
//! @date   2017/04/07		
//!
//! @author ���� ����
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include "GameMain.h"
#include "GameOver.h"

using namespace DirectX::SimpleMath;
using namespace DirectX;

//----------------------------------------------------------------------
//! @brief �Q�[���I�[�o�[�̃R���X�g���N�^
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
Over::Over()
{
	//���Ă���BGM���~�߂�
	ADX2Le::Stop();
	//�Q�[���I�[�o�[�V�[������BGM
	ADX2Le::Play(CRI_CUESHEET_0_TOMOSHIBI);

	//	�Q�[���I�[�o�[�摜�̏�����
	m_over_image = new Texture(L"Resources\\Images\\gameover.png");
	m_over_image2 = new Texture(L"Resources\\Images\\gameover2.png");

	//	�w�i(��)�̏�����
	m_back_image = new Texture(L"Resources\\Images\\back.png");

	//	�t�F�[�h�p�ϐ��̏�����
	m_fade_flag = false;
	m_alfa = 1.0f;

	//	�J�E���g�̏�����
	m_count = 0;
}

//----------------------------------------------------------------------
//! @brief �Q�[���I�[�o�[�̃f�X�g���N�^
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
Over::~Over()
{

}

//----------------------------------------------------------------------
//! @brief �Q�[���I�[�o�[�̍X�V����
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Over::Update()
{
	//�V�[���̍ŏ��Ɉ�񂾂��s������������
	if (g_init == 0)
	{
		g_init = 1;


	}

	//	Z�L�[����������^�C�g���V�[����
	if (g_keyTracker->pressed.Z)
	{
		ADX2Le::Play(CRI_CUESHEET_0_SE);
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
//! @brief �Q�[���I�[�o�[�̕`�揈��
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Over::Render()
{
	//	�摜�̕`��
	g_spriteBatch->Draw(m_back_image->m_pTexture, Vector2(0, 0));

	if (m_count <= 20)
	{
		//	�摜�̕`��
		g_spriteBatch->Draw(m_over_image->m_pTexture, Vector2(0, 0), Color(1.0f, 1.0f, 1.0f, m_alfa));
	}
	else
	{
		//	�摜�̕`��
		g_spriteBatch->Draw(m_over_image2->m_pTexture, Vector2(0, 0), Color(1.0f, 1.0f, 1.0f, m_alfa));
	}
}