#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
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
	struct K2
	{
		int zatrat;
		string category;
	};
	struct K
	{
		int number;
		int summa = 0;
		vector<K2>pokupki;
	};
	vector<K> pocket;
	vector<K> card_deb;
	vector<K> card_credit;
public:
	vector<K> getPocket() { return pocket; }
	vector<K> getCard_deb() { return card_deb; }
	vector<K> getCard_credit() { return card_credit; }
	void set_Pocket(const K& tmp) { pocket.push_back(tmp); }
	void set_Card_deb(const K& tmp) { card_deb.push_back(tmp); }
	void set_Card_credit(const K& tmp) { card_credit.push_back(tmp); }
	void Print(const vector<K>& pok)
	{
		if (!pok.empty())
			for (int i = 0; i < pok.size(); i++)
			{
				cout << i + 1 << ":\n";
				cout << " Номер карты:" << pok[i].number << endl;
				cout << " Остаток средств:" << pok[i].summa << endl;
			}
		else
		{
			cout << "Список пуст.\n";
		}
	}
	void PrintOtch(const vector<K>& pok)
	{
		if (!pok.empty())
			for (int i = 0; i < pok.size(); i++)
			{
				cout << "Карта номер " << i + 1 << ":\n";
				for (int u = 0; u < pok[i].pokupki.size(); u++)
				{
					cout << u + 1 << ": Категория: " << pok[i].pokupki[u].category << endl;
					cout << "   Расход: " << pok[i].pokupki[u].zatrat << endl;
				}
			}
		else
		{
			cout << "Список пуст.\n";
		}
	}
	void Popolnenie_Card_credit()
	{
		cout << "Выбор карты(кредит).\n";
		string p{ "asda" };
		Print(card_credit);
		while (Proverka(p) == 0 || stoi(p) < 0 || stoi(p) > card_credit.size())
		{
			cout << "Выберите номер карты(кредит): ";
			cin >> p;
			if (Proverka(p) == 0 || stoi(p) < 0 || stoi(p) > card_credit.size())
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
		card_credit[id].summa += stoi(p);
	}
	void Popolnenie_Card_deb()
	{
		cout << "Выбор карты(дебет).\n";
		string p{ "asda" };
		Print(card_deb);
		while (Proverka(p) == 0 || stoi(p) < 0 || stoi(p) > card_deb.size())
		{
			cout << "Выберите номер карты(дебет): ";
			cin >> p;
			if (Proverka(p) == 0 || stoi(p) < 0 || stoi(p) > card_deb.size())
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
		card_deb[id].summa += stoi(p);
	}
	void Popolnenie_Pocket()
	{
		cout << "Выбор кошелька.\n";
		string p{ "asda" };
		Print(pocket);
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
	K AddPocket()
	{
		K tmp;
		string t{ "akwedj" };
		cout << "\t~~~~~~~~~ Добавление кошелька. ~~~~~~~~~\n";
		while (Proverka(t) == 0 || t.size() != 5)
		{
			cout << "Придумайте номер кошелька (5 циферок): ";
			cin >> t;
			if (Proverka(t) == 0)
				cout << "Нужны цифры =(.\n";
			if (t.size() != 5 && Proverka(t) != 0)
				cout << "Циферок должно быть 5.\n";
		}
		tmp.number = stoi(t);
		return tmp;
	}
	void Pokupka_Pocket()
	{
		K2 t;
		string tmp;
		char vvod = 'a';
		while (vvod != '1' && vvod != '2')
		{
			cout << "~~~~~~~~~~~~~ Выбор категории покупки. ~~~~~~~~~~~~~\n";
			cout << "1. Прод. товары.\n2. Пром. товары.\n";
			vvod = _getch();
			if (vvod != '1' && vvod != '2')
				cout << "Нужно выбрать 1 или 2.\n";
		}
		tmp = "adkaw";
		while (Proverka(tmp) == 0)
		{
			cout << "Сумма покупки: ";
			cin >> tmp;
			if (Proverka(tmp) == 0)
				cout << "Это не цифра.\n";
		}
		t.zatrat = stoi(tmp);
		tmp = "adkaw";
		cout << "~~~~~~~~~~~~~ Выбор кошелька для оплаты. ~~~~~~~~~~~~~\n";
		Print(pocket);
		if (!pocket.empty())
		{
			while (Proverka(tmp) == 0 || stoi(tmp) < 1 || stoi(tmp) > pocket.size())
			{
				cout << "Выберите номер кошелька: ";
				cin >> tmp;
				if (Proverka(tmp) == 0 || stoi(tmp) < 1 || stoi(tmp) > pocket.size())
					cout << "Неправильный номер.\n";
			}
			int id = stoi(tmp) - 1;

			if (vvod == '1')
			{
				t.category = "Прод. товары.";
			}
			if (vvod == '2')
			{
				t.category = "Пром. товары.";
			}
			if (pocket[id].summa - t.zatrat >= 0)
			{
				pocket[id].pokupki.push_back(t);
				pocket[id].summa -= t.zatrat;
			}
			else
				cout << "Недостаточно средств.\n";
		}
	}
	void Pokupka_Card_deb()
	{
		K2 t;
		string tmp;
		char vvod = 'a';
		while (vvod != '1' && vvod != '2')
		{
			cout << "~~~~~~~~~~~~~ Выбор категории покупки. ~~~~~~~~~~~~~\n";
			cout << "1. Прод. товары.\n2. Пром. товары.\n";
			vvod = _getch();
			if (vvod != '1' && vvod != '2')
				cout << "Нужно выбрать 1 или 2.\n";
		}
		tmp = "adkaw";
		while (Proverka(tmp) == 0)
		{
			cout << "Сумма покупки: ";
			cin >> tmp;
			if (Proverka(tmp) == 0)
				cout << "Это не цифра.\n";
		}
		t.zatrat = stoi(tmp);
		tmp = "adkaw";
		cout << "~~~~~~~~~~~~~ Выбор карты(дебет) для оплаты. ~~~~~~~~~~~~~\n";
		Print(card_deb);
		if (!card_deb.empty())
		{
			while (Proverka(tmp) == 0 || stoi(tmp) < 1 || stoi(tmp) > card_deb.size())
			{
				cout << "Выберите номер карты(дебет): ";
				cin >> tmp;
				if (Proverka(tmp) == 0 || stoi(tmp) < 1 || stoi(tmp) > card_deb.size())
					cout << "Неправильный номер.\n";
			}
			int id = stoi(tmp) - 1;

			if (vvod == '1')
			{
				t.category = "Прод. товары.";
			}
			if (vvod == '2')
			{
				t.category = "Пром. товары.";
			}
			
			if (card_deb[id].summa - t.zatrat >= 0)
			{
				card_deb[id].pokupki.push_back(t);
				card_deb[id].summa -= t.zatrat;
			}
			else
				cout << "Недостаточно средств.\n";
		}
	}
	void Pokupka_Card_credit()
	{
		K2 t;
		string tmp;
		char vvod = 'a';
		while (vvod != '1' && vvod != '2')
		{
			cout << "~~~~~~~~~~~~~ Выбор категории покупки. ~~~~~~~~~~~~~\n";
			cout << "1. Прод. товары.\n2. Пром. товары.\n";
			vvod = _getch();
			if (vvod != '1' && vvod != '2')
				cout << "Нужно выбрать 1 или 2.\n";
		}
		tmp = "adkaw";
		while (Proverka(tmp) == 0)
		{
			cout << "Сумма покупки: ";
			cin >> tmp;
			if (Proverka(tmp) == 0)
				cout << "Это не цифра.\n";
		}
		t.zatrat = stoi(tmp);
		tmp = "adkaw";
		cout << "~~~~~~~~~~~~~ Выбор карты(кредит) для оплаты. ~~~~~~~~~~~~~\n";
		Print(card_credit);
		if (!card_credit.empty())
		{
			while (Proverka(tmp) == 0 || stoi(tmp) < 1 || stoi(tmp) > card_credit.size())
			{
				cout << "Выберите номер карты(кредит): ";
				cin >> tmp;
				if (Proverka(tmp) == 0 || stoi(tmp) < 1 || stoi(tmp) > card_credit.size())
					cout << "Неправильный номер.\n";
			}
			int id = stoi(tmp) - 1;

			if (vvod == '1')
			{
				t.category = "Прод. товары.";
			}
			if (vvod == '2')
			{
				t.category = "Пром. товары.";
			}
			card_credit[id].pokupki.push_back(t);
			card_credit[id].summa -= t.zatrat;
		}
	}
	void SavetoFile(const vector<K>& pok,const int&id)
	{	
		string path;
		if (id == 1)
			path = "pocket.txt";
		if (id == 2)
			path = "debet.txt";
		if (id == 3)
			path = "credit.txt";

		ofstream os(path);
		if (os.is_open())
		{
			for (int i = 0; i < pok.size(); i++)
			{
				os << "Номер: " << pok[i].number << endl;
				for (int u = 0; u < pok[i].pokupki.size(); u++)
				{
					os << "Категория: " << pok[i].pokupki[u].category << endl;
					os << "Затраты: " << pok[i].pokupki[u].zatrat << endl;
				}
				os << "\n";
			}
		}
		else
			cout << "Файл не был открыт.\n";
	}
	void TopSumm(const vector<K>& pok)
	{
		if (!pok.empty())
		{
			int kol = 1;
			vector<int>mas;
			for (int i = 0; i < pok.size(); i++)
			{
				for (int u = 0; u < pok[i].pokupki.size(); u++)
				{
					mas.push_back(pok[i].pokupki[u].zatrat);
				}
			}
			sort(mas.begin(), mas.end());
			cout << "~~~~~~~~~~~~ Top 3 max. ~~~~~~~~~~~~\n";
			for (int i = mas.size()-1; i >= 0 && kol<=3; i--,kol++)
			{
				cout << kol << " max: " << mas[i] << endl;
			}
		}
		else
			cout << "Список пуст.\n";
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
		cout << "1. Кошелёк.\n2. Карта дебетовая.\n";
		cout <<	"3. Карта кредитная.\n";
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
				cout << "1. Добавить кошелёк.\n2. Пополнить кошелёк.\n";
				cout << "3. Показать список всех кошельков.\n4. Сделать покупки.\n";
				cout << "5. Отчёт о покупках.\n6. Сохранение отчёта в файл.\n";
				cout << "7. Топ 3 максимальных платежей.\n";
				cout << "Esc. Предыдущее меню.\n~~~~~~~~~~~~~~~~~~~~~~~\n";
				vvod2 = _getch();
				switch (vvod2)
				{
				case'1':
				{
					A.set_Pocket(A.AddPocket());
					system("pause");
					break;
				}
				case'2':
				{
					if (A.getPocket().size() > 0)
					{
						A.Popolnenie_Pocket();
					}
					else
						cout << "Список карт пуст.\n";
					system("pause");
					break;
				}
				case'3':
				{
					if (A.getPocket().size() > 0)
					{
						A.Print(A.getPocket());
					}
					else
						cout << "Список карт пуст.\n";
					system("pause");
					break;
				}
				case'4':
				{
					if (!A.getPocket().empty())
					A.Pokupka_Pocket();
					else
					cout << "Список карт пуст.\n";
					system("pause");
					break;
				}
				case'5':
				{
					A.PrintOtch(A.getPocket());
					system("pause");
					break;
				}
				case'6':
				{
					if (!A.getPocket().empty())
						A.SavetoFile(A.getPocket(), 1);
					else
						cout << "Список пуст.\n";
					system("pause");
					break;
				}
				case'7':
				{			
					A.TopSumm(A.getPocket());
					system("pause");
					break;
				}
				}
			} while (vvod2 != 27);
			break;
		}
		case'2':
		{
			char vvod2;
			do
			{
				system("cls");
				cout << "1. Добавить карту(дебет).\n2. Пополнить карту(дебет).\n";
				cout << "3. Показать список всех карт(дебет).\n4. Сделать покупки.\n";
				cout << "5. Отчёт о покупках.\n6. Сохранение отчёта в файл.\n";
				cout << "7. Топ 3 максимальных платежей.\n";
				cout << "Esc. Предыдущее меню.\n~~~~~~~~~~~~~~~~~~~~~~~\n";
				vvod2 = _getch();
				switch (vvod2)
				{
				case'1':
				{
					A.set_Card_deb(A.AddPocket());
					system("pause");
					break;
				}
				case'2':
				{
					if (A.getCard_deb().size() > 0)
					{
						A.Popolnenie_Card_deb();
					}
					else
						cout << "Список карт пуст.\n";
					system("pause");
					break;
				}
				case'3':
				{
					if (A.getCard_deb().size() > 0)
					{
						A.Print(A.getCard_deb());
					}
					else
						cout << "Список карт пуст.\n";
					system("pause");
					break;
				}
				case'4':
				{
					if (!A.getCard_deb().empty())
					A.Pokupka_Card_deb();
					else
						cout << "Список карт пуст.\n";
					system("pause");
					break;
				}
				case'5':
				{
					A.PrintOtch(A.getCard_deb());
					system("pause");
					break;
				}
				case'6':
				{
					if (!A.getCard_deb().empty())
					A.SavetoFile(A.getCard_deb(), 2);
					else
						cout << "Список пуст.\n";
					system("pause");
					break;
				}
				case'7':
				{
					A.TopSumm(A.getCard_deb());
					system("pause");
					break;
				}
				}
			} while (vvod2 != 27);
			break;
		}
		case'3':
		{
			char vvod2;
			do
			{
				system("cls");
				cout << "1. Добавить карту(кредит).\n2. Пополнить карту(кредит).\n";
				cout << "3. Показать список всех карт(кредит).\n4. Сделать покупки.\n";
				cout << "5. Отчёт о покупках.\n6. Сохранение отчёта в файл.\n";
				cout << "7. Топ 3 максимальных платежей.\n";
				cout << "Esc. Предыдущее меню.\n~~~~~~~~~~~~~~~~~~~~~~~\n";
				vvod2 = _getch();
				switch (vvod2)
				{
				case'1':
				{
					A.set_Card_credit(A.AddPocket());
					system("pause");
					break;
				}
				case'2':
				{
					if (A.getCard_credit().size() > 0)
					{
						A.Popolnenie_Card_credit();
					}
					else
						cout << "Список карт пуст.\n";
					system("pause");
					break;
				}
				case'3':
				{
					if (A.getCard_credit().size() > 0)
					{
						A.Print(A.getCard_credit());
					}
					else
						cout << "Список карт пуст.\n";
					system("pause");
					break;
				}
				case'4':
				{
					if (!A.getCard_credit().empty())
					A.Pokupka_Card_credit();
					else
						cout << "Список карт пуст.\n";
					system("pause");
					break;
				}
				case'5':
				{
					A.PrintOtch(A.getCard_credit());
					system("pause");
					break;
				}
				case'6':
				{
					if(!A.getCard_credit().empty())
					A.SavetoFile(A.getCard_credit(), 3);
					else
						cout << "Список пуст.\n";
					system("pause");
					break;
				}
				case'7':
				{
					A.TopSumm(A.getCard_credit());
					system("pause");
					break;
				}
				}
			} while (vvod2 != 27);
			break;
		}
		default:
			break;
		}
		
	} while (vvod != 27);

	return 0;
}