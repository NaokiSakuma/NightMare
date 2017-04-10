//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Player.h
//!
//! @brief  �v���C���[�����̃w�b�_�t�@�C��
//!
//! @date   2017/04/09
//!
//! @author ���v�ԏ��P
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
#pragma once

#include "ObjectBase.h"

class Player :public ObjectBase
{
private:
	static const int PLAYER_GRP = 32;	//���摜��GRP
	static const int PLAYER_GRAVITY = 1;//�d��
	static const float PLAYER_HALF_GRAVITY; //�����̏d��
	static const int PLAYER_MOVE_POW = 3;//�ړ���
	static const int PLAYER_JUMP_POW = -15;//�W�����v��
	bool m_jump_flag;	//�W�����v
public:
	Player(int pos_x, int pos_y);	//�R���X�g���N�^
	~Player();			//�f�X�g���N�^
	void Move();		//�ړ�
	void Ground();		//�n�ʂɂ��Ă���
	void ChangePlayer();//�v���C���[�̑傫����ς���
};
