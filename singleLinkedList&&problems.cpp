//Single Linked List
#include<bits/stdc++.h>
using namespace std;
template <class T>
struct Node {
public:
    T item;
    Node *next;
};
template <class T>
class singleLinkedList{

    Node<T> *head;
    Node<T> *tail;
    int length;
public:
    singleLinkedList();
    void insertAtHead(T element);
    void insertAtTail(T element);
    void insertAt(T element, int index);
    void removeAtHead();
    void removeAtTail();
    void removeAt(int index);
    T retrieveAt(int index);
    void replaceAt(T newElement, int index);
    bool isExist (T element);
    bool isItemAtEqual(T element, int index);
    void  swap (int firstItemIdx, int secondItemIdx);
    bool isEmpty();
    int singleLinkedListSize();
    void clear();
    void print();
    void printByHead(Node<T>* first);
    Node<T>* getHead() {
        return head;
    }
};

template<class T>
singleLinkedList<T>::singleLinkedList() {
    head=tail=NULL;
    length=0;
}

template<class T>
void singleLinkedList<T>::insertAtHead(T element) {
    Node<T> *node = new Node<T>();
    node->item=element;
    if(isEmpty()){
        head=tail=node;
        node->next=NULL;
    }
    else{
        node->next=head;
        head=node;
    }
    length++;
}

template<class T>
void singleLinkedList<T>::insertAtTail(T element) {
    Node<T> *node = new Node<T>();
    node->item=element;
    if(isEmpty()){
        head=tail=node;
        node->next=NULL;
    }
    else{
        tail->next=node;
        node->next=NULL;
        tail=node;
    }
    length++;
}

template<class T>
void singleLinkedList<T>::insertAt(T element, int index) {
    if(index<0||index>length)
        cout<<"OUT OF RANGE!\n";
    else if(index==0)
        insertAtHead(element);
    else if(index==length)
        insertAtTail(element);
    else{
        Node<T> *node = new Node<T>();
        node -> item = element;
        Node<T> *current = head;
        for(int i=1; i<index; i++){
            current=current->next;
        }
        node->next= current->next;
        current->next=node;
        length++;
    }
}

template<class T>
void singleLinkedList<T>::removeAtHead() {
    if(length==0)
        cout << "The list is empty!\n";
    else if(length==1){
        delete head;
        head=tail=NULL;
        length--;
    }
    else{
        head= head->next;
        length--;
    }
}

template<class T>
void singleLinkedList<T>::removeAtTail() {
    if(length==0)
        cout << "The list is empty!\n";
    else if(length==1){
        delete head;
        head=tail=NULL;
        length--;
    }
    else{
        Node<T> *node=head;
        Node<T> *nextNode=head->next;
        while(nextNode!=tail){
            node=nextNode;
            nextNode=nextNode->next;
        }
        delete nextNode;
        node->next=NULL;
        tail=node;
        length--;
    }
}

template<class T>
void singleLinkedList<T>::removeAt(int index) {
    if (index < 0 || index > length)
        cout << "OUT OF RANGE!\n";
    else if(index==0)
        removeAtHead();
    else if (index==length)
        removeAtTail();
    else{
        Node<T> *node = head;
        Node<T> *nextNode=head->next;
        for(int i=1; i<index; i++){
            node=nextNode;
            nextNode=nextNode->next;
        }
        node->next=nextNode->next;
        delete nextNode;
        length--;
    }
}

template<class T>
T singleLinkedList<T>::retrieveAt(int index) {
    if(index<0||index>length) {
        cout << "OUT OF RANGE!\n";
        return 0;
    }
    else {
        Node<T> *node = head;
        for (int i = 1; i < index; i++) {
            node = node->next;
        }
        return node->item;
    }
}

template<class T>
void singleLinkedList<T>::replaceAt(T newElement, int index) {
    if (index < 0 || index > length)
        cout << "OUT OF RANGE!\n";
    else {
        Node<T> *node = head;
        for (int i = 1; i <= index; i++) {
            node = node->next;
        }
        node->item = newElement;
    }
}

template<class T>
bool singleLinkedList<T>::isExist(T element) {
    Node<T> *node = head;
    for (int i = 0; i < length; i++) {
        if (node->item == element) {
            cout<<"YES, EXIST\n";
            return true;
        }
        node = node->next;
    }
    cout<<"NOT EXIST!\n";
    return false;
}

template<class T>
bool singleLinkedList<T>::isItemAtEqual(T element, int index) {
    if (index < 0 || index > length) {
        cout << "OUT OF RANGE!\n";
        return 0;
    }
    else {
        Node<T> *node = head;
        for(int i = 1; i <= index; ++i){
            node = node->next;
        }
        if(element==node->item){
            cout<<"Yes, equal\n";

            return 1;
        }
        cout<<"Not equal!\n";

        return 0;
    }
}

template<class T>
void singleLinkedList<T>::swap(int firstItemIdx, int secondItemIdx) {
    if (firstItemIdx == secondItemIdx || firstItemIdx<0 || secondItemIdx<0)
        return;

    Node<T> *node1 = head;
    Node<T> *prev1 = NULL;
    for (int i = 0; i < firstItemIdx && node1 != NULL; i++) {
        prev1 = node1;
        node1 = node1->next;
    }
    Node<T> *node2 = head;
    Node<T> *prev2 = NULL;
    for (int i = 0; i < secondItemIdx && node2 != NULL; i++) {
        prev2 = node2;
        node2 = node2->next;
    }

    if (node1 == NULL || node2 == NULL) {
        return;
    }
    if (prev1 != NULL)
        prev1->next = node2;
    else
        head = node2;
    if (prev2 != NULL)
        prev2->next = node1;
    else
        head = node1;
    Node<T> *temp = node1->next;
    node1->next = node2->next;
    node2->next = temp;
}

template<class T>
bool singleLinkedList<T>::isEmpty() {
    return (length==0);
}

template<class T>
int singleLinkedList<T>::singleLinkedListSize() {
    return length;
}

template<class T>
void singleLinkedList<T>::clear() {
    Node<T> *current;
    while(head!=NULL){
        current=head;
        head=head->next;
        delete current;
    }
    tail=NULL;
    length=0;
}

template<class T>
void singleLinkedList<T>::print() {
    Node<T> *node = head;
    while(node!=NULL){
        cout << node->item << " ";
        node=node->next;
    }
    cout<<endl;
}

template<class T>
void singleLinkedList<T>::printByHead(Node<T>* first) {
    Node<T> *node = first;
    while(node!=NULL){
        cout << node->item << " ";
        node=node->next;
    }
    cout<<endl;
}
// #####################################################################################################################

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
// ########################################################################################################################
template<class T>
Node<T>* combineNodesBetweenZeros(Node<T>* head) {
Node<T>* curr = head->next;

while (curr) {
    Node<T>* running = curr;
    int sum = 0;
    while (running->item) {
    sum += running->item;
    running = running->next;
    }
    curr->item = sum;
    curr->next = running->next;
    curr = running->next;
}
return head->next;
// Node<T>* temp = head;
// head = head->next;
// delete temp;
// return head;
}