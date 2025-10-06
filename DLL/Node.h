#pragma once
#include <string>
using namespace std;

class Node {
public:
    string data;
    Node* next;
    Node* prev;

    Node(string _data); 
    ~Node();
};

///Constructor
Node::Node(string _data) {
    data = _data;
    next = nullptr;
    prev = nullptr;
}

///Deconstructor
Node::~Node() {
    delete next;
    delete prev;
}