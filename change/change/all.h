#include<Windows.h>
#include"resource.h"
#include<time.h>
#include<stdlib.h>
#include"resource12.h"
//#pragma  comment(lib,"Msimg32.lib")

int height,weight;
enum herobody{up,down,left,right};
enum herobody fx=up;

typedef struct STATUS
{
	int LIFE;//生命
	int ATK;//攻击
	int DEF;//防御
	int GOLD;//金币
	int redkey;
	int bluekey;
	int yellowkey;
	int aircraft;//飞行器数量
}HERO;
typedef struct STATUS1
{
	int LIFE;//生命
	int ATK;//攻击
	int DEF;//防御
	int GOLD;//金币
}Slm,Bone,Rabbi,Bat,Guardman;

HERO Hero ={300,20,10,0,0,1,2,0};



Slm slmgreen={35,18,1,1};
Slm slmred={45,20,2,2};
Bone Bonesmall={50,42,6,6};//小骷髅
Bone Bonemedium={55,52,12,8};//中等骷髅
Rabbi Rabbielementary={60,32,8,5};//初级法师
Bat Batsmall={35,38,3,3};
Guardman Medium={20,30,12,50};



HBITMAP BITMAPwall;
HBITMAP BITMAPfront;
HBITMAP BITMAPleft;
HBITMAP BITMAPright;
HBITMAP BITMAPbehind;
HBITMAP BITMAPback;
HBITMAP BITMAPwall1;
HBITMAP BITMAPreddoor;
HBITMAP BITMAPbluedoor;
HBITMAP BITMAPyellowdoor;
HBITMAP BITMAPslmred;
HBITMAP BITMAPslmgreen;
HBITMAP BITMAPkeyred;
HBITMAP BITMAPkeyyellow;
HBITMAP BITMAPkeyblue;
HBITMAP BITMAPbat;
HBITMAP BITMAPrabbi;
HBITMAP BITMAPbonesmall;
HBITMAP BITMAPbonemedium;
HBITMAP BITMAPvialred;//红药水
HBITMAP BITMAPvialblue;//蓝药水
HBITMAP BITMAPgemred;//红宝石
HBITMAP BITMAPgemblue;//蓝宝石
HBITMAP BITMAPaircraft;//飞行器
HBITMAP BITMAPstatus;//属性面板
HBITMAP BITMAPoracle;//贤者
HBITMAP BITMAPcriminal;//罪犯
HBITMAP BITMAPprincess;//公主
HBITMAP BITMAPvampire;//吸血鬼
HBITMAP BITMAPtransmit;//传送门
HBITMAP BITMAPmediumguardman;//中等卫兵
HBITMAP BITMAPbusinessman;//商人
HBITMAP BITMAPirondoor;//铁门
HBITMAP BITMAPbeijing;
void Showbackground(HDC hdc);
void startup();
void Showonestoreywall(HDC hdc);
void ShowHero(HDC hdc);

void Showdoor(HDC hdc);
void Showalldoor(HDC hdc);

void Showyellowkey(HDC hdc);
void Showbluekey(HDC hdc);
void Showredkey(HDC hdc);
void Showallkey(HDC hdc);

void Showtransmit(HDC hdc);

void Showmslm(HDC hdc);
void Showallslm(HDC hdc);
void Showbat(HDC hdc);
void Showrabbi(HDC hdc);
void Showbonesmall(HDC hdc);
void Showbonemedium(HDC hdc);
void Showvialred(HDC hdc);
void Showvialblue(HDC hdc);
void Showgemred(HDC hdc);
void Showgemblue(HDC hdc);
void Showaircraft(HDC hdc);
void Showstatusback(HDC hdc);
void Showoracle(HDC hdc);
void Showcriminal(HDC hdc);
void Showbusinessman(HDC hdc);
void Showirondoor(HDC hdc);
void Showmediumguardman(HDC hdc);
void InitInfotxt(HDC hdc);

void showChildWin();
void hideChildWin();

void Move();
void Moveback();
BOOL Ismove();
BOOL ISfightinggreenslm(Slm slm);
BOOL ISfightingredslm(Slm slm);
BOOL Isfightingbat(Bat bat);
BOOL Isfightingrabbi(Rabbi rabbi);
BOOL Isfightingbonesmall(Bone bonesmall);
BOOL Isfightingbonemedium(Bone bonemedium);
BOOL Iscanthroughreddoor();
BOOL Iscanthroughyellowdoor();
BOOL Iscanthroughbluedoor();
BOOL Isfighttingmediumguardman(Guardman mediumguardman);


LRESULT CALLBACK MyWNDPROC(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam);
int CreateChildWnd(HINSTANCE hInstance);
LRESULT CALLBACK WindowProcChild(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
HINSTANCE hIns = 0;  //全局变量，程序实例句柄
HWND hwnd = 0;
HWND hwndChild = 0;