//Doubly Linked List Implementation
#include<bits/stdc++.h>
using namespace std;
template<class T>
class doublyLinkedList {
    struct Node{
        T item;
        Node* prev;
        Node* next;
    };
    Node* first;
    Node* last;
    int length;
public:
    doublyLinkedList();
    void insertAtHead(T element);
    void insertAtTail(T element);
    void insertAt(T element, int index);
    void insertAfter(Node* prevNode, T data);
    void removeAtHead();
    void removeAtTail();
    void removeAt(int index);
    T retrieveAt(int index);
    void replaceAt(T newElement, int index);
    bool isExist (T element);
    bool isItemAtEqual(T element, int index);
    void  swap (int firstItemIdx, int secondItemIdx);
    void reverse();
    bool isEmpty();
    int doubleLinkedListSize();
    void clear();
    void forwardTraversal();
    void backwardTraversal();
};

template<class T>
doublyLinkedList<T>::doublyLinkedList() {
    first = last = NULL;
    length = 0;
}

template<class T>
void doublyLinkedList<T>::insertAtHead(T element) {
    Node newNode = new Node;
    newNode -> item = element;
    if(length == 0){
        first = last = newNode;
        newNode->next = newNode->prev = NULL;
    } else {
        newNode->next = first;
        newNode->prev = NULL;
        first = newNode;
    }
    ++length;
}

template<class T>
void doublyLinkedList<T>::insertAtTail(T element) {
    Node* newNode = new Node;
    newNode -> item = element;
    if(length == 0){
        first = last = newNode;
        newNode->next = newNode->prev = NULL;
    } else {
        newNode->prev = last;
        newNode->next = NULL;
        last->next = newNode;
        last = newNode; 
    }
    ++length;
}

template<class T>
void doublyLinkedList<T>::insertAt(T element, int index) {
    Node* newNode = new Node;
    newNode->item = element;
    if (index < 0 || index > length)
        cout << "Out Of Range ...!\n";
    else if(index == 0){
        insertAtHead(element);
    } else if(index == length) {
        insertAtTail(element);
    } else {
        Node* curr = first;
        for(int i = 1; i < index; ++i) {
            curr = curr->next;
        }
        curr->next = newNode;
        curr->next->prev = newNode;
        newNode->next = curr->next;
        newNode->prev= curr;
        ++length;
    }
}



template<class T>
void doublyLinkedList<T>::insertAfter(Node* prevNode, T data) {
    Node* newNode = new Node;
    newNode->item = data;
    Node* curr = first;
    while(curr->item != prevNode->item) {
        curr = curr-> next;
    } 
    curr->next = newNode;
    curr->next->prev = newNode;
    newNode->next = curr->next;
    newNode->prev= curr;
    ++length;
}

template<class T>
bool doublyLinkedList<T>::isEmpty() {
    return (length == 0);
}

template<class T>
bool doublyLinkedList<T>::isItemAtEqual(T element, int index) {
    if (index < 0 || index >= length){
        cout << "Out Of Range ...!\n";
        return false;
    } else {
        Node* temp = first;
        for(int i = 1; i <= index; ++i) {
            temp = temp->next;
        }
        if(temp->item == element) {
            return true;
        } 
        return false;
    }
}

template<class T>
bool doublyLinkedList<T>::isExist(T element) {
    Node* temp = first;
    for(int i = 1; i <= length; ++i){
        if(temp->item == element){
            return true;
        }
        temp = temp->next;
    }
    return false;
}
template<class T>
void doublyLinkedList<T>::removeAtHead() {
    if(isEmpty()){
        cout << "Can not remove from empty llist.\n";
    } else if (length == 1) {
        delete first;
        last = first = NULL;
        --length;
    } else {
        Node* temp = first;
        first->next->prev = NULL;
        first = first->next;
        delete temp;
        --length;
    }
}

template<class T>
void doublyLinkedList<T>::removeAtTail() {
    if(isEmpty()){
        cout << "Can not remove from empty llist.\n";
    } else if (length == 1) {
        delete first;
        last = first = NULL;
        --length;
    } else {
        Node* temp = last;
        last = last->prev;
        last->next = NULL;
        delete temp;
        --length;
    }
}

template<class T>
void doublyLinkedList<T>::removeAt(int index) {
    if (index < 0 || index >= length)
        cout << "Out Of Range ...!\n";
    else if(index == 0){
        removeAtHead();
    } else if(index == length - 1){
        removeAtTail();
    } else {
        Node* temp = first;
        for(int i = 1; i < index + 1; ++i){
            temp = temp->next;
        }
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        delete temp;
        length--;
    }
    
}

template<class T>
T doublyLinkedList<T>::retrieveAt(int index){
    if(index >= length || index < 0){
        cout << "Out of range!\n";
        return 0;
    } else{
        Node* temp = first;
        for(int i = 1; i <= index; ++i){
            temp = temp->next;
        }
        return temp->item;
    }

}

template<class T>
void doublyLinkedList<T>::replaceAt(T newElement, int index){
    if(index >= length || index < 0){
        cout << "Out of range!\n";
    } else{
        Node* temp = first;
        for(int i = 1; i <= index; ++i){
            temp = temp->next;
        }
        temp->item = newElement;
    }

}

template<class T>
int doublyLinkedList<T>::doubleLinkedListSize(){
    return length;
}

template<class T>
void doublyLinkedList<T>::swap(int firstItemIdx, int secondItemIdx){

}

template<class T>
void doublyLinkedList<T>::reverse(){
    Node* temp = NULL;
    Node* curr = first;
    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if (temp != NULL)
        first = temp->prev;
}

template<class T>
void doublyLinkedList<T>::forwardTraversal(){
    if(isEmpty()){
        cout << "The linked list is empyty!\n";
    } else{
        Node* temp = first;
        while(temp->next != NULL){
            cout << temp->item << ' ';
            temp = temp->next;
        }
        cout << temp->item;
        cout << '\n';
    }
}

template<class T>
void doublyLinkedList<T>::backwardTraversal(){
    if(isEmpty()){
        cout << "The linked list is empyty!\n";
    } else{
        Node* temp = last;
        while(temp->prev != NULL){
            cout << temp->item << ' ';
            temp = temp->prev;
        }
        cout << temp->item;
        cout << '\n';
    }
}

template<class T>
void doublyLinkedList<T>::clear() {
    Node* curr = new Node;
    while(first != NULL) {
        curr = first;
        first = first->next;
        delete first;
    }
    length = 0;
}
// #####################################################################################################################
