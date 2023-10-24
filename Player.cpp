#include "Player.h"
#include <cassert>
#include <iostream>
#include <algorithm>

Player::Player() {

}

Player::~Player() {
	delete sprite_;
	model_->Release();
	delete model_;
}

void Player::Initialize() {

	model_ = new Model();
	model_->CreateObject("Resources/Player", "playre.obj");

	input_ = Input::GetInstance();

	// ワールドトランスフォームの初期化
	transform_ = { {1.0f,1.0f,1.0f},{0.0f,0.0f,0.0f},{15.0f,15.0f,70.0f} };
	transform_.translate.y = 0;
}

void Player::Update() {

	ImGui::Begin("Player");
	ImGui::SliderFloat3("Translation", reinterpret_cast<float*>(&transform_.translate.x), -100, 100);
	ImGui::End();

	/*ImGui::Begin("Player");
	ImGui::InputFloat3("translate", &transform_.translate.x);
	ImGui::SliderFloat3("translate", &transform_.translate.x, -10.0f, 10.0f);
	ImGui::End();*/

	//今どこの辺にいるか
	if (transform_.translate.y <= -15) {
		nowPlayerSide = up;
	} else if (transform_.translate.y >= 15) {
		nowPlayerSide = down;
	} else if (transform_.translate.x <= -15) {
		nowPlayerSide = left;
	} else if (transform_.translate.x >= 15) {
		nowPlayerSide = right;
	}

	//横移動
	if (transform_.translate.y >= 15 || transform_.translate.y <= -15) {
		if(input_->GetInstance()->IsPushKey(DIK_A)){
			transform_.translate.x -= kPlayerSpeed;
		}
		if (input_->GetInstance()->IsPushKey(DIK_D)) {
			transform_.translate.x += kPlayerSpeed;
		}
	}

	//縦移動
	if (transform_.translate.x >= 15 || transform_.translate.x <= -15) {
		if (input_->GetInstance()->IsPushKey(DIK_W)) {
			transform_.translate.y += kPlayerSpeed;
		}
		if (input_->GetInstance()->IsPushKey(DIK_S)) {
			transform_.translate.y -= kPlayerSpeed;
		}
	}

	//チャージ処理
	if (input_->GetInstance()->IsPushKey(DIK_SPACE)) {
		playerChageFrame++;
		isPlayerChage = true;
	}
	
	//ボタンを離したとき
	if (isPlayerChage && !input_->GetInstance()->IsPushKey(DIK_SPACE)) {
		if (playerChageFrame >= 90) {
			isPlayerAttack = 2;//強攻撃
		} else {
			isPlayerAttack = 1;//弱攻撃
		}

		switch (nowPlayerSide) {
		case up://上にいたら下に
			transform_.translate.y = 15;
			break;
		case down://下にいたら上に
			transform_.translate.y = -15;
			break;
		case left://左にいたら右に
			transform_.translate.x = 15;
			break;
		case right://右にいたら左に
			transform_.translate.x = -15;
			break;
		}

		playerAttackTimer = kPlayerAttackFrame; // プレイヤーの攻撃タイマーをセット
		playerChageFrame = 0;//プレイヤーのチャージ中フレームをリセット
		isPlayerChage = false;//プレイヤーチャージフラグをオフに戻す
		attackRangePos = transform_.translate;
	}

	//攻撃中の処理
	if (isPlayerAttack) {
		playerAttackTimer--;//タイマー
		if (!playerAttackTimer) {
			//タイマーが0になったら攻撃中フラグをオフに
			isPlayerAttack = 0;
		}
	}

	//clampでプレイヤーの移動範囲制限
	transform_.translate.y = min(max(-15, transform_.translate.y), 15);
	transform_.translate.x = min(max(-15, transform_.translate.x), 15);

}

void Player::Draw() {

	//プレイヤーモデルの表示
	model_->Draw(transform_);

}

void Player::CollisionDraw() {

	//PrimitiveDrawer::GetInstance()->SetViewProjection(&viewprojection);
	//// 当たり判定の表示

	//int attackRange{};

	//if (isPlayerAttack == 2) {
	//	attackRange = kAttackRangeStrong;
	//} else if (isPlayerAttack == 1) {
	//	attackRange = kAttackRangeWeak;
	//}

	//if (isPlayerAttack) {
	//	switch (nowPlayerSide) {
	//	case up:
	//		PrimitiveDrawer::GetInstance()->DrawLine3d(
	//			{ attackRangePos.x - attackRange / 2, attackRangePos.y, attackRangePos.z },
	//			{ attackRangePos.x - attackRange / 2, attackRangePos.y + 30, attackRangePos.z },
	//			{ 1.0f, 0.0f, 0.0f, 1.0f });
	//		PrimitiveDrawer::GetInstance()->DrawLine3d(
	//			{ attackRangePos.x + attackRange / 2, attackRangePos.y, attackRangePos.z },
	//			{ attackRangePos.x + attackRange / 2, attackRangePos.y + 30, attackRangePos.z },
	//			{ 1.0f, 0.0f, 0.0f, 1.0f });
	//		break;
	//	case down:
	//		PrimitiveDrawer::GetInstance()->DrawLine3d(
	//			{ attackRangePos.x - attackRange / 2, attackRangePos.y, attackRangePos.z },
	//			{ attackRangePos.x - attackRange / 2, attackRangePos.y - 30, attackRangePos.z },
	//			{ 1.0f, 0.0f, 0.0f, 1.0f });
	//		PrimitiveDrawer::GetInstance()->DrawLine3d(
	//			{ attackRangePos.x + attackRange / 2, attackRangePos.y, attackRangePos.z },
	//			{ attackRangePos.x + attackRange / 2, attackRangePos.y - 30, attackRangePos.z },
	//			{ 1.0f, 0.0f, 0.0f, 1.0f });
	//		break;
	//	case left:
	//		PrimitiveDrawer::GetInstance()->DrawLine3d(
	//			{ attackRangePos.x, attackRangePos.y - attackRange / 2, attackRangePos.z },
	//			{ attackRangePos.x + 30, attackRangePos.y - attackRange / 2, attackRangePos.z },
	//			{ 1.0f, 0.0f, 0.0f, 1.0f });
	//		PrimitiveDrawer::GetInstance()->DrawLine3d(
	//			{ attackRangePos.x, attackRangePos.y + attackRange / 2, attackRangePos.z },
	//			{ attackRangePos.x + 30, attackRangePos.y + attackRange / 2, attackRangePos.z },
	//			{ 1.0f, 0.0f, 0.0f, 1.0f });
	//		break;
	//	case right:
	//		PrimitiveDrawer::GetInstance()->DrawLine3d(
	//			{ attackRangePos.x, attackRangePos.y - attackRange / 2, attackRangePos.z },
	//			{ attackRangePos.x - 30, attackRangePos.y - attackRange / 2, attackRangePos.z },
	//			{ 1.0f, 0.0f, 0.0f, 1.0f });
	//		PrimitiveDrawer::GetInstance()->DrawLine3d(
	//			{ attackRangePos.x, attackRangePos.y + attackRange / 2, attackRangePos.z },
	//			{ attackRangePos.x - 30, attackRangePos.y + attackRange / 2, attackRangePos.z },
	//			{ 1.0f, 0.0f, 0.0f, 1.0f });
	//		break;
	//	}
	//}

}
