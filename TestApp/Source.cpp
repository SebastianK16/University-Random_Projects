#include "Quiz.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
                             // function used by the program
void passwordAuthentication();
void displayMenu();
void startQuiz();
void viewResults();

int main()
{
    char choice;
    passwordAuthentication();
    while (true)
    {
        displayMenu();
        cin >> choice;
                       //Menu of the program
        switch (choice)
        {
        case '1':
            startQuiz();
            break;
        case '2':
            viewResults();
            break;
        case '3':
            cout << "Help option selected. Displaying help information." << endl;
            cout << "Here is some help information..." << endl;
            cout << "If option 1 is choosen the quiz will start" << endl;
            cout << "If option 2 is choosen the results will be dispalyed" << endl;
            cout << "If option 4 is choosen the program will close" << endl;
            break;
        case '4':
            cout << "Exiting the program..." << endl;
            return 0;
        default:
            cout << "Invalid option selected." << endl;
        }
        cout << "Continue? (y/n): ";
        cin >> choice;

        if (choice == 'n' || choice == 'N')
        {
            cout << "Exiting the program..." << endl;
            break;
        }
    }
    return 0;
}
                            //functios of the program
void passwordAuthentication()
{
    string password;
    bool authenticated = false;

    while (!authenticated)
    {
        cout << "Enter the password: ";
        cin >> password;

        if (password == "pass123")
        {
            authenticated = true;
            cout << "Authentication successful!" << endl;
        }
        else
        {
            cout << "Incorrect password. Try again." << endl;
        }
    }
}
                    //shows the user menu
void displayMenu()
{
    cout << "\n----- Quiz App Menu -----" << endl;
    cout << "1. Start Quiz" << endl;
    cout << "2. View Results" << endl;
    cout << "3. Help" << endl;
    cout << "4. Exit" << endl;  
    cout << "Enter your choice: " << endl;
}
                  //starts the quiz
void startQuiz()
{
    string name;
    int year;
    string group;

    cout << "Enter your name: ";
    cin >> name;

    cout << "Enter your year: ";
    cin >> year;

    cout << "Enter your group: ";
    cin >> group;

    Student student(name, year, group);
    student.startQuiz();
                                             //saves the users information
    ofstream outFile("results.txt", ios::app);
    if (outFile.is_open())
    {
        outFile << "Name: " << student.getName() << endl;
        outFile << "Year: " << student.getYear() << endl;
        outFile << "Group: " << student.getGroup() << endl;
        outFile << "Score: " << student.getScore() << "%" << endl;
        outFile << "-----------------------" << endl;
        outFile.close();
        cout << "Quiz result saved successfully." << endl;
    }
    else
    {
        cout << "Failed to save the quiz result." << endl;
    }
}
                  //shows results
void viewResults()
{
    ifstream inFile("results.txt");
    if (inFile.is_open())
    {
        string line;
        cout << "----- Quiz Results -----" << endl;
        while (getline(inFile, line))
        {
            cout << line << endl;
        }
        inFile.close();
    }
    else
    {
        cout << "No quiz results found." << endl;
    }
}
