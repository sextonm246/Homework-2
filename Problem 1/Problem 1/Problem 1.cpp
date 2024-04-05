// Michael Sexton
// Problem 1


#include <iostream>
#include <string>
#include <vector>

// Abstract base class Sensor
class Sensor {
public:
    virtual void gatherData() = 0;
    virtual void processData() = 0;
    virtual ~Sensor() {} 
};

// Classes for three different types of sensors
class StaticPressureSensor : public Sensor {
public:
    void gatherData() override {
        std::cout << "Gathering data from Static Pressure Sensor." << std::endl;
    }

    void processData() override {
        std::cout << "Processing data from Static Pressure Sensor." << std::endl;
    }
};

class TemperatureSensor : public Sensor {
public:
    void gatherData() override {
        std::cout << "Gathering data from Temperature Sensor." << std::endl;
    }

    void processData() override {
        std::cout << "Processing data from Temperature Sensor." << std::endl;
    }
};

class AOASensor : public Sensor {
public:
    void gatherData() override {
        std::cout << "Gathering data from AOA Sensor." << std::endl;
    }

    void processData() override {
        std::cout << "Processing data from AOA Sensor." << std::endl;
    }
};

// Sensor Factory class
class SensorFactory {
public:
    static Sensor* createSensor(const std::string& type) {
        if (type == "Static Pressure") {
            return new StaticPressureSensor();
        }
        else if (type == "Temperature") {
            return new TemperatureSensor();
        }
        else if (type == "AOA") {
            return new AOASensor();
        }
        return nullptr; // Invalid sensor type
    }
};

// Aerospace Control System class
class AerospaceControlSystem {
public:
    ~AerospaceControlSystem() {
        for (auto sensor : sensors) {
            delete sensor;
        }
    }

    void addSensor(Sensor* sensor) {
        sensors.push_back(sensor);
    }

    void monitorAndAdjust() {
        for (auto sensor : sensors) {
            sensor->gatherData();
            sensor->processData();
            std::cout << "Adjusting controls based on sensor data." << std::endl;
        }
    }

private:
    std::vector<Sensor*> sensors;
};

int main() {
    AerospaceControlSystem ctrlSys;

    // Add sensors
    ctrlSys.addSensor(SensorFactory::createSensor("Static Pressure"));
    ctrlSys.addSensor(SensorFactory::createSensor("Temperature"));
    ctrlSys.addSensor(SensorFactory::createSensor("AOA"));

    // Monitor and adjust
    ctrlSys.monitorAndAdjust();

    return 0;
}