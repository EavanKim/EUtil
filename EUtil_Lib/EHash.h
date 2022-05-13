#pragma once

namespace Eavan
{
	class E_F_DLL EHash
	{
	public:
		EHash(EString& _string);
		~EHash();

		EVINT64 GetHash();

		EBOOL operator ==(const EHash& _hash);
		EBOOL operator ==(EString& _string);

	private:
		EString m_key;
		EVINT64 m_hash;
	};
}

