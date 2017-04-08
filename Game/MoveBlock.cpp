//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   MoveBlock.cpp
//!
//! @brief  ²ÞM~bNÌ\[Xt@C
//!
//! @date   2017/04/07		
//!
//! @author nç²^l
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

//wb_t@CÌÇ
#include "MoveBlock.h"

using namespace DirectX::SimpleMath;
using namespace DirectX;


//ÖÌè`|
//----------------------------------------------------------------------
//! @brief RXgN^
//!
//! @param[in] Èµ
//!
//! @return Èµ
//----------------------------------------------------------------------
Moveblock::Moveblock()
{
	g_gimmickimage = new Texture(L"Resources\\Images\\orange.png");

	m_handle = g_gimmickimage;
	m_grp_x = 0;
	m_grp_y = 0;
	m_grp_w = M_BLOCK_GRP_W;
	m_grp_h = M_BLOCK_GRP_H;
	m_pos_x = M_BLOCK_POS_X;
	m_pos_y = 0;
}

//----------------------------------------------------------------------
//! @brief fXgN^
//!
//----------------------------------------------------------------------
Moveblock::~Moveblock()
{
	delete g_gimmickimage;
}


//----------------------------------------------------------------------
//! @brief M~bNÌãºÚ®
//!
//! @return Èµ
//----------------------------------------------------------------------
void Moveblock::MoveUpDown()
{
	if (m_pos_y_min == m_pos_y)
	{
		SetSpdY(6);
	}
	else if (m_pos_y_max == m_pos_y)
	{
		SetSpdY(-6);
	}
}


