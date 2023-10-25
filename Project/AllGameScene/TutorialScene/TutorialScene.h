#pragma once

#include <Input/Input.h>
#include <Audio/Audio.h>
#include "TextureManager/TextureManager.h"
#include "AllGameScene/GameManager/GameManager.h"
#include "AllGameScene/GameManager/IGameScene.h"
#include <Object/Enemy/enemy.h>
#include <Object/Player/Player.h>

class  TutorialScene : public IGameScene {
public:
	//コンストラクタ
	TutorialScene();

	/// デストラクタ
	~TutorialScene();

	/// 初期化
	void Initialize(GameManager* gameManager)override;


	//チュートリアル
	void Explanation();


	/// 更新
	void Update(GameManager* gameManager)override;

	/// 描画
	void Draw(GameManager* gameManager)override;



private:
	

	//Input
	Input* input_ = nullptr;
	//TextureManager
	TextureManager* textureManager_ = nullptr;



	//チュートリアル画面の画像
	Sprite* tutorialSprite = nullptr;
	Transform selectSpriteTransform_ = {};
	SpritePosition spriteAllPosition_ = {};
	float tutorialTextureTransparency_ = 0.0f;


	//フェード
	bool isFadeIn_ = true;
	int fadeInTime_ = 0;

	bool isFadeOut_ = false;
	int fadeOutTime_ = 0;




	//UI
	//ロード時間
	int waitingTime_ = 0;
	const int SECOND_ = 60;
	//
	Model* yuka_ = nullptr;
	Transform transformyuka_ = {};
	//
	Player* player_;
	Transform playerTransform_;
	//
	Sprite* wasdSprite;

	Transform wasdPos;
	SpritePosition wasdAll_ = {};
	//
	Sprite* keySprite;
	Transform kiPos;
	SpritePosition kiAll_ = {};
	//
	Sprite* redSprite;
	Transform redPos;
	SpritePosition redAll_ = {};
	//
	Sprite* spaceSprite;
	Transform spacePos;
	SpritePosition spaceAll_ = {};
	//
	int blinking_;
	int blinkingTime_;

	//点滅
	int blinkingCount_;

	 int stateMove;

	 int pushTime_;
	 int isSpaceExplanation_;


	 int flashTime_ = 0;
	 bool isMoveExplanation_ = false;

	 int spaceExplanationTime_ = 0;




	Sprite* explanationOverSprite_;
	Transform explanationOverTransform_;
	SpritePosition explanationOverAll_ = {};
	bool isThatAllExplanation_ = false;

	bool isExplanation_ = true;



	Audio* bgm_ = nullptr;
	uint32_t bgmHandle_ = 0u;


	Audio* se_ = nullptr;
	uint32_t seHandle_ = 0u;
	int seTime_ = 0;

};