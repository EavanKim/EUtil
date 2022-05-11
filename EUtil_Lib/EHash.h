#pragma once

namespace Eavan
{
	template<typename T>
	class E_F_DLL EHash
	{
	public:
		EHash(const EString& _string);
		~EHash();

		EVINT64 GetHash();

		EBOOL operator ==(const EHash& _hash);
		EBOOL operator ==(const EString& _string);

	private:
		EString m_key;
		EVINT64 m_hash;
	};

	template<typename T>
	inline EHash<T>::EHash(const EString& _string)
	{

	}
	
	template<typename T>
	inline EHash<T>::~EHash()
	{

	}
	
	template<typename T>
	inline EVINT64 EHash<T>::GetHash()
	{
		return m_hash;
	}
	
	template<typename T>
	inline EBOOL EHash<T>::operator==(const EHash& _hash)
	{
		if (m_hash == _hash.m_hash)
			return 1;

		return 0;
	}
	
	template<typename T>
	inline EBOOL EHash<T>::operator==(const EString& _string)
	{
		if (m_hash == EPtr<EHash>(new EHash(_string))->m_hash)
			return 1;

		return 0;
	}
}

