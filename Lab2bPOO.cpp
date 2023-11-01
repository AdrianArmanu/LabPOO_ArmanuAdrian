#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<float> data;
    int rows;
    int cols;
    int errorCode;

public:
    // Constructorul implicit
    Matrix() : rows(0), cols(0), errorCode(0) {}

    // Constructor pentru matrice pătrată
    Matrix(int size) : rows(size), cols(size), errorCode(0) {
        data.resize(rows * cols);
    }

    // Constructor pentru matrice dreptunghiulară
    Matrix(int numRows, int numCols) : rows(numRows), cols(numCols), errorCode(0) {
        data.resize(rows * cols);
    }

    // Funcție pentru a accesa elementul matricei (i, j)
    float& at(int i, int j) {
        return data[i * cols + j];
    }

    // Funcție pentru a returna valoarea elementului matricei (i, j)
    float get(int i, int j) const {
        return data[i * cols + j];
    }

    // Funcție pentru a obține numărul de rânduri
    int getRows() const {
        return rows;
    }

    // Funcție pentru a obține numărul de coloane
    int getCols() const {
        return cols;
    }

    // Funcție pentru a permite utilizatorului să introducă matricea manual
    void inputMatrix() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cout << "Introduceti elementul [" << i + 1 << "][" << j + 1 << "]:";
                std::cin >> at(i, j);
            }
        }
    }

    // Funcție pentru a afișa matricea
    void printMatrix() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cout << at(i, j) << " ";
            }
            std::cout << std::endl;
        }
    }

    // Funcție pentru adunarea a două matrice
    Matrix addMatrices(const Matrix& other) {
        if (rows != other.getRows() || cols != other.getCols()) {
            errorCode = 1;
            return Matrix();
        }

        Matrix result(rows, cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.at(i, j) = this->get(i, j) + other.get(i, j);
            }
        }

        return result;
    }

    // Funcție pentru scăderea a două matrice
    Matrix subtractMatrices(const Matrix& other) {
        if (rows != other.getRows() || cols != other.getCols()) {
            errorCode = 1;
            return Matrix();
        }

        Matrix result(rows, cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.at(i, j) = this->get(i, j) - other.get(i, j);
            }
        }

        return result;
    }

    // Funcție pentru înmulțirea cu un număr
    Matrix multiplyMatrixByScalar(float scalar) {
        Matrix result(rows, cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.at(i, j) = this->get(i, j) * scalar;
            }
        }

        return result;
    }

    // Funcție pentru a obține codul de eroare
    int getErrorCode() const {
        return errorCode;
    }
};

int main() {
    int numRows1, numCols1, numRows2, numCols2;
    std::cout << "Numarul de randuri si coloane ale matrici patrate: ";
    std::cin >> numRows1;
    Matrix matrix1(numRows1);

    std::cout << "Introduceti matricea:\n";
    matrix1.inputMatrix();

    std::cout << "\nMatricea patrata:\n";
    matrix1.printMatrix();

    std::cout << "\nNumarul de randuri si coloane ale matrici dreptunghiulare: ";
    std::cin >> numRows2 >> numCols2;
    Matrix matrix2(numRows2, numCols2);

    std::cout << "Introduceti matricea 2:\n";
    matrix2.inputMatrix();

    std::cout << "\nMatricea 2:\n";
    matrix2.printMatrix();

    // Verificăm dimensiunile matricelor înainte de a efectua operații
    if (matrix1.getRows() == matrix2.getRows() && matrix1.getCols() == matrix2.getCols()) {

        // Adunare
        Matrix additionResult = matrix1.addMatrices(matrix2);
        if (additionResult.getErrorCode() == 1) {
            std::cout << "Dimensiuni incompatibile.\n";
        }
        else {
            std::cout << "\nAdunare:\n";
            additionResult.printMatrix();
        }

        // Scădere
        Matrix subtractionResult = matrix1.subtractMatrices(matrix2);
        if (subtractionResult.getErrorCode() == 1) {
            std::cout << "Dimensiuni incompatibile.\n";
        }
        else {
            std::cout << "\nScadere:\n";
            subtractionResult.printMatrix();
        }
    }
    else {
        std::cout << "Dimensiuni incompatibile.\n";
    }
    if (matrix1.getCols() == matrix2.getRows()) {

        // Înmulțirea matricelor
        Matrix multiplicationResult(matrix1.getRows(), matrix2.getCols());

        for (int i = 0; i < matrix1.getRows(); i++) {
            for (int j = 0; j < matrix2.getCols(); j++) {
                float sum = 0;
                for (int k = 0; k < matrix1.getCols(); k++) {
                    sum += matrix1.get(i, k) * matrix2.get(k, j);
                }
                multiplicationResult.at(i, j) = sum;
            }
        }

        std::cout << "\nInmultirea matricelor:\n";
        multiplicationResult.printMatrix();
    }
    else {
        std::cout << "Dimensiuni incompatibile.\n";
    }

    // Înmulțire cu scalar
    float scalar;
    std::cout << "\nIntroduceti un numar pentru inmultire: ";
    std::cin >> scalar;
    Matrix multiplicationResult = matrix1.multiplyMatrixByScalar(scalar);
    std::cout << "Inmultire cu un numar:\n";
    multiplicationResult.printMatrix();

    return 0;
}