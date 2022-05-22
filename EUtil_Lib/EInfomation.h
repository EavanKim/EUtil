#pragma once

namespace Eavan
{
	class E_F_DLL EInfomation : public EBase
	{
	public:
		explicit EInfomation();
		explicit EInfomation(EPtr<EInfomation>);
		virtual ~EInfomation();

		void InsertData(EData* _data);
		void RemoveData(EData* _data);

		virtual void InitData(EPtr<EInfomation> _info) {};

	private:
		ESet<EData> m_datas;
	};
}

