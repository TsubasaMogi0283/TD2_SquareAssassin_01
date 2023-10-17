#include "TitleScene.h"

//コンストラクタ
TitleScene::TitleScene() {

}

/// デストラクタ
TitleScene::~TitleScene() {

}

/// 初期化
void TitleScene::Initialize(GameManager* gameManager) {
	uint32_t titleTextureHandle = TextureManager::LoadTexture("Resources/Title/Texture/Title.png");
	uint32_t startTextureHandle= TextureManager::LoadTexture("Resources/Title/Texture/TitleStart.png");


	transformSprite_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{0.0f,0.0f,0.0f} };

	titleSprite = new Sprite();
	titleSprite->LoadTextureHandle(titleTextureHandle);
	spriteAllPosition_ = { {0.0f,0.0f},{0.0f,720.0f},{1280.0f,0.0f},{1280.0f,720.0f} };
	titleSprite->SetAllPosition(spriteAllPosition_);

	transformSprite2_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{0.0f,0.0f,0.0f} };
	
	startSprite = new Sprite();
	startSprite->LoadTextureHandle(startTextureHandle);
	spriteAllPosition2_ = { {0.0f,0.0f},{0.0f,720.0f},{1280.0f,0.0f},{1280.0f,720.0f} };
	startSprite->SetAllPosition(spriteAllPosition2_);


	titleBGM_ = Audio::GetInstance();
	titleBGM_->Initialize();
	soundData_ = titleBGM_->LoadWave("Resources/Audio/Sample/Hit.wav");


	titleBGM_->PlayWave(soundData_ ,true);
	


}

/// 更新
void TitleScene::Update(GameManager* gameManager) {

	startSprite->SetTransparency(startTransparency);
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
	

	//Aかスペースキーでスタート



}

/// 描画
void TitleScene::Draw(GameManager* gameManager) {
	//下地
	titleSprite->DrawRect(transformSprite_);
	//スタート
	startSprite->DrawRect(transformSprite2_);
}

