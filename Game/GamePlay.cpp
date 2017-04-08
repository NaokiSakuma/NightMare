//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GamePlay.cpp
//!
//! @brief  �Q�[���v���C�����̃\�[�X�t�@�C��
//!
//! @date   2017/04/07		
//!
//! @author ���� ����
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include "GameMain.h"
#include "GamePlay.h"


using namespace DirectX::SimpleMath;
using namespace DirectX;

//�O���[�o���ϐ��������������������������������������������������������������|

//�֐��̒�`�����������������������������������������������������������������|
//----------------------------------------------------------------------
//! @brief �v���C�V�[���̃R���X�g���N�^
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
Play::Play()
{
	//	�w�i�摜
	m_back_image = new Texture(L"Resources\\Images\\back.png");

	//	�|�[�Y�摜
	m_pause_image = new Texture(L"Resources\\Images\\pause.png");

	//	�I��p�̐��̉摜
	m_line_image = new Texture(L"Resources\\Images\\Line.png");

	//	�|�[�Y�t���O�̏�����
	m_pause_flag = false;

	//	�|�[�Y�I��p�ϐ��̏�����
	m_pause_select = 0;

}

//----------------------------------------------------------------------
//! @brief �v���C�V�[���̃f�X�g���N�^
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
Play::~Play()
{

}

//----------------------------------------------------------------------
//! @brief �Q�[���v���C�̍X�V����
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Play::Update()
{
	//�V�[���̍ŏ��Ɉ�񂾂��s������������
	if (g_init == 0)
	{

	}
	//	�|�[�Y�t���O��false�Ȃ牺�̏������s��
	if (m_pause_flag == false)
	{
		if (g_keyTracker->pressed.X)
		{
			m_pause_flag = true;
		}
	}

	//	�|�[�Y�t���O��true�Ȃ牺�̏������s��
	if (m_pause_flag == true)
	{
		//	���L�[�������ꂽ��I����1�i�߂�
		if (g_keyTracker->pressed.Down)
		{
			//	�I��p�ϐ���1�𑫂�
			m_pause_select++;

			//	�I��p�ϐ����I�����𒴂������ɖ߂�
			if (m_pause_select > RETURN_TITLE)
			{
				m_pause_select = RETURN;
			}
		}

		//	��L�[�������ꂽ��I����1�߂�
		if (g_keyTracker->pressed.Up)
		{
			//	�I��p�ϐ�����1������
			m_pause_select--;

			//	�I��p�ϐ����I�����𒴂����牺�ɖ߂�
			if (m_pause_select < RETURN)
			{
				m_pause_select = RETURN_TITLE;
			}
		}

		//	Z�L�[�������ꂽ��I���ɂ���Ď��ɐi��
		if (g_keyTracker->pressed.Z)
		{
			//	�I����RETURN�̎��Ȃ�Q�[���֖߂�
			if (m_pause_select == RETURN)
			{

			}

			//	�I����RETURN_TITLE�Ȃ�^�C�g���֖߂�
			if (m_pause_select == RETURN_TITLE)
			{
				g_NextScene = TITLE;
			}
		}
	}
}

//----------------------------------------------------------------------
//! @brief �Q�[���v���C�`�揈��
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Play::Render()
{
	//	�摜�̕`��
	g_spriteBatch->Draw(m_back_image->m_pTexture, Vector2(0, 0));

	//	�|�[�Y�t���O��true�Ȃ牺�̏������s��
	if (m_pause_flag == true)
	{
		//	�摜�̕`��
		g_spriteBatch->Draw(m_pause_image->m_pTexture, Vector2(0, 0));

		//	�I��p�ϐ��ɂ���Đ��̈ʒu�����炷
		if (m_pause_select == RETURN)
		{
			//	�摜�̕`��
			g_spriteBatch->Draw(m_line_image->m_pTexture, Vector2(105.0f, 260.0f));
		}
		else if(m_pause_select == RETURN_TITLE)
		{
			//	�摜�̕`��
			g_spriteBatch->Draw(m_line_image->m_pTexture, Vector2(105.0f, 340.0f));
		}
	}

}
