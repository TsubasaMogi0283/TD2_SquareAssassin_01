#include "GameScene.h"
#include "AllGameScene/TutorialScene/TutorialScene.h"

//コンストラクタ
GameScene::GameScene() {

}

/// 初期化
void GameScene::Initialize(GameManager* gameManager) {
	




#pragma region 敵

	

	enemyMove_[0] =  { -0.06f,  0.06f, 0 };
	enemyMove_[1] =  {  0.06f,  0.06f, 0 };
	enemyMove_[2] =  { -0.06f,  0.04f, 0 };
	enemyMove_[3] =  { -0.06f, -0.04f, 0 };
	enemyMove_[4] =  {  0.06f, -0.06f, 0 };
	enemyMove_[5] =  { -0.06f, -0.06f, 0 };
	enemyMove_[6] =  { -0.06f,  0.06f, 0 };
	enemyMove_[7] =  {  0.06f,  0.06f, 0 };
	enemyMove_[8] =  { -0.06f,  0.04f, 0 };
	enemyMove_[9] =  { -0.06f, -0.04f, 0 };
	enemyMove_[10] = {  0.06f, -0.06f, 0 };
	enemyMove_[11] = { -0.06f, -0.06f, 0 };
	enemyMove_[12] = { -0.06f,  0.06f, 0 };
	enemyMove_[13] = {  0.06f,  0.06f, 0 };
	enemyMove_[14] = { -0.06f,  0.04f, 0 };
	enemyMove_[15] = { -0.06f, -0.04f, 0 };
	enemyMove_[16] = {  0.09f, -0.03f, 0 };
	enemyMove_[17] = { -0.06f, -0.06f, 0 };
	enemyMove_[18] = { -0.06f, -0.06f, 0 };
	enemyMove_[19] = { -0.06f, -0.06f, 0 };


	enemyTransform_[0] =  { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{ 1.0f,1.0f,0.0f} };
	enemyTransform_[1] =  { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{-1.0f,1.5f,0.0f} };
	enemyTransform_[2] =  { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{-1.0f,1.0f,0.0f} };
	enemyTransform_[3] =  { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{ 1.5f,1.5f,0.0f} };
	enemyTransform_[4] =  { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{ 1.5f,1.0f,0.0f} };
	enemyTransform_[5] =  { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{-1.5f,1.5f,0.0f} };
	enemyTransform_[6] =  { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{-2.0f,1.0f,0.0f} };
	enemyTransform_[7] =  { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{ 2.0f,1.5f,0.0f} };
	enemyTransform_[8] =  { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{ 2.0f,1.0f,0.0f} };
	enemyTransform_[9] =  { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{-2.5f,1.5f,0.0f} };
	enemyTransform_[10] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{-2.5f,1.0f,0.0f} };
	enemyTransform_[11] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{ 2.5f,1.5f,0.0f} };
	enemyTransform_[12] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{-3.0f,1.0f,0.0f} };
	enemyTransform_[13] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{-3.0f,1.5f,0.0f} };
	enemyTransform_[14] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{ 3.0f,1.0f,0.0f} };
	enemyTransform_[15] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{ 3.0f,1.0f,0.0f} };
	enemyTransform_[16] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{ 3.0f,1.5f,0.0f} };
	enemyTransform_[17] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{ 3.0f,1.0f,0.0f} };
	enemyTransform_[18] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{-3.0f,1.0f,0.0f} };
	enemyTransform_[19] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{-3.0f,1.0f,0.0f} };






	enemyMove2_[0] = { -0.04f,  0.02f, 0 };
	enemyMove2_[1] = {  0.03f,  0.03f, 0 };
	enemyMove2_[2] = { -0.04f,  0.02f, 0 };
	enemyMove2_[3] = { -0.03f, -0.03f, 0 };
	enemyMove2_[4] = {  0.02f, -0.04f, 0 };
	enemyMove2_[5] = { -0.03f, -0.03f, 0 };
	enemyMove2_[6] = { -0.02f,  0.04f, 0 };
	enemyMove2_[7] = {  0.03f,  0.03f, 0 };
	enemyMove2_[8] = { -0.04f,  0.02f, 0 };
	enemyMove2_[9] = { -0.03f, -0.03f, 0 };

	enemyTransformModel2_[0] = { {0.2f,0.2f,0.2f},{0.0f,0.0f,0.0f},{-1.0f,-1.0f,0.0f} };
	enemyTransformModel2_[1] = { {0.2f,0.2f,0.2f},{0.0f,0.0f,0.0f},{ 1.0f,-1.5f,0.0f} };
	enemyTransformModel2_[2] = { {0.2f,0.2f,0.2f},{0.0f,0.0f,0.0f},{-2.0f ,1.0f,0.0f} };
	enemyTransformModel2_[3] = { {0.2f,0.2f,0.2f},{0.0f,0.0f,0.0f},{-2.0f ,1.5f,0.0f} };
	enemyTransformModel2_[4] = { {0.2f,0.2f,0.2f},{0.0f,0.0f,0.0f},{ 2.0f, 1.0f,0.0f} };
	enemyTransformModel2_[5] = { {0.2f,0.2f,0.2f},{0.0f,0.0f,0.0f},{-3.0f,-1.2f,0.0f} };
	enemyTransformModel2_[6] = { {0.2f,0.2f,0.2f},{0.0f,0.0f,0.0f},{-3.0f, 1.0f,0.0f} };
	enemyTransformModel2_[7] = { {0.2f,0.2f,0.2f},{0.0f,0.0f,0.0f},{ 3.0f,-1.5f,0.0f} };
	enemyTransformModel2_[8] = { {0.2f,0.2f,0.2f},{0.0f,0.0f,0.0f},{ 3.0f,-1.0f,0.0f} };
	enemyTransformModel2_[9] = { {0.2f,0.2f,0.2f},{0.0f,0.0f,0.0f},{ 3.0f, 1.5f,0.0f} };



	enemyTransformModel3_[0] = { {0.4f,0.4f,0.4f},{0.0f,0.0f,0.0f},{-1.0f,-1.0f,0.0f} };
	enemyTransformModel3_[1] = { {0.4f,0.4f,0.4f},{0.0f,0.0f,0.0f},{1.0f,-1.5f,0.0f} };
	enemyTransformModel3_[2] = { {0.4f,0.4f,0.4f},{0.0f,0.0f,0.0f},{-2.0f,1.5f,0.0f} };

	enemyMove3_[0] = { -0.02f,  0.02f, 0 };
	enemyMove3_[1] = {  0.02f,  0.02f, 0 };
	enemyMove3_[2] = { -0.02f,  0.02f, 0 };
	for (int i = 0; i < enemyCount; i++) {

		enemy_[i] = new Enemy;
		enemy_[i]->Initialize("Resources/Game/Enemy/Enemy", "enemy.obj", enemyTransform_[i], enemyMove_[i],enemyHP);
	}

	for (int i = 0; i < enemyCount2; i++) {

		enemy2_[i] = new Enemy;
		enemy2_[i]->Initialize("Resources/Game/Enemy/Enemy2", "enemy2.obj", enemyTransformModel2_[i], enemyMove2_[i], enemyHP2);
	}
	for (int i = 0; i < enemyCount3; i++) {

		enemy3_[i] = new Enemy;
		enemy3_[i]->Initialize("Resources/Game/Enemy/Enemy3", "enemy3.obj", enemyTransformModel3_[i], enemyMove3_[i], enemyHP3);
	}
	yuka_ = new Model;
	transformyuka_ = { {0.25f,0.25f,0.1f},{0.0f,0.0f,0.0f},{0.0f,-2.28f,0.0f} };
	yuka_->CreateObject("Resources/Game/Ground", "yuka.obj");



#pragma endregion


#pragma region 自機
	player_ = new Player;

	player_->Initialize("Resources/Game/Player", "playre.obj");

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
	player_->Update();
	
}

/// 更新
void GameScene::Update(GameManager* gameManager) {

	ImGui::Begin("Game");
	ImGui::Text("1 To GameScene");
	ImGui::Text("2 To GameScene");


	ImGui::End();


	yuka_->SetTransparency(transparency_);

	//フェードイン
	if (isFadeIn_ == true) {
		transparency_ += 0.05f;
		if (transparency_ > 1.0f) {
			transparency_ = 1.0f;
			isFadeIn_ = false;
		}

		
		
	
	}
	



	//選択画面
	if (isFadeIn_ == false) {
		Play();
		
	}


	if (waitingTime_ > SECOND_ * 3) {
		//gameManager->ChangeScene(new TutorialScene());
	}
	
	
}

/// 描画
void GameScene::Draw(GameManager* gameManager) {
	//gameSprite_->DrawRect(selectSpriteTransform_);

	yuka_->Draw(transformyuka_);

	for (int i = 0; i < enemyCount; i++) {
		enemy_[i]->Draw();
	}
	for (int i = 0; i < enemyCount2; i++) {
		enemy2_[i]->Draw();
	}
	for (int i = 0; i < enemyCount3; i++) {
		enemy3_[i]->Draw();
	}
	player_->Draw();

}


/// デストラクタ
GameScene::~GameScene() {
	for (int i = 0; i < enemyCount; i++) {
		enemy_[i]->Release();
		delete enemy_[i];
	}
	for (int i = 0; i < enemyCount2; i++) {
		enemy2_[i]->Release();
		delete enemy2_[i];
	
	}
	for (int i = 0; i < enemyCount3; i++) {
		enemy3_[i]->Release();
		delete enemy3_[i];
	}

}