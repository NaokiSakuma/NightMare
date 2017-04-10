//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Goal.cpp
//!
//! @brief  �S�[���̏����̃\�[�X�t�@�C��
//!
//! @date   2017/04/10
//!
//! @author ���� ����
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

//	�w�b�_�t�@�C���̃C���N���[�h
#include "Goal.h"

//----------------------------------------------------------------------
//! @brief �R���X�g���N�^
//!
//! @param[in] �Ȃ�
//----------------------------------------------------------------------
Goal::Goal(int pos_x, int pos_y)
{
	m_handle = new Texture(L"Resources\\Images\\goal.png");	//�摜
	m_pos_x = pos_x;			//x���W
	m_pos_y = pos_y;			//y���W
	m_grp_x = 0;				//���摜��grp_x
	m_grp_y = 0;				//���摜��grp_y
	m_grp_w = GOAL_GRP_W;		//���摜��grp_w
	m_grp_h = GOAL_GRP_H;		//���摜��grp_h
	m_state = false;
}

//----------------------------------------------------------------------
//! @brief �f�X�g���N�^
//----------------------------------------------------------------------
Goal::~Goal()
{
	delete m_handle;
	m_handle = nullptr;
}