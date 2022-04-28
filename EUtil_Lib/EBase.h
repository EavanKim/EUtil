#pragma once

namespace Eavan
{
	class EBase
	{
	public:
		EVINT64 IncreaseReferenceCount();
		EVINT64 DecreaseReferenceCount();

	private:
		EVINT64 m_refCount;
	};
}

