#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	Point a(0.0f, 0.0f);
	Point b(5.0f, 0.0f);
	Point c(0.0f, 5.0f);

	Point inside(1.0f, 1.0f);
	Point edge(0.0f, 0.0f);
	Point outside(5.0f, 5.0f);

	std::cout << "Point (1,1) inside " << (bsp(a, b, c, inside) ? "Yes" : "No") << std::endl;
	std::cout << "Point (0,0) edge " << (bsp(a, b, c, edge) ? "Yes" : "No") << std::endl;
	std::cout << "Point (5,5) outside " << (bsp(a, b, c, outside) ? "Yes" : "No") << std::endl;

	return 0;
}
