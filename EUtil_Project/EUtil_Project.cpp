
#include <iostream>
#include "EInclude.h"

class TestClass : public Eavan::EBase
{
public:
	TestClass()
	{
		OutputDebugString(L"생성\n");
	}

	~TestClass()
	{
		OutputDebugString(L"해제\n");
	}
};

int main()
{
	Eavan::EPtr<Eavan::EAllocator> Allocator(new Eavan::EAllocator_Heap());
	Eavan::EPtr<TestClass> Test(new TestClass());
	Eavan::EPtr<TestClass> Test1(Test);
	Eavan::EPtr<TestClass> Test2(Test1);
	Eavan::EPtr<TestClass> Test3(Test2);
	Eavan::EPtr<Eavan::EString> TestString(new Eavan::EString("TestString"));
}
