#ifndef _CLOSEST_PAIR_H_
#define _CLOSEST_PAIR_H_

#include <iostream>
#include <vector>
#include "../geometry/Point.h"

namespace NsClosestPair
{
	class CClosestPair
	{
	public:
		CClosestPair &operator<< (NsPoint::CPoint pt);
		double GetCPair1D(void);
	protected:
	private:
		std::vector<NsPoint::CPoint> pt_vec;
	};
}

#endif