//
// Created by Caleb on 9/27/18.
//

#include "InfixParser.h"

int main() {


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

    return 0;
}