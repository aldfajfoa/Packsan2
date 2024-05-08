#pragma once
#include "Engine/GameObject.h"
#include "CDTimer.h"

namespace {
	enum MOVEDIR
	{
		MLEFT,MRIGHT,MNONE,MMAX
	};
	XMVECTOR moveVec[MMAX] = { {2,0,0} ,{-2,0,0}, {0,0,0} };
	const float DTIME{ 0.5 };
}

class Player :
    public GameObject
{
	int hModel_;
	void GetInputData();
	MOVEDIR moveDir_;
	XMVECTOR V[2];
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Player(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
	CDTimer* cdtimer_;
};

