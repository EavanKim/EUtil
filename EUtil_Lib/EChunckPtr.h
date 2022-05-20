#pragma once


namespace Eavan
{
	template <class C = EBase>
	class EChunck : public EBase
	{
	public:
		explicit EChunck();
		explicit EChunck(EINT64 _count);
		explicit EChunck(C* _ptrs, EINT64 _count);
		virtual ~EChunck();

	private:
		EUINT64 m_count;
		EBase* m_ptrs;
	};

	template<class C>
	inline EChunck<C>::EChunck()
		: m_ptrs(nullptr)
		, m_count(0)
	{
	}

	template<class C>
	inline EChunck<C>::EChunck(EINT64 _count)
		: m_ptrs(new C[_count])
		, m_count(_count)
	{
		ZeroMemory(m_ptrs, m_count);
	}

	template<class C>
	inline EChunck<C>::EChunck(C* _ptrs, EINT64 _count)
		: m_ptrs(new C[_count])
		, m_count(_count)
	{
		ZeroMemory(m_ptrs, m_count);
		memcpy_s(m_ptrs, m_count, _ptrs, _count);
	}

	template<class C>
	inline EChunck<C>::~EChunck()
	{
	}
}