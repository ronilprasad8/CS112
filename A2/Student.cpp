#include "Student.h"

Student::Student(string id, double coursework, double finalExam)
    : id(id), coursework(coursework), finalExam(finalExam) {
    totalMarks = coursework + finalExam;
}

string Student::getId() const { return id; }
double Student::getCoursework() const { return coursework; }
double Student::getFinalExam() const { return finalExam; }
double Student::getTotalMarks() const { return totalMarks; }

void Student::updateMarks(double newCoursework, double newFinalExam) {
    coursework = newCoursework;
    finalExam = newFinalExam;
    totalMarks = coursework + finalExam;
}