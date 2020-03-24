#include <iostream>
#include <fstream>
#include <random>


#include "LeftistPQ.hpp"

void intTest() {
    LeftistPQ<int> lpq;
    srand(time(0));
    for (int i = 10; i >= 0; i--) {
        lpq.insert(rand() % 100);
    }
    // Test to see if it built correctly.
    std::cout << lpq << std::endl;
}

int main(int argc, char const **argv)
{
    intTest();
    return 0;
}
