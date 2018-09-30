//
// Created by Caleb on 9/27/18.
//

#include "InfixParser.h"
//#include "Evaluator.h"

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

		string str;
		getline(cin, str);
		str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
		int stringsize = str.length();
		char stringarray[1024];
		strcpy_s(stringarray, str.c_str());


		char check[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '!', '<', '>', '=', '-', '+', '*', '/', '&', '|' };
		int arrsize = size(check);
		bool isvalid = checkvalidity(check, stringarray, arrsize, stringsize); 
		cout << isvalid; //will output 1 if all characters are valid and 0 if invalid character is used

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