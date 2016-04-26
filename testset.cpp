#include "testset.h"

TestSet::TestSet(vector<int> input, vector<int> goal)
{
    this->input = input;
    this->goal = goal;
}

TestSet::TestSet(int input[], int goal[])
{
    vector<int> inputVec(input, input + sizeof input / sizeof input[0]);
    vector<int> goalVec(goal, goal + sizeof goal / sizeof goal[0]);

    this->input = inputVec;
    this->goal = goalVec;
}
