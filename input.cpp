#include "input.h"

#include <stdlib.h>

Input::Input()
{
    this->raw_input = 0;
    this->weight = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

void Input::set(float input)
{
    this->raw_input = input;
}

float Input::getWeightedValue()
{
    return this->raw_input * this->weight;
}

void Input::tune(float deltaError, float learningRate)
{
    this->weight += learningRate * deltaError * this->raw_input;
}
