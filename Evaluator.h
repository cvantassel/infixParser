//
// Created by Caleb, Kole, and Landon
//


#ifndef INFIXPARSER_EVALUATOR_H
#define INFIXPARSER_EVALUATOR_H

#include <string>
#include <stack>

class Evaluator {
private:
    static bool isOperand(char opr);
public:
    static int evaluate(std::stack<int>* numStack, std::stack<std::string>* opStack);
};

#endif //INFIXPARSER_EVALUATOR_H
