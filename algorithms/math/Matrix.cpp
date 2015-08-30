#include "Matrix.h"

namespace NsMatrix
{
	CMatrix::CMatrix(const unsigned row, const unsigned column)
	{
		std::vector<int> tmp;
		for (int i = 0; i < row; ++ i)
		{
			tmp.clear();
			for (int j = 0; j < column; ++ j)
			{
				tmp.push_back(0);
			}
			this->m_mat.push_back(tmp);
		}
	}
}