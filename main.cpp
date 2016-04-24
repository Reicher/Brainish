#include <QCoreApplication>
#include <iostream>
#include <QDebug>
#include "perceptron.h"

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

void getTrainingSet(IntInputSets &inputs, vector<int> &results){
    inputs.push_back( vector<int>{ 1, 1 } );
    inputs.push_back( vector<int>{ 0, 0 } );
    inputs.push_back( vector<int>{ 1, 0 } );
    inputs.push_back( vector<int>{ 0, 1 } );
    results = vector<int>{ -1, 1, -1, -1 };
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int N = 2;
    Perceptron *test = new Perceptron(N);

    IntInputSets trainInput;
    vector<int> trainResults;
    getTrainingSet(trainInput, trainResults);
    bool trainingOK = test->train(trainInput, trainResults);

    if(trainingOK){
        cout << "Training Done!" << endl;
        int result = test->run(keyboardInput(N));
        qDebug() << "Result: " << result;
    }
    else
        cout << "Training Failed!";

    return 0;
}


