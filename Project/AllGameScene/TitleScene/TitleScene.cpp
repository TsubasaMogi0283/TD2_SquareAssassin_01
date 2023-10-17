#include "TitleScene.h"

//コンストラクタ
TitleScene::TitleScene() {

}

/// デストラクタ
TitleScene::~TitleScene() {
	input_ = Input::GetInstance();
}

/// 初期化
void TitleScene::Initialize(GameManager* gameManager) {
	input_->Initialize();


	uint32_t titleTextureHandle = TextureManager::LoadTexture("Resources/Title/Texture/Title.png");
	uint32_t startTextureHandle= TextureManager::LoadTexture("Resources/Title/Texture/TitleStart.png");


	transformSprite_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{0.0f,0.0f,0.0f} };

	titleSprite = new Sprite();
	titleSprite->LoadTextureHandle(titleTextureHandle);
	spriteAllPosition_ = { {0.0f,0.0f},{0.0f,720.0f},{1280.0f,0.0f},{1280.0f,720.0f} };
	titleSprite->SetAllPosition(spriteAllPosition_);

	transformSprite_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{0.0f,0.0f,0.0f} };
	
	startSprite = new Sprite();
	startSprite->LoadTextureHandle(startTextureHandle);
	spriteAllPosition2_ = { {0.0f,0.0f},{0.0f,720.0f},{1280.0f,0.0f},{1280.0f,720.0f} };
	startSprite->SetAllPosition(spriteAllPosition2_);



	//選択画面
	selectSprite_ = new Sprite();
	uint32_t selectTextureHandle= TextureManager::LoadTexture("Resources/Title/Texture/Select/Select.png");
	selectSprite_->LoadTextureHandle(selectTextureHandle);
	selectspriteAllPosition_= { {0.0f,0.0f},{0.0f,720.0f},{1280.0f,0.0f},{1280.0f,720.0f} };
	startSprite->SetAllPosition(spriteAllPosition_);


	titleBGM_ = Audio::GetInstance();
	titleBGM_->Initialize();
	titleSoundData_ = titleBGM_->LoadWave("Resources/Title/Music/TitleBGM.wav");


	titleBGM_->PlayWave(titleSoundData_ ,true);
	


}

/// 更新
void TitleScene::Update(GameManager* gameManager) {

	switch (allTitleScene_) {
	default:
		//スペースキーかAボタンでスタートのシーン
	case Start:
		//透明度の変更
		startSprite->SetTransparency(startTransparency);
		

		//0.5秒ずつ透明度が変わる
		textureChangeTime_ += 1;
		if (textureChangeTime_ > 0) {
			if (textureChangeTime_ > 0 && textureChangeTime_ <= SECOND_/2) {
				startTransparency = 1.0f;
			}
			if (textureChangeTime_ > SECOND_/2 && textureChangeTime_ <= SECOND_) {
				startTransparency = 0.0f;
			}
			if (textureChangeTime_ > SECOND_) {
				textureChangeTime_ = 0;
			}
		}

		//スペースを押したらSelectになる
		if (input_->IsTriggerKey(DIK_SPACE)) {
			allTitleScene_ = Select;
		}


		break;


		//「メインのゲーム」か「チュートリアル」を選択する
	case Select:







		break;
	}
	
	
	



}

/// 描画
void TitleScene::Draw(GameManager* gameManager) {
	switch (allTitleScene_) {
	default:
		//スペースキーかAボタンでスタートのシーン
	case Start:
		//下地
		titleSprite->DrawRect(transformSprite_);
		//スタート
		startSprite->DrawRect(transformSprite_);

		//「メインのゲーム」か「チュートリアル」を選択する
	case Select:
		//下地
		titleSprite->DrawRect(transformSprite_);
		//選択
		selectSprite_->DrawRect(transformSprite_);
	}

	
}

