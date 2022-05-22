#include "pch.h"

namespace Eavan
{
    void IEAllocator::Initialize()
    {
        m_allocator = new EAllocator_Heap();
    }

    void IEAllocator::Destroy()
    {
    }

    void* IEAllocator::malloc(EUINT64 _size)
    {
        return m_allocator->allocate(_size);
    }

    void* IEAllocator::malloc(EUINT64 _size, void** _ptr)
    {
        return m_allocator->allocate(_size, _ptr);
    }

    void IEAllocator::realloc(EUINT64 _size, void** _ptr)
    {
        m_allocator->reallocate(_size, _ptr);
    }

    void IEAllocator::free(void* _ptr)
    {
        m_allocator->delocate(_ptr);
    }
}
