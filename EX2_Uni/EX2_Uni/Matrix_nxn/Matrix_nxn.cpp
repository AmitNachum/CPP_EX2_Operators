#include "Matrix_nxn.hpp"
using namespace Squared_Matrix;

squaredMatrix &squaredMatrix::operator=(const Squared_Matrix::squaredMatrix &other){
    if(this == &other) return *this;

    for (size_t i = 0; i < this->n; i++)
    {
        delete[] this->matrix[i];
        this->matrix[i] = nullptr;
    }
    delete[] this->matrix;
    this->matrix = nullptr;

    if (this->n > other.n)
    {
        this->n = other.n;
    }
    
    

    this->matrix = new double*[this->n];

    for (size_t i = 0; i < this->n; i++)
    {
        this->matrix[i] = new double[n];
    }
    


    for (size_t i = 0; i < this->n; i++)
    {
        for(size_t j = 0; j < this->n; j++){
            this->matrix[i][j] = other.matrix[i][j];
        }

    }
    
return *this;

}




void squaredMatrix::printMatrix() const{

    for(int i = 0; i < n ; i++){
        for (int j = 0; j < n; j++)
        {
            if (j != n - 1)
            {
                std::cout << matrix[i][j] << ", ";
            }
            else
            std::cout << matrix[i][j];
            
        }
        std::cout << "\n";
        
    }
}


   
squaredMatrix squaredMatrix::operator-(const squaredMatrix &other)const{
    squaredMatrix result = squaredMatrix(n);


    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            result.matrix[i][j] = 0;
            double value = matrix[i][j];
            double otherValue = other.matrix[i][j];
            result.matrix[i][j] = value - otherValue;
        }
        
    }

    return result;
    
}

squaredMatrix squaredMatrix::operator+(const squaredMatrix &other)const{
    squaredMatrix result = squaredMatrix(n);
    

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            
            result.matrix[i][j] = 0;
            double value = matrix[i][j];
            double otherValue = other.matrix[i][j];
            result.getMatrix()[i][j] = value + otherValue;
        }
        
    }

    return result;
    
}

squaredMatrix squaredMatrix::operator*(const squaredMatrix &other)const{

    squaredMatrix result = squaredMatrix(n);

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            result.matrix[i][j] = 0;

            for (size_t k = 0; k < n; k++)
            {
                double value = this->matrix[i][k];
                double otherValue = other.matrix[k][j];
    
                result.matrix[i][j] += value * otherValue; 
            
            }
            
        }
        
    }


    return result;
    
}


squaredMatrix squaredMatrix::operator*(double scalar){
    squaredMatrix result = squaredMatrix(this->n);

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            double value = this->matrix[i][j];
            

            result.matrix[i][j] = value * scalar; 
        }
        
    }
    


    return result;
}


squaredMatrix squaredMatrix::operator%(const squaredMatrix &other){
    squaredMatrix result = squaredMatrix(this->n);

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            double value = matrix[i][j];
            double otherValue = other.matrix[i][j];

            result.matrix[i][j] = value * otherValue; 
        }
        
    }


    return result;

}
squaredMatrix squaredMatrix::operator%(uint modulu){
    squaredMatrix result = squaredMatrix(this->n);

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            double value = this->getMatrix()[i][j];

            if(value == (int)value ){
            result.matrix[i][j] = ((int)(value)) % modulu; 
            }
            else continue;


        }
        
    }


    return result;
}


squaredMatrix squaredMatrix::operator/(double scalar){
    if(scalar == 0) throw "Erorr:division by 0!\n";

    squaredMatrix res(n);


    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            double value = this->getMatrix()[i][j];
            res.matrix[i][j] = value / scalar;
        }
        
    }
    


    return res;
}

squaredMatrix squaredMatrix::operator^(uint power){
    if (power < 0) throw "Power cannot be a negative number";

    if(power == 0){
        squaredMatrix identity(n);
        for (size_t i = 0; i < n; i++)
        {
           identity.matrix[i][i] = 1;
        }

        return identity;
        
    }
    
    squaredMatrix res = *this;
    

    for (size_t i = 1; i < power; i++)
    {

        res = res * (*this);

    }
    
 
    return res;
}


squaredMatrix& squaredMatrix::operator++(){

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            ++matrix[i][j];
        }
        
    }

    return *this;
    
}


squaredMatrix& squaredMatrix::operator--(){

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            --matrix[i][j];
        }
        
    }

    return *this;
}

squaredMatrix squaredMatrix::operator++(int){
    squaredMatrix newMat = *this;

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            matrix[i][j]++;
        }
        
    }

    return newMat;
    
}

squaredMatrix squaredMatrix::operator--(int){
    squaredMatrix newMat = *this;

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            matrix[i][j]--;
        }
        
    }

    return newMat;
}

double squaredMatrix::operator!(){

    if (n == 1)
        return matrix[0][0];
    
    
    if (n == 2)
        return matrix[0][0] * matrix[1][1] -matrix[1][0] * matrix[0][1];
    

    size_t i = 0;
    double determinant = 0;

    for (size_t j = 0; j < n ; j++)
    {
        squaredMatrix minor = subMatrix(j,i,*this);
        double detMinor = !minor;
        determinant += matrix[i][j]*power(-1, i + j) * detMinor;

    }
    

    return determinant;
    
}

squaredMatrix squaredMatrix::subMatrix(size_t j,size_t i,squaredMatrix mat){
        size_t size = mat.n ;
        squaredMatrix minor(size - 1);

        size_t minorRow = 0;
        for (size_t row = 0; row < size ; row++)
        {
            if (row == i) continue;
            size_t minorCol = 0;
            
            for (size_t col = 0; col < size; col++)
            {
                if(col == j) continue;

                minor.matrix[minorRow][minorCol] = mat.matrix[row][col];
                minorCol++;
            }

            minorRow++;
            
            
        }


        return minor;    
        }


// Non-const version
double* squaredMatrix::operator[](size_t index) {
    if (index >= n) throw "Index out of bounds";
    return matrix[index];
}

// Const version
const double* squaredMatrix::operator[](size_t index) const {
    if (index >= n) throw "Index out of bounds";
    return matrix[index];
}

bool squaredMatrix::operator==(squaredMatrix &other)const{
    
    double sum1 = 0;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            sum1 += matrix[i][j];
        }
        
    }

    double sum2 = 0;

    for (size_t i= 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            sum2 += other.matrix[i][j];
        }
        
    }


    return sum1 == sum2;

    
}

bool squaredMatrix::operator!=(squaredMatrix &other)const{

    double sum1 = 0;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            sum1 += matrix[i][j];
        }
        
    }

    double sum2 = 0;

    for (size_t i= 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            sum2 += other.matrix[i][j];
        }
        
    }


    return sum1 != sum2;

}


bool squaredMatrix::operator<(squaredMatrix &other)const{

    double sum1 = 0;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            sum1 += matrix[i][j];
        }
        
    }

    double sum2 = 0;

    for (size_t i= 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            sum2 += other.matrix[i][j];
        }
        
    }


    return sum1 < sum2;
}



bool squaredMatrix::operator>(squaredMatrix &other)const{

    double sum1 = 0;

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            sum1 += this->matrix[i][j];
        }
        
    }

    double sum2 = 0;

    for (size_t i= 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            sum2 += other.matrix[i][j];
        }
        
    }

    return sum1 > sum2;
}
bool squaredMatrix::operator <=(const squaredMatrix &other)const{
    double sum1 = 0;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            sum1 += matrix[i][j];
        }
        
    }

    double sum2 = 0;

    for (size_t i= 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            sum2 += other.matrix[i][j];
        }
        
    }


    return sum1 <= sum2;
}

bool squaredMatrix::operator >=(const squaredMatrix &other)const{
    double sum1 = 0;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            sum1 += matrix[i][j];
        }
        
    }

    double sum2 = 0;

    for (size_t i= 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            sum2 += other.matrix[i][j];
        }
        
    }


    return sum1 >= sum2;
}



squaredMatrix &squaredMatrix::operator~(){


    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = i + 1; j < n; j++)
        {
           double temp = matrix[i][j];
           matrix[i][j] = matrix[j][i];
           matrix[j][i] = temp;
             
        }
        
    }

    return *this;
}


squaredMatrix &squaredMatrix::operator +=(const squaredMatrix &other){
        if (n != other.n) throw "Invalid operation between matrices with different dimensions\n";

        *this = *this + other;
        
return *this;
}

squaredMatrix &squaredMatrix::operator -=(const squaredMatrix &other){
    if (n != other.n) throw "Invalid operation between matrices with different dimensions\n";

   *this = *this - other;
    
return *this;
}

squaredMatrix &squaredMatrix::operator *=(const squaredMatrix &other){
    if (n != other.n) throw "Invalid operation between matrices with different dimensions\n";


  *this = (*this) * other;
  
  return *this;

}



squaredMatrix &squaredMatrix::invertHelper(squaredMatrix &other){

    if (!other == 0) throw "Error: Matrix is not invertable\n";

    squaredMatrix cofactor(n);
    

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            squaredMatrix minor(n);
            minor = subMatrix(j,i,other);
            cofactor.matrix[i][j] = (power(-1 , i + j) * !minor);

        }
        
    }




     

     *this = (~cofactor) * (1.0 / !other);
     



    

    
    return *this;
}

squaredMatrix &squaredMatrix::operator/=(squaredMatrix &other){
    if (!(other) == 0) throw "Error: Matrix isn't invertable\n";
    invertHelper(other);//inverting other


    *this = (*this) * other;


    return *this;



}



squaredMatrix &squaredMatrix::operator %=(const squaredMatrix &other){
    if (n != other.n) throw "Invalid operation between matrices with different dimensions\n";


   *this = *this % other;
    
return *this;

}


squaredMatrix &squaredMatrix::operator %=(size_t natural){
    
    if(natural <= 0) throw "Modulu operation does not support the number you have provided\n";
    *this = *this % natural;


    
return *this;
}









    

