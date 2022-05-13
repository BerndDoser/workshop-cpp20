#include <numeric>
#include <iostream>
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

auto norm(Matrix auto matrix)
{
    return std::accumulate(std::begin(matrix.value), std::end(matrix.value), 0);
}

int main()
{
    DenseMatrix A;
    std::cout << norm(A) << std::endl;

    SparseMatrix B;
    std::cout << norm(B) << std::endl;

    //std::cout << norm(1) << std::endl;
}