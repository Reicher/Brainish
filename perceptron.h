#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include "testset.h"
#include "input.h"

using namespace std;

class Perceptron
{
public:
    Perceptron(int inputs);

    float run(vector<int> input);

    bool tune(TestSet trainingSet);
    bool train(vector<TestSet> trainingSet);

private:

    Input bias;
    vector<Input> input;

    bool trained;
    float learningRate;
};

#endif // PERCEPTRON_H
