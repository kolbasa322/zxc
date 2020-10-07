#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	int i = 0, j = 0, r;
	const int n = 200;
	int a[n][n], b[n][n], c[n][n], elem_c;
	clock_t start = clock();
	srand(time(NULL)); // генератор случайных от времени
	while (i<n)
	{
		while (j<n)
		{
			a[i][j] = rand() % 100 + 1; // присваивание случ. знач.
			j++;
		}
		i++;
	}
	srand(time(NULL)); // генератор случайных от времени
	i = 0; j = 0;
	while (i<n)
	{
		while (j<n)
		{
			b[i][j] = rand() % 100 + 1; // присваивание случ. знач.
			j++;
		}
		i++;
	}

	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
		{
			elem_c = 0;
			for (r = 0; r<n; r++)
			{
				elem_c = elem_c + a[i][r] * b[r][j];
				c[i][j] = elem_c;
			}
		}
	}

	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("The time: %f seconds\n", seconds);
	system("pause");


	return(0);
}