#include "perceptron.h"
#include <QDebug>
#include <iostream>


Perceptron::Perceptron(int inputs)
{
    qDebug() << "Perceptron Constructor";
    this->trained = false;
    this->learningRate = 0.1;

    // + 1 for bias
    for(int i = 0; i < inputs+1; ++i){
        float r =  static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        this->weights.push_back(r);
    }
}

int Perceptron::run(std::vector<int> inputs)
{
    // add bias
    inputs.insert(inputs.begin(), 1);

    // Weighted sum
    float sum = 0;
    for(unsigned i = 0; i < inputs.size(); ++i){
        sum += (float)inputs[i] * this->weights[i];
    }
    // Step Function
    return sum > 0.5 ? 1 : -1;
}

void Perceptron::updateWeights(std::vector<int> input, int goal){
    input.insert(input.begin(), 1); // add bias

    for(unsigned w = 0; w < this->weights.size(); ++w) // update weights
        this->weights[w] += this->learningRate
            * goal
            * input[w];
}


bool Perceptron::train(std::vector< std::vector<int> > inputSet, std::vector<int> resultSet)
{
    int maxTries = 100;
    int tries = 0;
    do{
        bool fail = false;
        for(unsigned i = 0; i < inputSet.size(); ++i){
            std::vector<int> input = inputSet[i];

            int goal = resultSet[i];
            int result = run(input);

            if(result != goal){
                updateWeights(input, goal);
                fail  = true;
                }
            }
            this->trained = !fail;
            ++tries;
        }while(!this->trained && tries < maxTries);
    qDebug() << "Tries: " << tries;

    return this->trained;
}
