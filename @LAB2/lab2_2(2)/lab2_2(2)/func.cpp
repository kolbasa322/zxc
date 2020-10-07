#include "header.h"
#include <iostream>
void ex4_s(){
	// СОЗДАНИЕ И ЗАПОЛНЕНИЕ МАССИВА
	int i = 0, j = 0, r, n = 1, x = z;
	int a[z][z];
	for (int i = 0; i<x / 2; i++)
	for (int j = 0; j<x; j++)
	{
		a[i][j] = n;
		a[x / 2 + i][j] = 4999 - n;
		n++;
	}
	if (x % 2) // n - нечетное, осталась одна незаполненная строка в конце
	for (int j = 0; j < x; j++)
	{

		a[x - 1][j] = 4999 - n;
		n++;
	}
	int *f = &a[0][0];

	// ВЫПОЛНЕНИЕ АЛГОРИТМА
	printf("1- shell, 2 - qs,3 - qs (VS)\n");
	int symbol = 0;
	scanf_s("%d", &symbol);

	if (symbol == 1)
	{
		clock_t start = clock();
		shell(f, z*z);
		clock_t end = clock();
		double seconds = (double)(end - start) / CLOCKS_PER_SEC;
		printf("The time: %f seconds\n", seconds);

		system("pause");
	}
	if (symbol == 2)
	{
		clock_t start = clock();
		qs(f, 0, (z*z) - 1);
		clock_t end = clock();
		double seconds = (double)(end - start) / CLOCKS_PER_SEC;
		printf("The time: %f seconds\n", seconds);

		system("pause");
	}
	if (symbol == 3)
	{
		clock_t start = clock();
		qsort(f, z*z, sizeof(int), compare);
		clock_t end = clock();

		double seconds = (double)(end - start) / CLOCKS_PER_SEC;
		printf("The time: %f seconds\n", seconds);

		system("pause");
	}

}
void ex3_s(){
	// СОЗДАНИЕ И ЗАПОЛНЕНИЕ МАССИВА
	int i = 0, j = 0, r, n = 1;
	int a[z][z];
	srand(time(NULL));
	while (i < z)
	{
		while (j < z)
		{
			a[i][j] = (z*z) - n; // заполнение псевдослучайными
			j++;
			n++;
		}
		j = 0;
		i++;
	}
	int *f = &a[0][0];

	// ВЫПОЛНЕНИЕ АЛГОРИТМА
	printf("1- shell, 2 - qs,3 - qs (VS)\n");
	int symbol = 0;
	scanf_s("%d", &symbol);

	if (symbol == 1)
	{
		clock_t start = clock();
		shell(f, z*z);
		clock_t end = clock();
		double seconds = (double)(end - start) / CLOCKS_PER_SEC;
		printf("The time: %f seconds\n", seconds);

		system("pause");
	}
	if (symbol == 2)
	{
		clock_t start = clock();
		qs(f, 0, (z*z) - 1);
		clock_t end = clock();
		double seconds = (double)(end - start) / CLOCKS_PER_SEC;
		printf("The time: %f seconds\n", seconds);

		system("pause");
	}
	if (symbol == 3)
	{
		clock_t start = clock();
		qsort(f, z*z, sizeof(int), compare);
		clock_t end = clock();

		double seconds = (double)(end - start) / CLOCKS_PER_SEC;
		printf("The time: %f seconds\n", seconds);

		system("pause");
	}


}
void ex2_s()
{
	int i = 0, j = 0, r, n = 0;;
	int a[z][z];
	srand(time(NULL));
	while (i < z)
	{
		while (j < z)
		{
			a[i][j] = n; // заполнение возрастающими
			j++;
			n++;
		}
		j = 0;
		i++;
	}
	int *f = &a[0][0];
	printf("1- shell, 2 - qs,3 - qs (VS)\n");
	int symbol = 0;
	scanf_s("%d", &symbol);

	if (symbol == 1)
	{
		clock_t start = clock();
		shell(f, z*z);
		clock_t end = clock();
		double seconds = (double)(end - start) / CLOCKS_PER_SEC;
		printf("The time: %f seconds\n", seconds);

		system("pause");
	}
	if (symbol == 2)
	{
		clock_t start = clock();
		qs(f, 0, (z*z) - 1);
		clock_t end = clock();
		double seconds = (double)(end - start) / CLOCKS_PER_SEC;
		printf("The time: %f seconds\n", seconds);

		system("pause");
	}
	if (symbol == 3)
	{
		clock_t start = clock();
		qsort(f, z*z, sizeof(int), compare);
		clock_t end = clock();

		double seconds = (double)(end - start) / CLOCKS_PER_SEC;
		printf("The time: %f seconds\n", seconds);

		system("pause");
	}


}
void ex1_s(){
	// СОЗДАНИЕ И ЗАПОЛНЕНИЕ МАССИВА
	int i = 0, j = 0, r, n = 15;
	int a[z][z];
	srand(time(NULL));
	while (i < z)
	{
		while (j < z)
		{
			a[i][j] = rand() % 100; // заполнение псевдослучайными
			j++;
		}
		j = 0;
		i++;
	}
	int *f = &a[0][0];

	// ВЫПОЛНЕНИЕ АЛГОРИТМА + VREMYA
	printf("1- shell, 2 - qs,3 - qs (VS)\n");
	int symbol = 0;
	scanf_s("%d", &symbol);

	if (symbol == 1)
	{
		clock_t start = clock();
		shell(f, z*z);
		clock_t end = clock();
		double seconds = (double)(end - start) / CLOCKS_PER_SEC;
		printf("The time: %f seconds\n", seconds);

		system("pause");
	}
	if (symbol == 2)
	{	
		clock_t start = clock();
		qs(f, 0, (z*z) - 1);
		clock_t end = clock();
		double seconds = (double)(end - start) / CLOCKS_PER_SEC;
		printf("The time: %f seconds\n", seconds);

		system("pause");
	}
	if (symbol == 3)
	{
		clock_t start = clock();
		qsort(f, z*z, sizeof(int), compare);
		clock_t end = clock();

		double seconds = (double)(end - start) / CLOCKS_PER_SEC;
		printf("The time: %f seconds\n", seconds);

		system("pause");
	}
	
	
	



}


void qs(int *items, int left, int right) //qs(items, 0, count - 1)
{
	int i, j;
	int x, y;



	i = left; j = right;

	/* выбор компаранда */
	x = items[(left + right) / 2];

	do {
		while ((items[i] < x) && (i < right)) i++;
		while ((x < items[j]) && (j > left)) j--;

		if (i <= j) {
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++; j--;
		}
	} while (i <= j);

	if (left < j) qs(items, left, j);
	if (i < right) qs(items, i, right);
}
void menu()
{
	system("CLS");
	printf("---------------------------------\n");
	printf("1 - SLUCHAINIE-------------------\n");
	printf("2 - VOZR-------------------------\n");
	printf("3 - UBIV-------------------------\n");
	printf("4 - VOZR/UBIV--------------------\n");
	printf("---------------------------------\n");
}
void menu_input(char i)
{
	if (i == '1'){ ex1_s(); }
	if (i == '2'){ ex2_s(); }
	if (i == '3'){ ex3_s(); }
	if (i == '4'){ ex4_s(); }
}
void shell(int *items, int count)
{

	int i, j, gap, k;
	int x, a[5];

	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i < count; ++i) {
			x = items[i];
			for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
				items[j + gap] = items[j];
			items[j + gap] = x;
		}
	}
}

int compare(const void * x1, const void * x2)   // функция сравнения элементов массива
{
	return (*(int*)x1 - *(int*)x2);              // если результат вычитания равен 0, то числа равны, < 0: x1 < x2; > 0: x1 > x2
}
