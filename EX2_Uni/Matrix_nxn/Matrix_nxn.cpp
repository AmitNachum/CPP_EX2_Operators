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


squaredMatrix squaredMatrix::operator%(squaredMatrix &other){
    squaredMatrix result = squaredMatrix(this->n);

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            double value = this->getMatrix()[i][j];
            double otherValue = other.getMatrix()[i][j];

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
    
    squaredMatrix res(n);
    squaredMatrix temp1(n);

    for (size_t i = 0; i < power; i++)
    {
        squaredMatrix temp2(n);
        temp2 = *this;

        temp1 = temp2 *temp2;
        


    }
    
    res = temp1;
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

double squaredMatrix::operator~(){
    double determinant = 0;
    if (n == 2)
    {
        return matrix[0][0] * matrix[1][1] -matrix[1][0] * matrix[0][1];
    }

    size_t i = 0

    for (size_t j = 0; j < n - 1; j++)
    {
        squaredMatrix minor = subMatrix(j,i,n);
        double detMinor = ~minor;
        determinant = 

    }
    
    
}

squaredMatrix squaredMatrix::submatrix(size_t j,size_t i,size_t numElement){

        if(numElement == 0){
            return squaredMatrix ret(0);
        }

        squaredMatrix minor(numElement);


        size_t row = 0;
        size_t col = 0;


        while( row < numElement && col < numElement){
            if (row == i || col == j)
            {
                continue;
            }

            minor.matrix[row][col] = matrix[i][j];
            
        }



        return submatrix(j,i,numElement - 1);




}




    





