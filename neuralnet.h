#ifndef NEURALNET_H
#define NEURALNET_H

#include "perceptron.h"
#include "axon.h"

#include <vector>


using namespace std;

class NeuralNet
{
public:
    NeuralNet(unsigned inputs, unsigned hiddenLayers, unsigned perHiddenLayer, unsigned outputs);

    bool Train(vector<TestSet> trainingSet, vector<TestSet> testSet);

    vector<float> Run(vector<float> runSet);

    // creates a Perceptron and returns a pointer to the output
    float* AddPerceptron(vector<Axon *> inputs);

    void setInput(unsigned n, float in);
    vector<Axon*> getInputs();

private:
    vector<Axon*> input;
    vector<Axon*> output;
    vector<Perceptron> perceptron;
};

#endif // NEURALNET_H
