// Отключение предупреждений безопасности
#define _CRT_SECURE_NO_WARNINGS
// Подключение необходимых заголовочных файлов
#include "Triangle.h"
#include <math.h>
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
// Инициализация статической переменной count
int Triangle::count = 0;
// Конструктор класса Triangle с параметрами
Triangle::Triangle(Point _v1, Point _v2, Point _v3, const char* ident) : v1(_v1), v2(_v2), v3(_v3)
{
	char buf[16];
	objID = new char[strlen(ident) + 1]; // Выделение памяти для идентификатора
	strcpy(objID, ident); // Копирование идентификатора
	count++; // Увеличение счетчика объектов
	sprintf(buf, "Треугольник %d", count); // Формирование имени треугольника (возможна ошибка кодировки)
	name = new char[strlen(buf) + 1]; // Выделение памяти для имени
	strcpy(name, buf); // Копирование имени
	// Вычисление длин сторон треугольника
	a = sqrt((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y));
	b = sqrt((v2.x - v3.x) * (v2.x - v3.x) + (v2.y - v3.y) * (v2.y - v3.y));
	c = sqrt((v1.x - v3.x) * (v1.x - v3.x) + (v1.y - v3.y) * (v1.y - v3.y));
	cout << "Constructor_l for: " << objID << " (" << name << " ) " << endl;
}
// Конструктор для создания пустого треугольника
Triangle::Triangle(const char* ident)
{
	char buf[16];
	objID = new char[strlen(ident) + 1]; // Выделение памяти для идентификатора
	strcpy(objID, ident); // Копирование идентификатора
	count++; // Увеличение счетчика объектов
	sprintf(buf, "Треугольник ^d", count); // Формирование имени треугольника (возможна ошибка кодировки)
	name = new char[strlen(buf) + 1]; // Выделение памяти для имени
	strcpy(name, buf); // Копирование имени
	a = b = c = 0; // Инициализация сторон нулями
	cout << "Constructor_2 for: " << objID << " (" << name << ")" << endl;
}
// Деструктор класса Triangle
Triangle::~Triangle()
{
	cout << "Destructor for: " << objID << endl;
	delete[] objID; // Освобождение памяти, выделенной для идентификатора
	delete[] name; // Освобождение памяти, выделенной для имени
}
// Метод для отображения информации о треугольнике
void Triangle::Show() const
{
	cout << name << ":";
	v1.Show(); v2.Show(); v3.Show(); // Отображение вершин
	cout << endl;
}
// Метод для перемещения треугольника
void Triangle::Move(Point dp)
{
	v1 += dp; v2 += dp; v3 += dp; // Применение смещения к каждой вершине
}