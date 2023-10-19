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
	//audio_->SoundUnload(&soundData_);
	////delete sprite_;
	////delete sprite2_;
	////delete sprite3_;
	////plane_->Release();
	////delete plane_;

	//audio_->DeleteInstance();;


	for (int i = 0; i < 20; i++) {
		enemy_[i]->Release();
	}

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
	//uint32_t textureHandle_ = TextureManager::LoadTexture("Resources/uvChecker.png");
	//uint32_t textureHandle2_= TextureManager::LoadTexture("Resources/monsterBall.png");
	//uint32_t textureHandle3_= TextureManager::LoadTexture("Resources/bullet.png");


	//transformSprite_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{0.0f,0.0f,0.0f} };
	//
	//sprite_ = new Sprite();
	//sprite_->LoadTextureHandle(textureHandle_);
	//spriteAllPosition_ = { {0.0f,0.0f},{0.0f,512.0f},{512.0f,0.0f},{512.0f,512.0f} };
	//sprite_->SetAllPosition(spriteAllPosition_);

	//transformSprite2_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{300.0f,0.0f,0.0f} };
	//
	//sprite2_ = new Sprite();
	//sprite2_->LoadTextureHandle(textureHandle2_);
	//spriteAllPosition2_ = { {0.0f,0.0f},{0.0f,512.0f},{512.0f,0.0f},{512.0f,512.0f} };
	//sprite2_->SetAllPosition(spriteAllPosition2_);

	//

	//transformSprite3_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{800.0f,0.0f,0.0f} };
	//
	////sprite3_ = new Sprite();
	////sprite3_->LoadTextureHandle(textureHandle3_);
	////spriteAllPosition3_ = { {0.0f,0.0f},{0.0f,16.0f},{16.0f,0.0f},{16.0f,16.0f} };
	////sprite3_->SetAllPosition(spriteAllPosition3_);




	//transformModel_ = {{1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{0.0f,0.0f,0.0f}};
	////plane_ = new Model();
	/////plane_->CreateObject("Resources/Sample", "enemy.obj");
	//
	//

	//audio_ = Audio::GetInstance();
	//audio_->Initialize();
	//soundData_ = audio_->LoadWave("Resources/Audio/Sample/Hit.wav");


	//audio_->PlayWave(soundData_ ,true);
	//
	/////////////////////////////




	move_[0] = { -0.06f, 0.06f, 0 };
	move_[1] = { 0.06f, 0.06f, 0 };
	move_[2] = { -0.06f, 0.04f, 0 };
	move_[3] = { -0.06f, -0.04f, 0 };
	move_[4] = { 0.06f, -0.06f, 0 };
	move_[5] = { -0.06f, -0.06f, 0 };
	move_[6] = { -0.06f, 0.06f, 0 };
	move_[7] = { 0.06f, 0.06f, 0 };
	move_[8] = { -0.06f, 0.04f, 0 };
	move_[9] = { -0.06f, -0.04f, 0 };
	move_[10] = { 0.06f, -0.06f, 0 };
	move_[11] = { -0.06f, -0.06f, 0 };
	move_[12] = { -0.06f, 0.06f, 0 };
	move_[13] = { 0.06f, 0.06f, 0 };
	move_[14] = { -0.06f, 0.04f, 0 };
	move_[15] = { -0.06f, -0.04f, 0 };
	move_[16] = { 0.06f, -0.06f, 0 };
	move_[17] = { -0.06f, -0.06f, 0 };
	move_[18] = { -0.06f, -0.06f, 0 };
	move_[19] = { -0.06f, -0.06f, 0 };


	transformModel_[0] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{-1.0f,-1.0f,0.0f} };
	transformModel_[1] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{1.0f,-2.0f,0.0f} };
	transformModel_[2] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{-2.0f,2.0f,0.0f} };
	transformModel_[3] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{3.0f,1.0f,0.0f} };
	transformModel_[4] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{2.0f,2.0f,0.0f} };
	transformModel_[5] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{-3.0f,-1.0f,0.0f} };
	transformModel_[6] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{-3.0f,-1.0f,0.0f} };
	transformModel_[7] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{-3.0f,-1.0f,0.0f} };
	transformModel_[8] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{-3.0f,-1.0f,0.0f} };
	transformModel_[9] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{-3.0f,-1.0f,0.0f} };
	transformModel_[10] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{-2.1f,-1.0f,0.0f} };
	transformModel_[11] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{-2.2f,-1.0f,0.0f} };
	transformModel_[12] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{-1.3f,-0.9f,0.0f} };
	transformModel_[13] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{-2.4f,-1.8f,0.0f} };
	transformModel_[14] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{-3.0f,-0.7f,0.0f} };
	transformModel_[15] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{-2.6f,-1.6f,0.0f} };
	transformModel_[16] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{-2.7f,-1.5f,0.0f} };
	transformModel_[17] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{-1.8f,-2.4f,0.0f} };
	transformModel_[18] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{-2.9f,-0.3f,0.0f} };
	transformModel_[19] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{-2.0f,-1.2f,0.0f} };

	for (int i = 0; i < 20; i++) {

		enemy_[i] = new Enemy;
		enemy_[i]->Initialize("Resources/05_02", "enemy.obj", transformModel_[i], move_[i]);
	}
	
}

/// <summary>
/// 更新
/// </summary>
void SampleScene::Update(GameManager* gameManager) {

	//sampleTimer_ += 1;
	//if (sampleTimer_ >30) {
	//	//audio_->StopWave(soundData_);
	//}
	//if (sampleTimer_ > 120) {
	//	//gameManager->ChangeScene(new SampleScene2());
	//}
	//
	//sprite_->SetTransparency(transparency1);
	//sprite2_->SetTransparency(transparency2);


	//ImGui::Begin("SampleScene1");
	//ImGui::Text("Time",sampleTimer_);
	//ImGui::End();


	//ImGui::Begin("Sprite");
	//ImGui::InputFloat3("scale", &transformSprite_.scale.x);
	//ImGui::SliderFloat3("scale", &transformSprite_.scale.x,0.0f,10.0f);
	//
	//ImGui::InputFloat("transparency", &transparency1);
	//ImGui::SliderFloat("transparency", &transparency1, 0.0f, 1.0f);
	//ImGui::End();

	//ImGui::Begin("Sprite2");
	//ImGui::InputFloat("transparency", &transparency2);
	//ImGui::SliderFloat("transparency", &transparency2, 0.0f, 1.0f);
	//ImGui::End();


	//ImGui::Begin("Model");
	//ImGui::InputFloat3("translate", &transformModel_.translate.x);
	//ImGui::SliderFloat3("translate", &transformModel_.translate.x,-10.0f,10.0f);
	//ImGui::End();


	for (int i = 0; i < 20; i++) {
		enemy_[i]->Update();
	}
}

/// <summary>
/// 描画
/// </summary>
void SampleScene::Draw(GameManager* gameManager) {
	//plane_->Draw(transformModel_);
	//sprite_->DrawRect(transformSprite_);
	//sprite2_->DrawRect(transformSprite2_);
	////sprite3_->DrawRect(transformSprite3_);
	for (int i = 0; i < 20; i++) {
		enemy_[i]->Dorw();
	}
}
