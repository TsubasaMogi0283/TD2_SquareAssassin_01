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
	SoundData titleSoundData_ = {};

	//Input
	Input* input_ = nullptr;
	TextureManager* textureManager_ = nullptr;
	

	Sprite* titleSprite = nullptr;
	Sprite* startSprite = nullptr;
	Sprite* selectSprite_ = nullptr;


	

	Transform transformSprite_ = {};
	Transform selectSpriteTransform_ = {};


	SpritePosition spriteAllPosition_ = {};
	SpritePosition spriteAllPosition2_ = {};
	SpritePosition selectspriteAllPosition_ = {};


	//透明度
	float titleTransparency = 1.0f;
	float startTransparency = 1.0f;
	//透明になる時間をこれで管理
	int32_t textureChangeTime_ = 0;



	
	//1秒
	const int SECOND_ = 60;

	bool isFadeout_ = false;
	int waitingTime_ = 0;

	int startFlashTime_ = 0;
	const int FLASH_INTERVAL = 3;

};