//
// Created by Caleb on 9/27/18.
//

#ifndef INFIXPARSER_INFIXPARSER_H
#define INFIXPARSER_INFIXPARSER_H

#include <cmath>
#include "Evaluator.h"
#include <stack>
#include <map>
#include <string>
#include <iostream>

using namespace std;

class InfixParser {

private:

	//Stack Version
	stack<int> *numStack = new stack<int>();
	stack<char> *opStack = new stack<char>();
	string expression;
	int parentheticalExpressionLayer = 0;
	bool isComparison = false;
	string operators [18] = { "||", "&&", "==", "!=", ">", ">=", "<", "<=", "+", "-", "*", "/", "%", "^", "-", "--", "++", "!" };
	int precedence [18] = { 1,2,3,3,4,4,4,4,5,5,6,6,6,7,8,8,8,8 };
	int numOps = 18;

public:
    //void evaluateOffTop();

	int getPrecedence(string op);
	int binaryevaluator(); //before adding the next operator to the stack, we will run this to perform the last operator and update
	int getNum(string expression, int numStart);

};


#endif //INFIXPARSER_INFIXPARSER_H
