#include "TitleScene.h"
#include "AllGameScene/SelectScene/SelectScene.h"

//コンストラクタ
TitleScene::TitleScene() {
	//input_ = Input::GetInstance();
}

/// デストラクタ
TitleScene::~TitleScene() {
	
}

/// 初期化
void TitleScene::Initialize(GameManager* gameManager) {
	//input_->Initialize();


	uint32_t titleTextureHandle = TextureManager::LoadTexture("Resources/Title/Texture/Title.png");
	uint32_t startTextureHandle= TextureManager::LoadTexture("Resources/Title/Texture/TitleStart.png");


	transformSprite_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{0.0f,0.0f,0.0f} };

	titleSprite = new Sprite();
	titleSprite->LoadTextureHandle(titleTextureHandle);
	spriteAllPosition_ = { {0.0f,0.0f},{0.0f,720.0f},{1280.0f,0.0f},{1280.0f,720.0f} };
	titleSprite->SetAllPosition(spriteAllPosition_);

	
	startSprite = new Sprite();
	startSprite->LoadTextureHandle(startTextureHandle);
	spriteAllPosition2_ = { {0.0f,0.0f},{0.0f,720.0f},{1280.0f,0.0f},{1280.0f,720.0f} };
	startSprite->SetAllPosition(spriteAllPosition2_);




	titleBGM_ = Audio::GetInstance();
	titleBGM_->Initialize();
	titleSoundData_ = titleBGM_->LoadWave("Resources/Title/Music/TitleBGM.wav");


	titleBGM_->PlayWave(titleSoundData_ ,true);
	


}

/// 更新
void TitleScene::Update(GameManager* gameManager) {


	//スペースキーかAボタンでスタートのシーン
	if (isFadeout_ == false) {
		//透明度の変更
		
		startSprite->SetTransparency(startTransparency);
		

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
		titleTransparency -= 0.01f;
		if (titleTransparency < 0.0f) {
			waitingTime_ += 1;

			if (waitingTime_ > SECOND_ * 3) {
				gameManager->ChangeScene(new SelectScene());
			}
			
		}
	}
	titleSprite->SetTransparency(titleTransparency);

	ImGui::Begin("transparency");
	ImGui::InputFloat("titleSprite", &titleTransparency);
	ImGui::End();

}

/// 描画
void TitleScene::Draw(GameManager* gameManager) {

	//下地
	titleSprite->DrawRect(transformSprite_);
	//スタート
	startSprite->DrawRect(transformSprite_);
	

	
}

