/*

*/

#include <fstream>
#include <iostream>
#include "readlastklines.h"

void readlastklines::dummy() {
}

void readlastklines::ReadLastKLines(char *filename, int k) {
    if (filename == nullptr) return;

    vector<string> karray(k, "");
    std::ifstream file(filename);

    int sz = 0;
    while (file) {
        if (!getline(file, karray[sz % k])) break;
        ++sz;
    }

    int cnt = std::min(sz, k);
    int start = (sz > k) ? sz % k : 0;

    for (int i = 0; i < cnt; ++i) {
        std::cout << karray[(start + i) % k] << std::endl;
    }
}


