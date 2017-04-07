//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Stage.h
//!
//! @brief  �X�e�[�W�����̃w�b�_�t�@�C��
//!
//! @date   2017/04/07
//!
//! @author ���v�ԏ��P
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#pragma once

//�C���N���[�h
#include <string>
#include "Game\ObjectBase.h"
//�N���X�̌Ăяo��
class Texture;

class Stage final :public ObjectBase
{
private:
	static const int  MAP_WIDTH = 20;	//�}�b�v�̉���
	static const int MAP_HEIGHT = 15;	//�}�b�v�̏c��
	static const int MAX_TIP = 300;		//�}�b�v�`�b�v�̐�
	int g_map[MAP_HEIGHT][MAP_WIDTH];	//�}�b�v
public:
	Stage();			//�R���X�g���N�^
	~Stage();			//�f�X�g���N�^
	void DrawStage();	//�X�e�[�W�̕`��
	void importData(std::string filename);	//csv�t�@�C������̓ǂݍ���

};