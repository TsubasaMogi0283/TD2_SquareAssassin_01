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

	yuka_ = new Model;
	transformyuka_ = { {0.25f,0.25f,0.1f},{0.0f,0.0f,0.0f},{0.0f,-2.28f,0.0f} };
	yuka_->CreateObject("Resources/Game/Ground", "yuka.obj");
	//
	playerTransform_ = { {0.2f,0.2f,0.2f},{0.0f,0.0f,0.0f},{3.7f,2.0f,0.0f} };
	player_ = new Player;

	player_->Initialize("Resources/Game/Player", "playre.obj", playerTransform_);
	//
	uint32_t wasdHandle = TextureManager::LoadTexture("Resources/wasd.png");
	wasdSprite = new Sprite();
	wasdSprite->LoadTextureHandle(wasdHandle);
	wasdAll_ = { {0.0f,0.0f},{0.0f,20.0f},{300.0f,0.0f},{300.0f,20.0f} };
	wasdSprite->SetAllPosition(wasdAll_);
	wasdPos = { {3.0f,3.0f,3.0f},{0.0f,0.0f,0.0f},{100.0f,130.0f,0.0f} };

	uint32_t kiHandle = TextureManager::LoadTexture("Resources/ki.png");
	kiSprite = new Sprite();
	kiSprite->LoadTextureHandle(kiHandle);
	kiAll_ = { {0.0f,0.0f},{0.0f,20.0f},{300.0f,0.0f},{300.0f,20.0f} };
	kiSprite->SetAllPosition(kiAll_);
	kiPos = { {3.0f,3.0f,3.0f},{0.0f,0.0f,0.0f},{100.0f,200.0f,0.0f} };

	uint32_t redHandle = TextureManager::LoadTexture("Resources/red.png");
	redSprite = new Sprite();
	redSprite->LoadTextureHandle(redHandle);
	redAll_ = { {0.0f,0.0f},{0.0f,240.0f},{425.0f,0.0f},{425.0f,240.0f} };
	redSprite->SetAllPosition(redAll_);
	redPos = { {3.0f,3.0f,3.0f},{0.0f,0.0f,0.0f},{0.0f,0.0f,0.0f} };



	uint32_t spaceHandle = TextureManager::LoadTexture("Resources/space.png");
	spaceSprite = new Sprite();
	spaceSprite->LoadTextureHandle(spaceHandle);
	spaceAll_ = { {0.0f,0.0f},{0.0f,20.0f},{300.0f,0.0f},{300.0f,20.0f} };
	spaceSprite->SetAllPosition(spaceAll_);
	spacePos = { {3.0f,3.0f,3.0f},{0.0f,0.0f,0.0f},{0.0f,0.0f,0.0f} };

	stateMove = 5;
	pushTime_ = -120;
}


void TutorialScene::Explanation() {
	if (blinkingCount_ == stateMove) {
	player_->Update();

	}
}

/// 更新
void TutorialScene::Update(GameManager* gameManager) {
	ImGui::Begin("Tutorial");
	ImGui::SliderInt("blinkingTime_", &blinkingTime_, -15, 15);
	ImGui::SliderInt("blinkingCount_", &blinkingCount_, -15, 15);
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

		if (pushTime_>120) {
			//今の所キーボードは仮置き
			//1を押したらSelectになる
			if (input_->GetInstance()->IsTriggerKey(DIK_SPACE) == true) {
				isFadeOut_ = true;
			}
		}
		
	}

	if (blinkingCount_ < stateMove) {
		blinkingTime_++;
		if (blinkingTime_ > 0) {

			blinking_ = 1;

		}

		if (blinkingTime_ > 10) {

			blinkingTime_ = -30;
			blinkingCount_ += 1;
		}


		if (blinkingTime_ < 0) {


			blinking_ = 0;
		}
	}
	if (blinkingCount_ == stateMove) {
		pushTime_++;
		spaceFrigu_ = 1;
		if (pushTime_ >120) {
			spaceFrigu_ = 0;
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
	yuka_->Draw(transformyuka_);
	player_->Draw();
	if (blinkingCount_ < stateMove) {
		wasdSprite->DrawRect(wasdPos);
		kiSprite->DrawRect(kiPos);
		if (blinking_ == 1) {

			redSprite->DrawRect(redPos);
		}
	}

	if (spaceFrigu_==1) {

	spaceSprite->DrawRect(spacePos);
	}
}


/// デストラクタ
TutorialScene::~TutorialScene() {

}
