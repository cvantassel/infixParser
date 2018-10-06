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
#include "Evaluator.h"
#include <algorithm>

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
	string operators [20] = { "(", "||", "&&", "==", "!=", ">", ">=", "<", "<=", "+", "-", "*", "/", "%", "^", "-", "--", "++", "!", ")"};
	int precedence [20] = { 0,1,2,3,3,4,4,4,4,5,5,6,6,6,7,8,8,8,8,9 };
	char comparisonOps [18] = { };
	int numOps = 18;
	string couldBeTwo = "|&!=><+-";
	string openParenthesis = "([{";
	string closeParenthesis = ")]}";

	char check[23] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '!', '<', '>', '=', '-', '+', '*', '/', '&', '|', '(', ')', '^' }; //added up-carrot-Landon
	int arrsize = size(check);

public:
    //void evaluateOffTop();
	int getPrecedence(string op); //Returns precedence based on arrays found in private variables (doesn't handle parentheses)
	int comparisonEvaluator();
	int getNumLength(string expression, int numStart); //Returns the length of the digit
	int getNum(string expression, int numStart, int numLength); //Converts and returns substring of digits
	int parse(string expression); //Main function
	bool isIncrementOrDecrement(string expression, int startPos); //Checks if next char in string denotes increment or decrement
	bool isComparisonWithTwoChar(string expression, int startPos); //Checks if next character is string denotes boolean operator
	bool isLogical(string expression, int startPos); //Checks if next char in string denotes increment or decrement

	bool checkvalidity(char checkarray[], char stringarray[], int sizecheck, int sizestring); //checks input string for valid characters
	bool matchedparenthesis(string expression); //Checks input string to make sure parenthesis are matched
	
	bool makeParsable(string &expression); //Returns parseable or Error Message

};


#endif //INFIXPARSER_INFIXPARSER_H
