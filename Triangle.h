#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Point.h"
class Triangle
{
public:
	Triangle(Point, Point, Point, const char*); // Основной конструктор
	Triangle(const char*); // Конструктор пустого треугольника
	Triangle(const Triangle&); // Конструктор копирования
	~Triangle(); // Деструктор
	// Методы доступа
	Point Get_v1() const { return v1; }
	Point Get_v2() const { return v2; }
	Point Get_v3() const { return v3; }
	char* GetName() const { return name; }
	void Show() const; // Показать треугольник
	void Move(Point); // Переместить треугольник
	bool operator >(const Triangle&) const; // Сравнение по площади
	Triangle& operator =(const Triangle&); // Оператор присваивания
	static int count; // Счетчик объектов
private:
	char* objID; // Идентификатор объекта
	char* name; // Название треугольника
	Point v1, v2, v3; // Вершины
	double a, b, c; // Длины сторон
};
#endif