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
	audio_->SoundUnload(&soundData_);
	audio_->DeleteInstance();

	delete sprite_;
}

/// <summary>
/// 初期化
/// </summary>
void SampleScene2::Initialize(GameManager* gameManager) {
	textureManager_ = TextureManager::GetInstance();
	
	//TextureHandleはそれぞれ違う値になっているのに何故
	//シーン変えると表示されなくなった
	textureHandle_ = TextureManager::LoadTexture("Resources/monsterBall.png");

	sprite_ = new Sprite();

	transformSprite_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{0.0f,0.0f,0.0f} };
	spriteAllPosition_ = { {0.0f,0.0f},{0.0f,512.0f},{512.0f,0.0f},{512.0f,512.0f} };
	sprite_->SetAllPosition(spriteAllPosition_);

	sprite_->LoadTextureHandle(textureHandle_);


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
	ImGui::InputFloat3("traslate_", &transformSprite_.translate.x);
	ImGui::SliderFloat3("traslate_", &transformSprite_.translate.x,0.0f,1000.0f);

	ImGui::End();
}

/// <summary>
/// 描画
/// </summary>
void SampleScene2::Draw(GameManager* gameManager) {
	sprite_->DrawRect(transformSprite_);
}
