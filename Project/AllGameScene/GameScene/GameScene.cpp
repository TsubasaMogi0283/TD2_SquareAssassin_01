#include "GameScene.h"
#include "AllGameScene/TutorialScene/TutorialScene.h"

//コンストラクタ
GameScene::GameScene() {

}

/// 初期化
void GameScene::Initialize(GameManager* gameManager) {
	




#pragma region 敵

	

	move_[0] =  { -0.06f,  0.06f, 0 };
	move_[1] =  {  0.06f,  0.06f, 0 };
	move_[2] =  { -0.06f,  0.04f, 0 };
	move_[3] =  { -0.06f, -0.04f, 0 };
	move_[4] =  {  0.06f, -0.06f, 0 };
	move_[5] =  { -0.06f, -0.06f, 0 };
	move_[6] =  { -0.06f,  0.06f, 0 };
	move_[7] =  {  0.06f,  0.06f, 0 };
	move_[8] =  { -0.06f,  0.04f, 0 };
	move_[9] =  { -0.06f, -0.04f, 0 };
	move_[10] = {  0.06f, -0.06f, 0 };
	move_[11] = { -0.06f, -0.06f, 0 };
	move_[12] = { -0.06f,  0.06f, 0 };
	move_[13] = {  0.06f,  0.06f, 0 };
	move_[14] = { -0.06f,  0.04f, 0 };
	move_[15] = { -0.06f, -0.04f, 0 };
	move_[16] = {  0.09f, -0.03f, 0 };
	move_[17] = { -0.06f, -0.06f, 0 };
	move_[18] = { -0.06f, -0.06f, 0 };
	move_[19] = { -0.06f, -0.06f, 0 };


	transformModel_[0] =  { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{ 1.0f,1.0f,0.0f} };
	transformModel_[1] =  { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{-1.0f,1.5f,0.0f} };
	transformModel_[2] =  { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{-1.0f,1.0f,0.0f} };
	transformModel_[3] =  { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{ 1.5f,1.5f,0.0f} };
	transformModel_[4] =  { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{ 1.5f,1.0f,0.0f} };
	transformModel_[5] =  { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{-1.5f,1.5f,0.0f} };
	transformModel_[6] =  { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{-2.0f,1.0f,0.0f} };
	transformModel_[7] =  { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{ 2.0f,1.5f,0.0f} };
	transformModel_[8] =  { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{ 2.0f,1.0f,0.0f} };
	transformModel_[9] =  { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{-2.5f,1.5f,0.0f} };
	transformModel_[10] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{-2.5f,1.0f,0.0f} };
	transformModel_[11] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{ 2.5f,1.5f,0.0f} };
	transformModel_[12] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{-3.0f,1.0f,0.0f} };
	transformModel_[13] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{-3.0f,1.5f,0.0f} };
	transformModel_[14] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{ 3.0f,1.0f,0.0f} };
	transformModel_[15] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{ 3.0f,1.0f,0.0f} };
	transformModel_[16] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{ 3.0f,1.5f,0.0f} };
	transformModel_[17] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{ 3.0f,1.0f,0.0f} };
	transformModel_[18] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{-3.0f,1.0f,0.0f} };
	transformModel_[19] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{-3.0f,1.0f,0.0f} };






	move2_[0] = { -0.04f,  0.02f, 0 };
	move2_[1] = {  0.03f,  0.03f, 0 };
	move2_[2] = { -0.04f,  0.02f, 0 };
	move2_[3] = { -0.03f, -0.03f, 0 };
	move2_[4] = {  0.02f, -0.04f, 0 };
	move2_[5] = { -0.03f, -0.03f, 0 };
	move2_[6] = { -0.02f,  0.04f, 0 };
	move2_[7] = {  0.03f,  0.03f, 0 };
	move2_[8] = { -0.04f,  0.02f, 0 };
	move2_[9] = { -0.03f, -0.03f, 0 };

	transformModel2_[0] = { {0.2f,0.2f,0.2f},{0.0f,0.0f,0.0f},{-1.0f,-1.0f,0.0f} };
	transformModel2_[1] = { {0.2f,0.2f,0.2f},{0.0f,0.0f,0.0f},{ 1.0f,-1.5f,0.0f} };
	transformModel2_[2] = { {0.2f,0.2f,0.2f},{0.0f,0.0f,0.0f},{-2.0f ,1.0f,0.0f} };
	transformModel2_[3] = { {0.2f,0.2f,0.2f},{0.0f,0.0f,0.0f},{-2.0f ,1.5f,0.0f} };
	transformModel2_[4] = { {0.2f,0.2f,0.2f},{0.0f,0.0f,0.0f},{ 2.0f, 1.0f,0.0f} };
	transformModel2_[5] = { {0.2f,0.2f,0.2f},{0.0f,0.0f,0.0f},{-3.0f,-1.2f,0.0f} };
	transformModel2_[6] = { {0.2f,0.2f,0.2f},{0.0f,0.0f,0.0f},{-3.0f, 1.0f,0.0f} };
	transformModel2_[7] = { {0.2f,0.2f,0.2f},{0.0f,0.0f,0.0f},{ 3.0f,-1.5f,0.0f} };
	transformModel2_[8] = { {0.2f,0.2f,0.2f},{0.0f,0.0f,0.0f},{ 3.0f,-1.0f,0.0f} };
	transformModel2_[9] = { {0.2f,0.2f,0.2f},{0.0f,0.0f,0.0f},{ 3.0f, 1.5f,0.0f} };



	transformModel3_[0] = { {0.4f,0.4f,0.4f},{0.0f,0.0f,0.0f},{-1.0f,-1.0f,0.0f} };
	transformModel3_[1] = { {0.4f,0.4f,0.4f},{0.0f,0.0f,0.0f},{1.0f,-1.5f,0.0f} };
	transformModel3_[2] = { {0.4f,0.4f,0.4f},{0.0f,0.0f,0.0f},{-2.0f,1.5f,0.0f} };

	move3_[0] = { -0.02f,  0.02f, 0 };
	move3_[1] = {  0.02f,  0.02f, 0 };
	move3_[2] = { -0.02f,  0.02f, 0 };
	for (int i = 0; i < enemyCount; i++) {

		enemy_[i] = new Enemy;
		enemy_[i]->Initialize("Resources/Game/Enemy/Enemy", "enemy.obj", transformModel_[i], move_[i]);
	}

	for (int i = 0; i < enemyCount2; i++) {

		enemy2_[i] = new Enemy;
		enemy2_[i]->Initialize("Resources/Game/Enemy/Enemy2", "enemy2.obj", transformModel2_[i], move2_[i]);
	}
	for (int i = 0; i < enemyCount3; i++) {

		enemy3_[i] = new Enemy;
		enemy3_[i]->Initialize("Resources/Game/Enemy/Enemy3", "enemy3.obj", transformModel3_[i], move3_[i]);
	}
	yuka_ = new Model;
	transformyuka_ = { {0.25f,0.25f,0.1f},{0.0f,0.0f,0.0f},{0.0f,-2.28f,0.0f} };
	yuka_->CreateObject("Resources/Game/Ground", "yuka.obj");



#pragma endregion

}

void GameScene::Play() {


	for (int i = 0; i < enemyCount; i++) {
		enemy_[i]->Update();
	}
	for (int i = 0; i < enemyCount2; i++) {
		enemy2_[i]->Update();
	}
	for (int i = 0; i < enemyCount3; i++) {
		enemy3_[i]->Update();
	}


}

/// 更新
void GameScene::Update(GameManager* gameManager) {

	ImGui::Begin("Game");
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
		
		
	}


	if (waitingTime_ > SECOND_ * 3) {
		gameManager->ChangeScene(new TutorialScene());
	}
	

	
}

/// 描画
void GameScene::Draw(GameManager* gameManager) {
	//gameSprite_->DrawRect(selectSpriteTransform_);

	yuka_->Draw(transformyuka_);

	for (int i = 0; i < enemyCount; i++) {
		enemy_[i]->Dorw();
	}
	for (int i = 0; i < enemyCount2; i++) {
		enemy2_[i]->Dorw();
	}
	for (int i = 0; i < enemyCount3; i++) {
		enemy3_[i]->Dorw();
	}


}


/// デストラクタ
GameScene::~GameScene() {
	delete gameSprite_;

	for (int i = 0; i < enemyCount; i++) {
		enemy_[i]->Release();
	}
	for (int i = 0; i < enemyCount2; i++) {
		enemy2_[i]->Release();
	}
	for (int i = 0; i < enemyCount3; i++) {
		enemy3_[i]->Release();
	}

}