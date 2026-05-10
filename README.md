# CS112: Student Record Management System

This repository contains two assignments for the **CS112: Data Structures & Algorithms** course. Both projects solve the same problem—managing a student grading system—but demonstrate progression by utilizing different data structures and programming paradigms.

## Repository Structure

* **`/A1` (Assignment 1):** * Implements the system using a static **Array of Structs**.
  * Contains a single C++ source file (`AssignmentNo1-2024.cpp`) for procedural execution.
  
* **`/A2` (Assignment 2):** * Upgrades the system using **Object-Oriented Programming (OOP)** and a dynamic **Linked List**.
  * Modularized into multiple files (`main.cpp`, `List.h`, `List.cpp`, `Student.h`, `Student.cpp`) representing individual classes and templates.

## Shared Features
Both versions of the program allow the user to:
1. **Load Data:** Read student IDs, coursework, and final exam marks from `studentData.txt`.
2. **Print Details:** Display a formatted table of all students, calculating their total marks and final grades based on the USP Handbook.
3. **Update Marks:** Search for a student by ID and modify their coursework and final exam marks.
4. **View Statistics:** Calculate the class average, overall pass rate, and the details of the highest-scoring student.

## Setup & Usage

1. **Navigate to the desired version:**
   Choose whether you want to run the procedural version (A1) or the OOP version (A2).
   
2. **Data File Requirement:**
   Ensure that the `studentData.txt` file is located in the same directory as the compiled executable for the program to read the data successfully.
   
3. **Compile and Run:**
   * **For A1:** Compile `AssignmentNo1-2024.cpp` using any standard C++ compiler (e.g., Dev C++ or g++).
   * **For A2:** Open the Visual Studio solution (`Asg2.sln`), build the project, and run it.

## Authors
* **Ronil Prasad** (ID: S11231541)
* **Shivan S. Prasad** (ID: S11231502)
