#include "CDoubleLinkedList.h"



int main()
{
    CDoubleLinkedList test;

    test.addElement(10, 0);
    test.addElement(20, 1);
    test.addElement(30, 2);
    test.addElement(40, 3);
    test.addElement(50, 4);
    test.traverseList();
    cout << endl;

    test.addElement(60, 3);

    test.traverseList();
    cout << endl;

    test.delElement(3);
    test.traverseList();
    cout << endl;

    test.changeList(99,2);
    test.traverseList();
    cout << endl;

    cout << test.checkList(2);
    cout << endl;
    test.traverseList();
}