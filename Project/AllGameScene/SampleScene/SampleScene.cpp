#include "SampleScene.h"
#include "AllGameScene/SampleScene2/SampleScene2.h"

/// <summary>
	/// コンストラクタ
	/// </summary>
SampleScene::SampleScene() {

}

/// <summary>
/// デストラクタ
/// </summary>
SampleScene::~SampleScene() {
	//sprite_->Release();
	audio_->SoundUnload(&soundData_);
	delete sprite_;
}

/// <summary>
/// 初期化
/// </summary>
void SampleScene::Initialize(GameManager* gameManager) {
	sprite_ = new Sprite();
	//sprite_->Initialize();
	sprite_->LoadTexture("Resources/uvChecker.png");

	transformSprite_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{0.0f,0.0f,0.0f} };
	spriteAllPosition_ = { {0.0f,0.0f},{0.0f,512.0f},{512.0f,0.0f},{512.0f,512.0f} };
	sprite_->SetAllPosition(spriteAllPosition_);


	audio_ = Audio::GetInstance();
	audio_->Initialize();
	soundData_ = audio_->LoadWave("Resources/Audio/Sample/Hit.wav");


	audio_->PlayWave(soundData_ ,true);
	

	
}

/// <summary>
/// 更新
/// </summary>
void SampleScene::Update(GameManager* gameManager) {

	sampleTimer_ += 1;
	
	
	ImGui::Begin("SampleScene1");
	ImGui::Text("Time",sampleTimer_);
	ImGui::End();


	ImGui::Begin("Sprite");
	ImGui::InputFloat3("scale", &transformSprite_.scale.x);
	ImGui::SliderFloat3("scale", &transformSprite_.scale.x,0.0f,10.0f);
	ImGui::End();

}

/// <summary>
/// 描画
/// </summary>
void SampleScene::Draw(GameManager* gameManager) {
	sprite_->DrawRect(transformSprite_);
}
