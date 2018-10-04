//
// Created by Caleb on 9/27/18.
//


#include "InfixParser.h"


//void InfixParser::evaluateOffTop() {
//    // Function used when you are ready to evaluate the top two
//    // numbers in the NUM stack by the top operand in the OP stack
//
//    // Create string with expression from stacks
//    string exp;
//    exp += std::to_string(numQ->front()) + opQ->front();
//    // Remove used numbers
//    numQ->pop();
//    opQ->pop();
//    exp += std::to_string(numQ->front());
//    // Evaluate and put back in stack
//    if (opQ->front() == '(')
//        opQ->pop();
//    numQ->push(Evaluator::evaluate(exp));
//}

int InfixParser::comparisonEvaluator() {
	int oper1;
	int oper2;
	int result;


};

int InfixParser::getNumLength(string expression, int numStart)
{
	//Pass in string expression and position of the first digit in the number

	// This would never get executed because we check before we call the function -Caleb
//	if (!isdigit(expression[numStart]))
//		cout << "Precondition violated" << endl;
//		//TODO: Raise Error

//	else {
		int length = 0;
		for (int i = numStart; isdigit(expression[i]); i++)
			length++;
		return length;
//	}
}

int InfixParser::getNum(string expression, int numStart, int numLength)
{
	string numStr = expression.substr(numStart, numLength);
	return stoi(numStr);
}

int InfixParser::parse(string expression)
{
	//This is where the magic happens
	//PreCondition: Pass string with no whitepaces (or invalid characters if possible)
	//PostCondtion: Result

	Evaluator* evaluator = new Evaluator();


	int pos = 0;

	while (pos < expression.length()) {

		//Handle Parenthesis with Recursion
		//Will be easier to test when .parse() is functional
		//TODO: Handle mismatched parenthesis | we should do this upon reading the expression.
		int openType = static_cast<int>(openParenthesis.find(expression[pos]));
		if (openType != std::string::npos) {
			// Evaluate the contents of the parenthesis
			int closingLocation = static_cast<int>(expression.find(closeParenthesis[openType], pos)); // Location of ending parenthesis
			//unsigned long subLength = expression.find(closing);
			if (pos + 2 < closingLocation) {
				// You must have at least two characters between parenthesis to make an evaluation
				string subExpression = expression.substr(pos + 1, closingLocation - 1); //Doesn't include outermost parenthesis
				numStack->push(parse(subExpression));
			} else {
				cout << "Not enough characters in parenthesis.";
			}

			pos = closingLocation; // Increment position to skip past parenthesis
		}

		// Handle digit
		if (isdigit(expression[pos])) {
			//Gets the rest of the digit and increments position accordingly
			int digitLength = getNumLength(expression, pos);
			int operand = getNum(expression, pos, digitLength);
			pos += digitLength;

			//Push to operand stack
			numStack->push(operand);
		}

		// Handle comparison and 'crement
		//TODO: push it to the stack accounting for precedence
		else if (couldBeTwo.find(expression[pos]) != std::string::npos) {

			if (isIncrementOrDecrement(expression, pos)) {
				numStack->push(1);
				if (expression[pos] == '+'){
					opStack->push("++");
				} else if (expression[pos] == '-') {
					opStack->push("--");
				}
				pos += 2;
			} else if(isComparisonWithTwoChar(expression, pos) || isLogical(expression, pos)) {
				string op = expression.substr(pos, 2);

				// Evaluate everything on the LHS of the operator
				while (!opStack->empty()){
					evaluator->evaluate(numStack, opStack);
				}

				// Populate compStacks
				numStack->push(numStack->top());
				numStack->pop();


				if (!opStack->empty()) {
					int curOpPrecedence = operators->find(expression[pos]);
					int topOpPrecedence = operators->find(opStack->top());
					if (precedence[curOpPrecedence] < precedence[topOpPrecedence]) {  // Compare precedence
						comparisonEvaluator();
					} else {
						opStack->push(op);
					}
				}

				// Make sure there's nothing left over
				if (!numStack->empty())
					throw ("Invalid string, leftover number");
				pos += 2;
			}

		}
			else {
			// not sure the point of this... -Caleb
			string op = string(&expression[pos]);
			pos++;
			}


		// Handle operator
		string computations = "+-*/%^";
		if (computations.find(expression[pos]) != std::string::npos ) {
			if (!opStack->empty()) {
				string opstack = opStack->top();
				string expression1 = string(1, expression[pos]);
				int curOpPrecedence = operators->find(expression1);
				int topOpPrecedence = operators->find(opstack);

				int op = getPrecedence(opstack);
				int exp = getPrecedence(expression1);
				//if (precedence[curOpPrecedence] < precedence[topOpPrecedence]) {  // Compare precedence
				if (getPrecedence(expression1) < getPrecedence(opstack)) {  // Compare precedence
					evaluator->evaluate(numStack, opStack);
					opStack->push(expression1);
				} else {
					string s(1, expression[pos]); // Convert to string
					opStack->push(s);
				}
			} else {
				string s(1, expression[pos]); // Convert to string
				opStack->push(s);
			}
			pos++;
		}

	}

	// After string is fully parsed...
	// Evaluate everything in the arithmetic stack
	while (!opStack->empty()){
		evaluator->evaluate(numStack, opStack);
	}
	// If the comparison stack was populated..
	if (!opStack->empty()) {
		// Push what's left from the arithmetic stack
		numStack->push(numStack->top());
		// Evaluate everything in the comparison stack
		while (!opStack->empty()){
			comparisonEvaluator();
		}
		return numStack->top();
	}
	return numStack->top();
}

bool InfixParser::isIncrementOrDecrement(string expression, int startPos)
{
	//Checks for ++ and --

	if (&expression[startPos] == "+" || &expression[startPos] == "-") {
		if (expression[startPos] == expression[startPos++])
			return true;
		else
			return false;
	}
	else {
		return false;
	}
}

bool InfixParser::isComparisonWithTwoChar(string expression, int startPos)
{
	//Pass if char at startPos is !,=,<,> and see if next is =
	if (&expression[startPos++] == "=")
		return true;
	else
		return false;
}


bool InfixParser::isLogical(string expression, int startPos)
{
	if (expression[startPos] == expression[startPos+1])
		return true;
	else
		return false;
}

bool InfixParser::checkvalidity(char checkarray[], char stringarray[], int sizecheck, int sizestring)
{
	int j = 0;
	for (int i = 0; i < sizestring; i++)
	{
		for (j = 0; j < sizecheck; j++)
		{
			if (stringarray[i] == checkarray[j])
				break;
		}
		if (j == sizecheck)
			return false;
	}
	return true;
}

bool InfixParser::matchedparenthesis(string expression)
{
	//based off of the formula from https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/
	string openpar = "([{";
	string closepar = ")]}";
	stack<char> par;
	for (int i = 0; i < expression.length(); i++) {
		if (openpar.find(expression[i])) {
			par.push(expression[i]);
			continue;
		}

		if (closepar.find(expression[i]) && par.empty())
			return false;

		switch (expression[i]) {
		case ')':
			if (par.top() == '{' || par.top() == '[')
				return false;
			par.pop();
			break;

		case '}':
			if (par.top() == '(' || par.top() == '[')
				return false;
			par.pop();
			break;

		case ']':
			if (par.top() == '(' || par.top() == '{')
				return false;
			par.pop();
			break;
		}
		return (par.empty());
	}
}

int InfixParser::getPrecedence(string op){
	//pass in operator (doesn't account for parenthesis)	
	for (int i = 0; i < 18; i++) {
			if (operators[i] == op)
				return precedence[i];
		}

		//TODO: Raise Error
	}

