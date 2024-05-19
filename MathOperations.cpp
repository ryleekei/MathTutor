/* File: MathOperations.cpp
 * Course: CS215-002
 * Project: Lab 8 (as part of Project 2)
 * Purpose: to define the class named MathOperations
 * Author: Rylee Hobbs
 */
#include "MathOperations.h"

void MathOperations::setOperands(int op1, int op2) 
{
	operand1 = op1;
	operand2 = op2;
}

void MathOperations :: Addition() 
{
	theoperator = '+';
	answer = operand1 + operand2;
}

void MathOperations::Subtraction()
{
	theoperator = '-';
	answer = operand1 - operand2;
}

void MathOperations::Multiplication()
{
	theoperator = '*';
	answer = operand1 * operand2;
}

void MathOperations::Division()
{
	theoperator = DivisionSymbol;
	answer = operand1 / operand2;
}

char MathOperations::getOperator() const
 {
	 return theoperator;
}

int MathOperations::getAnswer() const 
{
	return answer;
}

bool MathOperations::checkAnswer(int response) const
{
	if (response == answer)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void MathOperations::print() const 
{
	if (operand1 < 10)
	{
		cout << theoperator << "    " << operand1 << endl;
	}
	else if (operand1 < 100)
	{
		cout << "   " << operand1 << endl;
	}
	else if (operand1 < 1000)
	{
		cout << "  " << operand1 << endl;
	}
	else
	{
		cout << " " << operand1 << endl;
	}

	if (operand2 < 10)
	{
		cout << theoperator << "   " << operand2 << endl;
	}
	else if (operand2 < 100)
	{
		cout << theoperator << "  " << operand2 << endl;
	}
	else
	{
		cout << theoperator << " " << operand2 << endl;
	}
	cout << "_____" << endl;
}

MathOperations::MathOperations() {
	answer = -1;
	operand1 = 0;
	operand2 = 0;
	theoperator = '\0';
}