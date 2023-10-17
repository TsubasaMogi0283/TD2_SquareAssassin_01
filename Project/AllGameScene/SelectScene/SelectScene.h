#pragma once

#include <Input/Input.h>
#include <Audio/Audio.h>
#include "TextureManager/TextureManager.h"
#include "AllGameScene/GameManager/GameManager.h"
#include "AllGameScene/GameManager/IGameScene.h"

class SelectScene  : public IGameScene{
public:
	//コンストラクタ
	SelectScene();

	/// デストラクタ
	~SelectScene();

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
	

	//選択画面の画像
	Sprite* selectSprite = nullptr;
	Transform selectSpriteTransform_ = {};
	SpritePosition spriteAllPosition_ = {};




};