//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameTitle.h
//!
//! @brief  �^�C�g���V�[���̃w�b�_�t�@�C��
//!
//! @date   2017/04/07
//!
//! @author ���� ����
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

//	���d�C���N���[�h�̖h�~
#pragma once
//	�w�b�_�t�@�C���̃C���N���[�h
#include "GameBase.h"

class Title:public GameBase
{
private:
	Texture *m_title_image;					//	�^�C�g���摜
	bool m_fade_flag;							//	�t�F�[�h�p�t���O				

public:
	Title();					//	�R���X�g���N�^
	~Title();					//	�f�X�g���N�^
	void Update();				//	�X�V����
	void Render();				//	�`�揈��

};



