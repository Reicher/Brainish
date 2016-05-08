#include "perceptron.h"
#include <QDebug>
#include <iostream>


Perceptron::Perceptron(vector<Axon *> input, unsigned outputs)
{
    qDebug() << "Perceptron Constructor";

    this->bias = Axon(1); // add bias first

    for(auto i : input)
        this->input.push_back(i);

    for(unsigned o = 0 ; o < outputs; ++o)
        this->output.push_back(new Axon());
}

void Perceptron::Update(){
    int sum = this->bias.getWeightedValue();
    for(Axon* in : this->input)
        sum += in->getWeightedValue();

    float finalOut = sum >= 0.5 ? 1.0 : 0.0;

    // Set Outputs
    for(Axon* out : this->output)
        out->set(finalOut);
}

vector<Axon*> Perceptron::getOutput(){
    return this->output;
}
