#pragma once

#include <Input/Input.h>
#include <Audio/Audio.h>
#include "TextureManager/TextureManager.h"
#include "AllGameScene/GameManager/GameManager.h"
#include "AllGameScene/GameManager/IGameScene.h"
#include <Object/Enemy/enemy.h>


class  GameScene : public IGameScene {
public:
	//コンストラクタ
	GameScene();

	/// デストラクタ
	~GameScene();

	/// 初期化
	void Initialize(GameManager* gameManager)override;

#pragma region Updateの中
	//デバッグ
	void ImGuiDebug();

	//メインのゲーム
	void Play();

	//カウントダウン
	void CountDown();

#pragma endregion

	/// 更新
	void Update(GameManager* gameManager)override;

	/// 描画
	void Draw(GameManager* gameManager)override;



private:
	//Audio
	//BGM
	Audio* gameBGM_ = nullptr;
	uint32_t gameBGMHandle_ = 0u;
	int bgmTime_ = 0;

	Audio* countSE_ = nullptr;
	uint32_t countSEHandle_ = 0u;

	Audio* startSE_ = nullptr;
	uint32_t startSEHandle_ = 0u;



	//Input
	Input* input_ = nullptr;
	//TextureManager
	TextureManager* textureManager_ = nullptr;


	//フェード
	bool isFadeIn_ = true;
	int fadeInTime_ = 0;

	float transparency_ = 0.0f;


	//UI
	//ロード時間
	int waitingTime_ = 0;
	const int SECOND_ = 60;





#pragma region 敵の動き



	Transform transformSprite_ = {};
	Transform transformSprite2_ = {};

	SpritePosition spriteAllPosition2_ = {};

	float startTransparency = 1.0f;


	int32_t textureChangeTime_ = 0;

	const int enemyCount = 20;
	const int enemyCount2 = 10;
	const int enemyCount3 = 3;


	Transform transformModel_[20] = {};
	Vector3 move_[20];



	Transform transformModel2_[10] = {};
	Vector3 move2_[10];

	Transform transformModel3_[3] = {};
	Vector3 move3_[3];


	Enemy* enemy_[20];
	Enemy* enemy2_[10];
	Enemy* enemy3_[3];

#pragma endregion


#pragma region 床
	Model* yuka_ = nullptr;
	Transform transformyuka_ = {};

#pragma endregion


	//ゲーム開始
	bool isGamePlay_ = false;

#pragma region カウントダウン
	int countDown_ = SECOND_ * 4;
	//カウント
	static const int COUNT_NUMBER_ = 3;
	float COUNT_SIZE = 1.0f;
	Sprite* count_[COUNT_NUMBER_] = { nullptr };
	Transform countTransform_[COUNT_NUMBER_] = {};
	SpritePosition countAllPosition_ = {};

	Sprite* start_ = nullptr;
	Transform startTransform_ = {};
	SpritePosition startAllPosition_ = {};

	Sprite* end_ = nullptr;
	Transform endTransform_ = {};
	SpritePosition endAllPosition_ = {};

#pragma endregion

	//ゲームの時間
	int gameTime_ = SECOND_ * 60;

	//表示されている時間
	int displayTime_ = 0;
	//1の位
	int onesPlace_ = 0;
	//10の位
	int tensPlace_ = 0;
	
	uint32_t numberTextureHandle[10] = {};

	//時間

	static const int NUMBER_AMOUNT_ = 10;
	Sprite* timeTensPlane_[NUMBER_AMOUNT_] = {nullptr};
	Sprite* timeOnesPlane_[NUMBER_AMOUNT_] = { nullptr };

	Transform timeTensPlaneTransform_  = {};
	Transform timeOnesPlaneTransform_  = {};
	SpritePosition timeOnesPlaneAllPosition_ = {};
	SpritePosition timeTensPlaneAllPosition_ = {};



};