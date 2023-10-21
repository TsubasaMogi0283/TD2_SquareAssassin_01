#include "AllGameScene/ResultScene/ResultScene.h"

//コンストラクタ
ResultScene::ResultScene() {

}

/// デストラクタ
ResultScene::~ResultScene() {

}

/// 初期化
void ResultScene::Initialize(GameManager* gameManager) {
	#pragma region 背景
	
	backSprite = new Sprite();
	backTransform_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{0.0f,0.0f,0.0f} };
	uint32_t selectTextureHandle = TextureManager::LoadTexture("Resources/Result/Texture/Back.png");
	backSprite->LoadTextureHandle(selectTextureHandle);
	backAllPosition_ = { {0.0f,0.0f},{0.0f,720.0f},{1280.0f,0.0f},{1280.0f,720.0f} };
	backSprite->SetAllPosition(backAllPosition_);

#pragma endregion

#pragma region 数字
	//32x64
	for (int i = 0; i < NUMBER_AMOUNT_; i++) {
		numberSprite_[i] =new Sprite();
		numberAllPosition_[i] = { {0.0f,0.0f},{0.0f,64.0f},{32.0f,0.0f},{32.0f,64.0f} };
	
	}

	uint32_t numberTextureHandle[NUMBER_AMOUNT_];
	numberTextureHandle[0]=TextureManager::LoadTexture("Resources/Result/Texture/Number/0.png");
	numberTextureHandle[1]=TextureManager::LoadTexture("Resources/Result/Texture/Number/1.png");
	numberTextureHandle[2]=TextureManager::LoadTexture("Resources/Result/Texture/Number/2.png");
	numberTextureHandle[3]=TextureManager::LoadTexture("Resources/Result/Texture/Number/3.png");
	numberTextureHandle[4]=TextureManager::LoadTexture("Resources/Result/Texture/Number/4.png");
	numberTextureHandle[5]=TextureManager::LoadTexture("Resources/Result/Texture/Number/5.png");
	numberTextureHandle[6]=TextureManager::LoadTexture("Resources/Result/Texture/Number/6.png");
	numberTextureHandle[7]=TextureManager::LoadTexture("Resources/Result/Texture/Number/7.png");
	numberTextureHandle[8]=TextureManager::LoadTexture("Resources/Result/Texture/Number/8.png");
	numberTextureHandle[9]=TextureManager::LoadTexture("Resources/Result/Texture/Number/9.png");



	Transform numberTransform_ = {};


	//スコア

#pragma endregion

}

void ResultScene::ImGuiDebug() {

}

/// 更新
void ResultScene::Update(GameManager* gameManager) {

}

/// 描画
void ResultScene::Draw(GameManager* gameManager) {
	backSprite->DrawRect(backTransform_);
}




