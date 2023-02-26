#include <ctime>
#include <iostream>
#include <string>
#include <iomanip>
#include "sandbox.h"
#include <conio.h>
#include<string>
#include<Windows.h>
#include<vector>
using std::cout;
using std::cin;
using std::setprecision;
using std::fixed;
using std::string;
using std::vector;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	vector<structmatrix> matrixes;
	bool program = true;
	short key = 0;
	short index, index2;
	string name;
	while (program)
	{
		switch (key)
		{
		case 0:
		{
			menu(matrixes);
			
			key = must_inic(matrixes);
			break;
		}
		case 1:
		{
			cout << ". Инициализация \n";
			
			addstruct(matrixes);
			
			init_rand_matrix(matrixes, matrixes.size() - 1, 5);
			
			printm(matrixes, matrixes.size() - 1);

			key = 0;
			break;
		}
		case 2:
		{
			cout << ". Вывод \n";
			
			printnames(matrixes);
			
			index = mygetch("Выберите номер матрицы\nClick-->", 0, matrixes.size(), "\nНет выбранного пункта!Выберите еще раз!\nClick--> ") - 1;
			
			printm(matrixes, index);

			key = 0;
			break;
		}
		case 3:
		{
			cout << ". Транспонирование \n";
			
			printnames(matrixes);
			
			index = mygetch("Выберите номер матрицы\nClick-->", 0, matrixes.size(), "\nНет выбранного пункта!Выберите еще раз!\nClick--> ") - 1;
			
			addstruct(matrixes);
			
			matrixes[matrixes.size() - 1] = transponitionm(matrixes[index], matrixes[matrixes.size() - 1].name);
			
			printm(matrixes, matrixes.size() - 1);

			key = 0;
			break;
		}
		case 4:
		{
			cout << ". Отражение \n";

			printnames(matrixes);

			index = mygetch("Выберите номер матрицы\nClick-->", 0, matrixes.size(), "\nНет выбранного пункта!Выберите еще раз!\nClick--> ") - 1;

			addstruct(matrixes);
			
			matrixes[matrixes.size() - 1] = reflectionm(matrixes[index], matrixes[matrixes.size() - 1].name, true);
			
			printm(matrixes, matrixes.size() - 1);

			key = 0;
			break;
		}
		case 5:
		{
			cout << ". Прокрутка \n";
			try {
				printnames(matrixes);

				index = mygetch("\nВыберите номер матрицы\nClick-->", 0, matrixes.size(), "\nНет выбранного пункта!Выберите еще раз!\nClick--> ") - 1;

				addstruct(matrixes);

				matrixes[matrixes.size() - 1] = scrolling(matrixes[index], matrixes[matrixes.size() - 1].name);

				printm(matrixes, matrixes.size() - 1);
			}
			catch (const std::invalid_argument& ex) {
				cout << ex.what() << '\n';

				deleting(matrixes, matrixes.size() - 1, false);
			}
			key = 0;
			break;

		}
		case 6:
		{
			cout << ". Сложение \n";
			try {
				choicematrix(matrixes, index, index2);

				addstruct(matrixes);

				matrixes[matrixes.size() - 1] = additionm(matrixes[index], matrixes[index2], matrixes[matrixes.size() - 1].name);

				printm(matrixes, matrixes.size() - 1);
			}
			catch (const std::exception& ex) {
				cout << ex.what() << '\n';

				deleting(matrixes, index, false);
			}
			key = 0;
			break;
		}
		case 7:
		{
			cout << ". Умножение \n";
			try {
				choicematrix(matrixes, index, index2);

				addstruct(matrixes);

				matrixes[matrixes.size() - 1] = multiplicationm(matrixes[index], matrixes[index2], matrixes[matrixes.size() - 1].name);

				printm(matrixes, matrixes.size() - 1);
			}
			catch (const std::invalid_argument& ex) {
				cout << ex.what() << '\n';

				deleting(matrixes, matrixes.size() - 1, false);
			}
			key = 0;
			break;
		}
		case 8:
		{
			cout << ". Удаление \n";

			printnames(matrixes);

			index = mygetch("Выберите номер матрицы\nClick-->", 1, matrixes.size(), "\nНет выбранного пункта!Выберите еще раз!\nClick--> ") - 1;

			deleting(matrixes, index, true);

			key = 0;
			break;
		}
		case 9:
		{
			cout << "\nВыход ... \n";
			program = false;
			break;
		}
		}
	}
	cout << "\nРабота программы успешно завершена!\n\nСпасибо за работу!";

	_getch();
	return 0;
}

