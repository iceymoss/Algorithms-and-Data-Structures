//
// Created by 风 on 2021/3/21.
//

#ifndef C___LEARNING_CSTUDENTS_H
#define C___LEARNING_CSTUDENTS_H


class CStudents {
private:
    char name[100];
    char stunum[100];
    float mathScore;

public:
    const char* getName();
    const  char* getNum();
    float getScore();
    //用于设置姓名，学号，成绩
    void setName(const char* myName); //从外部传入姓名
    void setNum(const char* myNum);
    void setScore(float myScore);

};


#endif //C___LEARNING_CSTUDENTS_H
