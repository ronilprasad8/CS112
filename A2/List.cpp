#include "List.h"
#include <iomanip>
#include <fstream>
#include <iostream>

using namespace std;

const int HALF_MARK = 50;

// Node constructor
template <class T>
Node<T>::Node(T data) : data(data), next(NULL) {}

// List constructor
template <class T>
List<T>::List() : head(NULL) {}

// Insert a new element into the list
template <class T>
void List<T>::insert(T data) {
    Node<T>* newNode = new Node<T>(data);
    if (head == NULL) {
        head = newNode;
    }
    else {
        Node<T>* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to determine grade based on total marks.
string det_grade(double totalMarks) {
    if (totalMarks >= 85) return "A+";
    else if (totalMarks >= 78) return "A";
    else if (totalMarks >= 71) return "B+";
    else if (totalMarks >= 64) return "B";
    else if (totalMarks >= 57) return "C+";
    else if (totalMarks >= 50) return "C";
    else if (totalMarks >= 40) return "D";
    else return "E";
}

// Print details of all students
template <class T>
void List<T>::print_details() {
    cout << "ID\tCoursework\tFinal Exam\tTotal Marks\tGrades\n";
    Node<T>* current = head;
    while (current) {
        cout << current->data.getId() << "\t"
            << current->data.getCoursework() << "\t\t"
            << current->data.getFinalExam() << "\t\t"
            << current->data.getTotalMarks() << "\t\t"
            << det_grade(current->data.getTotalMarks()) << endl;
        current = current->next;
    }
    cout << "==================================================================\n\n";
    avg_marks();
    cout << "==================================================================\n\n";
    pass_rate();
    cout << "==================================================================\n\n";
    print_highest_scorer();
    cout << "==================================================================\n\n";
}

// Calculate and print average marks
template <class T>
void List<T>::avg_marks() {
    double sum = 0;
    int count = 0;
    Node<T>* current = head;
    while (current) {
        sum += current->data.getTotalMarks();
        count++;
        current = current->next;
    }
    if (count > 0) {
        cout << "Average marks: " << fixed << setprecision(2) << (sum / count) << endl;
    }
    else {
        cout << "No records available to calculate average.\n";
    }
}

// Calculate and print pass rate
template <class T>
void List<T>::pass_rate() {
    int passedCount = 0;
    int totalCount = 0;
    Node<T>* current = head;
    while (current) {
        totalCount++;
        if (current->data.getTotalMarks() >= HALF_MARK) {
            passedCount++;
        }
        current = current->next;
    }
    if (totalCount > 0) {
        int passRate = (passedCount * 100) / totalCount;
        cout << "Pass Rate: " << passRate << "%" << endl;
    }
    else {
        cout << "No records available to calculate pass rate.\n";
    }
}

// Print highest scorer's details
template <class T>
void List<T>::print_highest_scorer() {
    double highestMarks = 0;
    Node<T>* highestScorer = NULL;

    Node<T>* current = head;
    while (current) {
        if (current->data.getTotalMarks() > highestMarks) {
            highestMarks = current->data.getTotalMarks();
            highestScorer = current;
        }
        current = current->next;
    }

    if (highestScorer) {
        cout << "Details of the highest scorer:\n";
        cout << "-------------------------------------------\n";
        cout << "ID: " << highestScorer->data.getId() << endl;
        cout << "Coursework: " << highestScorer->data.getCoursework() << endl;
        cout << "Final Exam: " << highestScorer->data.getFinalExam() << endl;
        cout << "Total Marks: " << highestScorer->data.getTotalMarks() << endl;
        cout << "Grade: " << det_grade(highestScorer->data.getTotalMarks()) << endl;
    }
    else {
        cout << "No data found for the highest scorer.\n";
    }
}

// Update marks for a specific student
template <class T>
void List<T>::update_marks(const string& studentID) {
    Node<T>* current = head;
    while (current) {
        if (current->data.getId() == studentID) {
            double newCoursework, newFinalExam;
            cout << "Enter new coursework mark for student " << studentID << ": ";
            while (!(cin >> newCoursework) || newCoursework < 0 || newCoursework > HALF_MARK) {
                cout << "Invalid input. Please enter a valid coursework mark (0-" << HALF_MARK << "): ";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            cout << "Enter new final exam mark for student " << studentID << ": ";
            while (!(cin >> newFinalExam) || newFinalExam < 0 || newFinalExam > HALF_MARK) {
                cout << "Invalid input. Please enter a valid final exam mark (0-" << HALF_MARK << "): ";
                cin.clear();
                cin.ignore(10000, '\n');
            }

            current->data.updateMarks(newCoursework, newFinalExam);
            cout << "==================================================================\n";
            cout << "Marks updated successfully for student " << studentID << endl;
            cout << "Updated Total Marks: " << current->data.getTotalMarks() << endl;
            cout << "Updated Grade: " << det_grade(current->data.getTotalMarks()) << endl;
            cout << "==================================================================\n\n";
            return;
        }
        current = current->next;
    }
    cout << "Student with ID " << studentID << " not found." << endl;
    cout << "==================================================================\n\n";
}

// Destructor for List 
template <class T>
List<T>::~List() {
    Node<T>* current = head;
    while (current) {
        Node<T>* toDelete = current;
        current = current->next;
        delete toDelete;
    }
}

template class List<Student>;