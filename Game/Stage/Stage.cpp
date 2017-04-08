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
#include <fstream>
#include <sstream>
#include <SimpleMath.h>

using namespace std;
using namespace DirectX::SimpleMath;
using namespace DirectX;

//----------------------------------------------------------------------
//! @brief �R���X�g���N�^
//!
//! @param[in] �Ȃ�
//----------------------------------------------------------------------
Stage::Stage()
	:m_press_count(0)	//�J�E���g
{
	m_map_image = new Texture(L"Resources\\Images\\PongImage.png");		//�}�b�v�̉摜
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
				m_press[m_press_count] = new Press(j * CHIPSIZE, i* CHIPSIZE);
				m_press_count++;
				break;
			default:
				break;
			}
		}
	}
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
				//��
			case WALL:
				DrawSprite(0, 0, CHIPSIZE, CHIPSIZE, i, j);
				break;
				//�����̕�
			case HORIZONTALWALL:
				DrawSprite(0, 0, CHIPSIZE, CHIPSIZE / 2, i, j);
				break;
				//�c���̕�
			case VERTICALWALL:
				DrawSprite(0, 0, CHIPSIZE / 2, CHIPSIZE, i, j);
				break;
				//��
			case WATER:
				break;
				//�v���X�@
			case PRESS:
				for (int k = 0; k < m_press_count; k++)
				m_press[k]->Render();
				break;
			default:
				break;
			}
			{
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
	g_spriteBatch->Draw(m_map_image->m_pTexture, Vector2(CHIPSIZE * j, CHIPSIZE * i),
		&rect, Colors::White, 0.0f, Vector2(0, 0), Vector2(1, 1));

}