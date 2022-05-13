#include <iostream>
#include <cmath>
#include <numeric>
#include <vector>

struct DenseMatrix
{
    std::vector<double> value;
};

struct SparseMatrix
{
    std::vector<double> key;
    std::vector<double> value;
};

template <typename T>
concept Matrix = requires (T x) { x.value; };

auto norm2(Matrix auto matrix)
{
    double sum = 0.0;
    for (auto v : matrix.value) { sum += std::pow(v,2); }
    return std::sqrt(sum);
}

int main()
{
    DenseMatrix A;
    std::cout << norm2(A) << std::endl;

    SparseMatrix B;
    std::cout << norm2(B) << std::endl;

    //std::cout << norm(1) << std::endl;
}