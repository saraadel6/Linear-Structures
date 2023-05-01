#include"arrayBasedList.cpp"
#include"singleLinkedList&&problems.cpp"
#include"doublyLinkedList.cpp"
#include"circularLinkedList.cpp"
#include"stack&&problems.cpp"
#include"queue&&problems.cpp"

int main(){ 
    arrayBasedList<int> a;
    a.insert(1);
    a.insert(2);
    a.insert(3);
    cout << a.isItemAtEqual(2, 1) << '\n';
    cout << a.listSize() << "\n";
    a.print();
}