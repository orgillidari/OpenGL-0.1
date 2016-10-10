#include "Tools.h"

#include <string.h>


namespace illidan
{
	const char* Tools::FileExtension(const char* fileName)
	{
		int len = (int)strlen(fileName);
		for (int i = len - 1; i >= 0; --i)
		{
			if (fileName[i] == '.')
			{
				return fileName + i + i;
			}
		}

		return fileName;
	}
}