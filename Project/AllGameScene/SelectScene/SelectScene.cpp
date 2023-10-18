#include "SelectScene.h"

//コンストラクタ
SelectScene::SelectScene() {

}

/// 初期化
void SelectScene::Initialize(GameManager* gameManager) {
	uint32_t selectTextureHandle = TextureManager::LoadTexture("Resources/Select/Texture/SelectTexture.png");

	selectSpriteTransform_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{0.0f,0.0f,0.0f} };

	selectSprite = new Sprite();
	selectSprite->LoadTextureHandle(selectTextureHandle);
	spriteAllPosition_ = { {0.0f,0.0f},{0.0f,720.0f},{1280.0f,0.0f},{1280.0f,720.0f} };
	selectSprite->SetAllPosition(spriteAllPosition_);



	ImGui::Begin("Select");
	ImGui::Text("Space To GameScene");

	ImGui::End();


}

/// 更新
void SelectScene::Update(GameManager* gameManager) {

}

/// 描画
void SelectScene::Draw(GameManager* gameManager) {
	selectSprite->DrawRect(selectSpriteTransform_);
}


/// デストラクタ
SelectScene::~SelectScene() {
	delete selectSprite;
}