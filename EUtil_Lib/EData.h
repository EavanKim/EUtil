#pragma once

namespace Eavan
{
	class E_F_DLL EData : public EBase
	{
	public:
		explicit EData() {}
		virtual ~EData() {}

		void SetIndex(EUINT64 _index) { m_dataIndex = _index; }

		virtual void Update(void* _data) {};

		virtual void InitData(EPtr<EInfomation> _info) {};

	private:
		EUINT64 m_dataIndex = 0;
	};
}

