#ifndef INPUT_H
#define INPUT_H

class Axon
{
public:
    Axon(int startValue = 0);

    void set(float input);
    float getWeightedValue();

    void tune(float deltaError, float learningRate);

private:
    float weight, raw_input;
};

#endif // INPUT_H
