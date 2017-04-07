#pragma once

#include "..\DirectXTK.h"
#include "..\Texture.h"

class ObjectBase
{
protected:
	Texture *handle;	//�O���t�B�b�N�n���h�� 
	int grp_x;			//���摜�̂����W 
	int grp_y;			//���摜�̂����W 
	int grp_w;			//���摜�̕� 
	int grp_h;			//���摜�̍��� 
	float pos_x;		//���Wx 
	float pos_y;		//���Wy 
	float spd_x;		//���xx 
	float spd_y;		//���xy 
	int state;			//���

public:
	void SetHandle(Texture *p);
	Texture* GetHandle();
	void SetGrpX(float x);
	float GetGrpX();
	void SetGrpY(float y);
	float GetGrpY();
	void SetGrpW(float w);
	float GetGrpW();
	void SetGrpH(float h);
	float GetGrpH();
	void SetPosX(float x);
	float GetPosX();
	void SetPosY(float y);
	float GetPosY();
	void SetSpdX(float x);
	void SetSpdY(float y);
	void SetState(int n);
	int GetState();
	void Update();
	void Render();
};