#include "SelectScene.h"
#include "AllGameScene/TutorialScene/TutorialScene.h"
#include "AllGameScene/GameScene/GameScene.h"
#include "AllGameScene/TitleScene/TitleScene.h"

//コンストラクタ
SelectScene::SelectScene() {

}

/// 初期化
void SelectScene::Initialize(GameManager* gameManager) {
	
#pragma region 背景
	
	selectSprite = new Sprite();
	selectSpriteTransform_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{0.0f,0.0f,0.0f} };
	uint32_t selectTextureHandle = TextureManager::LoadTexture("Resources/Select/Texture/Base/SelectTexture.png");
	selectSprite->LoadTextureHandle(selectTextureHandle);
	spriteAllPosition_ = { {0.0f,0.0f},{0.0f,720.0f},{1280.0f,0.0f},{1280.0f,720.0f} };
	selectSprite->SetAllPosition(spriteAllPosition_);

#pragma endregion

#pragma region ステージ
	for (int i = 0; i < STAGE_AMOUNT_; i++) {
		stageSprite_[i] = new Sprite();
		uint32_t stageTextureHandle = TextureManager::LoadTexture("Resources/Select/Texture/Stage/Stage.png");
		stageSprite_[i]->LoadTextureHandle(stageTextureHandle);
		stageAllPosition_ = {{0.0f,0.0f},{0.0f,300.0f},{200.0f,0.0f},{200.0f,300.0f}};
		stageTransform_[0] = { {stageTextureScale_,stageTextureScale_,stageTextureScale_},{0.0f,0.0f,0.0f},{500.0f,160.0f,0.0f}};
		stageTransform_[1] = { {stageTextureScale_,stageTextureScale_,stageTextureScale_},{0.0f,0.0f,0.0f},{900.0f,160.0f,0.0f}};
		stageSprite_[i]->SetAllPosition(stageAllPosition_);

	}

#pragma endregion

#pragma region ステージの名前

	gameTextSprite_ =  new Sprite() ;
	tutorialtextSprite_ = new Sprite();

	gameTextTransform_ = {{stageTextureScale_,stageTextureScale_,stageTextureScale_},{0.0f,0.0f,0.0f},{500.0f,160.0f,0.0f}};
	tutorialTextTransform_ = {{stageTextureScale_,stageTextureScale_,stageTextureScale_},{0.0f,0.0f,0.0f},{900.0f,160.0f,0.0f}};

	TextAllPosition_ = { {0.0f,0.0f},{0.0f,310.0f},{200.0f,0.0f}, {200.0f,310.0f}, };

	uint32_t tutorialTextureHandle = TextureManager::LoadTexture("Resources/Select/Texture/Text/Tutorial.png");
	uint32_t gameTextureHandle = TextureManager::LoadTexture("Resources/Select/Texture/Text/Game.png");

	gameTextSprite_->LoadTextureHandle(gameTextureHandle);
	tutorialtextSprite_->LoadTextureHandle(tutorialTextureHandle);


	gameTextSprite_->SetAllPosition(TextAllPosition_);
	tutorialtextSprite_->SetAllPosition(TextAllPosition_);

	
	
	

#pragma endregion

#pragma region タイトルに戻る
	titleIconSprite =  new Sprite();
	titleIconTransform_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{130.0f,460.0f,0.0f} };
	titleIconAllPosition_ = { {0.0f,0.0f},{0.0f,150.0f},{150.0f,0.0f},{150.0f,150.0f}};
	uint32_t titleIconTextureHandle = TextureManager::LoadTexture("Resources/Select/Texture/Icon/BackToTitle.png");
	titleIconSprite->LoadTextureHandle(titleIconTextureHandle);
	titleIconSprite->SetAllPosition(titleIconAllPosition_);

#pragma endregion

#pragma region キャラクター
	characterSprite =  new Sprite();;
	characterTransform_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,5.870f},{460.0f,500.0f,0.0f}};
	characterAllPosition_ = { {0.0f,0.0f},{0.0f,100.0f},{100.0f,0.0f},{100.0f,100.0f} };
	uint32_t characterTextureHandle = TextureManager::LoadTexture("Resources/Select/Texture/Character/Character.png");
	
	characterSprite->LoadTextureHandle(characterTextureHandle);

	characterSprite->SetAllPosition(characterAllPosition_);
#pragma endregion


	
	
	//SE
	//決定
	decideSE_ = Audio::GetInstance();
	decideSESoundData_ = decideSE_->LoadWave("Resources/Select/Music/DecideSE.wav");

	//移動
	moveSE_ = Audio::GetInstance();
	moveSESoundData_ = moveSE_->LoadWave("Resources/Select/Music/Move.wav");

	//BGM
	//タイトルBGM
	selectBGM_ = Audio::GetInstance();
	selectSoundData_ = selectBGM_->LoadWave("Resources/Select/Music/SelectBGM.wav");

	//再生
	selectBGM_->PlayWave(selectSoundData_ ,true);
	selectBGM_->ChangeVolume(selectSoundData_, 0.5f);
}

void SelectScene::ImGuiDebug() {
	ImGui::Begin("Select");
	ImGui::Text("1 To GameScene");
	ImGui::Text("2 To GameScene");
	

	ImGui::End();


	ImGui::Begin("Title");
	ImGui::SliderFloat3("Scale", &titleIconTransform_.scale.x,1.0f,5.0f);
	ImGui::SliderFloat3("Rotate", &titleIconTransform_.rotate.x,0.0f,60.0f);
	ImGui::SliderFloat3("Position", &titleIconTransform_.translate.x,0.0f,1280.0f);
	ImGui::End();


	ImGui::Begin("Character");
	ImGui::SliderFloat3("Scale", &characterTransform_.scale.x,1.0f,5.0f);
	ImGui::SliderFloat3("Rotate", &characterTransform_.rotate.x,0.0f,60.0f);
	ImGui::SliderFloat3("Position", &characterTransform_.translate.x,0.0f,1280.0f);
	ImGui::SliderFloat("MoveInterval", &MOVE_INTERVAL,0.0f,1280.0f);
	
	ImGui::End();


	ImGui::Begin("Stage1");
	ImGui::SliderFloat3("Scale", &stageTransform_[0].scale.x, 1.0f, 5.0f);
	ImGui::SliderFloat3("Rotate", &stageTransform_[0].rotate.x,0.0f,60.0f);
	ImGui::SliderFloat3("Position", &stageTransform_[0].translate.x,0.0f,1280.0f);
	ImGui::End();

	ImGui::Begin("Stage2");
	ImGui::SliderFloat3("Scale", &stageTransform_[1].scale.x, 1.0f, 5.0f);
	ImGui::SliderFloat3("Rotate", &stageTransform_[1].rotate.x,0.0f,60.0f);
	ImGui::SliderFloat3("Position", &stageTransform_[1].translate.x,0.0f,1280.0f);
	ImGui::End();

	ImGui::Begin("GameText");
	ImGui::SliderFloat3("Scale", &gameTextTransform_.scale.x, 1.0f, 5.0f);
	ImGui::SliderFloat3("Rotate", &gameTextTransform_.rotate.x,0.0f,60.0f);
	ImGui::SliderFloat3("Position", &gameTextTransform_.translate.x,0.0f,1280.0f);
	ImGui::End();

	ImGui::Begin("TutorialText");
	ImGui::SliderFloat3("Scale", &tutorialTextTransform_.scale.x, 1.0f, 5.0f);
	ImGui::SliderFloat3("Rotate", &tutorialTextTransform_.rotate.x,0.0f,60.0f);
	ImGui::SliderFloat3("Position", &tutorialTextTransform_.translate.x,0.0f,1280.0f);
	ImGui::End();




}

/// 更新
void SelectScene::Update(GameManager* gameManager) {

	

	//ImGuiDebug();

#pragma region 透明度
	selectSprite->SetTransparency(selectTextureTransparency_);
	for (int i = 0; i < STAGE_AMOUNT_; i++) {
		stageSprite_[i]->SetTransparency(selectTextureTransparency_);
	}
	characterSprite->SetTransparency(selectTextureTransparency_);
	titleIconSprite->SetTransparency(selectTextureTransparency_);

	
	
	gameTextSprite_->SetTransparency(selectTextureTransparency_);
	tutorialtextSprite_->SetTransparency(selectTextureTransparency_);



#pragma endregion

	//フェードイン
	if (isFadeIn_ == true) {
		selectTextureTransparency_ += 0.07f;
		if (selectTextureTransparency_ > 1.0f) {
			selectTextureTransparency_ = 1.0f;
			isFadeIn_ = false;
		}
	
	}
	



	//選択画面
	if (isFadeIn_ == false && isFadeOut_==false) {
		//selectBGM_->SetVolume(0.5f);

		XINPUT_STATE joyState{};

		if (Input::GetInstance()->GetJoystickState(joyState) ) {

			//Aボタン
			if (joyState.Gamepad.wButtons & XINPUT_GAMEPAD_A) {
				triggerButtonATime_ += 1;
			
			}

			



			//押していない時
			if ((joyState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT)==0) {
				isTriggerRight_ = false;
				triggerRightTime_ = 0;
			}
			//押していない時
			if ((joyState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT)==0) {
				isTriggerLeft_ = false;
				triggerLeftTime_ = 0;
			}


			
		


		}

		//falseの時押したとき
		if (isTriggerRight_ == false) {
			if (joyState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT&&triggerRightTime_==0) {
				triggerRightTime_ += 1;
		
			}
		}

		//falseの時押したとき
		if (isTriggerLeft_ == false) {
			if (joyState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT&&triggerLeftTime_==0) {
				triggerLeftTime_ += 1;
		
			}
		}
		//キャラクターの動き
		//右に動く
		if ((input_->GetInstance()->IsTriggerKey(DIK_RIGHT) == true) ||
			(input_->GetInstance()->IsTriggerKey(DIK_D) == true)||(triggerRightTime_==1)){
			isTriggerRight_ = true;
			triggerRightTime_ = 0;
			if (characterTransform_.translate.x !=860.0f) {
				moveSE_->PlayWave(moveSESoundData_, false);
				moveSE_->ChangeVolume(moveSESoundData_, 0.5f);
				characterTransform_.translate.x += MOVE_INTERVAL;
			}
			

		}

		//左に動く
		if ((input_->GetInstance()->IsTriggerKey(DIK_LEFT) == true) ||
			(input_->GetInstance()->IsTriggerKey(DIK_A) == true)||(triggerLeftTime_==1)) {
			isTriggerLeft_ = true;
			triggerLeftTime_ = 0;
		


			if (characterTransform_.translate.x != 60.0) {
				moveSE_->PlayWave(moveSESoundData_, false);
				moveSE_->ChangeVolume(moveSESoundData_, 0.5f);
				characterTransform_.translate.x -= MOVE_INTERVAL;
			}
		

		}
		//決定
		if ((input_->GetInstance()->IsTriggerKey(DIK_SPACE) == true) || triggerButtonATime_==1) {
			decideSE_->PlayWave(decideSESoundData_, false);
			decideSE_->ChangeVolume(decideSESoundData_,0.6f);

			selectBGM_->StopWave(selectSoundData_);
			
			

			//タイトルへ
			if (characterTransform_.translate.x == 60.0f) {
				isFadeOut_ = true;
				nextScene_ = Title;
				
			}

			//今の所キーボードは仮置き
			//1を押したらSelectになる
			if (characterTransform_.translate.x == 460.0f) {

				isFadeOut_ = true;
				nextScene_ = Game;
			}
			//2を押したらTutorialになる
			if (characterTransform_.translate.x == 860.0f) {
				isFadeOut_ = true;
				nextScene_ = Tutorial;
			}

		}



		
	}
	


	//フェードアウト
	if (isFadeOut_ == true && isFadeIn_==false) {
		
		//selectBGM_->StopWave(selectSoundData_);

		selectTextureTransparency_ -= 0.07f;
		if (selectTextureTransparency_ < 0.0f) {
			selectTextureTransparency_ = 0.0f;

			loadingTime_ += 1;
			if (loadingTime_ > 100) {
				//GameSceneへ
				if (nextScene_ == Game) {
					waitingTime_ += 1;
					if (waitingTime_ > SECOND_ * 2) {
						gameManager->ChangeScene(new GameScene());
					}
					
				}


				//TutorialSceneへ
				if (nextScene_ == Tutorial) {
					waitingTime_ += 1;

					if (waitingTime_ > SECOND_ * 2) {
						gameManager->ChangeScene(new TutorialScene());
					}
				}

				//TitleSceneへ
				if (nextScene_ == Title) {
					waitingTime_ += 1;

					if (waitingTime_ > SECOND_ * 2) {
						gameManager->ChangeScene(new TitleScene());
					}
				}
			
			}
			
		}
	}

	

	
}

/// 描画
void SelectScene::Draw(GameManager* gameManager) {
	//ベースの画像
	selectSprite->DrawRect(selectSpriteTransform_);
	//キャラクターひょっこり
	characterSprite->DrawRect(characterTransform_);
	//タイトルへ
	titleIconSprite->DrawRect(titleIconTransform_);

	//ステージこと巻物
	for (int i = 0; i < STAGE_AMOUNT_; i++) {
		stageSprite_[i]->DrawRect(stageTransform_[i]);

	}
	gameTextSprite_->DrawRect(gameTextTransform_);
	tutorialtextSprite_->DrawRect(tutorialTextTransform_);

	

	
}


/// デストラクタ
SelectScene::~SelectScene() {
	delete selectSprite;
	delete characterSprite;
	//タイトルへ
	delete titleIconSprite;

	//ステージこと巻物
	for (int i = 0; i < STAGE_AMOUNT_; i++) {
		delete stageSprite_[i];

	}
	delete gameTextSprite_;
	delete tutorialtextSprite_;


	decideSE_->SoundUnload(decideSESoundData_);
	selectBGM_->SoundUnload(selectSoundData_);
	
	//移動
	moveSE_->SoundUnload(moveSESoundData_);




}