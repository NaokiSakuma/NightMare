//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   SidePress.cpp
//!
//! @brief  ���ɋ��ރM�~�b�N�̃w�b�_�t�@�C��
//!
//! @date   2017/04/08
//!
//! @author �n粐^�l
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

//	���d�C���N���[�h�̖h�~
#pragma once

//	�w�b�_�t�@�C���̓ǂݍ���
#include "..\ObjectBase.h"
//�N���X
class SidePress : public ObjectBase
{
private:
	static const int SIDEPRESS_GRP_W = 128;	//�v���X�@�̕�
	static const int SIDEPRESS_GRP_H = 64; //�v���X�@�̍���
	static const int CHANGE_MOVE_COUNT = 120;//�ړ��̐؂�ւ��̃J�E���g
	int m_count;						//�J�E���g

public:
	SidePress(int pos_x, int pos_y);	//�R���X�g���N�^
	~SidePress();						//�f�X�g���N�^
	void Move();						//�ړ�
};