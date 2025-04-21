#ifndef POINT_H
#define POINT_H
// Класс точки в 2D пространстве
class Point
{
public:
	Point(double _x = 0, double _y = 0) : x(_x), y(_y) {} // Конструктор с параметрами по умолчанию
	void Show() const; // Отображение координат
	void operator +=(Point&); // Оператор сложения с другой точкой
public:
	double x, y; // Координаты точки
};
#endif