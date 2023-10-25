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
	uint32_t wasdHandle = TextureManager::LoadTexture("Resources/Tutorial/Texture/wasd.png");
	wasdSprite = new Sprite();
	wasdSprite->LoadTextureHandle(wasdHandle);
	wasdAll_ = { {0.0f,0.0f},{0.0f,20.0f},{300.0f,0.0f},{300.0f,20.0f} };
	wasdSprite->SetAllPosition(wasdAll_);
	wasdPos = { {3.0f,3.0f,3.0f},{0.0f,0.0f,0.0f},{100.0f,130.0f,0.0f} };

	uint32_t kiHandle = TextureManager::LoadTexture("Resources/Tutorial/Texture/Key.png");
	keySprite = new Sprite();
	keySprite->LoadTextureHandle(kiHandle);
	kiAll_ = { {0.0f,0.0f},{0.0f,20.0f},{300.0f,0.0f},{300.0f,20.0f} };
	keySprite->SetAllPosition(kiAll_);
	kiPos = { {3.0f,3.0f,3.0f},{0.0f,0.0f,0.0f},{100.0f,200.0f,0.0f} };

	uint32_t redHandle = TextureManager::LoadTexture("Resources/Tutorial/Texture/red.png");
	redSprite = new Sprite();
	redSprite->LoadTextureHandle(redHandle);
	redAll_ = { {0.0f,0.0f},{0.0f,240.0f},{425.0f,0.0f},{425.0f,240.0f} };
	redSprite->SetAllPosition(redAll_);
	redPos = { {3.0f,3.0f,3.0f},{0.0f,0.0f,0.0f},{0.0f,0.0f,0.0f} };



	uint32_t spaceHandle = TextureManager::LoadTexture("Resources/Tutorial/Texture/space.png");
	spaceSprite = new Sprite();
	spaceSprite->LoadTextureHandle(spaceHandle);
	spaceAll_ = { {0.0f,0.0f},{0.0f,20.0f},{300.0f,0.0f},{300.0f,20.0f} };
	spaceSprite->SetAllPosition(spaceAll_);
	spacePos = { {3.0f,3.0f,3.0f},{0.0f,0.0f,0.0f},{100.0f,200.0f,0.0f} };








#pragma region 説明以上
	uint32_t explanationOverHandle = TextureManager::LoadTexture("Resources/Tutorial/Texture/ThatIsAll.png");
	explanationOverSprite_=new Sprite();
	explanationOverTransform_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{0.0f,0.0f,0.0f} };
	explanationOverAll_ = { {0.0f,0.0f},{0.0f,720.0f},{1280.0f,0.0f},{1280.0f,720.0f}};
	explanationOverSprite_->LoadTextureHandle(explanationOverHandle);
	explanationOverSprite_->SetAllPosition(explanationOverAll_);


#pragma endregion



	stateMove = 5;
	pushTime_ = 0;
}


void TutorialScene::Explanation() {
	


	if (isExplanation_ == true) {
		player_->Update();

		flashTime_ += 1;
		
		//点滅と移動の説明
		int flashInterval = SECOND_ - 20;
		if (flashTime_ > 0&& flashTime_ <=flashInterval*6) {
			isMoveExplanation_ = true;
			if (flashTime_ > flashInterval*0 && flashTime_ <=flashInterval) {
				blinking_ = 1;
			}
			if (flashTime_ > flashInterval && flashTime_ <=flashInterval*2) {
				blinking_ = 0;
			}
			if (flashTime_ > flashInterval*2 && flashTime_ <=flashInterval*3) {
				blinking_ = 1;
			}
			if (flashTime_ > flashInterval *3 && flashTime_ <=flashInterval*4) {
				blinking_ = 0;
			}
			if (flashTime_ > flashInterval*4 && flashTime_ <=flashInterval*5) {
				blinking_ = 1;
			}
			if (flashTime_ > flashInterval *5 && flashTime_ <=flashInterval*6) {
				blinking_ = 0;
			}
		}
		if (flashTime_ >flashInterval*6) {
			isMoveExplanation_ = false;
			isSpaceExplanation_ = 1;
		}

		//攻撃
		if (isSpaceExplanation_ == 1) {
			spaceExplanationTime_ += 1;

			if (spaceExplanationTime_>SECOND_ * 3) {
				isSpaceExplanation_ = 0;
				isThatAllExplanation_ = true;
				isExplanation_ = false;
			}

		}
	}
	
	
	if (isExplanation_ == false) {
		XINPUT_STATE joyState{};

		//説明は以上
		if (isThatAllExplanation_ == true) {
			if (input_->GetInstance()->IsPushKey(DIK_SPACE) == true) {
				
				pushTime_ += 1;
			}
			//コントローラー版
			if (Input::GetInstance()->GetJoystickState(joyState)) {

				//左
				if (joyState.Gamepad.wButtons & XINPUT_GAMEPAD_A) {
					pushTime_ += 1;
				}

			}

			if (pushTime_>SECOND_*3) {
				isFadeOut_ = true;
				
			}
		}
	}
	
	
	


}

/// 更新
void TutorialScene::Update(GameManager* gameManager) {
	ImGui::Begin("Tutorial");
	ImGui::SliderInt("blinkingTime_", &blinkingTime_, -15, 15);
	ImGui::SliderInt("blinkingCount_", &blinkingCount_, -15, 15);
	ImGui::InputInt("pushTime", &pushTime_);
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

		
		
	}

	
	if (isExplanation_ == false) {
		//フェードアウト
		if (isFadeOut_ == true) {
			tutorialTextureTransparency_ -= 0.1f;
			if (tutorialTextureTransparency_ < 0.0f) {
				tutorialTextureTransparency_ = 0.0f;

				
				
				waitingTime_ += 1;

				if (waitingTime_ > SECOND_ * 3) {
					gameManager->ChangeScene(new SelectScene());
				}

			}
		}
	}

	



}

/// 描画
void TutorialScene::Draw(GameManager* gameManager) {
	yuka_->Draw(transformyuka_);
	
	if (isThatAllExplanation_ == false) {
		player_->Draw();
		//移動説明
		if (isMoveExplanation_==true) {
			wasdSprite->DrawRect(wasdPos);
			keySprite->DrawRect(kiPos);
			
		}
		if (blinking_ == 1) {
			//点滅する画像
			redSprite->DrawRect(redPos);
		}

		if (isSpaceExplanation_==1) {

			spaceSprite->DrawRect(spacePos);
		}
	}

	

	//説明は以上
	if (isThatAllExplanation_ == true) {
		explanationOverSprite_->DrawRect(explanationOverTransform_);
	}
}


/// デストラクタ
TutorialScene::~TutorialScene() {

}
