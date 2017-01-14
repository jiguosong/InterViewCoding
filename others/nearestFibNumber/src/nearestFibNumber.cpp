/*
http://stackoverflow.com/questions/7843048/finding-the-closest-fibonacci-numbers#7843192
*/

#include "nearestFibNumber.h"

void nearestFibNumber::dummy()
{
}

#include <cmath>
#include <iostream>

const double pheta = 0.5 * (std::sqrt(5) + 1);

double fib(unsigned int n)
{
    return (std::pow(pheta, n) - std::pow(1 - pheta, n)) / std::sqrt(5);
}

// fib(100) -- 354224848179263111168
// 2^64     -- 18446744073709551616
// fib(1000) -- 43466557686938914862637500386755014010958388901725051132915256476112292920052539720295234060457458057800732025086130975998716977051839168242483814062805283311821051327273518050882075662659534523370463746326528
// so in 64bit machine, max 100 is enough
unsigned int fibo_lowerbound(double N, unsigned min = 0, unsigned max = 1000)
{
    unsigned newpivot = (min + max) / 2;
    if (min == newpivot)
        return newpivot;

    if (fib(newpivot) <= N)
        return fibo_lowerbound(N, newpivot, max);
    else
        return fibo_lowerbound(N, min, newpivot);
}

std::pair<double, double> fibo_range(unsigned int n)
{
    unsigned int lbound = fibo_lowerbound(n);
    return std::make_pair(fib(lbound), fib(lbound + 1));
}


unsigned long long nearestFibNumber::FindNearestFibNumber(unsigned int n)
{
    std::pair<double, double> range = fibo_range(n);
    std::cout << "Fibonacci range wrapping " << n << " is "
    << "[" << (unsigned long long) range.first << ", " << (unsigned long long) range.second << "]"
    << std::endl;

    return (unsigned long long) range.first < (unsigned long long) range.second ?
           (unsigned long long) range.first : (unsigned long long) range.second;
}


