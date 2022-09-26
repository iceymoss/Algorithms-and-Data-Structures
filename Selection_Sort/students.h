//
// Created by 风 on 2021/2/1.
//

#ifndef SELECTION_SORT_STUDENTS_H
#define SELECTION_SORT_STUDENTS_H
#include<iostream>
#include<string>

using namespace std;

struct Student{
    string name;
    int score;
    bool operator<(const Student &otherStudent){
        return score != otherStudent.score ? score > otherStudent.score :name < otherStudent.name;
    }
    friend ostream& operator<<(ostream &os, Student &student){
        os<<"Student: "<<student.name<<" "<<student.score<<endl;
        return os;
    }
};
#endif //SELECTION_SORT_STUDENTS_H
