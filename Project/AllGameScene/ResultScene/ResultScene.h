#pragma once

#include <Input/Input.h>
#include <Audio/Audio.h>
#include "TextureManager/TextureManager.h"
#include "AllGameScene/GameManager/GameManager.h"
#include "AllGameScene/GameManager/IGameScene.h"

class ResultScene : public IGameScene{
public:

	//コンストラクタ
	ResultScene();

	/// デストラクタ
	~ResultScene();

	/// 初期化
	void Initialize(GameManager* gameManager)override;

	void ImGuiDebug();

	/// 更新
	void Update(GameManager* gameManager)override;

	/// 描画
	void Draw(GameManager* gameManager)override;



private:
	//Audio
	Audio* bgm_ = nullptr;
	uint32_t bgmHandle_ = 0u;

	Audio* decideSE_ = nullptr;
	uint32_t decideSEHandle_ = 0u;
	int decideSETime_ = 0;

	//Input
	Input* input_ = nullptr;
	TextureManager* textureManager_ = nullptr;
	

	//背景画面の画像
	Sprite* backSprite = nullptr;
	Transform backTransform_ = {};
	SpritePosition backAllPosition_ = {};
	float backTransparency_ = 0.0f;


	//数
	static const int NUMBER_AMOUNT_ = 10;
	Sprite* numberSprite_[NUMBER_AMOUNT_] = { nullptr };
	Transform numberTransform_ = {};
	SpritePosition numberAllPosition_[NUMBER_AMOUNT_] = {};


	//倒した数
	static const int SMALL_SCORE_ = 2;
	Sprite* smallScoreSprite_[NUMBER_AMOUNT_] = { nullptr };
	Transform smallScoreTransform_[NUMBER_AMOUNT_] = {};
	SpritePosition smallScoreAllPosition_[NUMBER_AMOUNT_] = {};




	//キャラクター
	Sprite* characterSprite_ = nullptr ;
	Transform characterTransform_ = {};
	SpritePosition characterAllPosition_ = {};


	//吹き出し
	Sprite* speechBubbleSprite_ = nullptr ;
	Transform speechBubbleTransform_ = {};
	SpritePosition speechBubbleAllPosition_ = {};
	float scaleSize_ = 1.5f;



	//ランク
	int32_t rankName_ = 0;

	static const int RANK_AMOUNT_ = 5;
	Sprite* rankSprite_[RANK_AMOUNT_] = { nullptr };
	Transform rankTransform_[RANK_AMOUNT_]  = {};
	SpritePosition rankAllPosition_ [RANK_AMOUNT_] = {};


	//コメント
	Sprite* commentSprite_[RANK_AMOUNT_] = { nullptr };
	Transform commentTransform_[RANK_AMOUNT_]  = {};
	SpritePosition commentAllPosition_ [RANK_AMOUNT_] = {};


	//倒した数
	const float ENEMY_SIZE_ = 3.0f;
	static const int ENMEY_AMOUNT_ = 3;
	Sprite* enemySprite_[ENMEY_AMOUNT_] = { nullptr };
	Transform enemyTransform_[ENMEY_AMOUNT_]  = {};
	SpritePosition enemyAllPosition_ [ENMEY_AMOUNT_] = {};

	//×部分
	const float MULTIPLY_SIZE_ = 2.5f;
	Sprite* multiplySprite_[ENMEY_AMOUNT_] = { nullptr };
	Transform multiplyTransform_[ENMEY_AMOUNT_] = {};
	SpritePosition multiplyAllPosition_[ENMEY_AMOUNT_] = {};



	bool isFadeOut_ = false;
	int loadingTime_ = 0;
	float transparency_ = 1.0f;



	//コントローラー
	int triggerButtonATime_ = 0;



};


