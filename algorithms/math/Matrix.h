#ifndef _MATRIX_
#define _MATRIX_

#include <iostream>
#include <vector>

namespace NsMatrix
{
	class CMatrix
	{
	public:
		CMatrix(const unsigned row = 0, const unsigned column = 0);
	protected:
	private:
		std::vector<std::vector<int> > m_mat;
	};
}

#endif