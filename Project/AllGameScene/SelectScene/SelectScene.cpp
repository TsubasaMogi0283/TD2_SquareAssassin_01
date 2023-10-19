#include "SelectScene.h"
#include "AllGameScene/TutorialScene/TutorialScene.h"

//コンストラクタ
SelectScene::SelectScene() {

}

/// 初期化
void SelectScene::Initialize(GameManager* gameManager) {
	uint32_t selectTextureHandle = TextureManager::LoadTexture("Resources/Select/Texture/SelectTexture.png");

	selectSpriteTransform_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{0.0f,0.0f,0.0f} };

	selectSprite = new Sprite();
	selectSprite->LoadTextureHandle(selectTextureHandle);
	spriteAllPosition_ = { {0.0f,0.0f},{0.0f,720.0f},{1280.0f,0.0f},{1280.0f,720.0f} };
	selectSprite->SetAllPosition(spriteAllPosition_);


	

}

/// 更新
void SelectScene::Update(GameManager* gameManager) {

	ImGui::Begin("Select");
	ImGui::Text("1 To GameScene");
	ImGui::Text("2 To GameScene");


	ImGui::End();


	selectSprite->SetTransparency(selectTextureTransparency_);

	//フェードイン
	if (isFadeIn_ == true) {
		selectTextureTransparency_ += 0.01f;
		if (selectTextureTransparency_ > 1.0f) {
			selectTextureTransparency_ = 1.0f;
			isFadeIn_ = false;
		}
	
	}
	



	//選択画面
	if (isFadeIn_ == false) {
		//今の所キーボードは仮置き
		//1を押したらSelectになる
		if (input_->GetInstance()->IsTriggerKey(DIK_1) == true) {
			nextScene_ = Game;
			isFadeOut_ = true;
		}
		//2を押したらTutorialになる
		if (input_->GetInstance()->IsTriggerKey(DIK_2) == true) {
			
			nextScene_ = Tutorial;
			isFadeOut_ = true;
		}
	}



	//フェードアウト
	if (isFadeOut_ == true) {
		selectTextureTransparency_ -= 0.01f;
		if (selectTextureTransparency_ < 0.0f) {
			selectTextureTransparency_ = 0.0f;

			//GameSceneへ
			if (nextScene_ == Game) {

			}
			//TutorialSceneへ
			if (nextScene_ == Tutorial) {
				waitingTime_ += 1;

				if (waitingTime_ > SECOND_ * 3) {
					gameManager->ChangeScene(new TutorialScene());
				}
			}



		}
	}

	

	
}

/// 描画
void SelectScene::Draw(GameManager* gameManager) {
	selectSprite->DrawRect(selectSpriteTransform_);
}


/// デストラクタ
SelectScene::~SelectScene() {
	delete selectSprite;
}