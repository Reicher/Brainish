#include <QCoreApplication>
#include <iostream>
#include <QDebug>

#include "perceptron.h"
#include "neuralnet.h"
#include "testset.h"

using namespace std;

typedef vector< vector<int> > IntInputSets;

vector<float> keyboardInput(int n)
{
    vector<float> inputs;
    for(int i = 0; i < n; ++i){
        cout << "Input " << i+1 << ": ";

        float buff;
        cin >> buff;
        inputs.push_back(buff);
    }

    return inputs;
}

void getTrainingSet(vector< TestSet> &testSet){

    testSet.push_back( TestSet( {1, 1} , { 1 } ) );
    testSet.push_back( TestSet( {1, 0} , { 0 } ) );
    testSet.push_back( TestSet( {0, 1} , { 0 } ) );
    testSet.push_back( TestSet( {0, 0} , { 0 } ) );
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int N = 2;

    NeuralNet *net = new NeuralNet(2, 0, 0, 1);

    vector<TestSet> trainingSet;
    getTrainingSet(trainingSet);

    bool trainingOK = true;//handler->Train(net, trainingSet, trainingSet);

    if(trainingOK){
        cout << "Training Done!" << endl;
        vector<float> result = net->Run(keyboardInput(N));
        qDebug() << "Result: " << result[0];
    }
    else
        cout << "Training Failed!" << endl;

    return 0;
}


