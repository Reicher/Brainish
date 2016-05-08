#include "axon.h"

#include <stdlib.h>

Axon::Axon(int startValue)
    : raw_input(startValue)
{
    this->weight = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

void Axon::set(float input)
{
    this->raw_input = input;
}

float Axon::getWeightedValue()
{
    return this->raw_input * this->weight;
}

void Axon::tune(float deltaError, float learningRate)
{
    this->weight += learningRate * deltaError * this->raw_input;
}
