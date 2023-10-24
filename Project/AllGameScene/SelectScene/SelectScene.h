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

	void ImGuiDebug();

	/// 更新
	void Update(GameManager* gameManager)override;

	/// 描画
	void Draw(GameManager* gameManager)override;


private:
	//Audio
	Audio* selectBGM_ = nullptr;
	SoundData selectSoundData_ = {};

	Audio* decideSE_ = nullptr;
	SoundData decideSESoundData_ = {};

	Audio* moveSE_ = nullptr;
	SoundData moveSESoundData_ = {};


	//Input
	Input* input_ = nullptr;
	TextureManager* textureManager_ = nullptr;
	

	//選択画面の画像
	Sprite* selectSprite = nullptr;
	Transform selectSpriteTransform_ = {};
	SpritePosition spriteAllPosition_ = {};
	float selectTextureTransparency_ = 0.0f;

	//タイトルに戻る
	Sprite* titleIconSprite = nullptr;
	Transform titleIconTransform_ = {};
	SpritePosition titleIconAllPosition_ = {};


	//ステージ
	const float stageTextureScale_ = 1.5f;
	static const int STAGE_AMOUNT_=2;
	Sprite* stageSprite_[STAGE_AMOUNT_] = { nullptr };
	Transform stageTransform_[STAGE_AMOUNT_] = {};
	SpritePosition stageAllPosition_ = {};


	//ステージの名前
	Sprite* gameTextSprite_ =  nullptr ;
	Sprite* tutorialtextSprite_ =  nullptr ;

	Transform gameTextTransform_ = {};
	Transform tutorialTextTransform_ = {};

	SpritePosition TextAllPosition_ = {};



	//キャラクター
	Sprite* characterSprite = nullptr;
	Transform characterTransform_ = {};
	SpritePosition characterAllPosition_ = {};
	float_t MOVE_INTERVAL = 400.0f;




	//フェード
	bool isFadeIn_ = true;
	int fadeInTime_ = 0;

	bool isFadeOut_ = false;
	int fadeOutTime_ = 0;

	int loadingTime_ = 0;

	//次はどのシーンに行くか決めるための列挙
	enum NextScene {
		Game,
		Tutorial,
		Title,
	};

	int nextScene_ = 0;

	//ロード時間
	int waitingTime_ = 0;
	const int SECOND_ = 60;


};