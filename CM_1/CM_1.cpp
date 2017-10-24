// CM_1.cpp: определяет точку входа для консольного приложения.
#include "stdafx.h"
#include "iostream"
#include <cstdlib>
#include <ctime>
using namespace std;
int n = 3;								 //размерность матрицы

										 //Random заполнение матрицы от 0 до 9
void Rnd(float **M,float** Ch, int n)
{
	int i = 0, j = 0;
	srand(time(NULL));                      // инициализация функции rand значением функции time
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n+1; j++)
		{
			M[i][j] = rand() % 9 + 1;
			Ch[i][j] = M[i][j];
			//cin >> M[i][j];
			cout << " " << M[i][j];
		}
		cout << endl;
	}
}
//Поиск максимального по столбцу
void Swp_stlb(float **M, int n, int flag)
{
	int i = 0, j = 0;
		float max = M[flag][flag]; //за макс возьмем первый элемент в каждом столбце
		int max_i = flag;//, max_j = j; // координаты текущего макса
		for (i = flag; i < n; i++) //строки
		{
			if (M[i][flag] > max)
			{
				max = M[i][flag];
				max_i = i;
				//max_j = j;
			}
		}
		if (M[flag][flag] != max)
		{
			for (j = 0;j < n+1; j++)
			{
				float swp = M[flag][j];
				M[flag][j] = M[max_i][j];
				M[max_i][j] = swp;
			}
		}
#pragma region Print
	cout << "SWAP" << endl;
	for (i = 0; i < n; i++) 
	{
		for (j = 0; j < n+1; j++)
		{
			cout << " " << M[i][j];
		}
		cout << endl;
	}
#pragma endregion
}
float Deter(float **M, int n)
{
	float det = 1;
	for (int i = 0; i < n; i++)
	{
		det = det*M[i][i];
	}
	return det;
}
void Top_trngl(float **M, int n)
{
	int i = 0, j = 0;
	int flag = 0;
	int diag_el = 1;
	while (flag < n)
	{
		Swp_stlb(M, n, flag);
		float del = M[flag][flag];
		/*for (j = 0; j < n; j++)
		{
			M[flag][j] = M[flag][j] / del;
		}
		cout << "check" << endl;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				std::cout.setf(std::ios::fixed);
				cout.precision(2);
				cout << " " << M[i][j];
			}
			cout << endl;
		}*/
		if (del != 0)
		{
			i = flag + 1;
			while (i < n)
			{
				
				float vych = M[i][flag];
				for (j = flag; j < n+1; j++)
				{
					M[i][j] = -1.0*M[flag][j] * vych / (del*1.0) + M[i][j];
				}
				i++;
			}
		}
		else
			{
				cout << "STOP" << endl;
				break;
			}
		cout << "check" << endl;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n+1; j++)
			{
				std::cout.setf(std::ios::fixed);
				cout.precision(4);
				cout << " " << M[i][j];
			}
			cout << endl;
		}
		flag++;
	} 
	/*cout << "check" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n+1; j++)
		{
			std::cout.setf(std::ios::fixed);
			cout.precision(2);
			cout<< " " << M[i][j];
		}
		cout << endl;
	}*/
}void Reverce(float** M, float* X, int n)
{
	X[n-1] = M[n-1][n] / M[n-1][n-1];
	int i = 0,j=1;
	for (i = 2; i <= n; i++)
	{
		X[n - i] = M[n - i][n];
		while ( j < i)
		{
			X[n - i] = X[n - i] - X[n - i + j] * M[n - i][n - i + j];
			j++;
		}
		X[n - i] = X[n - i] / M[n - i][n - i];
		j = 1;
	}
}
int main()
{
	float **M = new float*[n];
	float **Ch = new float*[n];
	float *X = new float[n];
	for (int count = 0; count < n; count++) {
		M[count] = new float[n];
		Ch[count] = new float[n];
	}
	cout << endl << "SOURCE!" << endl;

	Rnd(M,Ch, n);
	//to_do 
	//Сделай менЮ!!!!
	cout << endl << "TOP_TRNGL" << endl;
	Top_trngl(M, n);
	float det=Deter(M, n);
	if (det != 0)
	{
		cout << "Determinant=" <<det<<endl;
		Reverce(M, X,n);
	}
	else
		{
			cout << "STOP" << endl;
			system("pause");
 			return 0;
		}
	cout << "ROOTS" << endl;
	for (int i = 0; i < n; i++)
	{
		
		cout <<i<<") "<<X[i] << endl;
	}
	float check = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			check = check + Ch[i][j] * X[j];
		}
		cout << "check=" << check << endl;
		check = 0;
	}
	system("pause");
	return 0;
}

