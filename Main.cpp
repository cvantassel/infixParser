//
// Created by Caleb on 9/27/18.
//

#include "InfixParser.h"
//#include "Evaluator.h"

#include <iostream>
#include <string>
#include <algorithm>
//#include <bits/valarray_before.h>

using namespace std;

int main() {


	//Tests from project sheet
	string ex1 = "1+2*3";
	int answ1 = 7;

	string ex2 = "2+2^2*3";
	int answ2 = 14;

	string ex3 = "1==2";
	int answ3 = 0; //or False

	string ex4 = "1+3 > 2";
	int answ4 = 1; //or True

	string ex5 = " (4>=4) && 0";
	int answ5 = 0; //or False

	string ex6 = " (1+2) *3";
	int answ6 = 9;

	string ex7 = "++++2-5* (3^2)";
	int answ7 = -41;

	string testExList[] = { ex1, ex2, ex3, ex4, ex5, ex6, ex7 };
	int testAnswList[] = { answ1,answ2,answ3,answ4,answ5,answ6, answ7 };

	//Parser Object
	InfixParser* parser = new InfixParser();

	// Ensure all characters are valid
	char check[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '!', '<', '>', '=', '-', '+', '*', '/', '&', '|', '(', ')' };
	int arrsize = size(check);

	int succeessCount = 0;
	int failCount = 0;

	for (int i = 0; i < testExList->length(); i++) {

		string curTest = testExList[i];

		//Delete Spaces
		curTest.erase(remove_if(str.begin(), str.end(), isspace), str.end());

		//Move String to Array
		int stringsize = curTest.length();
		char stringarray[1024];
		strcpy_s(stringarray, curTest.c_str());

		bool isValid = parser->checkvalidity(check, stringarray, arrsize, stringsize);//will output 1 if only valid characters are input
		bool parenthesisValid = parser->matchedparenthesis(curTest); //checks to make sure parenthesis are matched

		if (isValid && parenthesisValid) {

			//PARSE!!
			int testAttempt = parser->parse(curTest);

			//Check results
			bool passed;
			string testState;
			if (testAttempt == testAnswList[i]) {
				passed = true;
				succeessCount++;
				testState = "PASSED";
			}
			else {
				passed = false;
				failCount++;
				testState = "FAILED";
			}

			//Output Results
			cout << "TEST" << i << " ==> " << testExList[i] << endl;
			cout << "ANSWER ==> " << testAnswList[i] << endl;
			cout << "ATTEMPT ==> " << testAttempt << endl;
			cout << "TEST " << testState << endl;
			cout << endl;

		}

	}

	//This reads through the string, first deletes all spaces, then it goes through and makes sure that only numbers and valid symbols are input-Kole
//	str.erase(remove_if(str.begin(), str.end(), isspace), str.end());

	// Move string to array
//	int stringsize = str.length();
//	char stringarray[1024];
//	strcpy_s(stringarray, str.c_str());

	// Ensure all characters are valid
//	char check[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '!', '<', '>', '=', '-', '+', '*', '/', '&', '|', '(', ')' };
//	int arrsize = size(check);
//	InfixParser* p = new InfixParser();
//	bool isValid = v->checkvalidity(check, stringarray, arrsize, stringsize);//will output 1 if only valid characters are input
//	bool parenthesisValid = p->matchedparenthesis(str); //checks to make sure parenthesis are matched
//	cout << isValid;

	/*
	 * I've taken some liberties as far as how we will handle boolean expressions and arithmetic expressions, as I
	 * wasn't able to find anything about it in the README.
	 *
	 * Essentially, I've made it so that there's two more stacks in the InfixParser class, for evaluating comparisons.
	 * I originally planned on making two instances of InfixParser, but that breaks with parenthesis.
	 * So now, whenever there's a comparison operator found, it will push the result
	 * of the LHS of the comparison to the new stack, then the comparison operator, then clear the original stack and go
	 * on to evaluate the RHS.
	*/

	/*
	if (isValid) {

		cout << "yeet";

		// Check that it starts with a valid character
		if (str[0] == '>' || str[0] == '<' || str[0] == '|' || str[0] == '&' || str[0] == '=' || str[0] == '*'
			|| str[0] == '/' || str[0] == '%' || str[0] == '^')
			throw ("Invalid string");

		// Send it through the parser
		InfixParser* parser = new InfixParser();

		int result = parser->parse(str);

		cout << "The result is " << result << endl;
	}
	*/

	// if you come to a boolean comparison, evaluate everything in stack before moving on



    /* As far as the arithmetic evaluation goes, essentially all that really needs to be done is we need to:
     * 1. parse expression
     * 2. tell when a pair of numbers are ready to be evaluated.
     * 3. check the next operator to see if we should evaluate
     *   based on that, we either
     *   a. go ahead and evaluate then push
     *   b. keep going until we can evaluate something
     *
     * We can evaluate a pair when the next operator doesn't have
     * precedence over it (ex: we can evaluate when 1 * 2 + 3, but not when 1 + 2 * 3)
     *
     * I wrote the evaluateOffTop function for when we have a ready pair and should evaluate.
     *
     * That's about as far as I got.
     * Caleb
     */


	////Testing
	//string exptest = "55+6+77";
	//string optest = "+";
	//InfixParser parser;
	//cout << parser.getPrecedence(optest) << endl;
	//cout << parser.getNum(exptest, 0) << endl;

	
	system("pause");
    return 0;
}