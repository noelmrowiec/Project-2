/* Student.cpp
Author: Noel Mrowiec
Date: 4FEB2023
CSCI221
Project 2
C++20 compiler used

Student needs ID at minimum. Allows for the follow info about student: ID, first name, last name, major,
and GPA. Precondition: all values must be valid. Student info is not checked or formatted to ensure correctness.
Accessors implemented in header file.
*/

#include "Student.h"

/* If Student default constructor utilized, id = 0 and all other will be default
   Note: should not call because cannot change id after initialization
*/
Student::Student() : id{ 0 }
{
    
}

/* Constructs student. At minumum, a student ID must be provided. ID cannot be changed after creation. 
* Precondition: all values must be valid. Parameters are not checked or formatted to ensure correct info.
*/
Student::Student(int id, std::string firstname, std::string lastname, std::string major, double gpa) : 
    id{id}, firstname{firstname},lastname{lastname}, major{major}, gpa{gpa}
{
    
}

/*  Returns true if this Student's ID is the same as the passed id
* 
* int id: ID to check
*/
bool Student::findStudent(int id)
{
    return (this->id == id);
}

/* Return true if this Student's gpa is higher than the passed gpa. 
* 
* double gpa: GPA floor (exclusive)
*/
bool Student::listStudents(double gpa)
{
    return (this->gpa > gpa );
}

/* Returns true if this Student's major is the same as the major passed.
* 
* string major: major to check if equal
*/
bool Student::listStudents(std::string major)
{
    return (major == this->major);
}

/*Sets firstname
*/
void Student::setFirstname(std::string firstname)
{

    this->firstname = firstname;
}

/*Sets lastname
*/
void Student::setLastname(std::string lastname)
{
    this->lastname = lastname;
}

/*Sets major
*/
void Student::setMajor(std::string major)
{
    this->major = major;
}

/*Sets GPA
*/
void Student::setGPA(double gpa)
{
    this->gpa = gpa;
}
