#include <iostream> //Вариант 7(бытовая техника)
#include <string> 
#include <windows.h>
using namespace std;
#undef max
class  technic
{
public:
	technic() {};
	virtual void see() = 0;
};
class impch : public technic
{
	virtual void see() = 0;
};
class noimpch : public technic
{
	virtual void see() = 0;
};
class household : public impch
{
public:
	bool isTypeCorrect();
	int inputNum(int, int);
	int insert();
	string designation;// Название техники 
	string model;// Модель
	void see() {
		cout << "-------------------------------ИНФОРМАЦИЯ О ПРИБОРЕ-------------------------------------------------------" << endl;
		cout << "\nНазвание техники: " << designation << "\nМодель техники: " << model << endl;
	}

};
int household::insert()
{
	int l;
	while (true)
	{
		cin >> l;
		if (cin.get() == '\n') {
			if (l > 0) {
				break;
			}

			else
			{
				cout << "Некорректный ввод ! Введите положительное число: \n";
			}
		}
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Некорректный ввод ! Введите заново: \n";
		}

	}
	return l;
}
bool household::isTypeCorrect()
{
	if (cin.get() == '\n')
		return true;
	else
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return false;
	}
}
int household::inputNum(int left_range, int right_range)
{
	int number;
	while (true)
	{
		cin >> number;
		if (isTypeCorrect() && (number >= left_range) && (number <= right_range))
		{
			return number;
		}
		else
		{
			cout << "\n\n\tВведено некорректное число(№)!";
			if ((number <= left_range) || (number >= right_range))
				cout << "\t Число может быть только от " << left_range << " и до " << right_range << " !";
			cout << "\n\t\tПопробуйте ещё раз: ";
		}
	}
}
class organization : public impch
{
protected:
public:
	string company;// компания
	string country;// cтрана изготовитель
	void see()
	{
		cout << " \nНазвание компании изготовившей данную технику : " << company << "\nСтрана Изготовления: " << country << endl;
	}
};
class amount :public impch
{
public:
	int n;// количество моделей данной техники
	int k;// нужное количество вспомогательных приборов
	void see()
	{
		cout << "\nКоличество моделей данной техники " << n << endl;
		cout << "\nНужное количество вспомогательных приборов " << k << endl;
	}
};

class division : public noimpch
{
public:
	int rz;
	void see()
	{
		switch (rz)
		{
		case 1:
		{cout << "\nВид:Крупная бытовая техника " << endl; break; }
		case 2:
		{cout << "\nВид:Климатическая техника " << endl; break; }
		case 3:
		{ cout << "\nВид:Мелкая бытовая техника " << endl; break; }
		}
	}
};
class controll :public noimpch
{
public:
	int vr;
	void see() {
		switch (vr)
		{
		case 0: {
			cout << "\nТип:Управляемая техника" << endl; break;
		}
		case 1: {
			cout << "\nТип:Неуправляемая техника " << endl; break;
		}
		}
	}
};
int create()
{
	technic *ptr[5];
	household mod;
	organization pro;
	amount kol;
	division sem;
	controll ler;
	cout << "Введите название техники:" << endl;
	getline(cin, mod.designation);
	cout << "Модель бытовой техники : " << endl;
	getline(cin, mod.model);
	cout << "Введите название компании изготовившей данную технику: " << endl;
	getline(cin, pro.company);
	cout << "Страна изготовитель: " << endl;
	getline(cin, pro.country);
	cout << "Количество моделей данной техники: " << endl;
	kol.n = mod.insert();
	cout << "Нужное количество вспомогательных приборов: " << endl;
	kol.k = mod.insert();
	cout << " -------------Определение вида ------------ " << endl
		<< "1.Введите 1, если техника относится к разряду Крупной " << endl
		<< "2.Введите 2, если техника относится к разряду Климатической " << endl
		<< "3.Введите 3, если техника относится к разряду Мелкой " << endl
		<< "Ваш выбор:";
	sem.rz = mod.inputNum(1, 3);
	cout << " ---------- Управляемость------------ " << endl
		<< "0.Введите 0 если бытовая техника является управляемой " << endl
		<< "1.Введите 1 если бытовая техника является неуправляемой " << endl
		<< "Ваш выбор:";
	ler.vr = mod.inputNum(0, 1);
	ptr[0] = &mod;
	ptr[1] = &pro;
	ptr[2] = &kol;
	ptr[3] = &sem;
	ptr[4] = &ler;
	for (int i = 0; i < 5; i++)
	{
		ptr[i]->see();
	}
	system("pause");
	return 0;
}
void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	household as;
	create();
	while (true)
	{
		cout << " ----------Выбор пути------------ " << endl
			<< "1.Ввести ещё одни данные для бытовой техники" << endl
			<< "0.Выйти из программы" << endl
			<< "Ваш выбор:";
		int choice;
		choice = as.inputNum(0, 1);
		switch (choice)
		{
		case 0:system("cls"); return;
		case 1: create();
		}

	}
}