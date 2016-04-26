#include "perceptron.h"
#include <QDebug>
#include <iostream>


Perceptron::Perceptron(int inputs)
    : trained(false)
    , learningRate(0.1)
{
    qDebug() << "Perceptron Constructor";

    this->bias = Input(); // add bias first

    for(int i = 0; i < inputs; ++i)
        this->input.push_back(Input());
}

float Perceptron::run(vector<int> input)
{
    //qDebug() << "Input: " << input[0] << ", " << input[1];

    // Set all input,sum all weighted inputs
    float sum = 0;
    for( auto i : input) {
        this->input[i].set((float)input[i]);
        sum += this->input[i].getWeightedValue();
    }
    // Step Function
    bool output = sum > 0.5 ? 1.0 : 0.0;

    //qDebug() << "Ouput: " << output;
    return output;
}


bool Perceptron::train(vector<TestSet> trainingSet)
{
    int maxTries = 100;
    int tries = 0;
    bool failed;

    do
    {
        failed = false;
        for(auto s : trainingSet)
            if(!this->tune(s))
                failed = true;

        tries++;
    }while (failed && tries < maxTries);

    this->trained = !failed;

    return this->trained;
}

// Returns true if there is no more tuning to be done for this set
bool Perceptron::tune(TestSet trainingSet)
{
    float result = this->run(trainingSet.input);
    float deltaError = trainingSet.goal[0] - result;
    bool trained = abs(deltaError) < this->learningRate;

    if( !trained ){
        bias.tune(deltaError, this->learningRate);
        for(auto &i : this->input)
            i.tune(deltaError, this->learningRate);
    }

    return trained;
}
