#pragma once
#ifndef QUIZ_H
#define QUIZ_H
#include <string>

using namespace std;
class Student
{
private:
    string name;
    int year;
    std::string group;
    int score;

public:
    Student(const std::string& name, int year, const std::string& group);
    string getName() const;
    int getYear() const;
    string getGroup() const;
    int getScore() const;
    void startQuiz();
    void calculateScore(int correctAnswers);
};
#endif
