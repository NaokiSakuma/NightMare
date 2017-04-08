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

//�N���X
class Play:public GameBase
{
private:
	Texture *m_back_image;		//	�w�i�摜
	Texture *m_pause_image;		//	�|�[�Y���摜
	Texture *m_line_image;		//	�I��p���̉摜
	bool m_pause_flag;			//	�|�[�Y�t���O
	int m_pause_select;			//	�|�[�Y���I��p�ϐ�

	const int RETURN = 0;		//	�Q�[���ɖ߂�Ƃ��̒萔
	const int RETURN_TITLE = 1; //	�^�C�g���ɖ߂�Ƃ��̒萔

public:
	Play();						//	�R���X�g���N�^
	~Play();					//	�f�X�g���N�^
	void Update();				//	�X�V����
	void Render();				//	�`�揈��
};
