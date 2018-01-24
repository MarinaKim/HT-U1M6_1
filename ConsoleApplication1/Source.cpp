#include<stdio.h>
#include<locale.h>
#include<iostream>
#include<stdint.h>
#include<time.h>

void ShiftRight3(int a, int b, int c);
void ShiftLeft3(int a, int b, int c);
int isLeap(int year);
int MonthDays(int month, int year);
void PrevDate(int day, int month, int year);


using namespace std;

void main()
{
	int n;
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	do
	{
		cout << "введите номер задания:";
		cin >> n;

		switch (n) {

			//1.	Описать процедуру ShiftRight3(A, B, C), выполняющую правый циклический сдвиг: значение A переходит в B, 
			//значение B — в C, значение C — в A (A, B, C — вещественные параметры, являющиеся одновременно входными и выходными). 
			//С помощью этой процедуры выполнить правый циклический сдвиг для двух данных наборов из трех чисел: (A1, B1, C1) и (A2, B2, C2).

		case 1: {
			int a, b, c;
			cout << "Введите a: ";
			cin >> a;
			cout << "Введите b: ";
			cin >> b;
			cout << "Введите c: ";
			cin >> c;

			ShiftRight3(a, b, c);
		} break;

			//2.	Описать процедуру ShiftLeft3(A, B, C), выполняющую левый циклический сдвиг: значение A переходит в C, 
			//значение C — в B, значение B — в A (A, B, C — вещественные параметры, являющиеся одновременно входными и выходными).
			//С помощью этой процедуры выполнить левый циклический сдвиг для двух данных наборов из трех чисел: (A1, B1, C1) и (A2, B2, C2).
		case 2: {
			int a, b, c;
			cout << "Введите a: ";
			cin >> a;
			cout << "Введите b: ";
			cin >> b;
			cout << "Введите c: ";
			cin >> c;

			ShiftLeft3(a, b, c);
		} break;

			//3.	Описать функцию IsLeapYear(Y) логического типа, которая возвращает True, если год Y (целое положительное число)
			//является високосным, и False в противном случае. Вывести значение функции IsLeapYear для пяти данных значений параметра Y. 
			//Високосным считается год, делящийся на 4, за исключением тех годов, которые делятся на 100 и не делятся на 400.
		case 3: {
			int year;
			cout << "Введите год: ";
			cin >> year;
		int	l = isLeap(year);
		if (l == 1)
			cout << "true" << endl;
		else
			cout << "False" <<endl;

		} break;

			//4.	Используя функцию IsLeapYear из задания 3, описать функцию MonthDays(M, Y) целого типа, которая возвращает 
			//количество дней для M-го месяца года Y (1 ≤ M ≤ 12, Y > 0 — целые числа). Вывести значение функции MonthDays 
			//для данного года Y и месяцев M1, M2, M3.
		case 4: {
			int month,year;
			cout << "Введите год: ";
			cin >> year;
			cout << "Введите номер месяца (1-12): ";
			cin >> month;
			cout << "кол-во дней: " << MonthDays(month, year) << endl;
		} break;

			//5.	Используя функцию MonthDays из задания 4, описать процедуру PrevDate(D, M, Y), которая по информации о правильной дате,
			//включаю- щей день D, номер месяца M и год Y, определяет предыдущую дату (пара- метры целого типа D, M, Y являются одновременно входными и выходными). 
			//Применить процедуру PrevDate к трем исходным датам и вывести полученные значения предыдущих дат
		case 5: {
			int month, year,day;
			cout << "Введите год: ";
			cin >> year;
			cout << "Введите месяц: ";
			cin >> month;
			cout << "Введите день: ";
			cin >> day;

			PrevDate(day,month,year);

		}break;
		}
	} while (n > 0);
}
//1.	Описать процедуру ShiftRight3(A, B, C), выполняющую правый циклический сдвиг: значение A переходит в B,
//значение B — в C, значение C — в A (A, B, C — вещественные параметры, являющиеся одновременно входными и выходными).
//С помощью этой процедуры выполнить правый циклический сдвиг для двух данных наборов из трех чисел: (A1, B1, C1) и (A2, B2, C2).

void ShiftRight3(int a, int b, int c)
{
	int l = c;
	c = b;
	b = a;
		a = l;
		cout << a << "\t" << b << "\t" << c << endl;
}

void ShiftLeft3(int a, int b, int c)
{
	int l = a;
	a = b;
	b = c;
	c = l;
	cout << a << "\t" << b << "\t" << c << endl;
}
//Функция, определяющая високосный день или нет
int isLeap(int year)
{
	int isLeap = 0;
	if ((year % 4 == 0 && year % 100) || (year % 400 == 0))
		return 1;
	else
		return 0;
}

//4
int MonthDays(int month, int year)
{
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	else if (month == 2)
	{
		if (isLeap(year) == 1) 
			return 29;
		else
			return 28;
	}
	else
		return 31;
}

//5
void PrevDate(int day, int month, int year)
{
	int leap = isLeap(year);
	//дату предыдущего дня;
	if ((day < 1 && day>31) && (month<1 || month>12))
	{
		cout << "Введите правильную дату." << endl;
	}

	if (day == 1)
	{
		if (day == 1 && month == 1)
			year = year - 1;
		if (month == 1)
			month = 12;
		else
			month = month - 1;

		day = MonthDays(month, year);

	}
	else
		day = day - 1;
	cout << "дату предыдущего дня: " <<
		day << "." <<
		month << "." <<
		year << endl;
}