//
// Created by Caleb on 9/27/18.
//

#include "InfixParser.h"

void InfixParser::evaluateOffTop() {
    // Function used when you are ready to evaluate the top two
    // numbers in the NUM stack by the top operand in the OP stack

    // Create string with expression from stacks
    string exp;
    exp += std::to_string(numQ->front()) + opQ->front();
    // Remove used numbers
    numQ->pop();
    opQ->pop();
    exp += std::to_string(numQ->front());
    // Evaluate and put back in stack
    if (opQ->front() == '(')
        opQ->pop();
    numQ->push(Evaluator::evaluate(exp));
}

int InfixParser::binaryevaluator()
{
	int oper1;
	int oper2;
	int result
		if (opstack.top() == '-') {
			oper2 = num.top();
			val.pop();
			oper1 = num.top();
			val.pop();
			result = oper1 - oper2;
			val.push(result);
			opstack.pop();
			return result;
		}

	if (opstack.top() == '*') {
		oper2 = num.top();
		val.pop();
		oper1 = num.top();
		val.pop();
		result = oper1 * oper2;
		val.push(result);
		opstack.pop();
		return result;
	}

	if (opstack.top() == '/') {
		oper2 = num.top();
		val.pop();
		oper1 = num.top();
		val.pop();
		if (oper2 == 0) {
			cout << "You cannot divide by 0!";
		}
		else {
			result = oper1 / oper2;
		}
		opstack.pop();
		return result;
	}
	if (opstack.top() == '+') {
		oper2 = num.top();
		val.pop();
		oper1 = num.top();
		val.pop();
		result = oper1 + oper2;
		val.push(result);
		opstack.pop();
		return result;
	}
	if (opstack.top() == '%') {
		oper2 = num.top();
		val.pop();
		oper1 = num.top();
		val.pop();
		result = oper1 % oper2;
		val.push(result);
		opstack.pop();
		return result;
	}
	if (opstack.top() == '^') {
		oper2 = num.top();
		val.pop();
		oper1 = num.top();
		val.pop();
		result = pow(oper1, oper2);
		val.push(result);
		opstack.pop();
		return result;
	}
	int InfixParser::getPrecedence(char op)
	{
		for (int i = 0; i < 18; i++) {
			if (operators[i] == op)
				return precedence[i];

		}

		//TODO: Raise Error
	}
