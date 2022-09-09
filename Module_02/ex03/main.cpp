#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {

	Point a(0, 0);
	Point b(5, 0);
	Point c(0, 5);
	Point d;

	d = c;
	std::cout << d.getX() << std::endl;
	std::cout << d.getY() << std::endl;

	std::cout << bsp(a, b, c, d) << std::endl;
	return 0;
}
