#include "Header.h"
bool third_m=false;



void scan_m()
{
	vector<int> vec_1;
	vector<int> vec_2;
	vector<int> vec_3;
	int num;
	int size_1 = 0;
	int size_2 = 0;
	int size_3 = 0;
	FILE *fin = fopen("F:\\Data\\data.txt", "w+");
	FILE *size_m_w = fopen("F:\\Data\\size.txt", "w+");
	/// множество 1

	cout << "Введите множество_1 (чтобы закончить введите 'q'):\n";
	bool same = false;

	cin >> num;
	size_1 += 1;
	vec_1.push_back(num);// добавляем в вектор первый элемент
	///////////////// ОЧИСТКА БУФЕРА ВВОДА

	cin.clear(); // на случай, если предыдущий ввод завершился с ошибкой
	cin.ignore(numeric_limits<streamsize>::max(), '\n');




	while (cin >> num){
		size_1 += 1;
		vec_1.push_back(num);
		for (int i = 0; i < (size_1 - 1); i++)
		{
			if (vec_1[i] == num)
			{

				same = true;
			}


		}
		if (same)
		{
			vec_1.pop_back();
			cout << "\nЭлемент удален, так как он уже присутствует в множестве\n";
			same = false;
			size_1 -= 1;
		}
	}


	///////////////// ОЧИСТКА БУФЕРА ВВОДА

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	////множество 2

	cout << "\n\nВведите множество_2 (чтобы закончить введите 'q'):\n";

	cin >> num;
	size_2 += 1;
	vec_2.push_back(num);



	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');



	while (cin >> num){
		size_2 += 1;
		vec_2.push_back(num);
		for (int i = 0; i < (size_2 - 1); i++)
		{
			if (vec_2[i] == num)
			{

				same = true;
			}


		}
		if (same)
		{
			vec_2.pop_back();
			cout << "\nЭлемент удален, так как он уже присутствует в множестве\n";
			same = false;
			size_2 -= 1;
		}
	}
	//// Узнаем у пользователя хочет ли он работать с 3-мя множествами
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Проводить оперцию с 3-мя множествами? (1- да/2 - нет)\n";
	int z;
	cin >> z;
	switch (z)
	{
	case 1:cout << "Выбрано 3 множества\n"; third_m = true;

		break;
	case 2: cout << "Выбрано 2 множества\n"; break;
	}

	if (third_m)
	{
		cout << "Введите множество_3 (чтобы закончить введите 'q'):\n";
		bool same = false;

		cin >> num;
		size_3 += 1;
		vec_3.push_back(num);// добавляем в вектор первый элемент
		///////////////// ОЧИСТКА БУФЕРА ВВОДА

		cin.clear(); // на случай, если предыдущий ввод завершился с ошибкой
		cin.ignore(numeric_limits<streamsize>::max(), '\n');




		while (cin >> num){
			size_3 += 1;
			vec_3.push_back(num);
			for (int i = 0; i < (size_3 - 1); i++)
			{
				if (vec_3[i] == num)
				{

					same = true;
				}


			}
			if (same)
			{
				vec_3.pop_back();
				cout << "\nЭлемент удален, так как он уже присутствует в множестве\n";
				same = false;
				size_3 -= 1;
			}
		}
	}










	///////////// запись размеров множеств в файл
	fprintf(fin, "%d\n", size_1);
	fprintf(fin, "%d\n", size_2);
	if (third_m)
	{
		fprintf(fin, "%d\n", size_3);
	}
	


	////////////// ВЫВОД МНОЖЕСТВ в файл

	for (int i = 0; i < size_1; i++)// 1-e множество
	{
		fprintf(fin, "%d\t", vec_1[i]);

	}
	fprintf(fin, "\n");

	for (int i = 0; i < size_2; i++)// 2-e множество
	{
		fprintf(fin, "%d\t", vec_2[i]);

	}
	if (third_m)
	{
		fprintf(fin, "\n");
		for (int i = 0; i < size_3; i++)// 3-e множество
		{
			fprintf(fin, "%d\t", vec_3[i]);

		}
	}
	
	fclose(fin);
	cout << "\nМножества успешно записаны!\nНажмите любую кнопку для возврата в меню.\n";
	//очистка буфера перед выходом в меню
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

}
int print_m()
{

	int size_1, size_2, size_3 = 0;
	vector<int> vec_1;
	vector<int> vec_2;
	vector<int> vec_3;
	int temp = 0;
	
	FILE *fin_r = fopen("F:\\Data\\data.txt", "r");
	
	



	if (!fin_r)
	{
		cout << "Ошибка! Множества пусты. Сгенерируйте или задайте множества вручную для начала работы" << endl;
		return 0;
	}
	
	fscanf(fin_r, "%d\n", &size_1);
	fscanf(fin_r, "%d\n", &size_2);
	if (third_m)
	{
		fscanf(fin_r, "%d\n", &size_3);
	}

	cout << "\nМножество_1: ";
	for (int i = 0; i < size_1; i++)
	{

		fscanf(fin_r, "%d\t", &temp);
		vec_1.push_back(temp);
		cout << vec_1[i] << " ";
	}

	cout << "\n\nМножество_2: ";
	for (int i = 0; i < size_2; i++)
	{

		fscanf(fin_r, "%d\t", &temp);
		vec_2.push_back(temp);
		cout << vec_2[i] << " ";
	}
	if (third_m)
	{
		cout << "\n\nМножество_3: ";
		for (int i = 0; i < size_3; i++)
		{

			fscanf(fin_r, "%d\t", &temp);
			vec_3.push_back(temp);
			cout << vec_3[i] << " ";
		}


		fclose(fin_r);

		return 0;

	}
}
void gen_m()

{
	vector<int> vec_1;
	vector<int> vec_2;
	vector<int> vec_3;
	bool same = false;
	int temp;
	int size_1;
	int size_2;
	int size_3;
	int size_temp;
	FILE *fin = fopen("F:\\Data\\data.txt", "w+");
	cout << "Введите размер 1-го множества:";
	cin >> size_1;
	cout << "\nВведите размер 2-го множества:";
	cin >> size_2;
	//// Узнаем у пользователя хочет ли он работать с 3-мя множествами
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Проводить оперцию с 3-мя множествами? (1- да/2 - нет)\n";
	int z;
	cin >> z;
	switch (z)
	{
	case 1:cout << "Выбрано 3 множества\n"; third_m = true; break;
	case 2: cout << "Выбрано 2 множества\n"; break;
	}

	if (third_m)
	{
		cout << "\nВведите размер 3-го множества:";
		cin >> size_3;
	}
	///////////// запись размеров множеств в файл
	fprintf(fin, "%d\n", size_1);
	fprintf(fin, "%d\n", size_2);
	if (third_m)
	{
		fprintf(fin, "%d\n", size_3);
	}
	/////////////

	srand(time(NULL));
	temp = rand() % 100;
	vec_1.push_back(temp);
	size_temp = 1;// размер для проверки ( уже есть 1 элемент ) 

	/// генерация первого множества
	while (size_1 != size_temp)
	{

		temp = rand() % size_1;
		vec_1.push_back(temp);
		size_temp += 1;
		for (int i = 0; i < size_temp - 1; i++)
		{
			if (vec_1[i] == temp)
			{

				same = true;
			}


		}
		if (same)
		{
			vec_1.pop_back();
			same = false;
			size_temp -= 1;
		}
	}
	// генерация 2-го множества



	temp = rand() % 100;
	vec_2.push_back(temp);
	size_temp = 1;// размер для проверки ( уже есть 1 элемент ) 


	while (size_2 != size_temp)
	{

		temp = rand() % size_2;
		vec_2.push_back(temp);
		size_temp += 1;
		for (int i = 0; i < size_temp - 1; i++)
		{
			if (vec_2[i] == temp)
			{

				same = true;
			}


		}
		if (same)
		{
			vec_2.pop_back();
			same = false;
			size_temp -= 1;
		}
	}
	if (third_m)
	{
		// генерация 3-го множества



		temp = rand() % 100;
		vec_3.push_back(temp);
		size_temp = 1;// размер для проверки ( уже есть 1 элемент ) 


		while (size_3 != size_temp)
		{

			temp = rand() % size_3;
			vec_3.push_back(temp);
			size_temp += 1;
			for (int i = 0; i < size_temp - 1; i++)
			{
				if (vec_3[i] == temp)
				{

					same = true;
				}


			}
			if (same)
			{
				vec_3.pop_back();
				same = false;
				size_temp -= 1;
			}
		}
	}
	/////// запись множеств в файл
	cout << "\nМножества успешно сгенерированы!\n";
	cout << "\nСгенерированное множество_1: ";
	for (int i = 0; i < size_1; i++)// 1-e
	{
		fprintf(fin, "%d\t", vec_1[i]);
		cout << vec_1[i] << " ";
	}
	fprintf(fin, "\n");
	cout << "\nСгенерированное множество_2: ";
	for (int i = 0; i < size_2; i++)// 2-e
	{
		fprintf(fin, "%d\t", vec_2[i]);
		cout << vec_2[i] << " ";
	}
	if (third_m)
	{
		fprintf(fin, "\n");
		cout << "\nСгенерированное множество_2: ";
		for (int i = 0; i < size_3; i++)// 2-e
		{
			fprintf(fin, "%d\t", vec_3[i]);
			cout << vec_3[i] << " ";
		}
	}
	fclose(fin);
	cout << "\n\nНажмите любую клавишу для выхода в меню\n";






}
void diff()
{
	int size_1, size_2,size_3 = 0;
	vector<int> vec_1;
	vector<int> vec_2;
	vector<int> vec_3;
	vector<int> vec_diff;
	vector<int> vec_diff2;
	int temp = 0;
	FILE *fin_r = fopen("F:\\Data\\data.txt", "r");
	FILE *fin = fopen("F:\\Data\\results.txt", "w+");

	fscanf(fin_r, "%d\n", &size_1);
	fscanf(fin_r, "%d\n", &size_2);
	if (third_m)
	{
		fscanf(fin_r, "%d\n", &size_3);
	}
	////////
	cout << "\nМножество_1: ";
	for (int i = 0; i < size_1; i++)
	{

		fscanf(fin_r, "%d\t", &temp);
		vec_1.push_back(temp);
		cout << vec_1[i] << " ";
	}
	cout << "\nМножество_2: ";
	for (int i = 0; i < size_2; i++)
	{

		fscanf(fin_r, "%d\t", &temp);
		vec_2.push_back(temp);
		cout << vec_2[i] << " ";
	}
	if (third_m)
	{
		cout << "\nМножество_3: ";
		for (int i = 0; i < size_3; i++)
		{

			fscanf(fin_r, "%d\t", &temp);
			vec_3.push_back(temp);
			cout << vec_3[i] << " ";
		}
	}
	fclose(fin_r);
	bool same = false;
	////////
	for (int i = 0; i < size_1; i++)
	{

		for (int j = 0; j < size_2; j++)
		{
			if (vec_1[i] == vec_2[j])
			{
				same = true;
				break;
			}

		}

		if (!same)
		{
			vec_diff.push_back(vec_1[i]);
		}
		else
		{
			same = false;
		}

	}
	///////
	for (int i = 0; i < size_2; i++)
	{

		for (int j = 0; j < size_1; j++)
		{
			if (vec_2[i] == vec_1[j])
			{
				same = true;
				break;
			}

		}

		if (!same)
		{
			vec_diff.push_back(vec_2[i]);
		}
		else
		{
			same = false;
		}

	}

	if (third_m)
	{
		bool same = false;
		for (int i = 0; i < vec_diff.size(); i++)
		{

			for (int j = 0; j < size_3; j++)
			{
				if (vec_diff[i] == vec_3[j])
				{
					same = true;
					break;
				}

			}

			if (!same)
			{
				vec_diff2.push_back(vec_diff[i]);
			}
			else
			{
				same = false;
			}

		}
		/////
		for (int i = 0; i < vec_3.size(); i++)
		{

			for (int j = 0; j < vec_diff.size(); j++)
			{
				if (vec_3[i] == vec_diff[j])
				{
					same = true;
					break;
				}

			}

			if (!same)
			{
				vec_diff2.push_back(vec_3[i]);
			}
			else
			{
				same = false;
			}

		}
	}

	if (third_m)
	{
		cout << "\n\nСимметрическая разность множеств: ";
		for (int i = 0; i < vec_diff2.size(); i++)
		{
			cout << vec_diff2[i] << " ";
			fprintf(fin, "%d\t", vec_diff2[i]);
		}
	}
	else
	{


		cout << "\n\nСимметрическая разность множеств: ";
		for (int i = 0; i < vec_diff.size(); i++)
		{
			cout << vec_diff[i] << " ";
			fprintf(fin, "%d\t", vec_diff[i]);
		}
	}
	fclose(fin);


}



