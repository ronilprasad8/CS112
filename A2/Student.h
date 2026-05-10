#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
    private:
        string id;
        double coursework;
        double finalExam;
        double totalMarks;

    public:
        Student(string id, double coursework, double finalExam);
        string getId() const;
        double getCoursework() const;
        double getFinalExam() const;
        double getTotalMarks() const;
        void updateMarks(double newCoursework, double newFinalExam);
};

#endif#
