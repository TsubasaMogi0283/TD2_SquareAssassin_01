#include "TutorialScene.h"
#include "AllGameScene/SelectScene/SelectScene.h"


//コンストラクタ
TutorialScene::TutorialScene() {

}



/// 初期化
void TutorialScene::Initialize(GameManager* gameManager) {
	uint32_t selectTextureHandle = TextureManager::LoadTexture("Resources/Select/Texture/Base/SelectTexture.png");

	selectSpriteTransform_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{0.0f,0.0f,0.0f} };

	tutorialSprite = new Sprite();
	tutorialSprite->LoadTextureHandle(selectTextureHandle);
	spriteAllPosition_ = { {0.0f,0.0f},{0.0f,720.0f},{1280.0f,0.0f},{1280.0f,720.0f} };
	tutorialSprite->SetAllPosition(spriteAllPosition_);



	

}


void TutorialScene::Explanation() {

}

/// 更新
void TutorialScene::Update(GameManager* gameManager) {
	ImGui::Begin("Tutorial");


	ImGui::End();

	tutorialSprite->SetTransparency(tutorialTextureTransparency_);

	//フェードイン
	if (isFadeIn_ == true) {
		tutorialTextureTransparency_ += 0.01f;
		if (tutorialTextureTransparency_ > 1.0f) {
			tutorialTextureTransparency_ = 1.0f;
			isFadeIn_ = false;
		}
	
	}
	


	//今の所
	if (isFadeIn_ == false) {

		//説明自体はExplanation関数内に書いてほしいです
		Explanation();


		//今の所キーボードは仮置き
		//1を押したらSelectになる
		if (input_->GetInstance()->IsTriggerKey(DIK_1) == true) {
			isFadeOut_ = true;
		}
		
	}



	//フェードアウト
	if (isFadeOut_ == true) {
		tutorialTextureTransparency_ -= 0.01f;
		if (tutorialTextureTransparency_ < 0.0f) {
			tutorialTextureTransparency_ = 0.0f;

			
			
			waitingTime_ += 1;

				if (waitingTime_ > SECOND_ * 3) {
					gameManager->ChangeScene(new SelectScene());
				}

		}
	}



}

/// 描画
void TutorialScene::Draw(GameManager* gameManager) {

}


/// デストラクタ
TutorialScene::~TutorialScene() {

}
