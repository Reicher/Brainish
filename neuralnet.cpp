#include "neuralnet.h"
#include <QDebug>

NeuralNet::NeuralNet(int inputs)
{
    qDebug() << "NeuralNet Constructor";

    // adding a 2 - 1 net
    this->nodes.push_back( vector<Perceptron>{ Perceptron(inputs), Perceptron(inputs) } );
    this->nodes.push_back( vector<Perceptron>{ Perceptron(inputs) } );
}
int NeuralNet::run(vector<int> nextInputs){

    vector<int> inputs;
    for(unsigned c = 0; c < this->nodes.size(); ++c){
        inputs = nextInputs;
        nextInputs.clear();
        for(unsigned r = 0; r < this->nodes[c].size(); ++r){
            nextInputs.push_back(this->nodes[c][r].run(inputs));
        }
    }

    return nextInputs[0];
}

bool NeuralNet::train(vector< vector<int> > inputSet, vector<int> resultSet){

    // Super fancy backward propegation training

    return false;
}
