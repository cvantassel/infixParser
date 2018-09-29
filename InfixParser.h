//
// Created by Caleb on 9/27/18.
//

#ifndef INFIXPARSER_INFIXPARSER_H
#define INFIXPARSER_INFIXPARSER_H

#include <queue> //queue or stack?
#include <cmath>
#include "Evaluator.h"

using namespace std;

class InfixParser {
private:
    queue<int> *numQ = new queue<int>();
    queue<char> *opQ = new queue<char>();
public:
    void evaluateOffTop();
	int binaryevaluator(); //before adding the next operator to the stack, we will run this to perform the last operator and update 
};


#endif //INFIXPARSER_INFIXPARSER_H
