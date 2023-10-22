#pragma once

#include <Input/Input.h>
#include <Audio/Audio.h>
#include "TextureManager/TextureManager.h"
#include "AllGameScene/GameManager/GameManager.h"
#include "AllGameScene/GameManager/IGameScene.h"


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



	//チュートリアル画面の画像
	Sprite* gameSprite_ = nullptr;
	Transform selectSpriteTransform_ = {};
	SpritePosition spriteAllPosition_ = {};
	float gameTextureTransparency_ = 0.0f;


	//フェード
	bool isFadeIn_ = true;
	int fadeInTime_ = 0;




	//UI
	//ロード時間
	int waitingTime_ = 0;
	const int SECOND_ = 60;





#pragma region 敵の動き



	Transform transformSprite_ = {};
	Transform transformSprite2_ = {};

	SpritePosition spriteAllPosition_ = {};
	SpritePosition spriteAllPosition2_ = {};

	float startTransparency = 1.0f;

	const int SECOND_ = 60;

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










};