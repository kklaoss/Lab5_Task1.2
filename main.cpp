// Подключение необходимых заголовочных файлов
#include <iostream>
#include "Triangle.h"
using namespace std;
// Объявление функций
int Menu(); // Функция для отображения меню
int GetNumber(int, int); // Функция для получения числа в диапазоне
double GetDouble(); // Функция для получения вещественного числа
void ExitBack(); // Функция для ожидания нажатия Enter
void Show(Triangle* [], int); // Вывод всех треугольников
void Move(Triangle* [], int); // Перемещение треугольника
void FindMax(Triangle* [], int); // Поиск треугольника с максимальной площадью
void IsIncluded(Triangle* [], int); // Проверка включения треугольников
int main()
{
	setlocale(LC_ALL, "ru"); // Установка русской локали
	// Создание точек-вершин треугольников
	Point p1(0, 0); Point p2(0.5, 1);
	Point p3(1, 0); Point p4(0, 4.5);
	Point p5(2, 1); Point p6(2, 0);
	Point p7(2, 2); Point p8(3, 0);
	// Создание треугольников
	Triangle triaA(p1, p2, p3, "triaA");
	Triangle triaB(p1, p4, p8, "triaB");
	Triangle triaC(p1, p5, p6, "triaC");
	Triangle triaD(p1, p7, p8, "triaD");
	// Массив указателей на треугольники
	Triangle* pTria[] = { &triaA, &triaB, &triaC, &triaD };
	int n = sizeof(pTria) / sizeof(pTria[0]); // Количество треугольников
	bool done = false; // Флаг завершения программы
	while (!done)
	{
		switch (Menu()) // Обработка меню
		{
		case 1: Show(pTria, n); break; // Показать треугольники
		case 2: Move(pTria, n); break; // Переместить треугольник
		case 3: FindMax(pTria, n); break; // Найти максимальный
		case 4: IsIncluded(pTria, n); break; // Проверить включение
		case 5: cout << "Конец работы." << endl; done = true; break; // Выход
		}
	}
	return 0;
}
// Функция отображения меню
int Menu()
{
	cout << "\n=================== Главное меню ===================\n" << endl;
	cout << "1 - вывести все oбъeкты\t 3 - найти максимальный" << endl;
	cout << "2 - nepeместить\t\t 4 - определить отношение включения" << endl;
	cout << "\t\t 5 - выход" << endl;
	return GetNumber(1, 5); // Получение выбора пользователя
}
// Функция получения числа в диапазоне [min, max]
int GetNumber(int min, int max)
{
	int number = min - 1;
	while (true)
	{
		cin >> number;
		if ((number >= min) && (number <= max) && (cin.peek() == '\n'))
			break;
		else
		{
			cout << "Повторите ввод (ожидается число от " << min << " до " << max << " ) : " << endl;
			cin.clear(); // Сброс ошибок
			while (cin.get() != '\n') {}; // Очистка буфера
		}
	}
	return number;
}
// Функция получения вещественного числа
double GetDouble()
{
	double value;
	while (true)
	{
		cin >> value;
		if (cin.peek() == '\n') break;
		else
		{
			cout << "Повторите ввод (ожидается вещественное число):" << endl;
			cin.clear();
			while (cin.get() != '\n') {}
		}
	}
	return value;
}
// Функция ожидания нажатия Enter
void ExitBack()
{
	cout << "Нажмите Enter." << endl;
	cin.get(); cin.get();
}
// Функция вывода всех треугольников
void Show(Triangle* p_tria[], int k)
{
	cout << "======= Перечень треугольников ========" << endl;
	for (int i = 0; i < k; ++i) p_tria[i]->Show();
	ExitBack();
}
// Функция перемещения треугольника
void Move(Triangle* p_tria[], int k)
{
	cout << "============== Перемещение ==========" << endl;
	cout << "Введите номер треугольника (от 1 до " << k << "): ";
	int i = GetNumber(1, k) - 1; // Получение индекса треугольника
	p_tria[i]->Show(); // Показ текущего положения
	Point dp; // Смещение
	cout << "Введите смещение по x: ";
	dp.x = GetDouble();
	cout << "Введите смещение по y: ";
	dp.y = GetDouble();
	p_tria[i]->Move(dp); // Применение смещения
	cout << "Новое положение треугольника:" << endl;
	p_tria[i]->Show(); // Показ нового положения
	ExitBack();
}
// Функция поиска треугольника с максимальной площадью
void FindMax(Triangle* p_tria[], int k)
{
	cout << "=== Поиск максимального треугольника ==" << endl;
	Triangle triaMax("triaMax"); // Временный объект
	triaMax = *p_tria[0]; // Начальное значение
	for (int i = 1; i < k; ++i)
		if (*p_tria[i] > triaMax) // Сравнение площадей
			triaMax = *p_tria[i];
	cout << "Максимальный треугольник: " << triaMax.GetName() << endl;
	ExitBack();
}
// Функция проверки включения треугольников (заглушка)
void IsIncluded(Triangle* p_tria[], int k)
{
	cout << "======== Отношение включения ==========" << endl;
	ExitBack();
}