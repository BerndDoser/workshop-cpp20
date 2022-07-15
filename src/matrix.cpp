#include <vector>

class Matrix
{
public:

    Matrix(int m, int n)
     : m(m), n(n), mat(m*n)
    {}

    Matrix operator * (Matrix B)
    {
        Matrix C(this->m, B.n);
        /* C(i,j) = sum_k A(i,k) * B(k,j) */
        return C;
    }

private:
    int m,n;
    std::vector<double> mat;
};

int main ()
{
    Matrix A(200, 50), B(50, 200);
    Matrix C = A * B;
}
