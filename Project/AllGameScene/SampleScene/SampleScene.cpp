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
	float x = 1280.0f;
	float y = 720.0f;


	sprite_ = new Sprite();
	//sprite_->Initialize();
	sprite_->LoadTexture("Resources/hai.png");

	transformSprite_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{0.0f,0.0f,0.0f} };
	spriteAllPosition_ = { {0.0f,0.0f},{0.0f,y},{x,0.0f},{x,y} };
	sprite_->SetAllPosition(spriteAllPosition_);

	plane_ = new Model();
	plane_->CreateObject("Resources/05_02", "axis.obj");
	plane_->LoadTexture("Resources/05_02/uvChecker.png");
	transformModel_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{0.0f,0.0f,0.0f} };
	cameraTransform_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{0.0f,0.0f,-9.8f} };

	/*audio_ = Audio::GetInstance();
	audio_->Initialize();
	soundData_ = audio_->LoadWave("Resources/Audio/Sample/Hit.wav");


	audio_->PlayWave(soundData_ ,true);
	

	*/
}

/// <summary>
/// 更新
/// </summary>
void SampleScene::Update(GameManager* gameManager) {

	sampleTimer_ += 1;
	//カメラ行列
	cameraMatrix_ = MakeAffineMatrix(cameraTransform_.scale, cameraTransform_.rotate, cameraTransform_.translate);
	viewMatrix_ = Inverse(cameraMatrix_);

	//遠視投影行列
	projectionMatrix_ = MakePerspectiveFovMatrix(0.45f, float(DirectXSetup::GetInstance()->GetClientWidth()) / float(DirectXSetup::GetInstance()->GetClientHeight()), 0.1f, 100.0f);



	
	ImGui::Begin("SampleScene1");
	ImGui::Text("Time",sampleTimer_);
	ImGui::End();

}

/// <summary>
/// 描画
/// </summary>
void SampleScene::Draw(GameManager* gameManager) {
	sprite_->DrawRect(transformSprite_);

	sprite_->DrawRect(transformSprite_);
}
