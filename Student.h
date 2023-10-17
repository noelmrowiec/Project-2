/* Student.h
Author: Noel Mrowiec
Date: 4FEB2023
CSCI221
Project 2
C++20 compiler used

Accessors implemented in header file. 
*/
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
class Student
{
private:
    const int id;
    std::string firstname{};
    std::string lastname{};
    std::string major{};
    double gpa{};

public:
    Student();
    Student(int id, std::string firstname, std::string lastname, 
        std::string major, double gpa);
    
    bool findStudent(int id);
    bool listStudents(double gpa);
    bool listStudents(std::string major);
    
    void setFirstname(std::string firstname);
    void setLastname(std::string lastname);
    void setMajor(std::string major);
    void setGPA(double gpa);

    int getID() { return id; }
    std::string getFirstname() { return firstname; }
    std::string getLastname() { return lastname; }
    std::string getMajor() { return major; }
    double getGPA() { return gpa; }

};
#endif
