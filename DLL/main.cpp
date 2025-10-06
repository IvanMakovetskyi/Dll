#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> 
#include "DoublyLinkedList.h"

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
        transform(word.begin(), word.end(), word.begin(),
              [](unsigned char c){ return tolower(c); });

        if (word == "delete") {
            string nameToDelete;
            inFile >> nameToDelete;
            transform(nameToDelete.begin(), nameToDelete.end(),
                  nameToDelete.begin(),
                  [](unsigned char c){ return tolower(c); });
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