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

#pragma region 数字
	//32x64
	for (int i = 0; i < NUMBER_AMOUNT_; i++) {
		numberSprite_[i] =new Sprite();
		numberAllPosition_[i] = { {0.0f,0.0f},{0.0f,64.0f},{32.0f,0.0f},{32.0f,64.0f} };
	
	}

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



	Transform numberTransform_ = {};


	//スコア


#pragma endregion



	//キャラクター
	characterSprite_ = new Sprite() ;
	characterTransform_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{0.0f,500.0f,0.0f} };
	uint32_t characterTextureHandle = TextureManager::LoadTexture("Resources/Result/Texture/Character.png");
	characterSprite_->LoadTextureHandle(characterTextureHandle);
	characterAllPosition_ = { {0.0f,0.0f},{0.0f,256.0f},{256.0f,0.0f},{256.0f,256.0f} };
	characterSprite_->SetAllPosition(characterAllPosition_);


	//吹き出し
	speechBubbleSprite_ = new Sprite() ;
	speechBubbleTransform_ = { {scaleSize_,scaleSize_,1.0f},{0.0f,0.0f,0.0f},{60.0f,300.0f,0.0f} };
	uint32_t speechBublleTextureHandle = TextureManager::LoadTexture("Resources/Result/Texture/Comment/SpeechBubble.png");
	speechBubbleSprite_->LoadTextureHandle(speechBublleTextureHandle);
	speechBubbleAllPosition_ = { {0.0f,0.0f},{0.0f,150.0f},{200.0f,0.0f},{200.0f,150.0f} };
	speechBubbleSprite_->SetAllPosition(speechBubbleAllPosition_);

	//ランク
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

	//BGM
	bgm_ = Audio::GetInstance();
	bgmHandle_ = bgm_->LoadWave("Resources/Result/Music/ResultBGM.wav");


	bgm_->PlayWave(bgmHandle_, true);
	bgm_->ChangeVolume(bgmHandle_,0.7f);



	//SE
	decideSE_ =  Audio::GetInstance();
	decideSEHandle_ = decideSE_->LoadWave("Resources/Result/Music/Decide.wav");;

}

void ResultScene::ImGuiDebug() {
	ImGui::Begin("Character");

	ImGui::SliderFloat3("Translate", &characterTransform_.translate.x, 0.0f, 1280.0f);
	ImGui::End();

	ImGui::Begin("SpeechBubble");
	ImGui::SliderFloat3("Rotate", &speechBubbleTransform_.scale.x, 0.0f, 5.0f);
	ImGui::SliderFloat3("Translate", &speechBubbleTransform_.translate.x, 0.0f, 1280.0f);
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

	ImGui::InputInt("decideSE", &decideSETime_);
	ImGui::End();

}

/// 更新
void ResultScene::Update(GameManager* gameManager) {

	ImGuiDebug();
	backSprite->SetTransparency(transparency_);
	characterSprite_->SetTransparency(transparency_);
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

	
	


#pragma region デバッグ
	if (input_->GetInstance()->IsTriggerKey(DIK_0) == true) {
		rankName_ = 0;
	}
	if (input_->GetInstance()->IsTriggerKey(DIK_1) == true) {
		rankName_ = 1;
	}
	if (input_->GetInstance()->IsTriggerKey(DIK_2) == true) {
		rankName_ = 2;
	}
	if (input_->GetInstance()->IsTriggerKey(DIK_3) == true) {
		rankName_ = 3;
	}
	if (input_->GetInstance()->IsTriggerKey(DIK_4) == true) {
		rankName_ = 4;
	}

#pragma endregion
	
	if (input_->GetInstance()->IsTriggerKey(DIK_SPACE) == true) {
		
		decideSE_->PlayWave(decideSEHandle_, false);
		decideSE_->ChangeVolume(decideSEHandle_,0.5f);
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
	backSprite->DrawRect(backTransform_);
	characterSprite_->DrawRect(characterTransform_);
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

			break;


		case Beginner:
			rankSprite_[1]->DrawRect(rankTransform_[1]);
			commentSprite_[1]->DrawRect(commentTransform_[1]);

			break;

		case Normal:
			rankSprite_[2]->DrawRect(rankTransform_[2]);
			commentSprite_[2]->DrawRect(commentTransform_[2]);


			break;

		case Expert:
			rankSprite_[3]->DrawRect(rankTransform_[3]);
			commentSprite_[3]->DrawRect(commentTransform_[3]);

			break;

		case Master:
			rankSprite_[4]->DrawRect(rankTransform_[4]);
			commentSprite_[4]->DrawRect(commentTransform_[4]);

			break;
	}


}

/// デストラクタ
ResultScene::~ResultScene() {
	decideSE_->Release();
		
}


