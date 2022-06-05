#include<iostream>
#include <ctime>

using namespace std;

template<class type>
void CreateMassFromKeyboard(type *Mass, int fsize)
{
	for (int i = 0; i < fsize; i++)
	{
		cin >> Mass[i];
	}
}
void CreateMassFromKeyboard(double* Mass, int fsize)
{
	double tmp;
	for (int i = 0; i < fsize; i++)
	{
		cin >> tmp;
		while(tmp < 10)
		{
			cout << "Значение типа DOUBLE должно быть больше 10" << endl;
			cin >> tmp;
		}
		Mass[i] = tmp;
	}
}

template<class type>
void CreateMassRand(type* Mass, int fsize)
{
	for (int i = 0; i < fsize; i++)
	{
		Mass[i] = rand() % 100;
	}
}
void CreateMassRand(double* Mass, int fsize)
{
	double tmp;
	for (int i = 0; i < fsize; i++)
	{
		Mass[i] = 10+0.01*(rand() % 10001);
	}
}

template<class type>
void Print(type* Mass, int fsize)
{
	cout << endl << "Печать массива: " << endl;
	for (int i = 0; i < fsize; i++)
		cout << *(Mass + i) << endl;
}

template<class type>
void Count(type* Mass, int fsize)
{
	int count = 0;
	cout << endl << "Количество нулевых элементов в массиве равно: ";
	for (int i = 0; i < fsize; i++)
		if (Mass[i] == 0) count++;
	cout << count << endl;
}

int ControlChoise()
{

	while (true) {

		int check;
		cin >> check;

		if (cin.fail())
		{
			cout << "Циферки, пожалуйста" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else if (check <= 0)
		{
			cout << "Неверная команта" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else if (check > 3)
		{
			cout << "Неверная команда" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else
		{
			return check;
			cin.clear();
			cin.ignore(32767, '\n');
		}

	}

}

int ControlChoise1()
{

	while (true) {

		int check;
		cin >> check;

		if (cin.fail())
		{
			cout << "Циферки, пожалуйста" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else if (check <= 0)
		{
			cout << "Неверная команта" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else if (check > 2)
		{
			cout << "Неверная команда" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else
		{
			return check;
			cin.clear();
			cin.ignore(32767, '\n');
		}

	}

}

int ControlSize()
{

	while (true) {

		int check;
		cin >> check;

		if (cin.fail())
		{
			cout << "Циферки, пожалуйста" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else if (check <= 0)
		{
			cout << "Больше нуля, пожалуйста" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else
		{
			if (check > 20)
			{
				cout << "Вам не надоест столько заполнять?..... ну ладно..." << endl;
			}
			return check;
			cin.clear();
			cin.ignore(32767, '\n');
		}

	}

}

void Menu(int* fchoise) {
	cout << endl << "МЕНЮ" << endl
		<< "Работа с типом данных INT" << "\t\t" << "..1" << endl
		<< "Работа с типом данных DOUBLE" << "\t\t" << "..2" << endl
		<< "Завершение программы" << "\t\t" << "..3" << endl;

	*(fchoise) = ControlChoise();
}

int main() {

	setlocale(LC_ALL, "Russian");
	srand(time(0));

	int choise=0, sizeInt, sizeDouble, choise1;

	cout << "Добрый день" << endl;
	int* MassInt=new int[1];
	double* MassDouble= new double[1];

	while (choise != 3)
	{
		Menu(&choise);

		if (choise == 1)
		{
			cout << "Введите количество элементов массива: ";
			sizeInt = ControlSize();
			cout << endl;
			MassInt = new int[sizeInt];

			cout << "Вы хотете инициализировать массив вручную? Введите 1, если да, и 2, если нет: ";
			choise1=ControlChoise1();
			cout << "Инициализация типа Int" << endl;
			if (choise1 == 1)
			{
				CreateMassFromKeyboard(MassInt, sizeInt);
			}
			else
			{
				CreateMassRand(MassInt, sizeInt);
			}
			Print(MassInt, sizeInt);
			Count(MassInt, sizeInt);
		}
		else if (choise == 2)
		{
			cout << "Введите количество элементов массива: ";
			sizeDouble = ControlSize();
			cout << endl;
			MassDouble = new double[sizeDouble];

			cout << "Вы хотете инициализировать массив вручную? Введите 1, если да, и 2, если нет: ";
			choise1 = ControlChoise1();
			cout << "Инициализация типа Double" << endl;
			if (choise1 == 1)
			{
				CreateMassFromKeyboard(MassDouble, sizeDouble);
			}
			else
			{
				CreateMassRand(MassDouble, sizeDouble);
			}
			Print(MassDouble, sizeDouble);
			cout << endl << "Все элементы больше 10, нулевых нет" << endl;
		}
	}

	delete[] MassInt;
	delete[] MassDouble;

	return 0;
}
