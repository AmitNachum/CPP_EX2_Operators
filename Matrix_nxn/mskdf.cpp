#include "Matrix_nxn.hpp"
#include <iostream>

using namespace Squared_Matrix;

int main(){
    squaredMatrix m1 = squaredMatrix(6);
    m1.getMatrix()[1][1] = 1;


    squaredMatrix m2 = m1 * 6;



    return 0;
}