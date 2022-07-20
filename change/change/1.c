#include"all.h"


int CALLBACK WinMain(HINSTANCE hInstance,
					 HINSTANCE hPrevInstance,
					 LPSTR lpCmdLine,
					 int nCmdShow)
{
	WNDCLASSEX ex;
	HWND hWnd;
	MSG Msg;
	
	
	
	startup();
	
	//1.设计窗口
	BITMAPwall=LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_BITMAP5));
	BITMAPfront=LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_BITMAP4));
	BITMAPleft=LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_BITMAP2));
	BITMAPright=LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_BITMAP3));
	BITMAPbehind=LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_BITMAP1));
	BITMAPback=LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_BITMAP6));
	BITMAPwall1=LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_BITMAP7));
	BITMAPreddoor=LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_BITMAP9));
	BITMAPyellowdoor=LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_BITMAP8));
	BITMAPslmred=LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_BITMAP13));
	BITMAPslmgreen=LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_BITMAP12));
	BITMAPkeyred=LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_BITMAP11));
	BITMAPkeyyellow=LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_BITMAP10));
	BITMAPbat=LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_BITMAP16));
	BITMAPrabbi=LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_BITMAP17));
	BITMAPbonesmall=LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_BITMAP14));
	BITMAPbonemedium=LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_BITMAP15));
	BITMAPvialred=LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_BITMAP18));//红药水
	BITMAPvialblue=LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_BITMAP19));//蓝药水
	BITMAPgemred=LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_BITMAP20));//红宝石
	BITMAPgemblue=LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_BITMAP21));//蓝宝石
	BITMAPaircraft=LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_BITMAP22));//飞行器
	BITMAPstatus=LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_BITMAP23));
	BITMAPkeyblue=LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_BITMAP24));
	BITMAPoracle=LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_BITMAP26));
	BITMAPcriminal=LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_BITMAP25));
	BITMAPprincess=LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_BITMAP28));//公主
	BITMAPvampire=LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_BITMAP27));//吸血鬼
	BITMAPtransmit=LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_BITMAP29));//传送门
	BITMAPbluedoor=LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_BITMAP30));
	BITMAPmediumguardman=LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_BITMAP32));//中等卫兵
	BITMAPbusinessman=LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_BITMAP33));//商人
	BITMAPirondoor=LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_BITMAP31));//铁门
	BITMAPbeijing = LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_BITMAP34));
	srand((unsigned int)time(NULL));
	

	ex.style = CS_HREDRAW | CS_VREDRAW;
	ex.cbSize = sizeof(ex);
	ex.cbClsExtra = 0;
	ex.cbWndExtra = 0;
	ex.hInstance = hInstance;
	ex.hIcon = NULL;
	ex.hCursor = NULL;
	ex.hbrBackground = CreateSolidBrush(RGB(150,0,0));
	ex.hIconSm = NULL;
	ex.lpfnWndProc = MyWNDPROC;	
	ex.lpszMenuName = NULL;
	ex.lpszClassName = "aaa";
	//2.注册窗口
	RegisterClassEx(&ex);
	//3.创建窗口
	hWnd = CreateWindow(ex.lpszClassName,"魔塔",WS_OVERLAPPEDWINDOW,100,100,531,504,NULL,
			NULL,hInstance,NULL);
	//4.显示窗口
	ShowWindow(hWnd,SW_SHOW);
	CreateChildWnd(hInstance);  //创建窗口

	SetTimer(hWnd,1,200,NULL);

	//消息循环
	while(GetMessage(&Msg,NULL,0,0))
	{
		
		//翻译消息
		TranslateMessage(&Msg);
		//分发消息
		DispatchMessage(&Msg);
	}

	return 0;
}
int CreateChildWnd(HINSTANCE hInstance) {
	LPCSTR lClassName = "yueChild";
	CHAR* strTitle = "对话框(鼠标左键继续)";
	int nx = 200;
	int ny = 182+monad*9;
	int nWidth = monad*13+15;
	int nHeight = monad*4;
	//
	WNDCLASSEX wndclass;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.cbSize = sizeof(wndclass);
	wndclass.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wndclass.hCursor = LoadCursor(0, MAKEINTRESOURCE(IDC_ARROW));
	wndclass.hIcon = 0;
	wndclass.hIconSm = 0;
	wndclass.hInstance = hInstance;
	wndclass.lpfnWndProc = WindowProcChild;
	wndclass.lpszClassName = lClassName;
	wndclass.lpszMenuName = 0;
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	// 2.  注册
	RegisterClassEx(&wndclass);

	//  3.  创建
	hwndChild = CreateWindow(lClassName, strTitle, WS_OVERLAPPEDWINDOW, nx, ny, nWidth, nHeight, hwnd, 0, hInstance, 0);


	return 0;
}
        
LRESULT CALLBACK MyWNDPROC(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam)
{

	HDC hdc;
	PAINTSTRUCT ps;
	const RECT rect = { 0,0,1000,1000 };
	
	switch(message)
	{
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:

		switch(wParam)
		{
		case VK_UP:

				fx=up;

			break;
		case VK_DOWN:

				fx=down;

			break;
		case VK_LEFT:

				fx=left;

			break;
		case VK_RIGHT:

				fx=right;

			break;
		
		
			

		}
		
		Move();

		if(Ismove())
		{	
			hdc=GetDC(hWnd);
			Showbackground(hdc);
			InitInfotxt(hdc);
			Showonestoreywall(hdc);
			Showalldoor(hdc);
			Showallkey(hdc);
			Showallslm(hdc);
			ShowHero(hdc);
			ReleaseDC(hWnd,hdc);
			
		
		}
		else
		{
			Moveback();		
		}
		InvalidateRect(hWnd, &rect, TRUE);

		break;
	

	case WM_PAINT:		//重绘消息
		hdc=BeginPaint(hWnd,&ps);

		Showbackground(hdc);
		Showstatusback(hdc);
		InitInfotxt(hdc);
		Showonestoreywall(hdc);
		Showalldoor(hdc);
		Showallkey(hdc);
		Showallslm(hdc);
		ShowHero(hdc);
		


		EndPaint(hWnd,&ps);
		break;
	case WM_TIMER:

		break;
	case WM_RBUTTONDOWN:
		hideChildWin();
		break;
	}

	return DefWindowProc(hWnd,message,wParam,lParam);
}
LRESULT CALLBACK WindowProcChild(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	HDC hdc;
	PAINTSTRUCT ps;
	hdc = BeginPaint(hwnd, &ps);
	if (uMsg == WM_KEYDOWN)  //重绘消息
	{
		TextOut(hdc, 0,36, "欢迎来到魔塔", 6);
	}
	EndPaint(hwnd, &ps);
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
void showChildWin() {
	//  4.  显示窗口
	ShowWindow(hwndChild, SW_SHOW);

}
void hideChildWin() {
	//  4.  隐藏窗口
	ShowWindow(hwndChild, SW_HIDE);

}
void Showbackground(HDC hdc)
{
	HDC hdcmen=CreateCompatibleDC(hdc);
	int i,j;
	SelectObject(hdcmen,BITMAPwall);
	for(i=100;i<=weight;i+=32)
	{
		for(j=50;j<=height;j+=32)
		{
			if(((j==50&&i>=100)||(i==100&&j>=50)||i==484||j==434)&&(i<=484&&j<=434))
			{
				BitBlt(hdc,i,j,32,32,hdcmen,0,0,SRCCOPY);
			}
		}
	}
	SelectObject(hdcmen,BITMAPback);
	for(i=132;i<=452;i+=32)
	{
		for(j=82;j<=420;j+=32)
		{
			BitBlt(hdc,i,j,32,32,hdcmen,0,0,SRCCOPY);
		}
	}
	

	DeleteDC(hdcmen);
}
void startup()
{
	srand((unsigned int)time(NULL));
	height=504;
	weight=531;
}
void Showonestoreywall(HDC hdc)
{
	HDC hdcmen=CreateCompatibleDC(hdc);
	int i,j;
	SelectObject(hdcmen,BITMAPwall1);
	switch(g_level)
	{
	case 1:
		for(i=132;i<=452;i+=32)
		{
			for(j=82;j<=420;j+=32)
			{
				if((i==228&&j>=178)||(j==114&&i<=432)||(i==356&&j>=338)||(i==420&&j>=82+32*2&&j<=82+32*6)
					||(j==82+32*6&&i>=132+32*5&&i<=132+32*8)||(i==132+32*5&&j>=82+32*2&&j<=82+32*4)
					||(j==82+32*4&&i>=132+32*6&&i<=132+32*7)||(i==132&&j==82+32*4)||(i==132+32*2&&j==82+32*4)
					||(i==132+32*4&&j==82+32*8)||(i==132+32*6&&j==82+32*8)||(i==132+32*8&&j==82+32*8)
					||(i==132+32*10&&j==82+32*8)||(i==132&&j==82+32*7)||(i==132+32*2&&j==82+32*7))
				{
					BitBlt(hdc,i,j,32,32,hdcmen,0,0,SRCCOPY);
				}
			}
		}
		break;
	case 2:
		for(i=132;i<=452;i+=32)
		{
			for(j=82;j<=420;j+=32)
			{
				if((i==132+monad*1&&j>=82+monad*2&&j<82+monad*7)||(i==132+monad*1&&j>=82+monad*8)||(i>=132+monad*2 && j==82+monad*2 && i<=132+monad*5)
					||(i>=132+monad*7&&j==82+monad*2&&i<=132+monad*10)||(i>=132+monad*8 && j==82+monad*5&& i<=132+monad*10)
					||(i>=132+monad*8&&j==82+monad*8&&i<=132+monad*10)||(i>=132+monad*2&&j==82+monad*5&&i<=132+monad*4)
					||(i>=132+monad*2&&j==82+monad*8&&i<=132+monad*4)||(i>=132+monad*2&&j==82+monad*1&&i<=132+monad*3)
					||(i>=132+monad*9&&j==82+monad*1&&i<=132+monad*10)||(i==132+monad*4&&j==82+monad*3)
					||(i==132+monad*8&&j==82+monad*3)||(i==132+monad*4&&j==82+monad*6)||(i==132+monad*4&&j==82+monad*9)
					||(i==132+monad*8&&j==82+monad*6||(i==132+monad*8&&j==82+monad*9)))
				{
					BitBlt(hdc,i,j,32,32,hdcmen,0,0,SRCCOPY);
				}
			}
		}
		break;
	}
	DeleteDC(hdcmen);
}
void ShowHero(HDC hdc)
{

	HDC hdcmen =CreateCompatibleDC(hdc);
	switch (fx)
	{
	case up:
		SelectObject(hdcmen,BITMAPfront);
		break;
	case down:
		SelectObject(hdcmen,BITMAPbehind);
		break;
	case left:
		SelectObject(hdcmen,BITMAPleft);
		break;
	case right:
		SelectObject(hdcmen,BITMAPright);
		break;
	default:
		break;
	}
	BitBlt(hdc,hero_x,hero_y,32,32,hdcmen,0,0,SRCCOPY);
	DeleteDC(hdcmen);
}
void Move()
{
	switch(fx)
	{
	case up:
		hero_y-=monad;
		break;
	case down:
		hero_y+=monad;
		break;
	case left:
		hero_x-=monad;
		break;
	case right:
		hero_x+=monad;
		break;
	}
}
BOOL Ismove()
{
	int i=hero_x;
	int j=hero_y;
	switch(g_level)
	{
	case 1:
		if(hero_x<=100||hero_y<=50||hero_y>=420||hero_x>=484||(hero_x==228&&hero_y>=178)||(hero_y==114&&hero_x<=432)
			||(hero_x==356&&hero_y>=338)||(hero_x==420&&hero_y>=82+32*2&&hero_y<=82+32*6)||Isfighttingmediumguardman(Medium)
					||(hero_y==82+32*6&&hero_x>=132+32*5&&hero_x<=132+32*8)||(hero_x==132+32*5&&hero_y>=82+32*2&&hero_y<=82+32*4)
					||(hero_y==82+32*4&&hero_x>=132+32*6&&hero_x<=132+32*7)||(hero_x==132&&hero_y==82+32*4)||(hero_x==132+32*2&&hero_y==82+32*4)
					||(hero_x==132+32*4&&hero_y==82+32*8)||(hero_x==132+32*6&&hero_y==82+32*8)||(hero_x==132+32*8&&hero_y==82+32*8)
					||(hero_x==132+32*10&&hero_y==82+32*8)||(hero_x==132&&hero_y==82+32*7)||(hero_x==132+32*2&&hero_y==82+32*7)
					||Iscanthroughreddoor()||Iscanthroughyellowdoor()||ISfightinggreenslm(slmgreen)||ISfightingredslm(slmred)
					||Isfightingbat(Batsmall)||Isfightingbonemedium(Bonemedium)||Isfightingbonesmall(Bonesmall)||Isfightingrabbi(Rabbielementary))
		{
			return FALSE;
		}
		return TRUE;
		break;
	case 2:
		if(hero_x<=100||hero_y<=50||hero_y>=420||hero_x>=484
			||Iscanthroughreddoor()||Iscanthroughyellowdoor()||ISfightinggreenslm(slmgreen)||ISfightingredslm(slmred)||Iscanthroughbluedoor()
		  ||Isfightingbat(Batsmall)||Isfightingbonemedium(Bonemedium)||Isfightingbonesmall(Bonesmall)||Isfightingrabbi(Rabbielementary)
		  ||(i==132+monad*1&&j>=82+monad*2&&j<82+monad*7)||(i==132+monad*1&&j>=82+monad*8)||(i>=132+monad*2 && j==82+monad*2 && i<=132+monad*5)
					||(i>=132+monad*7&&j==82+monad*2&&i<=132+monad*10)||(i>=132+monad*8 && j==82+monad*5&& i<=132+monad*10)
					||(i>=132+monad*8&&j==82+monad*8&&i<=132+monad*10)||(i>=132+monad*2&&j==82+monad*5&&i<=132+monad*4)
					||(i>=132+monad*2&&j==82+monad*8&&i<=132+monad*4)||(i>=132+monad*2&&j==82+monad*1&&i<=132+monad*3)
					||(i>=132+monad*9&&j==82+monad*1&&i<=132+monad*10)||(i==132+monad*4&&j==82+monad*3)||(i==132+monad*8&&j==82+monad*6)
					||(i==132+monad*8&&j==82+monad*3)||(i==132+monad*4&&j==82+monad*6)||(i==132+monad*4&&j==82+monad*9)
					||Isfighttingmediumguardman(Medium)||(i==132+monad*8&&j==82+monad*9))
		{
			return FALSE;
		}
		return TRUE;
		break;
	}
	return TRUE;
}
void Moveback()
{
	switch(fx)
	{
	case up:
		hero_y+=monad;
		break;
	case down:
		hero_y-=monad;
		break;
	case left:
		hero_x+=monad;
		break;
	case right:
		hero_x-=monad;
		break;
	}
}

BOOL Iscanthroughreddoor()
{
	switch(g_level)
	{
		case 1:
		if((hero_x==door1_x&&hero_y==door1_y))
		{
			if(Hero.redkey>=1)
			{
				Hero.redkey--;
				return FALSE;
			}
			return TRUE;
		}
		return FALSE;
		break;
	}
	return FALSE;
}
BOOL Iscanthroughbluedoor()
{
	switch(g_level)
	{
		case 2:
		if((hero_x==door7_x&&hero_y==door7_y))
		{
			if(Hero.bluekey>=1)
			{
				Hero.bluekey--;
				return FALSE;
			}
			return TRUE;
		}
		return FALSE;
		break;
	}
	return FALSE;
}
BOOL Iscanthroughyellowdoor()
{
	switch(g_level)
	{
		case 1:
		if(((hero_x==door2_x&&hero_y==door2_y)
			||(hero_x==door3_x&&hero_y==door3_y)||(hero_x==door4_x&&hero_y==door4_y)
			||(hero_x==door5_x&&hero_y==door5_y)||(hero_x==door6_x&&hero_y==door6_y)))
		{
			if(Hero.yellowkey>=1)
			{
				Hero.yellowkey--;
				return FALSE;
			}
			return TRUE;
		}
		return FALSE;
		break;
	}
	return FALSE;
}
BOOL ISfightingredslm(Slm slm)
{
	int reduce=0;
	int monsterlife=slm.LIFE;

	while(monsterlife>0)
	{
		monsterlife=monsterlife-Hero.ATK+slm.DEF;
		if(monsterlife>0)
		{
			reduce=reduce+slm.ATK-Hero.DEF;
		}
	}
	switch(g_level)
	{
		case 1:
		if((hero_x==monster2_x&&hero_y==monster2_y))
		{
			if(Hero.LIFE>reduce)
			{
				if(Hero.ATK>slm.DEF)
				{
					while(slm.LIFE>0)
					{
						slm.LIFE=slm.LIFE-(Hero.ATK-slm.DEF);
						if(slm.LIFE>0)
						{
							Hero.LIFE=Hero.LIFE-(slm.ATK-Hero.DEF);
						}
					}
					Hero.GOLD+=slm.GOLD;
					return FALSE;
				}
			}
			return TRUE;
		}
		return FALSE;
		break;
	}
	return FALSE;
}
BOOL Isfightingbat(Bat bat)
{
	int reduce=0;
	int monsterlife=bat.LIFE;

	while(monsterlife>0)
	{
		monsterlife=monsterlife-Hero.ATK+bat.DEF;
		if(monsterlife>0)
		{
			reduce=reduce+bat.ATK-Hero.DEF;
		}
	}
	switch(g_level)
	{
		case 1:
		if((hero_x==bat1_x&&hero_y==bat1_y)||(hero_x==bat2_x&&hero_y==bat2_y)
		||(hero_x==bat3_x&&hero_y==bat3_y))
		{
			if(Hero.LIFE>reduce)
			{
				if(Hero.ATK>bat.DEF)
				{
					while(bat.LIFE>0)
					{
						bat.LIFE=bat.LIFE-(Hero.ATK-bat.DEF);
						if(bat.LIFE>0)
						{
							Hero.LIFE=Hero.LIFE-(bat.ATK-Hero.DEF);
						}
					}
					Hero.GOLD+=bat.GOLD;
					return FALSE;
				}
			}
			return TRUE;
		}
		return FALSE;
		break;
	}
	return FALSE;
}
BOOL Isfightingrabbi(Rabbi rabbi)
{
	int reduce=0;
	int monsterlife=rabbi.LIFE;

	while(monsterlife>0)
	{
		monsterlife=monsterlife-Hero.ATK+rabbi.DEF;
		if(monsterlife>0)
		{
			reduce=reduce+rabbi.ATK-Hero.DEF;
		}
	}
	switch(g_level)
	{
		case 1:
		if((hero_x==rabbi_x&&hero_y==rabbi_y))
		{
			if(Hero.LIFE>reduce)
			{
				if(Hero.ATK>rabbi.DEF)
				{
					while(rabbi.LIFE>0)
					{
						rabbi.LIFE=rabbi.LIFE-(Hero.ATK-rabbi.DEF);
						if(rabbi.LIFE>0)
						{
							Hero.LIFE=Hero.LIFE-(rabbi.ATK-Hero.DEF);
						}
					}
					Hero.GOLD+=rabbi.GOLD;
					return FALSE;
				}
			}
			return TRUE;
		}
		return FALSE;
		break;
	}
	return FALSE;
}
BOOL Isfightingbonesmall(Bone bonesmall)
{
	int reduce=0;
	int monsterlife=bonesmall.LIFE;

	while(monsterlife>0)
	{
		monsterlife=monsterlife-Hero.ATK+bonesmall.DEF;
		if(monsterlife>0)
		{
			reduce=reduce+bonesmall.ATK-Hero.DEF;
		}
	}
	switch(g_level)
	{
		case 1:
		if((hero_x==bonesmall_x&&hero_y==bonesmall_y))
		{
			if(Hero.LIFE>reduce)
			{
				if(Hero.ATK>bonesmall.DEF)
				{
					while(bonesmall.LIFE>0)
					{
						bonesmall.LIFE=bonesmall.LIFE-(Hero.ATK-bonesmall.DEF);
						if(bonesmall.LIFE>0)
						{
							Hero.LIFE=Hero.LIFE-(bonesmall.ATK-Hero.DEF);
						}
					}
					Hero.GOLD+=bonesmall.GOLD;
					return FALSE;
				}
			}
			return TRUE;
		}
		return FALSE;
		break;
	}
	return FALSE;
}
BOOL Isfightingbonemedium(Bone bonemedium)
{
	int reduce=0;
	int monsterlife=bonemedium.LIFE;

	while(monsterlife>0)
	{
		monsterlife=monsterlife-Hero.ATK+bonemedium.DEF;
		if(monsterlife>0)
		{
			reduce=reduce+bonemedium.ATK-Hero.DEF;
		}
	}
	switch(g_level)
	{
		case 1:
		if((hero_x==bonemedium_x&&hero_y==bonemedium_y))
		{
			if(Hero.LIFE>reduce)
			{
				if(Hero.ATK>bonemedium.DEF)
				{
					while(bonemedium.LIFE>0)
					{
						bonemedium.LIFE=bonemedium.LIFE-(Hero.ATK-bonemedium.DEF);
						if(bonemedium.LIFE>0)
						{
							Hero.LIFE=Hero.LIFE-(bonemedium.ATK-Hero.DEF);
						}
					}
					Hero.GOLD+=bonemedium.GOLD;
					return FALSE;
				}
			}
			return TRUE;
		}
		return FALSE;
		break;
	}
	return FALSE;
}
BOOL ISfightinggreenslm(Slm slm)
{
	int reduce=0;
	int monsterlife=slm.LIFE;
	while(monsterlife>0)
	{
		monsterlife=monsterlife-Hero.ATK+slm.DEF;
		if(monsterlife>0)
		{
			reduce=reduce+slm.ATK-Hero.DEF;
		}
	}
	switch(g_level)
	{
		case 1:
		if((hero_x==monster1_x&&hero_y==monster1_y)
			||(hero_x==monster3_x&&hero_y==monster3_y)||(hero_x==monster4_x&&hero_y==monster4_y)
			||(hero_x==monster5_x&&hero_y==monster5_y))
		{
			if(Hero.LIFE>reduce)
			{
				if(Hero.ATK>slm.DEF)
				{
					while(slm.LIFE>0)
					{
						slm.LIFE=slm.LIFE-(Hero.ATK-slm.DEF);
						if(slm.LIFE>0)
						{
							Hero.LIFE=Hero.LIFE-(slm.ATK-Hero.DEF);
						}
					}
					Hero.GOLD+=slm.GOLD;
					return FALSE;
				}
			}
			return TRUE;
		}
		return FALSE;
	break;
	}
	return FALSE;
}
BOOL Isfighttingmediumguardman(Guardman mediumguardman)
{
	int reduce=0;
	int monsterlife=mediumguardman.LIFE;
	while(monsterlife>0)
	{
		monsterlife=monsterlife-Hero.ATK+mediumguardman.DEF;
		if(monsterlife>0)
		{
			reduce=reduce+mediumguardman.ATK-Hero.DEF;
		}
	}
	switch(g_level)
	{
		case 2:
		if((hero_x==mediumguardman1_x&&hero_y==mediumguardman1_y)
			||(hero_x==mediumguardman2_x&&hero_y==mediumguardman2_y))
		{
			if(Hero.LIFE>reduce)
			{
				if(Hero.ATK>mediumguardman.DEF)
				{
					while(mediumguardman.LIFE>0)
					{
						mediumguardman.LIFE=mediumguardman.LIFE-(Hero.ATK-mediumguardman.DEF);
						if(mediumguardman.LIFE>0)
						{
							Hero.LIFE=Hero.LIFE-(mediumguardman.ATK-Hero.DEF);
						}
					}
					Hero.GOLD+=mediumguardman.GOLD;
					return FALSE;
				}
				return TRUE;
			}
			return TRUE;
		}
		return FALSE;
		break;
	}
	return FALSE;
}
void Showdoor(HDC hdc)
{
	HDC hdcmen=CreateCompatibleDC(hdc);
	switch(g_level)
	{
	case 1:
		SelectObject(hdcmen,BITMAPreddoor);
		BitBlt(hdc,door1_x,door1_y,32,32,hdcmen,0,0,SRCCOPY);
		SelectObject(hdcmen,BITMAPyellowdoor);
		BitBlt(hdc,door2_x,door2_y,32,32,hdcmen,0,0,SRCCOPY);
		BitBlt(hdc,door3_x,door3_y,32,32,hdcmen,0,0,SRCCOPY);
		BitBlt(hdc,door4_x,door4_y,32,32,hdcmen,0,0,SRCCOPY);
		BitBlt(hdc,door5_x,door5_y,32,32,hdcmen,0,0,SRCCOPY);
		BitBlt(hdc,door6_x,door6_y,32,32,hdcmen,0,0,SRCCOPY);
		break;
	case 2:
		SelectObject(hdcmen,BITMAPbluedoor);
		BitBlt(hdc,door7_x,door7_y,32,32,hdcmen,0,0,SRCCOPY);
		break;
	}
	DeleteDC(hdcmen);
	
}

void Showalldoor(HDC hdc)
{
	switch(g_level)
	{
	case 1:
		if(hero_x==door1_x&&hero_y==door1_y)
		{
			door1_x=-100;
			door1_y=-100;
		}

		if(hero_x==door2_x&&hero_y==door2_y)
		{
			door2_x=-100;
			door2_y=-100;
		}
		if((hero_x==door3_x&&hero_y==door3_y))
		{
			door3_x=-100;
			door3_y=-100;
		}
		if(hero_x==door4_x&&hero_y==door4_y)
		{
			door4_x=-100;
			door4_y=-100;
		}
		if(hero_x==door5_x&&hero_y==door5_y)
		{
			door5_x=-100;
			door5_y=-100;
		}
		if(hero_x==door6_x&&hero_y==door6_y)
		{
			door6_x=-100;
			door6_y=-100;
		}
		break;
	case 2:
		if(hero_x==door7_x&&hero_y==door7_y)
		{
			door7_x=-100;
			door7_y=-100;
		}
		break;
	}
	Showdoor(hdc);
}

void Showyellowkey(HDC hdc)
{
	HDC hdcmen=CreateCompatibleDC(hdc);
	SelectObject(hdcmen,BITMAPkeyyellow);
	//TransparentBlt(
	//	hdc, //目标DC（人物图将要被放上去的DC）
	//	key6_x, //目标矩形左上角x坐标（人物图的起始x坐标）
	//	key6_y, //目标矩形左上角y坐标（人物图的起始y坐标）
	//	32, //目标矩形的宽度（贴在背景上的人物图的宽度）
	//	32,//目标矩形的高度（贴在背景上的人物图的高度）
	//	hdcmen, //指向源设备环境的句柄（已经贴上人物贴图的DC）
	//	0,//源矩形左上角x坐标
	//	0, //源矩形左上角y坐标
	//	32, //准备贴在背景上的贴图的宽度
	//	32,//准备贴在背景上的贴图的高度
	//	(255, 255, 255)//RGB值，贴图中准备去掉的颜色的RGB
	//);
	//BitBlt(hdc, key6_x, key6_y, 32, 32, hdcmen, 0, 0, SRCAND);
	BitBlt(hdc, key6_x, key6_y, 32, 32, hdcmen, 0, 0, SRCPAINT);
	
	/*BitBlt(hdc, key6_x, key6_y, 32, 32, hdcmen, 0, 0, SRCCOPY);*/
	switch(g_level)
	{
	case 1:
		
		BitBlt(hdc,key1_x,key1_y,32,32,hdcmen,0,0, SRCPAINT);
		BitBlt(hdc,key2_x,key2_y,32,32,hdcmen,0,0, SRCPAINT);
		BitBlt(hdc,key3_x,key3_y,32,32,hdcmen,0,0, SRCPAINT);
		BitBlt(hdc,key4_x,key4_y,32,32,hdcmen,0,0, SRCPAINT);
		
		break;
	case 2:
		BitBlt(hdc,key9_x,key9_y,32,32,hdcmen,0,0, SRCPAINT);
		BitBlt(hdc,key10_x,key10_y,32,32,hdcmen,0,0, SRCPAINT);
		BitBlt(hdc,key11_x,key11_y,32,32,hdcmen,0,0, SRCPAINT);
		break;
	}
	DeleteDC(hdcmen);
}
void Showbluekey(HDC hdc)
{
	HDC hdcmen=CreateCompatibleDC(hdc);
	SelectObject(hdcmen, BITMAPkeyblue);
	BitBlt(hdc, key7_x, key7_y, 32, 32, hdcmen, 0, 0, SRCPAINT);
	switch(g_level)
	{
	case 1:
		
		
	break;
	}
	DeleteDC(hdcmen);
	
}
void Showredkey(HDC hdc)
{
	HDC hdcmen=CreateCompatibleDC(hdc);
	SelectObject(hdcmen,BITMAPkeyred);
	BitBlt(hdc, key8_x, key8_y, 32, 32, hdcmen, 0, 0, SRCPAINT);
	switch(g_level)
	{
	case 1:
		BitBlt(hdc,key5_x,key5_y,32,32,hdcmen,0,0, SRCPAINT);
		
	break;
	}
	DeleteDC(hdcmen);
}

void Showallkey(HDC hdc)
{
	switch(g_level)
	{
	case 1:
		if(hero_x==key1_x&&hero_y==key1_y)
		{
			key1_x=-100;
			key1_y=-100;
			Hero.yellowkey++;
		}
		if(hero_x==key2_x&&hero_y==key2_y)
		{
			key2_x=-100;
			key2_y=-100;
			Hero.yellowkey++;
		}
		if(hero_x==key3_x&&hero_y==key3_y)
		{
			key3_x=-100;
			key3_y=-100;
			Hero.yellowkey++;
		}
		if(hero_x==key4_x&&hero_y==key4_y)
		{
			key4_x=-100;
			key4_y=-100;
			Hero.yellowkey++;
		}
		if(hero_x==key5_x&&hero_y==key5_y)
		{
			key5_x=-100;
			key5_y=-100;
			Hero.redkey++;
		}
		break;
	case 2:
		if(hero_x==key9_x&&hero_y==key9_y)
		{
			key9_x=-100;
			key9_y=-100;
			Hero.yellowkey++;
		}
		if(hero_x==key10_x&&hero_y==key10_y)
		{
			key10_x=-100;
			key10_y=-100;
			Hero.yellowkey++;
		}
		if(hero_x==key11_x&&hero_y==key11_y)
		{
			key11_x=-100;
			key11_y=-100;
			Hero.yellowkey++;
		}
		break;
	}
	Showyellowkey(hdc);
	Showbluekey(hdc);
	Showredkey(hdc);
}

void Showmslm(HDC hdc)
{
	HDC hdcmen=CreateCompatibleDC(hdc);
	
	switch(g_level)
	{
	case 1:
		SelectObject(hdcmen,BITMAPslmgreen);
		BitBlt(hdc,monster1_x,monster1_y,32,32,hdcmen,0,0,SRCPAINT);
		BitBlt(hdc,monster3_x,monster3_y,32,32,hdcmen,0,0,SRCPAINT);
		BitBlt(hdc,monster4_x,monster4_y,32,32,hdcmen,0,0,SRCPAINT);
		BitBlt(hdc,monster5_x,monster5_y,32,32,hdcmen,0,0,SRCPAINT);
		SelectObject(hdcmen,BITMAPslmred);
		BitBlt(hdc,monster2_x,monster2_y,32,32,hdcmen,0,0, SRCPAINT);
		break;
	}
	DeleteDC(hdcmen);
}
void Showallslm(HDC hdc)
{
	switch(g_level)
	{
	case 1:
		if(hero_x==monster1_x&&hero_y==monster1_y)
		{
			monster1_x=-100;
			monster1_y=-100;
		}
		if(hero_x==monster2_x&&hero_y==monster2_y)
		{
			monster2_x=-100;
			monster2_y=-100;
		}
		if(hero_x==monster3_x&&hero_y==monster3_y)
		{
			monster3_x=-100;
			monster3_y=-100;
		}
		if(hero_x==monster4_x&&hero_y==monster4_y)
		{
			monster4_x=-100;
			monster4_y=-100;
		}
		if(hero_x==monster5_x&&hero_y==monster5_y)
		{
			monster5_x=-100;
			monster5_y=-100;
		}
		if(hero_x==bonemedium_x&&hero_y==bonemedium_y)
		{
			bonemedium_x=-100;
			bonemedium_y=-100;

		}
		if(hero_x==bat1_x&&hero_y==bat1_y)
		{
			bat1_x=-100;
			bat1_y=-100;

		}
		if(hero_x==bat2_x&&hero_y==bat2_y)
		{
			bat2_x=-100;
			bat2_y=-100;

		}
		if(hero_x==bat3_x&&hero_y==bat3_y)
		{
			bat3_x=-100;
			bat3_y=-100;

		}
		if(hero_x==rabbi_x&&hero_y==rabbi_y)
		{
			rabbi_x=-100;
			rabbi_y=-100;

		}
		if(hero_x==bonesmall_x&&hero_y==bonesmall_y)
		{
			bonesmall_x=-100;
			bonesmall_y=-100;

		}
		if(hero_x==vialred1_x&&hero_y==vialred1_y)
		{
			vialred1_x=-100;
			vialred1_y=-100;
			Hero.LIFE+=100;
		}
		if(hero_x==vialred2_x&&hero_y==vialred2_y)
		{
			vialred2_x=-100;
			vialred2_y=-100;
			Hero.LIFE+=100;
		}
		if(hero_x==vialred3_x&&hero_y==vialred3_y)
		{
			vialred3_x=-100;
			vialred3_y=-100;
			Hero.LIFE+=100;
		}
		if(hero_x==vialred4_x&&hero_y==vialred4_y)
		{
			vialred4_x=-100;
			vialred4_y=-100;
			Hero.LIFE+=100;
		}
		if(hero_x==vialblue_x&&hero_y==vialblue_y)
		{
			vialblue_x=-100;
			vialblue_y=-100;
			Hero.LIFE+=200;
		}
		if(hero_x==gemred_x&&hero_y==gemred_y)
		{
			gemred_x=-100;
			gemred_y=-100;
			Hero.ATK+=2;
		}
		if(hero_x==gemblue_x&&hero_y==gemblue_y)
		{
			gemblue_x=-100;
			gemblue_y=-100;
			Hero.DEF+=2;
		}
		if(hero_x==aircraft_x&&hero_y==aircraft_y)
		{
			aircraft_x=-100;
			aircraft_y=-100;
			Hero.aircraft++;
		}
		if(hero_x==oracle_x&&hero_y==oracle_y)
		{
			oracle_x=-100;
			oracle_y=-100;
			showChildWin();
		}
		if(hero_x==criminal_x&&hero_y==criminal_y)
		{
			criminal_x=-100;
			criminal_y=-100;
		}
		if(hero_x==transmit_x&&hero_y==transmit_y)
		{
			transmit_x=-100;
			transmit_y=-100;
			g_level=2;
			Showmslm(hdc);
			Showoracle(hdc);
			Showcriminal(hdc);
			Showbat(hdc);
			Showrabbi(hdc);
			Showbonesmall(hdc);
			Showbonemedium(hdc);
			Showaircraft(hdc);
			Showgemblue(hdc);
			Showgemred(hdc);
			Showvialblue(hdc);
			Showvialred(hdc);
			Showtransmit(hdc);
			Showbusinessman(hdc);
			Showmediumguardman(hdc);
			hero_x=132;
			hero_y=82+monad*9;
			transmit1_x=132;
			transmit1_y=82+monad*10;
		}
		break;
	case 2:
		if(hero_x==businessman_x&&hero_y==businessman_y)
		{
			businessman_x=-100;
			businessman_y=-100;
		}
		if(hero_x==transmit1_x&&hero_y==transmit1_y)
		{
			transmit1_x=-100;
			transmit1_y=-100;
			g_level=1;
			Showmslm(hdc);
			Showoracle(hdc);
			Showcriminal(hdc);
			Showbat(hdc);
			Showrabbi(hdc);
			Showbonesmall(hdc);
			Showbonemedium(hdc);
			Showaircraft(hdc);
			Showgemblue(hdc);
			Showgemred(hdc);
			Showvialblue(hdc);
			Showvialred(hdc);
			Showtransmit(hdc);
			Showbusinessman(hdc);
			Showmediumguardman(hdc);
			hero_x=132+monad*1;
			hero_y=82;
			transmit_x=132;
			transmit_y=82;
		}
		if(hero_x==oracle1_x&&hero_y==oracle1_y)
		{
			oracle1_x=-100;
			oracle1_y=-100;
		}
		if(hero_x==mediumguardman1_x && hero_y==mediumguardman1_y)
		{
			mediumguardman1_x=-500;
			mediumguardman1_y=-500;
		}
		if(hero_x==mediumguardman2_x && hero_y==mediumguardman2_y)
		{
			mediumguardman2_x=-500;
			mediumguardman2_y=-500;
		}
		break;
	}

	Showmslm(hdc);
	Showoracle(hdc);
	Showcriminal(hdc);
	Showbat(hdc);
	Showrabbi(hdc);
	Showbonesmall(hdc);
	Showbonemedium(hdc);
	Showaircraft(hdc);
	Showgemblue(hdc);
	Showgemred(hdc);
	Showvialblue(hdc);
	Showvialred(hdc);
	Showtransmit(hdc);
	Showbusinessman(hdc);
	Showmediumguardman(hdc);
}

void Showbat(HDC hdc)
{
	HDC hdcmen=CreateCompatibleDC(hdc);
	SelectObject(hdcmen,BITMAPbat);
	switch(g_level)
	{
	case 1:
		BitBlt(hdc,bat1_x,bat1_y,32,32,hdcmen,0,0,SRCPAINT);
		BitBlt(hdc,bat2_x,bat2_y,32,32,hdcmen,0,0,SRCPAINT);
		BitBlt(hdc,bat3_x,bat3_y,32,32,hdcmen,0,0,SRCPAINT);
		break;
	}
	DeleteDC(hdcmen);
}
void Showrabbi(HDC hdc)
{
	HDC hdcmen=CreateCompatibleDC(hdc);
	SelectObject(hdcmen,BITMAPrabbi);
	switch(g_level)
	{
		case 1:
		BitBlt(hdc,rabbi_x,rabbi_y,32,32,hdcmen,0,0, SRCPAINT);
		break;
	}
	DeleteDC(hdcmen);
}
void Showbonesmall(HDC hdc)
{
	HDC hdcmen=CreateCompatibleDC(hdc);
	SelectObject(hdcmen,BITMAPbonesmall);
	switch(g_level)
	{
		case 1:
		BitBlt(hdc,bonesmall_x,bonesmall_y,32,32,hdcmen,0,0, SRCPAINT);
		break;
	}
	DeleteDC(hdcmen);
}
void Showbonemedium(HDC hdc)
{
	HDC hdcmen=CreateCompatibleDC(hdc);
	SelectObject(hdcmen,BITMAPbonemedium);
	switch(g_level)
	{
		case 1:
		BitBlt(hdc,bonemedium_x,bonemedium_y,32,32,hdcmen,0,0, SRCPAINT);
		break;
	}
	DeleteDC(hdcmen);
}


void Showvialred(HDC hdc)
{
	HDC hdcmen=CreateCompatibleDC(hdc);
	SelectObject(hdcmen,BITMAPvialred);
	switch(g_level)
	{
		case 1:
		BitBlt(hdc,vialred1_x,vialred1_y,32,32,hdcmen,0,0,SRCPAINT);
		BitBlt(hdc,vialred2_x,vialred2_y,32,32,hdcmen,0,0,SRCPAINT);
		BitBlt(hdc,vialred3_x,vialred3_y,32,32,hdcmen,0,0,SRCPAINT);
		BitBlt(hdc,vialred4_x,vialred4_y,32,32,hdcmen,0,0,SRCPAINT);
		break;
	}
	DeleteDC(hdcmen);
}
void Showvialblue(HDC hdc)
{
	HDC hdcmen=CreateCompatibleDC(hdc);
	SelectObject(hdcmen,BITMAPvialblue);
	switch(g_level)
	{
		case 1:
		BitBlt(hdc,vialblue_x,vialblue_y,32,32,hdcmen,0,0, SRCPAINT);
		break;
	}
	DeleteDC(hdcmen);
}
void Showgemred(HDC hdc)
{
	HDC hdcmen=CreateCompatibleDC(hdc);
	SelectObject(hdcmen,BITMAPgemred);
	switch(g_level)
	{
		case 1:
		BitBlt(hdc,gemred_x,gemred_y,32,32,hdcmen,0,0, SRCPAINT);
		break;
	}
	DeleteDC(hdcmen);
}
void Showgemblue(HDC hdc)
{
	HDC hdcmen=CreateCompatibleDC(hdc);
	SelectObject(hdcmen,BITMAPgemblue);
	switch(g_level)
	{
		case 1:
		BitBlt(hdc,gemblue_x,gemblue_y,32,32,hdcmen,0,0, SRCPAINT);
		break;
	}
	DeleteDC(hdcmen);
}
void Showaircraft(HDC hdc)
{
	HDC hdcmen=CreateCompatibleDC(hdc);
	SelectObject(hdcmen,BITMAPaircraft);
	switch(g_level)
	{
		case 1:
		BitBlt(hdc,aircraft_x,aircraft_y,32,32,hdcmen,0,0, SRCPAINT);
		break;
	}
	DeleteDC(hdcmen);
}
void Showoracle(HDC hdc)
{
	HDC hdcmen=CreateCompatibleDC(hdc);
	SelectObject(hdcmen,BITMAPoracle);
	switch(g_level)
	{
		case 1:
		BitBlt(hdc,oracle_x,oracle_y,32,32,hdcmen,0,0, SRCPAINT);
		
		break;
		case 2:
		BitBlt(hdc,oracle1_x,oracle1_y,32,32,hdcmen,0,0, SRCPAINT);
		break;
	}
	DeleteDC(hdcmen);
}
void Showcriminal(HDC hdc)
{
	HDC hdcmen=CreateCompatibleDC(hdc);
	SelectObject(hdcmen,BITMAPcriminal);
	switch(g_level)
	{
		case 1:
		BitBlt(hdc,criminal_x,criminal_y,32,32,hdcmen,0,0, SRCPAINT);
		break;
	}
	DeleteDC(hdcmen);
}
void Showstatusback(HDC hdc)
{
	HDC hdcmen=CreateCompatibleDC(hdc);
	SelectObject(hdcmen,BITMAPstatus);
	BitBlt(hdc,0,0,200,468,hdcmen,0,0, SRCCOPY);
	DeleteDC(hdcmen);
}
void InitInfotxt(HDC hdc)
{
	_itoa(Hero.LIFE,hero_life,10);
	_itoa(Hero.ATK,hero_atk,10);
	_itoa(Hero.DEF,hero_def,10);
	_itoa(Hero.GOLD,hero_gold,10);
	_itoa(Hero.yellowkey,hero_yellowkey,10);
	_itoa(Hero.bluekey,hero_bluekey,10);
	_itoa(Hero.redkey,hero_redkey,10);
			
	TextOut (hdc, 40, 100,hero_life, strlen(hero_life)) ;
	TextOut (hdc, 40, 132,hero_atk, strlen(hero_atk)) ;
	TextOut (hdc, 40, 164,hero_def, strlen(hero_def)) ;
	TextOut (hdc, 40, 196,hero_gold, strlen(hero_gold)) ;
	TextOut (hdc, 32, 82+32*9,hero_yellowkey, strlen(hero_yellowkey));
	TextOut (hdc, 32, 82+32*10,hero_bluekey, strlen(hero_bluekey));
	TextOut (hdc, 32, 82+32*11,hero_redkey, strlen(hero_redkey));
}
void Showtransmit(HDC hdc)
{
	HDC hdcmen=CreateCompatibleDC(hdc);
	SelectObject(hdcmen,BITMAPtransmit);
	switch(g_level)
	{
		case 1:
		BitBlt(hdc,transmit_x,transmit_y,32,32,hdcmen,0,0, SRCPAINT);
		break;
		case 2:
		BitBlt(hdc,transmit1_x,transmit1_y,32,32,hdcmen,0,0, SRCPAINT);
		break;
	}
	DeleteDC(hdcmen);
}
void Showbusinessman(HDC hdc)
{
	HDC hdcmen=CreateCompatibleDC(hdc);
	SelectObject(hdcmen,BITMAPbusinessman);
	switch(g_level)
	{
		case 2:
		BitBlt(hdc,businessman_x,businessman_y,32,32,hdcmen,0,0, SRCPAINT);
		break;
	}
	DeleteDC(hdcmen);
}

void Showmediumguardman(HDC hdc)
{
	HDC hdcmen=CreateCompatibleDC(hdc);
	SelectObject(hdcmen,BITMAPmediumguardman);
	switch(g_level)
	{
		case 2:
		BitBlt(hdc,mediumguardman1_x,mediumguardman1_y,32,32,hdcmen,0,0, SRCPAINT);
		BitBlt(hdc,mediumguardman2_x,mediumguardman2_y,32,32,hdcmen,0,0, SRCPAINT);
		break;
	}
	DeleteDC(hdcmen);
}