#include "Burner.h"
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Burner.cpp
//!
//! @brief  �o�[�i�[�̏����̃\�[�X�t�@�C��
//!
//! @date   2017/04/08
//!
//! @author ���v�ԏ��P
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

//----------------------------------------------------------------------
//! @brief �R���X�g���N�^
//!
//! @param[in] �Ȃ�
//----------------------------------------------------------------------
Burner::Burner(int pos_x, int pos_y)
	:m_count(0)
{
	m_handle = new Texture(L"Resources\\Images\\Burner.png");	//�摜
	m_pos_x = pos_x;			//x���W
	m_pos_y = pos_y;			//y���W
	m_grp_x = 0;				//���摜��grp_x
	m_grp_y = 0;				//���摜��grp_y
	m_grp_w = BURNER_GRP_W;		//���摜��grp_w
	m_grp_h = BURNER_GRP_H;		//���摜��grp_h
	m_state = false;
}

//----------------------------------------------------------------------
//! @brief �f�X�g���N�^
//----------------------------------------------------------------------
Burner::~Burner()
{
	delete m_handle;
	m_handle = nullptr;
}

//----------------------------------------------------------------------
//! @brief �΂�����
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Burner::Ignition()
{
	m_count++;
	//����
	if (m_count < STETA_COUNT / 2)
		m_state = false;
	//����
	if (m_count > STETA_COUNT / 2)
		m_state = true;
	//reset
	if (m_count > STETA_COUNT)
		m_count = 0;

}
