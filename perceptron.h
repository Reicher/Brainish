#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <vector>

class Perceptron
{
public:
    Perceptron(int inputs);

    int run(std::vector<int> inputs);

    bool train(std::vector< std::vector<int> > inputSet, std::vector<int> resultSet);

private:
    void updateWeights(std::vector<int> input, int goal);

    std::vector<float> weights;
    float learningRate;
    bool trained;
};

#endif // PERCEPTRON_H
