// CM_1.cpp: определяет точку входа для консольного приложения.
#include "stdafx.h"
#include "iostream"
#include <cstdlib>
#include <ctime>
using namespace std;
int n = 3;								 //размерность матрицы

										 //Random заполнение матрицы от 0 до 9
void Rnd(float **M, int n)
{
	int i = 0, j = 0;
	srand(time(NULL));                      // инициализация функции rand значением функции time
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n+1; j++)
		{
			M[i][j] = rand() % 9 + 1;
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
	//for (j = 0; j < n; j++) //столбцы
	//{
		int max = M[0][flag]; //за макс возьмем первый элемент в каждом столбце
		int max_i = 0;//, max_j = j; // координаты текущего макса
		for (i = 0; i < n; i++) //строки
		{
			if (abs(M[i][flag]) > abs(max))
			{
				max = M[i][flag];
				max_i = i;
				//max_j = j;
			}
		}
		if (M[flag][flag] != max)
		{
			for (j = 0;j < n; j++)
			{
				float swp = M[flag][j];
				M[flag][j] = M[max_i][j];
				M[max_i][j] = swp;
			}
			
			//M[j][j] = max;
			//M[max_i][max_j] = swp;
		}
	//}
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
void Top_trngl(float **M, int n)
{
	int i = 0, j = 0;
	int flag = 0;
	int diag_el = 1;
	
	//while (flag != n)
	//{
	//	diag_el = M[flag][flag];
	//	if (diag_el != 0)			//проверка на нулевой столбец
	//	{
	//		//деление на очередной диагональный элемент
	//		//какой-то бред
	//		//for (i = flag; i < n; i++)
	//		//{
	//			for (j = 0; j < n; j++)
	//			{

	//				M[flag][j] = M[flag][j] / (1.0*diag_el);
	//			}

	//		//}
	//		//
	//	}
	//	else
	//	{
	//		cout << "STOP" << endl;
	//		break;
	//	}
	//	//вывод после деления
	//	cout<<"AFTER DEL"<<endl;
	//	for (i = 0; i < n; i++)
	//	{
	//		for (j = 0; j < n; j++)
	//		{
	//			std::cout.setf(std::ios::fixed);
	//			cout.precision(2);
	//			cout << " " << M[i][j];
	//		}
	//		cout << endl;
	//	}
	//	cout << endl << "TOBI PIZDA"<<endl;
	//	for (int k = flag; k < n; k++) //вычитание 
	//	{
	//		//float del = M[k][0];
	//		for (int l = flag+1; l < n; l++)
	//		{
	//			//if (l != k)
	//			//{
	//				float del = M[l][k];
	//				M[l][k] = M[flag][k] * del - del;
	//			//}
	//		}
	//	}
	//	flag++;
	//}
	//вывод
	while (flag < n)
	{
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
				//Swp_stlb(M, n, flag);
				float vych = M[i][flag];
				for (j = flag; j < n+1; j++)
				{
					M[i][j] = -1.0*M[flag][j] * vych / (del*1.0) + M[i][j];
				}
				i++;
			}
		}
		cout << "check" << endl;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n+1; j++)
			{
				std::cout.setf(std::ios::fixed);
				cout.precision(2);
				cout << " " << M[i][j];
			}
			cout << endl;
		}
		flag++;
	} 
	cout << "check" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n+1; j++)
		{
			std::cout.setf(std::ios::fixed);
			cout.precision(2);
			cout<< " " << M[i][j];
		}
		cout << endl;
	}
}
int main()
{
	float **M = new float*[n];
	//float *X = new float[n];
	for (int count = 0; count < n; count++)
		M[count] = new float[n];
	cout << endl << "SOURCE!" << endl;

	Rnd(M, n);
	//to_do
	//Сделай менЮ!!!!
	//cout << endl << "SWAP_STOLB!" << endl;
	//Swp_stlb(M, n);

	cout << endl << "TOP_TRNGL" << endl;
	Top_trngl(M, n);
	/*X[n - 1] = M[n - 1][n]/M[n-1][n-1];
	for (int i = n-2; i >=0; i--)
	{
		X[i] = M[i][i + 1];
		for (int j = 0; j < i; j++)
		{
			X[i] = X[i] - X[i + j]*M[][];
		}
	}*/
	system("pause");
	return 0;
}

