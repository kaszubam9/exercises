// wektory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cmath>
#include<random>


using vd = std::vector<double>;
using vd2 = std::vector <vd>;
using std::cout;
using std::cin;
using std::endl;

vd generate(int size)
{


    vd a(size, 0.);

    for (int i = 0; i < size; i++)
    {
        a[i] = rand() % 20;
        cout << a[i] << " ";
    }

    cout << "\n\n";

    return a;
}

double skalar(vd a, vd b, int size)
{
    int skalar = {};

    for (int i = 0; i < size; i++)
    {
        skalar += a[i] * b[i];
    }

    return skalar;
}




int main()
{
    srand(time(NULL));

    int size = 5;

    vd a(size, 0);
    vd b(size, 0);

    a = generate(size);
    b = generate(size);

    cout << "\n Iloczyn skalarny dwoch wektorow: " << skalar(a, b, size) << " z funkcji wbudowanej: " << endl;




    // 2D Matrix

    vd2 ab(size, vd(size, 0.));

    cout << "\n\n Iloczyn zewnetrzny wektorow: " << endl;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            ab[i][j] = a[i] * b[j];

            cout << ab[i][j] << " ";
        }

        cout << endl;

    }

    return 0;
}