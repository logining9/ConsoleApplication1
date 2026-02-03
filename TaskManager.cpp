#include <iostream>
#include <vector> 
#include <string>
#include <sstream>
#include "TaskManager.hpp"
using namespace std;

string Task::sample(int id) {
	cout << "Название задачи:";
	cin >> name;
	cout << endl << "Текст задачи:";
	cin >> text;
	cout << endl << "Приоритет (от 1 - высокий, до 3 - низкий):";
	cin >> prioritet;
	if (status == "1") { prioritet = "высокий"; }
	else if (status == "2") { prioritet = "средний"; }
	else if (status == "3") { prioritet = "низкий"; }
	else { prioritet = "низкий"; }
	cout << endl << "Период выполнения:";
	cin >> date;
	cout << endl << "Статус(1 - в планах, 2 - в работе, 3 - выполнена):";
	cin >> status;
	cout << endl;
	if (status == "1") { status = "в планах"; }
	else if (status == "2") { status = "в работе"; }
	else if (status == "3") { status = "выполнена"; }
	else { status = "в планах"; }
	return to_string(id) + ": " + "Название задачи: " + name + ";\tТекст задачи: " + text + ";\tПриоритет: " + prioritet + ";\tПериод выполнения: " + date + ";\tСтатус:  " + status;
}

bool Task::menu() {
	cout << "\t\tTask Manager\n1 - Добавить задачу;\n2 - Изменить задачу;\n3 - Посмотреть задачи;\n0 - Выход;" << endl;
	int temp;
	cin >> temp;
	switch (temp) {
	case 1:
		addTask();
		break;
	case 2:
		rebildTask();
		break;
	case 3:
		printTask();
		break;
	case 0:
		return false;
		break;
	}
}
void Task::addTask() {
	id = id + 1;
	string result = sample(id);
	tasks.push_back(result);
}
void Task::rebildTask() {
	cout << "Введите номер задачи для изменения задачи: ";
	int temp;
	try {
		cin >> temp;
		tasks[temp - 1] = sample(temp);
	}
	catch (exception x) {
		cout << "Неверный ввод!" << endl;
	}
}
void Task::printTask() {
	cout << "Записанные задачи (сортировка по дате добавления от старых до новых):" << endl;
	for (string x : tasks)
	{
		cout << x << endl;
	}
}