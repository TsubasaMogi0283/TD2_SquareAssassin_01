#include "TextureManager.h"


TextureManager* TextureManager::instance_ = nullptr;

static uint32_t descriptorSizeSRV_ = 0u;
static uint32_t descriptorSizeRTV_ = 0u;
static uint32_t descriptorSizeDSV_ = 0u;

 uint32_t TextureManager::textureIndex;

//コンストラクタ
TextureManager::TextureManager() {

}

TextureManager* TextureManager::GetInstance() {
	//これだと無限に生成される
	if (instance_ == nullptr) {
		instance_ = new TextureManager();

	}
	
	return instance_;
}

//初期化
void TextureManager::Initilalize() {
	this->directXSetup_ = DirectXSetup::GetInstance();
	//COMの初期化
	//COM...ComponentObjectModel、Microsoftの提唱する設計技術の１つ
	//		DirectX12も簡略化されたCOM(Nano-COM)という設計で作られている
	
	//COMを使用して開発されたソフトウェア部品をCOMコンポーネントと呼ぶ
	//Textureを読むにあたって、COMコンポーネントの１つを利用する
	CoInitializeEx(0, COINIT_MULTITHREADED);

	descriptorSizeSRV_ = directXSetup_->GetDevice()->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV);
	descriptorSizeRTV_ = directXSetup_->GetDevice()->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
	descriptorSizeDSV_ = directXSetup_->GetDevice()->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_DSV);
	textureIndex = 0;
}

//Resource作成の関数化
ID3D12Resource* TextureManager::CreateBufferResource(size_t sizeInBytes) {
	//返り値も忘れずに
	ID3D12Resource* resource = nullptr;
	
	////VertexResourceを生成
	//頂点リソース用のヒープを設定
	
	uploadHeapProperties_.Type = D3D12_HEAP_TYPE_UPLOAD;

	//頂点リソースの設定
	
	//バッファリソース。テクスチャの場合はまた別の設定をする
	vertexResourceDesc_.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
	vertexResourceDesc_.Width = sizeInBytes;
	//バッファの場合はこれらは1にする決まり
	vertexResourceDesc_.Height = 1;
	vertexResourceDesc_.DepthOrArraySize = 1;
	vertexResourceDesc_.MipLevels = 1;
	vertexResourceDesc_.SampleDesc.Count = 1;

	//バッファの場合はこれにする決まり
	vertexResourceDesc_.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;

	//実際に頂点リソースを作る
	//ID3D12Resource* vertexResource_ = nullptr;
	
	//次はここで問題
	//hrは調査用
	HRESULT hr;
	hr = directXSetup_->GetDevice()->CreateCommittedResource(
		&uploadHeapProperties_,
		D3D12_HEAP_FLAG_NONE,
		&vertexResourceDesc_,
		D3D12_RESOURCE_STATE_GENERIC_READ,
		nullptr, IID_PPV_ARGS(&resource));
	assert(SUCCEEDED(hr));

	return resource;
}

D3D12_CPU_DESCRIPTOR_HANDLE TextureManager::GetCPUDescriptorHandle(ID3D12DescriptorHeap* descriptorHeap, uint32_t descriptorSize, uint32_t index) {
	D3D12_CPU_DESCRIPTOR_HANDLE handleCPU = descriptorHeap->GetCPUDescriptorHandleForHeapStart();
	handleCPU.ptr += (descriptorSize * index);
	return handleCPU;
}

D3D12_GPU_DESCRIPTOR_HANDLE TextureManager::GetGPUDescriptorHandle(ID3D12DescriptorHeap* descriptorHeap, uint32_t descriptorSize, uint32_t index) {
	D3D12_GPU_DESCRIPTOR_HANDLE handleGPU = descriptorHeap->GetGPUDescriptorHandleForHeapStart();
	handleGPU.ptr += (descriptorSize * index);
	return handleGPU;
}


//統合させた関数
uint32_t TextureManager::LoadTexture(const std::string& filePath) {
	//読み込むたびにインデックスが増やし重複を防ごう
	//同じ画像しか貼れなかったのはこれが原因
	textureIndex += 1;


	//Textureを読んで転送する
	mipImages_ = LoadTextureData(filePath);
	const DirectX::TexMetadata& metadata = mipImages_.GetMetadata();
	TextureManager::GetInstance()->textureResource_[textureIndex] = CreateTextureResource(metadata);
	UploadTextureData(textureResource_[textureIndex], mipImages_);

	

	//ShaderResourceView
	//metadataを基にSRVの設定
	D3D12_SHADER_RESOURCE_VIEW_DESC srvDesc{};
	srvDesc.Format = metadata.format;
	srvDesc.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
	//2Dテクスチャ
	srvDesc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2D;
	srvDesc.Texture2D.MipLevels = UINT(metadata.mipLevels);
	
	//今のDescriptorHeapには
	//0...ImGui
	//1...uvChecker
	//2...monsterBall
	//3...NULL
	//.
	//.
	//このような感じで入っている
	//後ろのindexに対応させる


	//SRVを作成するDescriptorHeapの場所を決める
	//後ろが1固定だったのでindex
	TextureManager::GetInstance()->textureSrvHandleCPU_[textureIndex] = TextureManager::GetInstance()->GetCPUDescriptorHandle(directXSetup_->GetSrvDescriptorHeap(), descriptorSizeSRV_, textureIndex);
	TextureManager::GetInstance()->textureSrvHandleGPU_[textureIndex] = TextureManager::GetInstance()->GetGPUDescriptorHandle(directXSetup_->GetSrvDescriptorHeap(), descriptorSizeSRV_, textureIndex);

	//先頭はImGuiが使っているのでその次を使う
	TextureManager::GetInstance()->textureSrvHandleCPU_[textureIndex].ptr += directXSetup_->GetDevice()->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV);
	TextureManager::GetInstance()->textureSrvHandleGPU_[textureIndex].ptr += directXSetup_->GetDevice()->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV);
	
	//SRVの生成
	directXSetup_->GetDevice()->CreateShaderResourceView(TextureManager::GetInstance()->textureResource_[textureIndex], &srvDesc, TextureManager::GetInstance()->textureSrvHandleCPU_[textureIndex]);
	

	return textureIndex;
}
	


#pragma region テクスチャの読み込み
//1.TextureデータそのものをCPUで読み込む
//2.DirectX12のTextureResourceを作る
//3.CPUで書き込む用にUploadHeapのResourceを作る(IntermediateResource)
//4.3に対してCPUでデータを書き込む
//5.CommandListに3を2に転送するコマンドを積む
//6.CommandQueueを使って実行する
//7.6の実行完了を待つ


#pragma region 上のLoadTextureにまとめた
//Textureを読み込むためのLoad関数
//1.TextureデータそのものをCPUで読み込む
DirectX::ScratchImage TextureManager::LoadTextureData(const std::string& filePath) {
	
	//テクスチャファイルを読んでプログラムで扱えるようにする
	DirectX::ScratchImage image{};
	std::wstring filePathW = ConvertString(filePath);
	//ここで問題
	HRESULT hr = DirectX::LoadFromWICFile(filePathW.c_str(), DirectX::WIC_FLAGS_FORCE_SRGB, nullptr, image);
	assert(SUCCEEDED(hr));
	
	//ミップマップの作成
	//ミップマップ...元画像より小さなテクスチャ群
	DirectX::ScratchImage mipImages{};
	hr = DirectX::GenerateMipMaps(image.GetImages(), image.GetImageCount(), image.GetMetadata(), DirectX::TEX_FILTER_SRGB, 0, mipImages);
	assert(SUCCEEDED(hr));

	//ミップマップ月のデータを返す
	return mipImages;
}

//2.DirectX12のTextureResourceを作る
ID3D12Resource* TextureManager::CreateTextureResource(const DirectX::TexMetadata& metadata) {
	ID3D12Resource* resource = nullptr;
	
	//1.metadataを基にResourceの設定
	D3D12_RESOURCE_DESC resourceDesc{};
	//Textureの幅
	resourceDesc.Width = UINT(metadata.width);
	//Textureの高さ
	resourceDesc.Height = UINT(metadata.height);
	//mipmapの数
	resourceDesc.MipLevels = UINT16(metadata.mipLevels);
	//奥行き or 配列Textureの配列数
	resourceDesc.DepthOrArraySize = UINT16(metadata.arraySize);
	//TextureのFormat
	resourceDesc.Format = metadata.format;
	//サンプリングカウント
	resourceDesc.SampleDesc.Count = 1;
	//Textureの次元数。普段使っているのは2次元
	resourceDesc.Dimension = D3D12_RESOURCE_DIMENSION(metadata.dimension);

	//2.利用するHeapの設定
	//利用するHeapの設定。非常に特殊な運用。02_04exで一般的なケース版がある
	D3D12_HEAP_PROPERTIES heapProperties{};
	//細かい設定を行う
	heapProperties.Type = D3D12_HEAP_TYPE_CUSTOM;
	//WriteBackポリシーでCPUアクセス可能
	heapProperties.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_WRITE_BACK;
	//プロセッサの近くに配置
	heapProperties.MemoryPoolPreference = D3D12_MEMORY_POOL_L0;

	
	

	//3.Resourceを生成する
	
	HRESULT hr = directXSetup_->GetDevice()->CreateCommittedResource(
		&heapProperties,					//Heapの設定
		D3D12_HEAP_FLAG_NONE,				//Heapの特殊な設定
		&resourceDesc,						//Resourceの設定
		D3D12_RESOURCE_STATE_COPY_DEST,	//初回のResourceState。データの転送を受け入れられるようにする
		nullptr,							//Clear最適値。使わないのでnullptr
		IID_PPV_ARGS(&resource));			//作成するResourceポインタへのポインタ
	assert(SUCCEEDED(hr));

	return resource;


}

//3.TextureResourceに1で読んだデータを転送する
//書き換え
void TextureManager::UploadTextureData(
	ID3D12Resource* texture, 
	const DirectX::ScratchImage& mipImages) {

	//Meta情報を取得
	const DirectX::TexMetadata& metadata = mipImages.GetMetadata();
	//全MipMapについて
	for (size_t mipLevel = 0; mipLevel < metadata.mipLevels; ++mipLevel) {
		//MipMapLevelを指定して各Imageを取得
		const DirectX::Image* img = mipImages.GetImage(mipLevel, 0, 0);
		//Textureに転送
		HRESULT hr = texture->WriteToSubresource(
			UINT(mipLevel),
			nullptr,				//全領域へコピー
			img->pixels,			//元データアドレス
			UINT(img->rowPitch),	//1ラインサイズ
			UINT(img->slicePitch)	//1枚サイズ
		);

		assert(SUCCEEDED(hr));
	}



}

//[[nodiscard]]
//ID3D12Resource* TextureManager::UploadTextureData(
//	ID3D12Resource* texture, 
//	const DirectX::ScratchImage& mipImages) {
//
//	std::vector<D3D12_SUBRESOURCE_DATA>subresource;
//	DirectX::PrepareUpload(directXSetup_->GetDevice(), mipImages.GetImages(), mipImages.GetImageCount(), mipImages.GetMetadata(), subresource);
//	uint64_t intermediateSize = GetRequiredIntermediateSize(texture, 0, UINT(subresource.size()));
//	ID3D12Resource* intermediateResource = CreateBufferResource(intermediateSize);
//	UpdateSubresources(directXSetup_->GetCommandList(), texture, intermediateResource, 0, 0, UINT(subresource.size()), subresource.data());
//	
//	//Textureへの転送後は利用出来るようD3D12_RESOURCE_STATE_COPY_DESTからD3D12_RESOURCE_STATE_GENERIC_READへResourceStateを変更
//	D3D12_RESOURCE_BARRIER barrier{};
//	barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
//	barrier.Flags = D3D12_RESOURCE_BARRIER_FLAG_NONE;
//	barrier.Transition.pResource = texture ;
//	barrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
//	barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_COPY_DEST;
//	barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_GENERIC_READ;
//	directXSetup_->GetCommandList()->ResourceBarrier(1, &barrier);
//	return intermediateResource;
//
//
//}

#pragma endregion



#pragma endregion


void TextureManager::TexCommand(uint32_t texHandle) {
	DirectXSetup::GetInstance()->GetCommandList()->SetGraphicsRootDescriptorTable(2, TextureManager::GetInstance()->textureSrvHandleGPU_[textureIndex]);
}

void TextureManager::Release() {
	//ゲーム終了時にはCOMの終了処理を行っておく
	CoUninitialize();
}

//デリート代わりの関数
void TextureManager::DeleteInstance() {

}

//コンストラクタ
TextureManager::~TextureManager() {

}


