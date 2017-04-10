//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameClear.h
//!
//! @brief  �N���A�V�[���̃w�b�_�t�@�C��
//!
//! @date   2017/04/07
//!
//! @author ���� ����
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

//	���d�C���N���[�h�̖h�~
#pragma once
//	�w�b�_�t�@�C���̃C���N���[�h
#include "GameBase.h"

class Clear : public GameBase 
{
private:
	Texture *m_clear_image;					//	�N���A�摜
	Texture *m_clear_image2;				//	�N���A�摜�Q
	Texture *m_back_image;					//	�w�i(��)�摜
	bool m_fade_flag;						//	�t�F�[�h�p�t���O				
	DirectX::SimpleMath::Color color;		//	�t�F�[�h�p�ϐ�
	float m_alfa;							//	�摜�̓����x�p�ϐ�
	int m_count;							//	�J�E���g

public:
	Clear();			//	�R���X�g���N�^
	~Clear();			//	�f�X�g���N�^
	void Update();		//	�X�V����
	void Render();		//	�`�揈��
};
