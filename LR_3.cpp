//Лабраторная работа № 3.
//Вариант 10. Реализовать класс String для работы со строками символов. Перегрузить оператор "-"(минус) так, чтобы определить, насколько одна 
//строка дленнее другой. Предоставить конструктор копирования.

// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include <string.h>
using namespace std;

class String
{
public: 
	char* s;
	int dlina;
	String();
	String(const char* str);
	String(const String& other);
	friend int operator - (const String& other, const String& second); //перегрузка оператора
	~String();
};

String::String()
{
	s = NULL;
	dlina = 0;
}

//конструктор инициализации строки со значением
String::String(const char* str)
{
	dlina = strlen(str) + 1;
	s = new char[dlina];
	strcpy_s(s, dlina, str);
	cout << "Работает конструктор" << endl;
}

// копирующий конструктор
String::String(const String& other)
{
	dlina = other.dlina;
	s = new char[dlina];
	strcpy_s(s, dlina, other.s); 
}

String::~String()
{
	delete[] s;
	cout << "Работает деструктор" << endl;
}

int operator -(const String& first, const String& second)
{
	int r;
	return r = abs(first.dlina - second.dlina);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	String stroka1("aaa");
	String stroka2("bbbbbb");
	int n = stroka1 - stroka2;
	if (stroka1.dlina > stroka2.dlina)
		cout << "Первая строка больше второй на: " << n << endl;
	else
		cout << "Вторая строка больше первой на: " << n << endl;
}