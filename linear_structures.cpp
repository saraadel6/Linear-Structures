#include"linear_structures.h"
int main(){
    doublyLinkedList<int> d1;
    d1.insertAtTail(1);
    d1.insertAtTail(2);
    d1.insertAtTail(3);
    d1.insertAtTail(4);
    d1.insertAtTail(5);
    // d1.swap(0, 4);
    d1.clear();
    d1.forwardTraversal();
}