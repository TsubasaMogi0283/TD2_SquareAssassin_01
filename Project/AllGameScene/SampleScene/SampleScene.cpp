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
	

	textureManager_ = TextureManager::GetInstance();
	
	//TextureHandleはそれぞれ違う値になっているのに何故
	textureHandle_ = textureManager_->LoadTexture("Resources/uvChecker.png");
	textureHandle2_=textureManager_->LoadTexture("Resources/monsterBall.png");
	transformSprite_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{0.0f,0.0f,0.0f} };
	
	sprite_ = new Sprite();
	sprite_->LoadTextureHandle(textureHandle_);
	spriteAllPosition_ = { {0.0f,0.0f},{0.0f,512.0f},{512.0f,0.0f},{512.0f,512.0f} };
	sprite_->SetAllPosition(spriteAllPosition_);

	transformSprite2_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{500.0f,0.0f,0.0f} };
	
	sprite2_ = new Sprite();
	sprite2_->LoadTextureHandle(textureHandle2_);
	spriteAllPosition_ = { {0.0f,0.0f},{0.0f,512.0f},{512.0f,0.0f},{512.0f,512.0f} };
	sprite2_->SetAllPosition(spriteAllPosition_);

	


	audio_ = Audio::GetInstance();
	audio_->Initialize();
	soundData_ = audio_->LoadWave("Resources/Audio/Sample/Hit.wav");


	//audio_->PlayWave(soundData_ ,true);
	

	
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
	sprite2_->DrawRect(transformSprite2_);
}
