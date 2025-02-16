//########## ヘッダーファイル読み込み ##########
#include "DxLib.h"
#include "resource.h"

//########## マクロ定義 ##########
#define GAME_WIDTH			800	//画面の横の大きさ
#define GAME_HEIGHT			600	//画面の縦の大きさ
#define GAME_COLOR			32	//画面のカラービット

#define GAME_WINDOW_BAR		0	//タイトルバーはデフォルトにする
#define GAME_WINDOW_NAME	"銀河鉄道と迷える羊"	//ウィンドウのタイトル

#define GAME_FPS			60	//FPSの数値	

#define PATH_MAX			255
#define NAME_MAX			255

//フォント
#define FONT_PATH			TEXT(".\\FONT\\07LogoTypeGothic7.ttf")	//フォントの場所
#define FONT_NAME			TEXT("ロゴたいぷゴシック")			//フォントの名前
#define FONT_SIZE			24

//画像のパス
//スタート画面
#define IMAGE_START_BACK		TEXT(".\\IMAGE\\ImageStartBack.png")	//背景
#define IMAGE_START_MENU1		TEXT(".\\IMAGE\\menu1.png")				//メニュー１
#define IMAGE_START_MENU2		TEXT(".\\IMAGE\\menu2.png")				//メニュー２
#define IMAGE_SETSUMEI			TEXT(".\\IMAGE\\HowToPlay.png")			//操作説明
#define IMAGE_START_TITLE2		TEXT(".\\IMAGE\\TitleRogoBlend2.png")	//タイトルロゴ１
#define IMAGE_START_TITLE		TEXT(".\\IMAGE\\TitleRogoBlend.png")	//タイトルロゴ２
#define IMAGE_START_TITLEROGO	TEXT(".\\IMAGE\\TitleRogo.png")			//タイトルロゴ
//プレイ画面
#define IMAGE_PLAY_BACK1		TEXT(".\\IMAGE\\ImagePlayBack1.png")	//背景１
#define IMAGE_PLAY_BACK2		TEXT(".\\IMAGE\\ImagePlayBack2.png")	//背景２
#define IMAGE_PLAY_FRONT1		TEXT(".\\IMAGE\\ImagePlayFront1.png")	//手前に流れる画像１
#define IMAGE_PLAY_FRONT2		TEXT(".\\IMAGE\\ImagePlayFront2.png")	//手前に流れる画像２
#define IMAGE_NUM				4		//手前に流れる画像の数
#define IMAGE_LOAD_BLACK		TEXT(".\\IMAGE\\Loading.png")			//黒画面
#define IMAGE_LOADING_CNT		25		//黒画面を表示する時間
#define IMAGE_TEXTBOX			TEXT(".\\IMAGE\\text.png")				//テキストボックス
#define IMAGE_ITEMTEXT			TEXT(".\\IMAGE\\ItemText.png")			//テキストボックス
#define IMAGE_RETURN			TEXT(".\\IMAGE\\enter.png")				//プッシュトゥエンター
#define IMAGE_BACKSPACE			TEXT(".\\IMAGE\\BackSpace.png")			//プッシュトゥバック
#define IMAGE_ITEM				TEXT(".\\IMAGE\\Item2.png")				//あいてむ
//エンド画面
#define IMAGE_END_BACK			TEXT(".\\IMAGE\\ImageEndBack.png")		//背景
#define IMAGE_END_COMP_ROGO		TEXT(".\\IMAGE\\EndRogo.png")			//エンドロゴ
//キャラ画像
#define IMAGE_BOY_PATH			TEXT(".\\IMAGE\\boy.PNG")				//少年
#define IMAGE_LEMON_PATH		TEXT(".\\IMAGE\\lemon.png")				//女性
#define IMAGE_SINNER_PATH		TEXT(".\\IMAGE\\sinner.png")			//男性
#define IMAGE_FRIEND_PATH		TEXT(".\\IMAGE\\friend.png")			//友人
#define IMAGE_PLAYER_PATH		TEXT(".\\IMAGE\\playerAll.png")
#define PLAYER_DIV_WIDTH		100		//プレイヤー画像を分割する幅
#define PLAYER_DIV_HEIGHT		169		//プレイヤー画像を分割する高さ
#define PLAYER_DIV_TATE			4		//プレイヤー画像を縦に分割する数
#define PLAYER_DIV_YOKO			1		//プレイヤー画像を横に分割する数
#define PLAYER_DIV_NUM		PLAYER_DIV_TATE * PLAYER_DIV_YOKO	//分割した画像の総数
#define IMAGE_PLAYER_CNT_MAX	25		//足を切り替えるときの時間
#define CHARA_POSITION_X		296		//キャラクター表示位置X
#define CHARA_POSITION_Y		144		//キャラクター表示位置Y
#define BOYFACE_PATH			TEXT(".\\IMAGE\\boyFace.png")		//顔画像
#define SINFACE_PATH			TEXT(".\\IMAGE\\sinFace.png")
#define BOYFACE_DIV_WIDTH		144		//画像を分割する幅
#define BOYFACE_DIV_HEIGHT		144		//画像を分割する高さ
#define BOYFACE_DIV_TATE		5		//画像を縦に分割する数
#define BOYFACE_DIV_YOKO		1		//画像を横に分割する数
#define BOYFACE_DIV_NUM		BOYFACE_DIV_TATE * BOYFACE_DIV_YOKO	//分割した画像の総数

//テキスト
#define TEXT_POSITION_X			224		//文字表示位置X
#define TEXT_POSITION_Y			61		//文字表示位置Y
#define NAME_POSITION_Y			24		//名前表示位置Y


//BGM
#define MUSIC_START_PATH		TEXT(".\\MUSIC\\魔法使いと振り子時計.mp3")
#define MUSIC_PLAY_PATH			TEXT(".\\MUSIC\\誰もいない風景.mp3")
#define MUSIC_PLAYBACK			TEXT(".\\MUSIC\\蒸気機関車走行音.mp3")
#define MUSIC_END_PATH			TEXT(".\\MUSIC\\アクアの旅路.mp3")
//SE
#define SE_CURSOR				TEXT(".\\MUSIC\\カーソル移動1.mp3")
#define SE_KETTEI				TEXT(".\\MUSIC\\決定、ボタン押下6.mp3")
#define SE_PAPER				TEXT(".\\MUSIC\\se_maoudamashii_se_paper01.mp3")
#define SE_WALK					TEXT(".\\MUSIC\\se_maoudamashii_se_footstep02.mp3")
#define SE_ITEM					TEXT(".\\MUSIC\\se_maoudamashii_system47.mp3")
#define SE_TALK					TEXT(".\\MUSIC\\メッセージ表示音2.mp3")
#define SE_DOOR					TEXT(".\\MUSIC\\ドア・開ける05.mp3")
#define SE_GACHA				TEXT(".\\MUSIC\\ドアノブ（がちゃがちゃ）02 (1).mp3")


//マップ
#define GAME_MAP_TATE_MAX	10
#define GAME_MAP_YOKO_MAX	13
#define GAME_MAP_KIND_MAX	5

#define GAME_MAP_PATH		TEXT(".\\IMAGE\\MAP\\マップ.png")

#define MAP_DIV_WIDTH		64
#define MAP_DIV_HEIGHT		64
#define MAP_DIV_TATE		10
#define MAP_DIV_YOKO		4
#define MAP_DIV_NUM MAP_DIV_TATE * MAP_DIV_YOKO


//エラーメッセージ
#define FONT_INSTALL_ERR_TITLE	TEXT("フォントインストールエラー")
#define FONT_CREATE_ERR_TITLE	TEXT("フォント作成エラー")

#define IMAGE_LOAD_ERR_TITLE	TEXT("画像読み込みエラー")

#define MUSIC_LOAD_ERR_TITLE	TEXT("音楽読み込みエラー")

#define START_ERR_TITLE			TEXT("スタート位置エラー")
#define START_ERR_CAPTION		TEXT("スタート位置が決まっていません")

#define GOAL_ERR_TITLE			TEXT("ゴール位置エラー")
#define GOAL_ERR_CAPTION		TEXT("ゴール位置が決まっていません")

#define ESC_TITLE				TEXT("ゲーム中断")
#define ESC_CAPTION				TEXT("ゲーム中断し、タイトル画面に戻りますか？")

enum GAME_MAP_KIND
{
	n = -1,
	s = 0,
	t = 10,
	k = 21,
	m = 11,
	a = 1,
	b = 4,
	o = 14,
	x = 3,
	z = 13,
	e = 5,
	d = 6,
	p = 12,
	c = 20,
	y = 2,
	r = 8,
	g = 7
};

enum GAME_SCENE {
	GAME_SCENE_START,
	GAME_SCENE_PLAY,
	GAME_SCENE_END,
};	//ゲームのシーン

enum GAME_END {
	GAME_END_COMP,
	GAME_END_FAIL
};

enum CHARA_SPEED {
	CHARA_SPEED_LOW = 1,
	CHARA_SPEED_MIDI = 2,
	CHARA_SPEED_HIGH = 3
};	//キャラスピード

typedef struct STRUCT_MAP_IMAGE
{
	char path[PATH_MAX];
	int handle[MAP_DIV_NUM];
	int kind[MAP_DIV_NUM];
	int width;
	int height;
}MAPCHIP;

typedef struct STRUCT_MAP
{
	GAME_MAP_KIND kind;
	int x;
	int y;
	int num;		//現在のマップ
	int width;
	int height;
}MAP;

//int型のPOINT構造体
typedef struct STRUCT_I_POINT
{
	int x = -1;	//座標を初期化
	int y = -1;	//座標を初期化
}iPOINT;

//フォント構造体
typedef struct STRUCT_FONT
{
	char path[PATH_MAX];	//パス
	char name[NAME_MAX];	//フォント名
	int handle;					//ハンドル
	int size;					//大きさ
	int bold;					//太さ
	int type;					//タイプ
	//※タイプは、https://dxlib.xsrv.jp/function/dxfunc_graph2.html#R17N10　を参照

}FONT;

typedef struct STRUCT_IMAGE
{
	char path[PATH_MAX];		//パス
	int handle;					//ハンドル
	int x;						//X位置
	int y;						//Y位置
	int width;					//幅
	int height;					//高さ
}IMAGE;	//画像構造体

typedef struct STRUCT_MUSIC
{
	char path[PATH_MAX];
	int handle;
}MUSIC;	//音楽構造体

typedef struct STRUCT_PLAYER
{
	char path[PATH_MAX];
	int handle[PLAYER_DIV_NUM];
	int speed;		//速さ
	int x;
	int y;
	int width;
	int height;

	iPOINT collBeforePt;

	int nowImageKind;					//現在の画像
	int changeImageCnt;					//画像を変えるためのカウント
	int changeImageCntMAX;
}PLAYER;	//プレイヤー構造体

typedef struct STRUCT_FACE
{
	char path[PATH_MAX];
	int handle[BOYFACE_DIV_NUM];
	int x;
	int y;
	int width;
	int height;

	int nowImageKind;					//現在の画像
}FACE;	//プレイヤー構造体

typedef struct STRUCT_CHARA
{
	IMAGE image;
	int CenterX;	//中心X
	int CenterY;	//中心Y
	RECT coll;
	BOOL IsDraw;

	PLAYER player[PLAYER_DIV_NUM];
	FACE face[BOYFACE_DIV_NUM];

}CHARA;	//キャラクター構造体

typedef struct STRUCT_IMAGE_DES
{
	IMAGE image;		//IMAGE構造体
	BOOL IsDraw;		//表示できるか

	int Cnt;
}IMAGE_DES;	//画像の構造体

//########## グローバル変数 ##########
//FPS関連
int StartTimeFps;				//測定開始時刻
int CountFps;					//カウンタ
float CalcFps;					//計算結果
int SampleNumFps = GAME_FPS;	//平均を取るサンプル数

//キーボードの入力を取得
char AllKeyState[256] = { '\0' };			//すべてのキーの状態が入る
char OldAllKeyState[256] = { '\0' };	//すべてのキーの状態(直前)が入る

FONT Font;	//たぬき油性マジック：大きさ32　のフォント構造体

int GameScene;		//ゲームシーンを管理
int menu;			//メニュー
int GameEndKind;

int EventMap = 1;	//イベントが起きているマップ

RECT GoalRect = { -1,-1,-1,-1 };
RECT ReturnRect = { -1,-1,-1,-1 };

CHARA chara;		//プレイヤー
CHARA boy;			//少年
CHARA Lemon;		//女性
CHARA Sinner;		//男性
CHARA Friend;		//友人

CHARA boyFace;
CHARA sinFace;

//当たり判定
RECT PlayerRect;	//プレイヤー
RECT boyRect;		//少年
RECT LemRect;		//女性
RECT SinRect;		//男性
RECT FriRect;		//友人

//画像
IMAGE_DES ImageBack[IMAGE_NUM];		//ゲームの背景
IMAGE_DES ImageFront[IMAGE_NUM];	//
IMAGE_DES TextBox;	//テキストボックス
IMAGE_DES ItemText;	//テキストボックス
IMAGE_DES Enter;
IMAGE_DES Back;
IMAGE_DES Chiket;
IMAGE_DES Shinbun;
IMAGE_DES MemoLem;
IMAGE_DES Title2;	//タイトルロゴ１
IMAGE_DES Title;	//タイトルロゴ２
IMAGE_DES TitleROGO;	//タイトルロゴ３
IMAGE_DES menu1;	//メニュー(はじめる)
IMAGE_DES menu2;	//メニュー(操作説明)
IMAGE_DES Setsumei;	//操作説明
IMAGE_DES Loading;	//車両移動時の黒い画像
IMAGE_DES EndROGO;	//エンドロゴ
IMAGE StartBack;	//スタート背景
IMAGE EndBack;		//エンド背景

//各マップはじめて入ったときのフラグ（二度目に入ったとき折る）
BOOL FirstMap1 = TRUE;
BOOL FirstMap2 = TRUE;
BOOL FirstMap3 = TRUE;
BOOL FirstMap4 = TRUE;
BOOL FirstMap5 = TRUE;
//次のマップに進めるかどうか
BOOL NextDoor2 = FALSE;	
BOOL NextDoor3 = FALSE;
BOOL NextDoor4 = FALSE;
BOOL NextDoor5 = FALSE;
BOOL NextDoorEnd = FALSE;
//表示フラグ
BOOL IsMove = FALSE;	//プレイヤーが動けるか
BOOL Walk = FALSE;		//プレイヤーが歩いているか
BOOL FirstBox = TRUE;	//テキストボックス
BOOL Load = FALSE;		//黒画面
BOOL boyName = FALSE;	//名前判明

//アイテム
BOOL ItemOK = FALSE;		//アイテムを拾えるか
BOOL ItemGet = FALSE;		//あいてむSE
BOOL ItemFlg = FALSE;		//アイテムテキスト表示フラグ
BOOL CheckChiket = FALSE;	//切符を拾ったか
BOOL CheckMemL = FALSE;
BOOL iNextString = FALSE;
BOOL iTEXT = FALSE;
BOOL iFirstText = FALSE;

//会話フラグ
//プレイヤー
BOOL PlayerFlg = FALSE;	
BOOL pTEXT = FALSE;
BOOL PlayerFirstText = TRUE;	//テキストSE
BOOL Player1flg = FALSE;
//少年
BOOL boyFlg = FALSE;	
BOOL bTEXT = FALSE;
BOOL boyFirstText = TRUE;	//テキストSE
BOOL bNextString = FALSE;	//次の行
BOOL boy1flg = FALSE;
BOOL boy2flg = FALSE;
BOOL boy3flg = FALSE;
BOOL boy4flg = FALSE;
BOOL boy5flg = FALSE;
BOOL boy6flg = FALSE;
BOOL boy7flg = FALSE;
BOOL boy8flg = FALSE;
BOOL boy9flg = FALSE;
BOOL boy10flg = FALSE;
//女性
BOOL LemFlg = FALSE;
BOOL lTEXT = FALSE;
BOOL lemFirstText = TRUE;	//テキストSE
BOOL lNextString = FALSE;	//次の行
BOOL lem1flg = FALSE;
BOOL lem2flg = FALSE;
BOOL lem3flg = FALSE;
BOOL lem4flg = FALSE;
//男性
BOOL sinFlg = FALSE;
BOOL sTEXT = FALSE;
BOOL sinFirstText = TRUE;	//テキストSE
BOOL sNextString = FALSE;	//次の行
BOOL sin1flg = FALSE;
BOOL sin2flg = FALSE;
//友人
BOOL FriFlg = FALSE;
BOOL fTEXT = FALSE;
BOOL friFirstText = TRUE;	//テキストSE
BOOL fNextString = FALSE;	//次の行
BOOL fri1flg = FALSE;
BOOL fri2flg = FALSE;

//行数カウント
int Playergyou = 0;
int boygyou = 0;
int lemgyou = 0;
int singyou = 0;
int frigyou = 0;

//表示する文
int PlayerCnt = 0;	//必須じゃないけど保険として
int boyCnt = 0;
int lemCnt = 0;
int sinCnt = 0;
int friCnt = 0;

//アイテムナンバー
int ItemNum = 0;

//文字色
int Yellow = GetColor(255, 200, 0);
int White = GetColor(255, 255, 255);
int Red = GetColor(255, 100, 100);

//BGM
MUSIC StartBGM;
MUSIC PlayBGM;
MUSIC pBackBGM;
MUSIC EndBGM;
//SE
MUSIC cursorSE;
MUSIC ketteiSE;
MUSIC paperSE;
MUSIC walkSE;
MUSIC talkSE;
MUSIC doorSE;
MUSIC GachaSE;
MUSIC ItemSE;

GAME_MAP_KIND mapData[GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX]{
	//  0,1,2,3,4,5,6,7,8,9,0,1,2,
		y,a,a,a,a,a,a,a,a,a,a,a,y,	// 0
		y,m,m,m,m,m,m,m,m,m,m,m,y,	// 1
		y,k,x,b,k,x,b,k,x,b,k,x,y,	// 2
		y,t,z,o,t,z,o,t,z,o,t,z,y,	// 3
		y,c,t,t,t,t,t,t,t,t,t,p,y,	// 4
		g,t,t,t,t,t,t,t,t,t,t,t,r,	// 5
		y,t,e,d,t,e,d,t,e,d,s,e,y,	// 6
		y,t,z,o,t,z,o,t,z,o,t,z,y,	// 7
		y,y,y,y,y,y,y,y,y,y,y,y,y,	// 8
		y,y,y,y,y,y,y,y,y,y,y,y,y,	// 9
};

GAME_MAP_KIND mapDataInit[GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX];

MAPCHIP mapChip;

MAP map[GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX];

iPOINT startPt{ -1,-1 };
iPOINT ReStartPt{ -1,-1 };
iPOINT ReturnPt{ -1,-1 };

RECT mapColl[GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX];

//########## プロトタイプ宣言 ##########
VOID MY_FPS_UPDATE(VOID);			//FPS値を計測、更新する
VOID MY_FPS_DRAW(VOID);				//FPS値を描画する
VOID MY_FPS_WAIT(VOID);				//FPS値を計測し、待つ

VOID MY_ALL_KEYDOWN_UPDATE(VOID);	//キーの入力状態を更新する
BOOL MY_KEY_DOWN(int);				//キーを押しているか、キーコードで判断する
BOOL MY_KEY_UP(int);				//キーを押し上げたか、キーコードで判断する
BOOL MY_KEYDOWN_KEEP(int, int);		//キーを押し続けているか、キーコードで判断する

BOOL MY_FONT_INSTALL_ONCE(VOID);	//フォントをこのソフト用に、一時的にインストール
VOID MY_FONT_UNINSTALL_ONCE(VOID);	//フォントをこのソフト用に、一時的にアンインストール
BOOL MY_FONT_CREATE(VOID);			//フォントを作成する
VOID MY_FONT_DELETE(VOID);			//フォントを削除する

VOID MY_START(VOID);				//スタート画面
VOID MY_START_PROC(VOID);			//スタート画面の処理
VOID MY_START_DRAW(VOID);			//スタート画面の描画

VOID MY_PLAY(VOID);					//プレイ画面
VOID MY_PLAY_PROC(VOID);			//プレイ画面の処理
VOID MY_PLAY_DRAW(VOID);			//プレイ画面の描画

VOID MY_END(VOID);					//エンド画面
VOID MY_END_PROC(VOID);				//エンド画面の処理
VOID MY_END_DRAW(VOID);				//エンド画面の描画

BOOL MY_LOAD_IMAGE(VOID);			//画像をまとめて読み込む関数
VOID MY_DELETE_IMAGE(VOID);			//画像をまとめて削除する関数

BOOL MY_LOAD_MUSIC(VOID);			//音楽をまとめて読み込む関数
VOID MY_DELETE_MUSIC(VOID);			//音楽をまとめて削除する関数

BOOL MY_CHECK_MAP1_PLAYER_COLL(RECT);	//プレイヤーとマップの当たり判定をする関数
BOOL MY_CHECK_CHARA_PLAYER_COLL(RECT);	//プレイヤーと他のキャラクターの当たり判定をする関数
BOOL MY_CHECK_RECT_COLL(RECT, RECT);	//領域の当たり判定をする関数

VOID LOADING(VOID);					//LOADING画面風黒画面を表示する関数

INT TEXTBOX(int, int);					//テキストボックスを表示する関数

VOID SISTEM_TEXT(int, int);			//アイテムテキストを表示する関数
VOID PLAYER_TEXT(int, int);			//プレイヤーテキストを表示する関数（将来的にはいらなくなるはず）
VOID BOY_TEXT(int, int);			//少年テキスト
VOID LEMON_TEXT(int, int);			//女性テキスト
VOID SINNER_TEXT(int, int);			//男性テキスト
VOID FRIEND_TEXT(int, int);			//友人テキスト


//########## プログラムで最初に実行される関数 ##########
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);								//ウィンドウモードに設定
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);	//指定の数値でウィンドウを表示する
	SetWindowStyleMode(GAME_WINDOW_BAR);				//タイトルバーはデフォルトにする
	SetMainWindowText(TEXT(GAME_WINDOW_NAME));			//ウィンドウのタイトルの文字
	SetAlwaysRunFlag(TRUE);								//非アクティブでも実行する
	SetWindowIconID(IDI_ICON1);							//アイコンファイルを読込

	if (DxLib_Init() == -1) { return -1; }	//ＤＸライブラリ初期化処理

	//画像を読み込む
	if (MY_LOAD_IMAGE() == FALSE) { return -1; }
	//音楽を読み込む
	if (MY_LOAD_MUSIC() == FALSE) { return -1; }

	//フォントを一時的にインストール
	if (MY_FONT_INSTALL_ONCE() == FALSE) { return -1; }
	//フォントハンドルを作成
	if (MY_FONT_CREATE() == FALSE) { return -1; }

	SetMouseDispFlag(TRUE);			//マウスカーソルを表示	

	GameScene = GAME_SCENE_START;	//ゲームシーンはスタート画面から

	SetDrawScreen(DX_SCREEN_BACK);	//Draw系関数は裏画面に描画

	for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
		{
			//スタート位置
			if (mapData[tate][yoko] == s)
			{
				startPt.x = mapChip.width * yoko + mapChip.width / 2;
				startPt.y = mapChip.height * tate + mapChip.height / 2;
			}
			//次のマップに進んだときのスタート位置
			if (mapData[tate][yoko] == p)
			{
				ReStartPt.x= mapChip.width * yoko + mapChip.width / 2;
				ReStartPt.y = mapChip.height * tate + mapChip.height / 2;
			}
			//前のマップに戻ったときのスタート位置
			if (mapData[tate][yoko] == c)
			{
				ReturnPt.x = mapChip.width * yoko + mapChip.width / 2;
				ReturnPt.y = mapChip.height * tate + mapChip.height / 2;
			}
			//戻るドアの当たり判定
			if (mapData[tate][yoko] == r)
			{
				ReturnRect.left = mapChip.width * yoko;
				ReturnRect.top = mapChip.height * tate;
				ReturnRect.right = mapChip.width * (yoko + 1);
				ReturnRect.bottom = mapChip.height * (tate + 1);
			}
			//進むドア（ゴール）の当たり判定
			if (mapData[tate][yoko] == g)
			{
				GoalRect.left = mapChip.width * yoko;
				GoalRect.top = mapChip.height * tate;
				GoalRect.right = mapChip.width * (yoko + 1);
				GoalRect.bottom = mapChip.height * (tate + 1);
			}
		}
	}

	//スタート位置・ゴール位置が見つからなかったらエラー
	if (startPt.x == -1 && startPt.y == -1)
	{
		MessageBox(GetMainWindowHandle(), START_ERR_CAPTION, START_ERR_TITLE, MB_OK); return -1;
	}
	if (GoalRect.left == -1)
	{
		MessageBox(GetMainWindowHandle(), GOAL_ERR_CAPTION, GOAL_ERR_TITLE, MB_OK); return -1;
	}

	//無限ループ
	while (TRUE)
	{
		if (ProcessMessage() != 0) { break; }	//メッセージ処理の結果がエラーのとき、強制終了
		if (ClearDrawScreen() != 0) { break; }	//画面を消去できなかったとき、強制終了

		MY_ALL_KEYDOWN_UPDATE();				//押しているキー状態を取得

		MY_FPS_UPDATE();	//FPSの処理[更新]
		
		//シーンごとに処理を行う
		switch (GameScene)
		{
		case GAME_SCENE_START:
			MY_START();	//スタート画面
			break;
		case GAME_SCENE_PLAY:
			MY_PLAY();	//プレイ画面
			break;
		case GAME_SCENE_END:
			MY_END();	//エンド画面
			break;
		}

		MY_FPS_DRAW();		//FPSの処理[描画]

		ScreenFlip();		//モニタのリフレッシュレートの速さで裏画面を再描画

		MY_FPS_WAIT();		//FPSの処理[待つ]
	}

	//フォントハンドルを破棄
	MY_FONT_DELETE();

	//一時的にインストールしたフォントをアンインストール
	MY_FONT_UNINSTALL_ONCE();

	//画像ハンドルを破棄
	MY_DELETE_IMAGE();

	//音楽ハンドルを破棄
	MY_DELETE_MUSIC();

	DxLib_End();	//ＤＸライブラリ使用の終了処理

	return 0;
}

//########## FPS値を計測、更新する関数 ##########
VOID MY_FPS_UPDATE(VOID)
{
	if (CountFps == 0) //1フレーム目なら時刻を記憶
	{
		StartTimeFps = GetNowCount();
	}

	if (CountFps == SampleNumFps) //60フレーム目なら平均を計算
	{
		int now = GetNowCount();
		//現在の時間から、0フレーム目の時間を引き、FPSの数値で割る＝1FPS辺りの平均時間が計算される
		CalcFps = 1000.f / ((now - StartTimeFps) / (float)SampleNumFps);
		CountFps = 0;
		StartTimeFps = now;
	}
	CountFps++;
	return;
}

//########## FPS値を描画する関数 ##########
VOID MY_FPS_DRAW(VOID)
{
	//文字列を描画
	DrawFormatString(0, GAME_HEIGHT - 20, GetColor(255, 255, 255), "FPS:%.1f", CalcFps);
	return;
}

//########## FPS値を計測し、待つ関数 ##########
VOID MY_FPS_WAIT(VOID)
{
	int resultTime = GetNowCount() - StartTimeFps;					//かかった時間
	int waitTime = CountFps * 1000 / GAME_FPS - resultTime;	//待つべき時間

	if (waitTime > 0)		//指定のFPS値よりも早い場合
	{
		WaitTimer(waitTime);	//待つ
	}
	return;
}

//########## キーの入力状態を更新する関数 ##########
VOID MY_ALL_KEYDOWN_UPDATE(VOID)
{
	//参考：https://dxlib.xsrv.jp/function/dxfunc_input.html

	char TempKey[256];	//一時的に、現在のキーの入力状態を格納する

	//直前のキー入力をとっておく
	for (int i = 0; i < 256; i++)
	{
		OldAllKeyState[i] = AllKeyState[i];
	}

	GetHitKeyStateAll(TempKey); // 全てのキーの入力状態を得る

	for (int i = 0; i < 256; i++)
	{
		if (TempKey[i] != 0)	//押されているキーのキーコードを押しているとき
		{
			AllKeyState[i]++;	//押されている
		}
		else
		{
			AllKeyState[i] = 0;	//押されていない
		}
	}
	return;
}

//キーを押しているか、キーコードで判断する
//引　数：int：キーコード：KEY_INPUT_???
BOOL MY_KEY_DOWN(int KEY_INPUT_)
{
	//キーコードのキーを押している時
	if (AllKeyState[KEY_INPUT_] != 0)
	{
		return TRUE;	//キーを押している
	}
	else
	{
		return FALSE;	//キーを押していない
	}
}

//キーを押し上げたか、キーコードで判断する
//引　数：int：キーコード：KEY_INPUT_???
BOOL MY_KEY_UP(int KEY_INPUT_)
{
	if (OldAllKeyState[KEY_INPUT_] >= 1	//直前は押していて
		&& AllKeyState[KEY_INPUT_] == 0)	//今は押していないとき
	{
		return TRUE;	//キーを押し上げている
	}
	else
	{
		return FALSE;	//キーを押し上げていない
	}
}

//キーを押し続けているか、キーコードで判断する
//引　数：int：キーコード：KEY_INPUT_???
//引　数：int：キーを押し続ける時間
BOOL MY_KEYDOWN_KEEP(int KEY_INPUT_, int DownTime)
{
	//押し続ける時間=秒数×FPS値
	//例）60FPSのゲームで、1秒間押し続けるなら、1秒×60FPS
	int UpdateTime = DownTime * GAME_FPS;

	if (AllKeyState[KEY_INPUT_] > UpdateTime)
	{
		return TRUE;	//押し続けている
	}
	else
	{
		return FALSE;	//押し続けていない
	}
}

//フォントをこのソフト用に、一時的にインストール
BOOL MY_FONT_INSTALL_ONCE(VOID)
{
	//フォントを一時的に読み込み(WinAPI)
	if (AddFontResourceEx(FONT_PATH, FR_PRIVATE, NULL) == 0)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), FONT_NAME, FONT_INSTALL_ERR_TITLE, MB_OK);
		return FALSE;
	}

	return TRUE;
}

//フォントをこのソフト用に、一時的にアンインストール
VOID MY_FONT_UNINSTALL_ONCE(VOID)
{
	//一時的に読み込んだフォントを削除(WinAPI)
	RemoveFontResourceEx(FONT_PATH, FR_PRIVATE, NULL);

	return;
}

//フォントを読み込む関数
//引　数：const char *：読み込むフォントの名前
//引　数：int　：フォントの大きさ
//引　数：int　：フォントの太さ
//引　数：int　：フォントのタイプ
//戻り値：なし→変更→戻り値：BOOL：エラー時：FALSE
BOOL MY_FONT_CREATE(VOID)
{
	//↓↓↓たぬき油性マジックのフォントを作成↓↓↓

	//フォントデータを作成
	strcpy_s(Font.path, sizeof(Font.path), FONT_PATH);	//パスをコピー
	strcpy_s(Font.name, sizeof(Font.name), FONT_NAME);	//フォント名をコピー
	Font.handle = -1;								//ハンドルを初期化
	Font.size = FONT_SIZE;							//サイズは24
	Font.bold = 1;								//太さ1
	Font.type = DX_FONTTYPE_ANTIALIASING_EDGE;	//アンチエイリアシング付きのフォント

	//フォントハンドル作成
	Font.handle = CreateFontToHandle(Font.name, Font.size, Font.bold, Font.type);
	//フォントハンドル作成できないとき、エラー
	if (Font.handle == -1) { MessageBox(GetMainWindowHandle(), FONT_NAME, FONT_CREATE_ERR_TITLE, MB_OK); return FALSE; }

	//↑↑↑たぬき油性マジックのフォントを作成↑↑↑

	return TRUE;
}

//フォントを削除する関数
VOID MY_FONT_DELETE(VOID)
{
	//フォントデータを削除
	DeleteFontToHandle(Font.handle);	//フォントのハンドルを削除

	return;
}

//スタート画面
VOID MY_START(VOID)
{
	MY_START_PROC();	//スタート画面の処理
	MY_START_DRAW();	//スタート画面の描画

	return;
}

//スタート画面の処理
VOID MY_START_PROC(VOID)
{
	if (CheckSoundMem(StartBGM.handle) == 0)
	{
		SetMouseDispFlag(FALSE);			//マウスカーソルを非表示

		ChangeVolumeSoundMem(255 * 50 / 100, StartBGM.handle);

		//BGMを流す
		//DX_PLAYTYPE_NORMAL:　ノーマル再生
		//DX_PLAYTYPE_BACK  : バックグラウンド再生
		//DX_PLAYTYPE_LOOP  : ループ再生
		PlaySoundMem(StartBGM.handle, DX_PLAYTYPE_LOOP);
	}

	//タイトルロゴ
	if (Title2.image.y > Title.image.y)		//半透明のやつを表示
	{
		Title2.IsDraw = TRUE;
		Title2.image.y--;
	}
	else if (Title.image.y > TitleROGO.image.y)		//高度を上げたやつを表示
	{
		Title2.IsDraw = FALSE;
		Title.IsDraw = TRUE;
		Title.image.y--;
	}
	else
	{
		Title.IsDraw = FALSE;
		TitleROGO.IsDraw = TRUE;		//上の画像が移動しきったら普通のロゴを表示
	}
	//エンターキーを押したら移動を省略して普通のロゴを表示
	if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)	
	{
		Title2.image.y = Title.image.y;
		Title2.IsDraw = FALSE;
		Title.image.y = TitleROGO.image.y + 1;
		Title.IsDraw = FALSE;
	}
	//普通のロゴが表示されたら
	if (TitleROGO.IsDraw == TRUE)
	{
		//メニューの表示
		//0:はじめる
		//1:操作説明
		if ((MY_KEY_DOWN(KEY_INPUT_RIGHT) == TRUE || MY_KEY_DOWN(KEY_INPUT_LEFT) == TRUE) && Setsumei.IsDraw == FALSE)
		{
			PlaySoundMem(cursorSE.handle, DX_PLAYTYPE_BACK);
		}
		if (MY_KEY_DOWN(KEY_INPUT_RIGHT) == TRUE && Setsumei.IsDraw == FALSE)
		{
			menu = 1;
		}
		if (MY_KEY_DOWN(KEY_INPUT_LEFT) == TRUE && Setsumei.IsDraw == FALSE)
		{
			menu = 0;
		}
		//二つの画像を切り替え
		switch (menu)
		{
		case 0:
			menu2.IsDraw = FALSE;
			menu1.IsDraw = TRUE;

			break;

		case 1:
			menu1.IsDraw = FALSE;
			menu2.IsDraw = TRUE;

			break;
		}
	}
	//はじめるを選択したとき
	if (menu1.IsDraw == TRUE && Setsumei.IsDraw == FALSE)
	{
		//エンターキーを押したら、プレイシーンへ移動する
		if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
		{
			SetMouseDispFlag(FALSE);

			if (Loading.Cnt < IMAGE_LOADING_CNT)
			{
				Load = TRUE;
			}
			else if (Loading.Cnt > IMAGE_LOADING_CNT)
			{
				Load = FALSE;
				Loading.Cnt = 0;
			}

			if (CheckSoundMem(ketteiSE.handle) == 0)
			{
				PlaySoundMem(ketteiSE.handle, DX_PLAYTYPE_BACK);
			}

			//BGMが流れているなら
			if (CheckSoundMem(StartBGM.handle) != 0)
			{
				StopSoundMem(StartBGM.handle);
			}

			chara.CenterX = startPt.x;
			chara.CenterY = startPt.y;

			for (int cnt = 0; cnt < PLAYER_DIV_NUM; cnt++)
			{
				chara.player[cnt].x = chara.CenterX;
				chara.player[cnt].y = chara.CenterY;

				chara.player[cnt].collBeforePt.x = chara.CenterX;
				chara.player[cnt].collBeforePt.y = chara.CenterY;
			}

			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{
					map[tate][yoko].num = 1;
				}
			}

			GameEndKind = GAME_END_FAIL;

			GameScene = GAME_SCENE_PLAY;

			return;
		}
	}
	//操作説明を選択したとき
	if (menu2.IsDraw == TRUE)
	{
		//エンターキーを押したら
		if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
		{
			//操作説明画像表示
			Setsumei.IsDraw = TRUE;
			//紙の音
			if (CheckSoundMem(paperSE.handle) == 0)
			{
				PlaySoundMem(paperSE.handle, DX_PLAYTYPE_BACK);
			}
		}
		if (Setsumei.IsDraw == TRUE)
		{
			//BACKSPACEキーを押したら
			if (MY_KEY_DOWN(KEY_INPUT_BACK) == TRUE)
			{
				//画像を非表示
				Setsumei.IsDraw = FALSE;
			}
		}
	}

	return;
}

//スタート画面の描画
VOID MY_START_DRAW(VOID)
{
	//背景を描画
	DrawGraph(StartBack.x, StartBack.y, StartBack.handle, TRUE);

	//タイトルロゴ
	if (Title2.IsDraw == TRUE)
	{
		DrawGraph(Title2.image.x, Title2.image.y, Title2.image.handle, TRUE);
	}
	if (Title.IsDraw == TRUE)
	{
		DrawGraph(Title.image.x, Title.image.y, Title.image.handle, TRUE);
	}
	if (TitleROGO.IsDraw == TRUE)
	{
		DrawGraph(TitleROGO.image.x, TitleROGO.image.y, TitleROGO.image.handle, TRUE);
	}

	//メニュー
	if (menu1.IsDraw == TRUE)
	{
		DrawGraph(menu1.image.x, menu1.image.y, menu1.image.handle, TRUE);
	}
	if (menu2.IsDraw == TRUE)
	{
		DrawGraph(menu2.image.x, menu2.image.y, menu2.image.handle, TRUE);
	}
	
	//操作説明
	if (Setsumei.IsDraw == TRUE)
	{
		DrawGraph(Setsumei.image.x, Setsumei.image.y, Setsumei.image.handle, TRUE);
	}

	//黒画面
	if (Load == TRUE)
	{
		LOADING();
	}

	return;
}

//プレイ画面
VOID MY_PLAY(VOID)
{
	MY_PLAY_PROC();	//プレイ画面の処理
	MY_PLAY_DRAW();	//プレイ画面の描画

	return;
}

//プレイ画面の処理
VOID MY_PLAY_PROC(VOID)
{
	if (CheckSoundMem(PlayBGM.handle) == 0)
	{
		ChangeVolumeSoundMem(255 * 50 / 100, PlayBGM.handle);

		//BGMを流す
		//DX_PLAYTYPE_NORMAL:　ノーマル再生
		//DX_PLAYTYPE_BACK  : バックグラウンド再生
		//DX_PLAYTYPE_LOOP  : ループ再生
		PlaySoundMem(PlayBGM.handle, DX_PLAYTYPE_LOOP);
	}
	//機関車走行音（よく聞かないと分からない）（いいかんじのフリー音源も無かった）
	if (CheckSoundMem(pBackBGM.handle) == 0)
	{
		ChangeVolumeSoundMem(255 * 70 / 100, pBackBGM.handle);
		PlaySoundMem(pBackBGM.handle, DX_PLAYTYPE_LOOP);
	}

	//ESCAPEキーを押したら
	if (MY_KEY_DOWN(KEY_INPUT_ESCAPE) == TRUE)
	{
		SetMouseDispFlag(TRUE);		//マウスカーソル表示

		//タイトルに戻りますか　YESNO
		int Ret = MessageBox(GetMainWindowHandle(), ESC_CAPTION, ESC_TITLE, MB_YESNO);

		//YESを選んだとき
		if (Ret == IDYES)
		{
			//BGMを止める
			if (CheckSoundMem(PlayBGM.handle) != 0)
			{
				StopSoundMem(PlayBGM.handle);
			}
			if (CheckSoundMem(pBackBGM.handle) != 0)
			{
				StopSoundMem(pBackBGM.handle);
			}

			//初期化
			FirstMap1 = TRUE;
			FirstMap2 = TRUE;
			FirstMap3 = TRUE;
			FirstMap4 = TRUE;
			FirstMap5 = TRUE;

			NextDoor2 = FALSE;
			NextDoor3 = FALSE;
			NextDoor4 = FALSE;
			NextDoor5 = FALSE;
			NextDoorEnd = FALSE;

			PlayerCnt = 0;
			boyCnt = 0;
			lemCnt = 0;
			sinCnt = 0;
			friCnt = 0;

			EventMap = 1;

			GameScene = GAME_SCENE_START;	//スタート画面に戻る

			return;
		}
		//NOを選んだとき
		else if (Ret == IDNO)
		{
			SetMouseDispFlag(FALSE);	//マウスカーソル非表示
		}
	}

	for (int cnt = 0; cnt < PLAYER_DIV_NUM; cnt++)
	{
		//プレイヤー移動
		chara.player[cnt].speed = 1;
		if (MY_KEY_DOWN(KEY_INPUT_UP) == TRUE)
		{
			chara.CenterY -= chara.player[cnt].speed;
		}
		if (MY_KEY_DOWN(KEY_INPUT_DOWN) == TRUE)
		{
			chara.CenterY += chara.player[cnt].speed;
		}
		if (MY_KEY_DOWN(KEY_INPUT_LEFT) == TRUE)
		{
			chara.CenterX -= chara.player[cnt].speed;
		}
		if (MY_KEY_DOWN(KEY_INPUT_RIGHT) == TRUE)
		{
			chara.CenterX += chara.player[cnt].speed;
		}

		//キャラの当たり判定(coll)
		//会話用当たり判定(~~Rect)(collよりちょっとだけ広くなってる)
		//プレイヤー
		chara.coll.left = chara.CenterX - mapChip.width / 2 + 9;
		chara.coll.top = chara.CenterY + mapChip.height / 2;
		chara.coll.right = chara.CenterX + mapChip.width / 2 - 7;
		chara.coll.bottom = chara.CenterY + mapChip.height + 17;

		PlayerRect.left = chara.coll.left - 5;
		PlayerRect.top = chara.coll.top - 5;
		PlayerRect.right = chara.coll.right + 5;
		PlayerRect.bottom = chara.coll.bottom + 5;
		
		//他のキャラは表示されていないとき当たり判定をなくす
		//少年
		if (boy.IsDraw == TRUE)
		{
			boy.coll.left = boy.CenterX - mapChip.width / 2 + 9;
			boy.coll.top = boy.CenterY + mapChip.height / 2;
			boy.coll.right = boy.CenterX + mapChip.width / 2 - 7;
			boy.coll.bottom = boy.CenterY + mapChip.height + 17;

			boyRect.left = boy.coll.left - 5;
			boyRect.top = boy.coll.top - 5;
			boyRect.right = boy.coll.right + 5;
			boyRect.bottom = boy.coll.bottom + 5;
		}
		else
		{
			boy.coll.left = 0;
			boy.coll.top = 0;
			boy.coll.right = 0;
			boy.coll.bottom = 0;

			boyRect.left = 0;
			boyRect.top = 0;
			boyRect.right = 0;
			boyRect.bottom = 0;
		}
		//女性
		if (Lemon.IsDraw == TRUE)
		{
			Lemon.coll.left = Lemon.CenterX - mapChip.width / 2 + 9;
			Lemon.coll.top = Lemon.CenterY + mapChip.height / 2;
			Lemon.coll.right = Lemon.CenterX + mapChip.width / 2 - 7;
			Lemon.coll.bottom = Lemon.CenterY + mapChip.height + 17;

			LemRect.left = Lemon.coll.left - 5;
			LemRect.top = Lemon.coll.top - 5;
			LemRect.right = Lemon.coll.right + 5;
			LemRect.bottom = Lemon.coll.bottom + 5;
		}
		else
		{
			Lemon.coll.left = 0;
			Lemon.coll.top = 0;
			Lemon.coll.right = 0;
			Lemon.coll.bottom = 0;

			LemRect.left = 0;
			LemRect.top = 0;
			LemRect.right = 0;
			LemRect.bottom = 0;
		}
		//男性
		if (Sinner.IsDraw == TRUE)
		{
			Sinner.coll.left = Sinner.CenterX - mapChip.width / 2 + 9;
			Sinner.coll.top = Sinner.CenterY + mapChip.height / 2;
			Sinner.coll.right = Sinner.CenterX + mapChip.width / 2 - 7;
			Sinner.coll.bottom = Sinner.CenterY + mapChip.height + 17;

			SinRect.left = Sinner.coll.left - 5;
			SinRect.top = Sinner.coll.top - 5;
			SinRect.right = Sinner.coll.right + 5;
			SinRect.bottom = Sinner.coll.bottom + 5;
		}
		else
		{
			Sinner.coll.left = 0;
			Sinner.coll.top = 0;
			Sinner.coll.right = 0;
			Sinner.coll.bottom = 0;

			SinRect.left = 0;
			SinRect.top = 0;
			SinRect.right = 0;
			SinRect.bottom = 0;
		}
		//友人
		if (Friend.IsDraw == TRUE)
		{
			Friend.coll.left = Friend.CenterX - mapChip.width / 2 + 9;
			Friend.coll.top = Friend.CenterY + mapChip.height / 2;
			Friend.coll.right = Friend.CenterX + mapChip.width / 2 - 7;
			Friend.coll.bottom = Friend.CenterY + mapChip.height + 17;

			FriRect.left = Friend.coll.left - 5;
			FriRect.top = Friend.coll.top - 5;
			FriRect.right = Friend.coll.right + 5;
			FriRect.bottom = Friend.coll.bottom + 5;
		}
		else
		{
			Friend.coll.left = 0;
			Friend.coll.top = 0;
			Friend.coll.right = 0;
			Friend.coll.bottom = 0;

			FriRect.left = 0;
			FriRect.top = 0;
			FriRect.right = 0;
			FriRect.bottom = 0;
		}

		IsMove = TRUE;	//プレイヤー動ける

		//プレイヤーとマップが当たったとき
		if (MY_CHECK_MAP1_PLAYER_COLL(chara.coll) == TRUE)
		{
			chara.CenterX = chara.player[cnt].collBeforePt.x;
			chara.CenterY = chara.player[cnt].collBeforePt.y;

			IsMove = FALSE;	//プレイヤー動けない
		}
		//プレイヤーとその他キャラ
		if (MY_CHECK_CHARA_PLAYER_COLL(chara.coll) == TRUE)
		{
			chara.CenterX = chara.player[cnt].collBeforePt.x;
			chara.CenterY = chara.player[cnt].collBeforePt.y;

			IsMove = FALSE;
		}

		//あいてむの当たり判定
		//切符
		RECT ItemRect;
		if (Chiket.IsDraw == TRUE)
		{
			ItemRect.left = Chiket.image.x + 20;
			ItemRect.top = Chiket.image.y + 20;
			ItemRect.right = Chiket.image.x + Chiket.image.width - 20;
			ItemRect.bottom = Chiket.image.y + Chiket.image.height - 20;
		}
		else
		{
			ItemRect.left = 0;
			ItemRect.top = 0;
			ItemRect.right = 0;
			ItemRect.bottom = 0;
		}
		//手帳
		RECT mLemRect;
		if (MemoLem.IsDraw == TRUE)
		{
			mLemRect.left = MemoLem.image.x + 20;
			mLemRect.top = MemoLem.image.y + 20;
			mLemRect.right = MemoLem.image.x + MemoLem.image.width - 20;
			mLemRect.bottom = MemoLem.image.y + MemoLem.image.height - 20;
		}
		else
		{
			mLemRect.left = 0;
			mLemRect.top = 0;
			mLemRect.right = 0;
			mLemRect.bottom = 0;
		}
		//新聞
		RECT shinbunRect;
		if (Shinbun.IsDraw == TRUE)
		{
			shinbunRect.left = Shinbun.image.x + 20;
			shinbunRect.top = Shinbun.image.y + 20;
			shinbunRect.right = Shinbun.image.x + Shinbun.image.width - 20;
			shinbunRect.bottom = Shinbun.image.y + Shinbun.image.height - 20;
		}
		else
		{
			shinbunRect.left = 0;
			shinbunRect.top = 0;
			shinbunRect.right = 0;
			shinbunRect.bottom = 0;
		}
		//アイテムテキスト
		//同じ処理なのでまとめたほうがよかったかも
		if (MY_CHECK_RECT_COLL(PlayerRect, ItemRect) == TRUE)
		{
			ItemNum = 0;	//アイテム番号０
			//エンターキーを押したら
			if (MY_KEY_UP(KEY_INPUT_RETURN) == TRUE)
			{
				ItemFlg = TRUE;	//テキスト表示
				ItemGet = TRUE;	//ＳＥ鳴らす
			}
			if (ItemFlg == TRUE)
			{
				//テキスト表示中はプレイヤーを動かせない
				chara.CenterX = chara.player[cnt].collBeforePt.x;
				chara.CenterY = chara.player[cnt].collBeforePt.y;

				IsMove = FALSE;

				//少年との会話前と後でテキストが変わる
				//アイテムが拾えるなら
				if (ItemOK == TRUE)
				{
					//ＳＥ
					if (ItemGet == TRUE)
					{
						if (CheckSoundMem(ItemSE.handle) == 0)
						{
							PlaySoundMem(ItemSE.handle, DX_PLAYTYPE_BACK);
						}
						ItemGet = FALSE;
					}
					if (MY_KEY_DOWN(KEY_INPUT_BACK) == TRUE)
					{
						CheckChiket = TRUE;	//切符ゲット
						ItemFlg = FALSE;	//テキスト非表示
						Chiket.IsDraw = FALSE;	//アイテム画像を消す
					}
				}
				else  //拾えないとき
				{
					if (MY_KEY_DOWN(KEY_INPUT_BACK) == TRUE)
					{
						ItemFlg = FALSE;	//テキスト非表示
					}
				}
			}
			if (ItemFlg == FALSE)
			{
				IsMove = TRUE;		//プレイヤー動ける
			}
		}
		//新聞
		if (MY_CHECK_RECT_COLL(PlayerRect, shinbunRect) == TRUE)
		{
			ItemNum = 1;	//アイテム番号１
			if (MY_KEY_UP(KEY_INPUT_RETURN) == TRUE)
			{
				ItemFlg = TRUE;
			}
			if (ItemFlg == TRUE)
			{
				chara.CenterX = chara.player[cnt].collBeforePt.x;
				chara.CenterY = chara.player[cnt].collBeforePt.y;

				IsMove = FALSE;

				if (ItemGet == TRUE)
				{
					if (CheckSoundMem(ItemSE.handle) == 0)
					{
						PlaySoundMem(ItemSE.handle, DX_PLAYTYPE_BACK);
					}
					ItemGet = FALSE;
				}
				if (MY_KEY_DOWN(KEY_INPUT_BACK) == TRUE)
				{
					ItemFlg = FALSE;
					Shinbun.IsDraw = FALSE;
				}
			}
			if (ItemFlg == FALSE)
			{
				IsMove = TRUE;
			}
		}
		//手帳
		if (MY_CHECK_RECT_COLL(PlayerRect, mLemRect) == TRUE)
		{
			ItemNum = 2;	//アイテム番号２
			if (MY_KEY_UP(KEY_INPUT_RETURN) == TRUE)
			{
				ItemFlg = TRUE;
				ItemGet = TRUE;
			}
			if (ItemFlg == TRUE)
			{
				chara.CenterX = chara.player[cnt].collBeforePt.x;
				chara.CenterY = chara.player[cnt].collBeforePt.y;

				IsMove = FALSE;

				if (ItemGet == TRUE)
				{
					if (CheckSoundMem(ItemSE.handle) == 0)
					{
						PlaySoundMem(ItemSE.handle, DX_PLAYTYPE_BACK);
					}
					ItemGet = FALSE;
				}

				if (MY_KEY_DOWN(KEY_INPUT_BACK) == TRUE)
				{
					CheckMemL = TRUE;
					ItemFlg = FALSE;
					MemoLem.IsDraw = FALSE;
				}
			}
			if (ItemFlg == FALSE)
			{
				IsMove = TRUE;
			}
		}


		//会話
		if (MY_CHECK_RECT_COLL(PlayerRect, boyRect) == TRUE)
		{
			if (MY_KEY_UP(KEY_INPUT_RETURN) == TRUE)
			{
				boyFlg = TRUE;		//会話フラグ
				if (boyCnt == 0)
				{
					boy1flg = TRUE;
				}
				if (boyCnt == 1)
				{
					boy2flg = TRUE;
				}
				if (boyCnt == 2)
				{
					if (EventMap != 1)	//次のマップに移動待ち
					{
						boyCnt = 3;
					}
					else
					{
						boy3flg = TRUE;
					}
				}
				if (boyCnt == 3)
				{
					boy4flg = TRUE;
				}
				if (boyCnt == 4)
				{
					if (CheckChiket == TRUE)	//切符待ち
					{
						boyCnt = 5;
					}
					else
					{
						boy5flg = TRUE;
					}
				}
				if (boyCnt == 5)
				{
					boy6flg = TRUE;
				}

				if (boyCnt == 6)
				{
					if (EventMap != 2)	//次のマップに移動待ち
					{
						boyCnt = 7;
					}
					else
					{
						boy7flg = TRUE;
					}
				}
				if (boyCnt == 7)
				{
					if (EventMap != 3)	//次のマップに移動待ち
					{
						boyCnt = 8;
						boy8flg = FALSE;	//なぜか重ねて表示されてしまうので前の分のフラグを折る
					}
					else
					{
						boy8flg = TRUE;
					}
				}
				if (boyCnt == 8)
				{
					if (EventMap != 4)	//次のマップに移動待ち
					{
						boyCnt = 9;
						boy9flg = FALSE;	//なぜか重ねて表示されてしまうので前の分のフラグを折る
					}
					else
					{
						boy9flg = TRUE;
					}
				}
				if (boyCnt == 9)
				{
					boy10flg = TRUE;
				}
				boyFirstText = TRUE;	//ＳＥ
			}
			if (boyFlg == TRUE)
			{
				chara.CenterX = chara.player[cnt].collBeforePt.x;
				chara.CenterY = chara.player[cnt].collBeforePt.y;

				IsMove = FALSE;
				bTEXT = TRUE;

				//ＳＥ
				if (boyFirstText == TRUE)
				{
					if (CheckSoundMem(talkSE.handle) == 0)
					{
						PlaySoundMem(talkSE.handle, DX_PLAYTYPE_BACK);
					}
					boyFirstText = FALSE;
				}

				if (MY_KEY_DOWN(KEY_INPUT_BACK) == TRUE)
				{
					if (boy1flg == TRUE)
					{
						boyCnt = 1;
						boy1flg = FALSE;
						boyName = TRUE;
					}
					if (boy2flg == TRUE)
					{
						boyCnt = 2;
						boy2flg = FALSE;
					}
					if (boy3flg == TRUE)
					{
						boy3flg = FALSE;
					}
					if (boy4flg == TRUE)
					{
						boyCnt = 4;
						boy4flg = FALSE;
						ItemOK = TRUE;
					}
					if (boy5flg == TRUE)
					{
						boy5flg = FALSE;
					}
					if (boy6flg == TRUE)
					{
						boyCnt = 6;
						boy6flg = FALSE;
					}
					if (boy7flg == TRUE)
					{
						boy7flg = FALSE;
					}
					if (boy8flg == TRUE)
					{
						boy8flg == FALSE;
					}
					if (boy9flg == TRUE)
					{
						boy9flg == FALSE;
					}
					if (boy10flg == TRUE)
					{
						boy10flg == FALSE;
					}
					boyFlg = FALSE;
				}
			}
			if (boyFlg == FALSE)
			{
				IsMove = TRUE;
				if (boyCnt == 2)
				{
					NextDoor2 = TRUE;
				}
				if (boyCnt == 6)
				{
					NextDoor3 = TRUE;
				}
			}
		}
		//女性
		if (MY_CHECK_RECT_COLL(PlayerRect, LemRect) == TRUE)
		{
			if (MY_KEY_UP(KEY_INPUT_RETURN) == TRUE)
			{
				LemFlg = TRUE;		//会話フラグ
				if (lemCnt == 0)
				{
					lem1flg = TRUE;
				}
				if (lemCnt == 1)
				{
					lem2flg = TRUE;
				}
				if (lemCnt == 2)
				{
					if (CheckMemL == TRUE)
					{
						lemCnt = 3;
					}
					else
					{
						lem3flg = TRUE;
					}
				}
				if (lemCnt == 3)
				{
					lem4flg = TRUE;
				}
				lemFirstText = TRUE;
			}
			if (LemFlg == TRUE)
			{
				chara.CenterX = chara.player[cnt].collBeforePt.x;
				chara.CenterY = chara.player[cnt].collBeforePt.y;

				IsMove = FALSE;
				lTEXT = TRUE;

				if (lemFirstText == TRUE)
				{
					if (CheckSoundMem(talkSE.handle) == 0)
					{
						PlaySoundMem(talkSE.handle, DX_PLAYTYPE_BACK);
					}
					lemFirstText = FALSE;
				}

				if (MY_KEY_DOWN(KEY_INPUT_BACK) == TRUE)
				{
					if (lem1flg == TRUE)
					{
						lemCnt = 1;
						lem1flg = FALSE;
					}
					if (lem2flg == TRUE)
					{
						lemCnt = 2;
						lem2flg = FALSE;
					}
					if (lem3flg == TRUE)
					{
						lem3flg = FALSE;
					}
					if (lem4flg == TRUE)
					{
						lem4flg = FALSE;
					}
					LemFlg = FALSE;
				}
			}
			if (LemFlg == FALSE)
			{
				IsMove = TRUE;
				if (lemCnt == 3)
				{
					NextDoor4 = TRUE;
				}
			}
		}
		//男性
		if (MY_CHECK_RECT_COLL(PlayerRect, SinRect) == TRUE)
		{
			if (MY_KEY_UP(KEY_INPUT_RETURN) == TRUE)
			{
				sinFlg = TRUE;		//会話フラグ
				if (sinCnt == 0)
				{
					sin1flg = TRUE;
				}
				if (sinCnt == 1)
				{
					sin2flg = TRUE;
				}
				sinFirstText = TRUE;
			}
			if (sinFlg == TRUE)
			{
				chara.CenterX = chara.player[cnt].collBeforePt.x;
				chara.CenterY = chara.player[cnt].collBeforePt.y;

				IsMove = FALSE;
				sTEXT = TRUE;

				if (sinFirstText == TRUE)
				{
					if (CheckSoundMem(talkSE.handle) == 0)
					{
						PlaySoundMem(talkSE.handle, DX_PLAYTYPE_BACK);
					}
					sinFirstText = FALSE;
				}

				if (MY_KEY_DOWN(KEY_INPUT_BACK) == TRUE)
				{
					if (sin1flg == TRUE)
					{
						sinCnt = 1;
						sin1flg = FALSE;
					}
					if (sin2flg == TRUE)
					{
						sin2flg = FALSE;
					}
					sinFlg = FALSE;
				}
			}
			if (sinFlg == FALSE)
			{
				IsMove = TRUE;
				if (sinCnt == 1)
				{
					NextDoor5 = TRUE;
				}
			}
		}
		//友人
		if (MY_CHECK_RECT_COLL(PlayerRect, FriRect) == TRUE)
		{
			if (MY_KEY_UP(KEY_INPUT_RETURN) == TRUE)
			{
				FriFlg = TRUE;		//会話フラグ
				if (friCnt == 0)
				{
					fri1flg = TRUE;
				}
				if (friCnt == 1)
				{
					fri2flg = TRUE;
				}
				friFirstText = TRUE;
			}
			if (FriFlg == TRUE)
			{
				chara.CenterX = chara.player[cnt].collBeforePt.x;
				chara.CenterY = chara.player[cnt].collBeforePt.y;

				IsMove = FALSE;
				fTEXT = TRUE;

				if (friFirstText == TRUE)
				{
					if (CheckSoundMem(talkSE.handle) == 0)
					{
						PlaySoundMem(talkSE.handle, DX_PLAYTYPE_BACK);
					}
					friFirstText = FALSE;
				}

				if (MY_KEY_DOWN(KEY_INPUT_BACK) == TRUE)
				{
					if (fri1flg == TRUE)
					{
						friCnt = 1;
						fri1flg = FALSE;
					}
					if (fri2flg == TRUE)
					{
						fri2flg = FALSE;
					}
					FriFlg = FALSE;
				}
			}
			if (FriFlg == FALSE)
			{
				IsMove = TRUE;
				if (friCnt == 1)
				{
					NextDoorEnd = TRUE;
				}
			}
		}

		if (FirstMap1 == TRUE)
		{
			if (PlayerCnt == 0)
			{
				if (MY_KEY_DOWN(KEY_INPUT_UP) == TRUE || MY_KEY_DOWN(KEY_INPUT_DOWN) == TRUE ||
					MY_KEY_DOWN(KEY_INPUT_LEFT) == TRUE || MY_KEY_DOWN(KEY_INPUT_RIGHT) == TRUE)
				{
					PlayerFlg = TRUE;
				}
			}
		}
		//プレイヤー会話
		if (PlayerFlg == TRUE)
		{
			Player1flg = TRUE;

			chara.CenterX = chara.player[cnt].collBeforePt.x;
			chara.CenterY = chara.player[cnt].collBeforePt.y;

			IsMove = FALSE;
			pTEXT = TRUE;

			if (PlayerFirstText == TRUE)
			{
				if (CheckSoundMem(talkSE.handle) == 0)
				{
					PlaySoundMem(talkSE.handle, DX_PLAYTYPE_BACK);
				}
				PlayerFirstText = FALSE;
			}

			if (MY_KEY_DOWN(KEY_INPUT_BACK) == TRUE)
			{
				Player1flg = FALSE;
				PlayerCnt = 1;
				PlayerFlg = FALSE;
				IsMove = TRUE;
			}
		}

		//プレイヤーが動けるとき
		if (IsMove == TRUE)
		{
			//プレイヤーの位置に置き換える
			chara.player[cnt].x = chara.CenterX - chara.player[cnt].width / 2;
			chara.player[cnt].y = chara.CenterY - chara.player[cnt].height / 2;
			//あたっていないときの座標を取得
			chara.player[cnt].collBeforePt.x = chara.CenterX;
			chara.player[cnt].collBeforePt.y = chara.CenterY;

			//押したキーに応じて画像を切り替え
			//０：左向き前
			//１：右向き前
			//２：左向き足
			//３：右向き足
			//移動キーを押したとき
			if (MY_KEY_DOWN(KEY_INPUT_LEFT) == TRUE || MY_KEY_DOWN(KEY_INPUT_RIGHT) == TRUE ||
				MY_KEY_DOWN(KEY_INPUT_DOWN) == TRUE || MY_KEY_DOWN(KEY_INPUT_UP) == TRUE)
			{
				//足音
				if (CheckSoundMem(walkSE.handle) == 0)
				{
					PlaySoundMem(walkSE.handle, DX_PLAYTYPE_BACK);
				}

				if (MY_KEY_DOWN(KEY_INPUT_LEFT) == TRUE)	//左
				{
					chara.player[cnt].nowImageKind = 0;
				}
				if (MY_KEY_DOWN(KEY_INPUT_RIGHT) == TRUE)	//右
				{
					chara.player[cnt].nowImageKind = 1;
				}
				if (MY_KEY_DOWN(KEY_INPUT_DOWN) == TRUE)	//下
				{
					//今の画像が左向きなら
					if (chara.player[cnt].nowImageKind == 0 || chara.player[cnt].nowImageKind == 2)
					{
						chara.player[cnt].nowImageKind = 0;
					}
					//それ以外(右向き)なら
					else
					{
						chara.player[cnt].nowImageKind = 1;
					}
				}
				if (MY_KEY_DOWN(KEY_INPUT_UP) == TRUE)		//上
				{
					//今の画像が左向きなら
					if (chara.player[cnt].nowImageKind == 0 || chara.player[cnt].nowImageKind == 2)
					{
						chara.player[cnt].nowImageKind = 0;
					}
					//それ以外(右向き)なら
					else
					{
						chara.player[cnt].nowImageKind = 1;
					}
				}

				Walk = TRUE;	//歩いているフラグ
			}
			else
			{
				Walk = FALSE;	//歩いてない
			}
			//歩いてるフラグが立っているとき
			if (Walk == TRUE)
			{
				int OldImageKind = chara.player[cnt].nowImageKind;	//歩き始めのプレイヤー画像

				if (MY_CHECK_MAP1_PLAYER_COLL(chara.coll) == TRUE || MY_CHECK_CHARA_PLAYER_COLL(chara.coll)
					|| OldImageKind == 2 || OldImageKind == 3)	//マップやキャラに当たったとき、または歩き始めの画像が２か３なら
				{
					Walk = FALSE;	//歩かせない
				}

				//移動中　画像点滅　切り替え
				if (chara.player[cnt].changeImageCnt < chara.player[cnt].changeImageCntMAX)
				{
					chara.player[cnt].changeImageCnt++;            

					if (chara.player[cnt].changeImageCnt > chara.player[cnt].changeImageCntMAX / 2)
					{
						if (OldImageKind == 0)
						{
							chara.player[cnt].nowImageKind = 2;
						}
						if (OldImageKind == 1)
						{
							chara.player[cnt].nowImageKind = 3;
						}
					}
				}
				else 
				{
					if (chara.player[cnt].nowImageKind == 2)
					{
						chara.player[cnt].nowImageKind = 0;
					}
					if (chara.player[cnt].nowImageKind == 3)
					{
						chara.player[cnt].nowImageKind = 1;
					}
					OldImageKind = chara.player[cnt].nowImageKind;
					chara.player[cnt].changeImageCnt = 0;
				}
			}
			if (Walk == FALSE)
			{
				if (chara.player[cnt].nowImageKind == 2)
				{
					chara.player[cnt].nowImageKind = 0;
				}
				if (chara.player[cnt].nowImageKind == 3)
				{
					chara.player[cnt].nowImageKind = 1;
				}
			}
		}
	}


	for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
		{
			//イベントが起きているマップにだけ少年を表示
			if (map[tate][yoko].num == EventMap)
			{
				//boy.image.y = CHARA_POSITION_Y;
				boy.IsDraw = TRUE;
			}
			if (map[tate][yoko].num == 1 && EventMap >= 2)
			{
				Shinbun.IsDraw = TRUE;
			}
			else
			{
				Shinbun.IsDraw = FALSE;
			}
			if (map[tate][yoko].num == 2 && EventMap == 2)
			{
				if (CheckChiket == FALSE)
				{
					Chiket.IsDraw = TRUE;
				}
			}
			//３両目、女性を表示
			if (map[tate][yoko].num == 3 && EventMap == 3)
			{
				Lemon.IsDraw = TRUE;
				if (CheckMemL == FALSE)
				{
					MemoLem.IsDraw = TRUE;
				}
			}
			//４両目、男性を表示
			if (map[tate][yoko].num == 4 && EventMap == 4)
			{
				Sinner.IsDraw = TRUE;
			}
			//５両目、友人を召喚
			if (map[tate][yoko].num == 5 && EventMap == 5)
			{
				Friend.IsDraw = TRUE;
			}
			//イベントが起きていないマップにいるとき
			if (map[tate][yoko].num != EventMap)
			{
				//キャラを非表示
				boy.IsDraw = FALSE;
				Lemon.IsDraw = FALSE;
				Sinner.IsDraw = FALSE;
				Friend.IsDraw = FALSE;
				//アイテムも非表示
				Chiket.IsDraw = FALSE;
				MemoLem.IsDraw = FALSE;
			}

			//右端(扉)
			if (MY_CHECK_RECT_COLL(PlayerRect, ReturnRect) == TRUE)
			{
				if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
				{
					//2番目以降の車両なら
					if (map[tate][yoko].num > 1)
					{
						//前の車両にどもる
						map[tate][yoko].num--;

						Loading.Cnt = 0;
						if (Loading.Cnt < IMAGE_LOADING_CNT)
						{
							Load = TRUE;
						}
						else if (Loading.Cnt > IMAGE_LOADING_CNT)
						{
							Load = FALSE;
						}

						PlaySoundMem(doorSE.handle, DX_PLAYTYPE_BACK);

						chara.CenterX = ReturnPt.x;
						chara.CenterY = ReturnPt.y;
					}
				}
			}

			if (MY_CHECK_RECT_COLL(PlayerRect, GoalRect) == TRUE)
			{
				if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
				{
					//１
					if (map[tate][yoko].num == 1)
					{
						if (NextDoor2 == FALSE)
						{
							if (CheckSoundMem(GachaSE.handle) == 0)
							{
								PlaySoundMem(GachaSE.handle, DX_PLAYTYPE_BACK);
							}
						}
					}
					if (NextDoor2 == TRUE)
					{
						if (map[tate][yoko].num == 1)
						{
							//次の車両に進む
							map[tate][yoko].num++;

							Loading.Cnt = 0;
							if (Loading.Cnt < IMAGE_LOADING_CNT)
							{
								Load = TRUE;
							}
							else if (Loading.Cnt > IMAGE_LOADING_CNT)
							{
								Load = FALSE;
							}

							PlaySoundMem(doorSE.handle, DX_PLAYTYPE_BACK);

							chara.CenterX = ReStartPt.x;
							chara.CenterY = ReStartPt.y;
						}
						if (map[tate][yoko].num == 2)
						{
							FirstMap1 = FALSE;
							if (FirstMap2 == TRUE)
							{
								EventMap = 2;
							}
						}
					}

					//２
					if (map[tate][yoko].num == 2)
					{
						if (NextDoor3 == FALSE)
						{
							if (CheckSoundMem(GachaSE.handle) == 0)
							{
								PlaySoundMem(GachaSE.handle, DX_PLAYTYPE_BACK);
							}
						}
					}
					if (NextDoor3 == TRUE)
					{
						if (map[tate][yoko].num == 2)
						{
							//次の車両に進む
							map[tate][yoko].num++;

							Loading.Cnt = 0;
							if (Loading.Cnt < IMAGE_LOADING_CNT)
							{
								Load = TRUE;
							}
							else if (Loading.Cnt > IMAGE_LOADING_CNT)
							{
								Load = FALSE;
							}

							PlaySoundMem(doorSE.handle, DX_PLAYTYPE_BACK);

							chara.CenterX = ReStartPt.x;
							chara.CenterY = ReStartPt.y;
						}
						if (map[tate][yoko].num == 3)
						{
							FirstMap2 = FALSE;
							if (FirstMap3 == TRUE)
							{
								EventMap = 3;
							}
						}
					}

					//３
					if (map[tate][yoko].num == 3)
					{
						if (NextDoor4 == FALSE)
						{
							if (CheckSoundMem(GachaSE.handle) == 0)
							{
								PlaySoundMem(GachaSE.handle, DX_PLAYTYPE_BACK);
							}
						}
					}
					if (NextDoor4 == TRUE)
					{
						if (map[tate][yoko].num == 3)
						{
							//次の車両に進む
							map[tate][yoko].num++;

							Loading.Cnt = 0;
							if (Loading.Cnt < IMAGE_LOADING_CNT)
							{
								Load = TRUE;
							}
							else if (Loading.Cnt > IMAGE_LOADING_CNT)
							{
								Load = FALSE;
							}

							PlaySoundMem(doorSE.handle, DX_PLAYTYPE_BACK);

							chara.CenterX = ReStartPt.x;
							chara.CenterY = ReStartPt.y;
						}
						if (map[tate][yoko].num == 4)
						{
							FirstMap3 = FALSE;
							if (FirstMap4 == TRUE)
							{
								EventMap = 4;
							}
						}
					}

					//４
					if (map[tate][yoko].num == 4)
					{
						if (NextDoor5 == FALSE)
						{
							if (CheckSoundMem(GachaSE.handle) == 0)
							{
								PlaySoundMem(GachaSE.handle, DX_PLAYTYPE_BACK);
							}
						}
					}
					if (NextDoor5 == TRUE)
					{
						if (map[tate][yoko].num == 4)
						{
							//次の車両に進む
							map[tate][yoko].num++;

							Loading.Cnt = 0;
							if (Loading.Cnt < IMAGE_LOADING_CNT)
							{
								Load = TRUE;
							}
							else if (Loading.Cnt > IMAGE_LOADING_CNT)
							{
								Load = FALSE;
							}

							PlaySoundMem(doorSE.handle, DX_PLAYTYPE_BACK);

							chara.CenterX = ReStartPt.x;
							chara.CenterY = ReStartPt.y;
						}
						if (map[tate][yoko].num == 5)
						{
							FirstMap4 = FALSE;
							if (FirstMap5 == TRUE)
							{
								EventMap = 5;
							}
						}
					}

					//５
					if (map[tate][yoko].num == 5)
					{
						if (NextDoorEnd == FALSE)
						{
							if (CheckSoundMem(GachaSE.handle) == 0)
							{
								PlaySoundMem(GachaSE.handle, DX_PLAYTYPE_BACK);
							}
						}
					}
					if (NextDoorEnd == TRUE && NextDoor2 == TRUE &&
						NextDoor3 == TRUE && NextDoor4 == TRUE && NextDoor5 == TRUE)
					{
						if (map[tate][yoko].num == 5)
						{
							//次の車両に進む
							map[tate][yoko].num++;

							PlaySoundMem(doorSE.handle, DX_PLAYTYPE_BACK);

							Loading.Cnt = 0;
							if (Loading.Cnt < IMAGE_LOADING_CNT)
							{
								Load = TRUE;
							}
							else if (Loading.Cnt > IMAGE_LOADING_CNT)
							{
								Load = FALSE;
							}
						}
						//最後の車両にいるなら
						if (map[tate][yoko].num == GAME_MAP_KIND_MAX + 1)
						{
							FirstMap5 = FALSE;

							//音楽を止める
							if (CheckSoundMem(PlayBGM.handle) != 0)
							{
								StopSoundMem(PlayBGM.handle);
							}
							if (CheckSoundMem(pBackBGM.handle) != 0)
							{
								StopSoundMem(pBackBGM.handle);
							}

							GameEndKind = GAME_END_COMP;
							//エンド画面へ
							GameScene = GAME_SCENE_END;

							return;
						}
					}
				}
			}
		}
	}

	//背景画像を動かす
	for (int num = 0; num < IMAGE_NUM; num++)
	{
		//画像を移動させる
		ImageBack[num].image.x++;

		if (ImageBack[num].IsDraw == FALSE)
		{
			//背景画像が画面内にいるとき
			if (ImageBack[num].image.x + ImageBack[num].image.width > 0)
			{
				ImageBack[num].IsDraw = TRUE;	//画像を描画する
			}
		}
		//背景画像が画面を通り越したとき
		if (ImageBack[num].image.x > GAME_WIDTH)
		{
			ImageBack[num].image.x = 0 - ImageBack[0].image.width * 3;	//画像の高さ２つ分、横に移動させる
			ImageBack[num].IsDraw = FALSE;								//画像を描画しない
		}
	}

	for (int num = 0; num < IMAGE_NUM; num++)
	{
		//画像を移動させる
		ImageFront[num].image.x--;

		if (ImageFront[num].IsDraw == FALSE)
		{
			//背景画像が画面内にいるとき
			if (ImageFront[num].image.x < GAME_WIDTH)
			{
				ImageFront[num].IsDraw = TRUE;	//画像を描画する
			}
		}
		//背景画像が画面を通り越したとき
		if (ImageFront[num].image.x + ImageFront[num].image.width < 0)
		{
			ImageFront[num].image.x = 0 + ImageFront[0].image.width * 3;	//画像の幅２つ分、横に移動させる
			ImageFront[num].IsDraw = FALSE;								//画像を描画しない
		}
	}

	return;
}

//プレイ画面の描画
VOID MY_PLAY_DRAW(VOID)
{
	//プレイ画面の背景を描画
	for (int num = 0; num < IMAGE_NUM; num++)
	{
		if (ImageBack[num].IsDraw == TRUE)
		{
			DrawGraph(ImageBack[num].image.x, ImageBack[num].image.y, ImageBack[num].image.handle, TRUE);
		}
	}
	//マップを描画
	for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
		{
			DrawGraph(
				map[tate][yoko].x,
				map[tate][yoko].y,
				mapChip.handle[map[tate][yoko].kind],
				TRUE);
		}
	}

	//当たり判定の描画（デバッグ用）
	//for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
	//{
	//	for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
	//	{
	//		//壁ならば
	//		if (mapData[tate][yoko] == k || mapData[tate][yoko] == a ||
	//			mapData[tate][yoko] == m || mapData[tate][yoko] == b ||
	//			mapData[tate][yoko] == o || mapData[tate][yoko] == x ||
	//			mapData[tate][yoko] == e || mapData[tate][yoko] == d ||
	//			mapData[tate][yoko] == z || mapData[tate][yoko] == y)
	//		{
	//			DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(0, 0, 255), FALSE);
	//		}
	//		//通路ならば
	//		if (mapData[tate][yoko] == t)
	//		{
	//			DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(255, 255, 0), FALSE);
	//		}
	//		if (mapData[tate][yoko] == g || mapData[tate][yoko] == r)
	//		{
	//			DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(0, 255, 0), FALSE);
	//		}
	//	}
	//}

	if (Chiket.IsDraw == TRUE)
	{
		DrawGraph(Chiket.image.x, Chiket.image.y, Chiket.image.handle, TRUE);
	}
	if (Shinbun.IsDraw == TRUE)
	{
		DrawGraph(Shinbun.image.x, Shinbun.image.y, Shinbun.image.handle, TRUE);
	}
	if (MemoLem.IsDraw == TRUE)
	{
		DrawGraph(MemoLem.image.x, MemoLem.image.y, MemoLem.image.handle, TRUE);
	}

	//キャラ表示
	//少年
	if (boy.IsDraw == TRUE)
	{
		DrawGraph(boy.image.x, boy.image.y, boy.image.handle, TRUE);
		//DrawBox(boy.coll.left, boy.coll.top, boy.coll.right, boy.coll.bottom, GetColor(255, 0, 0), FALSE);
	}
	//女性
	if (Lemon.IsDraw == TRUE)
	{
		DrawGraph(Lemon.image.x, Lemon.image.y, Lemon.image.handle, TRUE);
		//DrawBox(Lemon.coll.left, Lemon.coll.top, Lemon.coll.right, Lemon.coll.bottom, GetColor(255, 0, 0), FALSE);
	}
	//男性
	if (Sinner.IsDraw == TRUE)
	{
		DrawGraph(Sinner.image.x, Sinner.image.y, Sinner.image.handle, TRUE);
		//DrawBox(Sinner.coll.left, Sinner.coll.top, Sinner.coll.right, Sinner.coll.bottom, GetColor(255, 0, 0), FALSE);
	}
	//友人
	if (Friend.IsDraw == TRUE)
	{
		DrawGraph(Friend.image.x, Friend.image.y, Friend.image.handle, TRUE);
		//DrawBox(Friend.coll.left, Friend.coll.top, Friend.coll.right, Friend.coll.bottom, GetColor(255, 0, 0), FALSE);
	}
	//プレイヤー描写
	for (int cnt = 0; cnt < PLAYER_DIV_NUM; cnt++)
	{
		if (chara.IsDraw == TRUE)
		{
			DrawGraph(
				chara.player[cnt].x,
				chara.player[cnt].y,
				chara.player[cnt].handle[chara.player[cnt].nowImageKind],
				TRUE);

			//プレイヤーの当たり判定描画(デバッグ用)
			//DrawBox(chara.coll.left, chara.coll.top, chara.coll.right, chara.coll.bottom, GetColor(255, 0, 0), FALSE);
		}
	}

	//DrawString(0, 0, "矢印キーで移動・ESCAPEキーでスタートに戻る", GetColor(255, 255, 255));

	for (int num = 0; num < IMAGE_NUM; num++)
	{
		if (ImageFront[num].IsDraw == TRUE)
		{
			DrawGraph(ImageFront[num].image.x, ImageFront[num].image.y, ImageFront[num].image.handle, TRUE);
		}
	}

	for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
		{
			DrawFormatString(0, 20, GetColor(255, 255, 255), "現在のマップ：%d", map[tate][yoko].num);
			DrawFormatString(0, 40, GetColor(255, 255, 255), "イベントが起きているマップ：%d", EventMap);
		}
	}

	int Itemgyou = 1;
	int ItemgyouMAX = 1;
	if (ItemFlg == TRUE)
	{
		SISTEM_TEXT(Itemgyou, ItemgyouMAX);

		if (Itemgyou < ItemgyouMAX)
		{
			if (MY_KEY_UP(KEY_INPUT_RETURN) == TRUE)
			{
				iNextString = TRUE;
			}
			if (iNextString == TRUE)
			{
				if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
				{
					Itemgyou++;
					if (iTEXT == TRUE)
					{
						if (Itemgyou > 0)
						{
							iFirstText = TRUE;
						}
					}
					iNextString = FALSE;
				}
			}
		}
		if (Itemgyou > ItemgyouMAX - 1)
		{
			iTEXT = FALSE;
			if (MY_KEY_DOWN(KEY_INPUT_BACK) == TRUE)
			{
				ItemFlg = FALSE;
			}
		}
	}
	if (ItemFlg == FALSE)
	{
		Itemgyou = 0;
		iNextString = FALSE;
		iTEXT = TRUE;
		iFirstText = TRUE;
	}

	//プレイヤーテキスト表示
	if (PlayerFlg == TRUE)
	{
		int PlayergyouMAX = 3;
		PLAYER_TEXT(Playergyou, PlayergyouMAX);
		//文字送り
		if (Playergyou < PlayergyouMAX)
		{ 
			//MY_KEY_DOWNだとありえんぐらいカウントするのでMY_KEY_UPを使用
			if (MY_KEY_UP(KEY_INPUT_RETURN) == TRUE)
			{
				Playergyou++;
				if (pTEXT == TRUE)
				{
					PlayerFirstText = TRUE;
				}
			}
		}
		if (Playergyou >= PlayergyouMAX - 1)
		{
			pTEXT = FALSE;
			if (MY_KEY_DOWN(KEY_INPUT_BACK) == TRUE)
			{
				PlayerFlg = FALSE;
				Playergyou = 0;
				pTEXT = TRUE;
				PlayerFirstText = TRUE;
			}
		}
	}
	//少年テキスト表示
	if (boyFlg == TRUE)
	{
		int boygyouMAX = 3;

		if (boy2flg == TRUE)
		{
			boygyouMAX = 8;
		}
		if (boy3flg == TRUE || boy5flg == TRUE || boy7flg == TRUE)
		{
			boygyouMAX = 1;
		}
		if (boy6flg == TRUE)
		{
			boygyouMAX = 10;
		}
		if (boy8flg == TRUE || boy9flg == TRUE || boy10flg == TRUE)
		{
			boygyouMAX = 2;
		}

		//テキスト表示
		BOY_TEXT(boygyou, boygyouMAX);
		//文字送り
		if (boygyou < boygyouMAX)
		{
			//MY_KEY_DOWNだとありえんぐらいカウントするのでMY_KEY_UPを使用
			//最初の行が表示されなかったのでUPしたあともう一度DOWNさせてから次の行へ
			if (MY_KEY_UP(KEY_INPUT_RETURN) == TRUE)
			{
				bNextString = TRUE;
			}
			if (bNextString == TRUE)
			{
				if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
				{
					boygyou++;
					if (bTEXT == TRUE)
					{
						boyFirstText = TRUE;
					}
					bNextString = FALSE;
				}
			}
		}
		if (boygyou > boygyouMAX - 1)
		{
			bTEXT = FALSE;
			if (MY_KEY_DOWN(KEY_INPUT_BACK) == TRUE)
			{
				boyFlg = FALSE;
			}
		}
	}
	if (boyFlg == FALSE)
	{
		bNextString = FALSE;
		boygyou = 0;
		bTEXT = TRUE;
		boyFirstText = TRUE;
	}
	//女性テキスト表示
	if (LemFlg == TRUE)
	{
		int lemgyouMAX = 2;

		if (lem2flg == TRUE)
		{
			lemgyouMAX = 6;
		}
		if (lem4flg == TRUE)
		{
			lemgyouMAX = 1;
		}

		//テキスト表示
		LEMON_TEXT(lemgyou, lemgyouMAX);
		//文字送り
		if (lemgyou < lemgyouMAX)
		{
			//MY_KEY_DOWNだとありえんぐらいカウントするのでMY_KEY_UPを使用
			//最初の行が表示されなかったのでUPしたあともう一度DOWNさせてから次の行へ
			if (MY_KEY_UP(KEY_INPUT_RETURN) == TRUE)
			{
				lNextString = TRUE;
			}
			if (lNextString == TRUE)
			{
				if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
				{
					lemgyou++;
					if (bTEXT == TRUE)
					{
						lemFirstText = TRUE;
					}
					lNextString = FALSE;
				}
			}
		}
		if (lemgyou > lemgyouMAX -1)
		{
			lTEXT = FALSE;
			if (MY_KEY_DOWN(KEY_INPUT_BACK) == TRUE)
			{
				LemFlg = FALSE;
			}
		}
	}
	if (LemFlg == FALSE)
	{
		lNextString = FALSE;
		lemgyou = 0;
		lTEXT = TRUE;
		lemFirstText = TRUE;
	}
	//男性テキスト表示
	if (sinFlg == TRUE)
	{
		int singyouMAX = 6;

		if (sin2flg == TRUE)
		{
			singyouMAX = 1;
		}
		//テキスト表示
		SINNER_TEXT(singyou, singyouMAX);
		//文字送り
		if (singyou < singyouMAX)
		{
			//MY_KEY_DOWNだとありえんぐらいカウントするのでMY_KEY_UPを使用
			//最初の行が表示されなかったのでUPしたあともう一度DOWNさせてから次の行へ
			if (MY_KEY_UP(KEY_INPUT_RETURN) == TRUE)
			{
				sNextString = TRUE;
			}
			if (sNextString == TRUE)
			{
				if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
				{
					singyou++;
					if (sTEXT == TRUE)
					{
						sinFirstText = TRUE;
					}
					sNextString = FALSE;
				}
			}
		}
		if (singyou > singyouMAX - 1)
		{
			sTEXT = FALSE;
			if (MY_KEY_DOWN(KEY_INPUT_BACK) == TRUE)
			{
				sinFlg = FALSE;
			}
		}
	}
	if (sinFlg == FALSE)
	{
		sNextString = FALSE;
		singyou = 0;
		sTEXT = TRUE;
		sinFirstText = TRUE;
	}
	//友人テキスト表示
	if (FriFlg == TRUE)
	{
		int frigyouMAX = 1;
		//テキスト表示
		FRIEND_TEXT(frigyou, frigyouMAX);
		//文字送り
		if (frigyou < frigyouMAX)
		{
			//MY_KEY_DOWNだとありえんぐらいカウントするのでMY_KEY_UPを使用
			//最初の行が表示されなかったのでUPしたあともう一度DOWNさせてから次の行へ
			if (MY_KEY_UP(KEY_INPUT_RETURN) == TRUE)
			{
				fNextString = TRUE;
			}
			if (fNextString == TRUE)
			{
				if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
				{
					frigyou++;
					if (lTEXT == TRUE)
					{
						friFirstText = TRUE;
					}
					fNextString = FALSE;
				}
			}
		}
		if (frigyou > frigyouMAX - 1)
		{
			bTEXT = FALSE;
			if (MY_KEY_DOWN(KEY_INPUT_BACK) == TRUE)
			{
				FriFlg = FALSE;
			}
		}
	}
	if (FriFlg == FALSE)
	{
		fNextString = FALSE;
		frigyou = 0;
		fTEXT = TRUE;
		friFirstText = TRUE;
	}

	//黒画面
	if (Load == TRUE)
	{
		LOADING();
	}

	return;
}

//エンド画面
VOID MY_END(VOID)
{
	MY_END_PROC();	//エンド画面の処理
	MY_END_DRAW();	//エンド画面の描画
	return;
}

//エンド画面の処理
VOID MY_END_PROC(VOID)
{
	if (CheckSoundMem(EndBGM.handle) == 0)
	{
		ChangeVolumeSoundMem(255 * 50 / 100, EndBGM.handle);

		//BGMを流す
		//DX_PLAYTYPE_NORMAL:　ノーマル再生
		//DX_PLAYTYPE_BACK  : バックグラウンド再生
		//DX_PLAYTYPE_LOOP  : ループ再生
		PlaySoundMem(EndBGM.handle, DX_PLAYTYPE_LOOP);
	}

	//エスケープキーを押したら、スタートシーンへ移動する
	if (MY_KEY_DOWN(KEY_INPUT_ESCAPE) == TRUE)
	{
		//BGMが流れているなら
		if (CheckSoundMem(EndBGM.handle) != 0)
		{
			StopSoundMem(EndBGM.handle);
		}

		FirstMap1 = TRUE;
		FirstMap2 = TRUE;
		FirstMap3 = TRUE;
		FirstMap4 = TRUE;
		FirstMap5 = TRUE;

		PlayerCnt = 0;
		boyCnt = 0;
		lemCnt = 0;
		sinCnt = 0;
		friCnt = 0;

		EventMap = 1;

		GameScene = GAME_SCENE_START;
	}

	return;
}

//エンド画面の描画
VOID MY_END_DRAW(VOID)
{
	//背景を描画
	DrawGraph(EndBack.x, EndBack.y, EndBack.handle, TRUE);

	if (GameEndKind == GAME_END_COMP)
	{
		DrawGraph(EndROGO.image.x, EndROGO.image.y, EndROGO.image.handle, TRUE);
	}

	DrawString(0, 0, "エンド画面(エスケープキーを押して下さい)", GetColor(255, 255, 255));

	return;
}

BOOL MY_LOAD_IMAGE(VOID)
{
	//タイトル背景
	strcpy_s(StartBack.path, IMAGE_START_BACK);
	StartBack.handle = LoadGraph(StartBack.path);	//読み込み
	if (StartBack.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_START_BACK, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(StartBack.handle, &StartBack.width, &StartBack.height);
	StartBack.x = GAME_WIDTH / 2 - StartBack.width / 2;
	StartBack.y = GAME_HEIGHT / 2 - StartBack.height / 2;

	//タイトルロゴ
	strcpy_s(Title2.image.path, IMAGE_START_TITLE2);
	Title2.image.handle = LoadGraph(Title2.image.path);	//読み込み
	if (Title2.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_START_TITLE2, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(Title2.image.handle, &Title2.image.width, &Title2.image.height);
	Title2.image.x = GAME_WIDTH / 2 - Title2.image.width / 2;
	Title2.image.y = GAME_HEIGHT / 2 - Title2.image.width / 2 + 180;
	Title2.IsDraw = FALSE;

	strcpy_s(Title.image.path, IMAGE_START_TITLE);
	Title.image.handle = LoadGraph(Title.image.path);	//読み込み
	if (Title.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_START_TITLE, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(Title.image.handle, &Title.image.width, &Title.image.height);
	Title.image.x = GAME_WIDTH / 2 - Title.image.width / 2;
	Title.image.y = GAME_HEIGHT / 2 - Title.image.width / 2 + 120;
	Title.IsDraw = FALSE;

	strcpy_s(TitleROGO.image.path, IMAGE_START_TITLEROGO);
	TitleROGO.image.handle = LoadGraph(TitleROGO.image.path);	//読み込み
	if (TitleROGO.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_START_TITLEROGO, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(TitleROGO.image.handle, &TitleROGO.image.width, &TitleROGO.image.height);
	TitleROGO.image.x = GAME_WIDTH / 2 - TitleROGO.image.width / 2;
	TitleROGO.image.y = GAME_HEIGHT / 2 - TitleROGO.image.height / 2 - 40;
	TitleROGO.IsDraw = FALSE;

	//メニュー
	strcpy_s(menu1.image.path, IMAGE_START_MENU1);
	menu1.image.handle = LoadGraph(menu1.image.path);	//読み込み
	if (menu1.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_START_MENU1, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(menu1.image.handle, &menu1.image.width, &menu1.image.height);
	menu1.image.x = GAME_WIDTH / 2 - menu1.image.width / 2;
	menu1.image.y = TitleROGO.image.y + TitleROGO.image.height + 20;
	menu1.IsDraw = FALSE;

	strcpy_s(menu2.image.path, IMAGE_START_MENU2);
	menu2.image.handle = LoadGraph(menu2.image.path);	//読み込み
	if (menu2.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_START_MENU2, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(menu2.image.handle, &menu2.image.width, &menu2.image.height);
	menu2.image.x = GAME_WIDTH / 2 - menu2.image.width / 2;
	menu2.image.y = TitleROGO.image.y + TitleROGO.image.height + 20;
	menu2.IsDraw = FALSE;

	//操作説明
	strcpy_s(Setsumei.image.path, IMAGE_SETSUMEI);
	Setsumei.image.handle = LoadGraph(Setsumei.image.path);	//読み込み
	if (Setsumei.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_SETSUMEI, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(Setsumei.image.handle, &Setsumei.image.width, &Setsumei.image.height);
	Setsumei.image.x = GAME_WIDTH / 2 - Setsumei.image.width / 2;
	Setsumei.image.y = GAME_HEIGHT / 2 - Setsumei.image.height / 2;
	Setsumei.IsDraw = FALSE;

	//黒画面
	strcpy_s(Loading.image.path, IMAGE_LOAD_BLACK);
	Loading.image.handle = LoadGraph(Loading.image.path);	//読み込み
	if (Loading.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_LOAD_BLACK, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(Loading.image.handle, &Loading.image.width, &Loading.image.height);
	Loading.image.x = GAME_WIDTH / 2 - Loading.image.width / 2;
	Loading.image.y = GAME_HEIGHT / 2 - Loading.image.height / 2;
	Loading.Cnt = 0;
	Loading.IsDraw = FALSE;

	//エンドロゴ
	strcpy_s(EndROGO.image.path, IMAGE_END_COMP_ROGO);
	EndROGO.image.handle = LoadGraph(EndROGO.image.path);
	if (EndROGO.image.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_END_COMP_ROGO, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(EndROGO.image.handle, &EndROGO.image.width, &EndROGO.image.height);
	EndROGO.image.x = GAME_WIDTH / 2 - EndROGO.image.width / 2;
	EndROGO.image.y = GAME_HEIGHT / 2 - EndROGO.image.height / 2;
	EndROGO.IsDraw = FALSE;

	//背景画像
	strcpy_s(ImageBack[0].image.path, IMAGE_PLAY_BACK1);			//パスの設定
	strcpy_s(ImageBack[1].image.path, IMAGE_PLAY_BACK2);
	strcpy_s(ImageBack[2].image.path, IMAGE_PLAY_BACK1);
	strcpy_s(ImageBack[3].image.path, IMAGE_PLAY_BACK2);

	//画像を連続して読み込み
	for (int num = 0; num < IMAGE_NUM; num++)
	{
		ImageBack[num].image.handle = LoadGraph(ImageBack[num].image.path);
		if (ImageBack[num].image.handle == -1)
		{
			//エラーメッセージ表示
			MessageBox(GetMainWindowHandle(), IMAGE_PLAY_BACK1, IMAGE_LOAD_ERR_TITLE, MB_OK);
			return FALSE;
		}
		//画像の幅と高さを取得
		GetGraphSize(ImageBack[num].image.handle, &ImageBack[num].image.width, &ImageBack[num].image.height);
	}
	//背景画像�@の設定
	ImageBack[0].image.x = 0 - ImageBack[0].image.width * 0;				//xは原点から
	ImageBack[0].image.y = GAME_HEIGHT / 2 - ImageBack[0].image.height / 2;	//上下中央揃え
	ImageBack[0].IsDraw = FALSE;
	//背景画像�Aの設定
	ImageBack[1].image.x = 0 - ImageBack[0].image.width * 1;				//xは原点から
	ImageBack[1].image.y = GAME_HEIGHT / 2 - ImageBack[1].image.height / 2;	//上下中央揃え
	ImageBack[1].IsDraw = FALSE;
	//背景画像�Bの設定
	ImageBack[2].image.x = 0 - ImageBack[0].image.width * 2;				//xは原点から
	ImageBack[2].image.y = GAME_HEIGHT / 2 - ImageBack[2].image.height / 2;	//上下中央揃え
	ImageBack[2].IsDraw = FALSE;
	//背景画像�Cの設定
	ImageBack[3].image.x = 0 - ImageBack[0].image.width * 3;				//xは原点から
	ImageBack[3].image.y = GAME_HEIGHT / 2 - ImageBack[3].image.height / 2;	//上下中央揃え
	ImageBack[3].IsDraw = FALSE;

	//背景画像
	strcpy_s(ImageFront[0].image.path, IMAGE_PLAY_FRONT1);			//パスの設定
	strcpy_s(ImageFront[1].image.path, IMAGE_PLAY_FRONT2);
	strcpy_s(ImageFront[2].image.path, IMAGE_PLAY_FRONT1);
	strcpy_s(ImageFront[3].image.path, IMAGE_PLAY_FRONT2);

	//画像を連続して読み込み
	for (int num = 0; num < IMAGE_NUM; num++)
	{
		ImageFront[num].image.handle = LoadGraph(ImageFront[num].image.path);
		if (ImageFront[num].image.handle == -1)
		{
			//エラーメッセージ表示
			MessageBox(GetMainWindowHandle(), IMAGE_PLAY_FRONT1, IMAGE_LOAD_ERR_TITLE, MB_OK);
			return FALSE;
		}
		//画像の幅と高さを取得
		GetGraphSize(ImageFront[num].image.handle, &ImageFront[num].image.width, &ImageFront[num].image.height);
	}
	//背景画像�@の設定
	ImageFront[0].image.x = 0 + ImageFront[0].image.width * 0;				//xは原点から
	ImageFront[0].image.y = GAME_HEIGHT / 2 - ImageFront[0].image.height / 2;	//上下中央揃え
	ImageFront[0].IsDraw = FALSE;
	//背景画像�Aの設定
	ImageFront[1].image.x = 0 + ImageFront[0].image.width * 1;				//xは原点から
	ImageFront[1].image.y = GAME_HEIGHT / 2 - ImageFront[1].image.height / 2;	//上下中央揃え
	ImageFront[1].IsDraw = FALSE;
	//背景画像�Bの設定
	ImageFront[2].image.x = 0 + ImageFront[0].image.width * 2;				//xは原点から
	ImageFront[2].image.y = GAME_HEIGHT / 2 - ImageFront[2].image.height / 2;	//上下中央揃え
	ImageFront[2].IsDraw = FALSE;
	//背景画像�Cの設定
	ImageFront[3].image.x = 0 + ImageFront[0].image.width * 3;				//xは原点から
	ImageFront[3].image.y = GAME_HEIGHT / 2 - ImageFront[3].image.height / 2;	//上下中央揃え
	ImageFront[3].IsDraw = FALSE;

	
	//キャラの画像
	//プレイヤー
	int PRes = LoadDivGraph(
		IMAGE_PLAYER_PATH,									//プレイヤーのパス
		PLAYER_DIV_NUM, PLAYER_DIV_TATE, PLAYER_DIV_YOKO,	//分割する数
		PLAYER_DIV_WIDTH, PLAYER_DIV_HEIGHT,				//分割する
		&chara.player[0].handle[0]);
	if (PRes == -1)
	{
		//エラー
		MessageBox(GetMainWindowHandle(), IMAGE_PLAYER_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	//幅と高さを取得
	GetGraphSize(chara.player[0].handle[0], &chara.player[0].width, &chara.player[0].height);
	//画像の情報を生成
	for (int cnt = 0; cnt < PLAYER_DIV_NUM; cnt++)
	{
		//パスをコピー
		strcpyDx(chara.player[cnt].path, TEXT(IMAGE_PLAYER_PATH));

		for (int i_num = 0; i_num < PLAYER_DIV_NUM; i_num++)
		{
			//ハンドルをコピー
			chara.player[cnt].handle[i_num] = chara.player[0].handle[i_num];
		}

		chara.player[cnt].width = chara.player[0].width;
		chara.player[cnt].height = chara.player[0].height;

		chara.player[cnt].x = GAME_WIDTH / 2 - chara.player[cnt].width / 2;		//左右中央揃え
		chara.player[cnt].y = GAME_HEIGHT / 2 - chara.player[cnt].height / 2;		//上下中央揃
		chara.CenterX = chara.player[cnt].x + chara.player[cnt].width / 2;	//画像の横の中心を探す
		chara.CenterY = chara.player[cnt].y + chara.player[cnt].height / 2;	//画像の縦の中心を探す
		chara.IsDraw = TRUE;
		chara.player[cnt].nowImageKind = 0;		//現在の画像の種類
		chara.player[cnt].speed = CHARA_SPEED_LOW;	//スピードを設定
		chara.player[cnt].changeImageCnt = 0;
		chara.player[cnt].changeImageCntMAX = IMAGE_PLAYER_CNT_MAX;
	}
	//少年
	strcpy_s(boy.image.path, IMAGE_BOY_PATH);		//パスの設定
	boy.image.handle = LoadGraph(boy.image.path);	//読み込み
	if (boy.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_BOY_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(boy.image.handle, &boy.image.width, &boy.image.height);	//画像の幅と高さを取得
	boy.image.x = GAME_WIDTH - 115;
	boy.image.y = CHARA_POSITION_Y;
	boy.CenterX = boy.image.x + boy.image.width / 2;		//画像の横の中心を探す
	boy.CenterY = boy.image.y + boy.image.height / 2;		//画像の縦の中心を探す
	boy.IsDraw = FALSE;
	//女性
	strcpy_s(Lemon.image.path, IMAGE_LEMON_PATH);		//パスの設定
	Lemon.image.handle = LoadGraph(Lemon.image.path);	//読み込み
	if (Lemon.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_LEMON_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(Lemon.image.handle, &Lemon.image.width, &Lemon.image.height);	//画像の幅と高さを取得
	Lemon.image.x = CHARA_POSITION_Y;
	Lemon.image.y = boy.image.y;
	Lemon.CenterX = Lemon.image.x + Lemon.image.width / 2;		//画像の横の中心を探す
	Lemon.CenterY = Lemon.image.y + Lemon.image.height / 2;		//画像の縦の中心を探す
	Lemon.IsDraw = FALSE;
	//男性
	strcpy_s(Sinner.image.path, IMAGE_SINNER_PATH);		//パスの設定
	Sinner.image.handle = LoadGraph(Sinner.image.path);	//読み込み
	if (Sinner.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_SINNER_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(Sinner.image.handle, &Sinner.image.width, &Sinner.image.height);	//画像の幅と高さを取得
	Sinner.image.x = CHARA_POSITION_Y;
	Sinner.image.y = boy.image.y;
	Sinner.CenterX = Sinner.image.x + Sinner.image.width / 2;		//画像の横の中心を探す
	Sinner.CenterY = Sinner.image.y + Sinner.image.height / 2;		//画像の縦の中心を探す
	Sinner.IsDraw = FALSE;
	//友人
	strcpy_s(Friend.image.path, IMAGE_FRIEND_PATH);		//パスの設定
	Friend.image.handle = LoadGraph(Friend.image.path);	//読み込み
	if (Friend.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_FRIEND_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(Friend.image.handle, &Friend.image.width, &Friend.image.height);	//画像の幅と高さを取得
	Friend.image.x = CHARA_POSITION_Y;
	Friend.image.y = boy.image.y;
	Friend.CenterX = Friend.image.x + Friend.image.width / 2;		//画像の横の中心を探す
	Friend.CenterY = Friend.image.y + Friend.image.height / 2;		//画像の縦の中心を探す
	Friend.IsDraw = FALSE;

	//表情差分
	//少年
	int bRes = LoadDivGraph(
		BOYFACE_PATH,									//プレイヤーのパス
		BOYFACE_DIV_NUM, BOYFACE_DIV_TATE, BOYFACE_DIV_YOKO,	//分割する数
		BOYFACE_DIV_WIDTH, BOYFACE_DIV_HEIGHT,				//分割する
		&boyFace.face[0].handle[0]);
	if (bRes == -1)
	{
		//エラー
		MessageBox(GetMainWindowHandle(), BOYFACE_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	//幅と高さを取得
	GetGraphSize(boyFace.face[0].handle[0], &boyFace.face[0].width, &boyFace.face[0].height);
	//画像の情報を生成
	for (int cnt = 0; cnt < BOYFACE_DIV_NUM; cnt++)
	{
		//パスをコピー
		strcpyDx(boyFace.face[cnt].path, TEXT(BOYFACE_PATH));

		for (int i_num = 0; i_num < BOYFACE_DIV_NUM; i_num++)
		{
			//ハンドルをコピー
			boyFace.face[cnt].handle[i_num] = boyFace.face[0].handle[i_num];
		}

		boyFace.face[cnt].width = boyFace.face[0].width;
		boyFace.face[cnt].height = boyFace.face[0].height;

		boyFace.face[cnt].x = 40;
		boyFace.face[cnt].y = 20;
		boyFace.CenterX = boyFace.face[cnt].x + boyFace.face[cnt].width / 2;	//画像の横の中心を探す
		boyFace.CenterY = boyFace.face[cnt].y + boyFace.face[cnt].height / 2;	//画像の縦の中心を探す
		boyFace.IsDraw = FALSE;
		boyFace.face[cnt].nowImageKind = 0;		//現在の画像の種類
	}
	//
	int sRes = LoadDivGraph(
		SINFACE_PATH,									//プレイヤーのパス
		BOYFACE_DIV_NUM, BOYFACE_DIV_TATE, BOYFACE_DIV_YOKO,	//分割する数
		BOYFACE_DIV_WIDTH, BOYFACE_DIV_HEIGHT,				//分割する
		&sinFace.face[0].handle[0]);
	if (sRes == -1)
	{
		//エラー
		MessageBox(GetMainWindowHandle(), SINFACE_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	//幅と高さを取得
	GetGraphSize(sinFace.face[0].handle[0], &sinFace.face[0].width, &sinFace.face[0].height);
	//画像の情報を生成
	for (int cnt = 0; cnt < BOYFACE_DIV_NUM; cnt++)
	{
		//パスをコピー
		strcpyDx(sinFace.face[cnt].path, TEXT(SINFACE_PATH));

		for (int i_num = 0; i_num < BOYFACE_DIV_NUM; i_num++)
		{
			//ハンドルをコピー
			sinFace.face[cnt].handle[i_num] = sinFace.face[0].handle[i_num];
		}

		sinFace.face[cnt].width = sinFace.face[0].width;
		sinFace.face[cnt].height = sinFace.face[0].height;

		sinFace.face[cnt].x = 40;
		sinFace.face[cnt].y = 20;
		sinFace.CenterX = sinFace.face[cnt].x + sinFace.face[cnt].width / 2;	//画像の横の中心を探す
		sinFace.CenterY = sinFace.face[cnt].y + sinFace.face[cnt].height / 2;	//画像の縦の中心を探す
		sinFace.IsDraw = FALSE;
		sinFace.face[cnt].nowImageKind = 0;		//現在の画像の種類
	}


	//テキストボックス
	strcpy_s(TextBox.image.path, IMAGE_TEXTBOX);
	TextBox.image.handle = LoadGraph(TextBox.image.path);	//読み込み
	if (TextBox.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_TEXTBOX, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(TextBox.image.handle, &TextBox.image.width, &TextBox.image.height);
	TextBox.image.x = GAME_WIDTH / 2 - TextBox.image.width / 2;
	TextBox.image.y = GAME_HEIGHT / 2 - TextBox.image.height / 2;

	//テキストボックス
	strcpy_s(ItemText.image.path, IMAGE_ITEMTEXT);
	ItemText.image.handle = LoadGraph(ItemText.image.path);	//読み込み
	if (ItemText.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_ITEMTEXT, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ItemText.image.handle, &ItemText.image.width, &ItemText.image.height);
	ItemText.image.x = GAME_WIDTH / 2 - ItemText.image.width / 2;
	ItemText.image.y = GAME_HEIGHT / 2 - ItemText.image.height / 2;
	
	//
	strcpy_s(Enter.image.path, IMAGE_RETURN);
	Enter.image.handle = LoadGraph(Enter.image.path);	//読み込み
	if (Enter.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_RETURN, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(Enter.image.handle, &Enter.image.width, &Enter.image.height);
	Enter.image.x = GAME_WIDTH / 2 - Enter.image.width / 2;
	Enter.image.y = GAME_HEIGHT / 2 - Enter.image.height / 2;
	
	//
	strcpy_s(Back.image.path, IMAGE_BACKSPACE);
	Back.image.handle = LoadGraph(Back.image.path);	//読み込み
	if (Back.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_BACKSPACE, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(Back.image.handle, &Back.image.width, &Back.image.height);
	Back.image.x = GAME_WIDTH / 2 - Back.image.width / 2;
	Back.image.y = GAME_HEIGHT / 2 - Back.image.height / 2;


	//あいてむ
	//
	strcpy_s(Chiket.image.path, IMAGE_ITEM);
	Chiket.image.handle = LoadGraph(Chiket.image.path);	//読み込み
	if (Chiket.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_ITEM, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(Chiket.image.handle, &Chiket.image.width, &Chiket.image.height);
	Chiket.image.x = GAME_WIDTH / 2 - Chiket.image.width / 2;
	Chiket.image.y = GAME_HEIGHT / 2 - Chiket.image.height / 2;
	Chiket.IsDraw = FALSE;
	//
	strcpy_s(Shinbun.image.path, IMAGE_ITEM);
	Shinbun.image.handle = LoadGraph(Shinbun.image.path);	//読み込み
	if (Shinbun.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_ITEM, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(Shinbun.image.handle, &Shinbun.image.width, &Shinbun.image.height);
	Shinbun.image.x = GAME_WIDTH - (150 + mapChip.width * 2);
	Shinbun.image.y = GAME_HEIGHT - (190 + mapChip.height * 2);
	Shinbun.IsDraw = FALSE;
	//
	strcpy_s(MemoLem.image.path, IMAGE_ITEM);
	MemoLem.image.handle = LoadGraph(MemoLem.image.path);	//読み込み
	if (MemoLem.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_ITEM, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(MemoLem.image.handle, &MemoLem.image.width, &MemoLem.image.height);
	MemoLem.image.x = 90 + mapChip.width * 2;
	MemoLem.image.y = 180 + mapChip.height * 2;
	MemoLem.IsDraw = FALSE;


	//マップ
	int mapRes = LoadDivGraph(
		GAME_MAP_PATH,
		MAP_DIV_NUM, MAP_DIV_TATE, MAP_DIV_YOKO,
		MAP_DIV_WIDTH, MAP_DIV_HEIGHT,
		&mapChip.handle[0]);

	if (mapRes == -1)
	{
		MessageBox(GetMainWindowHandle(), GAME_MAP_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	GetGraphSize(mapChip.handle[0], &mapChip.width, &mapChip.height);

	for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
		{
			mapDataInit[tate][yoko] = mapData[tate][yoko];

			map[tate][yoko].kind = mapData[tate][yoko];
			map[tate][yoko].num = 1;

			map[tate][yoko].width = mapChip.width;
			map[tate][yoko].height = mapChip.height;

			map[tate][yoko].x = yoko * map[tate][yoko].width;
			map[tate][yoko].y = tate * map[tate][yoko].height;
		}
	}

	for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
		{
			//マップの当たり判定を設定
			mapColl[tate][yoko].left = (yoko + 0) * mapChip.width + 1;
			mapColl[tate][yoko].top = (tate + 0) * mapChip.height + 1;
			mapColl[tate][yoko].right = (yoko + 1) * mapChip.width - 1;
			mapColl[tate][yoko].bottom = (tate + 1) * mapChip.height - 1;
		}
	}

	//エンド背景
	strcpy_s(EndBack.path, IMAGE_END_BACK);
	EndBack.handle = LoadGraph(EndBack.path);	//読み込み
	if (EndBack.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_END_BACK, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(EndBack.handle, &EndBack.width, &EndBack.height);
	EndBack.x = GAME_WIDTH / 2 - EndBack.width / 2;
	EndBack.y = GAME_HEIGHT / 2 - EndBack.height / 2;

	return TRUE;
}

VOID MY_DELETE_IMAGE(VOID)
{
	for (int num = 0; num < IMAGE_NUM; num++)
	{
		DeleteGraph(ImageBack[num].image.handle);
	}

	for (int num = 0; num < IMAGE_NUM; num++)
	{
		DeleteGraph(ImageFront[num].image.handle);
	}

	for (int i_num = 0; i_num < PLAYER_DIV_NUM; i_num++) { DeleteGraph(chara.player[0].handle[i_num]); }

	for (int i_num = 0; i_num < BOYFACE_DIV_NUM; i_num++) { DeleteGraph(boyFace.face[0].handle[i_num]); }
	for (int i_num = 0; i_num < BOYFACE_DIV_NUM; i_num++) { DeleteGraph(sinFace.face[0].handle[i_num]); }

	for (int i_num = 0; i_num < MAP_DIV_NUM; i_num++) { DeleteGraph(mapChip.handle[i_num]); }

	DeleteGraph(boy.image.handle);
	DeleteGraph(TextBox.image.handle);
	DeleteGraph(Enter.image.handle);
	DeleteGraph(Back.image.handle);
	DeleteGraph(Chiket.image.handle);
	DeleteGraph(MemoLem.image.handle);
	DeleteGraph(Title2.image.handle);
	DeleteGraph(Title.image.handle);
	DeleteGraph(TitleROGO.image.handle);
	DeleteGraph(menu1.image.handle);
	DeleteGraph(menu2.image.handle);
	DeleteGraph(Setsumei.image.handle);
	DeleteGraph(Loading.image.handle);
	DeleteGraph(EndROGO.image.handle);
	DeleteGraph(StartBack.handle);
	DeleteGraph(EndBack.handle);

	return;
}

BOOL MY_LOAD_MUSIC(VOID)
{
	//BGM
	strcpy_s(StartBGM.path, MUSIC_START_PATH);
	StartBGM.handle = LoadSoundMem(StartBGM.path);
	if (StartBGM.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_START_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	strcpy_s(PlayBGM.path, MUSIC_PLAY_PATH);
	PlayBGM.handle = LoadSoundMem(PlayBGM.path);
	if (PlayBGM.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_PLAY_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	strcpy_s(pBackBGM.path, MUSIC_PLAYBACK);
	pBackBGM.handle = LoadSoundMem(pBackBGM.path);
	if (pBackBGM.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_PLAYBACK, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	strcpy_s(EndBGM.path, MUSIC_END_PATH);
	EndBGM.handle = LoadSoundMem(EndBGM.path);
	if (EndBGM.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_END_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	//SE
	strcpy_s(cursorSE.path, SE_CURSOR);
	cursorSE.handle = LoadSoundMem(cursorSE.path, 1);
	if (cursorSE.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), SE_CURSOR, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	ChangeVolumeSoundMem(255 * 80 / 100, cursorSE.handle);
	strcpy_s(ketteiSE.path, SE_KETTEI);
	ketteiSE.handle = LoadSoundMem(ketteiSE.path);
	if (ketteiSE.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), SE_KETTEI, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	ChangeVolumeSoundMem(255 * 80 / 100, ketteiSE.handle);

	strcpy_s(paperSE.path, SE_PAPER);
	paperSE.handle = LoadSoundMem(paperSE.path);
	if (paperSE.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), SE_PAPER, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	ChangeVolumeSoundMem(255 * 80 / 100, paperSE.handle);

	strcpy_s(walkSE.path, SE_WALK);
	walkSE.handle = LoadSoundMem(walkSE.path);
	if (walkSE.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), SE_WALK, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	ChangeVolumeSoundMem(255 * 30 / 100, walkSE.handle);

	strcpy_s(talkSE.path, SE_TALK);
	talkSE.handle = LoadSoundMem(talkSE.path);
	if (talkSE.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), SE_TALK, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	strcpy_s(doorSE.path, SE_DOOR);
	doorSE.handle = LoadSoundMem(doorSE.path);
	if (doorSE.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), SE_DOOR, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	ChangeVolumeSoundMem(255 * 80 / 100, doorSE.handle);

	strcpy_s(GachaSE.path, SE_GACHA);
	GachaSE.handle = LoadSoundMem(GachaSE.path);
	if (GachaSE.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), SE_GACHA, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	ChangeVolumeSoundMem(255 * 80 / 100, GachaSE.handle);

	strcpy_s(ItemSE.path, SE_ITEM);
	ItemSE.handle = LoadSoundMem(ItemSE.path);
	if (ItemSE.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), SE_ITEM, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	ChangeVolumeSoundMem(255 * 80 / 100, ItemSE.handle);

	return TRUE;
}

VOID MY_DELETE_MUSIC(VOID)
{
	DeleteSoundMem(StartBGM.handle);
	DeleteSoundMem(PlayBGM.handle);
	DeleteSoundMem(pBackBGM.handle);
	DeleteSoundMem(EndBGM.handle);
	DeleteSoundMem(cursorSE.handle);
	DeleteSoundMem(ketteiSE.handle);
	DeleteSoundMem(paperSE.handle);
	DeleteSoundMem(walkSE.handle);
	DeleteSoundMem(talkSE.handle);
	DeleteSoundMem(doorSE.handle);
	DeleteSoundMem(GachaSE.handle);
	DeleteSoundMem(ItemSE.handle);
}

BOOL MY_CHECK_MAP1_PLAYER_COLL(RECT player)
{
	//マップの当たり判定を設定する
	for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
		{
			//プレイヤーとマップが当たっているとき
			if (MY_CHECK_RECT_COLL(player, mapColl[tate][yoko]) == TRUE)
			{
				//壁のときは、プレイヤーとマップが当たっている
				if (mapData[tate][yoko] == k || mapData[tate][yoko] == a ||
					mapData[tate][yoko] == m || mapData[tate][yoko] == b ||
					mapData[tate][yoko] == o || mapData[tate][yoko] == x ||
					mapData[tate][yoko] == e || mapData[tate][yoko] == d ||
					mapData[tate][yoko] == z || mapData[tate][yoko] == y ||
					mapData[tate][yoko] == g || mapData[tate][yoko] == r) { return TRUE; }
			}
		}
	}

	return FALSE;
}

BOOL MY_CHECK_CHARA_PLAYER_COLL(RECT player)
{
	if (MY_CHECK_RECT_COLL(player, boy.coll) == TRUE || 
		MY_CHECK_RECT_COLL(player, Lemon.coll) == TRUE ||
		MY_CHECK_RECT_COLL(player, Sinner.coll) == TRUE ||
		MY_CHECK_RECT_COLL(player, Friend.coll) == TRUE)
	{
		return TRUE;
	}

	return FALSE;
}

//領域の当たり判定をする関数
BOOL MY_CHECK_RECT_COLL(RECT a, RECT b)
{
	if (a.left < b.right &&
		a.top < b.bottom &&
		a.right > b.left &&
		a.bottom > b.top
		)
	{
		return TRUE;	//当たっている
	}

	return FALSE;		//当たっていない
}

VOID LOADING(VOID)
{
	if (Loading.Cnt < IMAGE_LOADING_CNT)
	{
		Loading.Cnt++;
		DrawGraph(Loading.image.x, Loading.image.y, Loading.image.handle, TRUE);
	}
	
	return;
}

//テキストボックス表示関数
INT TEXTBOX(int g, int Max)
{
	int BoxPtY = 0;
	for (int cnt = 0; cnt < PLAYER_DIV_NUM; cnt++)
	{
		if ((chara.player[cnt].y - chara.image.y / 2) < GAME_HEIGHT / 2)
		{
			BoxPtY = GAME_HEIGHT - TextBox.image.height;
		}
	}
	if (ItemFlg == TRUE)
	{
		DrawGraph(0, BoxPtY, ItemText.image.handle, TRUE);
	}
	else
	{
		DrawGraph(0, BoxPtY, TextBox.image.handle, TRUE);
	}

	//顔画像もここで表示
	//種類は文章ごとに変えられる
	if (boyFlg == TRUE)
	{
		for (int cnt = 0; cnt < BOYFACE_DIV_NUM; cnt++)
		{
			DrawGraph(
				boyFace.face[cnt].x,
				boyFace.face[cnt].y + BoxPtY,
				boyFace.face[cnt].handle[boyFace.face[cnt].nowImageKind],
				TRUE);
		}
	}
	if (sinFlg == TRUE)
	{
		for (int cnt = 0; cnt < BOYFACE_DIV_NUM; cnt++)
		{
			DrawGraph(
				sinFace.face[cnt].x,
				sinFace.face[cnt].y + BoxPtY,
				sinFace.face[cnt].handle[sinFace.face[cnt].nowImageKind],
				TRUE);
		}
	}

	if (g < Max - 1)
	{
		DrawGraph(641, BoxPtY + 154, Enter.image.handle, TRUE);
	}
	if (g >= Max - 1)
	{
		DrawGraph(641, BoxPtY + 154, Back.image.handle, TRUE);
	}

	return BoxPtY;
}

//アイテムテキスト
VOID SISTEM_TEXT(int g, int Max)
{
	int TextPtY = TEXT_POSITION_Y;
	if (TEXTBOX(g, Max) != 0)
	{
		TextPtY = GAME_HEIGHT - ItemText.image.height + TEXT_POSITION_Y;
	}

	if (ItemOK == FALSE)
	{
		DrawStringToHandle(TEXT_POSITION_X - FONT_SIZE * 2, TextPtY, "なにかが落ちている。", White, Font.handle);
	}
	if (ItemOK == TRUE)
	{
		if (ItemNum == 0)
		{
			DrawStringToHandle(TEXT_POSITION_X - FONT_SIZE * 2, TextPtY, "【赤色の切符】", Red, Font.handle);
			DrawStringToHandle(TEXT_POSITION_X - FONT_SIZE * 2 + (FONT_SIZE * 7 + 5), TextPtY, "を見つけた。", White, Font.handle);
			DrawStringToHandle(TEXT_POSITION_X - FONT_SIZE * 2, TextPtY + FONT_SIZE + 5, "なぜか自分の名前が書かれている。", White, Font.handle);
		}
		if (ItemNum == 1)
		{
			DrawStringToHandle(TEXT_POSITION_X - FONT_SIZE * 2, TextPtY, "【新聞】", Red, Font.handle);
			DrawStringToHandle(TEXT_POSITION_X - FONT_SIZE * 2 + (FONT_SIZE * 4 + 5), TextPtY, "を見つけた。", White, Font.handle);
		}
		if (ItemNum == 2)
		{
			DrawStringToHandle(TEXT_POSITION_X - FONT_SIZE * 2, TextPtY, "【手帳】", Red, Font.handle);
			DrawStringToHandle(TEXT_POSITION_X - FONT_SIZE * 2 + (FONT_SIZE * 4 + 5), TextPtY, "を見つけた。", White, Font.handle);
		}
	}
	

	return;
}

VOID PLAYER_TEXT(int g, int Max)
{
	int TextPtY = TEXT_POSITION_Y;
	int NamePtY = NAME_POSITION_Y;

	if (TEXTBOX(g, Max) != 0)
	{
		TextPtY = GAME_HEIGHT - TextBox.image.height + TEXT_POSITION_Y;
		NamePtY = GAME_HEIGHT - TextBox.image.height + NAME_POSITION_Y;
	}

	DrawStringToHandle(TEXT_POSITION_X, NamePtY, "【ミツル】", Yellow, Font.handle);

	if (Player1flg == TRUE)
	{
		if (g == 0)
		{
			DrawStringToHandle(TEXT_POSITION_X, TextPtY, _T("あれ……？\nここ……どこだろう……？\n"), White, Font.handle);
		}
		if (g == 1)
		{
			DrawStringToHandle(TEXT_POSITION_X, TextPtY, "！！", White, Font.handle);
			DrawStringToHandle(TEXT_POSITION_X, TextPtY + FONT_SIZE + 5, "ナギサ", Yellow, Font.handle);
			DrawStringToHandle(TEXT_POSITION_X + FONT_SIZE * 3 + 5, TextPtY + FONT_SIZE + 5, "がいない！", White, Font.handle);
		}
		if (g >= Max - 1)
		{
			DrawStringToHandle(TEXT_POSITION_X, TextPtY, _T("さっきまで一緒にいたはずなのに……\nどこに行ったんだ……？"), White, Font.handle);
		}
	}

	return;
}

VOID BOY_TEXT(int g, int Max)
{
	int TextPtY = TEXT_POSITION_Y;
	int NamePtY = NAME_POSITION_Y;

	if (TEXTBOX(g, Max) != 0)
	{
		TextPtY = GAME_HEIGHT - TextBox.image.height + TEXT_POSITION_Y;
		NamePtY = GAME_HEIGHT - TextBox.image.height + NAME_POSITION_Y;
	}

	if (boyName == FALSE)
	{
		DrawStringToHandle(TEXT_POSITION_X, NamePtY, "【？？？】", Yellow, Font.handle);
	}

	if (boyName == TRUE)
	{
		DrawStringToHandle(TEXT_POSITION_X, NamePtY, "【カムパネルラ】", Yellow, Font.handle);
	}

	for (int cnt = 0; cnt < BOYFACE_DIV_NUM; cnt++)
	{
		//最初の車両
		if (boy1flg == TRUE)
		{
			if (g == 0)
			{
				DrawStringToHandle(TEXT_POSITION_X, TextPtY, "目が覚めましたか。", White, Font.handle);
				boyFace.face[cnt].nowImageKind = 0;
			}
			if (g == 1)
			{
				DrawStringToHandle(TEXT_POSITION_X, TextPtY, _T("こんにちは。\nこの度は銀河鉄道へのご乗車\nありがとうございます。\n"), White, Font.handle);
			}
			if (g >= Max - 1)
			{
				DrawStringToHandle(TEXT_POSITION_X, TextPtY, "僕は", White, Font.handle);
				DrawStringToHandle(TEXT_POSITION_X + FONT_SIZE * 2 + 5, TextPtY, "カムパネルラ", Yellow, Font.handle);
				DrawStringToHandle(TEXT_POSITION_X + FONT_SIZE * 9 + 5, TextPtY, "。", White, Font.handle);
				DrawStringToHandle(TEXT_POSITION_X, TextPtY + FONT_SIZE + 5, "この銀河鉄道の案内人をしています。\nどうぞよろしくおねがいします。\n", White, Font.handle);
			}
		}
		if (boy2flg == TRUE)
		{
			if (g == 0)
			{
				boyFace.face[cnt].nowImageKind = 1;
				DrawStringToHandle(TEXT_POSITION_X, TextPtY, _T("ん？\nお友達を探しているんですか？\n"), White, Font.handle);
			}
			if (g == 1)
			{
				DrawStringToHandle(TEXT_POSITION_X, TextPtY, _T("ふむふむ、\n気が付いたらいなくなっていたと……\n"), White, Font.handle);
			}
			if (g == 2)
			{
				boyFace.face[cnt].nowImageKind = 2;
				DrawStringToHandle(TEXT_POSITION_X, TextPtY, "（ここに来る前のこと、覚えてないのか……）", White, Font.handle);
			}
			if (g == 3)
			{
				boyFace.face[cnt].nowImageKind = 0;
				DrawStringToHandle(TEXT_POSITION_X, TextPtY, _T("なるほど、分かりました。\nたぶんお友達は\nこの先の車両にいると思います。\n"), White, Font.handle);
			}
			if (g == 4)
			{
				DrawStringToHandle(TEXT_POSITION_X, TextPtY, _T("案内がてら、僕も一緒に探しますよ。\nじゃあさっそく探しに……\n"), White, Font.handle);
			}
			if (g == 5)
			{
				boyFace.face[cnt].nowImageKind = 3;
				DrawStringToHandle(TEXT_POSITION_X, TextPtY, "あっ、そうだ！忘れるところでした。", White, Font.handle);
				DrawStringToHandle(TEXT_POSITION_X, TextPtY + FONT_SIZE + 5, "切符", Red, Font.handle);
				DrawStringToHandle(TEXT_POSITION_X + FONT_SIZE * 2 + 5, TextPtY + FONT_SIZE + 5, "はお持ちですか？", White, Font.handle);
			}
			if (g == 6)
			{
				DrawStringToHandle(TEXT_POSITION_X, TextPtY, _T("え？もらってない？\nうーんそんなことはないと\n思うんですけど……\n"), White, Font.handle);
			}
			if (g >= Max - 1)
			{
				boyFace.face[cnt].nowImageKind = 0;
				DrawStringToHandle(TEXT_POSITION_X, TextPtY, _T("もしかしたら次の車両に\n落ちてるかも……\n探しに行きましょうか。\n"), White, Font.handle);
			}
		}
		if (boy3flg == TRUE)
		{
			if (g >= Max - 1)
			{
				boyFace.face[cnt].nowImageKind = 0;
				DrawStringToHandle(TEXT_POSITION_X, TextPtY, _T("次の車両に行きましょう。\n扉はもう開いてますよ。\n"), White, Font.handle);	
			}
		}
		//２車両目
		if (boy4flg == TRUE)
		{
			if (g == 0)
			{
				boyFace.face[cnt].nowImageKind = 4;
				DrawStringToHandle(TEXT_POSITION_X, TextPtY, "瞬間移動じゃないですよ〜。", White, Font.handle);
			}
			if (g == 1)
			{
				boyFace.face[cnt].nowImageKind = 0;
				DrawStringToHandle(TEXT_POSITION_X, TextPtY, _T("というわけで２車両目になります。\nこの車両のどこかに、お客様の切符が落ちてる\nはずです。\n"), White, Font.handle);
			}
			if (g >= Max - 1)
			{
				DrawStringToHandle(TEXT_POSITION_X, TextPtY, _T("見つけたら僕にみせてください。\n確認しますので。\n"), White, Font.handle);
			}
		}
		if (boy5flg == TRUE)
		{
			if (g >= Max - 1)
			{
				boyFace.face[cnt].nowImageKind = 4;
				DrawStringToHandle(TEXT_POSITION_X, TextPtY, "のんびり待ってますので〜。", White, Font.handle);
			}
		}
		if (boy6flg == TRUE)
		{
			if (g == 0)
			{
				boyFace.face[cnt].nowImageKind = 0;
				DrawStringToHandle(TEXT_POSITION_X, TextPtY, _T("あ、見つけられましたか？\nどれどれ……\n"), White, Font.handle);
			}
			if (g == 1)
			{
				boyFace.face[cnt].nowImageKind = 3;
				DrawStringToHandle(TEXT_POSITION_X, TextPtY, "！？", White, Font.handle);
			}
			if (g == 2)
			{
				DrawStringToHandle(TEXT_POSITION_X, TextPtY, _T("この切符は……\nあの時の……まさか……\n"), White, Font.handle);
			}
			if (g == 3)
			{
				boyFace.face[cnt].nowImageKind = 2;
				DrawStringToHandle(TEXT_POSITION_X, TextPtY, "…… …… ……", White, Font.handle);
			}
			if (g == 4)
			{
				boyFace.face[cnt].nowImageKind = 1;
				DrawStringToHandle(TEXT_POSITION_X, TextPtY, _T("あの……落ち着いて聞いてくださいね。\n実はこの銀河鉄道に来る人たちは……\n"), White, Font.handle);
			}
			if (g == 5)
			{
				DrawStringToHandle(TEXT_POSITION_X, TextPtY, "みんなもう死んでいるんです。", White, Font.handle);
			}
			if (g == 6)
			{
				boyFace.face[cnt].nowImageKind = 3;
				DrawStringToHandle(TEXT_POSITION_X, TextPtY, _T("でもあなたは違うんです。\n生きたままここに来てしまった。\n"), White, Font.handle);
			}
			if (g == 7)
			{
				DrawStringToHandle(TEXT_POSITION_X, TextPtY, _T("その切符が証拠です。\n普通はうすい緑色ですが、あなたのは\n赤いですよね。\n"), White, Font.handle);
			}
			if (g == 8)
			{
				DrawStringToHandle(TEXT_POSITION_X, TextPtY, _T("……一刻も早く銀河鉄道を降りてください。\nきっとまだ間に合うはずです。\n"), White, Font.handle);
			}
			if (g >= Max - 1)
			{
				boyFace.face[cnt].nowImageKind = 1;
				DrawStringToHandle(TEXT_POSITION_X, TextPtY, _T("降りる方法は他の乗客が知っています。\n次の車両に誰かいると思いますので、\n話を聞きに行きましょう。\n"), White, Font.handle);
			}
		}
		if (boy7flg == TRUE)
		{
			if (g >= Max - 1)
			{
				boyFace.face[cnt].nowImageKind = 0;
				DrawStringToHandle(TEXT_POSITION_X, TextPtY, _T("さっそく次の車両に向かいましょう。\n"), White, Font.handle);
			}
		}
		if (boy8flg == TRUE)
		{
			if (g == 0)
			{
				boyFace.face[cnt].nowImageKind = 0;
				DrawStringToHandle(TEXT_POSITION_X, TextPtY, _T("カオルさんは去年も一昨年も\n銀河鉄道に乗っていました。\n"), White, Font.handle);
			}
			if (g >= Max - 1)
			{
				boyFace.face[cnt].nowImageKind = 2;
				DrawStringToHandle(TEXT_POSITION_X, TextPtY, _T("……お盆のナスとキュウリみたいな\nご利用をされています……\n"), White, Font.handle);
			}
		}
		if (boy9flg == TRUE)
		{
			if (g == 0)
			{
				boyFace.face[cnt].nowImageKind = 2;
				DrawStringToHandle(TEXT_POSITION_X, TextPtY, _T("アキさんは、なんというか……\n少し僕に似ている気がします。\n"), White, Font.handle);
			}
			if (g >= Max - 1)
			{
				boyFace.face[cnt].nowImageKind = 0;
				DrawStringToHandle(TEXT_POSITION_X, TextPtY, "友達は大事にしてくださいね。", White, Font.handle);
			}
		}
		if (boy10flg == TRUE)
		{
			if (g == 0)
			{
				boyFace.face[cnt].nowImageKind = 2;
				DrawStringToHandle(TEXT_POSITION_X, TextPtY, "…… …… ……", White, Font.handle);
			}
			if (g >= Max - 1)
			{
				DrawStringToHandle(TEXT_POSITION_X, TextPtY, "僕、彼のことは苦手です。", White, Font.handle);
			}
		}
	}

	return;
}
//女性テキスト
VOID LEMON_TEXT(int g, int Max)
{
	int TextPtY = TEXT_POSITION_Y;
	int NamePtY = NAME_POSITION_Y;

	if (TEXTBOX(g, Max) != 0)
	{
		TextPtY = GAME_HEIGHT - TextBox.image.height + TEXT_POSITION_Y;
		NamePtY = GAME_HEIGHT - TextBox.image.height + NAME_POSITION_Y;
	}

	DrawStringToHandle(TEXT_POSITION_X, NamePtY, "【カオル】", Yellow, Font.handle);

	if (lem1flg == TRUE)
	{
		if (g == 0)
		{
			DrawStringToHandle(TEXT_POSITION_X, TextPtY, _T("あら、こんにちは。\n今日はずいぶんと若い子が多いわね。\n"), White, Font.handle);
		}
		if (g >= Max - 1)
		{
			DrawStringToHandle(TEXT_POSITION_X, TextPtY, "わたし、", White, Font.handle);
			DrawStringToHandle(TEXT_POSITION_X + FONT_SIZE * 4 + 5, TextPtY, "カオル", Yellow, Font.handle);
			DrawStringToHandle(TEXT_POSITION_X + FONT_SIZE * 7 + 5, TextPtY, "っていうの。", White, Font.handle);
			DrawStringToHandle(TEXT_POSITION_X, TextPtY + FONT_SIZE + 5, "よろしくね。", White, Font.handle);
		}
	}
	if (lem2flg == TRUE)
	{
		if (g == 0)
		{
			DrawStringToHandle(TEXT_POSITION_X, TextPtY, _T("……銀河鉄道から降りる方法を\n教えてほしい？"), White, Font.handle);
		}
		if (g == 1)
		{
			DrawStringToHandle(TEXT_POSITION_X, TextPtY, _T("そうね、じゃあ教える代わりに、\nわたしの悩みを聞いてくれないかしら。\n"), White, Font.handle);
		}
		if (g == 2)
		{
			DrawStringToHandle(TEXT_POSITION_X, TextPtY, _T("……わたしね、この銀河鉄道に乗るの\n初めてじゃないの。"), White, Font.handle);
		}
		if (g == 3)
		{
			DrawStringToHandle(TEXT_POSITION_X, TextPtY, _T("もうずいぶん前に死んで、ここに来た。\nでもどうしても還れなくて……\n彼のことが気がかりで……\n"), White, Font.handle);
		}
		if (g == 4)
		{
			DrawStringToHandle(TEXT_POSITION_X, TextPtY, _T("……でもそれももうやめようと思って。\n最後に彼の様子が知りたいの。\n"), White, Font.handle);
		}
		if (g >= Max - 1)
		{
			DrawStringToHandle(TEXT_POSITION_X, TextPtY, _T("なんでもいいの。\n何か手がかりを探してくれないかしら？\n"), White, Font.handle);
		}
	}
	if (lem3flg == TRUE)
	{
		if (g == 0)
		{
			DrawStringToHandle(TEXT_POSITION_X, TextPtY, "この車両のどこかに手がかりがあるはずよ。", White, Font.handle);
		}
		if (g >= Max - 1)
		{
			DrawStringToHandle(TEXT_POSITION_X, TextPtY, "お願いね。", White, Font.handle);
		}
	}
	if (lem4flg == TRUE)
	{
		if (g >= Max - 1)
		{
			DrawStringToHandle(TEXT_POSITION_X, TextPtY, "ありがとう。", White, Font.handle);
		}
	}

	return;
}
//男性テキスト
VOID SINNER_TEXT(int g, int Max)
{
	int TextPtY = TEXT_POSITION_Y;
	int NamePtY = NAME_POSITION_Y;

	if (TEXTBOX(g, Max) != 0)
	{
		TextPtY = GAME_HEIGHT - TextBox.image.height + TEXT_POSITION_Y;
		NamePtY = GAME_HEIGHT - TextBox.image.height + NAME_POSITION_Y;
	}

	DrawStringToHandle(TEXT_POSITION_X, NamePtY, "【アキ】", Yellow, Font.handle);

	for (int cnt = 0; cnt < BOYFACE_DIV_NUM; cnt++)
	{
		if (sin1flg == TRUE)
		{
			if (g == 0)
			{
				sinFace.face[cnt].nowImageKind = 0;
				DrawStringToHandle(TEXT_POSITION_X, TextPtY, _T("……さっき君と同じくらいの年の少年が\nここに来たんです。\n"), White, Font.handle);
			}
			if (g == 1)
			{
				sinFace.face[cnt].nowImageKind = 1;
				DrawStringToHandle(TEXT_POSITION_X, TextPtY, _T("あ……いきなりすみません。\nまだ頭がぼんやりしていて……\n"), White, Font.handle);
			}
			if (g == 2)
			{
				sinFace.face[cnt].nowImageKind = 0;
				DrawStringToHandle(TEXT_POSITION_X, TextPtY, "私は", White, Font.handle);
				DrawStringToHandle(TEXT_POSITION_X + FONT_SIZE * 2 + 5, TextPtY, "アキ", Yellow, Font.handle);
				DrawStringToHandle(TEXT_POSITION_X + FONT_SIZE * 4 + 5, TextPtY, "といいます。", White, Font.handle);
				DrawStringToHandle(TEXT_POSITION_X, TextPtY + FONT_SIZE + 5, "医者でした。", White, Font.handle);
			}
			if (g == 3)
			{
				DrawStringToHandle(TEXT_POSITION_X, TextPtY, _T("まあ今となってはどうでもいい\nことなんですが。\n"), White, Font.handle);
			}
			if (g == 4)
			{
				sinFace.face[cnt].nowImageKind = 2;
				DrawStringToHandle(TEXT_POSITION_X, TextPtY, _T("あはは……\n"), White, Font.handle);
			}
			if (g >= Max - 1)
			{
				sinFace.face[cnt].nowImageKind = 1;
				DrawStringToHandle(TEXT_POSITION_X, TextPtY, _T("……………………\nはあ…………\nすみません…………\n"), White, Font.handle);
			}
		}
		if (sin2flg == TRUE)
		{
			if (g >= Max - 1)
			{
				sinFace.face[cnt].nowImageKind = 2;
				DrawStringToHandle(TEXT_POSITION_X, TextPtY, "がんばってください。", White, Font.handle);
			}
		}
	}

	return;
}
//友人テキスト
VOID FRIEND_TEXT(int g, int Max)
{
	int TextPtY = TEXT_POSITION_Y;
	int NamePtY = NAME_POSITION_Y;

	if (TEXTBOX(g, Max) != 0)
	{
		TextPtY = GAME_HEIGHT - TextBox.image.height + TEXT_POSITION_Y;
		NamePtY = GAME_HEIGHT - TextBox.image.height + NAME_POSITION_Y;
	}

	DrawStringToHandle(TEXT_POSITION_X, NamePtY, "【ナギサ】", Yellow, Font.handle);

	if (fri1flg == TRUE)
	{
		if (g >= Max - 1)
		{
			DrawStringToHandle(TEXT_POSITION_X, TextPtY, _T("あーー！！\nやっと来た！！\n何してたんだよもーー！！\n"), White, Font.handle);
		}
	}
	if (fri2flg == TRUE)
	{
		if (g >= Max - 1)
		{
			DrawStringToHandle(TEXT_POSITION_X, TextPtY, "ずっと待ってたよ。", White, Font.handle);
		}
	}
	return;
}