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

int InfixParser::getPrecedence(char op)
{
	for (int i = 0; i < 18; i++) {
		if (operators[i] == op)
			return precedence[i];

	}

	//TODO: Raise Error
}
