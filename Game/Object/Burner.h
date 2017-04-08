//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Burner.h
//!
//! @brief  �o�[�i�[�̏����̃w�b�_�t�@�C��
//!
//! @date   2017/04/08
//!
//! @author ���v�ԏ��P
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#pragma once

#include "..\ObjectBase.h"

class Burner : public ObjectBase
{
private:
	static const int BURNER_GRP_W = 64;
	static const int BURNER_GRP_H = 288;
	static const int STETA_COUNT = 120;
	int m_count; //�J�E���g
public:
	Burner(int pos_x, int pos_y);	//�R���X�g���N�^
	~Burner();			//�f�X�g���N�^
	void Ignition();	//�΂�����
};
