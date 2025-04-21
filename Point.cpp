#include <iostream>
#include "Point.h"
// ����� ����������� ��������� �����
void Point::Show() const
{
	std::cout << " (" << x << ", " << y << ").";
}
// ���������� ��������� += ��� �������� �����
void Point::operator +=(Point& p)
{
	x += p.x; // �������� x-���������
	y += p.y; // �������� y-���������
}