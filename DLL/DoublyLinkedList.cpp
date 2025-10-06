#include "DoublyLinkedList.h"
#include <fstream>
#include <iostream>
#include "Node.h"

DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
}

DoublyLinkedList::~DoublyLinkedList() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void DoublyLinkedList::insert(string data) {
    Node* node = new Node(data);

    if(!head) {  //no other nodes
        head = node;
        tail = head;
    }else if (data < head->data) { //smaller than head
        node->next = head;
        head->prev = node;
        head = node;
    }else if (data > tail->data) { //larger than tail
        node->prev = tail;
        tail->next = node;
        tail = node;
    }else { //somewhere in the middle
        Node* current = head;
        while (current && current->data < data) {
            current = current->next;
        }
        node->next = current;
        node->prev = current->prev;
        current->prev->next = node;
        current->prev = node;
    }

}

void DoublyLinkedList::remove(string data) {
    if (!head) return;  // list empty


    Node* current = head;

    // find the node to delete
    while (current && current->data != data) {
        current = current->next;
    }

    if (!current) return;  // not found

    //  deleting the head
    if (current == head) {
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr; // list became empty
    }
    // deleting the tail
    else if (current == tail) {
        tail = tail->prev;
        tail->next = nullptr;
    }
    // deleting in the middle
    else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

    delete current;
}

void DoublyLinkedList::displayAscending(ofstream& out) {
    Node* current = head;

    while(current) {
        out << current->data << endl;

        current = current->next;
    }
}

void DoublyLinkedList::displayDescending(ofstream& out) {
    Node* current = tail;

    while(current) {
        out << current->data << endl;

        current = current->prev;
    }
}