#include <iostream>
#include <vector>

class Matrix
{
public:

    Matrix(int m, int n)
     : m(m), n(n), mat(m*n)
    {
        std::cout << "constructor called" << std::endl;
    }

    Matrix(const Matrix& other)
     : m(other.m), n(other.n), mat(other.mat)
    {
        std::cout << "copy constructor called" << std::endl;
    }

    Matrix& operator = (const Matrix& other)
    {
        std::cout << "copy assignment operator called" << std::endl;

        return *this;
    }

    Matrix operator * (Matrix &B)
    {
        Matrix C(this->m, B.n);
        /* C(i,j) = sum_k A(i,k) * B(k,j) */
        return C; // Compiler return value optimization
    }

private:
    int m,n;
    std::vector<double> mat;
};

int main ()
{
    Matrix A(200, 50), B(50, 200);
    Matrix C = A * B;
    Matrix D(200, 50);
    D = A;
}
