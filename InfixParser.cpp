//
// Created by Caleb on 9/27/18.
//


#include "InfixParser.h"


int InfixParser::comparisonEvaluator() {
	int oper1;
	int oper2;
	int result;

	return 0; //Not sure where your going with this but I needed to add a return statement to allow the main to run -Landon
};

int InfixParser::getNumLength(string expression, int numStart)
{
	//Pass in string expression and position of the first digit in the number

	int length = 0;
	for (int i = numStart; isdigit(expression[i]); i++)
		length++;
	return length;
}

int InfixParser::getNum(string expression, int numStart, int numLength)
{
	string numStr = expression.substr(numStart, numLength);
	return stoi(numStr);
}

int InfixParser::parse(string expression)
{

	Evaluator* evaluator = new Evaluator();

	//Check Validity and erase whitespaces
	bool parsable = makeParsable(expression);
	if (!parsable)
		return -1;

	//Position in Expression
	int pos = 0;

	while (pos < expression.length()) {

		//Two steps with each loop
		//Step 1: Get new operand or operator
		//Step 2: If operator then check precedence and either
		//			a)If precedence greater push to stack
		//			b)Else evaluate stack then push
		//Finally: Evaluate rest of stack

		//Step 1: Get new operand or operator

		// Case: operand
		if (isdigit(expression[pos])) {

			//Gets the rest of the digit and increments position accordingly
			int digitLength = getNumLength(expression, pos);
			int operand = getNum(expression, pos, digitLength);
			pos += digitLength;

			//Push to operand stack
            lastPush = operand;
			numStack->push(operand);
		}

		//Case: operator
		else {

			//Op to be pushed
			string newOp;

			//Case: possible two character operator
			if (couldBeTwo.find(expression[pos]) != std::string::npos) {

				//Case: some two character operator
				if (isComparisonWithTwoChar(expression, pos) || isDoubleChar(expression, pos)) {

					newOp = expression.substr(pos, 2);
                    pos += 2;

				}

				//Case: Could've been two character but wasn't
				else {
					newOp = expression[pos];
					pos++;

					//handle negative
					if (!isdigit(expression[pos - 1]) && newOp == "-")
						newOp += " ";
				}

			}

			//Case: Single character operator
			else {

				newOp = expression[pos];
				pos++;
			}

            if (find(noTwoBinaryOps.begin(), noTwoBinaryOps.end(), newOp) != noTwoBinaryOps.end()) {
                if (find(noTwoBinaryOps.begin(), noTwoBinaryOps.end(), lastPush) !=
                    noTwoBinaryOps.end())
                    throw runtime_error("Two binary operators in a row @ char " + (pos));
                else if (find(unaryOps.begin(), unaryOps.end(), lastPush) != unaryOps.end())
                    throw runtime_error("A unary operand can't be followed by a binary operator @ char " + pos);
            }



			//Step 2: Check precedence => push or evaluate&push (Note: we're still inside the operator condition)


			//Case: Operator Stack Empty
			if (opStack->empty()) {
                lastPush = newOp;
				opStack->push(newOp);
			}

			//Case: operator stack not empty
			else {

				int curOpPrecedence = getPrecedence(newOp);
				int topOpPrecedence = getPrecedence(opStack->top());

				//temporary
				std::string operator1 = opStack->top();


				//Case: Precedence of new operator greater so just push to opStack
				if (curOpPrecedence >= topOpPrecedence || curOpPrecedence == 0 || curOpPrecedence == 0) {
				    lastPush = newOp;
					opStack->push(newOp);
				}

				//Case: Precedence of new operator less
				else {

					//Evaluate stack until new operator precedence is less than top operator or until stack empty
					do {
						if (opStack->top() == ")") {
							opStack->pop();
							while(opStack->top() != "(") {
							    try {
                                    evaluator->evaluate(numStack, opStack);
							    } catch (exception &e) {
							        cerr << e.what() << "@ char " << pos << endl;
							    }
							}
							opStack->pop();

						}
						else {
                            try {
                                evaluator->evaluate(numStack, opStack);
                            } catch (exception &e) {
								cerr << e.what() << "@ char " << pos << endl;
                            }
                        }
					} while (!opStack->empty() && curOpPrecedence < getPrecedence(opStack->top()));
					lastPush = newOp;
					opStack->push(newOp);
				}

			}

		}
	}

	//Finally: Evaluate rest of stack and return result

	/*while (!opStack->empty()) {
		if (opStack->top() == "(" || opStack->top() == ")")
			opStack->pop();
		if (!opStack->empty())
			evaluator->evaluate(numStack, opStack);
	}*/

	while (!opStack->empty()) {

		int closingCount = 0;
		if (opStack->top() == ")") {
			closingCount++;
			opStack->pop();
			while (opStack->top() != "(" || closingCount > 1) {
				if (opStack->top() == ")"){
					closingCount++;
					opStack->pop();
				}
				else if (opStack->top() == "(") {
					opStack->pop();
					closingCount--;
				}
				else {
                    try {
                        evaluator->evaluate(numStack, opStack);
                    } catch (exception &e) {
						cerr << e.what() << "@ char " << pos << endl;
                    }
				}
			}
			opStack->pop();
			closingCount--;
		}

		else{
            try {
                evaluator->evaluate(numStack, opStack);
            } catch (exception &e) {
				cerr << e.what() << "@ char " << pos << endl;
            }
		}
	}

	int result = numStack->top();
	numStack->pop();
	return result;
}

bool InfixParser::isComparisonWithTwoChar(string expression, int startPos)
{
	//Pass if char at startPos is !,=,<,> and see if next is =
	string nextChar = &expression[startPos];
	return (nextChar.at(1) == '=');
}


bool InfixParser::isDoubleChar(string expression, int startPos)
{
	string nextChar = &expression[startPos];
	char checkChar = nextChar.at(1);
	return nextChar.at(0) == checkChar;
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
			return true;

		switch (expression[i]) {
		case ')':
			if (par.top() == '{' || par.top() == '[')
				return true;
			par.pop();
			break;

		case '}':
			if (par.top() == '(' || par.top() == '[')
				return true;
			par.pop();
			break;

		case ']':
			if (par.top() == '(' || par.top() == '{')
				return true;
			par.pop();
			break;
		}
		return (par.empty());
	}
}

bool InfixParser::makeParsable(string &expression)
{

	// Error checking
	
	// Start of string
    char badStarts[10] = {'|', '&', '=', '>', '<', '^','*', '/', '%', ')'};
	if (badStarts[9] == expression[0]) throw runtime_error("Expression can't start with a closing parentheses @ char 0");
    for (int i = 0; i < 10; i++)
    	if (badStarts[i] == expression[0]) throw runtime_error("Expression can't start with a binary operator @ char 0");

	// Two operands check
	for (int i = 0; i < expression.length()-2; i++) {
		char temp = expression[i];
		if (isdigit(expression[i]))
			if (expression[i+1] == ' ')
				if (isdigit(expression[i+2])) throw runtime_error("Two operands in a row @ char" + i);
	}


		//Remove Spaces
	expression.erase(remove_if(expression.begin(), expression.end(), isspace), expression.end());
	//
	//	//Move String to Array
	int stringsize = expression.length();
	char stringarray[1024];
	strcpy_s(stringarray, expression.c_str());

	//Check Validity
	bool isValid = checkvalidity(check, stringarray, arrsize, stringsize);//will output 1 if only valid characters are input
	bool parenthesisValid = matchedparenthesis(expression); //checks to make sure parenthesis are matched

	if (isValid && parenthesisValid)
		return true;
	else
		return false; //TODO ERROR MESSAGES
}

int InfixParser::getPrecedence(string op) {
	//pass in operator (doesn't account for parenthesis)	
	int size = sizeof(operators) / sizeof(operators[0]);
	for (int i = 0; i < size; i++) {

		if (operators[i] == op)
			return precedence[i];

	}

}