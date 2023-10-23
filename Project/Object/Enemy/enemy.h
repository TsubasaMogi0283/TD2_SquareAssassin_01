#pragma once
#include "TextureManager/TextureManager.h"
#include "AllGameScene/GameManager/GameManager.h"
#include "AllGameScene/GameManager/IGameScene.h"
class Enemy {
public:
	void Initialize(const std::string& directoryPath, const std::string& fileName, Transform transformModel, Vector3 move);
	void Update();
	void Draw();
	void Release();
private:
	Model* model_ = nullptr;
	Transform transformModel_ = {};
	Vector3 move_ ;
	int32_t hpCount_;
	//int32_t killCount_;
	int32_t timCount_;
	int32_t isLive_;
};
