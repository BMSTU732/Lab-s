// Lab4_Matric.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <cstdlib> 
#include <ctime> 
#include <iomanip>
#include <cmath> 
#include <stdio.h>
using namespace std;

QMatrix operator- (QMatrix& x, QMatrix& y);
class QMatrix
{
private:
	int i, j;
	const int n = 5;
	const int m = 7;
	int** matrix;
	int m1[5][7]; int m2[7][5];
public:
	QMatrix() // конструктор (по умолчанию)
	{
		srand(time(NULL));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				m1[i][j] = ((rand() % 300) + 1);
			}

		};
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				m2[j][i] = ((rand() % 300) + 1);
			}
		}
	}
	void matr()
	{
		int **p;
		int i, j;
		p = new int *[n];
		std::cout << "Матрица 1"<<endl;
		for (i = 0; i < 5; i++)
		{
			p[i] = new int[m];
			for (j = 0; j < 7; j++)
			{
				p[i][j] = m1[i][j];
				std::cout << p[i][j] << "\t";
			}
			std::cout << endl;
		}
		std::cout << "Матрица 2 "<<endl;
		for (i = 0; i < 7; i++)
		{
			for (j = 0; j < 5; j++)
			{
				p[j][i] = m2[j][i];
				std::cout << p[j][i] << "\t";
			}
			std::cout << endl;
		}
	}
	~QMatrix()// деструктор ?
	{
	}

	void summ() // сумма матриц
	{
		int c[5][5];
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				int skalaar = 0;
				for (int k = 0; k < 7; k++)
				{
					skalaar += m1[i][k] + m2[k][j];
					c[i][j] = skalaar;
				}
				cout << c[i][j] << "\t";
			}
			cout << endl;
		}

	}
	friend QMatrix operator- (QMatrix& x, QMatrix& y);

	void umn() // умножение матриц
	{
		int c[5][5];
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				int skalaar = 0;
				for (int k = 0; k < 7; k++)
				{
					skalaar += m1[i][k] * m2[k][j];
					c[i][j] = skalaar;
				}
				cout << c[i][j] << "\t";
			}
			cout << endl;
		}
	}
	void index(int x, int y) 
	{
		cout<< m1[x - 1][y - 1];
	}

	};


	int _tmain(int argc, _TCHAR* argv[])
	{
		char Ch; // Переменная для ввода условия продолжения ввода
		setlocale(LC_ALL, "Russian");
		QMatrix objMessage;
		const int n = 5;
		const int m = 7;
		QMatrix();
		int a, x, y;
		do
		{
			cout << "1 Вывод матриц" << endl << "2 Умножение" << endl << "3 Сложение" << endl << "4 индексирование элмента" << endl << "Введите цифру:";
			cin >> a;
			if (a == 1)
			{
				objMessage.matr();
			}
			if (a == 2)
			{
				objMessage.umn();
			}
			if (a == 3)
			{
				objMessage.summ();
			}
			if (a == 4)
			{
				cout << "x =";
				cin >> x;
				cout << "y =";
				cin >> y;
				objMessage.index(x, y);
				cout << endl;
			}
			cout<< "Для продолжения нажмите Y или y: ";
			Ch = _getche(); // Чтение кода клавиши с печатью символа
			cout << endl;
		} while (Ch == 'Y' || Ch == 'y');
		system("pause");
		return 0;
	}
