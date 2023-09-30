#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <vector>

using namespace std;

// Абстрактные объекты любого из приютов:

class Abstract_obj_1
{
public:
	virtual void info() = 0;
	virtual ~Abstract_obj_1() {}
};
class Abstract_obj_2
{
public:
	virtual void info() = 0;
	virtual ~Abstract_obj_2() {}
};
class Abstract_obj_3
{
public:
	virtual void info() = 0;
	virtual ~Abstract_obj_3() {}
};
class Abstract_obj_4
{
public:
	virtual void info() = 0;
	virtual ~Abstract_obj_4() {}
};
class Abstract_obj_5
{
public:
	virtual void info() = 0;
	virtual ~Abstract_obj_5() {}
};

// Объекты первого приюта:

class obj_f1_1 : public Abstract_obj_1 {
public:
	void info() { cout << "Эгейский котик" << endl; }
};
class obj_f1_2 : public Abstract_obj_2 {
public:
	void info() { cout << "Тойгерский котик" << endl; }
};
class obj_f1_3 : public Abstract_obj_3 {
public:
	void info() { cout << "Сибирский котик" << endl; }
};
class obj_f1_4 : public Abstract_obj_4 {
public:
	void info() { cout << "Персидский котик" << endl; }
};
class obj_f1_5 : public Abstract_obj_5 {
public:
	void info() { cout << "Домашний котик" << endl; }
};

// Объекты второго приюта:

class obj_f2_1 : public Abstract_obj_1 {
public:
	void info() { cout << "Британский котик" << endl; }
};
class obj_f2_2 : public Abstract_obj_2 {
public:
	void info() { cout << "Бразильский котик" << endl; }
};
class obj_f2_3 : public Abstract_obj_3 {
public:
	void info() { cout << "Американский котик" << endl; }
};
class obj_f2_4 : public Abstract_obj_4 {
public:
	void info() { cout << "Австралийский котик" << endl; }
};
class obj_f2_5 : public Abstract_obj_5 {
public:
	void info() { cout << "Азиатский котик" << endl; }
};

// Абстрактная фабрика для производства объектов:

class Abstract_Factory
{
public:
	int   korm, voda;
	virtual Abstract_obj_1* create_obj_1() = 0;
	virtual Abstract_obj_2* create_obj_2() = 0;
	virtual Abstract_obj_3* create_obj_3() = 0;
	virtual Abstract_obj_4* create_obj_4() = 0;
	virtual Abstract_obj_5* create_obj_5() = 0;
	Abstract_Factory() { korm = 1500; voda = 1050; }
	virtual ~Abstract_Factory() {}
};

// Приюты:

class Factory_1 : public Abstract_Factory
{
public:
	Abstract_obj_1* create_obj_1() {
		korm -= 100; voda -= 50;
		return new obj_f1_1;
	}
	Abstract_obj_2* create_obj_2() {
		korm -= 100; voda -= 50;
		return new obj_f1_2;
	}
	Abstract_obj_3* create_obj_3() {
		korm -= 100; voda -= 50;
		return new obj_f1_3;
	}
	Abstract_obj_4* create_obj_4() {
		korm -= 100; voda -= 50;
		return new obj_f1_4;
	}
	Abstract_obj_5* create_obj_5() {
		korm -= 100; voda -= 50;
		return new obj_f1_5;
	}
};

class Factory_2 : public Abstract_Factory
{
public:
	Abstract_obj_1* create_obj_1() {
		korm -= 80; voda -= 40;
		return new obj_f2_1;
	}
	Abstract_obj_2* create_obj_2() {
		korm -= 80; voda -= 40;
		return new obj_f2_2;
	}
	Abstract_obj_3* create_obj_3() {
		korm -= 80; voda -= 40;
		return new obj_f2_3;
	}
	Abstract_obj_4* create_obj_4() {
		korm -= 80; voda -= 40;
		return new obj_f2_4;
	}
	Abstract_obj_5* create_obj_5() {
		korm -= 80; voda -= 40;
		return new obj_f2_5;
	}
};

// Класс, содержащий все объекты того или иного приюта:

class Baza
{
public:
	~Baza() {
		int i;
		for (i = 0; i < obj1.size(); ++i) delete obj1[i];
		for (i = 0; i < obj2.size(); ++i) delete obj2[i];
		for (i = 0; i < obj3.size(); ++i) delete obj3[i];
		for (i = 0; i < obj4.size(); ++i) delete obj4[i];
		for (i = 0; i < obj5.size(); ++i) delete obj5[i];
	}
	void info() {
		int i;
		for (i = 0; i < obj1.size(); ++i) obj1[i]->info();
		for (i = 0; i < obj2.size(); ++i) obj2[i]->info();
		for (i = 0; i < obj3.size(); ++i) obj3[i]->info();
		for (i = 0; i < obj4.size(); ++i) obj4[i]->info();
		for (i = 0; i < obj5.size(); ++i) obj5[i]->info();
	}
	vector<Abstract_obj_1*> obj1;
	vector<Abstract_obj_2*> obj2;
	vector<Abstract_obj_3*> obj3;
	vector<Abstract_obj_4*> obj4;
	vector<Abstract_obj_5*> obj5;
};

// Тут создается база того или иного приюта:

class Create_Baza

{

public:

	Baza* createBaza(Abstract_Factory& factory) {

		Baza* p = new Baza;

		for (int i = 0; i < 1; i++) {

			p->obj1.push_back(factory.create_obj_1());
			p->obj2.push_back(factory.create_obj_2());
			p->obj3.push_back(factory.create_obj_3());
			p->obj4.push_back(factory.create_obj_4());
			p->obj5.push_back(factory.create_obj_5());
		}
		return p;
	}
};

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleOutputCP(1251);
	Create_Baza Facto_ry;
	Factory_1 fact1; Baza* ABS = Facto_ry.createBaza(fact1);
	Factory_2 fact2; Baza* SW = Facto_ry.createBaza(fact2);
	int key = 1, key2 = 1, key3 = 1;
	do {
		switch (key) {
		case 1: A:
		while (key != 5) {
			cout << "\nПриют #1\n\nИнформация:\nВискас: " << fact1.korm << " единиц." << "\nВодичка: " << fact1.voda << " единиц." << "\n\nКотики в приюте:\n"; ABS->info();
			cout << "\nМеню:\n1. Купить котика;\n2. Продать котика;\n3. Обмен котиков;\n4. Другой приют;\n5. Выход.\n\nЗаметка:\nПри вводе некорректных данных у вас будет открываться главное меню выбранного приюта без всяческих изменений =)\n" << endl;
			fflush(stdin);
			cin >> key;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(32767, '\n');
				key = 666;
			}
			system("cls");
			switch (key) {
			case 1: {
				printf("Выберите котика для покупки:\n\n1: Эгейский котик \n2: Тойгерский котик \n3: Сибирский котик \n4: Персидский котик \n5: Домашний котик \n\n");
				fflush(stdin);
				cin >> key2;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(32767, '\n');
					key2 = 666;
				}
				system("cls");
				switch (key2) {
				case 1:
					if (fact1.korm >= 100 && fact1.voda >= 50 && key2 == 1) {
						ABS->obj1.push_back(fact1.create_obj_1());
					}
					else printf("Нет ресурсов =(");
					break;
				case 2:
					if (fact1.korm >= 100 && fact1.voda >= 50 && key2 == 2) {
						ABS->obj2.push_back(fact1.create_obj_2());
					}
					else printf("Нет ресурсов =(");
					break;
				case 3:
					if (fact1.korm >= 100 && fact1.voda >= 50 && key2 == 3) {
						ABS->obj3.push_back(fact1.create_obj_3());
					}
					else printf("Нет ресурсов =(");
					break;
				case 4:
					if (fact1.korm >= 100 && fact1.voda >= 50 && key2 == 4) {
						ABS->obj4.push_back(fact1.create_obj_4());
					}
					else printf("Нет ресурсов =(");
					break;
				case 5:
					if (fact1.korm >= 100 && fact1.voda >= 50 && key2 == 5) {
						ABS->obj5.push_back(fact1.create_obj_5());
					}
					else printf("Нет ресурсов =(");
					break;
				}
				break;
			}
			case 2:
				if (ABS->obj1.size() > 0) {
					ABS->obj1.pop_back();
					fact1.korm += 100;
					fact1.voda += 50;
				}
				else if (ABS->obj2.size() > 0) {
					ABS->obj2.pop_back();
					fact1.korm += 100;
					fact1.voda += 50;
				}
				else if (ABS->obj3.size() > 0) {
					ABS->obj3.pop_back();
					fact1.korm += 100;
					fact1.voda += 50;
				}
				else if (ABS->obj4.size() > 0) {
					ABS->obj4.pop_back();
					fact1.korm += 100;
					fact1.voda += 50;
				}
				else if (ABS->obj5.size() > 0) {
					ABS->obj5.pop_back();
					fact1.korm += 100;
					fact1.voda += 50;
				}
				else printf("Все котики проданы =)"); 
				break;
			case 3:
				cout << "Выберите, какой обмен хотите совершить:\n\n" << "Заметка:\nЕсли в приютах одинаковые породы котиков, то приюты обмениваються одинаковыми котиками, но разным их количеством =)\n\n" << 
					"1: Эгейские котики > Британские котики\n   Эгейские котики < Британские котики\n" << "2: Тойгерские котики > Бразильские котики\n   Тойгерские котики < Бразильские котики\n" <<
					"3: Сибирские котики > Американские котики\n   Сибирские котики < Американские котики\n" << "4: Персидские котики > Австралийские котики\n   Персидские котики < Австралийские котики\n" <<
					"5: Домашние котики > Азиатские котики\n   Домашние котики < Азиатские котики\n" << endl;
				fflush(stdin);
				cin >> key3;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(32767, '\n');
					key3 = 666;
				}
				system("cls");
				switch (key3) {
				case 1:
					if ((ABS->obj1.size() > 0) && (SW->obj1.size() > 0)) {
						swap(ABS->obj1, SW->obj1);	
					}
					else
					printf("Обмен не возможен =(");
					break;
				case 2:
					if ((ABS->obj2.size() > 0) && (SW->obj2.size() > 0)) {
						swap(ABS->obj2, SW->obj2);
					}
					else
					printf("Обмен не возможен =(");
					break;
				case 3:
					if ((ABS->obj3.size() > 0) && (SW->obj3.size() > 0)) {
						swap(ABS->obj3, SW->obj3);
					}
					else
					printf("Обмен не возможен =(");
					break;
				case 4:
					if ((ABS->obj4.size() > 0) && (SW->obj4.size() > 0)) {
						swap(ABS->obj4, SW->obj4);
					}
					else
					printf("Обмен не возможен =(");
					break;
				case 5:
					if ((ABS->obj5.size() > 0) && (SW->obj5.size() > 0)) {
						swap(ABS->obj5, SW->obj5);
					}
					else
					printf("Обмен не возможен =(");
					break;
				}
				break;
			case 4:
				goto B;
			case 5: break;
			}
		}
		break;

		// Второй приют:

		case 2: B:
		while (key != 5) {
			cout << "\nПриют #2\n\nИнформация:\nВискас: " << fact2.korm << " единиц." << "\nВодичка: " << fact2.voda << " единиц." << "\n\nКотики в приюте:\n"; SW->info();
			cout << "\nМеню:\n1. Купить котика;\n2. Продать котика;\n3. Обмен котиков;\n4. Другой приют;\n5. Выход.\n\nЗаметка:\nПри вводе некорректных данных у вас будет открываться главное меню выбранного приюта без всяческих изменений =)\n" << endl;
			fflush(stdin);
			cin >> key;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(32767, '\n');
				key = 666;
			}
			system("cls");
			switch (key) {
			case 1: {
				printf("Выберите котика для покупки:\n\n1: Британский котик \n2: Бразильский котик \n3: Американский котик \n4: Австралийский котик \n5: Азиатский котик \n\n");
				fflush(stdin);
				cin >> key2;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(32767, '\n');
					key2 = 666;
				}
				system("cls");
				switch (key2) {
				case 1:
					if (fact2.korm >= 80 && fact2.voda >= 40 && key2 == 1) {
						SW->obj1.push_back(fact2.create_obj_1());
					}
					else printf("Нет ресурсов =(");
					break;
				case 2:
					if (fact2.korm >= 80 && fact2.voda >= 40 && key2 == 2) {
						SW->obj2.push_back(fact2.create_obj_2());
					}
					else printf("Нет ресурсов =(");
					break;
				case 3:
					if (fact2.korm >= 80 && fact2.voda >= 40 && key2 == 3) {
						SW->obj3.push_back(fact2.create_obj_3());
					}
					else printf("Нет ресурсов =(");
					break;
				case 4:
					if (fact2.korm >= 80 && fact2.voda >= 40 && key2 == 4) {
						SW->obj4.push_back(fact2.create_obj_4());
					}
					else printf("Нет ресурсов =(");
					break;
				case 5:
					if (fact2.korm >= 80 && fact2.voda >= 40 && key2 == 5) {
						SW->obj5.push_back(fact2.create_obj_5());
					}
					else printf("Нет ресурсов =(");
					break;
				}
				break;
			}
			case 2:
				if (SW->obj1.size() > 0) {
					SW->obj1.pop_back();
					fact2.korm += 80;
					fact2.voda += 40;
				}
				else if (SW->obj2.size() > 0) {
					SW->obj2.pop_back();
					fact2.korm += 80;
					fact2.voda += 40;
				}
				else if (SW->obj3.size() > 0) {
					SW->obj3.pop_back();
					fact2.korm += 80;
					fact2.voda += 40;
				}
				else if (SW->obj4.size() > 0) {
					SW->obj4.pop_back();
					fact2.korm += 80;
					fact2.voda += 40;
				}
				else if (SW->obj5.size() > 0) {
					SW->obj5.pop_back();
					fact2.korm += 80;
					fact2.voda += 40;
				}
				else printf("Все котики проданы =)"); break;
			case 3:
				cout << "Выберите, какой обмен хотите совершить:\n\n" << "Заметка:\nЕсли в приютах одинаковые породы котиков, то приюты обмениваються одинаковыми котиками, но разным их количеством =)\n\n" <<
					"1: Эгейские котики > Британские котики\n   Эгейские котики < Британские котики\n" << "2: Тойгерские котики > Бразильские котики\n   Тойгерские котики < Бразильские котики\n" <<
					"3: Сибирские котики > Американские котики\n   Сибирские котики < Американские котики\n" << "4: Персидские котики > Австралийские котики\n   Персидские котики < Австралийские котики\n" <<
					"5: Домашние котики > Азиатские котики\n   Домашние котики < Азиатские котики\n" << endl;
				fflush(stdin);
				cin >> key3;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(32767, '\n');
					key3 = 666;
				}
				system("cls");
				switch (key3) {
				case 1:
					if ((ABS->obj1.size() > 0) && (SW->obj1.size() > 0)) {
						swap(ABS->obj1, SW->obj1);
					}
					else
						printf("Обмен не возможен =(");
					break;
				case 2:
					if ((ABS->obj2.size() > 0) && (SW->obj2.size() > 0)) {
						swap(ABS->obj2, SW->obj2);
					}
					else
						printf("Обмен не возможен =(");
					break;
				case 3:
					if ((ABS->obj3.size() > 0) && (SW->obj3.size() > 0)) {
						swap(ABS->obj3, SW->obj3);
					}
					else
						printf("Обмен не возможен =(");
					break;
				case 4:
					if ((ABS->obj4.size() > 0) && (SW->obj4.size() > 0)) {
						swap(ABS->obj4, SW->obj4);
					}
					else
						printf("Обмен не возможен =(");
					break;
				case 5:
					if ((ABS->obj5.size() > 0) && (SW->obj5.size() > 0)) {
						swap(ABS->obj5, SW->obj5);
					}
					else
						printf("Обмен не возможен =(");
					break;
				}
				break;
			case 4:
				goto A;
			case 5: break;
			}
		}
		break;
		}
	} while (key != 5);
	return 0;
}