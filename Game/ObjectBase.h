//	���d�C���N���[�h�̖h�~
#pragma once

//	�w�b�_�t�@�C���̃C���N���[�h
#include "..\DirectXTK.h"
#include "..\Texture.h"

class ObjectBase
{
protected:
	Texture *m_handle;	//�O���t�B�b�N�n���h�� 
	int m_grp_x;			//���摜�̂����W 
	int m_grp_y;			//���摜�̂����W 
	int m_grp_w;			//���摜�̕� 
	int m_grp_h;			//���摜�̍��� 
	float m_pos_x;		//���Wx 
	float m_pos_y;		//���Wy 
	float m_spd_x;		//���xx 
	float m_spd_y;		//���xy 
	int m_state;			//���

public:
	void SetHandle(Texture *p);		//	�n���h���̐ݒ�
	Texture* GetHandle();			//	�n���h���̎擾
	void SetGrpX(float x);			//	�n���h�����Wx�̐ݒ�
	float GetGrpX();				//	�n���h�����Wx�̎擾
	void SetGrpY(float y);			//	�n���h�����Wy�̐ݒ�
	float GetGrpY();				//	�n���h�����Wy�̎擾
	void SetGrpW(float w);			//	�I�u�W�F�N�g�̕���ݒ�
	float GetGrpW();				//	�I�u�W�F�N�g�̕����擾
	void SetGrpH(float h);			//	�I�u�W�F�N�g�̍�����ݒ�
	float GetGrpH();				//	�I�u�W�F�N�g�̍������擾
	void SetPosX(float x);			//	�I�u�W�F�N�g�̍��Wx�̐ݒ�
	float GetPosX();				//	�I�u�W�F�N�g�̍��Wx�̎擾
	void SetPosY(float y);			//	�I�u�W�F�N�g�̍��Wy�̐ݒ�
	float GetPosY();				//	�I�u�W�F�N�g�̍��Wy�̎擾
	void SetSpdX(float x);			//	�I�u�W�F�N�g�̃X�s�[�hx�̐ݒ�
	void SetSpdY(float y);			//	�I�u�W�F�N�g�̃X�s�[�hy�̐ݒ�
	void SetState(int n);			//	�I�u�W�F�N�g�̃X�e�[�g��ݒ�
	int GetState();					//	�I�u�W�F�N�g�̃X�e�[�g���擾
	void Update();					//	�X�V����
	void Render();					//	�`�揈��
};