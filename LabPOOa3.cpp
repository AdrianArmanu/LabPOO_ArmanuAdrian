#include <iostream>

class NumarIntreg {
private:
    int valoare;

public:
    NumarIntreg(int val) : valoare(val) {}

    // Operatorul de incrementare prefixat (++numar)
    NumarIntreg& operator++() {
        ++valoare;
        return *this;
    }

    // Operatorul de incrementare sufixat (numar++)
    NumarIntreg operator++(int) {
        NumarIntreg temp(valoare);
        ++valoare;
        return temp;
    }

    // Operatorul de adunare cu un alt obiect de tip NumarIntreg
    NumarIntreg operator+(const NumarIntreg& other) {
        return NumarIntreg(valoare + other.valoare);
    }

    // Operatorul de adunare cu un număr întreg
    NumarIntreg operator+(int num) {
        return NumarIntreg(valoare + num);
    }

    // Funcția prietenă pentru operatorul de decrementare prefixat (--numar)
    friend NumarIntreg operator--(NumarIntreg& num) {
        --num.valoare;
        return num;
    }

    // Funcția prietenă pentru operatorul de decrementare sufixat (numar--)
    friend NumarIntreg operator--(NumarIntreg& num, int) {
        NumarIntreg temp(num.valoare);
        --num.valoare;
        return temp;
    }

    // Funcția prietenă pentru operatorul de scădere cu un număr întreg
    friend NumarIntreg operator-(const NumarIntreg& num, int val) {
        return NumarIntreg(num.valoare - val);
    }

    // Funcția pentru afișarea valorii numerului
    void afisare() {
        std::cout << valoare << std::endl;
    }
};

int main() {
    NumarIntreg numar1(5);
    NumarIntreg numar2(3);

    // Operatorul de incrementare prefixat
    std::cout << "Operatorul de incrementare prefixat" << std::endl;
    ++numar1;
    numar1.afisare();

    // Operatorul de incrementare sufixat
    std::cout << "Operatorul de incrementare sufixat" << std::endl;
    numar2++;
    numar2.afisare(); 

    // Operatorul de adunare cu alt obiect NumarIntreg
    std::cout << "Operatorul de adunare cu alt obiect NumarIntreg" << std::endl;
    NumarIntreg rezultat = numar1 + numar2;
    rezultat.afisare(); 

    // Operatorul de adunare cu un număr întreg
    std::cout << "Operatorul de adunare cu un numar intreg" << std::endl;
    NumarIntreg rezultat2 = numar1 + 2;
    rezultat2.afisare(); 

    // Operatorul de decrementare prefixat
    std::cout << "Operatorul de decrementare prefixat" << std::endl;
    --numar1;
    numar1.afisare();

    // Operatorul de decrementare sufixat
    std::cout << "Operatorul de decrementare sufixat" << std::endl;
    numar2--;
    numar2.afisare(); 

    // Operatorul de scădere cu un număr întreg
    std::cout << "Operatorul de scadere cu un numar intreg" << std::endl;
    NumarIntreg rezultat3 = numar1 - 2;
    rezultat3.afisare(); 

    return 0;
}
