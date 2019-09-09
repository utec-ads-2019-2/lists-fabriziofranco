#include <iostream>
#include "test/tester.h"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "===========================================================" << endl;
    cout << "\tLists Practice" << endl;
    cout << "===========================================================" << endl << endl;
    Tester::execute();
    CircularLinkedList<int> C1;
    C1.push_back(1);
    C1.push_back(2);
    C1.push_back(3);
    C1.push_back(4);
    C1.push_back(4);
    C1.push_back(4);
    C1.push_back(4);
    C1.push_back(4);
    C1.push_back(7);
    C1.print();
    C1.reverse();
    C1.print();
    return EXIT_SUCCESS;
}
