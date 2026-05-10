# CS112 Assignment 1: Student Record Management System

## Overview
This program is designed to manage student records, allowing users to view student details, update marks, and calculate statistics such as average marks and pass rates. It reads student data from a text file, processes it, and provides interactive options for users to update student records.

## Features
* **Print Student Details:** Display coursework, final exam marks, total marks, and grades for each student.
* **Update Marks:** Modify coursework and final exam marks for a specific student by entering their ID.
* **Calculate Average Marks:** Compute and display the average marks of all students.
* **Calculate Pass Rate:** Determine the percentage of students passing based on university criteria.
* **Identify Highest Scorer:** Find and display the details of the student with the highest total marks.

## University Passing Criteria
The program evaluates student pass rates based on the following criteria:
* A student passes if they achieve above 50% in both coursework and the final exam.
* *Note:* Alternatively, a student passes if they score at least 40% in the final exam alone (this is not done in the program since clear instructions were not provided on the total maximum mark of the final exam).

## Requirements
* C++ compiler (Dev C++ 4.9.9 is specifically recommended for this assignment).
* Input data file named `studentData.txt` (Ensure this file is in the same directory/folder as the program).

## Program Structure
* **Struct:** It is used for encapsulating data of each student which allows streamlined operations and improve code readability.
* **Main Function:** Provides a menu for the user to select options to print details, update marks, or exit the program.
* **Functions**:
  * `print_details`: Prints all student details, calculates average marks, pass rate, and highest scorer.
  * `det_grade`: Determines the grade based on total marks.
  * `avg_marks`: Calculates the average of total marks for all students.
  * `pass_rate`: Computes the percentage of students who passed.
  * `print_highest_scorer`: Displays the student with the highest total marks.
  * `update_marks`: Allows users to update the coursework and final exam marks for a student.

## Setup and Usage
1. **Compile the Program:** Use a C++ compiler to compile the source code `AssignmentNo1-2024.cpp`.
2. **Run the Program:** Execute the compiled program.
3. **Interact with the Program:** Follow the on-screen instructions to view student details, update marks, or exit the program.

## Data File Format
Ensure `studentData.txt` is formatted as follows:
`<Student ID> <Coursework Mark> <Final Exam Mark>`

**Example Data Format:**
```text
S00001	46.05	39.4
S00002	23.6	12.4
S00003	17.3	17.8

Authors
Ronil Prasad (ID: S11231541)
Shivan S. Prasad (ID: S11231502)