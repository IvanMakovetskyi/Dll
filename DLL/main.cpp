#include <iostream>
#include <fstream>
#include <string>
#include "DoublyLinkedList.h"

using namespace std;

int main() {
    DoublyLinkedList list;
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    if (!inFile.is_open()) {
        cerr << "Error: could not open input.txt" << endl;
        return 1;
    }

    string word;
    while (inFile >> word) {

        if (word == "delete") {
            string nameToDelete;
            inFile >> nameToDelete;
            list.remove(nameToDelete);
        } 
        else {
            list.insert(word);
        }
    }

    // write ascending order
    list.displayAscending(outFile);

    // separator line
    outFile << "=============" << endl;

    // write descending order
    list.displayDescending(outFile);

    inFile.close();
    outFile.close();

    cout << "Processing complete. Check output.txt for results." << endl;
    return 0;
}