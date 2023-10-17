/* Client.cpp
Author: Noel Mrowiec
Date: 4FEB2023
CSCI221
Project 2
C++20 compiler required

Contains main() through which the various Student objects will be created and tested.
*/

#include "Student.h"
#include <iostream>
#include <vector>
#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision

struct StudentInfo
{
    int id{};
    std::string firstname{};
    std::string lastname{};
    std::string major{};
    double gpa{};
};

struct Majors
{
    std::string bio { "Biology" };
    std::string cs { "Computer Science" };
    std::string ed { "Education" };
    std::string eng { "Engineering" };
    std::string his { "History" };
    std::string math { "Mathematics" };
};

/* Creates a student object from the given student infomation.
* 
* StudentInfo: accepts struct StudentInfo with information for new student
*/
Student createStudent(StudentInfo info) {
    return (Student { info.id, info.firstname, info.lastname, info.major, info.gpa });
}

/* Displays student infomation to console
* 
* Student student: student to print info
*/
void displayStudentInfo(Student student) {
    std::cout << "Student Information: " << std::endl;
    std::cout << "ID = " << student.getID() << std::endl;
    std::cout << "Name: " << student.getFirstname() << " " << student.getLastname() << std::endl;
    std::cout << "Major: " << student.getMajor() << std::endl;
    //set percision to x.xx and fixed will always display 2 deceimals 
    double gpaFormatted = round(student.getGPA() * 100) / 100;           //Format to two decimals 
    std::cout << std::setprecision(2) << std::fixed << "GPA = " << gpaFormatted << std::endl; //
}

/* Tests the findStudent() method from a vector of students for a given id
* Prints results from test to console.
* 
* std::vector<Student> students: vector of students to chek
* int id: id to check
*/
void testFindStudentMethod(std::vector<Student>& students, int id) {
    bool isFound{ false };
    for (Student student : students) {
        if (student.findStudent(id)) {
            std::cout << "Student found - " << std::endl;
            isFound = true;
            displayStudentInfo(student);
        }
    }

    if (!isFound)
        std::cout << "Student with ID " << id << " was not found" << std::endl;     //Print not found message

}

/* Tests the listStudentMethod() from a vector of students for a given key. Will display student info if found.
* 
* std::vector<Student> students: vector of students to check
* auto key: GPA or major to evaluate student against. Precondition: must be double gpa or string major. 
*/
void testListStudentsMethod(std::vector<Student>& students, auto key) {
    //Checks each student against key
    for (Student student : students) {
        // Calls listStudents() overloaded function. 
        //If key is string, will call listStudents(string major)
        //If key is double, will call listStudents(double gpa)
        if (student.listStudents(key)) {
            displayStudentInfo(student);                //Display student info if found
        }
    }
}

int main()
{
    //TODO
    //create 5 Student objects
    Majors majors;
    StudentInfo student1{ 1001, "Thomas", "Edison", majors.eng, 3.55 };
    StudentInfo student2{ 1002, "Pythagoras", "", majors.math, 1.45 };
    StudentInfo student3{ 1003, "Bjarne", "Stroustrup", majors.cs, 3.00 };
    StudentInfo student4{ 1004, "Louis", "Pasteur", majors.bio, 2.005 };
    StudentInfo student5{ 1005, "Alan", "Turning", majors.math, 4.0 };
    
    using std::vector;
    //Add each student to vector of students
    vector<Student> students{ createStudent(student1), createStudent(student2), createStudent(student3), createStudent(student4), 
        createStudent(student5) };
    
    //Display student info
    for (Student student : students) {
        displayStudentInfo(student);
     }

    //Change major of two of the students and display change
    students.at(4).setMajor(majors.cs);       
    students.at(3).setMajor(majors.ed);

    //Change gpa of two other students. display change
    students.at(0).setGPA(3.32);
    students.at(1).setGPA(1.901);
    
    //Display updated students
    std::cout << "Changes to two student as follows: " << std::endl;
    for (Student student : students)
        displayStudentInfo(student);

    //Test findStudent() method. Pass valid id and display
    std::cout << "Test start: findStudent() " << std::endl;
    int idToTest{ 1002 };
    std::cout << "Searching for student ID " << idToTest << std::endl;
    testFindStudentMethod(students, idToTest);
    
    //Test findStudent() method with invalid id. Display message
    idToTest = 1;                                       //Invalid ID
    std::cout << "Searching for student ID " << idToTest << std::endl;
    testFindStudentMethod(students, idToTest);          //Should print that student id is not found

    std::cout << "Test end: findStudent() " << std::endl;

    //Test listStudents() method
    //pass a double gpa and list all students whose GPA is above the pass GPA
    std::cout << "Test start:listStudents() " << std::endl;
    double gpaToTest{ 3.0 };
    std::cout << "List of students wiht GPA above " << gpaToTest << " - " << std::endl;
    //Prints all students with GPA's above the given value. 
    //Note: GPA's equal to gpaToTest will not be printed in accordance with design specifications 
    testListStudentsMethod(students, gpaToTest);             

    //pass a string and list all students whose major equals the passed value
    std::string majorToTest{ majors.math };
    std::cout << "List of students with " << majorToTest << " major - " << std::endl;
    //Prints all students with the same major as majorToTest
    testListStudentsMethod(students, majorToTest);

    //pass a string and list all students whose major equals the passed value
    majorToTest =  majors.bio;
    std::cout << "List of students with " << majorToTest << " major - " << std::endl;
    //Prints all students with the same major as majorToTest
    testListStudentsMethod(students, majorToTest);

    std::cout << "Test end:listStudents() " << std::endl;

    std::cout << "All tests finished\n";
}