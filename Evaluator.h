//
// Created by Caleb on 9/27/18.
//

//Probably going to consolidate evaluation to parser class because it's not storing any information not in Parser already -Landon

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
