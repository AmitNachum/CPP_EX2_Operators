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

    cout << "\033[1;34m===Matrix 1===\033[0m\n";
    matrix1.printMatrix();
    cout << "\n\n";

    // Initialize matrix2 with all elements = 3
    squaredMatrix matrix2(N);
    for (size_t i = 0; i < N; i++)
        for (size_t j = 0; j < N; j++)
            matrix2.getMatrix()[i][j] = 3;


    cout << "\n\033[1;34m===Matrix 2===\033[0m\n";
    matrix2.printMatrix();
    cout << "\n\n";

    cout << "\n\033[1;32m===Arithmetic operations===\033[0m\n";

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
    cout << "\n\033[1;34m===Power Matrix===\033[0m\n";
    uint power = 2;
    result = matrix1^power;
    cout << "Matrix1 ^ power:\n";
    result.printMatrix();
    cout<< "\n\n";


    cout <<"\n\033[1;32m=== Increments and Decrements===\033[0m\n";
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
    cout << "\n\n";

    //Matrix determinant
    cout <<"\033[1;34m===Matrix determinant===\033[0m\n";
    double det = !result;
    cout <<"Result's determinant:" << det <<"\n\n\n";

    //Getting an Element and modifying it
    cout <<"\033[1;34m===Before modifying===\033[0m\n";
    result.printMatrix();
    cout<< "\n";
    cout <<"\033[1;34m===After modifying===\033[0m\n";
    result.getMatrix()[0][0] = 1;
    result.getMatrix()[1][0] = 52;
    result.getMatrix()[0][1] = 61;
    result.getMatrix()[0][2] = 23;
    result.getMatrix()[2][2] = 90;
    result.printMatrix();
    cout <<"\n\n";


    //Getting an Element without modifying
    cout << "\033[1;34m===Getting an element===\033[0m";
    double element = result.getMatrix()[1][1];
    cout<<"\nElement:" <<element << "\n\n\n";
    //result.getMatrix()[0][0] = 1; would cause an error.


    //logical operators
    cout <<"\033[1;34m===Logical operators===\033[0m\n\n";
    cout <<" =Matrix 1=\n";
    matrix1.printMatrix();
    cout <<"\n\n";

    cout <<" =Result=\n";
    result.printMatrix();
    cout <<"\n\n";

    const char* equal = (result == matrix1) ? "Yes" : "No";
    const char* notEqual = (result != matrix1)? "Yes" : "No";
    const char* smaller = (result < matrix1)? "Yes" : "No";
    const char* bigger = (result > matrix1)? "Yes" : "No";
    const char* smallerOrEqual = (result <= matrix1)? "Yes" : "No";
    const char* biggerOrEqual = (result >= matrix1)? "Yes" : "No"; 

    cout << "Equal:" << equal <<"\n";
    cout << "Not Equal:" << notEqual <<"\n";
    cout << "Smaller:" << smaller <<"\n";
    cout << "Bigger:" << bigger <<"\n";
    cout << "smaller Or Equal:" << smallerOrEqual <<"\n";
    cout << "Bigger or Equal:" << biggerOrEqual <<"\n";


    //Transpose
    cout << "\n\033[1;34m===Before transpose===\033[0m\n";
    result.printMatrix();
    ~result;
    cout << "\n\033[1;34m===After transpose===\033[0m\n";
    result.printMatrix();


    //Short Addition
    cout<<"\n\033[1;34m===Short Addition===\033[0m\n";
    result += matrix1;
    result.printMatrix();


    //Short Subtraction
    cout<<"\n\033[1;34m===Short Subtraction===\033[0m\n";
    result -= matrix1;
    result.printMatrix();

    //Short multiplication
    cout<<"\n\033[1;34m===Short multiplication===\033[0m\n";
    result *= matrix1;
    result.printMatrix();

    //Short Division
    cout<<"\n\033[1;34m===Short Division===\033[0m\n";
    matrix1.getMatrix()[1][1] = 2;
    matrix1.getMatrix()[0][0] = 5;
    matrix1.getMatrix()[2][2] = 4;
    result /= matrix1;
    cout << result;

    //Short element multiplication
    cout <<"\n\033[1;34m=== Short element multiplication ===\033[0m \n";
    result %= matrix1;
    result.printMatrix();




    //Short modulu
    size_t natural = 3;
     cout << "\n\033[1;34m=== Short modulu ===\033[0m \n";
    result %= natural;
    result.printMatrix();


    //Output stream
    cout << "\n\033[1;34m=== Output Stream ===\033[0m\n";
    cout << result;

    return 0;
}
