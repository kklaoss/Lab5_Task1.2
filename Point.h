#ifndef POINT_H
#define POINT_H
// Перечисление для ориентации точки
enum ORIENT { LEFT, RIGHT, AHEAD, BEHIND, BETWEEN };
// Предварительное объявление класса Triangle
class Triangle;
// Класс точки в 2D пространстве
class Point
{
public:
	Point(double _x = 0, double _y = 0) : x(_x), y(_y) {} // Конструктор с параметрами по умолчанию
	// Методы класса
	void Show() const; // Отображение координат
	void operator +=(Point&); // Оператор сложения с другой точкой
	Point operator +(const Point&) const; // Оператор сложения
	Point operator -(const Point&) const; // Оператор вычитания
	double Length() const; // Длина вектора
	ORIENT Classify(const Point& beg_p, const Point& end_p) const; // Определение ориентации
	bool InTriangle(const Triangle& tria) const; // Проверка принадлежности треугольнику
public:
	double x, y; // Координаты точки
};
#endif