#include"linear_structures.h"
int main(){
    singleLinkedList<int> l;
    l.insertAtTail(1);
    l.insertAtTail(2);
    l.insertAtTail(3);
    l.insertAtTail(4);
    l.insertAtTail(5);
    l.insertAt(66, 4);
    l.print();
}