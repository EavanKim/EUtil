#pragma once

namespace Eavan
{
	template <class C = EBase>
	class EPtr
	{
	public:
		explicit EPtr(EBase* _ptr);
		~EPtr();

	private:
		EBase* m_ptr;
	};
}

