#pragma once


//倒した敵を記録するためだけだからあまり機能はいらないね
class Record {
private:
	Record();

	~Record();


public:

	static Record* GetInstance();

	//コピーコンストラクタ禁止
	Record(const Record& obj) = delete;

	//代入演算子を無効にする
	Record& operator=(const Record& obj) = delete;



	void SetAttackedEnemy(int smallEnemy,int normalEnemy,int bigEnemy) {
		this->attackdEnemy[0] = smallEnemy;
		this->attackdEnemy[1] = normalEnemy;
		this->attackdEnemy[2] = bigEnemy;

	}


	int GetSmallEnemy() {
		return attackdEnemy[0];
	}

	int GetNormalEnemy() {
		return attackdEnemy[1];
	}
	int GetBigEnemy() {
		return attackdEnemy[2];
	}

private:

	static const int ENEMY_AMOUNT_ = 3;
	int attackdEnemy[ENEMY_AMOUNT_] = {};



};