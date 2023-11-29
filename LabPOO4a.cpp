#include <iostream>
#include <string>

class Joc {
public:
    Joc(const std::string& nume) : nume_(nume) {
        std::cout << "Constructor Joc: " << nume_ << std::endl;
    }

    virtual ~Joc() {
        std::cout << "Destructor Joc: " << nume_ << std::endl;
    }

    Joc(const Joc& other) {
        nume_ = other.nume_;
        std::cout << "Constructor de copiere Joc: " << nume_ << std::endl;
    }

    Joc& operator=(const Joc& other) {
        if (this != &other) {
            nume_ = other.nume_;
            std::cout << "Operator de atribuire Joc: " << nume_ << std::endl;
        }
        return *this;
    }

    virtual void desfasurare() const {
        std::cout << "Desfasurare Joc: " << nume_ << std::endl;
    }

protected:
    std::string nume_;
};

class JocSportiv : public Joc {
public:
    JocSportiv(const std::string& nume, const std::string& tipSport)
        : Joc(nume), tipSport_(tipSport) {
        std::cout << "Constructor JocSportiv: " << nume_ << ", " << tipSport_ << std::endl;
    }

    virtual ~JocSportiv() {
        std::cout << "Destructor JocSportiv: " << nume_ << ", " << tipSport_ << std::endl;
    }

    JocSportiv(const JocSportiv& other) : Joc(other) {
        tipSport_ = other.tipSport_;
        std::cout << "Constructor de copiere JocSportiv: " << nume_ << ", " << tipSport_ << std::endl;
    }

    JocSportiv& operator=(const JocSportiv& other) {
        if (this != &other) {
            Joc::operator=(other);
            tipSport_ = other.tipSport_;
            std::cout << "Operator de atribuire JocSportiv: " << nume_ << ", " << tipSport_ << std::endl;
        }
        return *this;
    }

    void desfasurare() const override {
        std::cout << "Desfasurare JocSportiv: " << nume_ << ", " << tipSport_ << std::endl;
    }

protected:
    std::string tipSport_;
};

class Volei : public JocSportiv {
public:
    Volei(const std::string& nume, const std::string& tipSport, int numarJucatori)
        : JocSportiv(nume, tipSport), numarJucatori_(numarJucatori) {
        std::cout << "Constructor Volei: " << nume_ << ", " << tipSport_ << ", " << numarJucatori_ << " jucatori" << std::endl;
    }

    ~Volei() override {
        std::cout << "Destructor Volei: " << nume_ << ", " << tipSport_ << ", " << numarJucatori_ << " jucatori" << std::endl;
    }

    Volei(const Volei& other) : JocSportiv(other) {
        numarJucatori_ = other.numarJucatori_;
        std::cout << "Constructor de copiere Volei: " << nume_ << ", " << tipSport_ << ", " << numarJucatori_ << " jucatori" << std::endl;
    }

    Volei& operator=(const Volei& other) {
        if (this != &other) {
            JocSportiv::operator=(other);
            numarJucatori_ = other.numarJucatori_;
            std::cout << "Operator de atribuire Volei: " << nume_ << ", " << tipSport_ << ", " << numarJucatori_ << " jucatori" << std::endl;
        }
        return *this;
    }

    void desfasurare() const override {
        std::cout << "Desfasurare Volei: " << nume_ << ", " << tipSport_ << ", " << numarJucatori_ << " jucatori" << std::endl;
    }

private:
    int numarJucatori_;
};

int main() {
    Volei volei("Turneu de Volei", "Volei", 6);

    std::cout << "\nApelarea functiei desfasurare:\n";
    volei.desfasurare();

    return 0;
}
