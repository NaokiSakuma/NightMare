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
<<<<<<< HEAD
#include "Object\Press.h"
=======
#include "MoveBlock.h"

>>>>>>> 592c7ff96f3a6235e62b19fc2ccbf2838140ca34
//�N���X
class Play:public GameBase
{
private:
<<<<<<< HEAD
	Stage* m_stage;
	//Press* m_press;
=======
	Stage m_stage;
	Moveblock* m_moveblock;
>>>>>>> 592c7ff96f3a6235e62b19fc2ccbf2838140ca34
public:
	Play();				//	�R���X�g���N�^
	~Play();			//	�f�X�g���N�^
	void Update();		//	�X�V����
	void Render();		//	�`�揈��

};
