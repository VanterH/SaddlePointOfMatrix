#include<iostream>
#include<ctime>
using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int arr[3][4], arr_y[3], arr_x[4], x = 0, max_x = -1, min_y = 101010;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			arr[i][j] = rand()%100;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		int b = -1;

		for (int j = 0; j < 4; j++)
		{
			if (arr[i][j] > b)
			{
				b = arr[i][j];
			}
			if (j == 3)
			{
				arr_y[i] = b;
			}
		}
	}

	for (int j = 0; j < 4; j++)
	{
		int b = 1000;

		for (int i = 0; i < 3; i++)
		{
			if (arr[i][j] < b)
			{
				b = arr[i][j];
			}
			if (i == 2)
			{
				arr_x[j] = b;
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << "max:" << arr_y[i] << "\n";
	}

	for (int i = 0; i < 4; i++)
	{
		cout << "min:" << arr_x[i] << "\t";
	}

	cout << "\n";

	for (int i = 0; i < 3; i++)
	{
		if (arr_y[i] < min_y)
		{
			min_y = arr_y[i];
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (arr_x[i] > max_x)
		{
			max_x = arr_x[i];
		}
	}

	cout << min_y << "\n" << max_x << "\n";

	if (min_y == max_x)
	{
		cout << "В матрице А есть седловая точка";
	}

	return 0;
}