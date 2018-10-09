//
// Created by Caleb on 9/27/18.


#include "Evaluator.h"
#include <stack>
#include <string>
#include <cmath>

bool Evaluator::isOperand(char opr) {
	return (opr == '+' || opr == '-' || opr == '*' || opr == '/');
}

int Evaluator::evaluate(std::stack<int>* numStack, std::stack<std::string>* opStack) {
	int result;

	if (opStack->top() == "++") {
		int oper1 = numStack->top();
		numStack->pop();
		result = oper1 + 1;
		numStack->push(result);
		opStack->pop();
		return result;
	}
	else if (opStack->top() == "--") {
		int oper1 = numStack->top();
		numStack->pop();
		result = oper1 - 1;
		numStack->push(result);
		opStack->pop();
		return result;
	}
	else if (opStack->top() == "!") {
        int oper1 = numStack->top();
        numStack->pop();
        result = !oper1;
        numStack->push(result);
        opStack->pop();
        return result;
	}
	else if (opStack->top() == "- ") {
        int oper2 = numStack->top();
        numStack->pop();
        numStack->push(oper2 * -1);
        opStack->pop();
        return result;
	}
	else if (opStack->top() == "/") {
		int oper2 = numStack->top();
		numStack->pop();
		int oper1 = numStack->top();
		numStack->pop();
		if (oper2 == 0) {
			throw "You cannot divide by 0!";
		}
		else {
			result = oper1 / oper2;
		}
		opStack->pop();
		return result;
	}
	else {
        std::string operator1 = opStack->top();
		int oper2 = numStack->top();
		numStack->pop();
		int oper1 = numStack->top();
		numStack->pop();

        if (operator1 == "-") result = oper1 - oper2;
		else if (operator1 == "*") result = oper1 * oper2;
        else if (operator1 == "+") result = oper1 + oper2;
        else if (operator1 == "%") result = oper1 % oper2;
        else if (operator1 == "^") result = pow(oper1, oper2);
        else if (operator1 == "<=") result = (oper1 <= oper2);
        else if (operator1 == "<") result = (oper1 < oper2);
        else if (operator1 == ">=") result = (oper1 >= oper2);
        else if (operator1 == ">") result = (oper1 > oper2);
        else if (operator1 == "!=") result = (oper1 != oper2);
        else if (operator1 == "==") result = (oper1 == oper2);
        else if (operator1 == "&&") result = (oper1 && oper2);
        else if (operator1 == "||") result = (oper1 || oper2);

		numStack->push(result);
		opStack->pop();
		return result;
	}
}