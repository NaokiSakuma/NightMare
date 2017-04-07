//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameLogo.cpp
//!
//! @brief  ロゴ処理のソースファイル
//!
//! @date   2016/11/04		
//!
//! @author 山田唯真
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み ================================================
#include "GameMain.h"
#include "GameLogo.h"
using namespace DirectX::SimpleMath;
using namespace DirectX;

//----------------------------------------------------------------------
//! @brief ロゴコンストラクタ
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
Logo::Logo()
{

}

//----------------------------------------------------------------------
//! @brief ロゴデストラクタ
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
Logo::~Logo()
{

}

//----------------------------------------------------------------------
//! @brief ロゴ処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Logo::Update()
{
	if (g_init == 0)
	{
		g_init = 1;

		g_TimeCnt = 0;
	}

	g_TimeCnt++;
	if (g_TimeCnt > 120)
	{
		g_NextScene = TITLE;
	}

}

//----------------------------------------------------------------------
//! @brief ロゴ描画処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Logo::Render()
{
}

