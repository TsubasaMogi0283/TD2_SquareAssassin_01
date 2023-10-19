#include "TitleScene.h"
#include "AllGameScene/SelectScene/SelectScene.h"

//コンストラクタ
TitleScene::TitleScene() {
	//input_ = Input::GetInstance();
}

/// デストラクタ
TitleScene::~TitleScene() {
	delete titleSprite;
	delete startSprite;
}

/// 初期化
void TitleScene::Initialize(GameManager* gameManager) {
	//input_->Initialize();


	uint32_t titleTextureHandle = TextureManager::LoadTexture("Resources/Title/Texture/Base/TitleLogo.png");
	uint32_t startTextureHandle= TextureManager::LoadTexture("Resources/Title/Texture/Start/Start.png");
	uint32_t cloudTextureHandle = TextureManager::LoadTexture("Resources/Title/Texture/Cloud/Cloud.png");

	transformSprite_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{0.0f,0.0f,0.0f} };

	titleSprite = new Sprite();
	titleSprite->LoadTextureHandle(titleTextureHandle);
	spriteAllPosition_ = { {0.0f,0.0f},{0.0f,720.0f},{1280.0f,0.0f},{1280.0f,720.0f} };
	titleSprite->SetAllPosition(spriteAllPosition_);

	
	startSprite = new Sprite();
	startSprite->LoadTextureHandle(startTextureHandle);
	spriteAllPosition2_ = { {0.0f,0.0f},{0.0f,720.0f},{1280.0f,0.0f},{1280.0f,720.0f} };
	startSprite->SetAllPosition(spriteAllPosition2_);


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
	
	Transform cloudTransform_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{0.0f,0.0f,0.0f}};




	titleBGM_ = Audio::GetInstance();
	titleBGM_->Initialize();
	titleSoundData_ = titleBGM_->LoadWave("Resources/Title/Music/TitleBGM.wav");


	titleBGM_->PlayWave(titleSoundData_ ,true);
	


}

/// 更新
void TitleScene::Update(GameManager* gameManager) {
	startSprite->SetTransparency(startTransparency);
	titleSprite->SetTransparency(titleTransparency);

	ImGui::Begin("transparency");
	ImGui::InputFloat("titleSprite", &titleTransparency);
	ImGui::InputInt("waitingTime_",&waitingTime_);
	
	ImGui::End();
	
	//スペースキーかAボタンでスタートのシーン
	if (isFadeout_ == false) {
		
		//雲の動き
		for (int i = 0; i < CLOUD_AMOUNT_; i++) {
			cloudTransform_[i].translate = Add(cloudTransform_[i].translate,cloudSpeed_);

			//ループ処理
			if (cloudTransform_[i].translate.x > 1280.0f) {
				cloudTransform_[i].translate.x = -256.0f;
			}

		}
		
		
		
		

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
				titleTransparency -= 0.01f;
				if (titleTransparency < 0.0f) {
					waitingTime_ += 1;
					titleTransparency = 0.0f;
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
	titleSprite->DrawRect(transformSprite_);
	//スタート
	startSprite->DrawRect(transformSprite_);
	
	//雲の動き
	for (int i = 0; i < CLOUD_AMOUNT_; i++) {
		cloudSprite_[i]->DrawRect(cloudTransform_[i]);

	}
	
}

