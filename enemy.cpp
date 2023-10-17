#include "enemy.h"

void Enemy::Initialize(const std::string& directoryPath, const std::string& fileName, Transform transformModel, Vector3 move)
{
	enemy_ = new Model();
	enemy_->CreateObject(directoryPath, fileName);
	transformModel_ = transformModel;
	move_ = move;
	//= { {0.1f,0.1f,0.1f},{0.0f,3.0f,0.0f},{0.0f,0.0f,0.0f} };

}

void Enemy::Update()
{
	//transformModel_.translate.x += 0.2f;
	if (transformModel_.translate.x > 3.0) {

		move_.x *= -1;
	}

	if (transformModel_.translate.x < -3.0) {

		move_.x *= -1;
	}

	if (transformModel_.translate.y > 2.0) {

		move_.y *= -1;
	}

	if (transformModel_.translate.y < -2.0) {

		move_.y *= -1;
	}

	transformModel_.translate = Add(transformModel_.translate, move_);
	/*worldTransform_.matWorld_ = MakeAffineMatrix(
		worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);*/

}

void Enemy::Dorw()
{
	enemy_->Draw(transformModel_);
}

void Enemy::Release(){

	enemy_->Release();

}
