#include "pch.h"

namespace Eavan
{
	EHash::EHash(EString& _string)
		: m_key(_string)
		, m_hash(MakeHash())
	{

	}

	EHash::EHash(EString* _string)
		: m_key(*_string)
		, m_hash(MakeHash())
	{
	}

	EHash::EHash(ECHAR* _string)
		: m_key(_string)
		, m_hash(MakeHash())
	{
	}

	EHash::~EHash()
	{

	}

	EVINT64 EHash::GetHash()
	{
		return m_hash;
	}

	EBOOL EHash::operator==(const EHash& _hash)
	{
		if (m_hash == _hash.m_hash)
			return 1;

		return 0;
	}

	EBOOL EHash::operator==(EString& _string)
	{
		if (m_hash == EHash(_string).m_hash)
			return 1;

		return 0;
	}

	//MurmurHash64A를 사용해 구현 예정.
	//해싱 관련으로 조금 더 파악해보기
	EINT64 EHash::MakeHash()
	{
		return EINT64();
	}
}
