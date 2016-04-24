#ifndef NEURALNET_H
#define NEURALNET_H

#include <vector>


class NeuralNet
{
public:
    NeuralNet(int inputs);

    int run(std::vector<int> inputs);

    bool train(std::vector< std::vector<int> > inputSet, std::vector<int> resultSet);
};

#endif // NEURALNET_H
