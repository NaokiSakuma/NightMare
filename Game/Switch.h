//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Switch.cpp
//!
//! @brief  �X�C�b�`�̃w�b�_�t�@�C��
//!
//! @date   2017/04/09	
//!
//! @author �n粐^�l
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

//	���d�C���N���[�h�̖h�~
#pragma once

//	�w�b�_�t�@�C���̓ǂݍ���
#include "ObjectBase.h"

//�N���X
class Switch :public ObjectBase
{
private:
	static const int M_SWTICH_GRP = 32;
	static const int M_ONSWTICH_GRP = 64;
public:
	Switch(int pos_x, int pos_y);
	~Switch();
	void Swtiching();
};