#pragma once

#include <Input/Input.h>
#include <Audio/Audio.h>
#include "TextureManager/TextureManager.h"
#include "AllGameScene/GameManager/GameManager.h"
#include "AllGameScene/GameManager/IGameScene.h"

struct ValuePlace {
	int hundred;
	int ten;
	int one;


};

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

#pragma region CV
	static const int COMMENT_AMOUNT_ = 5;
	Audio* characterComment_[COMMENT_AMOUNT_] = { nullptr };
	uint32_t characterCommentHandle_[COMMENT_AMOUNT_] = { 0u };
#pragma endregion



	//Input
	Input* input_ = nullptr;
	TextureManager* textureManager_ = nullptr;
	

	//背景画面の画像
	Sprite* backSprite = nullptr;
	Transform backTransform_ = {};
	SpritePosition backAllPosition_ = {};
	float backTransparency_ = 0.0f;





	//キャラクター
	Sprite* characterSprite_ = nullptr ;
	Sprite* characterSprite2_ = nullptr;
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
	int32_t noob = 0;

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





	//スコア

	static const int NUMBER_AMOUNT_ = 10;

	int smallScore_ = 0;

	ValuePlace smallScorePlace_ = {};

	Sprite* smallScoreHundredsPlane_[NUMBER_AMOUNT_] = {nullptr};
	Sprite* smallScoreTensPlane_[NUMBER_AMOUNT_] = {nullptr};
	Sprite* smallScoreOnesPlane_[NUMBER_AMOUNT_] = { nullptr };

	Transform smallScoreHundredsPlaneTransform_  = {};
	Transform smallScoreTensPlaneTransform_  = {};
	Transform smallScoreOnesPlaneTransform_  = {};
	

	SpritePosition smallScoreHundredsPlaneAllPosition_ = {};
	SpritePosition smallScoreTensPlaneAllPosition_ = {};
	SpritePosition smallScoreOnesPlaneAllPosition_ = {};
	


	
	int normalScore_ = 0;
	ValuePlace normalScorePlace_ = {};

	Sprite* normalScoreHundredsPlane_[NUMBER_AMOUNT_] = {nullptr};
	Sprite* normalScoreTensPlane_[NUMBER_AMOUNT_] = {nullptr};
	Sprite* normalScoreOnesPlane_[NUMBER_AMOUNT_] = { nullptr };

	Transform normalScoreHundredsPlaneTransform_  = {};
	Transform normalScoreTensPlaneTransform_  = {};
	Transform normalScoreOnesPlaneTransform_  = {};
	
	SpritePosition normalScoreHundredsPlaneAllPosition_ = {};
	SpritePosition normalScoreTensPlaneAllPosition_ = {};
	SpritePosition normalScoreOnesPlaneAllPosition_ = {};
	


	int bigScore_ = 0;
	ValuePlace bigScorePlace_ = {};

	Sprite* bigScoreHundredsPlane_[NUMBER_AMOUNT_] = {nullptr};
	Sprite* bigScoreTensPlane_[NUMBER_AMOUNT_] = {nullptr};
	Sprite* bigScoreOnesPlane_[NUMBER_AMOUNT_] = { nullptr };

	Transform bigScoreHundredsPlaneTransform_  = {};
	Transform bigScoreTensPlaneTransform_  = {};
	Transform bigScoreOnesPlaneTransform_  = {};

	SpritePosition bigScoreHundredsPlaneAllPosition_ = {};
	SpritePosition bigScoreTensPlaneAllPosition_ = {};
	SpritePosition bigScoreOnesPlaneAllPosition_ = {};


	int allScore_ = 0;



	bool isCalculation_ = true;
	int cvTime_ = 0;


};


