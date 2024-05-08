#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Debug.h"

void Player::GetInputData()
{
	if (Input::IsKeyDown(DIK_LEFT)) {
		moveDir_ = MLEFT;
		cdtimer_->ResetTimer();
		cdtimer_->StartTimer();
		V[0] = XMLoadFloat3(&transform_.position_);
		V[1] = V[0]+moveVec[moveDir_];
	}
	if (Input::IsKeyDown(DIK_RIGHT)) {
		moveDir_ = MRIGHT;
		cdtimer_->ResetTimer();
		cdtimer_->StartTimer();
		V[0] = XMLoadFloat3(&transform_.position_);
		V[1] = V[0] + moveVec[moveDir_];
	}
}

Player::Player(GameObject* parent)
	: GameObject(parent, "Player"), hModel_(-1),moveDir_(MNONE),cdtimer_(nullptr)
{
}

void Player::Initialize()
{
	cdtimer_ = new CDTimer(this, DTIME);
	cdtimer_->StopTimer();
	hModel_ = Model::Load("Model\\Pack.fbx");
	assert(hModel_ >= 0);
}

void Player::Update()
{
	cdtimer_->Update();

	float lerpRate = 1.0f - cdtimer_->GetTime() / DTIME;
	Debug::Log(cdtimer_->IsTimerRun(), true);
	GetInputData();
	if (moveDir_ == MNONE)
		return;
	if (cdtimer_->IsTimerRun()) 
	{
		XMVECTOR pos = XMVectorLerp(V[0],V[1],lerpRate);
		XMStoreFloat3(&transform_.position_, pos);
	}

	if (cdtimer_->GetTime() <= 0) {
		//XMVECTOR pos = XMLoadFloat3(&transform_.position_);
		//pos += moveVec[moveDir_];
		//XMStoreFloat3(&transform_.position_, pos);
		moveDir_ = MNONE;
		cdtimer_->StopTimer();
	}
}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}
