#include <iostream>
#include <string>
#include <conio.h>
#include <ctime>
using namespace std;

int hp, food, cash, dmg, armor, sum;
int enemy_dmg, enemy_hp, enemy_armor, enemy_sum;
int potion_price, food_price, armor_price, armor_type_price, armor_amount, gold;
int info;

bool news[3], cave_visited = false, cave_ready = false;

string answer, name, enemy_name, armor_type_string;

void v() {
	cout << "����� ���������� � Game of Storm! ����, � ������� �� ���� ������� ���� ������!" << endl;
	cout << "[����� ����� ����� �������]" << endl << endl;
	_getch();
	cout << "������ �����, � ������ ��������: \"������ �� �� � ������������ ������������, ������� ������� ���?\"" << endl;
	cout << "1 - ���� ��" << endl;
	cout << "2 - ���� ���" << endl;
	
	cin >> answer;
	while ((answer != "1") && (answer != "2"))
	{
		cout << "����� ��� ��������� �������!" << endl;
		cin >> answer;
	}
	
	if (answer == "2")
	{
		cout << "������. ����� � ������ ���..." << endl << endl;
		_getch();
		exit(0);
	}
	cout << "������� ������, �������, ��� �, ��������, ������ ��� ���!" << endl;
	cout << "[�������� ���� ���, ������� ������ ����������� ���������]" << endl;
	cin >> name;
	cout << "� �� ���� ��� �� ������, �� ������, " << name << ", ����� ���������� � �������!" << endl << endl;
	cout << "--------------------------------------------------------------------------------" << endl << endl;
}

void trade() { //����� ��������� �� �������� ��������� ���-�� �����!
	cout << "{��������: ������� �� ��� ������, �������! ��� ��� �������� �����������.}" << endl << endl;
	
	potion_price = rand() % 4 + 10;
	food_price = rand() % 4 + 20;
	armor_price = rand() % 4 + armor_type_price;

	
	answer = "5";
	while (answer != "0")
	{
		cout << endl << "�� ������ ������ � ��� " << cash << " ������." << endl << endl;

		cout << "1 - �������� ����� (+4 ��. ��������, ����. 10) [" << potion_price << " �������]" << endl;
		cout << "2 - ����� ���� (+3 ������� ����) [" << food_price << " �������]" << endl;
		cout << "3 - " << armor_type_string << " ����� (������ = " << armor_amount << ") [" << armor_price << " �������]" << endl;
		cout << "0 - ����" << endl;
		
		cin >> answer;
		while ((answer != "1") && (answer != "2") && (answer != "3") && (answer != "0"))
		{
			cout << "����������, �������� ���� �� ���������." << endl;
			cin >> answer;
		}
		
		if (answer == "1")
		{
			if (cash < potion_price)
				cout << "{��������: ����, �������! ������, � ���� ��� ����� �����!}" << endl;
			else
			{
				if (hp == 10)
					cout << "{��������: " << name << ", �� ����? �� � ��� ��������� ������! ���� ���-����� ��������!}" << endl;
				else if ((hp > 6) && (hp < 10))
				{
					hp = 10;
					cash = cash - potion_price;
					cout << "{��������: �! ������� ������������! ���-������ ���?}" << endl;
				}
				else
				{
					hp += 4;
					cash -= potion_price;
					cout << "{��������: �! ������� ������������! ���-������ ���?}" << endl;
				}
			}
		}
		else if (answer == "2")
		{
			if (cash < food_price)
				cout << "{��������: ����, �������! ������, � ���� ��� ����� �����!}" << endl;
			else
			{
				food += 3;
				cash -= food_price;
				cout << "{��������: �! ������� ������������! ���-������ ���?}" << endl;
			}
		}
		else if (answer == "3")
		{
			if (cash < armor_price)
				cout << "{��������: ����, �������! ������, � ���� ��� ����� �����!}" << endl;
			else
			{
				armor += armor_amount;
				cash -= armor_price;
				cout << "{��������: �! ������� ������������! ���-������ ���?}" << endl;
			}
		}
	}
	cout << "��, ����� �� �������!" << endl;
	cout << "���� ���������: �������� = " << hp << ", ����� = " << armor << ", ���� = " << food << "." << endl;
}

void battle() { //����� ���� �� �������� ������� ���-�� �����!
	gold = rand() % 15;
	
	cout << enemy_name << ". ���� = " << enemy_dmg << ". �������� = " << enemy_hp << ". ������ = " << enemy_armor << "." << endl;
	cout << name << ". ���� = " << dmg << ". �������� = " << hp << ". �����a = " << armor << "." << endl;
	cout << "[��� ������ ������?]" << endl << endl;
	cout << "[1 - �����; 2 - ������.]" << endl;
	
	cin >> answer;
	while ((answer != "1") && (answer != "2"))
	{
		cout << "1 ��� 2" << endl;
		cin >> answer;
	}
	
	if (answer == "2")
	{
		food -= 3;
		if (food <= 0)
		{
			cout << "�� �������. � ��� ����������� ��� �������. ���� ��������." << endl << endl;
			_getch();
			exit(0);
		}
	}
	else
	{
		sum = hp + armor;
		enemy_sum = enemy_hp + enemy_armor;
		
		while ((sum > 0) && (enemy_sum > 0))
		{
			sum -= enemy_dmg;
			enemy_sum -= dmg;
		}
		
		if (sum == 0)
		{
			cout << "�� �������. " << enemy_name << " ���� ���. ���� ��������." << endl << endl;
			_getch();
			exit(0);
		}
		else
		{
			cout << "�� ��������!. " << enemy_name << " ����." << endl;
			
			if (sum <= hp)
			{
				hp = sum;
				armor = 0;
			}
			else
				armor = sum - hp;
			
			cout << "���� ��������� ����� ���: �������� = " << hp << ", ����� = " << armor << "." << endl;
			cash += gold;
			cout << "����� �� �������� " << gold << " ������! ������ � ��� " << cash << " �������!" << endl << endl;
		}
	}
}

void w1() {
	cout << "�� ������������ �� ������� �������� ����. ������, ����� ���� ������. ����, ���� �� ����, ��� �� ��������� � ������, ��� ����� � �� �������." << endl << endl;
	_getch();
	cout << "������ ������� �������� ������. ������ ��� ���� ��� �� ��������." << endl << endl;
	_getch();
	cout << "��� �� �������, �� ������������� � ����� ������ ������ ��������� ���." << endl << endl;
	_getch();
	cout << "[� Game of Storm ��� ����� ����� ���������� ���� ������ � ���� ������� �����." << 
		" �� ������ ������ ���� ������ - ��������� ���. ������ ������ ����� ����, � ������ ����� ����� ������." << 
		" ������ ���� ����� ����� 0, � ��� ���� ����� 1.]" << endl << endl;
	_getch();
	cout << "�������� ������, �� ����������� ���� ������ �� ������ ��������� ������." << 
			" �� �������� �� ���� ����� � ���. ������ � ��� ���� ��� ����. ���� �� �� �����������?" << endl;
	cout << "[������� 1 - ������ (1 ������� ����) ��� 2 - ������� (2 ������� ����)]" << endl;
	cin >> answer;
}

void peshera() {
	cout << "����� � ����� ���� ������, �� ����� ��������� �������� ����� � ������������� � �������." << 
		" ������ � ������ �� ��� �����. �� ��������� � �����, ��� ���� ������ ��������� ������� ������" <<
		" � �������� ��������� �������: 4 ��������� �������� ����� � ������������ �� ��� ������, �������, ���� � �����." << 
		" ������ �� ������� ����� ��������. ����� �� ������ �������, � �� ��� ������� ��� ������ � ������� ������." << 
		" ��� ������ �� ��� �� ����������. ������ ����� ���-�� ������� � �������..." << endl << endl;
	_getch();
	cout << "[������� ������� ������. �������� � ������� ����� ������ �����: medved, lisa, volk, sokol.]" << endl;
	cout << "[0 - ����]" << endl << endl;
	getline(cin, answer);

	while ((answer != "0") && (answer != "lisa volk medved sokol"))
	{
		cout << "������ �� ����������. ����� ���-�� �� ���? ������ ������: \"volk sokol medved lisa\"" << endl;
		getline(cin, answer);
	}

	if (answer == "lisa volk medved sokol")
	{
		cave_visited = true;
		cout << "����������! �� ������� �������, �������� ������� ��� ������ � 50 �������, ������ ����� � � �������! �����������!" << endl;
		_getch();
		dmg = 4;
		cash += 50;
	}
}

void inf1() {
	news[0] = true;
	cout << "{������: � �����, ���� ������ ���������, ������� ������� ������ �� ������-�� �����, �������� � ���� ��� ���� � ��������� � ������." << 
		" ������ �����, ��� ��� ��� ��� ���������� � ����� ������, ������ �� �� �����, � ����� ������. ����� ��� ������� �������!}" << endl;
}

void inf2() {
	news[1] = true;
	cout << "{������: ��� ������ � ���� ����� ���� ��������, � ������, ���������, �������� ���� ����� ��������, ���������� �� ���� ������." << 
		" �� �� ����� ��� ������������ ����.}" << endl;
}

void inf3() {
	news[2] = true;
	cout << "{������: ���, �� ������, ��� � ����� ������ ���� �������� ��� ���, � ���, ������ �������� ������ �� ���� �����, �������� ����������� ���������!" << 
		" �, ������, ������� �������, � ���, ������� ������, �������! �� � � ��� ������� ������ ���!}" << endl;
}

void inf4() {
	cave_ready = true;
	news[0] = true;
	cout << "{������: �����, �� �� ��������! ����� ������, ��� ����� ��������� � ������ ������� � �������� \"������ �������\" ���� ���� � ������." <<
		" ������ ��, � ����� ������� �������, �� ������� ��� ���� ��������." << 
		" ��� �� �� ��� ���������� ����, ����� ����, ����� �������, �� � ����� ������� ����������..." << 
		" ��� �� ��� ������ ��� �� ������, ������� � ������ ������ ������, �� ���� �� ��������� ���� �����, ��������� ��� ���� �������!}" << endl;
}

void left() {
	food--;
	cout << "������ ��� ���� �� ������. ��� ������� ������� ������� ��������� � �� ����������� � ���, ������� ���" << endl;
	cout << "����������� � ������ �������, �� ��������� ��������, �������� �������. �� ��������� � �������� ��������." << endl << endl;
}

void taverna() {
	if (!cave_visited)
		info = rand() % 3 + 1;
	else
		info = rand() % 2 + 1;

	armor_type_string = "�������";
	armor_amount = 5;
	armor_type_price = 50;

	cout << "���� �� �� �������� � ���������, ��� ��������� ������� � ������� ���� �� ���������." <<
		" ����� ���� � ������� ���� ����, ���������� �����-�� ���������� �����, � ��������� �������, ������ ������ ���������� �����." << endl << endl;
	_getch();
	cout << "�� ��������� � ������� � �������� � ��� ��������." << endl << endl;
	_getch();
	cout << "{������: ����������� ���� � ���� �������, ��������! �� ������ ������� � �����? ��� ����� ���� ����� ���-�� ���������?}" << endl;
	cout << "{" << name << ": ���� �����-������ �������?}" << endl << endl;
	_getch();
	cout << "{������: ���, ��, ����� ����� ������ �����...}" << endl;

	if (info == 1)
		inf1();
	if (info == 2)
		inf2();
	if (info == 3)
		inf3();
	if (info == 4)
		inf4();

	while (answer != "0")
	{
		cout << endl << "{������: ���-������ ���?}" << endl << endl;
		cout << "1 - {����� � �����!} [������ � �����]" << endl;
		cout << "2 - {��, ������ ��� � ���� ����.} [��������]" << endl;
		cout << "0 - {����� ��� ��� ��������� ����� � ������� ���������.} [���� �� �������]" << endl;
		cin >> answer;
		if (answer == "1")
			cout << "[�� �����������.]" << endl;
		if (answer == "2")
			trade();
	}

	cout << "{������: ���, �����. ����� ���� � ����� �����������, " << name << "!}" << endl;

	if ((cave_ready) && (!cave_visited))
	{
		cout << "������ �� ����� �������� ����� ����� �� �����! ����������� ���� ������?" << endl;
		cout << "[1 - �� (2 ������� ���� ���� �������); 2 - ��� (���� �� �������)]" << endl;
		
		cin >> answer;
		while ((answer != "1") && (answer != "2"))
		{
			cout << "����������, �������� ���� �� ���������." << endl;
			cin >> answer;
		}
		
		if (answer == "1")
		{
			food--;
			if (food <= 0)
			{
				cout << "�� �������. � ��� ����������� ��� �������. ���� ��������." << endl << endl;
				_getch();
				exit(0);
			}
			
			cout << "����, �� ��������� ������� � ������������� � ������." << endl;
			cout << "���������� �� ���������� �� ������ ����. �� ����, �� ����������� ������ ������, �� ������� �������� �����." << endl;
			peshera();
			
			food--;
			if (food <= 0)
			{
				cout << "�� �������. � ��� ����������� ��� �������. ���� ��������." << endl << endl;
				_getch();
				exit(0);
			}
		}
	}
	
	cout << endl << "���������, " << name << ", ���� ��� ��� ��������� ��� =)" << 
		" �������� MIF-Technologic ���������� ���� �� ���� ����� ���� \"Game of Storm\"!" << 
		" ���������� �� ��������� � ���, ���� � ������� ��� ��� �� ����� ������ ������ ���� ����, �� ����� � ����� ���������� �������!" << 
		" �����, �� ����� ������ � ���� ���!" << endl << endl;
}

void naemnik() {
	cout << "{������: �! �� �������! �� � ����� � ����!}" << endl;
	cout << "[�������� ������� ������]" << endl;
	cout << "1 - {�� �������?}" << endl;
	cout << "2 - {��� ��� �� �������� ���� � ������! �� ��, ���������!} [������� �� �������]" << endl;
	
	cin >> answer;
	while ((answer != "1") && (answer != "2"))
	{
		cout << "1 ��� 2" << endl;
		cin >> answer;
	}
	
	if (answer == "2")
	{
		cout << "[����� ���������� � �������� ������ ������� Game of Storm!" << 
			" ������� � �������: � ���� ������� ������� ���� ����, �������� � ������." << 
			" �� ������� �� ������ ���� �������� � ��������� � ���. �� ���������, ���� ��������, ��� ��������� �������!" << 
			" ���� �� �� �� ������, �� �������� �������������� ���� � ������ �����." << 
			" �� ������ �������� ���� ����� ���� ������ �������, ���� ���-�� �� �����." << 
			" ������ � ���� ��� �� ������ �� ���������, �� ��������� 3 ������� ����. ������ ������ ����� �������!]" << endl << endl;
		
		enemy_dmg = 2;
		enemy_hp = 2;
		enemy_armor = 1;
		enemy_name = "������";
		battle();
		
		dmg = 2;
		cout << "���� �������, �� �������� �������� ��� �������! ��� ���� ����� ���� 2. ������ � �������!" << endl;
		
		taverna();
	}
	else
	{
		news[0] = true;
		cout << "{������: ���, � �����, ��� ������� ��������� ���� � ������, � ����� ������, ������� � ���� ����������!" << 
			" �� �������, �������, ��� �� �������. �� ����������� � ��������, ����� ��� ���� ������...}" << endl;
		cout << "1 - {������� ����, �������!}" << endl;
		cout << "2 - {������ �� �� ���� ��?}" << endl;
		
		cin >> answer;
		while ((answer != "1") && (answer != "2"))
		{
			cout << "1 ��� 2" << endl;
			cin >> answer;
		}
		
		if (answer == "2")
		{
			cout << "{������: ��! �� ���� ������� �����, � � ���� ���� ����! ��� �� � �������������...}" << endl;
			cout << "1 - {������� ����, �������!}" << endl << endl;
		}

		cout << "{������: ��� ������!}" << endl;
		cout << "������ � �������!" << endl;
	}
}

int main() {
	
	setlocale(0, "");

	srand(time(0));
	
	hp = 10;
	for (int i = 0; i < 3; i++)
		news[i] = false;
	food = 3;
	cash = 25;
	dmg = 1;
	armor = 0;
	
	v();
	w1();
	
	while ((answer != "1") && (answer != "2"))
	{
		cout << "1 ��� 2" << endl;
		cin >> answer;
	}
	
	cout << "[� Game of Storm ������ ��� ����� ������ �� ���������� �������� ����, ������� ��������� � ����.]" << endl << endl;
	_getch();
	cout << "��������� ��������� ����������, �� ������� �������� ��������� ������ � ����������, ����� � ��� �������� ��� ��� ���� �� ���." << endl << endl;
	_getch();
	cout << "[� Game of Storm ������ ���� ����������� �� ��������� ������� ������� ������������ ���-�� ����." <<
		" ���� �� �������� �� ����� ����� ��� ���, �� ��� ����� ��������. ������ ���-�� ���� ����� ����, ���� ���� �� ���� ������, � 1, ���� �������.]" << endl << endl;
	_getch();

	if (answer == "1")
	{
		left();
		naemnik();
		taverna();
	}
	else
	{
		food--;
		
		cout << "������ ��� ��������� � �����. ��� ������� ��������� �������������� ��������, �� ������������, � ������� ������ ������� ��������, � ���������� � ���." << endl;
		
		armor_type_string = "�����";
		armor_amount = 2;
		armor_type_price = 20;
		trade();
		
		cout << "����� �������� ��� ������� �� ����, �� ��� ������� ����, �������� �������." << endl;
		
		enemy_dmg = 1;
		enemy_hp = 2;
		enemy_armor = 0;
		enemy_name = "����";
		
		battle();

		if (answer == "2")
		{
			cout << "�� ������ ����� ������ �� ������������� ��� ����� � ���� �� �������� ��� ��������� ���� �������� � ��������� ����� �����-�� ������." << endl << endl;
			_getch();
			cout << "�� ������� ����� �������. �������� �� ���� ������� ������ ����, �� ����� � ���� ��������." << endl << endl;
			_getch();
			naemnik();
			taverna();
		}
		else
		{
			cout << "��������� ����� �� ���� ������, �������� �� ������ �� ���� ��� 2 ������� ����." << endl << endl;	
			_getch();
			cout << "���������� �� ���������� �� ������ ����. �� ����� ����, �� ����������� ������ ������, �� ������� �������� �����. ������ ����� ��������� ������." << endl << endl;
			_getch();
			cout << "������ ���� ���� - ����� �� �������� � ��?" << endl;
			cout << "[1 - ��; 2 - ���]" << endl;
			
			cin >> answer;

			while ((answer != "1") && (answer != "2"))
			{
				cout << "1 ��� 2" << endl;
				cin >> answer;
			}

			if (answer == "1")
			{
				peshera();
				cout << "��������� ���� � ������ ��� ��������� ����������, �� ��������� ����� ������� � ������������� � ���." << endl << endl;
				_getch();
				cout << "������� � �����, �� ������� ������� \"������ �������\". � �������� �� ���� �� �������� � ������." << endl << endl;
				_getch();
				taverna();
			}
		}
	}

	_getch();
	return 0;
}