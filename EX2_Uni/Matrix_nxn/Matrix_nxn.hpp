#ifndef MATRIX_NXN
#define MATRIX_NXN
#include <iostream>



namespace Squared_Matrix{

    class squaredMatrix{

        private:
        double **matrix;
        size_t n;

        squaredMatrix subMatrix(size_t j, size_t i,squaredMatrix mat);
        squaredMatrix &invertHelper(squaredMatrix &other);

        double power(double number, size_t power){
            double res = 0;
            size_t i = 0;
            while (i < power)
            {
                res += number *number;
                i++;
            }

            return res;
            
            
        }


        public:
        squaredMatrix(size_t n) :n(n){

            this->matrix = new double*[n];

            for (size_t i = 0; i < n; i++){
               matrix[i] = new double[n];
            }
            
        }

        squaredMatrix(squaredMatrix &other){
            this->n = other.n;
            this->matrix = new double*[n];

            for (size_t i = 0; i < n; i++)
            {
                this->matrix[i] = new double[n]();
                for (size_t j = 0; j < n; j++)
                {
                    this->matrix[i][j] = other.matrix[i][j];
                }
                
            }
            
            


        }


        ~squaredMatrix(){
            for (size_t i = 0; i < n; i++)
            {
                delete[] this->matrix[i];
            }

            delete[] this->matrix;

        }
        double** getMatrix()const {
            return (this->matrix);
        }

        void printMatrix() const;
        squaredMatrix &operator=(const squaredMatrix &other);
        squaredMatrix operator-(const squaredMatrix &other)const;
        squaredMatrix operator+(const squaredMatrix &other)const;
        squaredMatrix operator*(const squaredMatrix &other)const;
        squaredMatrix operator*(double scalar);
        squaredMatrix operator%(const squaredMatrix &other);
        squaredMatrix operator%(uint modulu);
        squaredMatrix operator/(double scalar);
        squaredMatrix operator^(uint power);
        squaredMatrix &operator++();
        squaredMatrix &operator--();
        squaredMatrix operator++(int);
        squaredMatrix operator--(int);
        double operator!();
        double* operator[](size_t index);                    // for non-const access
        const double* operator[](size_t index) const;        // for const access    
         bool operator ==(squaredMatrix &other)const;
         bool operator!=(squaredMatrix &other)const;
         bool operator <(squaredMatrix &other)const;
         bool operator >(squaredMatrix &other)const;
         bool operator <=(const squaredMatrix &other)const;
         bool operator >=(const squaredMatrix &other)const;
         squaredMatrix &operator ~();
         squaredMatrix &operator +=(const squaredMatrix &other);
         squaredMatrix &operator -=(const squaredMatrix &other);
         squaredMatrix &operator *=(const squaredMatrix &other);
         squaredMatrix &operator /=(squaredMatrix &other);
         squaredMatrix &operator %=(const squaredMatrix &other);
         squaredMatrix &operator %=(size_t natural);


         friend std::ostream& operator<<(std::ostream &os, squaredMatrix &other){
            size_t size = other.n;
        
        
            for (size_t i = 0; i < size; i++)
            {
               for (size_t j = 0; j < size; j++)
               {
        
                if (j != size - 1) 
                os << other.matrix[i][j] << ", ";
        
                else 
                os << other.matrix[i][j];
        
               }
               os << "\n";
               
            }
        
            return os;
        }



    };
    
    







};






#endif