#include "Matrix_nxn.hpp"
using namespace Squared_Matrix;
using std::cout, std::cin;

int main() {
    const size_t N = 3;

    // Initialize matrix1 with all elements = 2
    squaredMatrix matrix1(N);
    for (size_t i = 0; i < N; i++)
        for (size_t j = 0; j < N; j++)
            matrix1.getMatrix()[i][j] = 2;

    cout << "Matrix 1:\n";
    matrix1.printMatrix();
    cout << "\n\n";

    // Initialize matrix2 with all elements = 3
    squaredMatrix matrix2(N);
    for (size_t i = 0; i < N; i++)
        for (size_t j = 0; j < N; j++)
            matrix2.getMatrix()[i][j] = 3;

    cout << "Matrix 2:\n";
    matrix2.printMatrix();
    cout << "\n\n";

    // Subtraction
    squaredMatrix result = matrix1 - matrix2;
    cout << "Matrix1 - Matrix2:\n";
    result.printMatrix();
    cout << "\n\n";

    // Addition
    result = matrix1 + matrix2;
    cout << "Matrix1 + Matrix2:\n";
    result.printMatrix();
    cout << "\n\n";

    // Multiplication
    result = matrix1 * matrix2;
    cout << "Matrix1 * Matrix2:\n";
    result.printMatrix();
    cout << "\n\n";



    //Scalar Multiplication
    double scalar = 3.5;
    result = matrix1 * scalar;
    cout << "Matrix1 * scalar\n";
    result.printMatrix();
    cout << "\n\n";


    //elemental Matrix Multiplication
    result = matrix1 % matrix2;
    cout << "Matrix1 % Matrix2:\n";
    result.printMatrix();
    cout << "\n\n";

    //Matrix modulu by a scalar
    uint modulu = 3;
    result = matrix1 % modulu;
    cout << "Matrix1 % modulu:\n";
    result.printMatrix();
    cout << "\n\n";

    //Matrix division by a scalar
    double scalar2 = 2;
    result = matrix1 / scalar2;
    cout << "Matrix1 / scalar:\n";
    result.printMatrix();
    cout<< "\n\n";

    //Matrix Power
    uint power = 2;
    result = matrix1^power;
    cout << "Matrix1 ^ power:\n";
    result.printMatrix();
    cout<< "\n\n";

    //Matrix post Increment
    ++result;
    cout << "Matrix1 Post Increment\n";
    result.printMatrix();
    cout<< "\n\n";


    //Matrix pre Increment
    result++;
    cout << "Matrix1 Pre Increment\n";
    result.printMatrix();
    cout<< "\n\n";

    //Matrix post Decrement
    --result;
    cout << "Matrix1 Post Decrement\n";
    result.printMatrix();
    cout<< "\n\n";

    //Matrix pre Decrement'
    result--;
    cout << "Matrix1 Pre Decrement\n";
    result.printMatrix();
    cout<< "\n\n";

    //Matrix determinant
    double det = ~result;
    cout <<"Result's determinant:" << det <<"\n";
    

    return 0;
}
