#pragma once

namespace Eavan
{
	template<typename DataType, class Alloc = EAllocator<DataType>>
	class E_F_DLL EArray : public EBase
	{
	public:
		explicit EArray();
		explicit EArray(EINT64 _size);
		virtual ~EArray();

		EVINT64 GetCount();
		EVINT64 GetReserve();

		EBOOL At(EINT64 _Index, DataType& _return);

	private:
		EVINT64 m_arrayNum;
		EVINT64 m_arrayMax;
		DataType* m_datas;
	};
}

