// ����������� ����������� ������������ ������
#include <iostream>
#include "Triangle.h"
using namespace std;
// ���������� �������
int Menu(); // ������� ��� ����������� ���� � ������ ������
int GetNumber(int, int); // ������� ��� ��������� ������ ����� � �������� ���������
double GetDouble(); // ������� ��� ��������� ������������� �����
void ExitBack(); // ������� ��� �������� ������� Enter
void Show(Triangle* [], int); // ������� ��� ����������� ���� �������������
void Move(Triangle* [], int); // ������� ��� ����������� �������������
void FindMax(Triangle* [], int); // ������� ��� ������ ������������ � ������������ ��������
void IsIncluded(Triangle* [], int); // ������� ��� �������� ��������� ��������� �������������
// ������� ������� ���������
int main()
{
	setlocale(LC_ALL, "ru"); // ��������� ������ ��� ��������� �������� �����
	// �������� ����� ��� ������ �������������
	Point p1(0, 0); Point p2(0.5, 1);
	Point p3(1, 0); Point p4(0, 4.5);
	Point p5(2, 1); Point p6(2, 0);
	Point p7(2, 2); Point p8(3, 0);
	// �������� �������� ������������� � ��������� ��������� � ����������������
	Triangle triaA(p1, p2, p3, "triaA");
	Triangle triaB(p1, p4, p8, "triaB");
	Triangle triaC(p1, p5, p6, "triaC");
	Triangle triaD(p1, p7, p8, "triaD");
	// ������ ���������� �� ������������
	Triangle* pTria[] = { &triaA, &triaB, &triaC, &triaD };
	int n = sizeof(pTria) / sizeof(pTria[0]); // ���������� ���������� �������������
	bool done = false; // ���� ��� ���������� ������ ���������
	while (!done)
	{
		switch (Menu()) // ��������� ���������� ������ ����
		{
		case 1: Show(pTria, n); break; // �������� ��� ������������
		case 2: Move(pTria, n); break; // ����������� �����������
		case 3: FindMax(pTria, n); break; // ����� ������������ �����������
		case 4: IsIncluded(pTria, n); break; // ��������� ��������� ���������
		case 5: cout << "����� ������." << endl; done = true; break; // ����� �� ���������
		}
	}
	return 0;
}
// ������� ��� ����������� ���� � ������ ������
int Menu()
{
	cout << "\n=================== ������� ���� ===================\n" << endl;
	cout << "1 - ������� ��� o��e���\t 3 - ����� ������������" << endl;
	cout << "2 - nepe�������\t\t 4 - ���������� ��������� ���������" << endl;
	cout << "\t\t 5 - �����" << endl;
	return GetNumber(1, 5); // �������� ����� ���������� ������
}
// ������� ��� ��������� ������ ����� � �������� ���������
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
			cout << "��������� ���� (��������� ����� �� " << min << " �� " << max << " ) : " << endl;
			cin.clear(); // ����� ������ ������
			while (cin.get() != '\n') {}; // ������� ������ �����
		}
	}
	return number;
}
// ������� ��� ��������� ������������� �����
double GetDouble() {
	double value;
	while (true) {
		cin >> value;
		if (cin.peek() == '\n') break;
		else {
			cout << "��������� ���� (��������� ������������ �����):" << endl;
			cin.clear();
			while (cin.get() != '\n') {}
		}
	}
	return value;
}
// ������� ��� �������� ������� Enter
void ExitBack()
{
	cout << "������� Enter." << endl;
	cin.get(); cin.get();
}
// ������� ��� ����������� ���� �������������
void Show(Triangle* p_tria[], int k)
{
	cout << "======= �������� ������������� ========" << endl;
	for (int i = 0; i < k; ++i) p_tria[i]->Show(); // ����� ���������� � ������ ������������
	ExitBack(); // �������� ������� Enter
}
// ������� ��� ����������� ������������
void Move(Triangle* p_tria[], int k)
{
	cout << "============== ����������� ==========" << endl;
	cout << "������� ����� ������������ (�� 1 �� " << k << "): ";
	int i = GetNumber(1, k) - 1; // ��������� ������� ������������
	p_tria[i]->Show(); // ����������� �������� ��������� ������������

	Point dp; // ��������
	cout << "������� �������� �� x: ";
	dp.x = GetDouble(); // ��������� �������� �� x
	cout << "������� �������� �� y: ";
	dp.y = GetDouble(); // ��������� �������� �� y

	p_tria[i]->Move(dp); // ���������� ��������
	cout << "����� ��������� ������������:" << endl;
	p_tria[i]->Show(); // ����������� ������ ���������
	ExitBack(); // �������� ������� Enter
}
// ������� ��� ������ ������������ � ������������ ��������
void FindMax(Triangle* p_tria[], int k)
{
	cout << "=== ����� ������������� ������������ ==" << endl;
	ExitBack(); // �������� ������� Enter
}
// ������� ��� �������� ��������� ��������� �������������
void IsIncluded(Triangle* p_tria[], int k)
{
	cout << "======== ��������� ��������� ==========" << endl;
	ExitBack(); // �������� ������� Enter
}