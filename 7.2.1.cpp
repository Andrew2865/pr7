// Lab_7_2.cpp
// < Штогрин Андрій >
// Лабораторна робота No 7.2.1
// Пошук заданих елементів та впорядкування рядків  стовпчиків матриці.
// Варіант 9
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int n, const int Low, const int High);
void Print(int** a, const int n);
bool MaxMin(int** a, const int rowCount, const int colCount);
int main()
{
	srand((unsigned)time(NULL));
	int Low = - 10;
	int High = 10;
	int n;
	cout << "n = "; cin >> n;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	Create(a, n, Low, High);
	Print(a, n);
	int maxMin;
	if (MaxMin(a, n, maxMin))
		cout << "max element = " << maxMin << endl;
	else
		cout << "there are no even elements" << endl;


		for (int i = 0; i < n; i++)
			delete[] a[i];
	delete[] a;
	return 0;
}
void Create(int** a, const int n, const int Low, const int High)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
bool MaxMin(int** a, const int rowCount, const int colCount)
{
	int* min = new int[rowCount];
	for (int i = 0; i < rowCount; i++)
	{
		min[i] = a[i][0];
		for (int j = 1; j < colCount; j++)
			if (a[i][j] < min[i])
				min[i] = a[i][j];
	}
	int max = min[0];
	for (int i = 1; i < rowCount; i++)
		if (min[i] > max)
			max = min[i];
	delete[] min;
	return max;
}