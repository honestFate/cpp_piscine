#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point) {

	float aCheck = ((a.getX() - point.getX()) * (b.getY() - a.getY()) -
		(b.getX() - a.getX()) * (a.getY() - point.getY())).toFloat();
	float bCheck = ((b.getX() - point.getX()) * (c.getY() - b.getY()) -
		(c.getX() - b.getX()) * (b.getY() - point.getY())).toFloat();
	float cCheck = ((c.getX() - point.getX()) * (a.getY() - c.getY()) -
		(a.getX() - c.getX()) * (c.getY() - point.getY())).toFloat();

	return (aCheck >= 0 && bCheck >= 0 && cCheck >= 0)
		|| (aCheck <= 0 && bCheck <= 0 && cCheck <= 0);
}
