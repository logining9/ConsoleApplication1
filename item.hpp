#include <iostream>
#include <map> 
#include <vector>
using namespace std;

void run(int ran);

class Item {
private:
	vector <string> b;
	map<int, vector<string>> buys;
	int number = 0;
	string name, status;
public:
	bool menu();
	void new_list();
	void rebild_list();
	void print_list();
	void del();
};