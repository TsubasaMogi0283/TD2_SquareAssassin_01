#include "GameScene.h"
#include "AllGameScene/TutorialScene/TutorialScene.h"

//コンストラクタ
GameScene::GameScene() {

}

/// 初期化
void GameScene::Initialize(GameManager* gameManager) {
	uint32_t selectTextureHandle = TextureManager::LoadTexture("Resources/Select/Texture/SelectTexture.png");

	selectSpriteTransform_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{0.0f,0.0f,0.0f} };

	gameSprite_ = new Sprite();
	gameSprite_->LoadTextureHandle(selectTextureHandle);
	spriteAllPosition_ = { {0.0f,0.0f},{0.0f,720.0f},{1280.0f,0.0f},{1280.0f,720.0f} };
	gameSprite_->SetAllPosition(spriteAllPosition_);


	

}

void GameScene::Play() {

}

/// 更新
void GameScene::Update(GameManager* gameManager) {

	ImGui::Begin("Select");
	ImGui::Text("1 To GameScene");
	ImGui::Text("2 To GameScene");


	ImGui::End();


	gameSprite_->SetTransparency(gameTextureTransparency_);

	//フェードイン
	if (isFadeIn_ == true) {
		gameTextureTransparency_ += 0.01f;
		if (gameTextureTransparency_ > 1.0f) {
			gameTextureTransparency_ = 1.0f;
			isFadeIn_ = false;
		}
	
	}
	



	//選択画面
	if (isFadeIn_ == false) {
		
		
	}


	if (waitingTime_ > SECOND_ * 3) {
		gameManager->ChangeScene(new TutorialScene());
	}
	

	
}

/// 描画
void GameScene::Draw(GameManager* gameManager) {
	gameSprite_->DrawRect(selectSpriteTransform_);
}


/// デストラクタ
GameScene::~GameScene() {
	delete gameSprite_;
}