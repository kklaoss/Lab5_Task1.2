#include <iostream>
#include <math.h>
#include "Point.h"
#include "Triangle.h"
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
// Перегрузка оператора + для сложения точек
Point Point::operator +(const Point& p) const
{
	return Point(x + p.x, y + p.y); // Возврат новой точки
}
// Перегрузка оператора - для вычитания точек
Point Point::operator -(const Point& p) const
{
	return Point(x - p.x, y - p.y); // Возврат новой точки
}
// Вычисление длины вектора от начала координат до точки
double Point::Length() const
{
	return sqrt(x * x + y * y); // Теорема Пифагора
}
// Определение ориентации точки относительно отрезка
ORIENT Point::Classify(const Point& beg_p, const Point& end_p) const
{
	Point a = end_p - beg_p; // Вектор отрезка
	Point b = *this - beg_p; // Вектор от начала отрезка до точки
	double sa = a.x * b.y - b.x * a.y; // Векторное произведение
	if (sa > 0.0) return LEFT; // Точка слева
	if (sa < 0.0) return RIGHT; // Точка справа
	if ((a.x * b.x < 0.0) || (a.y * b.y < 0.0)) return BEHIND; // Точка позади
	if (a.Length() < b.Length()) return AHEAD; // Точка впереди
	return BETWEEN; // Точка на отрезке
}
// Проверка принадлежности точки треугольнику
bool Point::InTriangle(const Triangle& tria) const
{
	// Проверка ориентации точки относительно каждой стороны
	ORIENT or1 = Classify(tria.Get_v1(), tria.Get_v2());
	ORIENT or2 = Classify(tria.Get_v2(), tria.Get_v3());
	ORIENT or3 = Classify(tria.Get_v3(), tria.Get_v1());
	// Точка внутри, если для всех сторон она справа или на стороне
	return ((or1 == RIGHT || or1 == BETWEEN) &&
		(or2 == RIGHT || or2 == BETWEEN) &&
		(or3 == RIGHT || or3 == BETWEEN));
}