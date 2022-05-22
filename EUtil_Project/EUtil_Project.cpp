
#include <iostream>
#include "EInclude.h"

class TestClass : public Eavan::EBase
{
public:
	TestClass()
		: Eavan::EBase()
	{
		OutputDebugString(L"생성\n");
	}

	TestClass(Eavan::EInfomation* _test)
	{
		InitData(Eavan::EPtr<Eavan::EInfomation>(_test));
		OutputDebugString(L"파라메터 생성\n");
	}

	~TestClass()
	{
		OutputDebugString(L"해제\n");
	}

	// EBase을(를) 통해 상속됨
	virtual void InitData(Eavan::EPtr<Eavan::EInfomation> _info) override
	{
	}
};

int main()
{
	Eavan::EFramework frame;
	//Eavan::EPtr<Eavan::EAllocator> Allocator(new Eavan::EAllocator_Heap());
	Eavan::EPtr<TestClass> Test(Eavan::IEAllocator::alloc<TestClass>());
	//Eavan::EPtr<TestClass> Test(Eavan::IEAllocator::alloc<TestClass>(Eavan::IEAllocator::alloc<Eavan::EInfomation>()));
	Eavan::EPtr<TestClass> Test1(Test);
	Eavan::EPtr<TestClass> Test2(Test1);
	Eavan::EPtr<TestClass> Test3(Test2);
	//Eavan::EPtr<Eavan::EString> TestString(new Eavan::EString("TestString"));
}
