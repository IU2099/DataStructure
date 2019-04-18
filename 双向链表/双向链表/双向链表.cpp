#include "CDoubleLinkedList.h"

int main()
{
    CDoubleLinkedList<int> text;

    text.addElement(10, 0);
    text.addElement(20, 1);
    text.addElement(30, 2);
    text.addElement(40, 3);
    text.addElement(50, 4);
    text.addElement(60, 3);

    text.delElement(3);
    text.delElement(4);
}