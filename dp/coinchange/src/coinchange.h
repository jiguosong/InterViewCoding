#ifndef coinchange_H_
#define coinchange_H_

#include <vector>
#include <string>

using std::vector;
using std::string;

class coinchange {
public:
    int coinChange(vector<int> &coins, int amount);   // min number of coins to make up to amount
    int waystoChange(vector<int> &coins, int amount);  // number of ways to make up to amount

private:

};

#endif
