//
// Created by Caleb on 9/27/18.
//

//#include "InfixParser.h"
//#include "Evaluator.h"

#include <iostream>

using namespace std;

int main() {

	/*
	a way to remove all spaces from string

	s.erase(remove_if(s.begin(), s.end(), isspace), s.end());

	will completely modify string
	*/

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

	cout << "Hello";

    return 0;
}