#include "TitleScene.h"
#include "AllGameScene/SelectScene/SelectScene.h"

//コンストラクタ
TitleScene::TitleScene() {
}

/// デストラクタ
TitleScene::~TitleScene() {
	delete titleSprite_;
	delete startSprite_;

	
	//雲の動き
	for (int i = 0; i < CLOUD_AMOUNT_; i++) {
		delete cloudSprite_[i];

	}
	
	//キャラクター
	delete characterSprite_; 

}

/// 初期化
void TitleScene::Initialize(GameManager* gameManager) {

	//画像の読み込み
	uint32_t titleTextureHandle = TextureManager::LoadTexture("Resources/Title/Texture/Base/TitleLogo.png");
	uint32_t startTextureHandle= TextureManager::LoadTexture("Resources/Title/Texture/Start/Start.png");
	uint32_t cloudTextureHandle = TextureManager::LoadTexture("Resources/Title/Texture/Cloud/Cloud.png");
	uint32_t characterTextureHandle = TextureManager::LoadTexture("Resources/Title/Texture/Character/Character.png");


	//タイトルとスタート
	transformSprite_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{0.0f,0.0f,0.0f} };

	//タイトル
	titleSprite_ = new Sprite();
	titleSprite_->LoadTextureHandle(titleTextureHandle);
	spriteAllPosition_ = { {0.0f,0.0f},{0.0f,720.0f},{1280.0f,0.0f},{1280.0f,720.0f} };
	titleSprite_->SetAllPosition(spriteAllPosition_);

	
	//スタート
	startSprite_ = new Sprite();
	startSprite_->LoadTextureHandle(startTextureHandle);
	spriteAllPosition2_ = { {0.0f,0.0f},{0.0f,720.0f},{1280.0f,0.0f},{1280.0f,720.0f} };
	startSprite_->SetAllPosition(spriteAllPosition2_);


	//雲
	for (int i = 0; i < CLOUD_AMOUNT_; i++) {
		cloudSprite_[i] = new Sprite();
		cloudSprite_[i]->LoadTextureHandle(cloudTextureHandle);
		cloudAllPosition_ = { {0.0f,0.0f},{0.0f,128.0f},{256.0f,0.0f},{256.0f,128.0f} };
		cloudSprite_[i]->SetAllPosition(cloudAllPosition_);

		cloudTransform_[0] = { { 1.0f,1.0f,1.0f }, { 0.0f,0.0f,0.0f }, { -100.0f,10.0f,0.0f } };
		cloudTransform_[1] = { { 1.0f,1.0f,1.0f }, { 0.0f,0.0f,0.0f }, { 200.0f,30.0f,0.0f } };
		cloudTransform_[2] = { { 1.0f,1.0f,1.0f }, { 0.0f,0.0f,0.0f }, { 600.0f,20.0f,0.0f } };
		cloudTransform_[3] = { { 1.0f,1.0f,1.0f }, { 0.0f,0.0f,0.0f }, { 700.0f,0.0f,0.0f } };
		cloudTransform_[4] = { { 1.0f,1.0f,1.0f }, { 0.0f,0.0f,0.0f }, { 1100.0f,15.0f,0.0f } };

	}
	
	
	//キャラクター
	characterSprite_ = new Sprite();
	characterSprite_->LoadTextureHandle(characterTextureHandle);
	characterAllPosition_ = { {0.0f,0.0f},{0.0f,256.0f},{256.0f,0.0f},{256.0f,256.0f} };
	characterSprite_->SetAllPosition(characterAllPosition_);
	characterTransform_ = { { 1.0f,1.0f,1.0f }, { 0.0f,0.0f,0.0f }, { 0.0f,0.0f,0.0f } };





	//タイトルBGM
	titleBGM_ = Audio::GetInstance();
	//titleBGM_->Initialize();
	titleSoundData_ = titleBGM_->LoadWave("Resources/Title/Music/Title.wav");

	//再生
	titleBGM_->PlayWave(titleSoundData_ ,true);
	
	//SE
	startSE_ = Audio::GetInstance();
	//startSE_->Initialize();
	startSESoundData_ = startSE_->LoadWave("Resources/Title/Music/StartSE.wav");


}

void TitleScene::ImGui() {
	ImGui::Begin("Character");
	ImGui::InputFloat3("Position", &characterTransform_.translate.x);
	ImGui::SliderFloat3("Position", &characterTransform_.translate.x,0.0f,1280.0f);

	
	ImGui::End();


	ImGui::Begin("Volume");
	ImGui::SliderFloat("Title", &volume_, 0.0f, 1.0f);
	
	ImGui::End();

}

/// 更新
void TitleScene::Update(GameManager* gameManager) {

	//ImGui();

#pragma region 透明度

	startSprite_->SetTransparency(startTransparency);
	//タイトルキャラクター雲同じ透明度の変化だから変数一つで良いよね
	titleSprite_->SetTransparency(textureTransparency);
	characterSprite_->SetTransparency(textureTransparency);
	//雲の動き
	for (int i = 0; i < CLOUD_AMOUNT_; i++) {
		cloudSprite_[i]->SetTransparency(textureTransparency);

	}


#pragma endregion
	//titleBGM_->SetVolume(volume_);


	//雲の動き
	for (int i = 0; i < CLOUD_AMOUNT_; i++) {
		cloudTransform_[i].translate = Add(cloudTransform_[i].translate,cloudSpeed_);

		//ループ処理
		if (cloudTransform_[i].translate.x > 1280.0f) {
			cloudTransform_[i].translate.x = -256.0f;
		}

	}

	
	
	//スペースキーかAボタンでスタートのシーン
	if (isFadeout_ == false) {
		

		//0.5秒ずつ透明度が変わる
		textureChangeTime_ += 1;
		if (textureChangeTime_ > 0) {
			if (textureChangeTime_ > 0 && textureChangeTime_ <= SECOND_/2) {
				startTransparency = 1.0f;
			}
			if (textureChangeTime_ > SECOND_/2 && textureChangeTime_ <= SECOND_) {
				startTransparency = 0.0f;
			}
			if (textureChangeTime_ > SECOND_) {
				textureChangeTime_ = 0;
			}
		}
		//スペースを押したらSelectになる
		if (input_->GetInstance()->IsTriggerKey(DIK_SPACE) == true) {
			titleBGM_->StopWave(titleSoundData_);
			startSE_->PlayWave(startSESoundData_, false);

			isFadeout_ = true;
		}

		XINPUT_STATE joyState{};

		if (Input::GetInstance()->GetJoystickState(joyState)) {

			if (joyState.Gamepad.wButtons & XINPUT_GAMEPAD_A) {
				triggerButtonATime_ += 1;
			
			}

		}

		if (triggerButtonATime_ == 1) {
			titleBGM_->StopWave(titleSoundData_);
			startSE_->PlayWave(startSESoundData_, false);



			isFadeout_ = true;
		}


	}
	

	

	if (isFadeout_ == true) {
		
		startFlashTime_ += 1;
		//点滅処理
		if (startFlashTime_ > FLASH_INTERVAL * 0) {
			if (startFlashTime_ > FLASH_INTERVAL * 0 && startFlashTime_ <= FLASH_INTERVAL * 1 ) {
				startTransparency = 0.0f;
			}
			if (startFlashTime_ > FLASH_INTERVAL * 1 && startFlashTime_ <= FLASH_INTERVAL * 2 ) {
				startTransparency = 1.0f;
			}
			if (startFlashTime_ > FLASH_INTERVAL * 2 && startFlashTime_ <= FLASH_INTERVAL * 3 ) {
				startTransparency = 0.0f;
			}
			if (startFlashTime_ > FLASH_INTERVAL * 3 && startFlashTime_ <= FLASH_INTERVAL * 4 ) {
				startTransparency = 1.0f;
			}
			if (startFlashTime_ > FLASH_INTERVAL * 4 && startFlashTime_ <= FLASH_INTERVAL * 5 ) {
				startTransparency = 0.0f;
			}
			if (startFlashTime_ > FLASH_INTERVAL * 5 && startFlashTime_ <= FLASH_INTERVAL * 6 ) {
				startTransparency = 1.0f;
			}
			if (startFlashTime_ > FLASH_INTERVAL * 6 && startFlashTime_ <= FLASH_INTERVAL * 7 ) {
				startTransparency = 0.0f;
			}
			if (startFlashTime_ > FLASH_INTERVAL * 7 && startFlashTime_ <= FLASH_INTERVAL * 8 ) {
				startTransparency = 1.0f;
			}
			if (startFlashTime_ > FLASH_INTERVAL * 8 && startFlashTime_ <= FLASH_INTERVAL * 9 ) {
				startTransparency = 0.0f;
			}


			if (startFlashTime_ > FLASH_INTERVAL * 9 ) {

				
				//フェードアウト
				textureTransparency -= 0.01f;
				if (textureTransparency < 0.0f) {
					waitingTime_ += 1;
					textureTransparency = 0.0f;
					startTransparency = 0.0f;
					
					if (waitingTime_ > SECOND_ * 3) {
						
						gameManager->ChangeScene(new SelectScene());
					}
					
				}		
			}


		}

		
	}
	

}

/// 描画
void TitleScene::Draw(GameManager* gameManager) {

	//下地
	titleSprite_->DrawRect(transformSprite_);
	//スタート
	startSprite_->DrawRect(transformSprite_);
	
	//雲の動き
	for (int i = 0; i < CLOUD_AMOUNT_; i++) {
		cloudSprite_[i]->DrawRect(cloudTransform_[i]);

	}
	
	//キャラクター
	characterSprite_->DrawRect(characterTransform_);

}

