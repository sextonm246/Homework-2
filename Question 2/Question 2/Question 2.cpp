// Michael Sexton
// Homework 2

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

mutex mtx;

// Function to simulate the task performed by a robot
void performTask(int robotNumber, vector<bool>& tools, int& time) {
    {
        unique_lock<mutex> lock(mtx);
        cout << "Robot " << robotNumber << " is collecting data." << endl;
    }

    int leftToolIndex = (robotNumber + 3) % 5; // left tool
    int rightToolIndex = (robotNumber + 2) % 5; // right tool

    // Acquire tools
    {
        unique_lock<mutex> lock(mtx);
        while (!tools[leftToolIndex] || !tools[rightToolIndex]) {
            // Wait until both tools are available
        }
        tools[leftToolIndex] = false;
        tools[rightToolIndex] = false;
        cout << "Robot " << robotNumber << " acquired tools and started performing a task." << endl;
        if (robotNumber == 1 || robotNumber == 2 || robotNumber == 5) {
            time += 1; // Increase time by 1 for picking up tools
        }
    }

    // Return tools
    {
        unique_lock<mutex> lock(mtx);
        tools[leftToolIndex] = true;
        tools[rightToolIndex] = true;
        cout << "Robot " << robotNumber << " finished the task and returning tools." << endl;
        if (robotNumber == 1 || robotNumber == 2 || robotNumber == 5) {
            time += 5; // Increase time by 5 for completing the task
        }
    }
}

int main() {
    vector<bool> tools(5, true); // Initially, all tools are available
    int time = 0; // Initialize time counter 

    // Robots 1 and 3 work simultaneously
    thread t1(performTask, 1, ref(tools), ref(time));
    // Robots 2 and 4 work simultaneously
    thread t2(performTask, 2, ref(tools), ref(time));
    // Robot 3 works (with 1)
    thread t3(performTask, 3, ref(tools), ref(time));
    // Robot 4 works (with 2)
    thread t4(performTask, 4, ref(tools), ref(time));
    // Robot 5 works
    thread t5(performTask, 5, ref(tools), ref(time));

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    cout << "Total time: " << time << endl;

    return 0;
}