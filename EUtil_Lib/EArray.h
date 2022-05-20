#pragma once

namespace Eavan
{
	template<typename DataType>
	class EArray : public EBase
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

	template<typename DataType>
	inline EArray<DataType>::EArray()
		: m_arrayNum(0)
		, m_arrayMax(5)
		, m_datas(new DataType[5])
	{

	}

	template<typename DataType>
	inline EArray<DataType>::EArray(EINT64 _size)
		: m_arrayNum(_size)
		, m_arrayMax(_size)
		, m_datas(new DataType[m_arrayNum])
	{

	}

	template<typename DataType>
	inline EArray<DataType>::~EArray()
	{
		if (nullptr != m_datas)
		{
			if (0 != m_arrayNum)
			{
				for (int seek = 0; m_arrayNum > seek; ++seek)
				{
					m_datas[seek].~DataType();
				}
				delete[] m_datas;
			}
		}
	}

	template<typename DataType>
	inline EVINT64 EArray<DataType>::GetCount()
	{
		return m_arrayNum;
	}

	template<typename DataType>
	inline EVINT64 EArray<DataType>::GetReserve()
	{
		return m_arrayMax;
	}

	template<typename DataType>
	inline EBOOL EArray<DataType>::At(EINT64 _Index, DataType& _return)
	{
		if (m_arrayNum > _Index)
		{
			_return = m_datas[_Index];

			return 1;
		}

		return 0;
	}
}

