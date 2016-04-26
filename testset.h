#ifndef TESTSET_H
#define TESTSET_H

#include <vector>

using namespace std;

class TestSet
{
public:
    TestSet(vector<int> input, vector<int> goal);
    TestSet(int input[], int goal[]);

    vector<int> input, goal;
};

#endif // TESTSET_H
