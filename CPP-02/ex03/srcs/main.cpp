#include "../includes/Point.hpp"
#include "../includes/Fixed.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float V1x = a.getX().toFloat(),V1y = a.getY().toFloat();
	float V2x = b.getX().toFloat(),V2y = b.getY().toFloat();
	float V3x = c.getX().toFloat(),V3y = c.getY().toFloat();
	float Px = point.getX().toFloat(), Py = point.getY().toFloat();

	if ((V3x - Px) * (V1y - Py) - (V3y - Py) * (V1x - Px) > 0)
		return false;
	if ((V1x - Px) * (V2y - Py) - (V1y - Py) * (V2x - Px) > 0)
		return false;
	if ((V2x - Px) * (V3y - Py) - (V2y - Py) * (V3x - Px) > 0)
		return false;

	return true;
}

int main(void)
{
	Point a(0, 0);
	Point b(0, 10);
	Point c(10, 0);

	Point point(1, 1);
	if (bsp(a, b, c, point))
		std::cout << "WOUAHHHHH" << std::endl;
	else
		std::cout << "NAAAAAHHH" << std::endl;
}
