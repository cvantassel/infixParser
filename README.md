# infixParser


TODO:
multi parantheses

This parses infix expressions.

RULE OF THUMB
	Comment and commit before you begin working to rope off your section of code
	Comment and push to notify you're done 

In Main
	Get String
	Remove spaces Check for valid characters (use check array)
	Raise Error Messages accordingly
	Initialize and Call Parser
	Output Result

In Parser
	Fix getPrecedence
	
	Rough Infix Algorithm
		numStack & opStack
		numParStack & opParStack
		incrementBy = 0
		operators [+,-,...]

		checkMoreDig()
			num = "cur"
				while next.isDigit
					move i of cur by one
					num += cur

		while not end of string
			read in cur and next
			if cur == next
				op is unary so increment by +/-
			if cur isDigit && increment by != 0
				cur += increment by
			if cur isDigit
				checkMoreDig()
				num -> numStack
			if cur is in operators
				if stack empty
					cur -> opStack
				else if cur.getprec > opStack.top.getprec
					cur -> opStack
					next.checkForMore -> numStack
					evaluate()
				else
					opStack -> numStack
			if cur opening parentheical
				while not close
					run infix alg with two sep stacks
				result -> numStack


In Evaluator Function:
	Unary Evaluator
	Meaningful Error Messages
	Comparison Operators

![uml](https://user-images.githubusercontent.com/33508520/46710018-ca90e480-cc0b-11e8-9fc3-7f837a38481a.jpg)
