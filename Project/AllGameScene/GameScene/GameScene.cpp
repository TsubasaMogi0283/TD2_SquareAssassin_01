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

	player_ = std::make_unique<Player>();
	player_->Initialize();
	//敵の初期化
	enemy_[0] = new Enemy;
	enemy_[1] = new Enemy;
	enemy_[2] = new Enemy;
	enemy_[3] = new Enemy;
	enemy_[4] = new Enemy;
	enemy_[5] = new Enemy;

	enemy_[0]->Initialize( -22, 0, -0.5f, 0.05f);
	enemy_[1]->Initialize( 10, -10, 0.5f, -0.5f);
	enemy_[2]->Initialize( -23, -20, -0.5f, -0.5f);
	enemy_[3]->Initialize( 0, 0, 0.5f, 0.5f);
	enemy_[4]->Initialize( -30, -10, -0.5f, 0.5f);
	enemy_[5]->Initialize( 20, 5, 0.5f, -0.5f);

}

void GameScene::Play() {
	player_->Update();
	for (int i = 0; i < 6; i++) {
		enemy_[i]->Update();
	}
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
		Play();
	}


	if (waitingTime_ > SECOND_ * 3) {
		gameManager->ChangeScene(new TutorialScene());
	}
	

	
}

/// 描画
void GameScene::Draw(GameManager* gameManager) {
	//gameSprite_->DrawRect(selectSpriteTransform_);
	player_->Draw();
	for (int i = 0; i < 6; i++) {
		enemy_[i]->Draw();
	}
}


/// デストラクタ
GameScene::~GameScene() {
	delete gameSprite_;
}