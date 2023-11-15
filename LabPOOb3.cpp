#include <iostream>
#include <set>

class Set {
private:
    std::set<int> elements;

public:
    // Constructor implicit
    Set() {}

    // Constructor cu inițializare
    Set(std::initializer_list<int> initList) {
        for (const int& element : initList) {
            elements.insert(element);
        }
    }

    // Operatorul de uniune (+)
    friend Set operator+(const Set& set1, const Set& set2) {
        Set result = set1;
        for (const int& element : set2.elements) {
            result.elements.insert(element);
        }
        return result;
    }

    // Operatorul de intersecție (*)
    friend Set operator*(const Set& set1, const Set& set2) {
        Set result;
        for (const int& element : set1.elements) {
            if (set2.elements.count(element) > 0) {
                result.elements.insert(element);
            }
        }
        return result;
    }

    // Operatorul de scădere (-)
    friend Set operator-(const Set& set1, const Set& set2) {
        Set result = set1;
        for (const int& element : set2.elements) {
            result.elements.erase(element);
        }
        return result;
    }

    // Operatorul de inserare in mulțime (+=)
    void operator+=(int element) {
        elements.insert(element);
    }

    // Operatorul de comparare la egalitate (==)
    bool operator==(const Set& other) const {
        return elements == other.elements;
    }

    // Funcția de verificare a apartenenței unui element la mulțime
    bool contains(int element) const {
        return elements.count(element) > 0;
    }

    // Operatorul de citire (>>)
    friend std::istream& operator>>(std::istream& in, Set& set) {
        int element;
        in >> element;
        set.elements.insert(element);
        return in;
    }

    // Operatorul de afișare (<<)
    friend std::ostream& operator<<(std::ostream& out, const Set& set) {
        for (const int& element : set.elements) {
            out << element << ' ';
        }
        return out;
    }
};

int main() {
    Set set1 = { 1, 2, 3 };
    Set set2 = { 3, 4, 5 };

    Set unionSet = set1 + set2;
    Set intersectionSet = set1 * set2;
    Set differenceSet = set1 - set2;

    std::cout << "Uniune: " << unionSet << std::endl;
    std::cout << "Intersectie: " << intersectionSet << std::endl;
    std::cout << "Diferenta: " << differenceSet << std::endl;

    set1 += 6;
    std::cout << "adaugam 6 in set1: " << set1 << std::endl;

    if (set1 == set2) {
        std::cout << "set1 si set2 sunt egale" << std::endl;
    }
    else {
        std::cout << "set1 si set2 nu sunt egale" << std::endl;
    }

    int elementToCheck = 5;
    if (set1.contains(elementToCheck)) {
        std::cout << elementToCheck << " se afla in set1" << std::endl;
    }
    else {
        std::cout << elementToCheck << " nu se afla in set1" << std::endl;
    }

    return 0;
}
