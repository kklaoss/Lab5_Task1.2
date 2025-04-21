// Подключение необходимых заголовочных файлов
#include <iostream>
#include "Point.h"
// Метод для отображения координат точки
void Point::Show() const
{
	std::cout << " (" << x << y << ").";
}