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

//int InfixParser::binaryevaluator()
//{
//	int oper1;
//	int oper2;
//	int result;
//	if (opstack.top() == '-') {
//			oper2 = num.top();
//			val.pop();
//			oper1 = num.top();
//			val.pop();
//			result = oper1 - oper2;
//			val.push(result);
//			opstack.pop();
//			return result;
//		}
//
//	if (opstack.top() == '*') {
//		oper2 = num.top();
//		val.pop();
//		oper1 = num.top();
//		val.pop();
//		result = oper1 * oper2;
//		val.push(result);
//		opstack.pop();
//		return result;
//	}
//
//	if (opstack.top() == '/') {
//		oper2 = num.top();
//		val.pop();
//		oper1 = num.top();
//		val.pop();
//		if (oper2 == 0) {
//			cout << "You cannot divide by 0!";
//		}
//		else {
//			result = oper1 / oper2;
//		}
//		opstack.pop();
//		return result;
//	}
//	if (opstack.top() == '+') {
//		oper2 = num.top();
//		val.pop();
//		oper1 = num.top();
//		val.pop();
//		result = oper1 + oper2;
//		val.push(result);
//		opstack.pop();
//		return result;
//	}
//	if (opstack.top() == '%') {
//		oper2 = num.top();
//		val.pop();
//		oper1 = num.top();
//		val.pop();
//		result = oper1 % oper2;
//		val.push(result);
//		opstack.pop();
//		return result;
//	}
//	if (opstack.top() == '^') {
//		oper2 = num.top();
//		val.pop();
//		oper1 = num.top();
//		val.pop();
//		result = pow(oper1, oper2);
//		val.push(result);
//		opstack.pop();
//		return result;
//	}
//}

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

	while (pos < expression.size) {


		if (isdigit(expression[pos])) {
			//Gets the rest of the digit and increments position accordingly
			int digitLength = getNumLength(expression, pos);
			int operand = getNum(expression, pos, digitLength);
			pos += digitLength;

			//Push to operand stack
			opStack->push(operand);
		}

		//Check for increment and decrement
		//TODO: push it to the stack accounting for precedence
		if ((&expression[pos] == "+") || (&expression[pos] == "-"))
		{
			if (isIncrementOrDecrement(expression, pos)) {
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

int InfixParser::getPrecedence(string op)

	//pass in operator (doesn't account for parenthesis)
	{
		for (int i = 0; i < 18; i++) {
			if (operators[i] == op)
				return precedence[i];
		}

		//TODO: Raise Error
	}
