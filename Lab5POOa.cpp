#include <iostream>

class Student {
public:
    int mark;

    Student(int mark) : mark(mark) {}
};

class Worker {
public:
    int salary;

    Worker(int salary) : salary(salary) {}
};

class Practicant : public Student, public Worker {
public:
    Practicant(int mark, int salary) : Student(mark), Worker(salary) {}
};

int main() {
    Practicant p(5, 200);

    std::cout << "Mark: " << p.mark << std::endl;
    std::cout << "Salary: " << p.salary << std::endl;

    return 0;
}
