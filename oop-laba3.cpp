#include <iostream>
#include <string>

class MeasurementDevice {
private:
	std::string* name;
	std::string* unit;
	int* minValue;
	int* maxValue;
	std::string* material;
	bool isDeviceActiveForMeasurement;
	static int totalMeasurements;
	static double measurementAccuracyCoefficient;

public:
	MeasurementDevice() : name(new std::string("")), unit(new std::string("")), minValue(new int(0)), maxValue(new int(0)), material(new std::string("")), isDeviceActiveForMeasurement(false) { }

	MeasurementDevice(const std::string& _name, const std::string& _unit, int _minValue, int _maxValue, const std::string& _material)
		: name(new std::string(_name)), unit(new std::string(_unit)), minValue(new int(_minValue)), maxValue(new int(_maxValue)), material(new std::string(_material)), isDeviceActiveForMeasurement(false) { }

	MeasurementDevice(const MeasurementDevice& other)
		: name(new std::string(*(other.name))), unit(new std::string(*(other.unit))), minValue(new int(*(other.minValue))),
		maxValue(new int(*(other.maxValue))), material(new std::string(*(other.material))), isDeviceActiveForMeasurement(false) { }

	~MeasurementDevice() {
		delete name;
		delete unit;
		delete minValue;
		delete maxValue;
		delete material;
	}

	void startMeasuring() {
		if (!isDeviceActiveForMeasurement) {
			std::cout << "Start of measurement" << this << std::endl;
			isDeviceActiveForMeasurement = true;
		}
		else {
			std::cout << "\n!!!The device had already started measuring!!!\n" << std::endl;
		}
	}

	void stopMeasuring() {
		if (isDeviceActiveForMeasurement) {
			std::cout << "End of measurement" << this << std::endl;
			isDeviceActiveForMeasurement = false;
			totalMeasurements++;
		}
		else {
			std::cout << "\n!!!The device has not started measuring yet!!!\n" << std::endl;
		}
	}

	void print() const {
		if (isDeviceActiveForMeasurement) {
			std::cout << "============" << std::endl;
			std::cout << "Name: " << *name << std::endl;
			std::cout << "Unit: " << *unit << std::endl;
			std::cout << "Min Value: " << *minValue << std::endl;
			std::cout << "Max Value: " << *maxValue << std::endl;
			std::cout << "Material: " << *material << std::endl;
			std::cout << "============" << std::endl;
		}
		else {
			std::cout << "You have not started the measurement\n" << std::endl;
		}
	}

	static int getTotalMeasurements() {
		return totalMeasurements;
	}

	static double getMeasurementAccuracyCoefficient() {
		return measurementAccuracyCoefficient;
	}

	static void setMeasurementAccuracyCoefficient(double coefficient) {
		measurementAccuracyCoefficient = coefficient;
	}

};

int MeasurementDevice::totalMeasurements = 0;
double MeasurementDevice::measurementAccuracyCoefficient = 1.0;

int main() {
	MeasurementDevice::setMeasurementAccuracyCoefficient(0.25);

	MeasurementDevice thermometer("Thermometer", "Celsius", -50, 150, "Plastic");
	MeasurementDevice ruler("Ruler", "Centimeters", 0, 30, "Wood");

	thermometer.startMeasuring();
	thermometer.stopMeasuring();

	ruler.stopMeasuring();
	ruler.startMeasuring();
	ruler.startMeasuring();
	ruler.stopMeasuring();
	ruler.stopMeasuring();

	std::cout << "Total measurements taken by all MeasurementDevice objects: " << MeasurementDevice::getTotalMeasurements() << std::endl;
	std::cout << "Measurement Accuracy Coefficient: " << MeasurementDevice::getMeasurementAccuracyCoefficient() << std::endl;

	return 0;
}
