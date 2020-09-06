#include <iostream> //������� 7(������� �������)
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
	string designation;// �������� ������� 
	string model;// ������
	void see() {
		cout << "-------------------------------���������� � �������-------------------------------------------------------" << endl;
		cout << "\n�������� �������: " << designation << "\n������ �������: " << model << endl;
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
				cout << "������������ ���� ! ������� ������������� �����: \n";
			}
		}
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "������������ ���� ! ������� ������: \n";
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
			cout << "\n\n\t������� ������������ �����(�)!";
			if ((number <= left_range) || (number >= right_range))
				cout << "\t ����� ����� ���� ������ �� " << left_range << " � �� " << right_range << " !";
			cout << "\n\t\t���������� ��� ���: ";
		}
	}
}
class organization : public impch
{
protected:
public:
	string company;// ��������
	string country;// c����� ������������
	void see()
	{
		cout << " \n�������� �������� ������������ ������ ������� : " << company << "\n������ ������������: " << country << endl;
	}
};
class amount :public impch
{
public:
	int n;// ���������� ������� ������ �������
	int k;// ������ ���������� ��������������� ��������
	void see()
	{
		cout << "\n���������� ������� ������ ������� " << n << endl;
		cout << "\n������ ���������� ��������������� �������� " << k << endl;
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
		{cout << "\n���:������� ������� ������� " << endl; break; }
		case 2:
		{cout << "\n���:������������� ������� " << endl; break; }
		case 3:
		{ cout << "\n���:������ ������� ������� " << endl; break; }
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
			cout << "\n���:����������� �������" << endl; break;
		}
		case 1: {
			cout << "\n���:������������� ������� " << endl; break;
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
	cout << "������� �������� �������:" << endl;
	getline(cin, mod.designation);
	cout << "������ ������� ������� : " << endl;
	getline(cin, mod.model);
	cout << "������� �������� �������� ������������ ������ �������: " << endl;
	getline(cin, pro.company);
	cout << "������ ������������: " << endl;
	getline(cin, pro.country);
	cout << "���������� ������� ������ �������: " << endl;
	kol.n = mod.insert();
	cout << "������ ���������� ��������������� ��������: " << endl;
	kol.k = mod.insert();
	cout << " -------------����������� ���� ------------ " << endl
		<< "1.������� 1, ���� ������� ��������� � ������� ������� " << endl
		<< "2.������� 2, ���� ������� ��������� � ������� ������������� " << endl
		<< "3.������� 3, ���� ������� ��������� � ������� ������ " << endl
		<< "��� �����:";
	sem.rz = mod.inputNum(1, 3);
	cout << " ---------- �������������------------ " << endl
		<< "0.������� 0 ���� ������� ������� �������� ����������� " << endl
		<< "1.������� 1 ���� ������� ������� �������� ������������� " << endl
		<< "��� �����:";
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
		cout << " ----------����� ����------------ " << endl
			<< "1.������ ��� ���� ������ ��� ������� �������" << endl
			<< "0.����� �� ���������" << endl
			<< "��� �����:";
		int choice;
		choice = as.inputNum(0, 1);
		switch (choice)
		{
		case 0:system("cls"); return;
		case 1: create();
		}

	}
}