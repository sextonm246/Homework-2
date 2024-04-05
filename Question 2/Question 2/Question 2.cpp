// Michael Sexton
// Homework 2

#include<iostream>
#include<vector>

using namespace std;

int main() {
	int time = 0;
	string robotstatus1; string robotstatus2;
	int robotnumber1 = 1; int robotnumber2=4;

	while (robotnumber1 < 3) {
		cout << "Robot " << robotnumber1 << " acquired tools and started performing a task." << endl;
		cout << "Robot " << robotnumber2 << " acquired tools and started performing a task." << endl;
		time = time + 1; 

		cout << "Robot " << robotnumber1 << " has finished the task and is returning the tools." << endl;
		cout << "Robot " << robotnumber2 << " has finished the task and is returning the tools." << endl;
		time = time + 5;

		robotnumber1++; robotnumber2++;
	}

	if (robotnumber1 == 3) {
		cout << "Robot " << robotnumber1 << " acquired tools and started performing a task." << endl;
		time = time + 1;

		cout << "Robot " << robotnumber1 << " has finished the task and is returning the tools." << endl;
		time = time + 5;
	}

	cout << "Duration: " << time << " seconds." << endl;

	return 0;
}