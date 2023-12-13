#include <iostream>
#include <stdexcept>  // Pentru gestionarea excepțiilor

class Worker {
public:
    virtual double calculateSalary() const = 0;  // Funcție virtuală pură
    virtual ~Worker() {}  // Destructor virtual
};

class StateWorker : public Worker {
public:
    double calculateSalary() const override {
        
        return 5000.0;
    }
};

class HourlyWorker : public Worker {
public:
    double calculateSalary() const override {
        
        return hoursWorked * hourlyRate;
    }

    // Metodă pentru setarea numărului de ore lucrate și tariful orar
    void setHoursWorked(double hours, double rate) {
        hoursWorked = hours;
        hourlyRate = rate;
    }

private:
    double hoursWorked;
    double hourlyRate;
};

class CommissionWorker : public Worker {
public:
    double calculateSalary() const override {
        
        return sales * commissionRate;
    }

    // Metodă pentru setarea vânzărilor și comisionului
    void setSalesAndCommission(double salesAmount, double commission) {
        sales = salesAmount;
        commissionRate = commission;
    }

private:
    double sales;
    double commissionRate;
};

int main() {
    const int arraySize = 3;
    Worker* workers[arraySize];

    try {
        // Alocare și atribuire de obiecte derivate la pointeri de tipul clasei de bază
        workers[0] = new StateWorker();

        HourlyWorker* hourlyWorker = new HourlyWorker();
        hourlyWorker->setHoursWorked(40.0, 20.0);
        workers[1] = hourlyWorker;

        CommissionWorker* commissionWorker = new CommissionWorker();
        commissionWorker->setSalesAndCommission(10000.0, 0.1);
        workers[2] = commissionWorker;

        // Utilizare pointeri pentru a accesa funcția virtuală calculateSalary
        for (int i = 0; i < arraySize; ++i) {
            std::cout << "Salariul pentru lucratorul " << i + 1 << ": " << workers[i]->calculateSalary() << std::endl;
        }

        // Eliberare resurse (deallocation of memory)
        for (int i = 0; i < arraySize; ++i) {
            delete workers[i];
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Eroare: " << e.what() << std::endl;
    }

    return 0;
}
