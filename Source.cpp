#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
using namespace std;

bool Proverka(const string& st)
{
	for (int i = 0; i < st.size(); i++)
	{
		if(isdigit(st[i])==0)
			return 0;
	}
	return 1;
}
class Finan
{
	struct K
	{
		int number;
		int summa = 0;
		vector<string>log;
	};
	vector<K> pocket;
	vector<K> card_deb;
	vector<K> card_credit;
public:
	vector<K> getPocket() { return pocket; }
	vector<K> getCard_deb() { return card_deb; }
	vector<K> getCard_credit() { return card_credit; }
	void Print_Pocket()const
	{
		if(!pocket.empty())
		for (int i = 0; i < pocket.size(); i++)
		{
			cout << i + 1 << ":\n";
			cout <<" Номер карты:" << pocket[i].number << endl;
			cout <<" Остаток средств:" << pocket[i].summa << endl;
		}
		else
		{
			cout << "Список пуст.\n";
		}
	}
	void Popolnenie_Pocket()
	{
		cout << "Выбор кошелька.\n";
		string p{ "asda" };
		Print_Pocket();
		while (Proverka(p) == 0 || stoi(p) < 0 || stoi(p) > pocket.size())
		{
			cout << "Выберите номер кошелька: ";
			cin >> p;
			if (Proverka(p) == 0 || stoi(p) < 0 || stoi(p) > pocket.size())
				cout << "Неправильный номер.\n";
		}
		int id = stoi(p) - 1;
		p = "adajsd";
		while (Proverka(p) == 0 || stoi(p) < 1)
		{
			cout << "Введите сумму пополнения: ";
			cin >> p;
			if (Proverka(p) == 0 || stoi(p) < 1)
				cout << "Сумма должна быть больше 0.\n";
		}
		pocket[id].summa += stoi(p);
	}
	void AddPocket()
	{
		K tmp;
		string t {"akwedj"};
		cout << "\t~~~~~~~~~ Добавление кошелька. ~~~~~~~~~\n";
		while (Proverka(t) == 0 || t.size() != 5)
		{
			cout << "Придумайте номер карты (5 циферок)\n";
			cin >> t;
			if (Proverka(t) == 0)
				cout << "Нужны цифры =(.\n";
			if (t.size() != 5 && Proverka(t) != 0)
				cout << "Циферок должно быть 5.\n";
		}
		tmp.number = stoi(t);
		pocket.push_back(tmp);
	}

};

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "ru");
	Finan A;
	char vvod;
	do
	{
		system("cls");
		cout << "1. Кошелёк.\n2. Карта дебитовая.\n3. Карта кредитная.\n";
		cout << "ESC. Выход.\n~~~~~~~~~~~~~~~~~~~~~~~\n";
		vvod = _getch();
		switch (vvod)
		{
		case'1':
		{
			char vvod2;
			do
			{
				system("cls");
				cout << "1. Добавить кошелёк.\n2. Пополнить кошелёк.\n3. Показать список всех кошельков.\n";
				cout << "Esc. Предыдущее меню.\n~~~~~~~~~~~~~~~~~~~~~~~\n";
				vvod2 = _getch();
				switch (vvod2)
				{
				case'1':
				{
					A.AddPocket();
					break;
				}
				case'2':
				{
					if (A.getPocket().size() > 0)
					{
						A.Popolnenie_Pocket();
					}
					else
						cout << "Список пуст.\n";
					system("pause");
					break;
				}
				case'3':
				{
					if (A.getPocket().size() > 0)
					{
						A.Print_Pocket();
					}
					else
						cout << "Список пуст.\n";
					system("pause");
					break;
				}
				}
			} while (vvod2 != 27);
			A.Popolnenie_Pocket();
			A.Print_Pocket();
			system("pause");
			break;
		}
		case'2':
		{
			break;
		}
		case'3':
		{
			break;
		}
		default:
			break;
		}
		


	} while (vvod != 27);



	return 0;
}