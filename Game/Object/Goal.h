//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Goal.h
//!
//! @brief  �S�[�������̃w�b�_�t�@�C��
//!
//! @date   2017/04/10
//!
//! @author ���� ����
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

//	���d�C���N���[�h�̖h�~
#pragma once

//	�w�b�_�t�@�C���̃C���N���[�h
#include "..\ObjectBase.h"

class Goal : public ObjectBase
{
private:
	static const int GOAL_GRP_W = 32;		//	�S�[���摜�̕�
	static const int GOAL_GRP_H = 32;		//	�S�[���摜�̍���
public:
	Goal(int pos_x, int pos_y);				//�R���X�g���N�^
	~Goal();								//�f�X�g���N�^
};
