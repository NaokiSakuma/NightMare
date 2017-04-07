//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameClear.cpp
//!
//! @brief  ゲームクリア処理のソースファイル
//!
//! @date   2016/11/04		
//!
//! @author 山田唯真	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み ================================================
#include "GameMain.h"
#include "GameClear.h"
using namespace DirectX::SimpleMath;
using namespace DirectX;

//----------------------------------------------------------------------
//! @brief ゲームクリアコンストラクタ
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
Clear::Clear()
{

}

//----------------------------------------------------------------------
//! @brief ゲームクリアデストラクタ
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
Clear::~Clear()
{
}

//----------------------------------------------------------------------
//! @brief ゲームクリア処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Clear::Update()
{
	if (g_init == 0)
	{
		g_init = 1;
		g_TimeCnt = 0;
	}


	if (g_mouse.leftButton)
	{ 
		g_NextScene = TITLE;
	}
}

//----------------------------------------------------------------------
//! @brief ゲームクリア描画処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Clear::Render()
{
}
