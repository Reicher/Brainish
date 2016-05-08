#include "neuralnet.h"
#include <QDebug>

NeuralNet::NeuralNet(unsigned inputs, unsigned hiddenLayers, unsigned perHiddenLayer, unsigned outputs)
{
    qDebug() << "NeuralNet Constructor";

    // input
    for(unsigned i = 0; i < inputs; ++i)
        this->input.push_back(new Axon());

    // Hidden layers
    auto outAxon = this->input;
    for(unsigned l = 0; l < hiddenLayers; ++l){
        for(unsigned n = 0; n < perHiddenLayer; ++n){
            unsigned axonN = (l == hiddenLayers-1) ? 1 : perHiddenLayer;

            auto newPerceptron = Perceptron(outAxon, axonN);
            this->perceptron.push_back(newPerceptron);
            outAxon = newPerceptron.getOutput();
        }
    }

    // output layer
    for(unsigned o = 0; o < outputs; ++o){
        auto newPerceptron = Perceptron(outAxon, 1);
        this->perceptron.push_back(newPerceptron);
        this->output.push_back(newPerceptron.getOutput()[0]);

    }
}

vector<float> NeuralNet::Run(vector<float> runSet)
{
    vector<float> result;

    for(unsigned n = 0; n < runSet.size(); ++n)
        this->input[n]->set(runSet[n]);

    for(int i = 0; i < 10; ++i){ // really really stupid, need something scaleable
        for(Perceptron P : this->perceptron)
            P.Update();
    }

    for(Axon* Ax : this->output)
        result.push_back(Ax->getWeightedValue());

    return result;
}

bool NeuralNet::Train(vector<TestSet> trainingSet, vector<TestSet> testSet)
{
    return false;
}

void NeuralNet::setInput(unsigned n, float in){
    this->input[n]->set(in);
}

vector<Axon*> NeuralNet::getInputs(){
    vector<Axon*> inputs;

    return inputs;
}
