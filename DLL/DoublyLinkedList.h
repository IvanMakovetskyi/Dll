#pragma once
#include "Node.h"

class DoublyLinkedList
{
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void insert(string name);
    void remove(string name);
    void displayAscending(ofstream& out);
    void displayDescending(ofstream& out);
};