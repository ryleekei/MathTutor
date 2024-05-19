/* File: MathReport.cpp
 * Course: CS215-002
 * Project: Lab 9 (as part of Project 2)
 * Purpose: to define the class named MathReport
 * Author: Rylee Hobbs
 */
#include "MathReport.h"
#include "C:\Users\rylee\source\repos\CS215\Lab8\Lab8\MathOperations.h"

MathReport::MathReport()
{
	numCorrectAnswers = 0;
	numWrongAnswers = 0;
	
	
	//do nothing to the vector of MathOperations objects 
}

// add a Question object into the vector of mathQuestions
   // and the response to check with the correct answer: 
   //    if response is correct, increase numCorrectAnswers
   //    otherwise, increase numWrongAnswers
void MathReport::insert(MathOperations newQuestions, int response)
{
	mathQuestions.push_back(newQuestions);
	
	if (newQuestions.checkAnswer(response) == true)
	{
		numCorrectAnswers = numCorrectAnswers + 1;
	}
	else
	{
		numWrongAnswers = numWrongAnswers + 1;
	}


}

// return the value of numCorrectAnswers
int MathReport::getNumOfCorrectAnswers() const
{
	return numCorrectAnswers;
}

// return the value of numWrongAnswers
int MathReport::getNumOfWrongAnswers() const
{
	return numWrongAnswers;
}

void MathReport::generateReport() const
{
	cout << "You have solved the following " << getNumOfCorrectAnswers() + getNumOfWrongAnswers() << " math problems : " << endl;
	cout << " " << endl;
	
	for (int i = 0; i < getNumOfCorrectAnswers() + getNumOfWrongAnswers(); i++)
	{
		cout << "Question " << (i + 1) << ":"<< endl;
		mathQuestions[i].print();
		cout << "  "<< mathQuestions[i].getAnswer() << endl;
	}

	cout << "You answered " << numCorrectAnswers << " questions correctly." << endl;
	cout << "You made " << numWrongAnswers << " mistakes." << endl;
	
	if (numCorrectAnswers > numWrongAnswers)
	{
		cout << "Great job!"<< endl;
	}
	else 
	{
		cout << "You will do better next time..." << endl;
	}

}