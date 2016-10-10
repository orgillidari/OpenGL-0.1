#pragma once


namespace illidan
{
	class Data
	{
	public:
		unsigned char* m_Data;
		unsigned int m_Len;

	public:
		Data()
			: m_Data(nullptr), m_Len(0)
		{}
		~Data()
		{
			if (m_Data)
			{
				delete m_Data;
				m_Len = 0;
			}
		}
	};

	class FileSystem
	{
	public:
		static int LoadFile(const char* fileName, Data& data);
	};
}
