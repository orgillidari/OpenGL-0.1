#include "FileSystem.h"

#include <stdio.h>


namespace illidan
{
	int FileSystem::LoadFile(const char* fileName, Data& data)
	{
		FILE* pf = fopen(fileName, "rb");
		if (!pf)
		{
			return -1;
		}

		fseek(pf, 0, SEEK_END);
		data.m_Len = ftell(pf);
		rewind(pf);

		data.m_Data = new unsigned char[data.m_Len + 1];
		fread(data.m_Data, 1, data.m_Len, pf);
		data.m_Data[data.m_Len] = 0;
		fclose(pf);
		
		return 0;
	}
}