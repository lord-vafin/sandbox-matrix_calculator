#pragma once
#include<string>
#include<vector>
using std::vector;
using std::string;
struct structmatrix
{
	string name;
	int rows;
	int cols;
	vector<vector<int>> matrix;
};
const short KEY_0 = 48,
KEY_1 = 49, KEY_2 = 50, KEY_3 = 51,
KEY_4 = 52, KEY_5 = 53, KEY_6 = 54,
KEY_7 = 55, KEY_8 = 56, KEY_9 = 57;

void addstruct(vector<structmatrix>& matrixes);
bool search_name(vector<structmatrix>& matrixes, const string& name);
void deleting(vector<structmatrix>& matrixes, short index, bool message);
void init_rand_matrix(vector<structmatrix>& matrixes, short index, short maxnumber);
void menu(vector<structmatrix> matrixes);
short must_inic(vector<structmatrix> matrixes);
short mygetch(const string& message, short key1, short key2, const string& defaultmessage);
void printm(vector<structmatrix>& matrixes, short index);
void printnames(vector<structmatrix> matrixes);
structmatrix additionm(structmatrix matrix1, structmatrix matrix2, string name);
structmatrix multiplicationm(structmatrix matrix1, structmatrix matrix2, string name);
structmatrix transponitionm(structmatrix structure, string name);
structmatrix reflectionm(structmatrix structure, string name, bool opinion);
structmatrix scrolling(structmatrix structure, string name);
void choicematrix(vector<structmatrix> matrixes, short& number1, short& number2);