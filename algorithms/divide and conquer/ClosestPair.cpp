#include "ClosestPair.h"

namespace NsClosestPair
{
	CClosestPair &CClosestPair::operator<< (NsPoint::CPoint pt)
	{
		this->pt_vec.push_back(pt);
		return *this;
	}
	double CClosestPair::GetCPair1D(void)
	{
		if (this->pt_vec.size() < 2)
		{
			return -1;
		}
	}
}