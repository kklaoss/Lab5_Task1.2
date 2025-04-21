// Защита от повторного включения заголовочного файла
#pragma once
#ifndef POINT_H
#define POINT_H
// Класс Point для представления точки в двумерном пространстве
class Point
{
public:
	// Конструктор с параметрами по умолчанию
	Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
	// Метод для отображения координат точки
	void Show() const;
public:
	double x, y; // Координаты точки
};
#endif