#include <iostream>
#include <vector>
#include <string>

class Roata {
public:
    Roata(double raza) : raza_(raza) {
        std::cout << "Constructor Roata: raza = " << raza_ << std::endl;
    }

    ~Roata() {
        std::cout << "Destructor Roata: raza = " << raza_ << std::endl;
    }

    double getRaza() const {
        return raza_;
    }

    void setRaza(double raza) {
        raza_ = raza;
    }

private:
    double raza_;
};

class Automobil {
public:
    Automobil(const std::string& firmaProducatoare) : firmaProducatoare_(firmaProducatoare) {
        std::cout << "Constructor Automobil: Firma = " << firmaProducatoare_ << std::endl;
    }

    virtual ~Automobil() {
        std::cout << "Destructor Automobil: Firma = " << firmaProducatoare_ << std::endl;
    }

    const std::string& getFirmaProducatoare() const {
        return firmaProducatoare_;
    }

    void setFirmaProducatoare(const std::string& firmaProducatoare) {
        firmaProducatoare_ = firmaProducatoare;
    }

    void adaugaRoata(const Roata& roata) {
        roti_.push_back(roata);
    }

private:
    std::vector<Roata> roti_;
    std::string firmaProducatoare_;
};

class Autocamion : public Automobil {
public:
    Autocamion(const std::string& firmaProducatoare, double tonaj)
        : Automobil(firmaProducatoare), tonaj_(tonaj) {
        std::cout << "Constructor Autocamion: Firma = " << getFirmaProducatoare() << ", Tonaj = " << tonaj_ << std::endl;
    }

    ~Autocamion() override {
        std::cout << "Destructor Autocamion: Firma = " << getFirmaProducatoare() << ", Tonaj = " << tonaj_ << std::endl;
    }

    double getTonaj() const {
        return tonaj_;
    }

    void setTonaj(double tonaj) {
        tonaj_ = tonaj;
    }

private:
    double tonaj_;
};

int main() {
    Roata roata1(15.5);
    Roata roata2(15.5);
    Roata roata3(16.0);
    Roata roata4(16.0);

    Automobil masina("Toyota");
    masina.adaugaRoata(roata1);
    masina.adaugaRoata(roata2);
    masina.adaugaRoata(roata3);
    masina.adaugaRoata(roata4);

    Autocamion camion("Volvo", 5000.0);

    return 0;
}

