// Michael Sexton
// Problem 3


#include <iostream>
#include <queue>

using namespace std;

class AirTrafficController {
private:
    bool asleep; // Whether the ATC is asleep or not
    int trafficPattern; // Number of aircraft in the traffic pattern

public:
    AirTrafficController() : asleep(true), trafficPattern(0) {}

    // Pilot initiates communication with ATC
    void initiateCommunication(int AircraftNumber) {
        if (asleep) {
            asleep = false;
        }
        cout << "Aircraft #" << AircraftNumber << " is requesting to land" << endl;
    }

    // ATC starts communication with a pilot
    void startCommunication() {
        if (!asleep) {
            cout << "ATC is talking to a pilot." << endl;
        }
    }

    // ATC finishes communication with a pilot
    void finishCommunication(int AircraftNumber) {
        cout << "ATC finished talking to Pilot " << AircraftNumber << "." << endl;
        asleep = true;
    }

    // Check if the traffic pattern is full
    bool isTrafficPatternFull() {
        return trafficPattern >= 3;
    }

    // Add an aircraft to the traffic pattern
    void addAircraft(int AircraftNumber) {
        if (trafficPattern < 3) {
            ++trafficPattern;
            cout << "Aircraft with Pilot " << AircraftNumber << " entered the traffic pattern." << endl;
        }
    }

    // Remove an aircraft from the traffic pattern
    void removeAircraft(int AircraftNumber) {
        if (trafficPattern > 0) {
            --trafficPattern;
            cout << "Aircraft with Pilot " << AircraftNumber << " left the traffic pattern." << endl;
        }
    }
};

int main() {
    AirTrafficController atc;
    queue<int> arrivalTimes; // Arrival times of aircraft

    // Generate arrival times and pilot numbers for 10 aircraft
    for (int i = 1; i <= 10; ++i) {
        arrivalTimes.push(i);
    }

    // Simulation loop
    while (!arrivalTimes.empty()) {
        int currentTime = arrivalTimes.front();
        arrivalTimes.pop();
        cout << "Current time: " << currentTime << "s" << endl;

        // Check if there is an incoming aircraft
        if (!arrivalTimes.empty()) {
            int nextArrival = arrivalTimes.front();
            // If the next arrival is now or after the current time
            if (nextArrival <= currentTime) {
                int AircraftNumber = arrivalTimes.size() + 1; // Assign pilot number
                // Pilot initiates communication
                atc.initiateCommunication(AircraftNumber);

                // If ATC is talking to another pilot, try again later
                if (atc.isTrafficPatternFull()) {
                    cout << "Traffic pattern is full. Aircraft with Pilot " << AircraftNumber << " needs to divert to other airports." << endl;
                }
                else {
                    // Otherwise, add the aircraft to the traffic pattern
                    atc.addAircraft(AircraftNumber);
                }
            }
        }

        // If the ATC finishes talking to a pilot, remove the aircraft from the traffic pattern
        atc.finishCommunication(arrivalTimes.size() + 1);
        atc.removeAircraft(arrivalTimes.size() + 1);

        // Check if all aircraft have arrived
        if (arrivalTimes.empty()) {
            cout << "All aircraft have arrived." << endl;
        }
    }

    return 0;
}