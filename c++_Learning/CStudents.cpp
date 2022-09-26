//
// Created by 风 on 2021/3/21.
//
#include <cstring>
#include "CStudents.h"
const char* CStudents::getName(){
    return name;
}

const char* CStudents::getNum(){
    return stunum;
}
float CStudents::getScore(){
    return mathScore;
}
//将myName赋给name
void CStudents::setName(const char* myName) {
    strcpy(name, myName);
}
void CStudents::setNum(const char* myNum) {
    strcpy(stunum, myNum);
}
void CStudents::setScore(float myScore) {
    mathScore = myScore;
}
