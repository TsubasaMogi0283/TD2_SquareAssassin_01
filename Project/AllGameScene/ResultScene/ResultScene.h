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
	Audio* titleBGM_ = nullptr;
	//SoundData titleSoundData_ = {};

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


};


