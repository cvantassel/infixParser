#pragma once

#include "InfixParser.h"

#include <iostream>
#include <string>

using namespace std;

class infixTester {
private:

public:
	void inputLoop(); //Runs input loop until asked to stop
	void runProjectTests(); //Runs expressions given on Project Sheet
	void runErrorTests(); //Runs tests meant to generate Error Messages
};