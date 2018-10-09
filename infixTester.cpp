#include "infixTester.h"

void infixTester::inputLoop()
{
	InfixParser* parser = new InfixParser();

	while (true) {

		cout << "Plese input the expression you would like to evaluate below." << endl << endl;
		string expression;
		getline(cin, expression);

		int result = parser->parse(expression);
		cout << "RETURN ==> " << result << endl;

		cout << "Test Again?(y/n)";

		string response;
		getline(cin, response);

		if (response != "y")
			break;
		cin.clear();
		cout << endl;
	}
}

void infixTester::runProjectTests()
{
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

	//Test Lists
	string testExList[] = { ex1, ex2, ex3, ex4, ex5, ex6, ex7 };
	int testAnswList[] = { answ1,answ2,answ3,answ4,answ5,answ6, answ7 };

	//Parser Object
	InfixParser* parser = new InfixParser();

	int succeessCount = 0;
	int failCount = 0;

	for (int i = 0; i < testExList->length(); i++) {

		string curTest = testExList[i];
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

	cout << endl << "RESULTS" << endl << "TESTS PASSED: " << succeessCount << endl << "TESTS FAILED: " << failCount << endl;

}

void infixTester::runErrorTests()
{
	//Might be worth formalizing if we have time
}