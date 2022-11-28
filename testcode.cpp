//
// Created by 19115 on 2022/10/10.
//

#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

class A
{
};

class Test
{
public:
    int i;
    char c;
    double d;
    A a;
};

int main()
{
    uint64_t a = 5;
    uint64_t b = 6;
    cout << (a + (b - a) / 2) << endl;
    Test t11;
    cout << sizeof(t11) << endl;
    cout << sizeof(t11.i) << endl;
    cout << sizeof(t11.c) << endl;
    cout << sizeof(t11.d) << endl;
    cout << sizeof(t11.a) << endl;
}
