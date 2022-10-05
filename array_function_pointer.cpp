/**
 * @file array_function_pointer.cpp
 * @author 郝春城 (fobydn@163.com)
 * @brief 指针函数数组的运用，非常重要的内容
 * @version 0.1
 * @date 2022-10-03
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
// various notations,same signatures

const double *f1(const double ar[], int n);
const double *f2(const double[], int);
const double *f3(const double *, int);

using namespace std;
int main(void)
{
    double av[3] = {1112.3, 1542.6, 2227.9};
    //声明一个指针并指向一个函数
    const double *(*p1)(const double *, int) = f1;
    auto p2 = f2;
    // C++11标准可以把p2自动推断成：
    // coust double *(*p2)(const double *,int)
    cout << "Using pointers to functions:\n";
    cout << "Address value\n";
    cout << (*p1)(av, 3) << ": " << *(*p1)(av, 3) << endl;
    cout << p2(av, 3) << ": " << *p2(av, 3) << endl;

    // pa 是一个指针数组
    // auto无法初始化列表
    const double *(*pa[3])(const double *, int) = {f1, f2, f3};
    //但它对于初始化单个值确实有效
    // pb是指向pa第一个元素的指针
    auto pb = pa;
    //以上代码对于C++11而言被推断为：
    // const double *(**pb)(const double *, int)=pa;

    cout << "\nUsing an array of pointers to function:\n";
    cout << "Address value\n";
    for (int i = 0; i < 3; i++)
        cout << pa[i](av, 3) << ": " << *pa[i](av, 3) << endl;
    cout << "\nUsing a pointers to a pointers to a function:\n";
    cout << "Address value\n";
    for (int i = 0; i < 3; i++)
        cout << pb[i](av, 3) << ": " << *pb[i](av, 3) << endl;

    //指向函数指针数组的指针是什么样的呢？
    cout << "\nUsing pointers an array of function pointers:\n";
    cout << "Address value\n";
    //声明pc的简单方法
    auto pc = &pa;
    //以上代码对于C++11而言被推断为：
    // const double *(*(*pc[3]))(const double *, int)=&pa;
    cout << (*pc)[0](av, 3) << ": " << *(*pc)[0](av, 3) << endl;
    //用复杂的语法声明pd
    const double *(*(*pd)[3])(const double *, int) = &pa;
    //在pdb中存贮返回值
    const double *pdb = (*pd)[1](av, 3);
    cout << pdb << ": " << *pdb << endl;
    //标识符替换
    cout << (*(*pd)[2])(av, 3) << ": " << *(*(*pd)[2])(av, 3) << endl;
    cin.get();
    return 0;
}

/**
 * @brief 返回一个double指针,没有任何作用
 *
 * @param ar double 指针
 * @param n 数量
 * @return const double*
 */
const double *f1(const double *ar, int n)
{
    return ar;
}

/**
 * @brief 返回一个double指针,没有任何作用
 *
 * @param ar double数组
 * @param n 数量
 * @return const double*
 */
const double *f2(const double ar[], int n)
{
    return ar + 1;
}

/**
 * @brief 返回一个double指针,没有任何作用
 *
 * @param ar double数组
 * @param n 数量
 * @return const double*
 */
const double *f3(const double ar[], int n)
{
    return ar + 2;
}