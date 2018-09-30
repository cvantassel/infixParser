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

int InfixParser::binaryevaluator()
{
	int oper1;
	int oper2;
	int result;
	if (opStack.top() == '-') {
			oper2 = numStack.top();
			numStack.pop();
			oper1 = numStack.top();
			numStack.pop();
			result = oper1 - oper2;
			numStack.push(result);
			opStack.pop();
			return result;
	}

	if (opStack.top() == '*') {
		oper2 = numStack.top();
		numStack.pop();
		oper1 = num.top();
		numStack.pop();
		result = oper1 * oper2;
		numStack.push(result);
		opStack.pop();
		return result;
	}

	if (opStack.top() == '/') {
		oper2 = numStack.top();
		val.pop();
		oper1 = numStack.top();
		numStack.pop();
		if (oper2 == 0) {
			cout << "You cannot divide by 0!";
		}
		else {
			result = oper1 / oper2;
		}
		opStack.pop();
		return result;
	}
	if (opStack.top() == '+') {
		oper2 = numStack.top();
		numStack.pop();
		oper1 = numStack.top();
		numStack.pop();
		result = oper1 + oper2;
		val.push(result);
		opStack.pop();
		return result;
	}
	if (opStack.top() == '%') {
		oper2 = numStack.top();
		numStack.pop();
		oper1 = numStack.top();
		numStack.pop();
		result = oper1 % oper2;
		numStack.push(result);
		opStack.pop();
		return result;
	}
	if (opStack.top() == '^') {
		oper2 = numStack.top();
		numStack.pop();
		oper1 = numStack.top();
		numStack.pop();
		result = pow(oper1, oper2);
		numStack.push(result);
		opStack.pop();
		return result;
	}
}

int InfixParser::getNumLength(string expression, int numStart)
{
	//Pass in string expression and position of the first digit in the number

	if (!isdigit(expression[numStart]))
		cout << "Precondition violated" << endl;
		//TODO: Raise Error

	else {
		int length = 0;
		for (int i = numStart; isdigit(expression[i]); i++)
			length++;
		return length;
	}
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

	int pos = 0;

	while (pos < expression.length()) {

		//Handle Parenthesis with Recursion
		//Will be easier to test when .parse() is functional
		//TODO: Handle mismatched parenthesis
		//TODO: Hanlde empty parenthesis
		if (openParenthesis.find(expression[pos]) != std::string::npos)
		{
			string closing = closeParenthesis[openParenthesis.find(expression[pos])];
			int subLength = (expression.find(closing, pos + 1) - pos);
			string subExpression = expression.substr(pos + 1, subLength - 1); //Doesn't include outermost parenthesis
			opStack->push(parse(subExpression));
		}


		if (isdigit(expression[pos])) {
			//Gets the rest of the digit and increments position accordingly
			int digitLength = getNumLength(expression, pos);
			int operand = getNum(expression, pos, digitLength);
			pos += digitLength;

			//Push to operand stack
			opStack->push(operand);
		}

		//Check for double two character operators and adjust position accordingly
		//TODO: push it to the stack accounting for precedence
		if (couldBeTwo.find(expression[pos]) != std::string::npos) {

			if (isIncrementOrDecrement(expression, pos) || isComparisonWithTwoChar(expression, pos) || isLogical(expression, pos)) {
				string op = expression.substr(pos, 2);
				pos += 2;
			}
			else {
				string op = string(&expression[pos]);
				pos++;
			}

		}

	}

	//TODO: Clear stacks at the end to allow for repeated use
}

bool InfixParser::isIncrementOrDecrement(string expression, int startPos)
{
	//Checks for ++ and --

	if (expression[startPos] == expression[startPos++])
		return true;
	else
		return false;
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
	if (expression[startPos] == expression[startPos++])
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

int InfixParser::getPrecedence(string op){
	//pass in operator (doesn't account for parenthesis)	
	for (int i = 0; i < 18; i++) {
			if (operators[i] == op)
				return precedence[i];
		}

		//TODO: Raise Error
	}

