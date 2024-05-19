/* File: MathReport.h
 * Course: CS215-002
 * Project: Lab 9 (as part of Project 2)
 * Purpose: to declare the class named MathReport
 * Author: Rylee Hobbs
 */

 //#pragma once

#include <iostream>
#include <vector>
#include "../Lab8/Lab8/MathOperations.h"

using namespace std;

class MathReport
{
public:
    // default constructor
    MathReport();

    // add a Question object into the vector of mathQuestions
    // and the response to check with the correct answer: 
    //    if response is correct, increase numCorrectAnswers
    //    otherwise, increase numWrongAnswers
    void insert(MathOperations newQuestions, int response);

    // return the value of numCorrectAnswers
    int getNumOfCorrectAnswers() const;

    // return the value of numWrongAnswers
    int getNumOfWrongAnswers() const;

    // generate a brief report
    void generateReport() const;

private:
    int numCorrectAnswers;  // number of correctly answered questions
    int numWrongAnswers;  // number of wrong answers
    vector<MathOperations> mathQuestions; // sequence of questions
};