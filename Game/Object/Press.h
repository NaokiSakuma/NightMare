//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Press.h
//!
//! @brief  �v���X�@�����̃w�b�_�t�@�C��
//!
//! @date   2017/04/08
//!
//! @author ���v�ԏ��P
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#pragma once

#include "..\ObjectBase.h"
class Press : public ObjectBase
{
private:
	static const int PRESS_GRP_W = 64;	//�v���X�@�̕�
	static const int PRESS_GRP_H = 288; //�v���X�@�̍���
	static const int MOVE_COUNT = 120;	//�ړ��J�E���g
	int m_count;	//�J�E���g
public:
	Press(int pos_x, int pos_y);	//�R���X�g���N�^
	~Press();		//�f�X�g���N�^
	void Move();	//�ړ�
};