#include "neuralnet.h"
#include <QDebug>

NeuralNet::NeuralNet(int inputs)
{
    qDebug() << "NeuralNet Constructor";

    // adding a 2 - 1 net
    this->layer.push_back( vector<Perceptron>{ Perceptron(inputs), Perceptron(inputs) } );
    this->layer.push_back( vector<Perceptron>{ Perceptron(inputs) } );
}
vector<int> NeuralNet::run(vector<int> nextInputs){

    vector<int> inputs;
    for(unsigned c = 0; c < this->layer.size(); ++c){
        inputs = nextInputs;
        nextInputs.clear();
        for(unsigned r = 0; r < this->layer[c].size(); ++r){
            int output = this->layer[c][r].run(inputs);
            nextInputs.push_back(output);
        }
    }

    return nextInputs;
}

bool NeuralNet::train(vector< TestSet > trainingSet){

    return this->trained;
}
