// Подключение необходимых заголовочных файлов
#include <iostream>
#include "Triangle.h"
// Использование стандартного пространства имен
using namespace std;
// Объявление функций
int Menu(); // Функция для отображения меню и выбора пункта
int GetNumber(int, int); // Функция для получения числа в заданном диапазоне
void ExitBack(); // Функция для ожидания нажатия Enter
void Show(Triangle* [], int); // Функция для отображения всех треугольников
void Move(Triangle* [], int); // Функция для перемещения треугольников
void FindMax(Triangle* [], int); // Функция для поиска треугольника с максимальной площадью
void IsIncluded(Triangle* [], int); // Функция для проверки отношения включения треугольников
// Инициализация статической переменной count класса Triangle
int Triangle::count = 0;
// Главная функция программы
int main()
{
	// Установка локали для поддержки русского языка
	setlocale(LC_ALL, "ru");
	// Создание точек для вершин треугольников
	Point p1(0, 0); Point p2(0.5, 1);
	Point p3(1, 0); Point p4(0, 4.5);
	Point p5(2, 1); Point p6(2, 0);
	Point p7(2, 2); Point p8(3, 0);
	// Создание объектов треугольников с заданными вершинами и идентификаторами
	Triangle triaA(p1, p2, p3, "triaA");
	Triangle triaB(p1, p4, p8, "triaB");
	Triangle triaC(p1, p5, p6, "triaC");
	Triangle triaD(p1, p7, p8, "triaD");
	// Массив указателей на треугольники
	Triangle* pTria[] = { &triaA, &triaB, &triaC, &triaD };
	// Вычисление количества треугольников в массиве
	int n = sizeof(pTria) / sizeof(pTria[0]);
	// Флаг для завершения работы программы
	bool done = false;
	// Основной цикл программы
	while (!done)
	{
		// Выбор действия на основе выбранного пункта меню
		switch (Menu())
		{
		case 1: Show(pTria, n); break; // Показать все треугольники
		case 2: Move(pTria, n); break; // Переместить треугольники
		case 3: FindMax(pTria, n); break; // Найти максимальный треугольник
		case 4: IsIncluded(pTria, n); break; // Проверить отношение включения
		case 5: cout << "Конец работы." << endl; done = true; break; // Выход из программы
		}
	}
	return 0;
}
// Функция для отображения меню и выбора пункта
int Menu()
{
	cout << "\n=================== Главное меню ===================\n" << endl;
	cout << "1 - вывести все oбъeкты\t 3 - найти максимальный" << endl;
	cout << "2 - nepeместить\t\t 4 - определить отношение включения" << endl;
	cout << "\t\t 5 - выход" << endl;
	return GetNumber(1, 5); // Получить номер выбранного пункта
}
// Функция для получения числа в заданном диапазоне
int GetNumber(int min, int max)
{
	int number = min - 1;
	while (true)
	{
		std::cin >> number;
		// Проверка на корректность ввода
		if ((number >= min) && (number <= max) && (std::cin.peek() == '\n'))
		{
			break;
		}
		else
		{
			cout << "Повторите ввод (ожидается число от " << min
				<< " до " << max << " ) : " << endl;
			std::cin.clear(); // Сброс флагов ошибок
			while (std::cin.get() != '\n') {}; // Очистка буфера ввода
		}
	}
	return number;
}
// Функция для ожидания нажатия Enter
void ExitBack()
{
	cout << "Нажмите Enter." << endl;
	cin.get(); cin.get(); // Ожидание ввода
}
// Функция для отображения всех треугольников
void Show(Triangle* p_tria[], int k)
{
	cout << "======= Перечень треугольников ========" << endl;
	// Вывод информации о каждом треугольнике
	for (int i = 0; i < k; ++i) p_tria[i]->Show();
	for (int i = 0; i < k; ++i) p_tria[i]->ShowSideAndArea();
	ExitBack(); // Ожидание нажатия Enter
}
// Функция для перемещения треугольников
void Move(Triangle* p_tria[], int k)
{
	cout << "============= Перемещение =============" << endl;
	// здесь будет код функции...
	ExitBack(); // Ожидание нажатия Enter
}
// Функция для поиска треугольника с максимальной площадью
void FindMax(Triangle* p_tria[], int k) {
	cout << "=== Поиск максимального треугольника ==" << endl;
	// здесь будет код функции...
	ExitBack(); // Ожидание нажатия Enter
}
// Функция для проверки отношения включения треугольников
void IsIncluded(Triangle* p_tria[], int k) {
	cout << "======== Отношение включения ==========" << endl;
	// здесь будет код функции...
	ExitBack(); // Ожидание нажатия Enter
}