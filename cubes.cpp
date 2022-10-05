/**
 * @file cubes.cpp         C++primer plus  程序清单8.5
 * @author 郝春城 (fobydn@163.com)
 * @brief
 * @version 0.1
 * @date 2022-10-04
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
double cube(double a);
double refcube(double &ra);

int main(void)
{
    using namespace std;
    double x = 3.0;
    cout << cube(x);
    cout << " = cube of " << x << endl;
    cout << refcube(x);
    cout << " = cube of " << x << endl;
    cin.get();
    return 0;
}

double cube(double a)
{
    a *= a * a;
    return a;
}

double refcube(double &ra)
{
    ra *= ra * ra;
    return ra;
}