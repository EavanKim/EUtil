#include "pch.h"

namespace Eavan
{
	EInfomation::EInfomation()
	{
		OutputDebugStringW(L"InfoCreate");
	}

	EInfomation::EInfomation(EPtr<EInfomation> _ptr)
	{
		InitData(_ptr);
	}

	EInfomation::~EInfomation()
	{
		OutputDebugStringW(L"InfoDelete");
	}

	void EInfomation::InsertData(EData* _data)
	{

	}

	void EInfomation::RemoveData(EData* _data)
	{

	}
}
