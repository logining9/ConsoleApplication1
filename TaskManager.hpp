#include <iostream>
#include <vector> 
using namespace std;
class Task {
private:
	vector<string> tasks;
	string name, text, prioritet, date, status;
	int id = 0;
	string sample(int id);
public:
	bool menu();
	void addTask();
	void rebildTask();
	void printTask();
};