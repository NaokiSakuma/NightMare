//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Camera.h
//!
//! @brief  �J���������̃w�b�_�t�@�C��
//!
//! @date   2017/04/09
//!
//! @author ���v�ԏ��P
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#pragma once

#include "ObjectBase.h"

class Camera	:public ObjectBase
{
public:
	Camera();	//�R���X�g���N�^
	~Camera();	//�f�X�g���N�^
	void Coordinate(int pos_x, int grp_w);	//���W�ύX
	void CameraMaxPos();					//�X�N���[���̌��E
};
