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
#include "..\Object\SidePress.h"
#include "..\Object\Burner.h"
#include "..\Object\Water.h"
#include "..\Object\Goal.h"
#include "..\Object\SidePress.h"
#include "..\Player.h"
#include "..\Camera.h"

#define PLAYER_DEFAULT (m_player->GetGrpH() == CHIPSIZE && m_player->GetGrpW() == CHIPSIZE)			//���ʂ̏��
#define PLAYER_VERTICAL (m_player->GetGrpH() == CHIPSIZE && m_player->GetGrpW() == CHIPSIZE / 2)	//�c��
#define PLAYER_HORIZONTAL (m_player->GetGrpH() == CHIPSIZE / 2 && m_player->GetGrpW() == CHIPSIZE)	//����
//�N���X�̌Ăяo��
class Texture;

//enum
enum Map
{
	NONE,			//�����Ȃ�
	BACKGROUND,		//�w�i
	WALL,			//��
	HORIZONTALWALL,	//�����̕�
	VERTICALWALL,	//�c���̕�
	WATER,			//��
	PRESS,			//�v���X�@
	SIDEPRESS,		//���̃v���X�@
	BURNER,			//�o�[�i�[
	PLAYER,			//�v���C���[	
	GOAL,			//�S�[��
};

class Stage 
{
private:
	static const int  MAP_WIDTH = 90;		//�}�b�v�̉���
	static const int MAP_HEIGHT = 15;		//�}�b�v�̏c��
	static const int MAX_TIP = 1350;		//�}�b�v�`�b�v�̐�
	static const int CHIPSIZE = 32;			//�}�b�v�`�b�v�̑傫��
	static const int MAX_PRESS_NUM = 5;		//�v���X�@�̐�
	static const int MAX_BURNER_NUM = 5;	//�o�[�i�[�̐�
	static const int MAX_WATER_NUM = 5;		//���̃I�u�W�F�N�g��
	static const int SHIFTED_POS = 10;		//���W���Y����
	static const int SCREEN_WIDTH = 640;	//��ʂ̕�
	static const float HALF_UP;				//�����グ��
	int m_map[MAP_HEIGHT][MAP_WIDTH];		//�}�b�v
	Texture* m_map_image;					//�}�b�v�̉摜
	Press* m_press[MAX_PRESS_NUM];			//�v���X�@
	Burner* m_burner[MAX_BURNER_NUM];		//�o�[�i�[
	Water* m_water[MAX_WATER_NUM];			//��
	Goal* m_goal;							//�S�[��
	SidePress* m_side_press[MAX_PRESS_NUM];//���̃v���X�@
	Player* m_player;						//�v���C���[
	Camera* m_camera;						//�J����
	int m_press_count;						//�v���X�@�̃J�E���g
	int m_burner_count;						//�o�[�i�[�̃J�E���g
	int m_water_count;						//���̃I�u�W�F�N�g�̃J�E���g
	int m_side_press_count;					//���̃v���X�@�̃J�E���g
	void ImportData(std::string filename);	//csv�t�@�C������̓ǂݍ���
public:
	Stage();								//�R���X�g���N�^
	~Stage();								//�f�X�g���N�^
	void DrawStage();						//�X�e�[�W�̕`��
	void Update();							//�A�b�v�f�[�g
	void ObjectDraw();						//�I�u�W�F�N�g�̕`��
	void DrawSprite(int grp_x, int grp_y, int grp_w, int grp_h, int i, int j);	//�X�v���C�g�̕`��
	void MapDownDecison();					//�}�b�v�`�b�v�Ƃ̉��̓����蔻��
	void MapSideDecison();					//�}�b�v�`�b�v�Ƃ̉��̓����蔻��
	void MapJumpDecison();					//�}�b�v�`�b�v�Ƃ̏�̓����蔻��
	bool CollisionPress();					//�v���X�@�ƃv���C���[�̓����蔻��
	bool CollisionBurner(int i);			//�o�[�i�[�ƃv���C���[�̓����蔻��
	bool CollisionWater(int i);				//���ƃv���[���[�Ƃ̓����蔻��
	bool CollisionGoal();				//�S�[���ƃv���[���[�Ƃ̓����蔻��
};