#include "enemy.h"

void Enemy::Initialize(const std::string& directoryPath,
	const std::string& fileName, Transform transformModel,
	Vector3 move, int32_t hpCount)
{

	model_ = new Model();
	model_->CreateObject(directoryPath, fileName);
	transformModel_ = transformModel;
	move_ = move;
	hpCount_ = hpCount;

	isLive_ = 1;

}

void Enemy::Update()
{
	//transformModel_.translate.x += 0.2f;
	if (transformModel_.translate.x > 3.3) {

		move_.x *= -1;
	}

	if (transformModel_.translate.x < -3.3) {

		move_.x *= -1;
	}

	if (transformModel_.translate.y > 1.5) {

		move_.y *= -1;
	}

	if (transformModel_.translate.y < -1.5) {

		move_.y *= -1;
	}

	transformModel_.translate = Add(transformModel_.translate, move_);
	if (hpCount_ == 0) {
		isLive_ = 0;
	}
	if (isLive_ == 0) {
		timCount_ += 1;
	}
	if (timCount_ == 60) {
		isLive_ = 1;
		timCount_ = 0;
	}

}

void Enemy::Draw()
{
	if (isLive_ == 1) {

		model_->Draw(transformModel_);

	}

}


void Enemy::Release() {

	model_->Release();

}
