#include "GameManager.h"

#include "AllGameScene/SampleScene/SampleScene.h"
#include "AllGameScene/TitleScene/TitleScene.h"
#include "AllGameScene/SelectScene/SelectScene.h"
#include "AllGameScene/ResultScene/ResultScene.h"
#include "AllGameScene/GameScene/GameScene.h"
#include "AllGameScene/TutorialScene/TutorialScene.h"

//コンストラクタ
GameManager::GameManager() {
	
	
	//コンストラクタ
	//GameManager.cpp側ではwinApp=GetInstanceでやってるけど他のクラスでは直接GetInstanceってやった方が楽かも

	winApp_ = WinApp::GetInstance();
	directXSetup_ = DirectXSetup::GetInstance();
	imGuiManager_ = ImGuiManager::GetInstance();
	input_ = Input::GetInstance();
	camera_ = Camera::GetInstance();
	textureManager_ = TextureManager::GetInstance();
	audio_ = Audio::GetInstance();
	pipelineManager_ = PipelineManager::GetInstance();
	record_ = Record::GetInstance();
}
	
void GameManager::Initialize() {
	//ここでタイトルバーの名前を決めてね
	const wchar_t* titleBarName = L"2124_四角い刺客";

	//初期化
	winApp_->Initialize(titleBarName,WINDOW_SIZE_WIDTH_,WINDOW_SIZE_HEIGHT_);
	directXSetup_->Initialize();
	pipelineManager_->GenerateSpritePSO();
	pipelineManager_->GenerateModelPSO();
	imGuiManager_->Initialize();
	input_->Initialize();
	textureManager_->Initilalize();
	audio_->Initialize();

	//シーンごとに動作確認したいときはここを変えてね
	currentGameScene_ = new TitleScene();
	currentGameScene_->Initialize(this);

}

void GameManager::BeginFrame() {
	directXSetup_->BeginFrame();
	imGuiManager_->BeginFrame();

}


void GameManager::Update() {
	imGuiManager_->UpDate();

	//入力の更新
	input_->Update();
	currentGameScene_->Update(this);
}

void GameManager::Draw() {
	imGuiManager_->PreDraw();	
	imGuiManager_->Draw();
	
	currentGameScene_->Draw(this);

}

void GameManager::EndFrame() {

	imGuiManager_->EndFrame();
	directXSetup_->EndFrame();
			
}

void GameManager::Release() {
	camera_->DeleteInstance();
	
	textureManager_->Release();
	textureManager_->DeleteInstance();

	pipelineManager_->Release();
	pipelineManager_->DeleteInstance();

	imGuiManager_->Release();
	directXSetup_->Release();
	directXSetup_->DeleteInstance();
	winApp_->Close();
}

void GameManager::ChangeScene(IGameScene* newGameScene) {
	//一度消してから次のシーンにいく
	delete currentGameScene_;

	currentGameScene_ = newGameScene;
	//今は言っているシーンが引数
	currentGameScene_->Initialize(this);


}


void GameManager::Operate() {
	
	Initialize();
	

	
	MSG msg{};

	////メインループ
	//ウィンドウの✕ボタンが押されるまでループ
	while (msg.message != WM_QUIT) {
		//Windowにメッセージが来てたら最優先で処理させる
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			
			//common_->WinMSG(msg);
			winApp_->WindowsMSG(msg);

		}
		else {
			//ゲームの処理
			// 
			//フレームの開始
			BeginFrame();


			
			//更新処理
			Update();


			//描画
			Draw();
			
			


			//フレームの終わり
			EndFrame();

			
		}
		
	}

	Release();

	//ゲーム終了時にはCOMの終了処理を行っておく
	CoUninitialize();
}






//デストラクタ
GameManager::~GameManager() {

}


