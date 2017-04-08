//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GamePlay.h
//!
//! @brief  �v���C�V�[���̃w�b�_�t�@�C��
//!
//! @date   2017/04/07
//!
//! @author ���� ����
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

//	���d�C���N���[�h�̖h�~
#pragma once
//	�w�b�_�t�@�C���̃C���N���[�h
#include "GameBase.h"
#include "Stage\Stage.h"
#include "Object\Press.h"
#include "Object\SidePress.h"
#include "MoveBlock.h"
//�N���X
class Play:public GameBase
{
private:
	Stage* m_stage;
	Moveblock* m_moveblock;
	SidePress* m_sidepress[2];
public:
	Play();				//	�R���X�g���N�^
	~Play();			//	�f�X�g���N�^
	void Update();		//	�X�V����
	void Render();		//	�`�揈��

};
