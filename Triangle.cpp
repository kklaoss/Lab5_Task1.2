#define _CRT_SECURE_NO_WARNINGS
#include "Triangle.h"
#include <math.h>
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
int Triangle::count = 0; // ������������� ��������
// �������� �����������
Triangle::Triangle(Point _v1, Point _v2, Point _v3, const char* ident) : v1(_v1), v2(_v2), v3(_v3)
{
	char buf[16];
	objID = new char[strlen(ident) + 1]; // ��������� ������ ��� ID
	strcpy(objID, ident);
	count++;
	sprintf(buf, "����������� %d", count); // ������������ �����
	name = new char[strlen(buf) + 1];
	strcpy(name, buf);
	// ���������� ���� ������
	a = sqrt(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2));
	b = sqrt(pow(v2.x - v3.x, 2) + pow(v2.y - v3.y, 2));
	c = sqrt(pow(v1.x - v3.x, 2) + pow(v1.y - v3.y, 2));
	cout << "Constructor_l for: " << objID << " (" << name << " ) " << endl;
}
// ����������� ������� ������������
Triangle::Triangle(const char* ident)
{
	char buf[16];
	objID = new char[strlen(ident) + 1];
	strcpy(objID, ident);
	count++;
	sprintf(buf, "����������� %d", count);
	name = new char[strlen(buf) + 1];
	strcpy(name, buf);
	a = b = c = 0; // ������� �������
	cout << "Constructor_2 for: " << objID << " (" << name << ")" << endl;
}
// ����������� �����������
Triangle::Triangle(const Triangle& tria) : v1(tria.v1), v2(tria.v2), v3(tria.v3)
{
	cout << "Copy constructor for: " << tria.objID << endl;
	objID = new char[strlen(tria.objID) + strlen("(�����)") + 1];
	strcpy(objID, tria.objID);
	strcat(objID, "(�����)"); // ���������� ������� � ID
	name = new char[strlen(tria.name) + 1];
	strcpy(name, tria.name);
	a = tria.a; b = tria.b; c = tria.c; // ����������� ������
	count++;
}
// ����������
Triangle::~Triangle()
{
	cout << "Destructor for: " << objID << endl;
	delete[] objID; // ������������ ������
	delete[] name;
}
// ����� ����������� ������������
void Triangle::Show() const
{
	cout << name << ":";
	v1.Show(); v2.Show(); v3.Show(); // ����� ������
	cout << endl;
}
// ����� ����������� ������������
void Triangle::Move(Point dp)
{
	v1 += dp; v2 += dp; v3 += dp; // �������� ���� ������
}
// �������� ��������� > (�� �������)
bool Triangle::operator >(const Triangle& tria) const
{
	// ���������� ������� �������� ������������
	double p = (a + b + c) / 2;
	double s = sqrt(p * (p - a) * (p - b) * (p - c));
	// ���������� ������� ������� ������������
	double pl = (tria.a + tria.b + tria.c) / 2;
	double sl = sqrt(pl * (pl - tria.a) * (pl - tria.b) * (pl - tria.c));
	return s > sl; // ��������� ��������
}
// �������� ������������
Triangle& Triangle::operator =(const Triangle& tria)
{
	cout << "Assign operator: " << objID << " = " << tria.objID << endl;
	if (&tria == this) return *this; // �������� �� ����������������
	delete[] name; // ������������ ������ ������
	name = new char[strlen(tria.name) + 1]; // ��������� �����
	strcpy(name, tria.name); // ����������� �����
	a = tria.a; b = tria.b; c = tria.c; // ����������� ������
	return *this;
}