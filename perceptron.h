#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include "testset.h"
#include "axon.h"

using namespace std;

class Perceptron
{
public:
    Perceptron(vector<Axon *> inputs, unsigned outputs);

    void Update();
    vector<Axon*> getOutput();

private:
    Axon bias;
    vector<Axon*> input;
    vector<Axon*> output;

};

#endif // PERCEPTRON_H
