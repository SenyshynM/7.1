// Lab_7_1.cpp
// < Сенишина Михайла >
// Лабораторна робота № 7.1.
// Пошук заданих елементів та впорядкування рядків / стовпчиків матриці.
// Варіант 10

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** q, const int rowCount, const int colCount, const int Low, const int High, int i, int j);
void Print(int** q, const int rowCount, const int colCount, int i, int j);
void SumRows(int** q, const int rowCount, const int colCount, int rowNo, int& S, int& k);
void SumRow(int** q, const int rowNo, const int colCount, int colNo, int& S, int& k);


int main()
{
	srand((unsigned)time(NULL));
	int Low = -26;
	int High = 23;
	int rowCount = 6;
	int colCount = 8;
	int** q = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		q[i] = new int[colCount];
	Create(q, rowCount, colCount, Low, High, 0, 0);
	Print(q, rowCount, colCount, 0, 0);
	int S = 0;
	int k = 0;
	SumRows(q, rowCount, colCount, 0, S, k);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;
	Print(q, rowCount, colCount, 0, 0);
	for (int i = 0; i < rowCount; i++)
		delete[] q[i];
	delete[] q;
	return 0;
}

void Create(int** q, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
	q[i][j] = Low + rand() % (High - Low + 1);
	if (j < colCount - 1)
		Create(q, rowCount, colCount, Low, High, i, j + 1);
	if (i < rowCount - 1)
		Create(q, rowCount, colCount, Low, High, i + 1, 0);
}

void Print(int** q, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << q[i][j];
	if (j < colCount - 1)
		Print(q, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(q, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl << endl;
}

void SumRow(int** q, const int rowNo, const int colCount, int colNo, int& S, int& k)
{
	if (!(q[rowNo][colNo] % 2 == 0 && q[rowNo][colNo] > 0))
	{
		S += q[rowNo][colNo];
		q[rowNo][colNo] = 0;
		k++;
	}
	if (colNo < colCount - 1) {
		SumRow(q, rowNo, colCount, colNo + 1, S, k);
	}
}

void SumRows(int** q, const int rowCount, const int colCount, int rowNo, int& S, int& k)
{
	SumRow(q, rowNo, colCount, 0, S, k);
	if (rowNo < rowCount - 1)
	{
		SumRows(q, rowCount, colCount, rowNo + 1, S, k);
	}
}

//	if (!(q[i][j] % 2 == 0 && q[i][j] > 0))