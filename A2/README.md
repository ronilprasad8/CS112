# CS112 Assignment 2: Student Record Management System

## Overview
This program is designed to manage student records, allowing users to view student details, update marks, and calculate statistics such as average marks and pass rates. Building upon the previous assignment, this version upgrades the architecture by using **Object-Oriented Programming (OOP)** principles. It stores the data dynamically using a **Linked List of class objects** rather than a static array of structs, making the program more modular and dynamic.

## Features
* **Print Student Details:** Display coursework, final exam marks, total marks, and grades for each student in a formatted table.
* **Update Marks:** Modify coursework and final exam marks for a specific student by entering their ID.
* **Calculate Average Marks:** Compute and display the average marks of all students rounded to two decimal places.
* **Calculate Pass Rate:** Determine the percentage of students passing based on university criteria.
* **Identify Highest Scorer:** Find and display the full details of the student with the highest total marks.

## University Passing Criteria
The program evaluates student grades and pass rates based on the official USP Handbook 2024 criteria. 
*(Note: As per standard guidelines, passing generally requires a satisfactory threshold in total marks, coursework, and the final exam).*

## Requirements
* **IDE:** Visual Studio IDE (strictly required for this assignment).
* **Compiler:** Standard C++ Compiler (MSVC via Visual Studio).
* **Input Data:** A text file named `studentData.txt` must be placed in the project directory so the executable can read it.

## Program Structure
The application is modularized into header and implementation files:
* **`Student` Class (`Student.h`, `Student.cpp`):** Encapsulates individual student data (ID, coursework, final exam, and total marks) and provides getter methods and an `updateMarks` method.
* **`Node` Template Class (`List.h`):** Represents an individual element in the Linked List containing the data and a pointer to the next node.
* **`List` Template Class (`List.h`, `List.cpp`):** Handles the dynamic Linked List operations. It contains methods to insert data, calculate statistics (`avg_marks`, `pass_rate`, `print_highest_scorer`), and print or update details.
* **`main.cpp`:** Contains the program's entry point. It handles reading the data file, populating the Linked List, and displaying the interactive user menu.

## Setup and Usage
1. **Open the Project:** Open the provided solution file (`Asg2.sln`) in Visual Studio IDE.
2. **Verify File Location:** Ensure that `studentData.txt` is located in the same directory as your source code / working directory so it can be read successfully.
3. **Compile and Build:** Build the solution using the Visual Studio build menu (Ctrl + Shift + B).
4. **Run the Program:** Execute the program (F5 or Ctrl + F5).
5. **Interact:** Follow the on-screen menu to:
   * Enter `1` to Print details.
   * Enter `2` to Update Marks.
   * Enter `3` to Quit.

## Data File Format
Ensure `studentData.txt` is formatted exactly as follows:
`<Student ID> <Coursework Mark> <Final Exam Mark>`

**Example Data Format:**
```text
ID	Coursework	Final_Exam
S00001	46.05	39.4
S00002	23.6	12.4
S00003	17.3	17.8