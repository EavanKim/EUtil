#pragma once
#include "EAllocator.h"
#include "EAllocator_Heap.h"

namespace Eavan
{
	class EInfomation;
	class E_F_DLL IEAllocator
	{
	public:
		static void Initialize();
		static void Destroy();

		template<class C>
		static C* alloc(EInfomation* _init = nullptr);

		template <class C>
		static void remalloc(EUINT64 _count, C** _ptr);

		template <class C>
		static void del(C* _ptr);

	private:
		static void* malloc(EUINT64 _size);
		static void* malloc(EUINT64 _size, void** _ptr);
		static void realloc(EUINT64 _size, void** _ptr);
		static void free(void* _ptr);

		static EAllocator* m_allocator;
	};

	template<class C>
	inline C* IEAllocator::alloc(EInfomation* _init)
	{
		C* ptr = reinterpret_cast<C*>(malloc(sizeof(C)));

		if (nullptr == _init)
			new (ptr) C();
		else
			new (ptr) C(_init);

		return ptr;
	}

	template<class C>
	inline void IEAllocator::remalloc(EUINT64 _count, C** _ptr)
	{
		realloc(sizeof(C) * _count, _ptr);
	}

	template<class C>
	inline void IEAllocator::del(C* _ptr)
	{
		_ptr->~C();
		free(_ptr);
	}
}