#include "Enemy.h"
#include <Polygon/Model/Model.h>
void Enemy::Initialize(
	float x, float y, float kCharacterSpeedx,
	float kCharacterSpeedy) {
	model_ = new Model();
	model_->CreateObject("Resources/Sample", "enemy.obj");
	transform_.translate.x = x;
	transform_.translate.y = y;
	transform_.translate.z = 70;
	transform_.scale = { 1.0f, 1.0f, 1.0f };
	kCharacterSpeedX_ = kCharacterSpeedx;
	kCharacterSpeedY_ = kCharacterSpeedy;
	move.x = kCharacterSpeedX_;
	move.y = kCharacterSpeedY_;
}

void Enemy::Update() {

	float inputFloat3[3] = {
		transform_.translate.x, transform_.translate.y,
		transform_.translate.z };
	///

	if (transform_.translate.x > 35.0) {

		move.x *= -1;
	}

	if (transform_.translate.x < -35.0) {

		move.x *= -1;
	}

	if (transform_.translate.y > 20.0) {

		move.y *= -1;
	}

	if (transform_.translate.y < -20.0) {

		move.y *= -1;
	}

	transform_.translate = Add(transform_.translate, move);
	/*transform_.matWorld_ = MakeAffineMatrix(
		transform_.scale_, transform_.rotation_, transform_.translate);*/

	ImGui::Begin("enemy");
	ImGui::SliderFloat3("trns", inputFloat3, -33.0f, 33.0f);
	ImGui::SliderFloat("kCharacterSpeed", &kCharacterSpeedX_, -5.0f, 5.0f);
	ImGui::End();

	///

	/*const float kMoveLimitX = 33;
	const float kMoveLimitY = 18;
	worldTransform_.translation_.x = max(worldTransform_.translation_.x, -kMoveLimitX);
	worldTransform_.translation_.x = min(worldTransform_.translation_.x, +kMoveLimitX);
	worldTransform_.translation_.y = max(worldTransform_.translation_.y, -kMoveLimitY);
	worldTransform_.translation_.y = min(worldTransform_.translation_.y, +kMoveLimitY);
*/
}

void Enemy::Draw() {
	if (!isDeath) {
		model_->Draw(transform_);
	}
}

void Enemy::OnCollision() {
	isDeath = true;
}
