// CM_1.cpp: ���������� ����� ����� ��� ����������� ����������.
#include "stdafx.h"
#include "iostream"
#include <cstdlib>
#include <ctime>
using namespace std;
int n = 3;								 //����������� �������

										 //Random ���������� ������� �� 0 �� 9
void Rnd(float **M,float** Ch, int n)
{
	int i = 0, j = 0;
	srand(time(NULL));                      // ������������� ������� rand ��������� ������� time
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n+1; j++)
		{
			//cin >> M[i][j];
			M[i][j] = rand() % 9 + 1;
			Ch[i][j] = M[i][j];
			
			cout << " " << M[i][j];
		}
		cout << endl;
	}
}
//����� ������������� �� �������
void Swp_stlb(float **M, int n, int flag)
{
	int i = 0, j = 0;
		float max = M[flag][flag]; //�� ���� ������� ������ ������� � ������ �������
		int max_i = flag;//, max_j = j; // ���������� �������� �����
		for (i = flag; i < n-1; i++) //������
		{
			if (abs(M[i][flag]) > abs(max))
			{
				max = M[i][flag];
				max_i = i;
				//max_j = j;
			}
		}
		if (abs(M[flag][flag]) != abs(max))
		{
			for (j = 0;j < n+1; j++)
			{
				float swp = M[flag][j];
				M[flag][j] = M[max_i][j];
				M[max_i][j] = swp;
			}
		}
//#pragma region Print
//	cout << "SWAP" << endl;
//	for (i = 0; i < n; i++) 
//	{
//		for (j = 0; j < n+1; j++)
//		{
//			cout << " " << M[i][j];
//		}
//		cout << endl;
//	}
//#pragma endregion
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
void Swp_str(float** M, int n,int flag,float* Y)
{
	int i = 0, j = 0;
	float max = M[flag][flag]; //�� ���� ������� ������ ������� � ������ �������
	int max_j = flag; // ���������� �������� �����

	for (j = flag; j < n; j++) //�������
	{
		if (abs(M[flag][j]) > abs(max))
		{
			max = M[flag][j];
			max_j = j;
		}
	}
	if (abs(M[flag][flag]) != abs(max))
	{
		for (i = 0; i < n; i++)
		{
			float swp = M[i][flag];
			M[i][flag] = M[i][max_j];
			M[i][max_j] = swp;
			
		}
		float swp = Y[flag];
		Y[flag] = Y[max_j];
		Y[max_j] = swp;//flag
	}
	/*cout << "SWAP" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n + 1; j++)
		{
			cout << " " << M[i][j];
		}
		cout << endl;
	}*/
}
void Top_trngl(float **M, int n,float * Y,int choise)
{
	int i = 0, j = 0;
	int flag = 0;
	int diag_el = 1;
	while (flag < n)
	{
		if (choise == 0)
		{
			Swp_stlb(M, n, flag);
		}
		else
		{
			Swp_str(M, n, flag, Y);
		}
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
		/*cout << "check" << endl;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n+1; j++)
			{
				std::cout.setf(std::ios::fixed);
				cout.precision(4);
				cout << " " << M[i][j];
			}
			cout << endl;
		}*/
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
	float *Y = new float[n];
	for (int count = 0; count < n; count++) {
		M[count] = new float[n];
		Ch[count] = new float[n];
		Y[count] = count;
	}
	cout << endl << "SOURCE!" << endl;
		Rnd(M,Ch, n);
	int choice = 2;
	while (1)
	{
		cout << "Press 0 to use the biggest element in column, else press 1. Press 9 to exit: ";
		cin >> choice;
		if (choice != 9) {
			//cout << endl << "TOP_TRNGL" << endl;
			Top_trngl(M, n, Y, choice);
			float det = Deter(M, n);
			if (det != 0)
			{
				//cout << "Determinant=" << det << endl;
				Reverce(M, X, n);
			}
			else
			{
				cout << "STOP" << endl;
				system("pause");
				return 0;
			}
			cout << "YY!!" << endl;
			for (int i = 0; i < n; i++)
			{
				cout << Y[i] << " |";
				//cout << X[i] << " ";
			}
			cout << "ROOTS" << endl;
			int no = 0;
			for (int i = 0; i < n; i++)
			{
				if ((int)Y[i] == i)
				{
					cout << i << ") " << X[i] << endl;
				}
				else
				{
					/*float tmp;
					tmp = X[i];
					X[i] = X[(int)Y[i]];
					X[(int)Y[i]] = tmp;
					tmp = Y[i];
					Y[i] = i;
					Y[(int)tmp] = tmp;
					cout << i << ") " << X[i] << endl;*/
					
					for (int j = no; j < n; j++)
					{
						if (i == Y[j])
						{
							float tmp;
							tmp = X[i];
							X[i] = X[j];
							X[j] = tmp;
							tmp = Y[i];
							Y[i] = Y[j];
							Y[j] = tmp;
						}
					}
					no++;
					cout << i << ") " << X[i] << endl; 
				}
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
		}
		else break;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n+1; j++)
			{
				M[i][j] = Ch[i][j];
			}		
			cout << endl;
		}
		for (int count = 0; count < n; count++) {
			Y[count] = count;
		}
	}
	system("pause");
	return 0;
}

