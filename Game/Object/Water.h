//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Water.h
//!
//! @brief  �������̃w�b�_�t�@�C��
//!
//! @date   2017/04/10
//!
//! @author ���� ����
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

//	���d�C���N���[�h�̖h�~
#pragma once

//	�w�b�_�t�@�C���̃C���N���[�h
#include "..\ObjectBase.h"

class Water : public ObjectBase
{
private:
	static const int WATER_GRP_W = 32;		//	���摜�̕�
	static const int WATER_GRP_H = 16;		//	���摜�̍���
public:
	Water(int pos_x, int pos_y);			//�R���X�g���N�^
	~Water();								//�f�X�g���N�^
};
