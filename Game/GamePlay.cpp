//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GamePlay.cpp
//!
//! @brief  �Q�[���v���C�����̃\�[�X�t�@�C��
//!
//! @date   2017/04/07		
//!
//! @author ���� ����
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include "GameMain.h"
#include "GamePlay.h"

using namespace DirectX::SimpleMath;
using namespace DirectX;
using namespace std;
//�O���[�o���ϐ��������������������������������������������������������������|

//�֐��̒�`�����������������������������������������������������������������|
//----------------------------------------------------------------------
//! @brief �v���C�V�[���̃R���X�g���N�^
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
Play::Play()
{
	m_stage = new Stage;	//�X�e�[�W
	m_moveblock = new Moveblock;	//�㉺�ɓ����M�~�b�N
	
	m_sidepress[0] = new SidePress(32 * 8, 32 * 8);	
	m_sidepress[1] = new SidePress(32 * 11, 32 * 8);
	
	m_sidepress[0]->SetState(0);
	m_sidepress[1]->SetState(1);
}

//----------------------------------------------------------------------
//! @brief �v���C�V�[���̃f�X�g���N�^
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
Play::~Play()
{
	delete m_stage;	//�X�e�[�W
	m_stage = nullptr;
	delete m_moveblock;	//�㉺�ɓ����M�~�b�N
	m_moveblock = nullptr;
	for (int i = 0; i < 2; i++)
	{
		delete m_sidepress[i];
		m_sidepress[i] = nullptr;
	}
}

//----------------------------------------------------------------------
//! @brief �Q�[���v���C�̍X�V����
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Play::Update()
{

	//�V�[���̍ŏ��Ɉ�񂾂��s������������
	if (g_init == 0)
	{
	}	
	//�X�e�[�W�̍X�V
	m_stage->Update();

	//�㉺�ɓ����M�~�b�N�̍X�V
	m_moveblock->Update();

	for (int i = 0; i < 2; i++)
	{
		m_sidepress[i]->Update();
		m_sidepress[i]->Move();
	}
}

//----------------------------------------------------------------------
//! @brief �Q�[���v���C�`�揈��
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Play::Render()
{
	//�X�e�[�W�̕`��
	m_stage->DrawStage();

	//�㉺�ɓ����M�~�b�N�̕`��
	m_moveblock->Render();

	for (int i = 0; i < 2; i++)
	{
		m_sidepress[i]->Render();
	}
}

