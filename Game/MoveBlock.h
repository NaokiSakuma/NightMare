<<<<<<< HEAD
////__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
////! @file   MoveBlock.cpp
////!
////! @brief  ���ރM�~�b�N�̃w�b�_�t�@�C��
////!
////! @date   2017/04/07		
////!
////! @author �n粐^�l
////__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//
////	���d�C���N���[�h�̖h�~
//#pragma once
//
////	�w�b�_�t�@�C���̓ǂݍ���
//#include "GameMain.h"
//#include "ObjectBase.h"
//
////�N���X
//class Moveblock :public ObjectBase
//{
//private:
//	static const int m_block_size = 32;						//1�u���b�N�̃T�C�Y
//	static const int m_pos_y_min = 0;						//�������W�̍ŏ��l
//	static const int m_pos_y_max = m_block_size * 9;		//�������W�̍ő�l
//	Texture* g_gimmickimage;								//���ރM�~�b�N�p�̉摜
//public:
//	Moveblock();											//�R���X�g���N�^
//	~Moveblock();											//�f�X�g���N�^
//	void Move_up_down();									//�㉺�ɓ���
//	void Move_right_left();									//���E�ɓ���
//
//};
=======
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   MoveBlock.cpp
//!
//! @brief  ���ރM�~�b�N�̃w�b�_�t�@�C��
//!
//! @date   2017/04/07		
//!
//! @author �n粐^�l
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

//	���d�C���N���[�h�̖h�~
#pragma once

//	�w�b�_�t�@�C���̓ǂݍ���
#include "ObjectBase.h"

//�N���X
class Moveblock :public ObjectBase
{
private:
	static const int M_BLOCK_SIZE = 32;						//1�u���b�N�̃T�C�Y
	static const int M_BLOCK_GRP_W = M_BLOCK_SIZE * 3;		//grp_w�̃T�C�Y
	static const int M_BLOCK_GRP_H = M_BLOCK_SIZE * 3;		//grp_h�̃T�C�Y
	static const int M_BLOCK_POS_X = M_BLOCK_SIZE * 10;		//pos_x�̃T�C�Y
	static const int m_pos_y_min = 0;						//�������W�̍ŏ��l
	static const int m_pos_y_max = M_BLOCK_SIZE * 9;		//�������W�̍ő�l
	Texture* g_gimmickimage;								//���ރM�~�b�N�p�̉摜
public:
	Moveblock();											//�R���X�g���N�^
	~Moveblock();											//�f�X�g���N�^
	void MoveUpDown();										//�㉺�ɓ���
	
};
>>>>>>> 592c7ff96f3a6235e62b19fc2ccbf2838140ca34
