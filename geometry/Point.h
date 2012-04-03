#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>

namespace NsPoint
{
	class CPoint
	{
	public:
		CPoint(const double _x, const double _y);
		double GetX(void);
		double GetY(void);
		friend std::ostream &operator<< (std::ostream &os, CPoint &p);
	protected:
	private:
		double x, y;
	};
}

#endif