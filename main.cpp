#include <iostream>
#include "test/tester.h"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "===========================================================" << endl;
    cout << "\tLists Practice" << endl;
    cout << "===========================================================" << endl << endl;
    Tester::execute();



    auto C1= new CircularLinkedList<int>; auto L1= new LinkedList<int>; auto F1= new ForwardList<int>;

    C1->push_back(1);C1->push_back(2);C1->push_back(3);C1->push_back(4);C1->push_back(5);
    C1->push_back(1);C1->push_back(2);C1->push_back(3);C1->push_back(4);C1->push_back(5);

    L1->push_back(1);L1->push_back(2);L1->push_back(3);L1->push_back(4);L1->push_back(5);
    L1->push_back(1);L1->push_back(2);L1->push_back(3);L1->push_back(4);L1->push_back(5);

    F1->push_back(1);F1->push_back(2);F1->push_back(3);F1->push_back(4);F1->push_back(5);
    F1->push_back(1);F1->push_back(2);F1->push_back(3);F1->push_back(4);F1->push_back(5);

    auto it = C1->begin();
    auto it2 = ++it;
    cout << *it2 << endl;

    C1->print();L1->print();F1->print();

    C1->sort();L1->sort();F1->sort();

    C1->print();L1->print();F1->print();

    delete C1; delete L1; delete F1;


    return EXIT_SUCCESS;
}
