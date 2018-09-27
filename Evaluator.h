//
// Created by Caleb on 9/27/18.
//

#ifndef INFIXPARSER_EVALUATOR_H
#define INFIXPARSER_EVALUATOR_H

#include <string>

class Evaluator {
private:
    static bool isOperand(char opr);
public:
    static int evaluate(std::string exp);
};

#endif //INFIXPARSER_EVALUATOR_H
