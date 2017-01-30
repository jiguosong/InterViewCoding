#ifndef Fibonacci_H_
#define Fibonacci_H_

#include <vector>
#include <string>

using std::vector;
using std::string;

class Fibonacci {
public:
    struct BI {
        char Digits[110];
        int LastDigit;
    };

    unsigned long long getNthFibs(int n);

    int howManyFibs(BI &small, BI &big);

    unsigned long long getNthFibs_Binet(int n);

    bool isFib(int n);

private:
    void addBI(BI &a, BI &b, BI &c);
    int compBI(BI &a, BI &b);
    bool perfectSquare(int n);

};

#endif
