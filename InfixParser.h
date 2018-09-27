//
// Created by Caleb on 9/27/18.
//

#ifndef INFIXPARSER_INFIXPARSER_H
#define INFIXPARSER_INFIXPARSER_H

#include <queue>
#include "Evaluator.h"

using namespace std;

class InfixParser {
private:
    queue<int> *numQ = new queue<int>();
    queue<char> *opQ = new queue<char>();
public:
    void evaluateOffTop();
};


#endif //INFIXPARSER_INFIXPARSER_H
