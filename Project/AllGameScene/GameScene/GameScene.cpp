#include "GameScene.h"
#include "AllGameScene/TutorialScene/TutorialScene.h"

//コンストラクタ
GameScene::GameScene() {

}

/// 初期化
void GameScene::Initialize(GameManager* gameManager) {
	
#pragma region  カウントと終了
	for (int i = 0; i < COUNT_NUMBER_; i++) {
		count_[i] = { new Sprite()};
		
		countTransform_[i] = {{COUNT_SIZE,COUNT_SIZE,COUNT_SIZE},{0.0f,0.0f,0.0f},{490.0f,210.0f,0.0f}};
		countAllPosition_ = { {0.0f,0.0f},{0.0f,300.0f},{300.0f,0.0f},{300.0f,300.0f}};

	}
	

	for (int i = 0; i < COUNT_NUMBER_; i++) {
		uint32_t counDownTextureHandle[COUNT_NUMBER_] = {};
		counDownTextureHandle[0]=TextureManager::LoadTexture("Resources/Game/CountDown/1.png");
		counDownTextureHandle[1]=TextureManager::LoadTexture("Resources/Game/CountDown/2.png");
		counDownTextureHandle[2]=TextureManager::LoadTexture("Resources/Game/CountDown/3.png");
		count_[i]->LoadTextureHandle(counDownTextureHandle[i]);
		count_[i]->SetAllPosition(countAllPosition_);
	}

	start_ = new Sprite();
	startTransform_ = {{1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{190.0f,210.0f,0.0f}};
	startAllPosition_ = { {0.0f,0.0f},{0.0f,300.0f},{900.0f,0.0f},{900.0f,300.0f}};
	uint32_t startTextureHandle = TextureManager::LoadTexture("Resources/Game/CountDown/Start.png");
	start_->LoadTextureHandle(startTextureHandle);
	start_->SetAllPosition(startAllPosition_);

	end_ = new Sprite();
	endTransform_ = {{1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{190.0f,210.0f,0.0f}};
	endAllPosition_ = {{0.0f,0.0f},{0.0f,300.0f},{900.0f,0.0f},{900.0f,300.0f}};
	uint32_t endTextureHandle = TextureManager::LoadTexture("Resources/Game/CountDown/End.png");
	end_->LoadTextureHandle(startTextureHandle);
	end_->SetAllPosition(startAllPosition_);


#pragma endregion


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
	for (int i = 0; i < NUMBER_AMOUNT_; i++) {
		timeTensPlane_[i] = new Sprite();
		timeOnesPlane_[i] = new Sprite();
	
	}
	
	numberTextureHandle[0]=TextureManager::LoadTexture("Resources/Game/Number/0.png");
	numberTextureHandle[1]=TextureManager::LoadTexture("Resources/Game/Number/1.png");
	numberTextureHandle[2]=TextureManager::LoadTexture("Resources/Game/Number/2.png");
	numberTextureHandle[3]=TextureManager::LoadTexture("Resources/Game/Number/3.png");
	numberTextureHandle[4]=TextureManager::LoadTexture("Resources/Game/Number/4.png");
	numberTextureHandle[5]=TextureManager::LoadTexture("Resources/Game/Number/5.png");
	numberTextureHandle[6]=TextureManager::LoadTexture("Resources/Game/Number/6.png");
	numberTextureHandle[7]=TextureManager::LoadTexture("Resources/Game/Number/7.png");
	numberTextureHandle[8]=TextureManager::LoadTexture("Resources/Game/Number/8.png");
	numberTextureHandle[9]=TextureManager::LoadTexture("Resources/Game/Number/9.png");
	
	timeTensPlaneTransform_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{600.0f,30.0f,0.0f} };
	timeOnesPlaneTransform_  = {{1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{680.0f,30.0f,0.0f} };

	timeTensPlaneAllPosition_ = {{0.0f,0.0f},{0.0f,64.0f},{32.0f,0.0f},{32.0f,64.0f} };
	timeOnesPlaneAllPosition_ = { {0.0f,0.0f},{0.0f,64.0f},{32.0f,0.0f},{32.0f,64.0f} };
	
	

	for (int i=0; i < NUMBER_AMOUNT_; i++) {
		timeOnesPlane_[i]->LoadTextureHandle(numberTextureHandle[i]);
		timeTensPlane_[i]->LoadTextureHandle(numberTextureHandle[i]);

		timeTensPlane_[i]->SetAllPosition(timeTensPlaneAllPosition_);
		timeOnesPlane_[i]->SetAllPosition(timeOnesPlaneAllPosition_);
	}
	



	//BGM
	//タイトルBGM
	gameBGM_ = Audio::GetInstance();
	//titleBGM_->Initialize();
	gameBGMHandle_ = gameBGM_->LoadWave("Resources/Game/Music/Game.wav");

	

	//カウントダウン
	countSE_ =  Audio::GetInstance();
	countSEHandle_ = countSE_->LoadWave("Resources/Game/Music/Count.wav");

	//開始
	startSE_ = Audio::GetInstance();;
	startSEHandle_ = startSE_->LoadWave("Resources/Game/Music/Start.wav");





}

void GameScene::ImGuiDebug() {
	ImGui::Begin("Game");
	ImGui::Text("1 To GameScene");
	ImGui::Text("2 To GameScene");


	ImGui::End();


	ImGui::Begin("count");
	ImGui::SliderFloat3("Translate", &countTransform_[2].translate.x, 0.0f, 1280.0f);
	ImGui::SliderFloat3("Scale", &countTransform_[2].scale.x, 1.0f, 2.0f);
	ImGui::End();



	ImGui::Begin("Start");
	ImGui::SliderFloat3("Translate", &startTransform_.translate.x, 0.0f, 1280.0f);
	ImGui::End();

	ImGui::Begin("Time");
	ImGui::InputInt("DisplayTime", &displayTime_);
	ImGui::InputInt("TenPlace", &tensPlace_);
	ImGui::InputInt("OnePlace", &onesPlace_);
	ImGui::End();

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

//カウントダウン
void GameScene::CountDown() {
	//仮で60秒
	gameTime_ -= 1;

	displayTime_ = gameTime_ / 60;

	tensPlace_ = displayTime_ / 10;
	onesPlace_ = displayTime_ % 10;



}

/// 更新
void GameScene::Update(GameManager* gameManager) {

	ImGuiDebug();


	yuka_->SetTransparency(transparency_);

	//フェードイン
	if (isFadeIn_ == true) {
		transparency_ += 0.01f;
		if (transparency_ > 1.0f) {
			transparency_ = 1.0f;
			isFadeIn_ = false;
		}

	}



	//フェード終わり
	//カウントダウン
	if (isFadeIn_ == false) {
		countDown_ -= 1;

		if (countDown_ < SECOND_ * 4 && countDown_ >= SECOND_ * 3) {
			if (countDown_ == SECOND_ * 4 - 1) {
				countSE_->PlayWave(countSEHandle_, false);
			}
		}
		if (countDown_ < SECOND_ * 3 && countDown_ >= SECOND_ * 2) {
			if (countDown_ == SECOND_ * 3 - 1) {
				countSE_->PlayWave(countSEHandle_, false);
			}

		}
		if (countDown_ < SECOND_ * 2 && countDown_ >= SECOND_ * 1) {
			if (countDown_ == SECOND_ * 2 - 1) {
				countSE_->PlayWave(countSEHandle_, false);
			}
		}
		if (countDown_ < SECOND_ * 1 && countDown_ >= SECOND_ * 0) {
			if (countDown_ == SECOND_ * 1 - 1) {
				startSE_->PlayWave(startSEHandle_, false);
			}
		}


		if (countDown_ < 0) {
			isGamePlay_ = true;
		}

	}

	//ゲームプレイ
	if (isGamePlay_ == true){
		//主なゲームの動き
		Play();

		//ゲームの時間
		CountDown();

		//再生
		bgmTime_ += 1;
		//ループ
		if (bgmTime_ == 1) {
			gameBGM_->PlayWave(gameBGMHandle_ ,false);
		}
		if (bgmTime_ > SECOND_ * 30) {
			
			bgmTime_ = 0;
		}
		
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
	
	
#pragma region カウントダウン
	if (countDown_ < SECOND_ * 4 && countDown_ >= SECOND_ * 3) {
		 count_[2]->DrawRect(countTransform_[2]);	
	}
	if (countDown_ < SECOND_ * 3 && countDown_ >= SECOND_ * 2) {
		 count_[1]->DrawRect(countTransform_[1]);	
	}
	if (countDown_ < SECOND_ * 2 && countDown_ >= SECOND_ * 1) {
		 count_[0]->DrawRect(countTransform_[0]);	
	}
	if (countDown_ < SECOND_ * 1 && countDown_ >= SECOND_ * 0) {
		start_->DrawRect(startTransform_);
	}

#pragma endregion

#pragma region 時間


	for (int i = 0; i < NUMBER_AMOUNT_; i++) {
		if (tensPlace_ == i) {
			timeTensPlane_[i]->DrawRect(timeTensPlaneTransform_);
		}
		if (onesPlace_ == i) {
			timeOnesPlane_[i]->DrawRect(timeOnesPlaneTransform_);
		}
		


	}

	

	
#pragma endregion



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