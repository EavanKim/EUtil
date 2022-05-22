#include "pch.h"

namespace Eavan
{
	EFramework::EFramework()
	{
		IEAllocator::Initialize();
	}

	EFramework::~EFramework()
	{
		IEAllocator::Destroy();
	}

	EPtr<EData> EFramework::Create_data()
	{
		return nullptr;
	}

	EPtr<EInfomation> EFramework::Create_Infomation()
	{
		return nullptr;
	}

	void EFramework::Update_Infomation()
	{
	}

	void EFramework::Delete_data(EPtr<EData> _deleteData)
	{
	}

	void EFramework::Delete_data(EVINT64 _deleteIndex)
	{
	}

	void EFramework::Delete_Infomation(EPtr<EInfomation> _deleteInfomation)
	{
	}

	void EFramework::Delete_Infomation(EVINT64 _deleteIndex)
	{
	}
}
