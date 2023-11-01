#include <iostream>
#include <string>

class Date {
private:
    int zi;
    int luna;
    int an;

public:
    // Constructor implicit
    Date() : zi(1), luna(1), an(2000) {}

    // Constructor cu parametri
    Date(int zi, int luna, int an) {
        setZi(zi);
        setLuna(luna);
        setAn(an);
    }

    // Funcție de setare a zilei cu verificare
    void setZi(int zi) {
        if (zi >= 1 && zi <= 31) {
            this->zi = zi;
        }
        else {
            std::cerr << "Zi invalida. Setata la 1." << std::endl;
            this->zi = 1;
        }
    }

    // Funcție de setare a lunii cu verificare
    void setLuna(int luna) {
        if (luna >= 1 && luna <= 12) {
            this->luna = luna;
        }
        else {
            std::cerr << "Luna invalida. Setata la 1." << std::endl;
            this->luna = 1;
        }
    }

    // Funcție de setare a anului cu verificare
    void setAn(int an) {
        if (an >= 0) {
            this->an = an;
        }
        else {
            std::cerr << "An invalid. Setat la 2000." << std::endl;
            this->an = 2000;
        }
    }

    // Funcție de returnare a zilei
    int getZi() const {
        return zi;
    }

    // Funcție de returnare a lunii
    int getLuna() const {
        return luna;
    }

    // Funcție de returnare a anului
    int getAn() const {
        return an;
    }

    // Funcție de afișare tip "6 iunie 2004"
    std::string afisareLunga() const {
        const char* numeLuni[] = {
            "ianuarie", "februarie", "martie", "aprilie", "mai", "iunie",
            "iulie", "august", "septembrie", "octombrie", "noiembrie", "decembrie"
        };
        return std::to_string(zi) + " " + numeLuni[luna - 1] + " " + std::to_string(an);
    }

    // Funcție de afișare tip "6.06.2004"
    std::string afisareScurta() const {
        return (zi < 10 ? "0" : "") + std::to_string(zi) + "." + (luna < 10 ? "0" : "") + std::to_string(luna) + "." + std::to_string(an);
    }
};

int main() {
    int zi1, luna1, an1, zi2, luna2, an2;

    std::cout << "Introduceți data 1 (zi luna an): ";
    std::cin >> zi1 >> luna1 >> an1;

    std::cout << "Introduceți data 2 (zi luna an): ";
    std::cin >> zi2 >> luna2 >> an2;

    Date data1(zi1, luna1, an1);
    Date data2(zi2, luna2, an2);

    std::cout << "Data 1: " << data1.afisareLunga() << std::endl;
    std::cout << "Data 2: " << data2.afisareScurta() << std::endl;

    return 0;
}
