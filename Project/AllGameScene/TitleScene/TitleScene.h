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

	void ImGui();

	/// 更新
	void Update(GameManager* gameManager)override;

	/// 描画
	void Draw(GameManager* gameManager)override;


private:
	//Audio
	Audio* titleBGM_ = nullptr;
	uint32_t titleSoundData_ = {};

	Audio* startSE_ = nullptr;
	uint32_t startSESoundData_ = {};
	int seTime_ = 0;

	//Input
	Input* input_ = nullptr;
	TextureManager* textureManager_ = nullptr;
	

	Sprite* titleSprite_ = nullptr;
	Sprite* startSprite_ = nullptr;
	Sprite* selectSprite_ = nullptr;

	Sprite* characterSprite_ = nullptr;

	static const int CLOUD_AMOUNT_ = 5;
	Sprite* cloudSprite_[CLOUD_AMOUNT_] = { nullptr };

	Transform transformSprite_ = {};
	Transform selectSpriteTransform_ = {};
	Transform cloudTransform_[CLOUD_AMOUNT_] = {};
	Transform characterTransform_ = {};
	//Spriteのトランスフォーム改良したい
	//Vector2にしたい
	const Vector3 cloudSpeed_ = { 1.0f,0.0f,0.0f };

	SpritePosition spriteAllPosition_ = {};
	SpritePosition spriteAllPosition2_ = {};
	SpritePosition selectspriteAllPosition_ = {};
	SpritePosition cloudAllPosition_ = {};
	SpritePosition characterAllPosition_ = {};



	//透明度
	float textureTransparency = 1.0f;
	float startTransparency = 1.0f;
	//透明になる時間をこれで管理
	int32_t textureChangeTime_ = 0;



	
	//1秒
	const int SECOND_ = 60;

	bool isFadeout_ = false;
	int waitingTime_ = 0;

	int startFlashTime_ = 0;
	const int FLASH_INTERVAL = 3;

	float volume_ = 1.0f;
};