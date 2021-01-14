
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
#include <stdlib.h>
#include <queue>
#include <vector>
using namespace std;
int i, j, m;
bool* visited = new bool[m];
int** graph;
vector<int> dist;

void BFS(int st)
{
	queue<int> Queue = {}; // инициализация очереди
	Queue.push(st); // помещаем в очередь вершину
	dist[st] = 0;
	while (!Queue.empty()){
		// пока очередь не пустая 
		st = Queue.front(); // извлекаем вершину
		Queue.pop(); // извлекаем элемент из очереди
		printf("%d\t", st + 1);
		for (int i = 0; i < m; i++)
		{ // проверяем для нее все смежные вершины
			if ((graph[st][i] != 0) && (dist[i] == -1))
			{ // если вершина смежная и не обнаружена
				Queue.push(i); // добавляем ее в очередь
				dist[i] = dist[st] + 1; // отмечаем вершину как обнаруженную
			}
		}
		//printf("%d ", st + 1); // выводим номер вершины
	}
}
void main()
{
	setlocale(LC_ALL, "Rus");
	printf("Введите размер матрицы (x*x): ");
	scanf_s("%d", &m);
	printf("\n\n");
	////создание и генерация графа
	graph = new int*[m];
	for (int i = 0; i < m; i++) {
		graph[i] = new int[m];
	}

	srand(time(NULL));
	for (i = 0; i < m; ++i){
		for (j = i; j < m; ++j){
			/*	if ((i % 2>0) && (j % 2>0))
			{*/
			graph[i][j] = graph[j][i] = rand() % 2;
			/*}
			else
			{
			graph[i][j] = graph[j][i] = 0;
			}*/
		}
	}
	for (i = 0; i < m; ++i){
		for (j = i; j < m; ++j){
			if (j == i)
			{
				graph[j][i] = 0;

			}
		}
	}


	////////////////////////// ВЫВОД графа ////////
	printf("  \t");
	for (j = 0; j < m; j++)
	{
		printf("x%d\t", j + 1);
	}
	printf("\n\n");

	for (i = 0; i < m; ++i)
	{
		printf("x%d\t", i + 1);
		for (j = 0; j < m; ++j)
			printf("%d\t", graph[i][j]);
		printf("\n\n\n");
	}

	/////////////////// BFS
	int vershina;
	printf("\nВведите вершину с которой начать: ");
	scanf_s("%d", &vershina);
	while (vershina > m) {
		printf("\nТакой вершины не существует\n");
		printf("\nВведите вершину с которой начать: ");
		scanf_s("%d", &vershina);
	}
	for (i = 0; i < m; i++){
		dist.push_back(-1);
	}

	printf("Порядок обхода в ширину: ");

	BFS(vershina - 1);
	printf("\n\nРасстояние:\n");
	for (i = 0; i < m; i++){
		printf("x[%d", i + 1);
		printf("]: ");
		printf("%d\n", dist[i]);
	}

	_getch();
}