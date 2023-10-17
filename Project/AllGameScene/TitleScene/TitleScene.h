#pragma once

#include <Input/Input.h>
#include <Audio/Audio.h>
#include "TextureManager/TextureManager.h"
#include "AllGameScene/GameManager/GameManager.h"
#include "AllGameScene/GameManager/IGameScene.h"

class TitleScene  : public IGameScene{
public:
	//コンストラクタ
	TitleScene();

	/// デストラクタ
	~TitleScene();

	/// 初期化
	void Initialize(GameManager* gameManager)override;

	/// 更新
	void Update(GameManager* gameManager)override;

	/// 描画
	void Draw(GameManager* gameManager)override;


private:
	//Audio
	Audio* titleBGM_ = nullptr;
	//Input
	Input* input_ = nullptr;
	TextureManager* textureManager_ = nullptr;
	

	Sprite* titleSprite = nullptr;
	Sprite* startSprite = nullptr;


	SoundData soundData_ = {};

	Transform transformSprite_ = {};
	Transform transformSprite2_ = {};

	SpritePosition spriteAllPosition_ = {};
	SpritePosition spriteAllPosition2_ = {};

	float startTransparency = 1.0f;

	const int SECOND_ = 60;

	int32_t textureChangeTime_ = 0;
};