#pragma once

#include <Input/Input.h>
#include <Audio/Audio.h>
#include "TextureManager/TextureManager.h"
#include "AllGameScene/GameManager/GameManager.h"
#include "AllGameScene/GameManager/IGameScene.h"
#include "../../../Player.h"
#include <memory>

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

	//プレイヤー
	std::unique_ptr<Player> player_ = nullptr;


	//UI
	//ロード時間
	int waitingTime_ = 0;
	const int SECOND_ = 60;


};