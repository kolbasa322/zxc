#include "header.h"


int main() {
	setlocale(LC_ALL, "Rus");
	system("CLS");
	while (1)
	{
		menu();
		menu_input(_getch());
	}

}