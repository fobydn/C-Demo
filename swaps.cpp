/**
 * @file swaps.cpp
 * @author 郝春城 (fobydn@163.com)
 * @brief 引用一旦初始化就无法更换目标，但指针可以。
 * @version 0.1
 * @date 2022-10-04
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>

void swapr(int &a, int &b);
void swapp(int *p, int *q);
void swapv(int a, int b);

int main(void)
{
    using namespace std;
    int wallet1 = 300;
    int wallet2 = 350;
    cout << "wallet1 = $" << wallet1;
    cout << "       wallet2 = $" << wallet2 << endl;

    cout << "Using references to swap contents:\n";
    swapr(wallet1, wallet2);
    cout << "wallet1 = $" << wallet1;
    cout << "       wallet2 = $" << wallet2 << endl;

    cout << "Using pointers to swap contents again:\n";
    swapp(&wallet1, &wallet2);
    cout << "wallet1 = $" << wallet1;
    cout << "       wallet2 = $" << wallet2 << endl;

    cout << "Trying to use passing by value:\n";
    swapv(wallet1, wallet2);
    cout << "wallet1 = $" << wallet1;
    cout << "       wallet2 = $" << wallet2 << endl;

    cin.get();

    return 0;
}
/**
 * @brief 引用类型数据交换
 *
 * @param a
 * @param b
 */
void swapr(int &a, int &b)
{
    int temp;

    temp = a;
    a = b;
    b = temp;
}
/**
 * @brief 指针类型数据交换
 *
 * @param p
 * @param q
 */
void swapp(int *p, int *q)
{
    int temp;

    temp = *p;
    *p = *q;
    *q = temp;
}
/**
 * @brief 基本类型数据交
 *
 * @param a
 * @param b
 */
void swapv(int a, int b)
{
    int temp;

    temp = a;
    a = b;
    b = temp;
}