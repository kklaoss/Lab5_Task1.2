// Отключение предупреждений безопасности
#define _CRT_SECURE_NO_WARNINGS
// Подключение необходимых заголовочных файлов
#include "Triangle.h"
#include <math.h>
#include <iostream>
#include <iomanip>
#include <cstring>
// Использование стандартного пространства имен
using namespace std;
// Конструктор класса Triangle с параметрами
Triangle::Triangle(Point _v1, Point _v2, Point _v3, const char* ident) : v1(_v1), v2(_v2), v3(_v3)
{
	char buf[16];
	// Выделение памяти и копирование идентификатора
	objID = new char[strlen(ident) + 1];
	strcpy(objID, ident);
	count++; // Увеличение счетчика объектов
	// Формирование имени треугольника
	sprintf(buf, "Треугольник %d", count);
	name = new char[strlen(buf) + 1];
	strcpy(name, buf);
	// Вычисление длин сторон треугольника
	a = sqrt((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y));
	b = sqrt((v2.x - v3.x) * (v2.x - v3.x) + (v2.y - v3.y) * (v2.y - v3.y));
	c = sqrt((v1.x - v3.x) * (v1.x - v3.x) + (v1.y - v3.y) * (v1.y - v3.y));
	// Вывод информации о создании объекта
	cout << "Constructor_l for: " << objID
		<< " (" << name << " ) " << endl;
}
// Конструктор для создания пустого треугольника
Triangle::Triangle(const char* ident)
{
	char buf[16];
	// Выделение памяти и копирование идентификатора
	objID = new char[strlen(ident) + 1];
	strcpy(objID, ident);
	count++; // Увеличение счетчика объектов
	// Формирование имени треугольника
	sprintf(buf, "Треугольник ^d", count);
	name = new char[strlen(buf) + 1];
	strcpy(name, buf);
	a = b = c = 0; // Инициализация сторон нулями
	cout << "Constructor_2 for: " << objID << " (" << name << ")" << endl;
}
// Деструктор класса Triangle
Triangle::~Triangle()
{
	cout << "Destructor for: " << objID << endl;
	// Освобождение выделенной памяти
	delete[] objID;
	delete[] name;
}
// Метод для отображения информации о треугольнике
void Triangle::Show() const
{
	cout << name << ":";
	v1.Show(); v2.Show(); v3.Show(); // Отображение вершин
	cout << endl;
}
// Метод для отображения сторон и площади треугольника
void Triangle::ShowSideAndArea() const
{
	// Вычисление полупериметра
	double p = (a + b + c) / 2;
	// Вычисление площади по формуле Герона
	double s = sqrt(p * (p - a) * (p - b) * (p - c));
	cout << " • " << endl;
	cout << name << ":";
	cout.precision(4); // Установка точности вывода
	cout << " a = " << setw(5) << a;
	cout << ". b = " << setw(5) << b;
	cout << ". c = " << setw(5) << c;
	cout << ";\ts = " << s << endl;
}