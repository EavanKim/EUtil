#include "pch.h"

namespace Eavan
{
	EHash::EHash(EString& _string)
		: m_key(*_string)
	{

	}

	EHash::~EHash()
	{
	}

	EVINT64 EHash::GetHash()
	{
		return EVINT64();
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
}