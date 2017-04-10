//	�w�b�_�t�@�C���̃C���N���[�h
#include "ObjectBase.h"
#include "GameMain.h"

using namespace DirectX::SimpleMath;
using namespace DirectX;

//	�n���h���̐ݒ�
void  ObjectBase::SetHandle(Texture *p)
{
	m_handle = p;
}

//	�n���h���̎擾
Texture*  ObjectBase::GetHandle()
{
	return m_handle;
}

//	�n���h�����Wx�̐ݒ�
void ObjectBase::SetGrpX(float x)
{
	m_grp_x = x;
}

//	�n���h�����Wx�̎擾
float  ObjectBase::GetGrpX()
{
	return m_grp_x;
}

//	�n���h�����Wy�̐ݒ�
void  ObjectBase::SetGrpY(float y)
{
	m_grp_y = y;
}

//	�n���h�����Wy�̎擾
float  ObjectBase::GetGrpY()
{
	return m_grp_y;
}

//	�I�u�W�F�N�g�̕��ݒ�
void  ObjectBase::SetGrpW(float w)
{
	m_grp_w = w;
}

//	�I�u�W�F�N�g�̕����擾
float  ObjectBase::GetGrpW()
{
	return m_grp_w;
}

//	�I�u�W�F�N�g�̍�����ݒ�
void  ObjectBase::SetGrpH(float h)
{
	m_grp_h = h;
}

//	�I�u�W�F�N�g�̍�����ݒ�
float ObjectBase::GetGrpH()
{
	return m_grp_h;
}

//	�I�u�W�F�N�g�̍��Wx��ݒ�
void ObjectBase::SetPosX(float x)
{
	m_pos_x = x;
}

//	�I�u�W�F�N�g�̍��Wx���擾
float ObjectBase::GetPosX()
{
	return m_pos_x;
}

//	�I�u�W�F�N�g�̍��Wy��ݒ�
void ObjectBase::SetPosY(float y)
{
	m_pos_y = y;
}

//	�I�u�W�F�N�g�̍��Wy���擾
float ObjectBase::GetPosY()
{
	return m_pos_y;
}

//	�I�u�W�F�N�g�̃X�s�[�hy�̐ݒ�
void ObjectBase::SetSpdX(float x)
{
	m_spd_x = x;
}

//	�I�u�W�F�N�g�̃X�s�[�hy�̎擾
void ObjectBase::SetSpdY(float y)
{
	m_spd_y = y;
}

//	�I�u�W�F�N�g�̃X�e�[�g��ݒ�
void ObjectBase::SetState(int n)
{
	m_state = n;
}

//	�I�u�W�F�N�g�̃X�e�[�g���擾
int ObjectBase::GetState()
{
	return m_state;
}

//	�I�u�W�F�N�g�̍X�V����
void ObjectBase::Update()
{
	m_pos_x = m_pos_x + m_spd_x;
	m_pos_y = m_pos_y + m_spd_y;
}

//	�I�u�W�F�N�g�̕`�揈��
void ObjectBase::Render()
{
	//	�摜�̒Z�`�p�ϐ�
	RECT rect;

	rect = { m_grp_x, m_grp_y, m_grp_x + m_grp_w, m_grp_y + m_grp_h };

	g_spriteBatch->Draw(m_handle->m_pTexture, Vector2(m_pos_x, m_pos_y),
		&rect, Colors::White, 0.0f, Vector2(0, 0), 1.0f);
}

float ObjectBase::GetSpdX()
{
	return m_spd_x;
}

//�I�u�W�F�N�g�̕`�揈��(�X�N���[���ɑΉ�)
void ObjectBase::Render(int camera_pos_x)
{
	//	�摜�̒Z�`�p�ϐ�
	RECT rect;

	rect = { m_grp_x, m_grp_y, m_grp_x + m_grp_w, m_grp_y + m_grp_h };

	g_spriteBatch->Draw(m_handle->m_pTexture, Vector2(m_pos_x - (camera_pos_x - SCREEN_WIDTH / 2),
		m_pos_y),
		&rect, Colors::White, 0.0f, Vector2(0, 0), 1.0f);

}
