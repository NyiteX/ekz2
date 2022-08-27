#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <windows.h>
#define UP 72
#define DOWN 80
#define ESC 27
#define ENTER 13
using namespace std;

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
void GoToXY(short x, short y)
{
	SetConsoleCursorPosition(hStdOut, { x, y });
}
void ConsoleCursorVisible(bool show, short size)
{
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = show;
	structCursorInfo.dwSize = size;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}
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
				cout << "ID: " << i + 1 << "\n";
				cout << "Номер карты:" << pok[i].number << endl;
				cout << "Остаток средств:" << pok[i].summa << endl;
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
			SetConsoleTextAttribute(hStdOut, 4);
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
		string tmp = "adasdk";
		char vvod = 'a';
		int active_menu2 = 0;
		while (vvod != 49 && vvod != 50 && vvod!=27)
		{		
			int x = 32, y = 17;
			system("cls");
			GoToXY(x, y);

			string Menu2[] = { "Прод. товары","Пром. товары","Предыдущее меню" };

			for (int i = 0; i < size(Menu2); i++)
			{
				if (i == active_menu2)
					SetConsoleTextAttribute(hStdOut, 8);
				else
					SetConsoleTextAttribute(hStdOut, 7);
				GoToXY(x, y++);
				cout << Menu2[i] << endl;
			}
			vvod = _getch();
			switch (vvod)
			{
			case UP:
				if (--active_menu2 < 0)
					active_menu2 = size(Menu2) - 1;
				break;
			case DOWN:
				if (++active_menu2 > size(Menu2) - 1)
					active_menu2 = 0;
				break;
			case ENTER:
				switch (active_menu2)
				{
				case 0:
					vvod = 49;
					break;
				case 1:
					vvod = 50;
					break;
				case 2:
					vvod = 27;
					break;
				}
			}
		}	
		if(vvod == 49 || vvod == 50)
		{
			SetConsoleTextAttribute(hStdOut, 8);
			while (Proverka(tmp) == 0)
			{
				cout << "Сумма покупки: ";
				cin >> tmp;
				if (Proverka(tmp) == 0)
				{
					SetConsoleTextAttribute(hStdOut, 4);
					cout << "Это не цифра.\n";
				}
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
					{
						SetConsoleTextAttribute(hStdOut, 4);
						cout << "Неправильный номер.\n";
					}
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
					vvod = 27;
				}
				else
				{
					vvod = 27;
					SetConsoleTextAttribute(hStdOut, 4);
					cout << "Недостаточно средств.\n";
				}
			}
		}
	}
	void Pokupka_Card_deb()
	{
		K2 t;
		string tmp = "adasdk";
		char vvod = 'a';
		int active_menu2 = 0;
		while (vvod != 49 && vvod != 50 && vvod != 27)
		{
			int x = 32, y = 17;
			system("cls");
			GoToXY(x, y);

			string Menu2[] = { "Прод. товары","Пром. товары","Предыдущее меню" };

			for (int i = 0; i < size(Menu2); i++)
			{
				if (i == active_menu2)
					SetConsoleTextAttribute(hStdOut, 8);
				else
					SetConsoleTextAttribute(hStdOut, 7);
				GoToXY(x, y++);
				cout << Menu2[i] << endl;
			}
			vvod = _getch();
			switch (vvod)
			{
			case UP:
				if (--active_menu2 < 0)
					active_menu2 = size(Menu2) - 1;
				break;
			case DOWN:
				if (++active_menu2 > size(Menu2) - 1)
					active_menu2 = 0;
				break;
			case ENTER:
				switch (active_menu2)
				{
				case 0:
					vvod = 49;
					break;
				case 1:
					vvod = 50;
					break;
				case 2:
					vvod = 27;
					break;
				}
			}
		}
		if (vvod == 49 || vvod == 50)
		{
			SetConsoleTextAttribute(hStdOut, 8);
			while (Proverka(tmp) == 0)
			{
				cout << "Сумма покупки: ";
				cin >> tmp;
				if (Proverka(tmp) == 0)
				{
					SetConsoleTextAttribute(hStdOut, 4);
					cout << "Это не цифра.\n";
				}
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
					{
						SetConsoleTextAttribute(hStdOut, 4);
						cout << "Неправильный номер.\n";
					}
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
					vvod = 27;
				}
				else
				{
					vvod = 27;
					SetConsoleTextAttribute(hStdOut, 4);
					cout << "Недостаточно средств.\n";
				}
			}
		}
	}
	void Pokupka_Card_credit()
	{
		K2 t;
		string tmp = "adasdk";
		char vvod = 'a';
		int active_menu2 = 0;
		while (vvod != 49 && vvod != 50 && vvod != 27)
		{
			int x = 32, y = 17;
			system("cls");
			GoToXY(x, y);

			string Menu2[] = { "Прод. товары","Пром. товары","Предыдущее меню" };

			for (int i = 0; i < size(Menu2); i++)
			{
				if (i == active_menu2)
					SetConsoleTextAttribute(hStdOut, 8);
				else
					SetConsoleTextAttribute(hStdOut, 7);
				GoToXY(x, y++);
				cout << Menu2[i] << endl;
			}
			vvod = _getch();
			switch (vvod)
			{
			case UP:
				if (--active_menu2 < 0)
					active_menu2 = size(Menu2) - 1;
				break;
			case DOWN:
				if (++active_menu2 > size(Menu2) - 1)
					active_menu2 = 0;
				break;
			case ENTER:
				switch (active_menu2)
				{
				case 0:
					vvod = 49;
					break;
				case 1:
					vvod = 50;
					break;
				case 2:
					vvod = 27;
					break;
				}
			}
		}
		if (vvod == 49 || vvod == 50)
		{
			SetConsoleTextAttribute(hStdOut, 8);
			while (Proverka(tmp) == 0)
			{
				cout << "Сумма покупки: ";
				cin >> tmp;
				if (Proverka(tmp) == 0)
				{
					SetConsoleTextAttribute(hStdOut, 4);
					cout << "Это не цифра.\n";
				}
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
					{
						SetConsoleTextAttribute(hStdOut, 4);
						cout << "Неправильный номер.\n";
					}
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
				vvod = 27;
			}
		}
	}
	void SavetoFile(const vector<K>& pok, const int& id)
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
			SetConsoleTextAttribute(hStdOut, 8);
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
		{
			SetConsoleTextAttribute(hStdOut, 4);
			cout << "Список пуст.\n";
		}
	}
};

int main()
{
	srand(time(0));
	SetConsoleTitle(L"DA");
	system("Color 0D");
	setlocale(LC_ALL, "Rus");
	ConsoleCursorVisible(false, 100);
	Finan A;

	string Menu[] = { "Кошелёк", "Карта дебетовая", "Карта кредитная", "Выход" };
	int active_menu = 0;

	char ch;
	while (true)
	{
		int x = 32, y = 17;
		GoToXY(x, y);

		for (int i = 0; i < size(Menu); i++)
		{
			if (i == active_menu)
				SetConsoleTextAttribute(hStdOut, 8);
			else
				SetConsoleTextAttribute(hStdOut, 7);
			GoToXY(x, y++);
			cout << Menu[i] << endl;
		}
		ch = _getch();
		if (ch == -32) ch = _getch();
		switch (ch)
		{
		case ESC:
			exit(0);
		case UP:
			if (--active_menu < 0)
				active_menu = size(Menu) - 1;
			break;
		case DOWN:
			if (++active_menu > size(Menu) - 1)
				active_menu = 0;
			break;
		case ENTER:
			switch (active_menu)
			{
			case 0:
			{
				int active_menu2 = 0;
				char ch2 = 'a';
				while (ch2 != 27)
				{
					x = 32, y = 17;
					system("cls");
					GoToXY(x, y);

					string Menu2[] = { "Добавить кошелёк","Пополнить кошелёк",
						"Показать список всех кошельков","Сделать покупки",
					"Отчёт о покупках","Сохранение отчёта в файл",
					"Топ 3 максимальных платежей", "Предыдущее меню" };

					for (int i = 0; i < size(Menu2); i++)
					{
						if (i == active_menu2)
							SetConsoleTextAttribute(hStdOut, 8);
						else
							SetConsoleTextAttribute(hStdOut, 7);
						GoToXY(x, y++);
						cout << Menu2[i] << endl;
					}
					ch2 = _getch();
					switch (ch2)
					{
					case UP:
						if (--active_menu2 < 0)
							active_menu2 = size(Menu2) - 1;
						break;
					case DOWN:
						if (++active_menu2 > size(Menu2) - 1)
							active_menu2 = 0;
						break;
					case ENTER:
						switch (active_menu2)
						{
						case 0:
							SetConsoleTextAttribute(hStdOut, 8);
							A.set_Pocket(A.AddPocket());
							cout << "Добавлено!\n";
							system("pause");
							break;
						case 1:						
							if (A.getPocket().size() > 0)
							{
								SetConsoleTextAttribute(hStdOut, 8);
								A.Popolnenie_Pocket();
							}
							else
							{
								SetConsoleTextAttribute(hStdOut, 4);
								cout << "Список карт пуст.\n";
							}
							system("pause");
							break;
						case 2:
							
							if (A.getPocket().size() > 0)
							{
								SetConsoleTextAttribute(hStdOut, 8);
								A.Print(A.getPocket());
							}
							else
							{
								SetConsoleTextAttribute(hStdOut, 4);
								cout << "Список карт пуст.\n";
							}
							system("pause");
							break;
						case 3:
							if (!A.getPocket().empty())
							{
								SetConsoleTextAttribute(hStdOut, 8);
								A.Pokupka_Pocket();
							}
							else
							{
								SetConsoleTextAttribute(hStdOut, 4);
								cout << "Список карт пуст.\n";							
							}
							system("pause");
							break;
						case 4:
						{
							SetConsoleTextAttribute(hStdOut, 8);
							A.PrintOtch(A.getPocket());
							system("pause");
							break;
						}
						case 5:
						{
							if (!A.getPocket().empty())
							{
								SetConsoleTextAttribute(hStdOut, 8);
								A.SavetoFile(A.getPocket(), 1);
							}
							else
							{
								SetConsoleTextAttribute(hStdOut, 4);
								cout << "Список пуст.\n";
							}
							system("pause");
							break;
						}
						case 6:
						{
							SetConsoleTextAttribute(hStdOut, 8);
							A.TopSumm(A.getPocket());
							system("pause");
							break;
						}
						case 7:
							ch2 = 27;
							break;
						}
					}
				}
				system("cls");
				break;
			}
			case 1:
			{
				int active_menu2 = 0;
				char ch2 = 'a';
				while (ch2 != 27)
				{
					x = 32, y = 17;
					system("cls");
					GoToXY(x, y);

					string Menu2[] = { "Добавить карту(дебет)","Пополнить карту(дебет)",
						"Показать список всех карт(дебет)","Сделать покупки",
					"Отчёт о покупках","Сохранение отчёта в файл",
					"Топ 3 максимальных платежей", "Предыдущее меню" };

					for (int i = 0; i < size(Menu2); i++)
					{
						if (i == active_menu2)
							SetConsoleTextAttribute(hStdOut, 8);
						else
							SetConsoleTextAttribute(hStdOut, 7);
						GoToXY(x, y++);
						cout << Menu2[i] << endl;
					}
					ch2 = _getch();
					switch (ch2)
					{
					case UP:
						if (--active_menu2 < 0)
							active_menu2 = size(Menu2) - 1;
						break;
					case DOWN:
						if (++active_menu2 > size(Menu2) - 1)
							active_menu2 = 0;
						break;
					case ENTER:
						switch (active_menu2)
						{
						case 0:
							SetConsoleTextAttribute(hStdOut, 8);
							A.set_Card_deb(A.AddPocket());
							cout << "Добавлено!\n";
							system("pause");
							break;
						case 1:
							if (A.getCard_deb().size() > 0)
							{
								SetConsoleTextAttribute(hStdOut, 8);
								A.Popolnenie_Card_deb();
							}
							else
							{
								SetConsoleTextAttribute(hStdOut, 4);
								cout << "Список карт пуст.\n";
							}
							system("pause");
							break;
						case 2:

							if (A.getCard_deb().size() > 0)
							{
								SetConsoleTextAttribute(hStdOut, 8);
								A.Print(A.getCard_deb());
							}
							else
							{
								SetConsoleTextAttribute(hStdOut, 4);
								cout << "Список карт пуст.\n";
							}
							system("pause");
							break;
						case 3:
							if (!A.getCard_deb().empty())
							{
								SetConsoleTextAttribute(hStdOut, 8);
								A.Pokupka_Card_deb();
							}
							else
							{
								SetConsoleTextAttribute(hStdOut, 4);
								cout << "Список карт пуст.\n";
							}
							system("pause");
							break;
						case 4:
						{
							SetConsoleTextAttribute(hStdOut, 8);
							A.PrintOtch(A.getCard_deb());
							system("pause");
							break;
						}
						case 5:
						{
							if (!A.getCard_deb().empty())
							{
								SetConsoleTextAttribute(hStdOut, 8);
								A.SavetoFile(A.getCard_deb(), 2);
							}
							else
							{
								SetConsoleTextAttribute(hStdOut, 4);
								cout << "Список пуст.\n";
							}
							system("pause");
							break;
						}
						case 6:
						{
							SetConsoleTextAttribute(hStdOut, 8);
							A.TopSumm(A.getCard_deb());
							system("pause");
							break;
						}
						case 7:
							ch2 = 27;
							break;
						}
					}
				}
				system("cls");
				break;
			}
			case 2:
			{
				int active_menu2 = 0;
				char ch2 = 'a';
				while (ch2 != 27)
				{
					x = 32, y = 17;
					system("cls");
					GoToXY(x, y);

					string Menu2[] = { "Добавить карту(кредит)","Пополнить карту(кредит)",
						"Показать список всех карт(кредит)","Сделать покупки",
					"Отчёт о покупках","Сохранение отчёта в файл",
					"Топ 3 максимальных платежей", "Предыдущее меню" };

					for (int i = 0; i < size(Menu2); i++)
					{
						if (i == active_menu2)
							SetConsoleTextAttribute(hStdOut, 8);
						else
							SetConsoleTextAttribute(hStdOut, 7);
						GoToXY(x, y++);
						cout << Menu2[i] << endl;
					}
					ch2 = _getch();
					switch (ch2)
					{
					case UP:
						if (--active_menu2 < 0)
							active_menu2 = size(Menu2) - 1;
						break;
					case DOWN:
						if (++active_menu2 > size(Menu2) - 1)
							active_menu2 = 0;
						break;
					case ENTER:
						switch (active_menu2)
						{
						case 0:
							SetConsoleTextAttribute(hStdOut, 8);
							A.set_Card_credit(A.AddPocket());
							cout << "Добавлено!\n";
							system("pause");
							break;
						case 1:
							if (A.getCard_credit().size() > 0)
							{
								SetConsoleTextAttribute(hStdOut, 8);
								A.Popolnenie_Card_credit();
							}
							else
							{
								SetConsoleTextAttribute(hStdOut, 4);
								cout << "Список карт пуст.\n";
							}
							system("pause");
							break;
						case 2:

							if (A.getCard_credit().size() > 0)
							{
								SetConsoleTextAttribute(hStdOut, 8);
								A.Print(A.getCard_credit());
							}
							else
							{
								SetConsoleTextAttribute(hStdOut, 4);
								cout << "Список карт пуст.\n";
							}
							system("pause");
							break;
						case 3:
							if (!A.getCard_credit().empty())
							{
								SetConsoleTextAttribute(hStdOut, 8);
								A.Pokupka_Card_credit();
							}
							else
							{
								SetConsoleTextAttribute(hStdOut, 4);
								cout << "Список карт пуст.\n";
							}
							system("pause");
							break;
						case 4:
						{
							SetConsoleTextAttribute(hStdOut, 8);
							A.PrintOtch(A.getCard_credit());
							system("pause");
							break;
						}
						case 5:
						{
							if (!A.getCard_credit().empty())
							{
								SetConsoleTextAttribute(hStdOut, 8);
								A.SavetoFile(A.getCard_credit(), 3);
							}
							else
							{
								SetConsoleTextAttribute(hStdOut, 4);
								cout << "Список пуст.\n";
							}
							system("pause");
							break;
						}
						case 6:
						{
							SetConsoleTextAttribute(hStdOut, 8);
							A.TopSumm(A.getCard_credit());
							system("pause");
							break;
						}
						case 7:
							ch2 = 27;
							break;
						}
					}
				}
				system("cls");
				break;
			}
			case 3:
				exit(0);
			}

		}
	}
}