#include <iostream>
#include <vector>
#include "app.hpp"
#include "TaskManager.hpp"
using namespace std;

void run() {
	Task tk;
	bool temp = true;
	while (temp) {
		temp = tk.menu();
	}
}