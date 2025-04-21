#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Point.h"
class Triangle
{
public:
	Triangle(Point, Point, Point, const char*); // �������� �����������
	Triangle(const char*); // ����������� ������� ������������
	Triangle(const Triangle&); // ����������� �����������
	~Triangle(); // ����������
	// ������ �������
	Point Get_v1() const { return v1; }
	Point Get_v2() const { return v2; }
	Point Get_v3() const { return v3; }
	char* GetName() const { return name; }
	void Show() const; // �������� �����������
	void Move(Point); // ����������� �����������
	bool operator >(const Triangle&) const; // ��������� �� �������
	Triangle& operator =(const Triangle&); // �������� ������������
	static int count; // ������� ��������
private:
	char* objID; // ������������� �������
	char* name; // �������� ������������
	Point v1, v2, v3; // �������
	double a, b, c; // ����� ������
};
#endif