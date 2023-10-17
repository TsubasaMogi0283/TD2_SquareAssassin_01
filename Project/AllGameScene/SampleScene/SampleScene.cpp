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
	for (int i = 0; i < 20; i++) {
		enemy_[i]->Release();
	}
}

/// <summary>
/// 初期化
/// </summary>
void SampleScene::Initialize(GameManager* gameManager) {

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
	for (int i = 0; i < 20; i++) {
		enemy_[i]->Update();
	}
}

/// <summary>
/// 描画
/// </summary>
void SampleScene::Draw(GameManager* gameManager) {
	for (int i = 0; i < 20; i++) {
		enemy_[i]->Dorw();
	}
}
