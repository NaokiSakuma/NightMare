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
#include "..\ObjectBase.h"
#include "..\Object\Press.h"
//�N���X�̌Ăяo��
class Texture;

//enum
enum Map
{
	NONE,			//�����Ȃ�
	WALL,			//��
	HORIZONTALWALL,	//�����̕�
	VERTICALWALL,	//�c���̕�
	WATER,			//��
	PRESS,			//�v���X�@
};

class Stage 
{
private:
	static const int  MAP_WIDTH = 20;	//�}�b�v�̉���
	static const int MAP_HEIGHT = 15;	//�}�b�v�̏c��
	static const int MAX_TIP = 300;		//�}�b�v�`�b�v�̐�
	static const int CHIPSIZE = 32;		//�}�b�v�`�b�v�̑傫��
	static const int MAX_PRESS_NUM = 3;	//�v���X�@�̐�
	int m_map[MAP_HEIGHT][MAP_WIDTH];	//�}�b�v
	Texture* m_map_image;				//�}�b�v�̉摜
	void ImportData(std::string filename);	//csv�t�@�C������̓ǂݍ���
	Press* m_press[MAX_PRESS_NUM];		//�v���X�@
	int m_press_count;					//�J�E���g
public:
	Stage();			//�R���X�g���N�^
	~Stage();			//�f�X�g���N�^
	void DrawStage();	//�X�e�[�W�̕`��
	void Update();		//�A�b�v�f�[�g
	void DrawSprite(int grp_x, int grp_y, int grp_w, int grp_h, int i, int j);	//�X�v���C�g�̕`��
};