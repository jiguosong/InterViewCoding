/*
https://en.wikipedia.org/wiki/Fibonacci_number#Recognizing_Fibonacci_numbers
http://stackoverflow.com/questions/7843048/finding-the-closest-fibonacci-numbers#7843192

 F(1) = 1; F(2) = 1; F(n) = F(n-1) + F(n-2);
 */

#include "Fibonacci.h"
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>

#define pi acos(-1.0)
using namespace std;


unsigned long long Fibonacci::getNthFibs(int n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 1;

    int a = 1;
    int b = 1;
    int c = 0;

    for (int i = 3; i <= n; ++i) {
        c = a + b;
        b = a;
        a = c;
    }

    return (unsigned long long) c;
}

// phi = (1 + \sqrt{5}) / 2    -- golden ratio
unsigned long long Fibonacci::getNthFibs_Binet(int n)
{
    double phi = (1 + std::sqrt(5)) / (double)2;
    return (unsigned long long) std::floor(std::pow(phi, n)/std::sqrt(5)+0.5);
}

bool Fibonacci::isFib(int n)
{
    return perfectSquare(5 * n * n + 4) || perfectSquare(5 * n * n - 4);
}

bool Fibonacci::perfectSquare(int n)
{
    int x = (int) std::sqrt(n);
    return x * x == n;
}


void Fibonacci::addBI(BI &a, BI &b, BI &c)
{
    for (int i = 0; i < 110; i++)
        c.Digits[i] = 0;
    int carry = 0;
    c.LastDigit = max(a.LastDigit, b.LastDigit);
    for (int i = 0; i <= c.LastDigit; i++) {
        c.Digits[i] = (a.Digits[i] + b.Digits[i] + carry) % 10;
        carry = (a.Digits[i] + b.Digits[i] + carry) / 10;
    }
    if (carry)
        c.Digits[++c.LastDigit] = carry;
    return;
}

int Fibonacci::compBI(BI &a, BI &b)
{
    if (a.LastDigit != b.LastDigit)
        return a.LastDigit > b.LastDigit;

    for (int i = a.LastDigit; i >= 0; i--)
        if (a.Digits[i] != b.Digits[i])
            return a.Digits[i] > b.Digits[i];

    return -1;
}

int Fibonacci::howManyFibs(BI &small, BI &big)
{
    BI *a, *b, *c;
    a = new BI;
    b = new BI;
    c = new BI;

    for (int i = 0; i < 110; i++)
        a->Digits[i] = b->Digits[i] = 0;
    a->Digits[0] = 1;
    b->Digits[0] = 1;
    a->LastDigit = 0;
    b->LastDigit = 0;

    int nFibs = 0;
    bool reached = false;
    while (1) {
        if (compBI(*b, small) && compBI(*b, big) < 1)
            nFibs++;
        else if (compBI(*b, big) == 1)
            break;
        addBI(*a, *b, *c);
        //swap(b, c);
        //swap(a, c);
    }
    return nFibs;
}





