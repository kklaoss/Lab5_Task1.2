#include <iostream>
#include "Point.h"
// Метод отображения координат точки
void Point::Show() const
{
	std::cout << " (" << x << ", " << y << ").";
}
// Перегрузка оператора += для сложения точек
void Point::operator +=(Point& p)
{
	x += p.x; // Сложение x-координат
	y += p.y; // Сложение y-координат
}