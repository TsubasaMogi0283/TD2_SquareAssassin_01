#pragma once
#include "TextureManager/TextureManager.h"
#include "AllGameScene/GameManager/GameManager.h"
#include "AllGameScene/GameManager/IGameScene.h"
class Enemy {
public:
	void Initialize(const std::string& directoryPath, const std::string& fileName, Transform transformModel, Vector3 move);
	void Update();
	void Dorw();
	void Release();
private:
	Model* enemy_ = nullptr;
	Transform transformModel_ = {};
	Vector3 move_ ;
};
