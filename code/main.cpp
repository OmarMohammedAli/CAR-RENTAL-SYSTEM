#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

using namespace std;

int login() {
    string pass = "";
    char ch;
    cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t       CAR RENTAL SYSTEM \n\n";
    cout << "\t\t\t\t\t------------------------------";
    cout << "\n\t\t\t\t\t\t     LOGIN \n";
    cout << "\t\t\t\t\t------------------------------\n\n";
    cout << "\t\t\t\t\tEnter Password: ";
    ch = _getch();
    while (ch != 13) {  // character 13 is enter
        pass.push_back(ch);
        cout << '*';
        ch = _getch();
    }
    if (pass == "pass") {
        cout << "\n\n\n\t\t\t\t\t\tAccess Granted! \n";
        system("PAUSE");
        system("CLS");
    } else {
        cout << "\n\n\t\t\t\t\t\t\tAccess Aborted...\n\t\t\t\t\t\t\tPlease Try Again\n\n";
        system("PAUSE");
        system("CLS");
        login();
    }
}

class Car {
private:
    string model;
    bool available;
    double dailyRate;
    vector<int> manufacturingYears;

public:
    Car(const string& model, double dailyRate, const vector<int>& manufacturingYears)
        : model(model), available(true), dailyRate(dailyRate), manufacturingYears(manufacturingYears) {}

    const string& getModel() const {
        return model;
    }

    bool isAvailable() const {
        return available;
    }

    void setAvailability(bool availability) {
        available = availability;
    }

    double getDailyRate() const {
        return dailyRate;
    }

    const vector<int>& getManufacturingYears() const {
        return manufacturingYears;
    }
};

class RentalSystem {
private:
    vector<Car> cars;

public:
    RentalSystem() {
        cars = {
            Car("BMW", 50.0, {2010, 2015, 2020, 2022, 2023}),
            Car("KIA", 60.0, {2011, 2016, 2021, 2023, 2024}),
            Car("HONDA", 70.0, {2012, 2017, 2022, 2024, 2025}),
            Car("TOYOTA", 55.0, {2013, 2018, 2023, 2025, 2026}),
            Car("FORD", 65.0, {2014, 2019, 2024, 2026, 2027}),
            Car("JEEP", 75.0, {2015, 2020, 2025, 2027, 2028}),
            Car("MG", 80.0, {2016, 2021, 2026, 2028, 2029}),
            Car("JETURE", 85.0, {2017, 2022, 2027, 2029, 2030}),
            Car("HAVAL", 90.0, {2018, 2023, 2028, 2030, 2031}),
            Car("FIAT", 95.0, {2019, 2024, 2029, 2031, 2032})
        };
    }

    void displayAvailableCars() const {
        cout << "Available Cars:" << endl;
        for (auto it = cars.begin(); it != cars.end(); ++it) {
            const Car& car = *it;
            if (car.isAvailable()) {
                cout << car.getModel() << " (Years: ";
                const auto& years = car.getManufacturingYears();
                for (size_t i = 0; i < years.size(); ++i) {
                    cout << years[i];
                    if (i != years.size() - 1) {
                        cout << ", ";
                    }
                }
                cout << ") => Daily Rate: $" << car.getDailyRate() << endl;
            }
        }
    }

    bool rentCar(const string& model, int year, int days) {
        for (auto it = cars.begin(); it != cars.end(); ++it) {
            Car& car = *it;
            if (car.getModel() == model && car.isAvailable()) {
                const auto& years = car.getManufacturingYears();
                bool yearFound = false;
                for (size_t i = 0; i < years.size(); ++i) {
                    if (years[i] == year) {
                        yearFound = true;
                        break;
                    }
                }

                if (yearFound) {
                    car.setAvailability(false);
                    double totalCost = car.getDailyRate() * days;
                    cout << "You have rented " << car.getModel() << " (Year: " << year << ") for " << days << " days. Total Cost: $" << totalCost << endl;
                    return true;
                } else {
                    cout << "Car " << model << " is not available for the selected year." << endl;
                    return false;
                }
            }
        }
        cout << "Car " << model << " is not available for rent." << endl;
        return false;
    }
};

int main() {
    login();  // Call the login function at the beginning

    RentalSystem rentalSystem;

    int choice;
    do {
        cout << endl << "==================== Car Rental System Menu ====================" << endl;
        cout << endl << "1. Display Available Cars" << endl;
        cout << "2. Rent a Car" << endl;
        cout << "3. Exit" << endl;  // Removed "Return a Car" option
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl << "========================================" << endl;

        switch (choice) {
            case 1:
                rentalSystem.displayAvailableCars();
                break;
            case 2: {
                int modelChoice, year, days;
                cout << "Enter the number corresponding to the car model:" << endl;
                cout << "[1] BMW" << endl;
                cout << "[2] KIA" << endl;
                cout << "[3] HONDA" << endl;
                cout << "[4] TOYOTA" << endl;
                cout << "[5] FORD" << endl;
                cout << "[6] JEEP" << endl;
                cout << "[7] MG" << endl;
                cout << "[8] JETURE" << endl;
                cout << "[9] HAVAL" << endl;
                cout << "[10] FIAT" << endl;
                cout << "Enter your choice: ";
                cin >> modelChoice;

                string modelName;
                switch (modelChoice) {
                    case 1:
                        modelName = "BMW";
                        break;
                    case 2:
                        modelName = "KIA";
                        break;
                    case 3:
                        modelName = "HONDA";
                        break;
                    case 4:
                        modelName = "TOYOTA";
                        break;
                    case 5:
                        modelName = "FORD";
                        break;
                    case 6:
                        modelName = "JEEP";
                        break;
                    case 7:
                        modelName = "MG";
                        break;
                    case 8:
                        modelName = "JETURE";
                        break;
                    case 9:
                        modelName = "HAVAL";
                        break;
                    case 10:
                        modelName = "FIAT";
                        break;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                        continue;
                }

                cout << "Enter manufacturing year: ";
                cin >> year;
                cout << "Enter number of days: ";
                cin >> days;

                rentalSystem.rentCar(modelName, year, days);
                break;
            }
            case 3:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
