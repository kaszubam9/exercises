// matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include<string>
#include<algorithm>
#include<random>
#include<numeric>

using vec = std::vector<int>;
using mat = std::vector<vec>;
using std::cout, std::cin, std::endl, std::setw;


auto    CreateRandomVector(const int kFrom, const int kTo, const int kNumOfTrials)
{

    std::random_device rd;
    std::mt19937 mtRandomEngine(rd());
    std::uniform_int_distribution uni_distr(kFrom, kTo);
    std::vector< int >    random_decimals;

    generate_n(back_inserter(random_decimals), kNumOfTrials, [&]() { return uni_distr(mtRandomEngine); });

    return random_decimals;
}



auto CreateMatrix(int row, int col) {


    mat m(row, vec(col, 0));

    return m;
}


void GenRandMatrix(mat& m) {

    int kFrom(1);
    int kTo(15);

    for (int i = 0; i < m.size(); i++) {
        m[i] = CreateRandomVector(kFrom, kTo, m[0].size());
    }

}

void PrintM(mat& m1, std::string name) {

    cout << "\n\nPrinting matrix " << name << "\n\n";

    for (int i = 0; i < m1.size(); ++i) {
        for (int j = 0; j < m1[0].size(); ++j) {

            cout << setw(3) << m1[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\n\n\n";

}

auto Add(mat m1, mat m2) {

    cout << "\n\na + b\n\n";
    mat ma(CreateMatrix(m1.size(), m1[0].size()));

    for (int i = 0; i < m1.size(); ++i) {
        for (int j = 0; j < m1[0].size(); ++j) {
            ma[i][j] = m1[i][j] + m2[i][j];

            cout << setw(3) << ma[i][j] << " ";
        }
        cout << endl;
    }

    return ma;
}

auto Sub(mat m1, mat m2) {

    cout << "\n\na - b\n\n";

    mat ma(CreateMatrix(m1.size(), m1[0].size()));

    for (int i = 0; i < m1.size(); ++i) {
        for (int j = 0; j < m1[0].size(); ++j) {
            ma[i][j] = m1[i][j] - m2[i][j];

            cout << setw(3) << ma[i][j] << " ";
        }
        cout << endl;
    }

    return ma;
}

auto Mul(mat m1, mat m2) {


    mat ma(CreateMatrix(m1.size(), m1[0].size()));

    for (int i = 0; i < m1.size(); ++i) {
        for (int j = 0; j < m2[0].size(); ++j) {
            for (int k = 0; k < m1[0].size(); ++k) {
                ma[i][j] = m1[i][k] * m2[k][j];

            }

        }

    }

    return ma;
}



int main()
{
    int col = 5;
    int row = 5;

    mat a(CreateMatrix(row, col));
    mat b(CreateMatrix(row, col));



    GenRandMatrix(a);
    GenRandMatrix(b);

    PrintM(a, "a");
    PrintM(b, "b");


    mat add(Add(a, b));

    mat sub(Sub(a, b));

    mat mul(Mul(a, b));

    PrintM(mul, "a * b");


}
