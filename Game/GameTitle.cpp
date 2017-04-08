//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameTitle.cpp
//!
//! @brief  �^�C�g�������̃\�[�X�t�@�C��
//!
//! @date   2017/04/07		
//!
//! @author ���� ����
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include "GameMain.h"
#include "GameTitle.h"

using namespace DirectX::SimpleMath;
using namespace DirectX;

//----------------------------------------------------------------------
//! @brief �R���X�g���N�^
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
Title::Title()
{
	//	�^�C�g���摜�̏�����
	m_title_image = new Texture(L"Resources\\Images\\title.png");
	m_title_image2 = new Texture(L"Resources\\Images\\title2.png");

	//	�t�F�[�h�p�ϐ��̏�����
	m_fade_flag = false;
	m_alfa = 1.0f;

	//	�J�E���g�̏�����
	m_count = 0;
}

//----------------------------------------------------------------------
//! @brief �f�X�g���N�^
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
Title::~Title()
{

}

//----------------------------------------------------------------------
//! @brief �^�C�g���̍X�V����
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Title::Update()
{
	//�V�[���̍ŏ��Ɉ�񂾂��s������������
	if (g_init == 0)
	{
		g_init = 1;
	}

	//	Z�L�[����������v���C�V�[����
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
		g_NextScene = PLAY;
	}

}

//----------------------------------------------------------------------
//! @brief �^�C�g���̕`�揈��
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Title::Render()
{
	if (m_count <= 20)
	{
		//	�摜�̕`��
		g_spriteBatch->Draw(m_title_image->m_pTexture, Vector2(0, 0), Color(1.0f, 1.0f, 1.0f, m_alfa));
	}
	else
	{
		//	�摜�̕`��
		g_spriteBatch->Draw(m_title_image2->m_pTexture, Vector2(0, 0), Color(1.0f, 1.0f, 1.0f, m_alfa));
	}
}
