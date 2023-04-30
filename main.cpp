#include"arrayBasedList.cpp"
#include"singleLinkedList&&problems.cpp"
#include"doublyLinkedList.cpp"
#include"circularLinkedList.cpp"
#include"stack&&problems.cpp"
#include"queue&&problems.cpp"

int main(){
    singleLinkedList<int> l;
    l.insertAtTail(0);
    l.insertAtTail(3);
    l.insertAtTail(4);
    l.insertAtTail(0);
    l.insertAtTail(5);
    l.insertAtTail(8);
    l.insertAtTail(0);
    l.insertAtTail(1);
    l.insertAtTail(1);
    l.insertAtTail(0); 
    l.printByHead(combineNodesBetweenZeros(l.getHead()));
}