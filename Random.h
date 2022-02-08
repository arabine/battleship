#ifndef RANDOM_H
#define RANDOM_H

#include <random>

class Random
{
public:
    Random() {
        set(1, 10);
    }
    Random(int low, int high) {
        set(low, high);
    }

    // Set the distribution parameters low and high.
    void set(int low, int high) {
        std::uniform_int_distribution<int>::param_type param(low, high);
        _dist.param(param);
    }

    // Get random integer.
    int get() {
        return _dist(_gen);
    }

private:
    std::random_device _rd{};
    std::mt19937 _gen{_rd()};
    std::uniform_int_distribution<int> _dist;
};

#endif // RANDOM_H
