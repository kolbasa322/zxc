#include "header.h"


void main()
{

	setlocale(LC_ALL, "Rus");


	int z, x;
	while (1)
	{

		system("CLS");
		cout << "����:\n";
		cout << "1 ���������� ��������\n2 ����� ��������\n3 �������������� �������� ��������\n";
		cout << "\n�������� ����� ����:\n\n";
		cin >> z;
		switch (z)
		{
		case 1:system("CLS");
			cout << "========================���������� ��������========================\n";
			cout << "1 ������ ���� ���������\n2 ��������� ��������� ���������� �������\n";
			cin >> x; switch (x){
			case 1:system("CLS"); scan_m();	_getch(); break;
			case 2: system("CLS"); gen_m(); _getch(); break;

			}; break;
		case 2: system("CLS"); print_m(); _getch(); break;
		case 3: system("CLS"); diff(); _getch(); break;

		}
	}



}