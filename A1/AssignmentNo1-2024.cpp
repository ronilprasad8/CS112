#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// Constant declaration.
const int MAXSIZE = 100; // Maximum number of student records.
const int NUMRECS = 20;  // Number of records to be processed.
const int HALF_MARK = 50;//Passing mark.

// Struct to encapsulate each student's record.
struct Student {
    string id;           // Student ID.
    double coursework;   // Marks obtained in coursework.
    double finalExam;    // Marks obtained in the final exam.
    double totalMarks;   // Total marks obtained.
};

// Function prototypes.
void print_details(Student students[], int size);
string det_grade(float marks);
void avg_marks(Student students[], double sum);
void pass_rate(Student students[], int count);
void print_highest_scorer(Student students[], int size);
void update_marks(Student students[], int size);

// Main function to handle user interaction and program execution.
int main(){
    char choice; // Variable to store user's menu choice.

    // Array to store student records.
    Student students[MAXSIZE];
    ifstream file("studentData.txt"); // Input file stream to read student data from a file.

    // Reading student data from the file.
    if (file.is_open()){
        string line;
        int count = 0; // Counter to track the number of records.
		while (getline(file, line) && count < NUMRECS) {
            file >> students[count].id >> students[count].coursework >> students[count].finalExam;
            count++;
        }
	}
	else{
		cerr<<"File not found";// Error message if the file cannot be opened.
	}
	
	// Loop for user Interaction.
	do{
	    cout<<"This program allows to print details of students and update mark.\n";
	    cout<<"1. Print details.\n";
	    cout<<"2. Update Mark.\n";
	    cout<<"3. Quit.\n";
	    cout<<"==================================================================\n\n";
	    cout<<"Enter your choice: \n";
	    
		// Input validation for menu choice.
	    while (!(cin >> choice)) {
	            cout << "Invalid input. Please enter a number: ";
	            cin.clear();
	            string not_an_int;
				cin>>not_an_int;
	        }
	    
	    // Handling user choices.
	    if (choice == '1'){
	    	print_details(students, NUMRECS);
		}
		else if (choice =='2'){
			update_marks(students, NUMRECS);
		}
		else if (choice =='3'){
			cout <<"Program exitted.\n";
			exit(1);// Function to exit the program.
		}
		else {
			cout << "Invalid choice. Please try again.\n\n";
		}
	}while (choice != '3');
		
	return 0;
}

// Function to print details of all students including their grades, highest scorer's details and average marks.
void print_details(Student students[], int size){
	cout<<"ID\t"<<"Coursework\t"<<"Final Exam\t"<<"Total Marks\t"<<"Grades\n";
	for (int i=0; i<NUMRECS; i++){
		students[i].totalMarks=students[i].coursework+students[i].finalExam;
    	cout<<students[i].id<<"\t" << students[i].coursework <<"\t\t"<< students[i].finalExam <<"\t\t"<< students[i].totalMarks <<"\t\t"<< det_grade(students[i].totalMarks)<<endl;
	}
	cout<<"==================================================================\n\n";
	avg_marks(students, NUMRECS);
	cout<<"==================================================================\n\n";
	pass_rate(students, NUMRECS);
	cout<<"==================================================================\n\n";
	print_highest_scorer(students, NUMRECS);
	cout<<"==================================================================\n\n";
}

// Function to determine grade.
string det_grade(float marks) {
    if (marks >= 85) return "A+";
    else if (marks >= 78) return "A";
    else if (marks >= 71) return "B+";
    else if (marks >= 64) return "B";
    else if (marks >= 57) return "C+";
    else if (marks >= 50) return "C";
    else if (marks >= 40) return "D";
    else return "E";
}

// Function to calculate and display average marks.
void avg_marks(Student students[], double sum){
	for (int i=0; i<NUMRECS; i++){
		sum = sum + students[i].totalMarks;
	}
	cout<<"Average marks: "<< fixed << setprecision(2) <<sum/NUMRECS<<endl;
}

// Function to calculate and display the pass rate.
void pass_rate(Student students[], int count) {
    int passedCount = 0;
    for (int i = 0; i < NUMRECS; i++) {
        if (students[i].totalMarks >= HALF_MARK) {
            passedCount++;
        }
    }
    int passRate = (passedCount * 100) / NUMRECS;
    cout << "Pass Rate: " << passRate << "%" << endl;
}

// Function to print the details of the highest scorer.
void print_highest_scorer(Student students[], int size) {
    double highestMarks = 0;
    int highestScorerIndex = -1;

    for (int i = 0; i < NUMRECS; i++) {
        if (students[i].totalMarks > highestMarks) {
            highestMarks = students[i].totalMarks;
            highestScorerIndex = i;
        }
    }

    if (highestScorerIndex != -1) {
        cout << "Details of the highest scorer:\n";
        cout <<"-------------------------------------------\n";
        cout << "ID: " << students[highestScorerIndex].id << endl;
        cout << "Coursework: " << students[highestScorerIndex].coursework << endl;
        cout << "Final Exam: " << students[highestScorerIndex].finalExam << endl;
        cout << "Total Marks: " << students[highestScorerIndex].totalMarks << endl;
        cout << "Grade: " << det_grade(students[highestScorerIndex].totalMarks) << endl;
    }
	else {
        cout << "No data found for the highest scorer." << endl;
    }
}

// Function to update the marks of a specific student by ID.
void update_marks(Student students[], int size) {
    string studentID;
    cout << "Enter the student ID for whom you want to update marks: ";
    cin >> studentID;

    for (int i = 0; i < size; i++) {
    	while (studentID!=students[i].id){
    		cout << "Student with ID " << studentID << " not found.\n";
        	cout <<"Try again.\n";
        	cin.clear();
	        cin>>studentID;
		}
        if (students[i].id == studentID) {
            double newCoursework, newFinalExam;
            cout << "Enter new coursework mark for student " << studentID << ": ";
            while (!(cin >> newCoursework) || newCoursework < 0 || newCoursework > HALF_MARK) {
                cout << "Invalid input. Please enter a valid coursework mark (0-" << HALF_MARK << "): ";
                cin.clear();
		        string not_an_int;
		        cin>>not_an_int;
            }
            cout << "Enter new final exam mark for student " << studentID << ": ";
            while (!(cin >> newFinalExam) || newFinalExam < 0 || newFinalExam > HALF_MARK) {
                cout << "Invalid input. Please enter a valid final exam mark (0-" << HALF_MARK << "): ";
                cin.clear();
                string not_an_int;
		        cin>>not_an_int;
            }
            students[i].coursework = newCoursework;
            students[i].finalExam = newFinalExam;
            students[i].totalMarks = students[i].coursework + students[i].finalExam;

            cout << "Marks updated successfully for student " << studentID << endl;
            cout << "Updated Total Marks: " << students[i].totalMarks << endl;
            cout << "Updated Grade: " << det_grade(students[i].totalMarks) << endl;
            return; //return to main function after updating marks
        }
    }
}
