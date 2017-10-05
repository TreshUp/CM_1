// CM_1.cpp: определяет точку входа для консольного приложения.
#include "stdafx.h"
#include "iostream"
#include <cstdlib>
#include <ctime>
using namespace std;
int n = 7;								 //размерность матрицы

										 //Random заполнение матрицы от 0 до 9
void Rnd(int **M, int n)
{
	int i = 0, j = 0;
	srand(time(NULL));                      // инициализация функции rand значением функции time
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			M[i][j] = rand() % 9 + 1;
			cout << " " << M[i][j];
		}
		cout << endl;
	}
}
//Поиск максимального по столбцу
void Swp_stlb(int **M, int n)
{
	int i = 0, j = 0;
	for (j = 0; j < n; j++) //столбцы
	{
		int max = M[0][j]; //за макс возьмем первый элемент в каждом столбце
		int max_i = 0, max_j = j; // координаты текущего макса
		for (i = 0; i < n; i++) //строки
		{
			if (abs(M[i][j]) > abs(max))
			{
				max = M[i][j];
				max_i = i;
				max_j = j;
			}
		}
		if (M[j][j] != max)
		{
			int swp = M[j][j];
			M[j][j] = max;
			M[max_i][max_j] = swp;
		}
	}
#pragma region Print
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << " " << M[i][j];
		}
		cout << endl;
	}
#pragma endregion
}
//int Deter(int **M, int n)
//{
//	int det = 0;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			
//			det=det+M[i][j]*Det
//		}
//	}
//	return det;
//}
void Top_trngl(int **M, int n)
{
	int i = 0, j = 0;
	int flag = 0;
	int diag_el = 1;
	diag_el = M[flag][flag];
	while (flag != n)
	{
		if (diag_el != 0)
		{
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{

					M[i][j] = M[i][j] / (1.0*diag_el);
				}

			}
		}
		else
		{
			cout << "STOP" << endl;
			break;
		}
		flag++;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << " " << M[i][j];
		}
		cout << endl;
	}
}
int main()
{
	int **M = new int*[n];
	for (int count = 0; count < n; count++)
		M[count] = new int[n];
	cout << endl << "SOURCE!" << endl;
	Rnd(M, n);
	//to_do
	//Сделай менЮ!!!!
	cout << endl << "SWAP_STOLB!" << endl;

	Swp_stlb(M, n);
	cout << endl << "TOP_TRNGL" << endl;
	Top_trngl(M, n);
	system("pause");
	return 0;
}

