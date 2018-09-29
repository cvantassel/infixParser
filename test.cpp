#include <iostream>
#include <string>

using namespace std;


int main() {


	string operators[] = { "||", "&&", "==", "!=", ">", ">=", "<", "<=", "+", "-", "*", "/", "%", "^", "-", "--", "++", "!" };
	int precedence[] = { 1,2,3,3,4,4,4,4,5,5,6,6,6,7,8,8,8,8 };



	for (int i = 0; i < operators.size(); i++) {
		if operators[i] == "+"
			cout << i;
	}

	system("pause");
}