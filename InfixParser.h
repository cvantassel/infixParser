//
// Created by Caleb on 9/27/18.
//

#ifndef INFIXPARSER_INFIXPARSER_H
#define INFIXPARSER_INFIXPARSER_H

#include <queue>
#include "Evaluator.h"
#include <stack>
#include <map>
#include <string>

using namespace std;

class InfixParser {

private:

    queue<int> *numQ = new queue<int>();
    queue<char> *opQ = new queue<char>();

	//Stack Version
	stack<int> *numStack = new stack<int>();
	stack<char> *opStack = new stack<char>();
	string expression;
	bool parentheticalExpression = false;
	bool isComparison = false;
	string operators[] = { "||", "&&", "==", "!=", ">", ">=", "<", "<=", "+", "-", "*", "/", "%", "^", "-", "--", "++", "!" };
	int precedence[] = { 1,2,3,3,4,4,4,4,5,5,6,6,6,7,8,8,8,8 };
	int numOps

public:
    void evaluateOffTop();
	int getPrecedence(char op);

};


#endif //INFIXPARSER_INFIXPARSER_H
