#include <vector>
#include <random>
#include <memory>
#include <iostream>
#include "alloc.hpp"

using namespace std;

constexpr int num_tries = 10000000;

int uniform(int a, int b) {
    static default_random_engine engine;
    uniform_int_distribution<int> distribution{a, b-1};
    return distribution(engine);
}

int main() {
    vector<unique_ptr<Fast>> blocks;
    
    for (size_t i = 0; i < num_tries; i++) {
        if (uniform(0, 2) == 0) {
            // allocate
            blocks.push_back(move(make_unique<Fast>()));
        } else {
            if (blocks.size() > 0) blocks.pop_back();
        }
    }
}
