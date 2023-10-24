#pragma once

#include <Input/Input.h>
#include <Audio/Audio.h>
#include "TextureManager/TextureManager.h"
#include "AllGameScene/GameManager/GameManager.h"
#include "AllGameScene/GameManager/IGameScene.h"
#include <Object/Enemy/enemy.h>
#include <Object/Player/Player.h>


class  GameScene  : public IGameScene{
public:
	//コンストラクタ
	GameScene();

	/// デストラクタ
	~GameScene();

	/// 初期化
	void Initialize(GameManager* gameManager)override;

	void Play();

	/// 更新
	void Update(GameManager* gameManager)override;

	/// 描画
	void Draw(GameManager* gameManager)override;



private:
	//Audio
	Audio* gameBGM_ = nullptr;
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

	
	Model* yuka_ = nullptr;
	Transform transformyuka_ = {};

	int32_t enemyHP = 1;
	int32_t enemyHP2 = 2;
	int32_t enemyHP3 = 3;

#pragma region 自機の動き
	Player* player_;



};