#ifndef MATRIX_NXN
#define MATRIX_NXN
#include <iostream>



namespace Squared_Matrix{

  
    class squaredMatrix{

        private:
        double **matrix;
        size_t n;

        squaredMatrix submatrix(size_t j, size_t i,size_t numElement);


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
        squaredMatrix operator%(squaredMatrix &other);
        squaredMatrix operator%(uint modulu);
        squaredMatrix operator/(double scalar);
        squaredMatrix operator^(uint power);
        squaredMatrix &operator++();
        squaredMatrix &operator--();
        squaredMatrix operator++(int);
        squaredMatrix operator--(int);
        double operator~();
        //squaredMatrix operator[](int index)const;
        // bool operator==(squaredMatrix &other)const;
        // bool operator!=(squaredMatrix &other)const;
        // bool operator <(squaredMatrix &other)const;
        // bool operator >(squaredMatrix &other)const;
        // bool operator <=(const squaredMatrix &other)const;
        // bool operator >=(const squaredMatrix &other)const;
        // squaredMatrix operator !();
        // squaredMatrix operator +=(const squaredMatrix &other);
        // squaredMatrix operator -=(const squaredMatrix &other);
        // squaredMatrix operator *=(const squaredMatrix &other);
        //  squaredMatrix operator /=(const squaredMatrix &other);
        // squaredMatrix operator %=(const squaredMatrix &other);
        // friend std::ostream& operator<<(std::ostream &os, const squaredMatrix &other);






    };







};






#endif