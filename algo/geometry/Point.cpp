#include "Point.h"

namespace NsPoint
{
	CPoint::CPoint(const double _x, const double _y)
	{
		this->x = _x;
		this->y = _y;
	}
	std::ostream &operator<< (std::ostream &os, CPoint &p)
	{
		return os << "point( " << p.x << ", " << p.y << " )";
	}
}