#pragma once

#include <Input/Input.h>
#include <Audio/Audio.h>
#include "TextureManager/TextureManager.h"
#include "AllGameScene/GameManager/GameManager.h"
#include "AllGameScene/GameManager/IGameScene.h"


class  TutorialScene  : public IGameScene{
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
	//Audio
	Audio* titleBGM_ = nullptr;
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


};