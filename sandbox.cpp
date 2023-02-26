#include"sandbox.h"
#include<iostream>
#include<vector>
#include <ctime>
#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>
using std::vector;
using std::cin;
using std::cout;
using std::setprecision;
using std::fixed;
using std::string;
#define CTRL(x) (#x[0] - 'a' + 1)
#define myfor(i,n) for(int i=0; i<n; i++)
//добавление структуры в общий вектор matrixes
void addstruct(vector<structmatrix>& matrixes)
{
	structmatrix new_structure;

	cout << "\nВведите имя матрицы\n->";
	do
	{
		bool f = true;
		cin >> new_structure.name;
		if (!search_name(matrixes, new_structure.name))
		{
			cout << "Такое имя уже используется! Введите другое имя!\n-> ";
		}
		else
		{
			break;
		}
	} while (true);

	matrixes.push_back(new_structure);
}

//поиск имени структуры
bool search_name(vector<structmatrix>& matrixes, const string& name)
{
	bool f = true;
	for (const structmatrix& structure : matrixes)
	{
		if (structure.name == name)
			f = false;
	}
	return f;
}

//удаление структуры из вектора matrixes
void deleting(vector<structmatrix>& matrixes, short index, bool message)
{
	string name = matrixes[index].name;

	matrixes.erase(matrixes.begin() + index);

	if (message)
		cout << "\n\nМатрица " << name << " успешно удалена!\n";
}

//инициализация структуры рандомными числами от 1 до maxnumber
void init_rand_matrix(vector<structmatrix>& matrixes, short index, short maxnumber)
{
	matrixes[index].rows = mygetch("Введите количество строк, а затем количество столбцов матрицы:\nClick--> ", 1, 9, "\nНажмите клавишу с корректным значением!\nClick-->");

	matrixes[index].cols = mygetch("\nClick--> ", 1, 9, "\nНажмите клавишу с корректным значением!\nClick-->");
	
	matrixes[index].matrix = {};
	
	srand(time(0));
	
	vector<vector<int>>list(matrixes[index].rows, vector<int>(matrixes[index].cols, 0));
	
	myfor(i,matrixes[index].rows)
		myfor(j, matrixes[index].cols)
		list[i][j] = rand() % maxnumber + 1;
		
	
	matrixes[index].matrix = list;
}

//вывод меню на экран
void menu(vector<structmatrix> matrixes)
{
	string message = " [blocked]";
	
	string must_be_1_matrix, must_be_2_matrix;
	
	if (matrixes.size() == 0) must_be_1_matrix = message;
	
	if (matrixes.size() < 2) must_be_2_matrix = message;
	
	cout << "\n\t\t\t\t\t\tМЕНЮ\n \t\t\t\t\t1.Инициализация"
		<< "\n \t\t\t\t\t2.Вывод " << must_be_1_matrix
		<< "\n \t\t\t\t\t3.Транспонирование " << must_be_1_matrix
		<< "\n \t\t\t\t\t4.Отражение " << must_be_1_matrix
		<< "\n \t\t\t\t\t5.Прокрутка " << must_be_1_matrix
		<< "\n \t\t\t\t\t6.Сложение " << must_be_2_matrix
		<< "\n \t\t\t\t\t7.Умножение" << must_be_2_matrix
		<< "\n \t\t\t\t\t8.Удаление " << must_be_1_matrix
		<< "\n \t\t\t\t\t9.Выход ";
}

//обязательная инициализация матриц в зависимости от пунктов использования
short must_inic(vector<structmatrix> matrixes)
{
	short key = mygetch("\n\n\t\t\t\t     ->->-> Нажмите КНОПКУ <-<-<-\n", 1, 9, "\nНе соответствует пункта меню! Нажмите еще раз!\n-->");
	
	if (matrixes.size() == 0)
	{
		if (key == 2 || key == 3 || key == 4 || key == 5 || key == 8)
		{
			while (key != 1 && key != 9)
			{
				key = mygetch("\nНет инициализированных матриц! Выберите пункт 1, чтобы инициализировать или 9, чтобы выйти!\n-> ", 1, 9, "\nНе соответствует пункта меню! Нажмите еще раз!\n-->");
			}
		}
		return key;
	}
	else if (matrixes.size() == 1)
	{
		if (key == 6 || key == 7)
		{
			while (key == 6 || key == 7)
			{
				key = mygetch("\nСлишком мало инициализированных матриц! Нужно минимум 2 инициализированные матрицы! Выберите другой доступный пункт!\n-> ", 1, 9, "\nНе соответствует пункта меню! Нажмите еще раз!\n-->");
			}
		}
	}
	return key;
}

//сканирование нажатий
short mygetch(const string& message, short key1, short key2, const string& defaultmessage)
{
	cout << message;
metka1:
	
	short x = _getch();
	
	switch (x)
	{
	case KEY_1:
	{
		cout << 1;
		x = 1;
		break;
	}
	case KEY_2:
	{
		cout << 2;
		x = 2;
		break;
	}
	case KEY_3:
	{
		cout << 3;
		x = 3;
		break;
	}
	case KEY_4:
	{
		cout << 4;
		x = 4;
		break;
	}
	case KEY_5:
	{
		cout << 5;
		x = 5;
		break;
	}
	case KEY_6:
	{
		cout << 6;
		x = 6;
		break;
	}
	case KEY_7:
	{
		cout << 7;
		x = 7;
		break;
	}
	case KEY_8:
	{
		cout << 8;
		x = 8;
		break;
	}
	case KEY_9:
	{
		cout << 9;
		x = 9;
		break;
	}
	case CTRL(c):
	{
		exit(0);
		break;
	}
	case 0:
	case 224:
	{
		_getch();
	}
	default:
	{
		cout << defaultmessage;
		goto metka1;
	}
	}
	if (!(key1 <= x && x <= key2))
	{
		cout << defaultmessage;
		goto metka1;
	}
	return x;
}

//печать матрицы с по индексу из общего списка структур
void printm(vector<structmatrix>& matrixes, short index)
{
	cout << '\n' << matrixes[index].name << "  " << matrixes[index].rows << '*' << matrixes[index].cols << '\n';
	
	myfor(i, matrixes[index].rows)
	{
		myfor(j, matrixes[index].cols)
			cout << matrixes[index].matrix[i][j] << ' ';
		cout << '\n';
	}
}


//вывод списка имен всех матриц
void printnames(vector<structmatrix> matrixes)
{
	short x = 1;
	
	for (const structmatrix& structure : matrixes)
	{
		cout << x << ". " << structure.name << "  [ " << structure.rows << '*' << structure.cols << " ]\n";
		x++;
	}
}

//сложение матриц
structmatrix additionm(structmatrix matrix1, structmatrix matrix2, string name)
{
	if (!((matrix1.rows == matrix2.rows) && (matrix1.cols == matrix2.cols)))
	{
		throw std::invalid_argument("\n#ОШИБКА: СЛОЖЕНИЕ НЕВОЗМОЖНО! РАЗМЕРЫ ЭТИХ МАТРИЦ НЕ ОДИНАКОВЫ!\n\n");
	}
	structmatrix addition_matrix;
	vector<vector<int>>list(matrix1.rows, vector<int>(matrix1.cols, 0));
	myfor(i, matrix1.rows)
	{
		myfor(j, matrix1.cols)
		{
			list[i][j] = matrix1.matrix[i][j] + matrix1.matrix[i][j];
		}
	}
	addition_matrix.rows = matrix1.rows;
	addition_matrix.cols = matrix1.cols;
	addition_matrix.matrix = list;
	addition_matrix.name = name;
	return addition_matrix;
}

//умножение матриц
structmatrix multiplicationm(structmatrix matrix1, structmatrix matrix2, string name)
{
	if (matrix1.cols != matrix2.rows)
		throw std::invalid_argument("\n#ОШИБКА: УМНОЖЕНИЕ НЕВОЗМОЖНО! КОЛИЧЕСТВО СТОЛБЦОВ ПЕРВОЙ МАТРИЦЫ НЕ РАВНО КОЛИЧЕСТВУ СТРОК ВТОРОЙ МАТРИЦЫ!\n\n");
	structmatrix multimatrix;
	vector<vector<int>>list(matrix1.rows, vector<int>(matrix1.cols, 0));
	myfor(i, matrix1.rows)
	{
		myfor(j, matrix2.cols)
		{
			myfor(x, matrix1.cols)
			{
				list[i][j] += (matrix1.matrix[i][x] * matrix2.matrix[x][j]);
			}
		}
	}
	multimatrix.rows = matrix1.rows;
	multimatrix.cols = matrix2.cols;
	multimatrix.matrix = list;
	multimatrix.name = name;
	return multimatrix;
}

//транспонирование матриц
structmatrix transponitionm(structmatrix structure, string name)
{
	vector<vector<int>>list(structure.cols, vector<int>(structure.rows, 0));
	myfor(i, structure.cols)
	{
		myfor(j, structure.rows)
		{
			list[i][j] = structure.matrix[j][i];
		}
	}
	structmatrix transpon_matrix;
	transpon_matrix.matrix = list;
	transpon_matrix.rows = structure.cols;
	transpon_matrix.cols = structure.rows;
	transpon_matrix.name = name;
	return transpon_matrix;
}

//отражение матриц с выбором: по горизонтали или по вертикали
structmatrix reflectionm(structmatrix structure, string name, bool opinion)
{
	vector<vector<int>>list(structure.rows, vector<int>(structure.cols, 0));
	short f = 0;
	if (opinion)
		f = mygetch("По вертикали = 1(относительно ОХ) или по горизонтали = 2(относительно ОУ) ?\n->", 1, 2, "\nВведите только 1 или 2!\nClick--> ");
	else
		f = 2;
	if (f == 1)
	{
		myfor(i, structure.rows)
		{
			myfor(j, structure.cols)
			{
				list[i][j] = structure.matrix[structure.rows - i - 1][j];
			}
		}
	}
	if (f == 2)
	{
		myfor(i, structure.rows)
		{
			myfor(j, structure.cols)
			{
				list[i][j] = structure.matrix[i][structure.cols - j - 1];
			}
		}
	}
	structmatrix refliction_matrix;
	refliction_matrix.name = name;
	refliction_matrix.rows = structure.rows;
	refliction_matrix.cols = structure.cols;
	refliction_matrix.matrix = list;
	return refliction_matrix;
}

//прокрутка матриц с выбором: по часовой стрелке или против
structmatrix scrolling(structmatrix structure, string name)
{
	if (structure.rows != structure.cols)
		throw std::invalid_argument("\n#ОШИБКА: ПРОКРУТКА НЕВОЗМОЖНА! МАТРИЦА НЕ КВАДРАТНАЯ!\n\n");
	structmatrix scrolled_matrix;
	short key = mygetch("\nПо часовой стрелке - 1 или против - 2?\nClick--> ", 1, 2, "\nНажмите только 1 или 2\nClick--> ");
	if (key == 1)
	{
		scrolled_matrix = transponitionm(structure, name);
		scrolled_matrix = reflectionm(scrolled_matrix, name, false);
	}
	else
	{
		scrolled_matrix = reflectionm(structure, name, false);
		scrolled_matrix = transponitionm(scrolled_matrix, name);
	}

	return scrolled_matrix;

}

//выбор двух матриц для фукнции умножения и сложения
void choicematrix(vector<structmatrix> matrixes, short& number1, short& number2)
{
	printnames(matrixes);
	number1 = mygetch("\nВыберите первую матрицу\nClick--> ", 0, matrixes.size(), "\nНет выбранного пункта!Выберите еще раз\nClick--> ") - 1;
	number2 = mygetch("\nВыберите вторую матрицу\nClick--> ", 0, matrixes.size(), "\nНет выбранного пункта!Выберите еще раз\nClick--> ") - 1;
}