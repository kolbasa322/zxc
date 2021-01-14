#include "header.h"


void main()
{

	setlocale(LC_ALL, "Rus");


	int z, x;
	while (1)
	{

		system("CLS");
		cout << "Меню:\n";
		cout << "1 Заполнение множеств\n2 Вывод множеств\n3 Симметрическая разность множеств\n";
		cout << "\nВыберите пункт меню:\n\n";
		cin >> z;
		switch (z)
		{
		case 1:system("CLS");
			cout << "========================Заполнение множеств========================\n";
			cout << "1 Ручной ввод элементов\n2 Заполнить множества случайными числами\n";
			cin >> x; switch (x){
			case 1:system("CLS"); scan_m();	_getch(); break;
			case 2: system("CLS"); gen_m(); _getch(); break;

			}; break;
		case 2: system("CLS"); print_m(); _getch(); break;
		case 3: system("CLS"); diff(); _getch(); break;

		}
	}



}