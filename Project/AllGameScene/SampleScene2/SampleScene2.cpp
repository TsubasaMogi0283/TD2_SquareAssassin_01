#include "SampleScene2.h"

/// <summary>
	/// コンストラクタ
	/// </summary>
SampleScene2::SampleScene2() {

}

/// <summary>
/// デストラクタ
/// </summary>
SampleScene2::~SampleScene2() {
	//sprite_->Release();
	audio_->SoundUnload(soundData_);

	delete sprite_;
}

/// <summary>
/// 初期化
/// </summary>
void SampleScene2::Initialize(GameManager* gameManager) {
	textureManager_ = TextureManager::GetInstance();
	
	//TextureHandleはそれぞれ違う値になっているのに何故
	uint32_t textureHandle_ = TextureManager::LoadTexture("Resources/monsterBall.png");
	uint32_t textureHandle2_= TextureManager::LoadTexture("Resources/uvChecker.png");
	uint32_t textureHandle3_= TextureManager::LoadTexture("Resources/bullet.png");


	transformSprite_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{0.0f,0.0f,0.0f} };
	
	sprite_ = new Sprite();
	sprite_->LoadTextureHandle(textureHandle_);
	spriteAllPosition_ = { {0.0f,0.0f},{0.0f,512.0f},{512.0f,0.0f},{512.0f,512.0f} };
	sprite_->SetAllPosition(spriteAllPosition_);

	transformSprite2_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{500.0f,0.0f,0.0f} };
	
	sprite2_ = new Sprite();
	sprite2_->LoadTextureHandle(textureHandle2_);
	spriteAllPosition2_ = { {0.0f,0.0f},{0.0f,512.0f},{512.0f,0.0f},{512.0f,512.0f} };
	sprite2_->SetAllPosition(spriteAllPosition2_);

	

	transformSprite3_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{1000.0f,0.0f,0.0f} };
	
	sprite3_ = new Sprite();
	sprite3_->LoadTextureHandle(textureHandle3_);
	spriteAllPosition3_ = { {0.0f,0.0f},{0.0f,16.0f},{16.0f,0.0f},{16.0f,16.0f} };
	sprite3_->SetAllPosition(spriteAllPosition3_);

	

	

	audio_ = Audio::GetInstance();
	audio_->Initialize();
	soundData_ = audio_->LoadWave("Resources/Audio/Sample/Win.wav");


	audio_->PlayWave(soundData_ ,true);
	


	
}

/// <summary>
/// 更新
/// </summary>
void SampleScene2::Update(GameManager* gameManager) {
	ImGui::Begin("SampleScene2");
	
	ImGui::End();
}

/// <summary>
/// 描画
/// </summary>
void SampleScene2::Draw(GameManager* gameManager) {
	sprite_->DrawRect(transformSprite_);
	sprite2_->DrawRect(transformSprite2_);
	sprite3_->DrawRect(transformSprite3_);

}
