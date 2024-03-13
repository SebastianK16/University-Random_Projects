#include "Quiz.h"
#include <iostream>

using namespace std;

Student::Student(const string& name, int year, const string& group)
    : name(name), year(year), group(group), score(0) {}

string Student::getName() const
{
    return name;
}

int Student::getYear() const
{
    return year;
}

string Student::getGroup() const
{
    return group;
}

int Student::getScore() const
{
    return score;
}

void Student::startQuiz()
{
    char answers[] = { 'b', 'd', 'a', 'c', 'b', 'b', 'd', 'a', 'c', 'c' };//quiz answers
    char userAnswer;
    int correctAnswers = 0;

    cout << "Welcome, " << name << "!" << endl;
    cout << "Please answer the following questions:" << endl;

    for (int i = 0; i < 10; ++i)
    {
		//quiz questions and possible answers
        cout << "Question " << (i + 1) << ": ";
        switch (i)
        {
		case 0:
			cout << "In which Italian city can you find the Colosseum?" << endl;
			cout << "a. Venice" << endl;
			cout << "b. Rome" << endl;
			cout << "c. Naples" << endl;
			cout << "d. Milan" << endl;
			break;
		case 1:
			cout << "How many wives did Henry VIII have?" << endl;
			cout << "a. 1" << endl;
			cout << "b. 3" << endl;
			cout << "c. 4" << endl;
			cout << "d. 6" << endl;
			break;
		case 2:
			cout << "What is the largest continent in size?" << endl;
			cout << "a. Asia" << endl;
			cout << "b. Africa" << endl;
			cout << "c. Europe" << endl;
			cout << "d. North America" << endl;
			break;
		case 3:
			cout << "Which famous inventor invented the telephone?" << endl;
			cout << "a. Thomas Edison" << endl;
			cout << "b. Benjamin Franklin" << endl;
			cout << "c. Alexander Graham Bell" << endl;
			cout << "d. Nikola Tesla" << endl;
			break;
		case 4:
			cout << "What is the longest river in the world?" << endl;
			cout << "a. Amazon River" << endl;
			cout << "b. Nile" << endl;
			cout << "c. Yellow River" << endl;
			cout << "d. Congo River" << endl;
			break;
		case 5:
			cout << "How many sides has a Hexagon ?" << endl;
			cout << "a. 5 " << endl;
			cout << "b. 6" << endl;
			cout << "c. 7" << endl;
			cout << "d. 8" << endl;
			break;
		case 6:
			cout << "Which country does not share a border with Romania?" << endl;
			cout << "a. Ukraine" << endl;
			cout << "b. Bulgaria" << endl;
			cout << "c. Hungary" << endl;
			cout << "d. Poland" << endl;
			break;
		case 7:
			cout << "Apart from water, what is the most popular drink in the world?" << endl;
			cout << "a. Tea" << endl;
			cout << "b. Coffee" << endl;
			cout << "c. Beer" << endl;
			cout << "d. Orange Juice" << endl;
			break;
		case 8:
			cout << "What is the name of the gem in the movie Titanic??" << endl;
			cout << "a. Call of the Ocean" << endl;
			cout << "b. Heart of Love" << endl;
			cout << "c. Heart of the Ocean" << endl;
			cout << "d. Call of Love" << endl;
			break;
		case 9:
			cout << "What is 2+2?" << endl;
			cout << "a. 1" << endl;
			cout << "b. 0" << endl;
			cout << "c. 4" << endl;
			cout << "d. 1000" << endl;
			break;
        default:
            cout << "Invalid question." << endl;
            break;
        }
        cout << "Enter your answer (a, b, c, or d): ";
        cin >> userAnswer;
        if (userAnswer == answers[i])
        {
            ++correctAnswers;
        }
    }

    calculateScore(correctAnswers);
}

void Student::calculateScore(int correctAnswers)
{
    score = (correctAnswers / 10.0) * 100;
}
