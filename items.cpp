#include <iostream>
#include <map> 
#include <vector>
#include "item.hpp"
using namespace std;

void run(int ran) {
	bool ran = true;
	Item abc;
	while (ran) {
		ran = abc.menu();
	}
}

bool Item::menu() {
	cout << "\t\tshopping list\t\t" << endl;
	cout << "1 - Создать новый список;\n2 - изменить статус продукта;\n3 - показать список;\n4 - удалить проукт;\n0 - выход;" << endl;
	int temp;
	try {
		cin >> temp;
		switch (temp) {
		case 1:
			new_list();
			break;
		case 2:
			rebild_list();
			break;
		case 3:
			print_list();
			break;
		case 4:
			del();
			break;
		case 0:
			return false;
			break;
		default:
			cout << "Такого пункта нет!" << endl;
			break;
		}
	}
	catch (exception x) {
		cout << "Неверный ввод!" << endl;
	}
}

void Item::new_list() {
	cout << "Если существовал старый список, то он будет атоматически удалён!" << endl;
	cout << "Хотите продолжить?(Да/Нет)";
	string temp;
	cin >> temp;
	if (temp == "да" || temp == "Да" || temp == "Д" || temp == "д") {
		if (buys.empty()) {
			buys.clear();
			number = 0;
		}
		number = number + 1;
		status = "Не куплен";
		cout << "Введите название продукта/товара:";
		cin >> name;
		if (b.empty()) {
			b.clear();
		}
		b.push_back(name);
		b.push_back(status);
		buys[number] = b;
	}
}
void Item::print_list() {
	cout << "\t\tСписок покупок:\t\t" << endl;
	for (auto elm : buys) {
		string temp;
		for (auto elem : elm.second) {
			temp = temp + elem;
		}
		cout << elm.first << " - " << temp << endl;
	}
}
void Item::rebild_list() {
	cout << "Введите номер продукта для изменения его статуса:";
	int num;
	cin >> num;
	cout << "\nВведите его статус:";
	cin >> status;
	for (auto elm : buys) {
		if (num-1 == elm.first) {
			elm.second.pop_back();
			elm.second.push_back(status);
		}
	}
}
void Item::del() {
	cout << "Введите номер продукта для его удаления:";
	int num;
	cin >> num;
	buys.erase(num - 1);
}