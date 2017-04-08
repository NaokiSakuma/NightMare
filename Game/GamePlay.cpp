//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GamePlay.cpp
//!
//! @brief  ゲームプレイ処理のソースファイル
//!
//! @date   2017/04/07		
//!
//! @author 加藤 竜哉
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み ================================================
#include "GameMain.h"
#include "GamePlay.h"

using namespace DirectX::SimpleMath;
using namespace DirectX;
using namespace std;
//グローバル変数＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝−

//関数の定義＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝−
//----------------------------------------------------------------------
//! @brief プレイシーンのコンストラクタ
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
Play::Play()
{
	m_moveblock = new Moveblock;
}

//----------------------------------------------------------------------
//! @brief プレイシーンのデストラクタ
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
Play::~Play()
{
	delete m_moveblock;
}

//----------------------------------------------------------------------
//! @brief ゲームプレイの更新処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Play::Update()
{

	//シーンの最初に一回だけ行う初期化処理
	if (g_init == 0)
	{
	}	

	m_moveblock->Move_up_down();

	m_moveblock->Update();

}

//----------------------------------------------------------------------
//! @brief ゲームプレイ描画処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Play::Render()
{
	m_stage.DrawStage();
	m_moveblock->Render();
}

