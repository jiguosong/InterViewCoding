/*

*/

#include "convertFIFOtoLIFO.h"

void convertFIFOtoLIFO::FIFOtoLIFO(std::queue<int> &queue)
{
    if (queue.empty()) return;

    std::stack<int> stack;

    while (!queue.empty()) {
        stack.push(queue.front());
        queue.pop();
    }

    while(!stack.empty()) {
        queue.push(stack.top());
        stack.pop();
    }
}

