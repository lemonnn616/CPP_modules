#include "Point.hpp"

static Fixed area(const Point &a, const Point &b, const Point &c) // mi bi mogli prosto ispolzoval float dlya proverki < 0 no menee tochno
{
	return Fixed(
		(a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) +
		 b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) +
		 c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat()))
		/ 2.0f
	).toFloat() < 0 ? -Fixed(
		(a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) +
		 b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) +
		 c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat()))
		/ 2.0f
	) : Fixed(
		(a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) +
		 b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) +
		 c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat()))
		/ 2.0f
	);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed total = area(a, b, c); // S = 1/2 x1(y2-y3)+x2(y3-y1)+x3(y1-y-2)
	Fixed area1 = area(point, b, c);
	Fixed area2 = area(a, point, c);
	Fixed area3 = area(a, b, point);

	if (area1 == Fixed(0) || area2 == Fixed(0) || area3 == Fixed(0)) // proverka esli lezhit na granice togda S=0
		return false;

	return total == area1 + area2 + area3; // true esli realno summa false esli net
}
