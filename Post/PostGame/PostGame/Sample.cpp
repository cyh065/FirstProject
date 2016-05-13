#include "Sample.h"
#include "KSys.h"
#include "KBitmapMgr.h"
#include "KCollision.h"
bool			game = true;
bool			over = true;
bool			g_over = true;
bool			bVolume = true;
int				iVolumeIndex;
//bool			bBox = true;
//
//struct Box
//{
//	bool m_Ob_One = false;
//	bool m_Ob_Two = false;
//	bool m_Ob_Thr = false;
//	bool m_Ob_Fou = false;
//};
//Box PostBox;
bool			Sample::Init()
{
	//////////////////////데이터 입력/////////////////////////////
	//메뉴 로딩
		m_GameMenu.SetPos(0, 0, 0.0f);
		m_GameMenu.SetRect(0, 0, 800, 600);
		m_GameMenu.Load(m_hScreenDC,
			m_hOffScreenDC,
			L"../../data/men.bmp");
	//사운드 로딩
		m_pSound.Init();
		iVolumeIndex = m_pSound.Load("../../data/おじいさんの11ヶ月.mp3");
		iVolumeIndex = m_pSound.Load("../../data/end.mp3");
	//배경 로딩
		m_Background.SetPos(0, 0, 0.0f);
		m_Background.SetRect(0, 0, 800, 600);
		m_Background.Load(m_hScreenDC,
			m_hOffScreenDC, L"../../data/bk.bmp");

		m_GameOver.SetPos(0, 0, 0.0f);
		m_GameOver.SetRect(0, 0, 800, 600);
		m_GameOver.Load(m_hScreenDC,
			m_hOffScreenDC, L"../../data/gameover.bmp");

		m_Hero.SetPos(550, 450, 0.0f);
		m_Hero.SetRect(140, 0, 30, 36);
		m_Hero_Up.SetPos(550, 450, 0.0f);
		m_Hero_Up.SetRect(140, 60, 30, 36);
		m_Hero.Load(m_hScreenDC,
			m_hOffScreenDC, L"../../data/Trail.bmp");
		m_Hero_Up.Load(m_hScreenDC,
			m_hOffScreenDC, L"../../data/Trail.bmp");

		m_Box.SetPos(50, 90, 0.0f);
		m_Box.SetRect(200, 0, 166, 289);
		m_Box.Load(m_hScreenDC, m_hOffScreenDC, L"../../data/Trail.bmp");

		m_Truck.SetPos(400, 490, 0.0f);
		m_Truck.SetRect(0, 360, 320, 128);
		m_Truck.Load(m_hScreenDC, m_hOffScreenDC, L"../../data/Trail.bmp");

		m_ColorBitmap.Load(_T("../../data/Trail.bmp"));
		m_MaskBitmap.Load(_T("../../data/Mask.bmp"));
		m_Data_One.push_back(new KVector(70, 0, 40, 50));
		m_Data_Two.push_back(new KVector(70, 60, 40, 36));
		m_Data_Thr.push_back(new KVector(70, 110, 40, 31));
		m_Data_Fou.push_back(new KVector(70, 150, 40, 38));

		m_Trail[0].SetPos(375, 0, 0.0f);
		m_Trail[0].SetRect(0, 0, 50, 290);
		m_Trail[1].SetPos(525, 0, 0.0f);
		m_Trail[1].SetRect(0, 0, 50, 290);
		m_Trail[2].SetPos(675, 0, 0.0f);
		m_Trail[2].SetRect(0, 0, 50, 290);

		for (int iTrail = 0;iTrail < 3;iTrail++)
		{
			m_Trail[iTrail].Load(m_hScreenDC, m_hOffScreenDC, L"../../data/Trail.bmp");
		}
		//m_Object[0].SetRect(70, 0, 40, 50);
		//m_Object[1].SetRect(70, 60, 40, 36);
		//m_Object[2].SetRect(70, 110, 40, 31);
		//m_Object[3].SetRect(70, 150, 40, 37);
		//for (int iObj = 0; iObj < 4; iObj++)
		//{
		//	m_Object[iObj].SetPos(545, 475, 100.0f);
		//	m_Object[iObj].Load(m_hScreenDC, m_hOffScreenDC, L"../../data/Trail.bmp");
		//}
		
		

		for (int iObj = 0; iObj < MAX_OBJECT; iObj++)
		{

			m_Object_One[iObj].SetPos(400, -25, 100.0f);
			m_Object_One[iObj].SetRect(70, 0, 40, 50);
			m_Object_One[iObj].Load(m_hScreenDC, m_hOffScreenDC, L"../../data/Trail.bmp");

			if (iObj >= 12)
			{
				if (iObj % 3 == 0)
				{
					m_Object_One[iObj].SetPos(400, -18, 100.0f);
					m_Object_One[iObj].SetRect(70, 60, 40, 36);
					m_Object_One[iObj].Load(m_hScreenDC, m_hOffScreenDC, L"../../data/Trail.bmp");

					if (iObj >= 25)
					{
						if (iObj % 4 == 0)
						{
							m_Object_One[iObj].SetPos(400, -16, 100.0f);
							m_Object_One[iObj].SetRect(70, 110, 40, 31);
							m_Object_One[iObj].Load(m_hScreenDC, m_hOffScreenDC, L"../../data/Trail.bmp");
							if (iObj >= 49)
							{
								if (iObj % 5 == 0)
								{
									m_Object_One[iObj].SetPos(400, -19, 100.0f);
									m_Object_One[iObj].SetRect(70, 150, 40, 38);
									m_Object_One[iObj].Load(m_hScreenDC, m_hOffScreenDC, L"../../data/Trail.bmp");
								}
							}
						}
					}
				}
			}

			m_Object_Two[iObj].SetPos(550, -25, 100.0f);
			m_Object_Two[iObj].SetRect(70, 0, 40, 50);
			m_Object_Two[iObj].Load(m_hScreenDC, m_hOffScreenDC, L"../../data/Trail.bmp");
			if (iObj >= 12)
			{
				if (iObj % 3 == 2)
				{
					m_Object_Two[iObj].SetPos(550, -18, 100.0f);
					m_Object_Two[iObj].SetRect(70, 60, 40, 36);
					m_Object_Two[iObj].Load(m_hScreenDC, m_hOffScreenDC, L"../../data/Trail.bmp");
					if (iObj >= 25)
					{
						if (iObj % 4 == 2)
						{
							m_Object_Two[iObj].SetPos(550, -16, 100.0f);
							m_Object_Two[iObj].SetRect(70, 110, 40, 31);
							m_Object_Two[iObj].Load(m_hScreenDC, m_hOffScreenDC, L"../../data/Trail.bmp");
							if (iObj >= 49)
							{
								if (iObj % 5 == 2)
								{
									m_Object_Two[iObj].SetPos(550, -19, 100.0f);
									m_Object_Two[iObj].SetRect(70, 150, 40, 38);
									m_Object_Two[iObj].Load(m_hScreenDC, m_hOffScreenDC, L"../../data/Trail.bmp");
								}
							}
						}
					}
				}
			}

			m_Object_Thr[iObj].SetPos(700, -25, 100.0f);
			m_Object_Thr[iObj].SetRect(70, 0, 40, 50);
			m_Object_Thr[iObj].Load(m_hScreenDC, m_hOffScreenDC, L"../../data/Trail.bmp");
			if (iObj >= 12)
			{
				if (iObj % 3 == 0)
				{
					m_Object_Thr[iObj].SetPos(700, -18, 100.0f);
					m_Object_Thr[iObj].SetRect(70, 60, 40, 36);
					m_Object_Thr[iObj].Load(m_hScreenDC, m_hOffScreenDC, L"../../data/Trail.bmp");
					if (iObj >= 25)
					{
						if (iObj % 5 == 4)
						{

							m_Object_Thr[iObj].SetPos(700, -16, 100.0f);
							m_Object_Thr[iObj].SetRect(70, 110, 40, 31);
							m_Object_Thr[iObj].Load(m_hScreenDC, m_hOffScreenDC, L"../../data/Trail.bmp");
							if (iObj >= 49)
							{
								if (iObj % 7 == 6)
								{
									m_Object_Thr[iObj].SetPos(700, -19, 100.0f);
									m_Object_Thr[iObj].SetRect(70, 150, 40, 38);
									m_Object_Thr[iObj].Load(m_hScreenDC, m_hOffScreenDC, L"../../data/Trail.bmp");
								}
							}
						}
					}
				}
			}
		}
	return true;
}

bool			Sample::Frame()
{
	m_pSound.Frame();
	if (game == true)
	{
		m_GameMenu.Frame();
		m_Timer.m_fAccumulation = 0.0f;
			if (m_Input.m_MovePt.x >= 510 && m_Input.m_MovePt.x <= 690)
			{
				if (m_Input.m_MovePt.y >= 435 && m_Input.m_MovePt.y <= 475)
				{
					if (m_Input.m_dwMouseState[0])
					{
						game = false;
					}
				}
			}
	}
	else
	{
		
		if (m_Input.KeyCheck(VK_INSERT) == KEY_HOLD)
		{
			m_pSound.Volume(0, g_fSecondPerFrame, true);
		}
		if (m_Input.KeyCheck(VK_DELETE) == KEY_HOLD)
		{
			m_pSound.Volume(0, g_fSecondPerFrame, false);
		}

		m_pSound.Play(iVolumeIndex-1, true);
	
		m_fTimer_One = m_Timer.m_fAccumulation / 2.5f;
		m_fTimer_Two = m_Timer.m_fAccumulation / 3.6f;
		m_fTimer_Thr = m_Timer.m_fAccumulation / 4.7f;

		if (m_Input.KeyCheck('W') == KEY_PUSH)
		{
			m_Hero.Up();
			m_Hero_Up.Up();
			
		}
		if (m_Input.KeyCheck('S') == KEY_PUSH)
		{
		/*	if (m_Hero.m_bGet == true)
			{
				if (PostBox.m_Ob_One == true)
				{
					m_Object[0].Frame();
					PostBox.m_Ob_One = false;
				}
				if (PostBox.m_Ob_Two == true)
				{
					m_Object[1].Frame();
					PostBox.m_Ob_Two = false;
				}
				if (PostBox.m_Ob_Thr == true)
				{
					m_Object[2].Frame();
					PostBox.m_Ob_Thr = false;
				}
				if (PostBox.m_Ob_Fou == true)
				{
					m_Object[3].Frame();
					PostBox.m_Ob_Fou = false;
				}
			}
			bBox = false;*/
			m_Hero.Down();
			m_Hero_Up.Down();
			m_Hero.m_iget = m_iCnt;

		}
		if (m_Input.KeyCheck('A') == KEY_PUSH)
		{
			m_Hero.Left();
			m_Hero_Up.Left();


		}
		if (m_Input.KeyCheck('D') == KEY_PUSH)
		{
			m_Hero.Right();
			m_Hero_Up.Right();

		}
		m_Hero.Frame();

		for (int iObj = 0;iObj < MAX_OBJECT;iObj++)
		{
			if (m_Timer.m_fAccumulation > 10.0f)
			{
				m_fTimer_One = m_Timer.m_fAccumulation / 2.2f;
				m_fTimer_Two = m_Timer.m_fAccumulation / 2.8f;
				m_fTimer_Thr = m_Timer.m_fAccumulation / 3.5f;
			}
			if (m_Timer.m_fAccumulation > 15.0f)
			{
				m_fTimer_One = m_Timer.m_fAccumulation / 2.1f;
				m_fTimer_Two = m_Timer.m_fAccumulation / 2.7f;
				m_fTimer_Thr = m_Timer.m_fAccumulation / 3.4f;
			}
			if (m_Timer.m_fAccumulation > 20.0f)
			{
				m_fTimer_One = m_Timer.m_fAccumulation / 2.0f;
				m_fTimer_Two = m_Timer.m_fAccumulation / 2.6f;
				m_fTimer_Thr = m_Timer.m_fAccumulation / 3.3f;
			}
			if (m_Timer.m_fAccumulation > 25.0f)
			{
				m_fTimer_One = m_Timer.m_fAccumulation / 1.9f;
				m_fTimer_Two = m_Timer.m_fAccumulation / 2.5f;
				m_fTimer_Thr = m_Timer.m_fAccumulation / 3.2f;
			}
			if (m_Timer.m_fAccumulation > 30.0f)
			{
				m_fTimer_One = m_Timer.m_fAccumulation / 1.8f;
				m_fTimer_Two = m_Timer.m_fAccumulation / 2.4f;
				m_fTimer_Thr = m_Timer.m_fAccumulation / 3.1f;
			}
		
			if (iObj < m_fTimer_One)
			{
				m_Object_One[iObj].Frame();
				if (RectInRect(m_Object_One[iObj].m_rtCollide, m_Object_One[iObj-1].m_rtCollide))
				{
					m_Object_One[iObj].m_fSpeed = 0.0f;
					if (m_Object_One[iObj].m_fPosY <= 0)
					{

						m_pSound.Stop(0);
						game = true;
						over = false;
						Release();
						Init();
						m_iCnt = 0;
						m_Hero.m_iget = 0;
						for (int i = 0;i < MAX_OBJECT;i++) {
							m_Object_One[i].m_bUsed = true;
							m_Object_Two[i].m_bUsed = true;
							m_Object_Thr[i].m_bUsed = true;
						}
					}
				}
				else
				{
					m_Object_One[iObj].m_fSpeed = 100.0f;
					for (vector<KVector*>::iterator Obj = m_Data_Two.begin();
					Obj != m_Data_Two.end();
						Obj++)
					{
						if (m_Object_One[iObj].m_rt.h == (*Obj)->ih && m_Object_One[iObj].m_rt.w == (*Obj)->iw)
						{
							m_Object_One[iObj].m_fSpeed = 80.0f;
						}
					}
					for (vector<KVector*>::iterator Obj = m_Data_Thr.begin();
					Obj != m_Data_Thr.end();
						Obj++)
					{
						if (m_Object_One[iObj].m_rt.h == (*Obj)->ih && m_Object_One[iObj].m_rt.w == (*Obj)->iw)
						{
							m_Object_One[iObj].m_fSpeed = 70.0f;
						}
					}
					for (vector<KVector*>::iterator Obj = m_Data_Fou.begin();
					Obj != m_Data_Fou.end();
						Obj++)
					{
						if (m_Object_One[iObj].m_rt.h == (*Obj)->ih && m_Object_One[iObj].m_rt.w == (*Obj)->iw)
						{
							m_Object_One[iObj].m_fSpeed = 60.0f;
						}
					}
				}
			}
			if (iObj < m_fTimer_Two)
			{
				m_Object_Two[iObj].Frame();
				if (RectInRect(m_Object_Two[iObj].m_rtCollide, m_Object_Two[iObj - 1].m_rtCollide))
				{
					m_Object_Two[iObj].m_fSpeed = 0.0f;
					if (m_Object_Two[iObj].m_fPosY <= 0)
					{

						m_pSound.Stop(0);
						game = true;
						over = false;
						Release();
						Init();
						m_iCnt = 0;
						m_Hero.m_iget = 0;
						for (int i = 0;i < MAX_OBJECT;i++) {
							m_Object_One[i].m_bUsed = true;
							m_Object_Two[i].m_bUsed = true;
							m_Object_Thr[i].m_bUsed = true;
						}
					}
				}
				else
				{
					m_Object_Two[iObj].m_fSpeed = 100.0f;
					for (vector<KVector*>::iterator Obj = m_Data_Two.begin();
					Obj != m_Data_Two.end();
					Obj++)
					{
						if (m_Object_Two[iObj].m_rt.h == (*Obj)->ih && m_Object_Two[iObj].m_rt.w == (*Obj)->iw)
						{
							m_Object_Two[iObj].m_fSpeed = 80.0f;
						}
					}
					for (vector<KVector*>::iterator Obj = m_Data_Thr.begin();
					Obj != m_Data_Thr.end();
						Obj++)
					{
						if (m_Object_Two[iObj].m_rt.h == (*Obj)->ih && m_Object_Two[iObj].m_rt.w == (*Obj)->iw)
						{
							m_Object_Two[iObj].m_fSpeed = 70.0f;
						}
					}			
					for (vector<KVector*>::iterator Obj = m_Data_Fou.begin();
					Obj != m_Data_Fou.end();
						Obj++)
					{
						if (m_Object_Two[iObj].m_rt.h == (*Obj)->ih && m_Object_Two[iObj].m_rt.w == (*Obj)->iw)
						{
							m_Object_Two[iObj].m_fSpeed = 60.0f;
						}
					}
				}
			}
			if (iObj < m_fTimer_Thr)
			{
				m_Object_Thr[iObj].Frame();
				if (RectInRect(m_Object_Thr[iObj].m_rtCollide, m_Object_Thr[iObj-1].m_rtCollide))
				{
					m_Object_Thr[iObj].m_fSpeed = 0.0f;
					if (m_Object_Thr[iObj].m_fPosY <= 0)
					{
						m_pSound.Stop(0);
						game = true;
						over = false;
						Release();
						Init();
						m_iCnt = 0;
						m_Hero.m_iget = 0;
						for (int i = 0;i < MAX_OBJECT;i++) {
							m_Object_One[i].m_bUsed = true;
							m_Object_Two[i].m_bUsed = true;
							m_Object_Thr[i].m_bUsed = true;
						}
					}
				}
				else
				{
					m_Object_Thr[iObj].m_fSpeed = 100.0f;
					for (vector<KVector*>::iterator Obj = m_Data_Two.begin();
					Obj != m_Data_Two.end();
						Obj++)
					{
						if (m_Object_Thr[iObj].m_rt.h == (*Obj)->ih && m_Object_Thr[iObj].m_rt.w == (*Obj)->iw)
						{
							m_Object_Thr[iObj].m_fSpeed = 80.0f;
						}
					}
					for (vector<KVector*>::iterator Obj = m_Data_Thr.begin();
					Obj != m_Data_Thr.end();
						Obj++)
					{
						if (m_Object_Thr[iObj].m_rt.h == (*Obj)->ih && m_Object_Thr[iObj].m_rt.w == (*Obj)->iw)
						{
							m_Object_Thr[iObj].m_fSpeed = 80.0f;
						}
					}
					for (vector<KVector*>::iterator Obj = m_Data_Fou.begin();
					Obj != m_Data_Fou.end();
						Obj++)
					{
						if (m_Object_Thr[iObj].m_rt.h == (*Obj)->ih && m_Object_Thr[iObj].m_rt.w == (*Obj)->iw)
						{
							m_Object_Thr[iObj].m_fSpeed = 80.0f;
						}
					}
				}
			}
		}
		for (int iObj = 0; iObj < MAX_OBJECT;iObj++)
		{
			if (m_Hero.m_bGet == false)
			{
				if (RectInRect(m_Object_One[iObj].m_rtCollide, m_Hero.m_rtCollide))
				{
					if (m_Object_One[iObj].m_bUsed == true)
					{
						vector<KVector*>::iterator _F = m_Data_Two.begin();
						vector<KVector*>::iterator _E = m_Data_Two.end();
						vector<KVector*>::iterator _F1 = m_Data_Thr.begin();
						vector<KVector*>::iterator _E1 = m_Data_Thr.end();
						vector<KVector*>::iterator _F2 = m_Data_Fou.begin();
						vector<KVector*>::iterator _E2 = m_Data_Fou.end();
						for (;_F != _E; _F++)
						{
							if (m_Object_One[iObj].m_rt.w == (*_F)->iw && m_Object_One[iObj].m_rt.h == (*_F)->ih)
							{
								m_iCnt += 30;
							}
							else
							{
								for (;_F1 != _E1; _F1++)
								{
									if (m_Object_One[iObj].m_rt.w == (*_F1)->iw && m_Object_One[iObj].m_rt.h == (*_F1)->ih)
									{
										m_iCnt += 50;
									}
									else
									{
										for (;_F2 != _E2; _F2++)
										{
											if (m_Object_One[iObj].m_rt.w == (*_F2)->iw && m_Object_One[iObj].m_rt.h == (*_F2)->ih)
											{
												m_iCnt += 100;
											}
											else
											{
												m_iCnt += 10;

											}
										}
									}
								}
							}
						}
						m_Object_One[iObj].m_bUsed = false;
						m_Object_One[iObj].m_rt.w = 0;
						m_Object_One[iObj].m_rt.h = 0;
						m_Hero.m_bGet = true;
					}
				}
				if (RectInRect(m_Object_Two[iObj].m_rtCollide, m_Hero.m_rtCollide))
				{
					if (m_Object_Two[iObj].m_bUsed == true)
					{
						vector<KVector*>::iterator _F = m_Data_Two.begin();
						vector<KVector*>::iterator _E = m_Data_Two.end();
						vector<KVector*>::iterator _F1 = m_Data_Thr.begin();
						vector<KVector*>::iterator _E1 = m_Data_Thr.end();
						vector<KVector*>::iterator _F2 = m_Data_Fou.begin();
						vector<KVector*>::iterator _E2 = m_Data_Fou.end();
						for (;_F != _E; _F++) {
							if (m_Object_Two[iObj].m_rt.w == (*_F)->iw && m_Object_Two[iObj].m_rt.h == (*_F)->ih)
							{
								m_iCnt += 30;
							}
							else
							{
								for (;_F1 != _E1; _F1++)
								{
									if (m_Object_Two[iObj].m_rt.w == (*_F1)->iw && m_Object_Two[iObj].m_rt.h == (*_F1)->ih)
									{
										m_iCnt += 50;
									}
									else
									{
										for (;_F2 != _E2; _F2++)
										{
											if (m_Object_Two[iObj].m_rt.w == (*_F2)->iw && m_Object_Two[iObj].m_rt.h == (*_F2)->ih)
											{
												m_iCnt += 100;

											}
											else
											{
												m_iCnt += 10;
											}
										}
									}
								}
							}
						}
						m_Object_Two[iObj].m_bUsed = false;
						m_Object_Two[iObj].m_rt.w = 0;
						m_Object_Two[iObj].m_rt.h = 0;
						m_Hero.m_bGet = true;
					}
				}
				if (RectInRect(m_Object_Thr[iObj].m_rtCollide, m_Hero.m_rtCollide))
				{
					if (m_Object_Thr[iObj].m_bUsed == true)
					{
						vector<KVector*>::iterator _F = m_Data_Two.begin();
						vector<KVector*>::iterator _E = m_Data_Two.end();
						vector<KVector*>::iterator _F1 = m_Data_Thr.begin();
						vector<KVector*>::iterator _E1 = m_Data_Thr.end();
						vector<KVector*>::iterator _F2 = m_Data_Fou.begin();
						vector<KVector*>::iterator _E2 = m_Data_Fou.end();
						for (;_F != _E; _F++) {
							if (m_Object_Thr[iObj].m_rt.w == (*_F)->iw && m_Object_Thr[iObj].m_rt.h == (*_F)->ih)
							{
								m_iCnt += 30;
							}
							else
							{
								for (;_F1 != _E1; _F1++)
								{
									if (m_Object_Thr[iObj].m_rt.w == (*_F1)->iw && m_Object_Thr[iObj].m_rt.h == (*_F1)->ih)
									{
										m_iCnt += 50;
									}
									else
									{
										for (;_F2 != _E2; _F2++)
										{
											if (m_Object_Thr[iObj].m_rt.w == (*_F2)->iw && m_Object_Thr[iObj].m_rt.h == (*_F2)->ih)
											{
												m_iCnt += 100;
											}
											else
											{
												
												m_iCnt += 10;
											}
										}
									}
								}
							}
						}
						m_Object_Thr[iObj].m_bUsed = false;
						m_Object_Thr[iObj].m_rt.w = 0;
						m_Object_Thr[iObj].m_rt.h = 0;
						m_Hero.m_bGet = true;
					}
				}
			}
		}
	}
	return true;

}

bool			Sample::Render()
{
	
if(game == true)
{
	
	if (over == false)
	{
		m_GameOver.Frame();
		m_GameOver.Draw();
		if (g_over == false)
		{
			m_pSound.Play(iVolumeIndex, true);
			Sleep(3000);
			g_over = true;
			over = true;
		}
		else
		{
			g_over = false;
		}
	}
	else
	{
		m_GameMenu.Draw();
	}
}
else
{
	m_Background.Draw();

	if (BitBlt(g_hOffScreenDC, m_Box.m_fPosX, m_Box.m_fPosY,
		m_Box.m_rt.w,
		m_Box.m_rt.h,
		m_MaskBitmap.m_hMemDC,
		m_Box.m_rt.x, m_Box.m_rt.y, SRCAND) == FALSE)
	{
		return true;
	};
	BitBlt(g_hOffScreenDC, m_Box.m_fPosX, m_Box.m_fPosY,
		m_Box.m_rt.w,
		m_Box.m_rt.h,
		m_ColorBitmap.m_hMemDC,
		m_Box.m_rt.x, m_Box.m_rt.y, SRCINVERT);

	BitBlt(g_hOffScreenDC, m_Box.m_fPosX, m_Box.m_fPosY,
		m_Box.m_rt.w,
		m_Box.m_rt.h,
		m_MaskBitmap.m_hMemDC,
		m_Box.m_rt.x, m_Box.m_rt.y, SRCINVERT);
	/*if (bBox == false)
	{
		if (PostBox.m_Ob_One == true) {
			if (BitBlt(g_hOffScreenDC, m_Object[0].m_fPosX, m_Object[0].m_fPosY,
				m_Object[0].m_rt.w,
				m_Object[0].m_rt.h,
				m_MaskBitmap.m_hMemDC,
				m_Object[0].m_rt.x, m_Object[0].m_rt.y, SRCAND) == FALSE)
			{
				return true;
			};
			BitBlt(g_hOffScreenDC, m_Object[0].m_fPosX, m_Object[0].m_fPosY,
				m_Object[0].m_rt.w,
				m_Object[0].m_rt.h,
				m_ColorBitmap.m_hMemDC,
				m_Object[0].m_rt.x, m_Object[0].m_rt.y, SRCINVERT);

			BitBlt(g_hOffScreenDC, m_Object[0].m_fPosX, m_Object[0].m_fPosY,
				m_Object[0].m_rt.w,
				m_Object[0].m_rt.h,
				m_MaskBitmap.m_hMemDC,
				m_Object[0].m_rt.x, m_Object[0].m_rt.y, SRCINVERT);
		}
		
		if (PostBox.m_Ob_Two == true) {
			if (BitBlt(g_hOffScreenDC, m_Object[1].m_fPosX, m_Object[1].m_fPosY,
				m_Object[1].m_rt.w,
				m_Object[1].m_rt.h,
				m_MaskBitmap.m_hMemDC,
				m_Object[1].m_rt.x, m_Object[1].m_rt.y, SRCAND) == FALSE)
			{
				return true;
			};
			BitBlt(g_hOffScreenDC, m_Object[1].m_fPosX, m_Object[1].m_fPosY,
				m_Object[1].m_rt.w,
				m_Object[1].m_rt.h,
				m_ColorBitmap.m_hMemDC,
				m_Object[1].m_rt.x, m_Object[1].m_rt.y, SRCINVERT);

			BitBlt(g_hOffScreenDC, m_Object[1].m_fPosX, m_Object[1].m_fPosY,
				m_Object[1].m_rt.w,
				m_Object[1].m_rt.h,
				m_MaskBitmap.m_hMemDC,
				m_Object[1].m_rt.x, m_Object[1].m_rt.y, SRCINVERT);
		}

		if (PostBox.m_Ob_Thr == true) {
			if (BitBlt(g_hOffScreenDC, m_Object[2].m_fPosX, m_Object[2].m_fPosY,
				m_Object[2].m_rt.w,
				m_Object[2].m_rt.h,
				m_MaskBitmap.m_hMemDC,
				m_Object[2].m_rt.x, m_Object[2].m_rt.y, SRCAND) == FALSE)
			{
				return true;
			};
			BitBlt(g_hOffScreenDC, m_Object[2].m_fPosX, m_Object[2].m_fPosY,
				m_Object[2].m_rt.w,
				m_Object[2].m_rt.h,
				m_ColorBitmap.m_hMemDC,
				m_Object[2].m_rt.x, m_Object[2].m_rt.y, SRCINVERT);

			BitBlt(g_hOffScreenDC, m_Object[2].m_fPosX, m_Object[2].m_fPosY,
				m_Object[2].m_rt.w,
				m_Object[2].m_rt.h,
				m_MaskBitmap.m_hMemDC,
				m_Object[2].m_rt.x, m_Object[2].m_rt.y, SRCINVERT);
		}

		if (PostBox.m_Ob_Fou == true) {
			if (BitBlt(g_hOffScreenDC, m_Object[3].m_fPosX, m_Object[3].m_fPosY,
				m_Object[3].m_rt.w,
				m_Object[3].m_rt.h,
				m_MaskBitmap.m_hMemDC,
				m_Object[3].m_rt.x, m_Object[3].m_rt.y, SRCAND) == FALSE)
			{
				return true;
			};
			BitBlt(g_hOffScreenDC, m_Object[3].m_fPosX, m_Object[3].m_fPosY,
				m_Object[3].m_rt.w,
				m_Object[3].m_rt.h,
				m_ColorBitmap.m_hMemDC,
				m_Object[3].m_rt.x, m_Object[3].m_rt.y, SRCINVERT);

			BitBlt(g_hOffScreenDC, m_Object[3].m_fPosX, m_Object[3].m_fPosY,
				m_Object[3].m_rt.w,
				m_Object[3].m_rt.h,
				m_MaskBitmap.m_hMemDC,
				m_Object[3].m_rt.x, m_Object[3].m_rt.y, SRCINVERT);
		}
		for (int iObj = 0;iObj < 4;iObj++)
		{
			if (m_Object[iObj].m_fPosY > 550)
			{
				bBox = true;
			}
		}
	}*/

	
	for (int iTrail = 0;iTrail < 3; iTrail++)
	{
		//m_Trail[iTrail].Render();
		if (BitBlt(g_hOffScreenDC, m_Trail[iTrail].m_fPosX, m_Trail[iTrail].m_fPosY,
			m_Trail[iTrail].m_rt.w,
			m_Trail[iTrail].m_rt.h,
			m_MaskBitmap.m_hMemDC,
			m_Trail[iTrail].m_rt.x, m_Trail[iTrail].m_rt.y, SRCAND) == FALSE)
		{
			return true;
		};
		BitBlt(g_hOffScreenDC, m_Trail[iTrail].m_fPosX, m_Trail[iTrail].m_fPosY,
			m_Trail[iTrail].m_rt.w,
			m_Trail[iTrail].m_rt.h,
			m_ColorBitmap.m_hMemDC,
			m_Trail[iTrail].m_rt.x, m_Trail[iTrail].m_rt.y, SRCINVERT);

		BitBlt(g_hOffScreenDC, m_Trail[iTrail].m_fPosX, m_Trail[iTrail].m_fPosY,
			m_Trail[iTrail].m_rt.w,
			m_Trail[iTrail].m_rt.h,
			m_MaskBitmap.m_hMemDC,
			m_Trail[iTrail].m_rt.x, m_Trail[iTrail].m_rt.y, SRCINVERT);

	/*	BitBlt(g_hOffScreenDC, m_Trail_0[iTrail].m_fPosX, 0,
			50,
			280,
			m_ColorBitmap.m_hMemDC,
			0, 1, SRCCOPY);*/
	}

	_stprintf_s(m_csBuffer, L"점수 : %d",
		m_Hero.m_iget);
	TextOut(m_hOffScreenDC, 0, 25, m_csBuffer, _tcslen(m_csBuffer));
	for (int iObj = 0; iObj < MAX_OBJECT; iObj++)
	{
	
		if (iObj < m_fTimer_One)
		{
			//m_Object_One[iObj].Render();
			if (BitBlt(g_hOffScreenDC, m_Object_One[iObj].m_rtCollide.x, m_Object_One[iObj].m_rtCollide.y,
				m_Object_One[iObj].m_rt.w,
				m_Object_One[iObj].m_rt.h,
				m_MaskBitmap.m_hMemDC,
				m_Object_One[iObj].m_rt.x, m_Object_One[iObj].m_rt.y, SRCAND) == FALSE)
			{
				return true;
			};
			BitBlt(g_hOffScreenDC, m_Object_One[iObj].m_rtCollide.x, m_Object_One[iObj].m_rtCollide.y,
				m_Object_One[iObj].m_rt.w,
				m_Object_One[iObj].m_rt.h,
				m_ColorBitmap.m_hMemDC,
				m_Object_One[iObj].m_rt.x, m_Object_One[iObj].m_rt.y, SRCINVERT);

			BitBlt(g_hOffScreenDC, m_Object_One[iObj].m_rtCollide.x, m_Object_One[iObj].m_rtCollide.y,
				m_Object_One[iObj].m_rt.w,
				m_Object_One[iObj].m_rt.h,
				m_MaskBitmap.m_hMemDC,
				m_Object_One[iObj].m_rt.x, m_Object_One[iObj].m_rt.y, SRCINVERT);
		}
		if (iObj < m_fTimer_Two)
		{
			//m_Object_Two[iObj].Render();
			if (BitBlt(g_hOffScreenDC, m_Object_Two[iObj].m_rtCollide.x, m_Object_Two[iObj].m_rtCollide.y,
				m_Object_Two[iObj].m_rt.w,
				m_Object_Two[iObj].m_rt.h,
				m_MaskBitmap.m_hMemDC,
				m_Object_Two[iObj].m_rt.x, m_Object_Two[iObj].m_rt.y, SRCAND) == FALSE)
			{
				return true;
			};
			BitBlt(g_hOffScreenDC, m_Object_Two[iObj].m_rtCollide.x, m_Object_Two[iObj].m_rtCollide.y,
				m_Object_Two[iObj].m_rt.w,
				m_Object_Two[iObj].m_rt.h,
				m_ColorBitmap.m_hMemDC,
				m_Object_Two[iObj].m_rt.x, m_Object_Two[iObj].m_rt.y, SRCINVERT);

			BitBlt(g_hOffScreenDC, m_Object_Two[iObj].m_rtCollide.x, m_Object_Two[iObj].m_rtCollide.y,
				m_Object_Two[iObj].m_rt.w,
				m_Object_Two[iObj].m_rt.h,
				m_MaskBitmap.m_hMemDC,
				m_Object_Two[iObj].m_rt.x, m_Object_Two[iObj].m_rt.y, SRCINVERT);
		}
		if (iObj < m_fTimer_Thr)
		{
			//m_Object_Thr[iObj].Render();
			if (BitBlt(g_hOffScreenDC, m_Object_Thr[iObj].m_rtCollide.x, m_Object_Thr[iObj].m_rtCollide.y,
				m_Object_Thr[iObj].m_rt.w,
				m_Object_Thr[iObj].m_rt.h,
				m_MaskBitmap.m_hMemDC,
				m_Object_Thr[iObj].m_rt.x, m_Object_Thr[iObj].m_rt.y, SRCAND) == FALSE)
			{
				return true;
			};
			BitBlt(g_hOffScreenDC, m_Object_Thr[iObj].m_rtCollide.x, m_Object_Thr[iObj].m_rtCollide.y,
				m_Object_Thr[iObj].m_rt.w,
				m_Object_Thr[iObj].m_rt.h,
				m_ColorBitmap.m_hMemDC,
				m_Object_Thr[iObj].m_rt.x, m_Object_Thr[iObj].m_rt.y, SRCINVERT);

			BitBlt(g_hOffScreenDC, m_Object_Thr[iObj].m_rtCollide.x, m_Object_Thr[iObj].m_rtCollide.y,
				m_Object_Thr[iObj].m_rt.w,
				m_Object_Thr[iObj].m_rt.h,
				m_MaskBitmap.m_hMemDC,
				m_Object_Thr[iObj].m_rt.x, m_Object_Thr[iObj].m_rt.y, SRCINVERT);
		}
	}
	if (m_Hero.m_fPosX == 550 && m_Hero.m_fPosY == 450)
	{
		if (BitBlt(g_hOffScreenDC, m_Hero.m_fPosX, m_Hero.m_fPosY,
			m_Hero.m_rt.w,
			m_Hero.m_rt.h,
			m_MaskBitmap.m_hMemDC,
			m_Hero.m_rt.x, m_Hero.m_rt.y, SRCAND) == FALSE)
		{
			return true;
		};
		BitBlt(g_hOffScreenDC, m_Hero.m_fPosX, m_Hero.m_fPosY,
			m_Hero.m_rt.w,
			m_Hero.m_rt.h,
			m_ColorBitmap.m_hMemDC,
			m_Hero.m_rt.x, m_Hero.m_rt.y, SRCINVERT);

		BitBlt(g_hOffScreenDC, m_Hero.m_fPosX, m_Hero.m_fPosY,
			m_Hero.m_rt.w,
			m_Hero.m_rt.h,
			m_MaskBitmap.m_hMemDC,
			m_Hero.m_rt.x, m_Hero.m_rt.y, SRCINVERT);
	}
	if (!(m_Hero_Up.m_fPosX == 550 && m_Hero_Up.m_fPosY == 450))
	{
		if (BitBlt(g_hOffScreenDC, m_Hero_Up.m_fPosX, m_Hero_Up.m_fPosY,
			m_Hero_Up.m_rt.w,
			m_Hero_Up.m_rt.h,
			m_MaskBitmap.m_hMemDC,
			m_Hero_Up.m_rt.x, m_Hero_Up.m_rt.y, SRCAND) == FALSE)
		{
			return true;
		};
		BitBlt(g_hOffScreenDC, m_Hero_Up.m_fPosX, m_Hero_Up.m_fPosY,
			m_Hero_Up.m_rt.w,
			m_Hero_Up.m_rt.h,
			m_ColorBitmap.m_hMemDC,
			m_Hero_Up.m_rt.x, m_Hero_Up.m_rt.y, SRCINVERT);

		BitBlt(g_hOffScreenDC, m_Hero_Up.m_fPosX, m_Hero_Up.m_fPosY,
			m_Hero_Up.m_rt.w,
			m_Hero_Up.m_rt.h,
			m_MaskBitmap.m_hMemDC,
			m_Hero_Up.m_rt.x, m_Hero_Up.m_rt.y, SRCINVERT);
	}
	if (BitBlt(g_hOffScreenDC, m_Truck.m_fPosX, m_Truck.m_fPosY,
		m_Truck.m_rt.w,
		m_Truck.m_rt.h,
		m_MaskBitmap.m_hMemDC,
		m_Truck.m_rt.x, m_Truck.m_rt.y, SRCAND) == FALSE)
	{
		return true;
	};
	BitBlt(g_hOffScreenDC, m_Truck.m_fPosX, m_Truck.m_fPosY,
		m_Truck.m_rt.w,
		m_Truck.m_rt.h,
		m_ColorBitmap.m_hMemDC,
		m_Truck.m_rt.x, m_Truck.m_rt.y, SRCINVERT);

	BitBlt(g_hOffScreenDC, m_Truck.m_fPosX, m_Truck.m_fPosY,
		m_Truck.m_rt.w,
		m_Truck.m_rt.h,
		m_MaskBitmap.m_hMemDC,
		m_Truck.m_rt.x, m_Truck.m_rt.y, SRCINVERT);
	//m_Hero.Render();

}
	return true;
}

bool			Sample::Release()
{
	KBitmapMgr::GetInstance().Release();
	m_Background.Release();
	//for (int iObj = 0; iObj < 4; iObj++)
	//{
	//	m_Object[iObj].Release();
	//}
	for (int iObj = 0; iObj < MAX_OBJECT; iObj++)
	{
		m_Object_One[iObj].Release();
		m_Object_Two[iObj].Release();
		m_Object_Thr[iObj].Release();
	}
	for (int iTrail = 0;iTrail < 3; iTrail++)
	{
		m_Trail[iTrail].Release();
	/*	m_Trail_0[iTrail].Release();*/
	}
	vector<KVector*>::iterator _F = m_Data_One.begin();
	vector<KVector*>::iterator _E = m_Data_One.end();
	for (;_F != _E; _F++)
	{
		delete (*_F);
	}
	
	_F = m_Data_Two.begin();
	_E = m_Data_Two.end();
	for (;_F != _E; _F++)
	{
		delete (*_F);
	}

	_F = m_Data_Thr.begin();
	_E = m_Data_Thr.end();
	for (;_F != _E; _F++)
	{
		delete (*_F);
	}
	
	_F = m_Data_Fou.begin();
	_E = m_Data_Fou.end();
	for (;_F != _E; _F++)
	{
		delete (*_F);
	}

	m_Data_One.clear();
	m_Data_Two.clear();
	m_Data_Thr.clear();
	m_Data_Fou.clear();
	
	m_Truck.Release();

	m_pSound.Release();
	m_Box.Release();

	m_Hero.Release();
	m_Hero_Up.Release();

	m_GameOver.Release();
	return true;
}


Sample::Sample()
{
	m_iX = 0;
	m_iY = 0;
}


Sample::~Sample()
{
}

int WINAPI wWinMain(
			HINSTANCE	hInstance,
			HINSTANCE	hPrevInstance,
			LPWSTR		lpCmdLine,
			int			nCmdShow)
{
	Sample Kwin;
	if (Kwin.SetWindow(hInstance) == true)
	{
			Kwin.Run();

	}
	return 0;
}