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
	/// 当たり判定
	void Collision();


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

	static const int enemyCount = 20;
	static const int enemyCount2 = 10;
	static const int enemyCount3 = 3;


	Transform enemyTransform_[enemyCount] = {};
	Vector3 enemyMove_[enemyCount];



	Transform enemyTransformModel2_[enemyCount2] = {};
	Vector3 enemyMove2_[enemyCount2];

	Transform enemyTransformModel3_[enemyCount3] = {};
	Vector3 enemyMove3_[enemyCount3];


	Enemy* enemy_[enemyCount];
	Enemy* enemy2_[enemyCount2];
	Enemy* enemy3_[enemyCount3];

	
	Model* yuka_ = nullptr;
	Transform transformyuka_ = {};

	int32_t  enemyHP[enemyCount] ;
	int32_t enemyHP2[enemyCount2];
	int32_t enemyHP3[enemyCount3];

	int32_t killCount1_;
	int32_t killCount2_;
	int32_t killCount3_;
	int32_t allKillCount_;

	uint32_t HPCoolTimer_[enemyCount] = {};
	uint32_t HPCoolTimer2_[enemyCount2] = {};
	uint32_t HPCoolTimer3_[enemyCount3] = {};


	bool HPCoolFlag_[enemyCount]={ false };
	bool HPCoolFlag2_[enemyCount2] = { false };
	bool HPCoolFlag3_[enemyCount3] = { false };

#pragma region 自機の動き
	Player* player_;
	Transform playerTransform_;


};