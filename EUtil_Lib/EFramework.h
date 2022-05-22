#pragma once

namespace Eavan
{
	class E_F_DLL EFramework
	{
	public:
		explicit EFramework();
		~EFramework();

		EPtr<EData> Create_data();
		EPtr<EInfomation> Create_Infomation();

		void Update_Infomation();

		void Delete_data(EPtr<EData> _deleteData);
		void Delete_data(EVINT64 _deleteIndex);
		void Delete_Infomation(EPtr<EInfomation> _deleteInfomation);
		void Delete_Infomation(EVINT64 _deleteIndex);

	private:
		ESet<EData> m_datas;
		ESet<EInfomation> m_infomations;
	};
}

