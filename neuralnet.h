#ifndef NEURALNET_H
#define NEURALNET_H

#include "perceptron.h"

#include <vector>


using namespace std;

class NeuralNet
{
public:
    NeuralNet(int inputs);

    vector<int> run(vector<int> inputs);

    bool train(std::vector< TestSet > trainingSet);

private:
    void updateWeights(std::vector<int> input, float error);

    vector< vector<Perceptron> > layer;
    bool trained;
    float learningRate;

};

#endif // NEURALNET_H
