#include "Player.h"

void Player::Initialize(const std::string& directoryPath,
	const std::string& fileName, Transform transform)
{

	model_ = new Model();
	model_->CreateObject(directoryPath, fileName);
	input_ = Input::GetInstance();

	// ワールドトランスフォームの初期化

	fixedX = 3.7f;
	fixedY = 2;
	transform_ = transform;
}

void Player::Update(){

	XINPUT_STATE joyState{};

		

	// 今どこの辺にいるか
	if (transform_.translate.y <= -fixedY) {
		nowPlayerSide = up;
	}
	else if (transform_.translate.y >= fixedY) {
		nowPlayerSide = down;
	}
	else if (transform_.translate.x <= -fixedX) {
		nowPlayerSide = left;
	}
	else if (transform_.translate.x >= fixedX) {
		nowPlayerSide = right;
	}

	// 横移動
	if (transform_.translate.y >= fixedY || transform_.translate.y <= -fixedY) {
		if (input_->GetInstance()->IsPushKey(DIK_A) || input_->GetInstance()->IsPushKey(DIK_LEFT)) {
			transform_.translate.x -= kPlayerSpeed;
		}
		if (input_->GetInstance()->IsPushKey(DIK_D) || input_->GetInstance()->IsPushKey(DIK_RIGHT)) {
			transform_.translate.x += kPlayerSpeed;
		}


		//コントローラー版
		if (Input::GetInstance()->GetJoystickState(joyState)) {

			//右
			if (joyState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT) {
				transform_.translate.x += kPlayerSpeed;
			}
			//左
			if (joyState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT) {
				transform_.translate.x -= kPlayerSpeed;
			}

		}


	}

	// 縦移動
	if (transform_.translate.x >= fixedX || transform_.translate.x <= -fixedX) {
		if ((input_->GetInstance()->IsPushKey(DIK_W)) || 
			(input_->GetInstance()->IsPushKey(DIK_UP))){
			transform_.translate.y += kPlayerSpeed;
		}
		if ((input_->GetInstance()->IsPushKey(DIK_S)) ||
			(input_->GetInstance()->IsPushKey(DIK_DOWN))){
			transform_.translate.y -= kPlayerSpeed;
		}

		//コントローラー版
		if (Input::GetInstance()->GetJoystickState(joyState)) {

			//右
			if (joyState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN) {
				transform_.translate.y -= kPlayerSpeed;
			}
			//左
			if (joyState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP) {
				transform_.translate.y += kPlayerSpeed;
			}

		}

	}






	// チャージ処理
	if (input_->GetInstance()->IsTriggerKey(DIK_SPACE)) {
		playerChageFrame++;
		isPlayerChage = true;
	}
	

	if (Input::GetInstance()->GetJoystickState(joyState)) {

		if (joyState.Gamepad.wButtons & XINPUT_GAMEPAD_A) {
			triggerButtonATime_ += 1;
			
		}

		if (triggerButtonATime_ == 1) {
			triggerButtonATime_ = 0;
			playerChageFrame++;
			isPlayerChage = true;
		}
		

	}


	// ボタンを離したとき
	if ((isPlayerChage && !input_->GetInstance()->IsTriggerKey(DIK_SPACE))) {
		if (playerChageFrame >= 90) {
			isPlayerAttack = 2; // 強攻撃
			move =0.2f;
		}
		else {
			isPlayerAttack = 1; // 弱攻撃
			move = 0.2f;
		}
		playerAttackTimer = kPlayerAttackFrame; // プレイヤーの攻撃タイマーをセット
		playerChageFrame = 0;  // プレイヤーのチャージ中フレームをリセット
		isPlayerChage = false; // プレイヤーチャージフラグをオフに戻す
		attackRangePos = transform_.translate;
	}






	switch (nowPlayerSide) {
	case up: // 上にいたら下に
		transform_.translate.y += move;
		if (transform_.translate.y> fixedY) {
			move = 0;
		}
		break;
	case down: // 下にいたら上に
		transform_.translate.y -= move;
		if (transform_.translate.y < -fixedY) {
			move = 0;
		}
		break;
	case left: // 左にいたら右に

		transform_.translate.x += move;
		if (transform_.translate.x > fixedX) {
			move = 0;
		}
		break;
	case right: // 右にいたら左に
		transform_.translate.x -= move;
		if (transform_.translate.x < -fixedX) {
			move = 0;
		}
		break;
	}

	// 攻撃中の処理
	if (isPlayerAttack) {
		playerAttackTimer--; // タイマー
		if (!playerAttackTimer) {
			// タイマーが0になったら攻撃中フラグをオフに
			isPlayerAttack = 0;
		}
	}

	// clampでプレイヤーの移動範囲制限
	transform_.translate.y = min(max(-fixedY, transform_.translate.y), fixedY);
	transform_.translate.x = min(max(-fixedX, transform_.translate.x), fixedX);


}

void Player::Draw()
{
	model_->Draw(transform_);
}
Vector3 Player::GetWorldPosition() {
	Vector3 worldPos;

	worldPos.x = transform_.translate.x;
	worldPos.y = transform_.translate.y;
	worldPos.z = transform_.translate.z;

	return worldPos;
}