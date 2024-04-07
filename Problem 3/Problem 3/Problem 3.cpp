// Michael Sexton
// Problem 3

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>

using namespace std;

mutex mtx;
bool ATC_awake = false;
int traffic_pattern = 0;

void ATC() {
    while (true) {
        mtx.lock();
        if (traffic_pattern == 0) {
            cout << "ATC is asleep." << endl;
            ATC_awake = false;
        }
        mtx.unlock();
        this_thread::sleep_for(chrono::seconds(1));
    }
}

void pilot(int id) {
    while (true) {
        mtx.lock();
        if (!ATC_awake) {
            cout << "Aircraft " << id << " is waking up ATC." << endl;
            cout << "Aircraft " << id << " requests landing." << endl;
            ATC_awake = true;
            mtx.unlock();
            this_thread::sleep_for(chrono::seconds(2)); // Simulate communication with ATC
            mtx.lock();
            traffic_pattern++;
            cout << "Aircraft " << id << " enters the traffic pattern." << endl;
            mtx.unlock();
            
        }
        else if (traffic_pattern < 3) {
            cout << "Aircraft " << id << " requests landing." << endl;
            cout << "Aircraft " << id << " enters the traffic pattern." << endl;
            traffic_pattern++;
            mtx.unlock();
            
        }
        else {
            cout << "Aircraft " << id << " requests landing." << endl;
            cout << "Aircraft " << id << " needs to divert to other airports." << endl;
            mtx.unlock();
            break;
        }
        this_thread::sleep_for(chrono::seconds(2));
    }
}

int main() {
    traffic_pattern = 0; // Initialize traffic pattern as empty
    thread ATC_thread(ATC);
    vector<thread> aircraft_threads;
    for (int i = 0; i < 10; ++i) {
        aircraft_threads.push_back(thread(pilot, i + 1));
    }
    for (int i = 0; i < 10; ++i) {
        aircraft_threads[i].join();
    }
    ATC_thread.join();
    return 0;
}