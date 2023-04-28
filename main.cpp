#include"stack&&problems.cpp"
#include"queue&&problems.cpp"
#include"singleLinkedList&&problems.cpp"
#include"doublyLinkedList.cpp"
#include"circularLinkedList.cpp"
#include"arrayBasedList.cpp"


int main(){
    doublyLinkedList<int> l;
    l.insertAtTail(1);
    l.insertAtTail(2);
    l.insertAtTail(3);
    l.insertAtTail(4);
    l.insertAtTail(5);
    l.swap(1, 4);
    l.forwardTraversal();
    // singleLinkedList<int> list1;
    // list1.insertAtTail(1);
    // list1.insertAtTail(4);
    // list1.insertAtTail(5);

    // singleLinkedList<int> list2;
    // list2.insertAtTail(1);
    // list2.insertAtTail(3);
    // list2.insertAtTail(4);

    // singleLinkedList<int> list3;
    // list3.insertAtTail(2);
    // list3.insertAtTail(6);

    // singleLinkedList<int> lists[] = {list1, list2, list3};
    // singleLinkedList<int> mergedList = mergeLists(lists, 3);
    // cout << "List1 after merging: ";
    // mergedList.print();

    // singleLinkedList<int> list4;
    // list4.insertAtTail(1);
    // list4.insertAtTail(3);
    // list4.insertAtTail(5);
    // list4.insertAtTail(7);

    // singleLinkedList<int> list5;
    // list5.insertAtTail(2);
    // list5.insertAtTail(4);
    // list5.insertAtTail(6);
    // list5.insertAtTail(8);

    // singleLinkedList<int> list6;
    // list6.insertAtTail(0);
    // list6.insertAtTail(9);
    // list6.insertAtTail(10);

    // singleLinkedList<int> lists2[] = {list4, list5, list6};
    // singleLinkedList<int> mergedList2 = mergeLists(lists2, 3);
    // cout << "List2 after merging: ";
    // mergedList2.print();
}