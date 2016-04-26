#include <QCoreApplication>
#include <iostream>
#include <QDebug>

#include "perceptron.h"
#include "neuralnet.h"
#include "testset.h"

using namespace std;

typedef vector< vector<int> > IntInputSets;

vector<int> keyboardInput(int n)
{
    vector<int> inputs;
    for(int i = 0; i < n; ++i){
        cout << "Input " << i+1 << ": ";

        int buff;
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
    Perceptron *test = new Perceptron(N);
    //NeuralNet *test = new NeuralNet(N);

    vector<TestSet> trainingSet;
    getTrainingSet(trainingSet);

    bool trainingOK = test->train(trainingSet);

    if(trainingOK){
        cout << "Training Done!" << endl;
        int result = test->run(keyboardInput(N));
        qDebug() << "Result: " << result;
    }
    else
        cout << "Training Failed!" << endl;

    return 0;
}


