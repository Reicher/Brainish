#ifndef NEURALNET_H
#define NEURALNET_H

#include <vector>
#include "perceptron.h"

using namespace std;

class NeuralNet
{
public:
    NeuralNet(int inputs);

    int run(vector<int> inputs);

    bool train(vector< vector<int> > inputSet, vector<int> resultSet);

private:
    vector< vector<Perceptron> > nodes;

};

#endif // NEURALNET_H
