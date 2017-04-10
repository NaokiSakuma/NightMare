//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Stage.cpp
//!
//! @brief  �X�e�[�W�����̃\�[�X�t�@�C��
//!
//! @date   2017/04/07
//!
//! @author ���v�ԏ��P
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#include "Stage.h"
#include "..\GameMain.h"
#include <fstream>
#include <sstream>
#include <SimpleMath.h>

using namespace std;
using namespace DirectX::SimpleMath;
using namespace DirectX;

//�萔
const float Stage::HALF_UP = 0.5f;

//----------------------------------------------------------------------
//! @brief �R���X�g���N�^
//!
//! @param[in] �Ȃ�
//----------------------------------------------------------------------
Stage::Stage()
	:m_press_count(0)	//�v���X�@�̃J�E���g
	,m_burner_count(0)	//�o�[�i�[�̃J�E���g
	,m_side_press_count(0)//���̃v���X�@�̃J�E���g
{
	m_map_image = new Texture(L"Resources\\Images\\MapChip.png");		//�}�b�v�̉摜
	ImportData("Resources\\map\\map.csv");	//�}�b�v�̓ǂݍ���
	//�I�u�W�F�N�g�p
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			switch (m_map[i][j])
			{
				//�v���X�@�̐���
			case PRESS:
				m_press[m_press_count] = new Press(j * CHIPSIZE, i* CHIPSIZE - CHIPSIZE / 2);
				m_press_count++;
				break;
				//���̃v���X�@�̐���
			case SIDEPRESS:
				m_side_press[m_side_press_count] = new SidePress(j * CHIPSIZE + CHIPSIZE / 2, i* CHIPSIZE);
				m_side_press_count++;
				break;
				//�o�[�i�[�̐���
			case BURNER:
				m_burner[m_burner_count] = new Burner(j * CHIPSIZE, i * CHIPSIZE - CHIPSIZE / 2);
				m_burner_count++;
				break;
				//�v���C���[�̐���
			case PLAYER:
				m_player = new Player(j * CHIPSIZE, i * CHIPSIZE);
				break;
			default:
				break;
			}
		}
	}
	//�J����
	m_camera = new Camera();
}

//----------------------------------------------------------------------
//! @brief �f�X�g���N�^
//----------------------------------------------------------------------
Stage::~Stage()
{
	delete m_map_image;		//�摜
	m_map_image = nullptr;
	for (int i = 0; i < m_press_count; i++)
	{
		delete m_press[i];	//�v���X�@
		m_press[i] = nullptr;
	}
	for (int i = 0; i < m_side_press_count; i++)
	{
		delete m_side_press[i];	//���̃v���X�@
		m_side_press[i] = nullptr;
	}
	for (int i = 0; i < m_burner_count; i++)
	{
		delete m_burner[i];	//�o�[�i�[
		m_burner[i] = nullptr;
	}
	delete m_player;	//�v���C���[
	m_player = nullptr;
	delete m_camera;	//�J����
	m_camera = nullptr;
}

//----------------------------------------------------------------------
//! @brief �X�e�[�W�̕`��
//!
//! @param[in] �t�@�C���̖��O
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Stage::DrawStage()
{
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			//�ǂ̕`��
			switch (m_map[i][j])
			{
			case BACKGROUND :
				DrawSprite(0, 0, CHIPSIZE, CHIPSIZE, i, j);
				break;
				//��
			case WALL:
				DrawSprite(CHIPSIZE, 0 , CHIPSIZE * WALL, CHIPSIZE, i, j);
				break;
				//�����̕�
			case HORIZONTALWALL:
				DrawSprite(CHIPSIZE * WALL, 0 ,
					CHIPSIZE * HORIZONTALWALL, CHIPSIZE, i, j);
				break;
				//�c���̕�
			case VERTICALWALL:
				DrawSprite(CHIPSIZE * HORIZONTALWALL, 0,
					CHIPSIZE * VERTICALWALL , CHIPSIZE , i, j);
				break;
				//��
			case WATER:
				break;
				//�v���X�@
			case PRESS:
				DrawSprite(0, 0, CHIPSIZE, CHIPSIZE, i, j);
				break;
				//���̃v���X�@
			case SIDEPRESS:
				DrawSprite(0, 0, CHIPSIZE, CHIPSIZE, i, j);
				break;
				//�o�[�i�[
			case BURNER:
				DrawSprite(0, 0, CHIPSIZE, CHIPSIZE, i, j);
				break;
				//�v���C���[
			case PLAYER:
				DrawSprite(0, 0, CHIPSIZE, CHIPSIZE, i, j);
				break;
			default:
				break;
			}

		}
	}

}

//----------------------------------------------------------------------
//! @brief �A�b�v�f�[�g
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Stage::Update()
{
	//�v���X�@
	for (int i = 0; i < m_press_count; i++)
	{
		m_press[i]->Update();	//���W�ύX
		m_press[i]->Move();		//�ړ�
	}
	//�o�[�i�[
	for (int i = 0; i < m_burner_count; i++)
	{
		m_burner[i]->Ignition();	//�΂�����
	}
	//���̃v���X�@
	for (int i = 0; i < m_side_press_count; i++)
	{
		m_side_press[i]->Update();	//���W�ύX
		m_side_press[i]->Move();	//�ړ�
	}
	//�J����
	m_camera->Coordinate(m_player->GetPosX(),  m_player->GetGrpW());	//���W�ύX
	m_camera->CameraMaxPos();	//�X�N���[���̌��E
	//�v���C���[
	m_player->Move();	//�ړ�
	m_player->Update(); //���W�ύX
	MapDownDecison();	//�}�b�v�`�b�v�Ƃ̉��̓����蔻��
	MapSideDecison();	//�}�b�v�`�b�v�Ƃ̉��̓����蔻��
	MapJumpDecison();	//�}�b�v�`�b�v�Ƃ̏�̓����蔻��
	//�v���X�@�ƃv���C���[�̓����蔻��
	CollisionPress();
	//���̃v���X�@
	CollisionSidePress();
	m_press_flag = false;	//�v���X����Ă��Ȃ�
}

//----------------------------------------------------------------------
//! @brief �I�u�W�F�N�g�̕`��
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Stage::ObjectDraw()
{
	//�v���X�@
	for (int i = 0; i < m_press_count; i++)
		m_press[i]->Render(m_camera->GetPosX());
	//���̃v���X�@
	for (int i = 0; i < m_side_press_count; i++)
		m_side_press[i]->Render(m_camera->GetPosX());

	//�o�[�i�[
	for (int i = 0; i < m_burner_count; i++)
	{
		//�o�[�i�[�������Ă��鎞
		if (m_burner[i]->GetState() == true)
			m_burner[i]->Render(m_camera->GetPosX());
	}
	//�v���C���[
	m_player->Render(m_camera->GetPosX());

}


//----------------------------------------------------------------------
//! @brief csv�t�@�C���̓ǂݍ���
//!
//! @param[in] �t�@�C���̖��O
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Stage::ImportData(string filename)
{
	ifstream ifs(filename);
	string str;
	int i;
	if (!ifs)
	{
		for (i = 0; i < MAX_TIP; i++)
		{
			m_map[i / MAP_WIDTH][i % MAP_WIDTH] = 0;
		}
	}

	i = 0;
	while (getline(ifs, str))
	{
		string token;
		istringstream stream(str);

		//��s�̂����A������ƃR���}�𕪊�����
		while (getline(stream, token, ','))
		{
			//���ׂĕ�����Ƃ��ēǂݍ��܂�邽��
			//���l�͕ϊ����K�v
			m_map[i / MAP_WIDTH][i % MAP_WIDTH] = atoi(token.c_str());
			i++;
		}
	}

}

//----------------------------------------------------------------------
//! @brief �X�v���C�g�̕`��
//!
//! @param[in] �摜��AABB�A�����A��
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Stage::DrawSprite(int grp_x, int grp_y, int grp_w, int grp_h, int i,int j)
{
	RECT rect = { grp_x,grp_y,grp_w,grp_h };
	//�X�N���[���ɑΉ�
	g_spriteBatch->Draw(m_map_image->m_pTexture, Vector2(CHIPSIZE * j - (m_camera->GetPosX() - SCREEN_WIDTH / 2), CHIPSIZE * i),
		&rect, Colors::White, 0.0f, Vector2(0, 0), Vector2(1, 1));

}

//----------------------------------------------------------------------
//! @brief �}�b�v�`�b�v�Ƃ̉��̓����蔻��
//!
//! @param[in] 
//!
//! @return �Ȃ�
//----------------------------------------------------------------------

void Stage::MapDownDecison()
{
	int map_x;
	int map_y;
	//����
	map_x = floor((m_player->GetPosX() + SHIFTED_POS) / CHIPSIZE);
	map_y = floor((m_player->GetPosY() + m_player->GetGrpH()) / CHIPSIZE);
	if ((map_x >= 0 && map_x < MAP_WIDTH) && (map_y >= 0 && map_y < MAP_HEIGHT))
	{
		//�}�b�v�`�b�v���ǂ̎�
		if (m_map[map_y][map_x] == WALL)
		{
			if (m_player->GetPosY() + m_player->GetGrpH() > map_y * CHIPSIZE)
			{
				//�v���C���[�����ʂ̏��
				if (PLAYER_DEFAULT)
					m_player->SetPosY((map_y - 1)*CHIPSIZE);
				//�v���C���[�������̏��
				else if (PLAYER_HORIZONTAL)
					m_player->SetPosY(((float)map_y - HALF_UP)*CHIPSIZE);
				//�v���C���[���c���̏��
				else if(PLAYER_VERTICAL)
					m_player->SetPosY((map_y - 1)*CHIPSIZE);
				m_player->SetSpdY(0);
				m_player->Ground();
			}

		}
		//�}�b�v�`�b�v���c���̕ǂ̎�
		if (m_map[map_y][map_x] == VERTICALWALL)
		{
			if (m_player->GetPosY() + m_player->GetGrpH() > map_y * CHIPSIZE)
			{
				//�v���C���[�����ʂ̏��
				if (PLAYER_DEFAULT)
				{
					m_player->SetPosY((map_y - 1)*CHIPSIZE);
					m_player->SetSpdY(0);
					m_player->Ground();
				}
				//�v���C���[�������̏��
				else if (PLAYER_HORIZONTAL)
				{
					m_player->SetPosY(((float)map_y - HALF_UP)*CHIPSIZE);
					m_player->SetSpdY(0);
					m_player->Ground();
				}
			}

		}

	}
	//�E��
	map_x = floor((m_player->GetPosX() + m_player->GetGrpW() - SHIFTED_POS) / CHIPSIZE);
	map_y = floor((m_player->GetPosY() + m_player->GetGrpH()) / CHIPSIZE);
	if ((map_x >= 0 && map_x < MAP_WIDTH) && (map_y >= 0 && map_y < MAP_HEIGHT))
	{
		//�}�b�v�`�b�v���ǂ̎�
		if (m_map[map_y][map_x] == WALL)
		{
			if (m_player->GetPosY() + m_player->GetGrpH() > map_y * CHIPSIZE)
			{
				//�v���C���[�����ʂ̏��
				if (PLAYER_DEFAULT)
					m_player->SetPosY((map_y - 1) * CHIPSIZE);
				//�v���C���[�������̏��
				else if (PLAYER_HORIZONTAL)
					m_player->SetPosY(((float)map_y - HALF_UP) * CHIPSIZE);
				//�v���C���[���c���̏��
				if (PLAYER_VERTICAL)
					m_player->SetPosY((map_y - 1) * CHIPSIZE);
				m_player->SetSpdY(0);
				m_player->Ground();
			}
		}
		//�}�b�v�`�b�v���c���̕ǂ̎�
		if (m_map[map_y][map_x] == VERTICALWALL)
		{
			if (m_player->GetPosY() + m_player->GetGrpH() > map_y * CHIPSIZE)
			{
				//�v���C���[�����ʂ̏��
				if (PLAYER_DEFAULT)
				{
					m_player->SetPosY((map_y - 1) * CHIPSIZE);
					m_player->SetSpdY(0);
					m_player->Ground();
				}
				//�v���C���[�������̏��
				else if (PLAYER_HORIZONTAL)
				{
					m_player->SetPosY(((float)map_y - HALF_UP) * CHIPSIZE);
					m_player->SetSpdY(0);
					m_player->Ground();
				}
			}
		}
	}
}
//----------------------------------------------------------------------
//! @brief �}�b�v�`�b�v�Ƃ̉��̓����蔻��
//!
//! @param[in] m_player
//!
//! @return �Ȃ�
//----------------------------------------------------------------------

void Stage::MapSideDecison()
{
	int map_x;
	int map_y;
	//�����S
	map_x = (int)floor((m_player->GetPosX() + m_player->GetGrpW()) / CHIPSIZE);
	map_y = (int)floor((m_player->GetPosY() + m_player->GetGrpH() / 2) / CHIPSIZE);
	if ((map_x >= 0 && map_x < MAP_WIDTH) && (map_y >= 0 && map_y < MAP_HEIGHT))
	{
		//�}�b�v�`�b�v���ǂ̎�
		if (m_map[map_y][map_x] == WALL)
		{
			if (m_player->GetPosX() + m_player->GetGrpW() >= map_x * CHIPSIZE)
			{
				//�v���C���[�����ʂ̏��
				if (PLAYER_DEFAULT)
					m_player->SetPosX((map_x - 1)* CHIPSIZE);
				//�v���C���[�������̏��
				if (PLAYER_HORIZONTAL)
					m_player->SetPosX((map_x - 1)* CHIPSIZE);
				//�v���C���[���c���̏��
				else if (PLAYER_VERTICAL)
					m_player->SetPosX(((float)map_x - HALF_UP)* CHIPSIZE);
				m_player->SetSpdX(0);
			}
		}
		//�}�b�v�`�b�v�������̕ǂ̎�
		if (m_map[map_y][map_x] == HORIZONTALWALL)
		{
				if (m_player->GetPosX() + m_player->GetGrpW() >= map_x * CHIPSIZE)
				{
					//�v���C���[�����ʂ̏��
					if (PLAYER_DEFAULT)
						m_player->SetPosX((map_x - 1)* CHIPSIZE);
					//�v���C���[���c���̏��
					else if (PLAYER_VERTICAL)
						m_player->SetPosX(((float)map_x - HALF_UP)* CHIPSIZE);
					m_player->SetSpdX(0);
				}
		}
		//�}�b�v�`�b�v���c���̕ǂ̎�
		if (m_map[map_y][map_x] == VERTICALWALL)
		{
			if (m_player->GetPosX() + m_player->GetGrpW() >= map_x * CHIPSIZE)
			{
				//�v���C���[���c���̏��
				if (PLAYER_VERTICAL)
					m_player->SetPosX(((float)map_x - HALF_UP)* CHIPSIZE);
				m_player->SetSpdX(0);
			}
		}

	}
	//�E���S
	map_x = (int)floor((m_player->GetPosX()) / CHIPSIZE);
	map_y = (int)floor((m_player->GetPosY() + m_player->GetGrpH() / 2) / CHIPSIZE);
	if ((map_x >= 0 && map_x < MAP_WIDTH) && (map_y >= 0 && map_y < MAP_HEIGHT))
	{
		//�}�b�v�`�b�v���ǂ̎�
		if (m_map[map_y][map_x] == WALL)
		{
			if (m_player->GetPosX() <= map_x* CHIPSIZE + CHIPSIZE)
			{
				m_player->SetPosX((map_x + 1)* CHIPSIZE);
				m_player->SetSpdX(0);
				m_press_flag = true;
			}
		}
		//�}�b�v�`�b�v�������̕ǂ̎�
		if (m_map[map_y][map_x] == HORIZONTALWALL)
		{
			if (m_player->GetPosX() <= map_x* CHIPSIZE + CHIPSIZE)
			{
				//�v���C���[�����ʂ̏��
				if (PLAYER_DEFAULT)
					m_player->SetPosX((map_x + 1)* CHIPSIZE);
				//�v���C���[�������̏��
				if (PLAYER_VERTICAL)
					m_player->SetPosX((map_x + 1)* CHIPSIZE);
				m_player->SetSpdX(0);
			}
		}
		//�}�b�v�`�b�v���c���̕ǂ̎�
		if (m_map[map_y][map_x] == VERTICALWALL)
		{
			if (m_player->GetPosX() <= map_x* CHIPSIZE + CHIPSIZE)
			{
				//�v���C���[���c���̏��
				if (PLAYER_VERTICAL)
					m_player->SetPosX((map_x - HALF_UP)* CHIPSIZE);
				m_player->SetSpdX(0);
			}
		}
	}
}
//----------------------------------------------------------------------
//! @brief �}�b�v�`�b�v�Ƃ̏�̓����蔻��
//!
//! @param[in] m_player
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Stage::MapJumpDecison()
{
	int map_x;
	int map_y;
	//����
	map_x = ((int)floor((m_player->GetPosX() + SHIFTED_POS / 2) / CHIPSIZE));
	map_y = ((int)floor(m_player->GetPosY() / CHIPSIZE));
	//�z������`�F�b�N
	if ((map_x >= 0 && map_x < MAP_WIDTH && map_y >= 0 && map_y < MAP_HEIGHT))
	{
		//�}�b�v�`�b�v���ǂ̎�
		if (m_map[map_y][map_x] == WALL)
		{
			//����
			if ((m_player->GetPosY()) >(map_y * CHIPSIZE))
			{
				m_player->SetPosY((map_y + 1) * CHIPSIZE);
				m_player->SetSpdY(0);
			}
		}
		//�}�b�v�`�b�v�������̕ǂ̎�
		if (m_map[map_y][map_x] == HORIZONTALWALL)
		{
			//����
			if ((m_player->GetPosY()) >(map_y * CHIPSIZE))
			{
				//�v���C���[�����ʂ̏��
				if (PLAYER_DEFAULT)
					m_player->SetPosY((map_y + 1) * CHIPSIZE);
				//�v���C���[�������̏��
				else if (PLAYER_HORIZONTAL)
					m_player->SetPosY(((float)map_y + HALF_UP) * CHIPSIZE);
				m_player->SetSpdY(0);
			}
		}

	}
	//�E��
	map_x = ((int)floor((m_player->GetPosX() + m_player->GetGrpW() - SHIFTED_POS / 2) / CHIPSIZE));
	map_y = ((int)floor(m_player->GetPosY() / CHIPSIZE));
	//�z������`�F�b�N
	if ((map_x >= 0 && map_x < MAP_WIDTH && map_y >= 0 && map_y < MAP_HEIGHT))
	{
		//�}�b�v�`�b�v���ǂ̎�
		if (m_map[map_y][map_x] == WALL)
		{
			//����
			if ((m_player->GetPosY()) >(map_y * CHIPSIZE))
			{
				m_player->SetPosY((map_y + 1)* CHIPSIZE);
				m_player->SetSpdY(0);
			}
		}
		//�}�b�v�`�b�v�������̕ǂ̎�
		if (m_map[map_y][map_x] == HORIZONTALWALL)
		{
			//����
			if ((m_player->GetPosY()) >(map_y * CHIPSIZE))
			{
				//�v���C���[�����ʂ̏��
				if (PLAYER_DEFAULT)
					m_player->SetPosY((map_y + 1)* CHIPSIZE);
				//�v���C���[�������̏��
				else if (PLAYER_HORIZONTAL)
					m_player->SetPosY(((float)map_y + HALF_UP)* CHIPSIZE);
				m_player->SetSpdY(0);
			}
		}
	}
}


//----------------------------------------------------------------------
//! @brief �v���X�@�ƃv���C���[�̓����蔻��
//!
//! @param[in] �Ȃ�
//!
//! @return �������Ă��邩�ǂ���
//----------------------------------------------------------------------
void Stage::CollisionPress()
{
	for (int i = 0; i < m_press_count; i++)
	{
		//��
		if (m_player->GetPosY() > m_press[i]->GetPosY() &&
			m_press[i]->GetPosY() + m_press[i]->GetGrpH() > m_player->GetPosY() + m_player->GetGrpH() &&
			m_player->GetPosX() + m_player->GetGrpW() > m_press[i]->GetPosX() &&
			m_player->GetPosX() < m_press[i]->GetPosX())
		{
			m_player->SetPosX(m_press[i]->GetPosX() - m_player->GetGrpW());	//���W
			m_player->SetSpdX(0);	//�X�s�[�h
		}
		//�E
		if (m_player->GetPosY() > m_press[i]->GetPosY() &&
			m_press[i]->GetPosY() + m_press[i]->GetGrpH() > m_player->GetPosY() + m_player->GetGrpH() &&
			m_player->GetPosX() < m_press[i]->GetPosX() + m_press[i]->GetGrpW() &&
			m_player->GetPosX() + m_player->GetGrpW() > m_press[i]->GetPosX() + m_press[i]->GetGrpW())
		{
			m_player->SetPosX(m_press[i]->GetPosX() + m_press[i]->GetGrpW());	//���W
			m_player->SetSpdX(0);	//�X�s�[�h
		}
		//��
		else if (m_player->GetPosX() + m_player->GetGrpW() > m_press[i]->GetPosX() &&
			m_press[i]->GetPosX() + m_press[i]->GetGrpW() > m_player->GetPosX() &&
			m_press[i]->GetPosY() + m_press[i]->GetGrpH() > m_player->GetPosY())
		{
			m_player->SetPosY(m_press[i]->GetPosY() + m_press[i]->GetGrpH());	//���W
			m_player->SetSpdY(0);	//�X�s�[�h
			//�W�����v���Ă��Ȃ��Ȃ�
			if (!m_player->GetJump())
				m_player->ChangePlayerH();	//�ׂ�
		}
	}
}

//----------------------------------------------------------------------
//! @brief ���̃v���X�@�ƃv���C���[�̓����蔻��
//!
//! @param[in] �Ȃ�
//!
//! @return �������Ă��邩�ǂ���
//----------------------------------------------------------------------
void Stage::CollisionSidePress()
{
	for (int i = 0; i < m_side_press_count; i++)
	{
		//��
		if (m_player->GetPosX() + m_player->GetGrpW() > m_side_press[i]->GetPosX() &&
			m_player->GetPosY() > m_side_press[i]->GetPosY() &&
			m_side_press[i]->GetPosY() + m_side_press[i]->GetGrpH() >= m_player->GetPosY() + m_player->GetGrpH())
		{
			m_player->SetPosX(m_side_press[i]->GetPosX() - m_player->GetGrpW());	//���W
			m_player->SetSpdX(0);	//�X�s�[�h
			if(m_press_flag)
			m_player->ChangePlayerW();	//�ׂ�
		}
		//��
		if (m_player->GetPosX() + m_player->GetGrpW() > m_side_press[i]->GetPosX() &&
			m_side_press[i]->GetPosX() + m_side_press[i]->GetGrpW() > m_player->GetPosX() &&
			m_player->GetPosY() + m_player->GetGrpH() > m_side_press[i]->GetPosY())
		{
			m_player->SetPosY(m_side_press[i]->GetPosY() - m_player->GetGrpH());
			m_player->SetSpdY(0);
			m_player->Ground();
		}
	}
}

//----------------------------------------------------------------------
//! @brief�@�v���C���[�ƃo�[�i�[�Ƃ̓����蔻��
//!
//! @param[in] �Ȃ�
//!
//! @return false:�������Ă��Ȃ�, true:�������Ă���
//----------------------------------------------------------------------
bool Stage::CollisionBurner()
{
	//	�Z�`�ł̓����蔻��
	if (
		(m_player->GetPosX() <= m_burner[m_burner_count - 1]->GetPosX() + m_burner[m_burner_count - 1]->GetGrpW()) &&
		(m_player->GetPosX() + m_player->GetGrpW() >= m_burner[m_burner_count - 1]->GetPosX()) &&
		(m_player->GetPosY() <= m_burner[m_burner_count - 1]->GetPosY() + m_burner[m_burner_count - 1]->GetGrpH()) &&
		(m_player->GetPosY() + m_player->GetGrpH() >= m_burner[m_burner_count - 1]->GetPosY())
		)
	{
		return true;
	}

	return false;
}
