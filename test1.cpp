#include <iostream>
#include <typeinfo>

int f1(const char c[]);
int f2(const char *);
// int *p1(const char *c);
int judge(int &p1);
int add(int a);

int main(void)
{
    using namespace std;

    int a = 255;
    int &b = a;
    cout << "基本类型a:" << a << endl;
    cout << "引用类型b:" << b + 1 << endl;

    cout << "基本类型add方法:" << typeid(a).name() << endl;
    cout << "引用类型judge:" << typeid(b).name() << endl;
    cin.get();
}

int judge(int &p1)
{
    return p1 + 2;
}

int add(int a)
{
    return a + 3;
}