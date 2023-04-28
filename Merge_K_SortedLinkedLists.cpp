#include "linear_structures.cpp"
using namespace std;

template<class T>
singleLinkedList<T> merge(singleLinkedList<T>& list1, singleLinkedList<T>& list2) {
    singleLinkedList<T> newList;
    Node<T> *node1;
    Node<T> *node2;
    node1 = list1.getHead();
    node2 = list2.getHead();
    while (node1 != NULL && node2 != NULL) {
        if (node1->item < node2->item) {
            newList.insertAtTail(node1->item);
            node1 = node1->next;
        }
        else {
            newList.insertAtTail(node2->item);
            node2 = node2->next;
        }
    }
    while (node1 != NULL) {
        newList.insertAtTail(node1->item);
        node1 = node1->next;
    }
    while (node2 != NULL) {
        newList.insertAtTail(node2->item);
        node2 = node2->next;
    }
    return newList;
}

template<typename T>
singleLinkedList<T> mergeLists(singleLinkedList<T>* list, int n) {
    if (n == 0)
        return singleLinkedList<T>();

    if (n == 1)
        return list[0];

    if (n == 2)
        return merge(list[0], list[1]);

    int middle = n / 2;
    singleLinkedList<T> left = mergeLists(list, middle);
    singleLinkedList<T> right = mergeLists(list + middle, n - middle);
    return merge(left, right);
}


int main() {
    singleLinkedList<int> list1;
    list1.insertAtTail(1);
    list1.insertAtTail(4);
    list1.insertAtTail(5);

    singleLinkedList<int> list2;
    list2.insertAtTail(1);
    list2.insertAtTail(3);
    list2.insertAtTail(4);

    singleLinkedList<int> list3;
    list3.insertAtTail(2);
    list3.insertAtTail(6);

    singleLinkedList<int> lists[] = {list1, list2, list3};
    singleLinkedList<int> mergedList = mergeLists(lists, 3);
    cout << "List1 after merging: ";
    mergedList.print();

    singleLinkedList<int> list4;
    list4.insertAtTail(1);
    list4.insertAtTail(3);
    list4.insertAtTail(5);
    list4.insertAtTail(7);

    singleLinkedList<int> list5;
    list5.insertAtTail(2);
    list5.insertAtTail(4);
    list5.insertAtTail(6);
    list5.insertAtTail(8);

    singleLinkedList<int> list6;
    list6.insertAtTail(0);
    list6.insertAtTail(9);
    list6.insertAtTail(10);

    singleLinkedList<int> lists2[] = {list4, list5, list6};
    singleLinkedList<int> mergedList2 = mergeLists(lists2, 3);
    cout << "List2 after merging: ";
    mergedList2.print();
}