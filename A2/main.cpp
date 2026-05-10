#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "List.h"
#include "Student.h"

using namespace std;

// Function prototypes
void read_file_data(const string& filename, List<Student>& list);
void discard_line(ifstream& in);

int main() {
    List<Student> studentList;
    read_file_data("studentData.txt", studentList);

    char choice;

    // Loop for user Interaction.
    do {
        cout << "This program allows to print details of students and update marks.\n";
        cout << "Enter 1/2/3 to do the following.\n";
        cout << "1. Print details.\n";
        cout << "2. Update Marks.\n";
        cout << "3. Quit.\n";
        cout << "==================================================================\n\n";
        cout << "Enter your choice:";
        cin >> choice;
        cout << "\n";

        // Handling user choices.
        if (choice == '1') {
            studentList.print_details();
        }
        else if (choice == '2') {
            string studentID;
            cout << "Enter the student ID for whom you want to update marks: ";
            cin >> studentID;
            studentList.update_marks(studentID);
        }
        else if (choice == '3') {
            cout << "Program exited.\n";
            exit(0);
        }
        else {
            cout << "Invalid choice. Please try again.\n\n";
        }
    } while (choice != '3');

    return 0;
}

// Function to read student data from a file and populate the list
void read_file_data(const string& filename, List<Student>& list) {
    ifstream inFile("studentData.txt", ios::in);
    if (inFile.is_open()) {
        discard_line(inFile);
        string id;
        double coursework, finalExam;
        while (inFile >> id >> coursework >> finalExam) {
            list.insert(Student(id, coursework, finalExam));
        }
        inFile.close();
    }
    else {
        cerr << "File not found" << endl;
    }
}

void discard_line(ifstream& in) {
    char c;
    do {
        in.get(c);
    } while (c != '\n');
}
