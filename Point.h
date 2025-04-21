// Защита от повторного включения заголовочного файла
#ifndef POINT_H
#define POINT_H
// Класс Point для представления точки в двумерном пространстве
class Point
{
public:
	Point(double _x = 0, double _y = 0) : x(_x), y(_y) {} // Конструктор с параметрами по умолчанию
	void Show() const; // Метод для отображения координат точки
	void operator +=(Point&); // Перегрузка оператора +=
public:
	double x, y; // Координаты точки
};
#endif