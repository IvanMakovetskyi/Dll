#ifndef NODE_H
#define NODE_H
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


#endif // NODE_H