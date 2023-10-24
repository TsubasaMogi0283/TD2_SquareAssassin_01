#pragma once
#include "TextureManager/TextureManager.h"
#include "AllGameScene/GameManager/GameManager.h"
#include "AllGameScene/GameManager/IGameScene.h"
class Player {
public:
	/// <summary>
	/// コンストクラタ
	/// </summary>
//	Player();

	/// <summary>
	/// デストラクタ
	/// </summary>
//	~Player();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(const std::string& directoryPath,
		const std::string& fileName, Transform transform);

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();
	float GetRadius() { return radius_; }
	/// <summary>
	/// 描画
	/// </summary>
	//void CollisionDraw(ViewProjection& viewprojection);

	float kPlayerSpeed =0.07f ; // プレイヤーのスピード規定値
	int playerChageFrame = 0;          // プレイヤーがチャージしているフレーム数
	bool isPlayerChage = false;        // プレイヤーがチャージしているか
	int isPlayerAttack = 0;            // プレイヤーが攻撃中か
	const int kPlayerAttackFrame = 60; // プレイヤーの攻撃時間規定値
	int playerAttackTimer = 0; // プレイヤーが攻撃しているフレーム数タイマー
	const int kAttackRangeWeak = 6;    // 弱攻撃の範囲
	const int kAttackRangeStrong = 10; // 強攻撃の範囲

	enum side { up, down, left, right };
	int nowPlayerSide = up; // 現在プレイヤーがどこの辺にいるか

	Vector3 attackRangePos{};
	Vector3 GetWorldPosition();

private:
	// ワールドトランスフォーム
	Transform transform_;
	

	// スプライト
	//Sprite* sprite_ = nullptr;

	Input* input_ = nullptr;

	// 3Dモデル
	Model* model_ = nullptr;

	float fixedY;
	float fixedX;
	float move = 0;
	const float radius_ = 0.2f;


};

