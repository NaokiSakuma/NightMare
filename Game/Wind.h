//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Wind.cpp
//!
//! @brief  �X�C�b�`�̃w�b�_�t�@�C��
//!
//! @date   2017/04/10
//!
//! @author �n粐^�l
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

//	���d�C���N���[�h�̖h�~
#pragma once

//	�w�b�_�t�@�C���̓ǂݍ���
#include "ObjectBase.h"

//�N���X
class Wind : public ObjectBase
{
private:
	static const int M_WIND_GRP = 32;
	
public:
	Wind(int pos_x, int pos_y);
	~Wind();
};