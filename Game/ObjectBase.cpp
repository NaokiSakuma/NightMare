//	�w�b�_�t�@�C���̃C���N���[�h
#include "ObjectBase.h"
#include "GameMain.h"

using namespace DirectX::SimpleMath;
using namespace DirectX;

//	�n���h���̐ݒ�
void  ObjectBase::SetHandle(Texture *p)
{
	handle = p;
}

//	�n���h���̎擾
Texture*  ObjectBase::GetHandle()
{
	return handle;
}

//	�n���h�����Wx�̐ݒ�
void ObjectBase::SetGrpX(float x)
{
	grp_x = x;
}

//	�n���h�����Wx�̎擾
float  ObjectBase::GetGrpX()
{
	return grp_x;
}

//	�n���h�����Wy�̐ݒ�
void  ObjectBase::SetGrpY(float y)
{
	grp_y = y;
}

//	�n���h�����Wy�̎擾
float  ObjectBase::GetGrpY()
{
	return grp_y;
}

//	�I�u�W�F�N�g�̕��ݒ�
void  ObjectBase::SetGrpW(float w)
{
	grp_w = w;
}

//	�I�u�W�F�N�g�̕����擾
float  ObjectBase::GetGrpW()
{
	return grp_w;
}

//	�I�u�W�F�N�g�̍�����ݒ�
void  ObjectBase::SetGrpH(float h)
{
	grp_h = h;
}

//	�I�u�W�F�N�g�̍�����ݒ�
float ObjectBase::GetGrpH()
{
	return grp_h;
}

//	�I�u�W�F�N�g�̍��Wx��ݒ�
void ObjectBase::SetPosX(float x)
{
	pos_x = x;
}

//	�I�u�W�F�N�g�̍��Wx���擾
float ObjectBase::GetPosX()
{
	return pos_x;
}

//	�I�u�W�F�N�g�̍��Wy��ݒ�
void ObjectBase::SetPosY(float y)
{
	pos_y = y;
}

//	�I�u�W�F�N�g�̍��Wy���擾
float ObjectBase::GetPosY()
{
	return pos_y;
}

//	�I�u�W�F�N�g�̃X�s�[�hy�̐ݒ�
void ObjectBase::SetSpdX(float x)
{
	spd_x = x;
}

//	�I�u�W�F�N�g�̃X�s�[�hy�̎擾
void ObjectBase::SetSpdY(float y)
{
	spd_y = y;
}

//	�I�u�W�F�N�g�̃X�e�[�g��ݒ�
void ObjectBase::SetState(int n)
{
	state = n;
}

//	�I�u�W�F�N�g�̃X�e�[�g���擾
int ObjectBase::GetState()
{
	return state;
}

//	�I�u�W�F�N�g�̍X�V����
void ObjectBase::Update()
{
	pos_x = pos_x + spd_x;
	pos_y = pos_y + spd_y;
}

//	�I�u�W�F�N�g�̕`�揈��
void ObjectBase::Render()
{
	//	�摜�̒Z�`�p�ϐ�
	RECT rect;

	rect = { grp_x, grp_y, grp_x + grp_w, grp_y + grp_h };

	g_spriteBatch->Draw(handle->m_pTexture, Vector2(pos_x, pos_y),
		&rect, Colors::White, 0.0f, Vector2(0, 0), 1.0f);
}