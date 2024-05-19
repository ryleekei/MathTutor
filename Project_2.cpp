/*
 * Course: CS215-002
 * Project: Project 2
 * Purpose: This program repeatedly allows the user to pick between five choices-- an addition, subtraction, multiplication,
 *			or division problem, and an option to quit the program. It then allows the user to answer the choice and determines 
 *			whether the answer was correct or not. When the user chooses to quit, the program reports the amount of correct and 
			incorrect answers to the user.
 *         
 *Author: Rylee Hobbs
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "C:\Users\rylee\source\repos\CS215\Lab8\Lab8\MathOperations.h"
#include "C:\Users\rylee\source\repos\CS215\Lab9\MathReport.h"

using namespace std;

int main()
{
    int choice;     // The user's choice: either choose addition, subtraction, multiplication, division, or quit the program
    MathReport userReport;  // The user report for using Math Tutor program

    srand(time(0)); // Seed the random number generator.
    do {
        cout << "         Math Is Fun!Take a challenge..." << endl;
        cout << "--------------------------------------" << endl;
        cout << "1. Addition problem" << endl;
        cout << "2. Subtraction problem" << endl;
        cout << "3. Multiplication problem" << endl;
        cout << "4. Division problem" << endl;
        cout << "5. Quit this program" << endl;
        cout << "--------------------------------------" << endl;
        cout << "Enter your choice (1-5): ";
        bool isint = false;
        

        while (isint == false)
        {
            cin >> choice;
            cin.ignore(256, '\n');
           
            if (cin.fail() || choice < 1 || choice > 5)
            {
                cin.clear(); // reset the status to "good"
                cin.ignore(256, '\n'); // clean the leftover in the pipe
                cout << "Invalid input! Please try again..." << endl;
                cout << "Your answer is: ";
            }
            else
            {
                isint = true;
            }
        }
      
            int num1;          // The first random number
            int num2;          // The second random number
            int studentAnswer; // The student's answer
            int rand1;         // placeholder for subtraction determination
            int rand2;         // second placeholder for subtraction determination
            MathOperations question; // the question for user to solve

            switch (choice) // cleaner than if/else statements 
            {
                case 1: // addition
            
                    // generate two random numbers between 1 and 500
                    num1 = 1 + rand() % 500;
                    num2 = 1 + rand() % 500;
                    question.setOperands(num1, num2);
                    question.Addition();
                    // Display the problem.
                    question.print();
                    cout << "Your answer is: ";
                    cin >> studentAnswer;
                    cin.ignore(256, '\n');

                    // user input validation
                    // if the user input is invalid, allow the user to try again
                    while (cin.fail())
                    {
                        cin.clear(); // reset the status to "good"
                        cin.ignore(256, '\n'); // clean the leftover in the pipe
                        cout << "Invalid input! Please try again..." << endl;
                        cout << "Your answer is: ";
                        cin >> studentAnswer;
                        cin.ignore(256, '\n');
                    }

                    // when the user input is valid
                    // check if it is the correct answer
                    if (question.checkAnswer(studentAnswer))
                        cout << "Congratulations! " << studentAnswer << " is the right answer." << endl;
                    else
                        cout << "Sorry, the correct answer is " << question.getAnswer() << "." << endl;

                    userReport.insert(question, studentAnswer); 
                   
                    break;

                case 2: // subtraction
                    //generate two random numbers between 1 and 500
                   rand1 = 1 + rand() % 500;
                   rand2 = 1 + rand() % 500;
                // decide which is the first and second operand
                   if (rand1 > rand2)
                   {
                       num1 = rand1;
                       num2 = rand2;
                   }
                   else
                   {
                       num1 = rand2;
                       num2 = rand1;
                   }
                   question.setOperands(num1, num2);
                   question.Subtraction();
                   // Display the problem.
                   question.print();
                   cout << "Your answer is: ";
                   cin >> studentAnswer;
                   cin.ignore(256, '\n');

                   // user input validation
                   // if the user input is invalid, allow the user to try again
                   while (cin.fail())
                   {
                       cin.clear(); // reset the status to "good"
                       cin.ignore(256, '\n'); // clean the leftover in the pipe
                       cout << "Invalid input! Please try again..." << endl;
                       cout << "Your answer is: ";
                       cin >> studentAnswer;
                       cin.ignore(256, '\n');
                   }

                   // when the user input is valid
                   // check if it is the correct answer
                   if (question.checkAnswer(studentAnswer))
                       cout << "Congratulations! " << studentAnswer << " is the right answer." << endl;
                   else
                       cout << "Sorry, the correct answer is " << question.getAnswer() << "." << endl;
                  
                   userReport.insert(question, studentAnswer);

                    break;
                case 3: // Multiplication
        
                // Generate two random numbers: 
                    num1 = 1 + rand() % 100;// The first one is in the range of [1, 100];
                    num2 = 1 + rand() % 9;// The second one is in the range of [1, 9].
                    question.setOperands(num1, num2);
                    question.Multiplication();
                    // Display the problem.
                    question.print();
                    cout << "Your answer is: ";
                    cin >> studentAnswer;
                    cin.ignore(256, '\n');

                    // user input validation
                    // if the user input is invalid, allow the user to try again
                    while (cin.fail())
                    {
                        cin.clear(); // reset the status to "good"
                        cin.ignore(256, '\n'); // clean the leftover in the pipe
                        cout << "Invalid input! Please try again..." << endl;
                        cout << "Your answer is: ";
                        cin >> studentAnswer;
                        cin.ignore(256, '\n');
                    }

                    // when the user input is valid
                    // check if it is the correct answer
                    if (question.checkAnswer(studentAnswer))
                        cout << "Congratulations! " << studentAnswer << " is the right answer." << endl;
                    else
                        cout << "Sorry, the correct answer is " << question.getAnswer() << "." << endl;
                   
                    userReport.insert(question, studentAnswer);

                    break;
                case 4: // division
                    // generate two random numbers
                    num1 = 1 + rand() % 111; // makes sure the resulting dividend is below 999
                    num2 = 1 + rand() % 9;
                   
                    // make sure there are no fractions
                    num1 = num1 * num2;
                    question.setOperands(num1, num2);
                    question.Division();
                    // Display the problem.
                    question.print();
                    cout << "Your answer is: ";
                    cin >> studentAnswer;
                    cin.ignore(256, '\n');

                    // user input validation
                    // if the user input is invalid, allow the user to try again
                    while (cin.fail())
                    {
                        cin.clear(); // reset the status to "good"
                        cin.ignore(256, '\n'); // clean the leftover in the pipe
                        cout << "Invalid input! Please try again..." << endl;
                        cout << "Your answer is: ";
                        cin >> studentAnswer;
                        cin.ignore(256, '\n');
                    }

                    // when the user input is valid
                    // check if it is the correct answer
                    if (question.checkAnswer(studentAnswer))
                        cout << "Congratulations! " << studentAnswer << " is the right answer." << endl;
                    else
                        cout << "Sorry, the correct answer is " << question.getAnswer() << "." << endl;

                    userReport.insert(question, studentAnswer);
                    
                    break;
            }



        

    } while (choice != 5);

    cout << endl;
    userReport.generateReport();
    cout << "Thank you for using Math Tutor." << endl;
    return 0;
}
