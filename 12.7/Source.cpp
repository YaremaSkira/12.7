#include <iostream>
#include <windows.h>
#include <iomanip>
#include <string>

using namespace std;

struct StElem
{
	StElem* link;
	string prizv;
	string telnumber;
	int debt;
};

void CreateList(StElem*& first, StElem*& last, int N);
void AddElem(StElem*& first, StElem*& last, string prizv, string telnumber, int debt);
void Print(StElem* first, int i);
void Find(StElem* first, int i, double x);
void DeleteBegElem(StElem*& first, StElem*& last);
void DeleteElem(StElem*& first, StElem*& last);
void Scanning(StElem* first, StElem* last);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	StElem* first = NULL,
		* last = NULL;

	int N;
	double x;
	cout << "Введіть кількість абонентів в списку: "; cin >> N;
	cout << endl;
	CreateList(first, last, N);
	cout << endl;
	for (int i = 0; i < 3; i++)
		Print(first, i);
	cout << endl;
	cout << "Вивід абонентів,заборгованість яких вище вказаного значення :" << endl;
	cout << "Введіть значення: "; cin >> x;
	cout << "Абоненти, заборгованість яких вище вказаного значення:" << endl;

	for (int i = 0; i < 3; i++)
		Find(first, i, x);
	cout << endl;
	Scanning(first, last);

	system("pause");
	return 0;
}

void CreateList(StElem*& first, StElem*& last, int N)
{
	string prizv;
	string telnumber;
	int debt;
	for (int i = 0; i < N; i++)
	{
		cin.sync();
		cout << "Прізвище абонента: "; cin >> prizv;
		cout << "Номер Телефону: "; cin >> telnumber;
		do
		{
			cout << "Заборгованість: "; cin >> debt;
		} while (debt < 0);
		AddElem(first, last, prizv, telnumber, debt);
		cout << endl << endl;
	}
}

void AddElem(StElem*& first, StElem*& last, string prizv, string telnumber, int debt)
{
	StElem* tmp = new StElem;
	tmp->prizv = prizv;
	tmp->telnumber = telnumber;
	tmp->debt = debt;
	tmp->link = NULL;
	if (last != NULL)
		last->link = tmp;
	last = tmp;
	if (first == NULL)
		first = tmp;
}

void Print(StElem* first, int i)
{
	while (first != NULL)
	{
		if (i == 0)
			cout << "| " << setw(8) << left << first->prizv << " ";
		else if (i == 1)
			cout << "| " << setw(8) << left << first->telnumber << " ";
		else
			cout << "| " << setw(8) << left << first->debt << " ";

		first = first->link;
	}
	cout << "|" << endl;
}

void Find(StElem* first, int i, double x)
{
	while (first != NULL)
	{
		if (first->debt > x)
		{
			if (i == 0)
				cout << "| " << setw(8) << left << first->prizv << " ";
			else if (i == 1)
				cout << "| " << setw(8) << left << first->telnumber << " ";
			else
				cout << "| " << setw(8) << left << first->debt << " ";
		}
		first = first->link;
	}
	cout << "|" << endl;
}

void DeleteBegElem(StElem*& first, StElem*& last)
{
	StElem* tmp = first->link;
	delete first;
	first = tmp;
}

void DeleteElem(StElem*& first, StElem*& last)
{
	StElem* tmp = first->link->link;
	delete first->link;
	first->link = tmp;
}

void Scanning(StElem* first, StElem* last)
{
	while (first != NULL && first->debt == 0)
		DeleteBegElem(first, last);
	while (first != NULL && first->link != NULL)
	{
		if (first->link->debt == 0)
			DeleteElem(first, last);
		else
			first = first->link;
	}
}