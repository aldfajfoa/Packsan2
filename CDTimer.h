#pragma once
#include "Engine/GameObject.h"

class CDTimer :
    public GameObject
{
private:
    double CountDownTimer_;  //現在の残り時間
    double TIMER_INIT_TIME_; //初期時間
    bool isTimerRun_;//タイマーが動いているかどうか？
    DWORD oldTime_;
public:
    //コンストラクタ
    //引数：parent  親オブジェクト（SceneManager）
    CDTimer(GameObject* parent);
    CDTimer(GameObject* parent, double _initTime);


    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

public:

    bool IsTimeOver();//タイマーは０になりましたか？ＹＥＳ？ＮＯ？
    void ResetTimer();//タイマーを初期時間に戻す
    void StartTimer();//タイマーをスタートします
    void StopTimer();//タイマーをストップします
    bool IsTimerRun() { return (isTimerRun_); }
    void SetInitTime(double cdTime) { TIMER_INIT_TIME_ = cdTime; ResetTimer(); }
    double GetTime() { return(CountDownTimer_); }
};

