#pragma once
#include <Math/Vector/Vector3.h>
#include <Input/Input.h>
#include <Polygon/Sprite/Sprite.h>
#include <Polygon/Model/Model.h>

class Player {
public:
	/// <summary>
	/// コンストクラタ
	/// </summary>
	Player();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Player();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	/// <summary>
	/// 描画
	/// </summary>
	void CollisionDraw();

	const Transform& GetWorldTransform() { return transform_; };
	const int& GetIsPlayerAttack() { return isPlayerAttack; };
	const int& GetAttackRangeWeak() { return kAttackRangeWeak; };
	const int& GetAttackRangeStrong() { return kAttackRangeStrong; };
	const int& GetNowPlayerSide() { return nowPlayerSide; };
	const Vector3& GetAttackRangePos() { return attackRangePos; };

	enum side { up, down, left, right };

private:

	const float kPlayerSpeed = (float)0.2; // プレイヤーのスピード規定値
	int playerChageFrame = 0;          // プレイヤーがチャージしているフレーム数
	bool isPlayerChage = false;        // プレイヤーがチャージしているか
	int isPlayerAttack = 0;            // プレイヤーが攻撃中か
	const int kPlayerAttackFrame = 60; // プレイヤーの攻撃時間規定値
	int playerAttackTimer = 0; // プレイヤーが攻撃しているフレーム数タイマー
	const int kAttackRangeWeak = 6;    // 弱攻撃の範囲
	const int kAttackRangeStrong = 10; // 強攻撃の範囲

	int nowPlayerSide = up; // 現在プレイヤーがどこの辺にいるか

	Vector3 attackRangePos{};

	// ワールドトランスフォーム
	Transform transform_{};

	// テクスチャハンドル
	uint32_t textureHandle_ = 0;
	uint32_t textureHandleAttackRange_ = 0;

	// スプライト
	Sprite* sprite_ = nullptr;

	Input* input_ = nullptr;

	// 3Dモデル
	Model* model_ = nullptr;

};
