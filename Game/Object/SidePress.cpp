//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Press.cpp
//!
//! @brief  �v���X�@�����̃\�[�X�t�@�C��
//!
//! @date   2017/04/08
//!
//! @author �n粐^�l
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//�w�b�_�t�@�C���̃C���N���[�h
#include "SidePress.h"

//----------------------------------------------------------------------
//! @brief �R���X�g���N�^
//!
//! @param[in] x���W�Ay���W
//----------------------------------------------------------------------
SidePress::SidePress(int pos_x, int pos_y)
	:m_count(0)			//�J�E���g
{
	m_handle = new Texture(L"Resources\\Images\\Press.png");	//�摜
	m_pos_x = pos_x;											//x���W
	m_pos_y = pos_y;											//y���W
	m_grp_x = 0;												//���摜��grp_x
	m_grp_y = 0;												//���摜��grp_y
	m_grp_w = SIDEPRESS_GRP_W;									//���摜��grp_w				
	m_grp_h = SIDEPRESS_GRP_H;									//���摜��grp_h				
}

//----------------------------------------------------------------------
//! @brief �f�X�g���N�^
//----------------------------------------------------------------------
SidePress::~SidePress()
{
	delete m_handle;	//�摜
}

//----------------------------------------------------------------------
//! @brief �ړ�
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void SidePress::Move()
{

	m_count++;

	if (m_state % 2 == 0) //�X�e�C�g�������Ȃ�E�Ɉړ�
	{
		//���ړ�
		if (m_count < CHANGE_MOVE_COUNT / 2)
			m_spd_x = 1;
		//��ړ�
		if (m_count > CHANGE_MOVE_COUNT / 2)
			m_spd_x = -1;
		//reset
		if (m_count == CHANGE_MOVE_COUNT)
			m_count = 0;
	}
	else				  //�X�e�C�g����Ȃ獶�Ɉړ�
	{
		//���ړ�
		if (m_count < CHANGE_MOVE_COUNT / 2)
			m_spd_x = -1;
		//��ړ�
		if (m_count > CHANGE_MOVE_COUNT / 2)
			m_spd_x = 1;
		//reset
		if (m_count == CHANGE_MOVE_COUNT)
			m_count = 0;
	}
	

}