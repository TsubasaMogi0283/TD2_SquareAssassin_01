#include "GameScene.h"
#include "AllGameScene/TutorialScene/TutorialScene.h"
#include "AllGameScene/ResultScene/ResultScene.h"

//コンストラクタ
GameScene::GameScene() {

}

/// 初期化
void GameScene::Initialize(GameManager* gameManager) {

#pragma region  カウントと終了
	for (int i = 0; i < COUNT_NUMBER_; i++) {
		count_[i] = { new Sprite() };

		countTransform_[i] = { {COUNT_SIZE,COUNT_SIZE,COUNT_SIZE},{0.0f,0.0f,0.0f},{490.0f,210.0f,0.0f} };
		countAllPosition_ = { {0.0f,0.0f},{0.0f,300.0f},{300.0f,0.0f},{300.0f,300.0f} };


	}


	for (int i = 0; i < COUNT_NUMBER_; i++) {
		uint32_t counDownTextureHandle[COUNT_NUMBER_] = {};
		counDownTextureHandle[0] = TextureManager::LoadTexture("Resources/Game/CountDown/1.png");
		counDownTextureHandle[1] = TextureManager::LoadTexture("Resources/Game/CountDown/2.png");
		counDownTextureHandle[2] = TextureManager::LoadTexture("Resources/Game/CountDown/3.png");
		count_[i]->LoadTextureHandle(counDownTextureHandle[i]);
		count_[i]->SetAllPosition(countAllPosition_);
	}

	start_ = new Sprite();
	startTransform_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{190.0f,210.0f,0.0f} };
	startAllPosition_ = { {0.0f,0.0f},{0.0f,300.0f},{900.0f,0.0f},{900.0f,300.0f} };
	uint32_t startTextureHandle = TextureManager::LoadTexture("Resources/Game/CountDown/Start.png");
	start_->LoadTextureHandle(startTextureHandle);
	start_->SetAllPosition(startAllPosition_);

	end_ = new Sprite();
	endTransform_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{190.0f,210.0f,0.0f} };
	endAllPosition_ = { {0.0f,0.0f},{0.0f,300.0f},{900.0f,0.0f},{900.0f,300.0f} };
	uint32_t endTextureHandle = TextureManager::LoadTexture("Resources/Game/CountDown/End.png");
	end_->LoadTextureHandle(endTextureHandle);
	end_->SetAllPosition(startAllPosition_);


#pragma endregion

#pragma region 自機
	playerTransform_ = { {0.2f,0.2f,0.2f},{0.0f,0.0f,0.0f},{3.7f,2.0f,0.0f} };
	player_ = new Player;

	player_->Initialize("Resources/Game/Player", "playre.obj", playerTransform_);

#pragma endregion


#pragma region 敵



	enemyMove_[0] = { -0.06f,  0.06f, 0 };
	enemyMove_[1] = { 0.06f,  0.06f, 0 };
	enemyMove_[2] = { -0.06f,  0.04f, 0 };
	enemyMove_[3] = { -0.06f, -0.04f, 0 };
	enemyMove_[4] = { 0.06f, -0.06f, 0 };
	enemyMove_[5] = { -0.06f, -0.06f, 0 };
	enemyMove_[6] = { -0.06f,  0.06f, 0 };
	enemyMove_[7] = { 0.06f,  0.06f, 0 };
	enemyMove_[8] = { -0.06f,  0.04f, 0 };
	enemyMove_[9] = { -0.06f, -0.04f, 0 };
	enemyMove_[10] = { 0.06f, -0.06f, 0 };
	enemyMove_[11] = { -0.06f, -0.06f, 0 };
	enemyMove_[12] = { -0.06f,  0.06f, 0 };
	enemyMove_[13] = { 0.06f,  0.06f, 0 };
	enemyMove_[14] = { -0.06f,  0.04f, 0 };
	enemyMove_[15] = { -0.06f, -0.04f, 0 };
	enemyMove_[16] = { 0.09f, -0.03f, 0 };
	enemyMove_[17] = { -0.06f, -0.06f, 0 };
	enemyMove_[18] = { -0.06f, -0.06f, 0 };
	enemyMove_[19] = { -0.06f, -0.06f, 0 };


	enemyTransform_[0] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{ 1.0f,1.0f,0.0f} };
	enemyTransform_[1] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{-1.0f,1.5f,0.0f} };
	enemyTransform_[2] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{-1.0f,1.0f,0.0f} };
	enemyTransform_[3] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{ 1.5f,1.5f,0.0f} };
	enemyTransform_[4] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{ 1.5f,1.0f,0.0f} };
	enemyTransform_[5] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{-1.5f,1.5f,0.0f} };
	enemyTransform_[6] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{-2.0f,1.0f,0.0f} };
	enemyTransform_[7] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{ 2.0f,1.5f,0.0f} };
	enemyTransform_[8] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{ 2.0f,1.0f,0.0f} };
	enemyTransform_[9] = { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{-2.5f,1.5f,0.0f} };
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
	enemyHP[0] = 1;
	enemyHP[1] = 1;
	enemyHP[2] = 1;
	enemyHP[3] = 1;
	enemyHP[4] = 1;
	enemyHP[5] = 1;
	enemyHP[6] = 1;
	enemyHP[7] = 1;
	enemyHP[8] = 1;
	enemyHP[9] = 1;
	enemyHP[10] = 1;
	enemyHP[11] = 1;
	enemyHP[12] = 1;
	enemyHP[13] = 1;
	enemyHP[14] = 1;
	enemyHP[15] = 1;
	enemyHP[16] = 1;
	enemyHP[17] = 1;
	enemyHP[18] = 1;
	enemyHP[19] = 1;



	enemyMove2_[0] = { -0.04f,  0.02f, 0 };
	enemyMove2_[1] = { 0.03f,  0.03f, 0 };
	enemyMove2_[2] = { -0.04f,  0.02f, 0 };
	enemyMove2_[3] = { -0.03f, -0.03f, 0 };
	enemyMove2_[4] = { 0.02f, -0.04f, 0 };
	enemyMove2_[5] = { -0.03f, -0.03f, 0 };
	enemyMove2_[6] = { -0.02f,  0.04f, 0 };
	enemyMove2_[7] = { 0.03f,  0.03f, 0 };
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



	enemyHP2[0] = 2;
	enemyHP2[1] = 2;
	enemyHP2[2] = 2;
	enemyHP2[3] = 2;
	enemyHP2[4] = 2;
	enemyHP2[5] = 2;
	enemyHP2[6] = 2;
	enemyHP2[7] = 2;
	enemyHP2[8] = 2;
	enemyHP2[9] = 2;




	enemyTransformModel3_[0] = { {0.4f,0.4f,0.4f},{0.0f,0.0f,0.0f},{-1.0f,-1.0f,0.0f} };
	enemyTransformModel3_[1] = { {0.4f,0.4f,0.4f},{0.0f,0.0f,0.0f},{1.0f,-1.5f,0.0f} };
	enemyTransformModel3_[2] = { {0.4f,0.4f,0.4f},{0.0f,0.0f,0.0f},{-2.0f,1.5f,0.0f} };

	enemyMove3_[0] = { -0.02f,  0.02f, 0 };
	enemyMove3_[1] = { 0.02f,  0.02f, 0 };
	enemyMove3_[2] = { -0.02f,  0.02f, 0 };


	enemyHP3[0] = 3;
	enemyHP3[1] = 3;
	enemyHP3[2] = 3;


	for (int i = 0; i < enemyCount; i++) {
		recoveryTime[i] = 10;
	}
	for (int i = 0; i < enemyCount2; i++) {
		recoveryTime2[i] = 10;

	}
	for (int i = 0; i < enemyCount3; i++) {
		recoveryTime3[i] = 10;
	}




	for (int i = 0; i < enemyCount; i++) {

		enemy_[i] = new Enemy;
		enemy_[i]->Initialize("Resources/Game/Enemy/Enemy", "enemy.obj", enemyTransform_[i], enemyMove_[i]);
	}

	for (int i = 0; i < enemyCount2; i++) {

		enemy2_[i] = new Enemy;
		enemy2_[i]->Initialize("Resources/Game/Enemy/Enemy2", "enemy2.obj", enemyTransformModel2_[i], enemyMove2_[i]);
	}
	for (int i = 0; i < enemyCount3; i++) {

		enemy3_[i] = new Enemy;
		enemy3_[i]->Initialize("Resources/Game/Enemy/Enemy3", "enemy3.obj", enemyTransformModel3_[i], enemyMove3_[i]);
	}
	yuka_ = new Model;
	transformyuka_ = { {0.25f,0.25f,0.1f},{0.0f,0.0f,0.0f},{0.0f,-2.28f,0.0f} };
	yuka_->CreateObject("Resources/Game/Ground", "yuka.obj");



#pragma endregion

#pragma region 数字

	for (int i = 0; i < NUMBER_AMOUNT_; i++) {
		timeTensPlane_[i] = new Sprite();
		timeOnesPlane_[i] = new Sprite();

	}

	numberTextureHandle[0] = TextureManager::LoadTexture("Resources/Game/Number/0.png");
	numberTextureHandle[1] = TextureManager::LoadTexture("Resources/Game/Number/1.png");
	numberTextureHandle[2] = TextureManager::LoadTexture("Resources/Game/Number/2.png");
	numberTextureHandle[3] = TextureManager::LoadTexture("Resources/Game/Number/3.png");
	numberTextureHandle[4] = TextureManager::LoadTexture("Resources/Game/Number/4.png");
	numberTextureHandle[5] = TextureManager::LoadTexture("Resources/Game/Number/5.png");
	numberTextureHandle[6] = TextureManager::LoadTexture("Resources/Game/Number/6.png");
	numberTextureHandle[7] = TextureManager::LoadTexture("Resources/Game/Number/7.png");
	numberTextureHandle[8] = TextureManager::LoadTexture("Resources/Game/Number/8.png");
	numberTextureHandle[9] = TextureManager::LoadTexture("Resources/Game/Number/9.png");

	timeTensPlaneTransform_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{600.0f,30.0f,0.0f} };
	timeOnesPlaneTransform_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{680.0f,30.0f,0.0f} };

	timeTensPlaneAllPosition_ = { {0.0f,0.0f},{0.0f,64.0f},{32.0f,0.0f},{32.0f,64.0f} };
	timeOnesPlaneAllPosition_ = { {0.0f,0.0f},{0.0f,64.0f},{32.0f,0.0f},{32.0f,64.0f} };



	for (int i = 0; i < NUMBER_AMOUNT_; i++) {
		timeOnesPlane_[i]->LoadTextureHandle(numberTextureHandle[i]);
		timeTensPlane_[i]->LoadTextureHandle(numberTextureHandle[i]);

		timeTensPlane_[i]->SetAllPosition(timeTensPlaneAllPosition_);
		timeOnesPlane_[i]->SetAllPosition(timeOnesPlaneAllPosition_);
	}

#pragma endregion


	//BGM
	//タイトルBGM
	gameBGM_ = Audio::GetInstance();
	gameBGMHandle_ = gameBGM_->LoadWave("Resources/Game/Music/Game.wav");



	//カウントダウン
	countSE_ = Audio::GetInstance();
	countSEHandle_ = countSE_->LoadWave("Resources/Game/Music/Count.wav");

	//開始
	startSE_ = Audio::GetInstance();
	startSEHandle_ = startSE_->LoadWave("Resources/Game/Music/Start.wav");


	//終了
	endSE_ = Audio::GetInstance();
	endSEHandle_ = endSE_->LoadWave("Resources/Game/Music/End.wav");

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


	ImGui::Begin("End");
	ImGui::SliderFloat3("translate", &endTransform_.translate.x, 0.0f, 1280.0f);

	ImGui::End();

	ImGui::Begin("DisplayTime");
	ImGui::InputInt("a", &displayStopTime_);
	ImGui::End();



}

void GameScene::Play() {


	Collision();
	for (int i = 0; i < enemyCount; i++) {
		enemy_[i]->Update(enemyHP[i]);
	}
	for (int i = 0; i < enemyCount2; i++) {
		enemy2_[i]->Update(enemyHP2[i]);
	}
	for (int i = 0; i < enemyCount3; i++) {
		enemy3_[i]->Update(enemyHP3[i]);
	}
	player_->Update();


}

//カウントダウン
void GameScene::CountDown() {
	//仮で60秒
	gameTime_ -= 1;

	displayTime_ = gameTime_ / 60;

	tensPlace_ = displayTime_ / 10;
	onesPlace_ = displayTime_ % 10;

	if (displayTime_ < 1) {
		isStopGame_ = true;
	}

}

/// 更新
void GameScene::Update(GameManager* gameManager) {

	ImGuiDebug();


	yuka_->SetTransparency(transparency_);

	//フェードイン
	if (isFadeIn_ == true) {
		transparency_ += 0.05f;
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
	if (isGamePlay_ == true && isStopGame_ == false) {


		//再生
		bgmTime_ += 1;
		//ループ
		if (bgmTime_ == 1) {
			gameBGM_->PlayWave(gameBGMHandle_, false);
		}
		if (bgmTime_ > SECOND_ * 30) {

			bgmTime_ = 0;
		}
		//主なゲームの動き
		Play();

		//ゲームの時間
		CountDown();
	}



	if (isStopGame_ == true) {



		endSETime_ += 1;
		if (endSETime_ == 1) {

			endSE_->PlayWave(endSEHandle_, false);
			endSE_->ChangeVolume(endSEHandle_, 1.5f);

			gameBGM_->ChangeVolume(gameBGMHandle_, 0.4f);

		}



		gameTime_ = 0;


		displayStopTime_ += 1;

		if (displayStopTime_ > SECOND_ * 3) {
			//BGM止める
			gameBGM_->StopWave(gameBGMHandle_);

			transparency_ -= 0.01f;
			if (transparency_ < 0.0f) {
				transparency_ = 0.0f;
				gameManager->ChangeScene(new ResultScene());
			}

		}
	}



}

/// 描画
void GameScene::Draw(GameManager* gameManager) {
	//地面
	yuka_->Draw(transformyuka_);

	if (isGamePlay_ == true && isStopGame_ == false) {

#pragma region 敵
		if (isGamePlay_ == true) {
			for (int i = 0; i < enemyCount; i++) {
				enemy_[i]->Draw();
			}
			for (int i = 0; i < enemyCount2; i++) {
				enemy2_[i]->Draw();
			}
			for (int i = 0; i < enemyCount3; i++) {
				enemy3_[i]->Draw();
			}


		}

#pragma endregion

		player_->Draw();
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
	if (isGamePlay_ == true) {

		for (int i = 0; i < NUMBER_AMOUNT_; i++) {
			if (tensPlace_ == i) {
				timeTensPlane_[i]->DrawRect(timeTensPlaneTransform_);
			}
			if (onesPlace_ == i) {
				timeOnesPlane_[i]->DrawRect(timeOnesPlaneTransform_);
			}



		}

	}

#pragma endregion

	if (isStopGame_ == true) {
		end_->DrawRect(endTransform_);

	}



}

void GameScene::Collision()
{

	ImGui::Begin("killCount");
	ImGui::SliderInt("allKillCount_ ", &allKillCount_, -15, 15);
	ImGui::SliderInt("enemykill1", &killCount_, -15, 15);
	ImGui::SliderInt("enemykill2", &killCount2_, -15, 15);
	ImGui::SliderInt("enemykill3", &killCount3_, -15, 15);
	ImGui::SliderInt("enemyHP1", &enemyHP[0], -15, 15);
	ImGui::SliderInt("enemyHP2", &enemyHP2[0], -15, 15);
	ImGui::SliderInt("enemyHP3", &enemyHP3[0], -15, 15);
	ImGui::End();
	Vector3 posA, posB;

	//小敵
	for (int i = 0; i < enemyCount; i++) {
		posA = enemy_[i]->GetWorldPosition();
		posB = player_->GetWorldPosition();
		float distanceAB = Length(Subtract(posA, posB));
		//当たり判定
		//小敵
		if (distanceAB <= enemy_[i]->GetRadius() + player_->GetRadius()) {
			if (!HPCoolFlag_[i])
			{
				enemyHP[i] -= 1;
				HPCoolFlag_[i] = true;
			}


		}
		if (enemyHP[i] == 0) {
			recoveryTime[i]--;
		}

		if (recoveryTime[i] == 0) {
			killCount_ += 1;
			Record::GetInstance()->SetAttackedSmallEnemy(killCount_);
			allKillCount_ += 1;
			enemyHP[i] = 1;
			recoveryTime[i] = 20;
		}


		if (HPCoolFlag_[i])
		{
			HPCoolTimer_[i]++;
			if (HPCoolTimer_[i] > 30)
			{
				HPCoolTimer_[i] = 0;
				HPCoolFlag_[i] = false;
			}
		}

	}
	//中敵
	for (int i = 0; i < enemyCount2; i++) {
		posA = enemy2_[i]->GetWorldPosition();
		posB = player_->GetWorldPosition();
		float distanceAB = Length(Subtract(posA, posB));

		if (distanceAB <= enemy2_[i]->GetRadius() + player_->GetRadius()) {


			//配列にしましょう
			//ん、はやくやるべき
			if (!HPCoolFlag2_[i])
			{
				enemyHP2[i] -= 1;
				HPCoolFlag2_[i] = true;
			}


		}
		if (enemyHP2[i] == 0) {
			recoveryTime2[i]--;
		}

		if (recoveryTime2[i] == 0) {
			killCount2_ += 1;
			Record::GetInstance()->SetAttackedNormalEnemy(killCount2_);
			allKillCount_ += 1;
			enemyHP2[i] = 3;
			recoveryTime2[i] = 20;
		}

		if (HPCoolFlag2_[i])
		{
			HPCoolTimer2_[i]++;
			if (HPCoolTimer2_[i] > 30)
			{

				HPCoolTimer2_[i] = 0;
				HPCoolFlag2_[i] = false;
			}
		}

	}

	//大敵
	for (int i = 0; i < enemyCount3; i++) {
		posA = enemy3_[i]->GetWorldPosition();
		posB = player_->GetWorldPosition();
		float distanceAB = Length(Subtract(posA, posB));

		if (distanceAB <= enemy3_[i]->GetRadius() + player_->GetRadius()) {


			//配列にしましょう
			//ん、はやくやるべき
			if (!HPCoolFlag3_[i])
			{
				enemyHP3[i] -= 1;
				HPCoolFlag3_[i] = true;
			}


		}
		if (enemyHP3[i] == 0) {
			recoveryTime3[i]--;
		}

		if (recoveryTime3[i] == 0) {
			killCount3_ += 1;
			Record::GetInstance()->SetAttackedBigEnemy(killCount3_);
			allKillCount_ += 1;
			enemyHP3[i] = 5;
			recoveryTime3[i] = 20;
		}


		if (HPCoolFlag3_[i])
		{
			HPCoolTimer3_[i]++;
			if (HPCoolTimer3_[i] > 30)
			{
				HPCoolTimer3_[i] = 0;
				HPCoolFlag3_[i] = false;
			}
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



	delete yuka_;

	for (int i = 0; i < COUNT_NUMBER_; i++) {
		delete count_[i];

	}

	delete start_;

	delete end_;

	for (int i = 0; i < NUMBER_AMOUNT_; i++) {
		delete timeTensPlane_[i];
		delete timeOnesPlane_[i];

	}


	delete player_;


}