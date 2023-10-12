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
	

	//textureManager_ = TextureManager::GetInstance();
	//
	// 
	// 
	// 

	////TextureHandleはそれぞれ違う値になっているのに何故
	//uint32_t textureHandle_ = TextureManager::LoadTexture("Resources/uvChecker.png");
	//uint32_t textureHandle2_= TextureManager::LoadTexture("Resources/monsterBall.png");
	//uint32_t textureHandle3_= TextureManager::LoadTexture("Resources/bullet.png");


	//transformSprite_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{0.0f,0.0f,0.0f} };
	//
	//sprite_ = new Sprite();
	//sprite_->LoadTextureHandle(textureHandle_);
	//spriteAllPosition_ = { {0.0f,0.0f},{0.0f,512.0f},{512.0f,0.0f},{512.0f,512.0f} };
	//sprite_->SetAllPosition(spriteAllPosition_);

	//transformSprite2_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{500.0f,0.0f,0.0f} };
	//
	//sprite2_ = new Sprite();
	//sprite2_->LoadTextureHandle(textureHandle2_);
	//spriteAllPosition2_ = { {0.0f,0.0f},{0.0f,512.0f},{512.0f,0.0f},{512.0f,512.0f} };
	//sprite2_->SetAllPosition(spriteAllPosition2_);

	//

	//transformSprite3_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{1000.0f,0.0f,0.0f} };
	//
	//sprite3_ = new Sprite();
	//sprite3_->LoadTextureHandle(textureHandle3_);
	//spriteAllPosition3_ = { {0.0f,0.0f},{0.0f,16.0f},{16.0f,0.0f},{16.0f,16.0f} };
	//sprite3_->SetAllPosition(spriteAllPosition3_);




	//transformModel_ = {{1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{0.0f,0.0f,0.0f}};
	//plane_ = new Model();
	//plane_->CreateObject("Resources/Sample", "enemy.obj");
	//
	//

	//audio_ = Audio::GetInstance();
	//audio_->Initialize();
	//soundData_ = audio_->LoadWave("Resources/Audio/Sample/Hit.wav");


	//audio_->PlayWave(soundData_ ,true);

	plane_ = new Model();
	plane_->CreateObject("Resources/05_02", "enemy.obj");
	plane_->LoadTexture("Resources/05_02/enemy.png");
	transformModel_ = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{0.0f,0.0f,0.0f} };
	cameraTransform_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{0.0f,0.0f,-9.8f} };


	
}

/// <summary>
/// 更新
/// </summary>
void SampleScene::Update(GameManager* gameManager) {

	sampleTimer_ += 1;
	if (sampleTimer_ >30) {
		//audio_->StopWave(soundData_);
	}
	if (sampleTimer_ > 120) {
		gameManager->ChangeScene(new SampleScene2());
	}
	
	ImGui::Begin("SampleScene1");
	ImGui::Text("Time",sampleTimer_);
	ImGui::End();


	ImGui::Begin("Sprite");
	ImGui::InputFloat3("scale", &transformSprite_.scale.x);
	ImGui::SliderFloat3("scale", &transformSprite_.scale.x,0.0f,10.0f);
	ImGui::End();

	ImGui::Begin("Model");
	ImGui::InputFloat3("translate", &transformModel_.translate.x);
	ImGui::SliderFloat3("translate", &transformModel_.translate.x,-10.0f,10.0f);
	ImGui::End();
}

/// <summary>
/// 描画
/// </summary>
void SampleScene::Draw(GameManager* gameManager) {
	plane_->Draw(transformModel_);
	sprite_->DrawRect(transformSprite_);
	//sprite2_->DrawRect(transformSprite2_);
	sprite3_->DrawRect(transformSprite3_);

}
