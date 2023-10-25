#include "AllGameScene/ResultScene/ResultScene.h"
#include "AllGameScene/TitleScene/TitleScene.h"

#include "Object/Rank/Rank.h"

//コンストラクタ
ResultScene::ResultScene() {

}



/// 初期化
void ResultScene::Initialize(GameManager* gameManager) {
#pragma region 背景
	
	backSprite = new Sprite();
	backTransform_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{0.0f,0.0f,0.0f} };
	uint32_t selectTextureHandle = TextureManager::LoadTexture("Resources/Result/Texture/Back.png");
	backSprite->LoadTextureHandle(selectTextureHandle);
	backAllPosition_ = { {0.0f,0.0f},{0.0f,720.0f},{1280.0f,0.0f},{1280.0f,720.0f} };
	backSprite->SetAllPosition(backAllPosition_);

#pragma endregion



#pragma region キャラクター
	characterSprite_ = new Sprite() ;
	characterSprite2_ = new Sprite();
	characterTransform_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{0.0f,500.0f,0.0f} };
	uint32_t characterTextureHandle = TextureManager::LoadTexture("Resources/Result/Texture/Character.png");
	uint32_t characterTextureHandle2 = TextureManager::LoadTexture("Resources/Result/Texture/Character2.png");
	characterSprite_->LoadTextureHandle(characterTextureHandle);
	characterSprite2_->LoadTextureHandle(characterTextureHandle2);
	characterAllPosition_ = { {0.0f,0.0f},{0.0f,256.0f},{256.0f,0.0f},{256.0f,256.0f} };
	characterSprite_->SetAllPosition(characterAllPosition_);
	characterSprite2_->SetAllPosition(characterAllPosition_);

#pragma endregion

#pragma region 吹き出し

	//吹き出し
	speechBubbleSprite_ = new Sprite() ;
	speechBubbleTransform_ = { {scaleSize_,scaleSize_,1.0f},{0.0f,0.0f,0.0f},{60.0f,300.0f,0.0f} };
	uint32_t speechBublleTextureHandle = TextureManager::LoadTexture("Resources/Result/Texture/Comment/SpeechBubble.png");
	speechBubbleSprite_->LoadTextureHandle(speechBublleTextureHandle);
	speechBubbleAllPosition_ = { {0.0f,0.0f},{0.0f,150.0f},{200.0f,0.0f},{200.0f,150.0f} };
	speechBubbleSprite_->SetAllPosition(speechBubbleAllPosition_);

#pragma endregion

#pragma region ランク
	for (int i = 0; i < RANK_AMOUNT_; i++) {
		rankSprite_[i] = new Sprite();
		rankTransform_[i]  = {{1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{0.0f,0.0f,0.0f}};
		
	}
	uint32_t noobTextureHandle = TextureManager::LoadTexture("Resources/Result/Texture/Rank/Noob.png");
	uint32_t BeginnerTextureHandle = TextureManager::LoadTexture("Resources/Result/Texture/Rank/Beginner.png");
	uint32_t NormalTextureHandle = TextureManager::LoadTexture("Resources/Result/Texture/Rank/Normal.png");
	uint32_t expertTextureHandle = TextureManager::LoadTexture("Resources/Result/Texture/Rank/Expert.png");
	uint32_t masterTextureHandle = TextureManager::LoadTexture("Resources/Result/Texture/Rank/Master.png");
	
	
	rankSprite_[0]->LoadTextureHandle(noobTextureHandle);
	rankSprite_[1]->LoadTextureHandle(BeginnerTextureHandle);
	rankSprite_[2]->LoadTextureHandle(NormalTextureHandle);
	rankSprite_[3]->LoadTextureHandle(expertTextureHandle);
	rankSprite_[4]->LoadTextureHandle(masterTextureHandle);

	for (int i = 0; i < RANK_AMOUNT_; i++) {
		rankAllPosition_[i] = {{0.0f,0.0f},{0.0f,720.0f},{1280.0f,0.0f},{1280.0f,720.0f}};
		rankSprite_[i]->SetAllPosition(rankAllPosition_[i]);
	}

#pragma endregion

#pragma region コメント
	//コメント
	for (int i = 0; i < RANK_AMOUNT_; i++) {
		commentSprite_[i] = new Sprite();
		commentTransform_[i]  = {{1.5f,1.5f,1.0f},{0.0f,0.0f,0.0f},{60.0f,300.0f,0.0f}};
	}
	
	uint32_t noobCommentTextureHandle = TextureManager::LoadTexture("Resources/Result/Texture/Comment/NoobComment.png");
	uint32_t BeginnerCommentTextureHandle = TextureManager::LoadTexture("Resources/Result/Texture/Comment/BeginnerComment.png");
	uint32_t NormalCommentTextureHandle = TextureManager::LoadTexture("Resources/Result/Texture/Comment/NormalComment.png");
	uint32_t expertCommentTextureHandle = TextureManager::LoadTexture("Resources/Result/Texture/Comment/ExpertComment.png");
	uint32_t masterCommentTextureHandle = TextureManager::LoadTexture("Resources/Result/Texture/Comment/MasterComment.png");
	

	commentSprite_[0]->LoadTextureHandle(noobCommentTextureHandle);
	commentSprite_[1]->LoadTextureHandle(BeginnerCommentTextureHandle);
	commentSprite_[2]->LoadTextureHandle(NormalCommentTextureHandle);
	commentSprite_[3]->LoadTextureHandle(expertCommentTextureHandle);
	commentSprite_[4]->LoadTextureHandle(masterCommentTextureHandle);


	for (int i = 0; i < RANK_AMOUNT_; i++) {
		commentAllPosition_[i] = {{0.0f,0.0f},{0.0f,150.0f},{200.0f,0.0f},{200.0f,150.0f}};
		commentSprite_[i]->SetAllPosition(commentAllPosition_[i]);
	}
	
#pragma endregion

#pragma region 敵

	for (int i = 0; i < ENMEY_AMOUNT_; i++) {
		enemySprite_[i] = { new Sprite()};
		
	}
	uint32_t enemyTextureHandle_[ENMEY_AMOUNT_] = {};
	enemyTextureHandle_[0] = TextureManager::LoadTexture("Resources/Result/Texture/Enemy/enemy1.png");
	enemyTextureHandle_[1] = TextureManager::LoadTexture("Resources/Result/Texture/Enemy/enemy2.png");
	enemyTextureHandle_[2] = TextureManager::LoadTexture("Resources/Result/Texture/Enemy/enemy3.png");
	
	enemyTransform_[0] = {{ENEMY_SIZE_,ENEMY_SIZE_,1.0f},{0.0f,0.0f,0.0f},{600.0f,300.0f,0.0f}};
	enemyTransform_[1] = {{ENEMY_SIZE_,ENEMY_SIZE_,1.0f},{0.0f,0.0f,0.0f},{600.0f,430.0f,0.0f}};
	enemyTransform_[2] = {{ENEMY_SIZE_,ENEMY_SIZE_,1.0f},{0.0f,0.0f,0.0f},{600.0f,560.0f,0.0f}};


	enemySprite_[0]->LoadTextureHandle(enemyTextureHandle_[0]);
	enemySprite_[1]->LoadTextureHandle(enemyTextureHandle_[1]);
	enemySprite_[2]->LoadTextureHandle(enemyTextureHandle_[2]);

	for (int i = 0; i < ENMEY_AMOUNT_; i++) {
		commentAllPosition_[i] = {{0.0f,0.0f},{0.0f,32.0f},{32.0f,0.0f},{32.0f,32.0f}};
		enemySprite_[i]->SetAllPosition(commentAllPosition_[i]);
	}




	//×
	for (int i = 0; i < ENMEY_AMOUNT_; i++) {
		multiplySprite_[i] = new Sprite();
		uint32_t multiplyTextureHandle = TextureManager::LoadTexture("Resources/Result/Texture/Enemy/x.png");
		multiplySprite_[i]->LoadTextureHandle(multiplyTextureHandle);
		multiplyAllPosition_[i] = {{0.0f,0.0f},{0.0f,32.0f},{32.0f,0.0f},{32.0f,32.0f}};
		multiplySprite_[i]->SetAllPosition(multiplyAllPosition_[i]);
	}
	multiplyTransform_[0] = {{MULTIPLY_SIZE_,MULTIPLY_SIZE_,1.0f},{0.0f,0.0f,0.0f},{720.0f,310.0f,0.0f}};
	multiplyTransform_[1] = {{MULTIPLY_SIZE_,MULTIPLY_SIZE_,1.0f},{0.0f,0.0f,0.0f},{720.0f,440.0f,0.0f}};
	multiplyTransform_[2] = {{MULTIPLY_SIZE_,MULTIPLY_SIZE_,1.0f},{0.0f,0.0f,0.0f},{720.0f,570.0f,0.0f}};
	

	





#pragma endregion

#pragma region スコア
	


	smallScore_ = Record::GetInstance()->GetSmallEnemy();
	normalScore_ = Record::GetInstance()->GetNormalEnemy();
	bigScore_ = Record::GetInstance()->GetBigEnemy();


	allScore_ = smallScore_ + normalScore_*2 + bigScore_*3;




	//格付け
	//ここは仮
	if (allScore_ == 0) {
		rankName_ = Noob;
	}
	if (allScore_ > 0 && allScore_<=80) {
		rankName_ = Beginner;
	}
	if (allScore_ > 80 && allScore_<=160) {
		rankName_ = Normal;
	}
	if (allScore_ > 160 && allScore_<=200) {
		rankName_ = Expert;
	}
	if (allScore_ >200) {
		rankName_ = Master;
	}




	const float NUMBER_SIZE_ = 1.5f;

#pragma region 読み込み
	

	uint32_t numberTextureHandle[NUMBER_AMOUNT_];
	numberTextureHandle[0]=TextureManager::LoadTexture("Resources/Result/Texture/Number/0.png");
	numberTextureHandle[1]=TextureManager::LoadTexture("Resources/Result/Texture/Number/1.png");
	numberTextureHandle[2]=TextureManager::LoadTexture("Resources/Result/Texture/Number/2.png");
	numberTextureHandle[3]=TextureManager::LoadTexture("Resources/Result/Texture/Number/3.png");
	numberTextureHandle[4]=TextureManager::LoadTexture("Resources/Result/Texture/Number/4.png");
	numberTextureHandle[5]=TextureManager::LoadTexture("Resources/Result/Texture/Number/5.png");
	numberTextureHandle[6]=TextureManager::LoadTexture("Resources/Result/Texture/Number/6.png");
	numberTextureHandle[7]=TextureManager::LoadTexture("Resources/Result/Texture/Number/7.png");
	numberTextureHandle[8]=TextureManager::LoadTexture("Resources/Result/Texture/Number/8.png");
	numberTextureHandle[9]=TextureManager::LoadTexture("Resources/Result/Texture/Number/9.png");




#pragma endregion


#pragma region 小さい敵のスコア
	for (int i = 0; i < NUMBER_AMOUNT_; i++) {
		smallScoreHundredsPlane_[i] = new Sprite();
		smallScoreTensPlane_[i] = new Sprite();
		smallScoreOnesPlane_[i] = new Sprite();

	}
	
	smallScoreHundredsPlaneTransform_ = {{NUMBER_SIZE_,NUMBER_SIZE_,NUMBER_SIZE_},{0.0f,0.0f,0.0f},{830.0f,300.0f,0.0f}};
	smallScoreTensPlaneTransform_ = {{NUMBER_SIZE_,NUMBER_SIZE_,NUMBER_SIZE_},{0.0f,0.0f,0.0f},{900.0f,300.0f,0.0f}};
	smallScoreOnesPlaneTransform_ = {{NUMBER_SIZE_,NUMBER_SIZE_,NUMBER_SIZE_},{0.0f,0.0f,0.0f},{970.0f,300.0f,0.0f}};

	smallScoreHundredsPlaneAllPosition_ = {{0.0f,0.0f},{0.0f,64.0f},{32.0f,0.0f},{32.0f,64.0f}};
	smallScoreTensPlaneAllPosition_ = {{0.0f,0.0f},{0.0f,64.0f},{32.0f,0.0f},{32.0f,64.0f}};
	smallScoreOnesPlaneAllPosition_ = {{0.0f,0.0f},{0.0f,64.0f},{32.0f,0.0f},{32.0f,64.0f}};
	

	for (int i = 0; i < NUMBER_AMOUNT_; i++) {
		smallScoreHundredsPlane_[i]->LoadTextureHandle(numberTextureHandle[i]);
		smallScoreTensPlane_[i]->LoadTextureHandle(numberTextureHandle[i]);
		smallScoreOnesPlane_[i]->LoadTextureHandle(numberTextureHandle[i]);

		smallScoreHundredsPlane_[i]->SetAllPosition(smallScoreHundredsPlaneAllPosition_);
		smallScoreTensPlane_[i]->SetAllPosition(smallScoreOnesPlaneAllPosition_);
		smallScoreOnesPlane_[i]->SetAllPosition(smallScoreTensPlaneAllPosition_);

	}

#pragma endregion

#pragma region 普通サイズの敵のスコア
	for (int i = 0; i < NUMBER_AMOUNT_; i++) {
		normalScoreHundredsPlane_[i] = new Sprite();
		normalScoreTensPlane_[i] = new Sprite();
		normalScoreOnesPlane_[i] = new Sprite();


	}
	
	normalScoreHundredsPlaneTransform_  = {{NUMBER_SIZE_,NUMBER_SIZE_,NUMBER_SIZE_},{0.0f,0.0f,0.0f},{830.0f,430.0f,0.0f}};
	normalScoreTensPlaneTransform_  = {{NUMBER_SIZE_,NUMBER_SIZE_,NUMBER_SIZE_},{0.0f,0.0f,0.0f},{900.0f,430.0f,0.0f}};
	normalScoreOnesPlaneTransform_  = {{NUMBER_SIZE_,NUMBER_SIZE_,NUMBER_SIZE_},{0.0f,0.0f,0.0f},{970.0f,430.0f,0.0f}};
	

	normalScoreHundredsPlaneAllPosition_ = {{0.0f,0.0f},{0.0f,64.0f},{32.0f,0.0f},{32.0f,64.0f}};
	normalScoreTensPlaneAllPosition_ = {{0.0f,0.0f},{0.0f,64.0f},{32.0f,0.0f},{32.0f,64.0f}};
	normalScoreOnesPlaneAllPosition_ = {{0.0f,0.0f},{0.0f,64.0f},{32.0f,0.0f},{32.0f,64.0f}};
	
	for (int i = 0; i < NUMBER_AMOUNT_; i++) {
		normalScoreHundredsPlane_[i]->LoadTextureHandle(numberTextureHandle[i]);
		normalScoreTensPlane_[i]->LoadTextureHandle(numberTextureHandle[i]);
		normalScoreOnesPlane_[i]->LoadTextureHandle(numberTextureHandle[i]);

		normalScoreHundredsPlane_[i]->SetAllPosition(normalScoreHundredsPlaneAllPosition_);
		normalScoreTensPlane_[i]->SetAllPosition(normalScoreTensPlaneAllPosition_);
		normalScoreOnesPlane_[i]->SetAllPosition(normalScoreOnesPlaneAllPosition_);

	}

	#pragma endregion

#pragma region 大きい敵スコア 
	for (int i = 0; i < NUMBER_AMOUNT_; i++) {
		bigScoreHundredsPlane_[i] = new Sprite();
		bigScoreTensPlane_[i] =  new Sprite();
		bigScoreOnesPlane_[i] =  new Sprite();
	}



	
	bigScoreHundredsPlaneTransform_  = {{NUMBER_SIZE_,NUMBER_SIZE_,NUMBER_SIZE_},{0.0f,0.0f,0.0f},{830.0f,560.0f,0.0f}};
	bigScoreTensPlaneTransform_  = {{NUMBER_SIZE_,NUMBER_SIZE_,NUMBER_SIZE_},{0.0f,0.0f,0.0f},{900.0f,560.0f,0.0f}};
	bigScoreOnesPlaneTransform_  = {{NUMBER_SIZE_,NUMBER_SIZE_,NUMBER_SIZE_},{0.0f,0.0f,0.0f},{970.0f,560.0f,0.0f}};

	bigScoreHundredsPlaneAllPosition_ = { {0.0f,0.0f},{0.0f,64.0f},{32.0f,0.0f},{32.0f,64.0f} };
	bigScoreTensPlaneAllPosition_ = {{0.0f,0.0f},{0.0f,64.0f},{32.0f,0.0f},{32.0f,64.0f}};
	bigScoreOnesPlaneAllPosition_ = {{0.0f,0.0f},{0.0f,64.0f},{32.0f,0.0f},{32.0f,64.0f}};

	for (int i = 0; i < NUMBER_AMOUNT_; i++) {
		bigScoreHundredsPlane_[i]->LoadTextureHandle(numberTextureHandle[i]);
		bigScoreTensPlane_[i]->LoadTextureHandle(numberTextureHandle[i]);
		bigScoreOnesPlane_[i]->LoadTextureHandle(numberTextureHandle[i]);

		bigScoreHundredsPlane_[i]->SetAllPosition(bigScoreHundredsPlaneAllPosition_);
		bigScoreTensPlane_[i]->SetAllPosition(bigScoreTensPlaneAllPosition_);
		bigScoreOnesPlane_[i]->SetAllPosition(bigScoreOnesPlaneAllPosition_);

	}

#pragma endregion



#pragma endregion




#pragma region シークレット
	//シークレット
	konKon_ = new Sprite();
	uint32_t konHandle=TextureManager::LoadTexture("Resources/Result/Texture/Kon.png");
	konKonTransform_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{0.0f,100.0f,0.0f} };
	konKonAllPosition_ = { {0.0f,0.0f},{0.0f,200.0f},{260.0f,0.0f},{260.0f,200.0f} };

	konKon_->LoadTextureHandle(konHandle);
	konKon_->SetAllPosition(konKonAllPosition_);
	


#pragma endregion



	//BGM
	bgm_ = Audio::GetInstance();
	bgmHandle_ = bgm_->LoadWave("Resources/Result/Music/ResultBGM.wav");


	bgm_->PlayWave(bgmHandle_, true);
	bgm_->ChangeVolume(bgmHandle_,0.4f);



	for (int i = 0; i < COMMENT_AMOUNT_; i++) {
		characterComment_[i] = Audio::GetInstance();;
		

	}
	//Noob
	characterCommentHandle_[0] = characterComment_[0]->LoadWave("Resources/Result/Music/CV/Noob.wav");
	characterCommentHandle_[1] = characterComment_[1]->LoadWave("Resources/Result/Music/CV/Beginner.wav");
	characterCommentHandle_[2] = characterComment_[2]->LoadWave("Resources/Result/Music/CV/Normal.wav");
	characterCommentHandle_[3] = characterComment_[3]->LoadWave("Resources/Result/Music/CV/Expert.wav");
	characterCommentHandle_[4] = characterComment_[4]->LoadWave("Resources/Result/Music/CV/Master.wav");







	//SE
	decideSE_ =  Audio::GetInstance();
	decideSEHandle_ = decideSE_->LoadWave("Resources/Result/Music/Decide.wav");;

}

void ResultScene::ImGuiDebug() {

	ImGui::Begin("Record");

	ImGui::InputInt("Small", &smallScore_);
	ImGui::InputInt("Normal", &normalScore_);
	ImGui::InputInt("Big", &bigScore_);

	ImGui::End();


	ImGui::Begin("Rank");
	ImGui::SliderInt("rank", &rankName_, 0, 4);
	ImGui::SliderFloat3("commentPosition", &commentTransform_[0].translate.x, 0.0f, 1280.0f);
	ImGui::End();

	ImGui::Begin("Enemy");
	ImGui::SliderFloat3("enemy1",&enemyTransform_[0].translate.x,0.0f,1280.0f);
	ImGui::SliderFloat3("enemy2",&enemyTransform_[1].translate.x,0.0f,1280.0f);
	ImGui::SliderFloat3("enemy3",&enemyTransform_[2].translate.x,0.0f,1280.0f);
	ImGui::End();

	
	ImGui::Begin("time");

	ImGui::SliderFloat3("SmallHundred", &smallScoreHundredsPlaneTransform_.translate.x,0.0f,1280.0f);
	ImGui::SliderFloat3("SmallTen", &smallScoreTensPlaneTransform_.translate.x,0.0f,1280.0f);
	ImGui::SliderFloat3("SmallOne", &smallScoreOnesPlaneTransform_.translate.x,0.0f,1280.0f);

	ImGui::End();


	
}

/// 更新
void ResultScene::Update(GameManager* gameManager) {
	//ImGui::Begin("j");
	//ImGui::InputInt("all", &allScore_);
	//ImGui::InputInt("nom", &normalScore_);
	//ImGui::InputInt("big", &bigScore_);
	//ImGui::End();
	//ImGuiDebug();
	backSprite->SetTransparency(transparency_);
	characterSprite_->SetTransparency(transparency_);
	characterSprite2_->SetTransparency(transparency_);
	speechBubbleSprite_->SetTransparency(transparency_);


	
	//敵
	for (int i = 0; i < ENMEY_AMOUNT_; i++) {
		enemySprite_[i]->SetTransparency(transparency_);
		multiplySprite_[i]->SetTransparency(transparency_);
	}
	
	for (int i = 0; i < RANK_AMOUNT_; i++) {
		rankSprite_[i]->SetTransparency(transparency_);
		commentSprite_[i]->SetTransparency(transparency_);
	}



	//演出
	//ピスタチオですっ

	
	
		
	switch (rankName_){
		case Noob:
			//何やってんだ
			cvTime_ += 1;
			if (cvTime_ == 1) {
				characterComment_[0]->PlayWave(characterCommentHandle_[0], false);
				characterComment_[0]->ChangeVolume(characterCommentHandle_[0],1.5f);
			}
			

			break;


		case Beginner:
			//Are You OK?
			cvTime_ += 1;
			if (cvTime_ == 1) {
				characterComment_[1]->PlayWave(characterCommentHandle_[1], false);

			}


			break;

		case Normal:
			//一人前
			cvTime_ += 1;
			if (cvTime_ == 1) {
				characterComment_[2]->PlayWave(characterCommentHandle_[2], false);
			}

			break;

		case Expert:
			//あと一歩
			cvTime_ += 1;
			if (cvTime_ == 1) {
				characterComment_[3]->PlayWave(characterCommentHandle_[3], false);
			}

			break;

		case Master:
			//伝説
			cvTime_ += 1;
			if (cvTime_ == 1) {
				characterComment_[4]->PlayWave(characterCommentHandle_[4], false);
			}

			break;
	}



	XINPUT_STATE joyState{};

	if (Input::GetInstance()->GetJoystickState(joyState)) {
		//Aボタン
		if (joyState.Gamepad.wButtons & XINPUT_GAMEPAD_A) {
			triggerButtonATime_ += 1;
		
		}

	}



	if ((input_->GetInstance()->IsTriggerKey(DIK_SPACE) == true) || triggerButtonATime_==1) {

		decideSE_->PlayWave(decideSEHandle_, false);
		decideSE_->ChangeVolume(decideSEHandle_, 0.5f);
		isFadeOut_ = true;
		bgm_->StopWave(bgmHandle_);

	}
	if (isFadeOut_ == true) {
		decideSETime_ = 0;

		transparency_ -= 0.01f;
		if (transparency_ < 0.0f) {
			transparency_ = 0.0f;

			//ローディング
			loadingTime_ += 1;
			if (loadingTime_ > 120) {
				gameManager->ChangeScene(new TitleScene());

			}

		}

	}
	
	

}

/// 描画
void ResultScene::Draw(GameManager* gameManager) {
	//背景
	backSprite->DrawRect(backTransform_);

	//キャラクター表情差分
	if (noob == 1) {
		characterSprite_->DrawRect(characterTransform_);
	}
	if (noob==0) {
	characterSprite2_->DrawRect(characterTransform_);

	}
	
	//吹き出し
	speechBubbleSprite_->DrawRect(speechBubbleTransform_);

	//敵
	for (int i = 0; i < ENMEY_AMOUNT_; i++) {
		enemySprite_[i]->DrawRect(enemyTransform_[i]);
		multiplySprite_[i]->DrawRect(multiplyTransform_[i]);
	}
	
	

	

	switch (rankName_){
		case Noob:
			rankSprite_[0]->DrawRect(rankTransform_[0]);
			commentSprite_[0]->DrawRect(commentTransform_[0]);
			noob = 0;
			
			break;


		case Beginner:
			rankSprite_[1]->DrawRect(rankTransform_[1]);
			commentSprite_[1]->DrawRect(commentTransform_[1]);
			noob = 1;
			break;

		case Normal:
			rankSprite_[2]->DrawRect(rankTransform_[2]);
			commentSprite_[2]->DrawRect(commentTransform_[2]);

			noob = 1;
			break;

		case Expert:
			rankSprite_[3]->DrawRect(rankTransform_[3]);
			commentSprite_[3]->DrawRect(commentTransform_[3]);
			noob = 1;
			break;

		case Master:
			rankSprite_[4]->DrawRect(rankTransform_[4]);
			commentSprite_[4]->DrawRect(commentTransform_[4]);
			konKon_->DrawRect(konKonTransform_);
			noob = 1;
			break;
	}


	//128
	//128/100=1
	//28/10=2
	//128%10=8


	//スコア
	//小さな敵
	smallScorePlace_.hundred = smallScore_ / 100;
	smallScorePlace_.ten = (smallScore_ %100)/10;
	smallScorePlace_.one = smallScore_ % 10;


	smallScoreHundredsPlane_[smallScorePlace_.hundred]->DrawRect(smallScoreHundredsPlaneTransform_);
	smallScoreTensPlane_[smallScorePlace_.ten]->DrawRect(smallScoreTensPlaneTransform_);
	smallScoreOnesPlane_[smallScorePlace_.one]->DrawRect(smallScoreOnesPlaneTransform_);


	//普通の敵
	normalScorePlace_.hundred = normalScore_ / 100;
	normalScorePlace_.ten = (normalScore_ %100)/10;
	normalScorePlace_.one = normalScore_ % 10;


	normalScoreHundredsPlane_[normalScorePlace_.hundred]->DrawRect(normalScoreHundredsPlaneTransform_);
	normalScoreTensPlane_[normalScorePlace_.ten]->DrawRect(normalScoreTensPlaneTransform_);
	normalScoreOnesPlane_[normalScorePlace_.one]->DrawRect(normalScoreOnesPlaneTransform_);





	//大きい敵
	bigScorePlace_.hundred = bigScore_ / 100;
	bigScorePlace_.ten = (bigScore_ %100)/10;
	bigScorePlace_.one = bigScore_ % 10;


	bigScoreHundredsPlane_[bigScorePlace_.hundred ]->DrawRect(bigScoreHundredsPlaneTransform_);
	bigScoreTensPlane_[bigScorePlace_.ten ]->DrawRect(bigScoreTensPlaneTransform_);
	bigScoreOnesPlane_[bigScorePlace_.one ]->DrawRect(bigScoreOnesPlaneTransform_);



}

/// デストラクタ
ResultScene::~ResultScene() {
	decideSE_->Release();
		
}


