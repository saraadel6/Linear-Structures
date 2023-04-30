#include"arrayBasedList.cpp"
#include"singleLinkedList&&problems.cpp"
#include"doublyLinkedList.cpp"
#include"circularLinkedList.cpp"
#include"stack&&problems.cpp"
#include"queue&&problems.cpp"

int main(){
    doublyLinkedList<int> l;
    l.insertAtTail(1);
    l.insertAtTail(2);
    l.insertAtTail(3);
    l.insertAtTail(4);
    l.insertAtTail(5);
    l.insertAtTail(6);
    l.insertAfter(l.getHead()->next->next->next->next, 44);
    l.forwardTraversal();
}