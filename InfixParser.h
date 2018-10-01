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
	stack<string> *opStack = new stack<string>();
	stack<int> *compNumStack = new stack<int>();
	stack<string> *compOpStack = new stack<string>();
	string expression; //Assign expression to this if we want to construct the parser with the expression in it -Landon
	//int parentheticalExpressionLayer = 0; //I think this will work to keep track of how many parthesese deep we are in an expression -Landon
	// Pretty sure the recursive function handles this -Caleb
	string operators [18] = { "||", "&&", "==", "!=", ">", ">=", "<", "<=", "+", "-", "*", "/", "%", "^", "-", "--", "++", "!" };
	int precedence [18] = { 1,2,3,3,4,4,4,4,5,5,6,6,6,7,8,8,8,8 };
	char comparisonOps [18] = { };
	int numOps = 18;
	string couldBeTwo = "|&!=><+-";
	string openParenthesis = "([{";
	string closeParenthesis = ")]}";

public:
    //void evaluateOffTop();
	int getPrecedence(string op); //Returns precedence based on arrays found in private variables (doesn't handle parentheses)
	int binaryevaluator(); //may need parameters but should be fine with only stacks
	int comparisonEvaluator();
	int getNumLength(string expression, int numStart); //Returns the length of the digit
	int getNum(string expression, int numStart, int numLength); //Converts and returns substring of digits
	int parse(string expression); //Main function
	bool isIncrementOrDecrement(string expression, int startPos); //Checks if next char in string denotes increment or decrement
	bool isComparisonWithTwoChar(string expression, int startPos); //Checks if next character is string denotes boolean operator
	bool isLogical(string expression, int startPos); //Checks if next char in string denotes increment or decrement
	bool checkvalidity(char checkarray[], char stringarray[], int sizecheck, int sizestring);
};


#endif //INFIXPARSER_INFIXPARSER_H
