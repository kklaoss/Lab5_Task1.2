// Защита от повторного включения заголовочного файла
#ifndef TRIANGLE_H
#define TRIANGLE_H
// Подключение заголовочного файла класса Point
#include "Point.h"
// Класс Triangle для представления треугольника
class Triangle
{
public:
	// Конструктор с параметрами
	Triangle(Point, Point, Point, const char*);
	// Конструктор для создания пустого треугольника
	Triangle(const char*);
	// Деструктор
	~Triangle();
	// Методы для получения вершин треугольника
	Point Get_v1() const { return v1; }
	Point Get_v2() const { return v2; }
	Point Get_v3() const { return v3; }
	// Метод для получения имени объекта
	char* GetName() const { return name; }
	// Метод для отображения информации о треугольнике
	void Show() const;
	// Метод для отображения сторон и площади треугольника
	void ShowSideAndArea() const;
public:
	static int count; // Статическая переменная для подсчета объектов
private:
	char* objID; // Идентификатор объекта
	char* name; // Наименование треугольника
	Point v1, v2, v3; // Вершины треугольника
	double a; // Длина стороны между v1 и v2
	double b; // Длина стороны между v2 и v3
	double c; // Длина стороны между v1 и v3
};
#endif