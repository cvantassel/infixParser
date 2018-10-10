//
// Created by Caleb, Kole, and Landon
//

#include "InfixParser.h"
#include "infixTester.h"
//#include "Evaluator.h"

#include <iostream>
#include <string>
#include <algorithm>
//#include <bits/valarray_before.h>

using namespace std;

int main() {

	infixTester *tester = new infixTester;

	tester->inputLoop(); //Run Parser Loop until asked to quit
	tester->runProjectTests(); //Run non-error-generating expressions on the project sheet
	
	system("pause");
    return 0;
}