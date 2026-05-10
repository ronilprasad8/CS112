#ifndef LIST_H
#define LIST_H

#include <string>
#include "Student.h"

template <class T>
class Node {
    public:
        T data;
        Node* next;

        Node(T data);
};

template <class T>
class List {
    private:
        Node<T>* head;

    public:
        List();
        void insert(T data);
        void print_details();
        void avg_marks();
        void pass_rate();
        void print_highest_scorer();
        void update_marks(const string& studentID);
        ~List();
};

#endif
