#include <iostream>

class Om {
public:
    std::string nume;

    Om(const std::string& nume) : nume(nume) {
        std::cout << "Constructor Om pentru " << nume << std::endl;
    }

    ~Om() {
        std::cout << "Destructor Om pentru " << nume << std::endl;
    }
};

class Student : virtual public Om {
public:
    int mark;

    Student(const std::string& nume, int mark) : Om(nume), mark(mark) {
        std::cout << "Constructor Student pentru " << nume << std::endl;
    }
};

class Worker : virtual public Om {
public:
    int salary;

    Worker(const std::string& nume, int salary) : Om(nume), salary(salary) {
        std::cout << "Constructor Worker pentru " << nume << std::endl;
    }
};

class Practicant : public Student, public Worker {
public:
    Practicant(const std::string& nume, int mark, int salary) : Om(nume), Student(nume, mark), Worker(nume, salary) {
        std::cout << "Constructor Practicant pentru " << nume << std::endl;
    }
};

int main() {
    Practicant p("John", 5, 200);

    std::cout << "Nume: " << p.nume << std::endl;
    std::cout << "Mark: " << p.mark << std::endl;
    std::cout << "Salary: " << p.salary << std::endl;

    return 0;
}

