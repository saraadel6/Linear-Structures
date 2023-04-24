#include<bits/stdc++.h>
using namespace std;

template<class T>
class arrayBasedList {
    T* list;
    int maxSize;
    int length;
public:
    arrayBasedList(int size);
    void insert(T element);
    void insertAt(T element, int index);
    void removeAt(int index);
    void replaceAt(T newElement, int index);
    bool isItemAtEqual(T element, int index);
    bool isEmpty();
    bool isFull();
    int listSize();
    int maxListSize();
    void clear();
    void print();
    ~arrayBasedList();
};

template<class T>
arrayBasedList<T>::arrayBasedList(int size){
    if(size <= 0){
        cout << "Incorrect initial size for the array.\n";
        maxSize = 100;
    } else {
        maxSize = size;
        length = 0;
        list = new int[maxSize];
    }
}

template<class T>
void arrayBasedList<T>::insert(T element){
    if(isFull()){
        cout << "The list is full.\n";
    } else {
        list[length++] = element;
    }
}

template<class T>
void arrayBasedList<T>::removeAt(int index){
    if(index < 0 || index > length){
        cout << "Out of range.\n";
    } else {
        for(int i = index; i < length; ++i){
            list[i] = list[i + 1];
        }
        length--;
    }
}

template<class T>
void arrayBasedList<T>::replaceAt(T newElement, int index){
    if(index < 0 || index > length){
        cout << "Out of range.\n";
    } else {
        list[index] = newElement;
    }
}

template<class T>
void arrayBasedList<T>::insertAt(T element, int index){
    if(isFull()){
        cout << "The list is full.\n";
    } else if(index < 0 || index > length){
        cout << "Out of range.\n";
    } else {
        for(int i = length; i > index; --i){
            list[i] = list [i - 1];
        }
        list[index] = element;
        length++;
    }
}

template<class T>
bool arrayBasedList<T>::isEmpty(){
    if(length == 0){
        return true;
    } else {
        return false;
    }
}

template<class T>
bool arrayBasedList<T>::isFull(){
    if(length == maxSize){
        return true;
    } else {
        return false;
    }
}

template<class T>
bool arrayBasedList<T>::isItemAtEqual(T element, int index){
    if(index >= length || index < 0){
        return false;
    } else {
        return (list[index] == element);
    }
}

template<class T>
int arrayBasedList<T>::maxListSize(){
    return maxSize;
}

template<class T>
int arrayBasedList<T>::listSize(){
    return length;
}

template<class T>
arrayBasedList<T>::~arrayBasedList(){
    delete [] list;
}

template<class T>
void arrayBasedList<T>::print(){
    if(isEmpty()) cout << "The array is empty.\n";
    else {
        for(int i = 0; i < length; ++i){
            cout << list[i] << ' ';
        }
        cout <<"\n";
    }
}

template<class T>
void arrayBasedList<T>::clear(){
    length = 0;
}
// -------------------------------------------------------------------------------------------
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
doublyLinkedList<T>::doublyLinkedList(){
    first = last = NULL;
    length = 0;
}

template<class T>
void doublyLinkedList<T>::insertAtHead(T element){
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
void doublyLinkedList<T>::insertAtTail(T element){
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
void doublyLinkedList<T>::insertAt(T element, int index){
    Node* newNode = new Node;
    newNode->item = element;
    if (index < 0 || index > length)
        cout << "Out Of Range ...!\n";
    else if(index == 0){
        insertAtHead(element);
    } else if(index == length){
        insertAtTail(element);
    } else {
        Node* curr = first;
        for(int i = 1; i < index; ++i){
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
void doublyLinkedList<T>::insertAfter(Node* prevNode, T data){
    Node* newNode = new Node;
    newNode->item = data;
    Node* curr = first;
    while(curr->item != prevNode->item){
        curr = curr-> next;
    } 
    curr->next = newNode;
    curr->next->prev = newNode;
    newNode->next = curr->next;
    newNode->prev= curr;
    ++length;
}

template<class T>
bool doublyLinkedList<T>::isEmpty(){
    return (length == 0);
}

template<class T>
bool doublyLinkedList<T>::isItemAtEqual(T element, int index){
    if (index < 0 || index >= length){
        cout << "Out Of Range ...!\n";
        return false;
    } else {
        Node* temp = first;
        for(int i = 1; i <= index; ++i){
            temp = temp->next;
        }
        if(temp->item == element){
            return true;
        } 
        return false;
    }
}

template<class T>
bool doublyLinkedList<T>::isExist(T element){
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
void doublyLinkedList<T>::removeAtHead(){
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
void doublyLinkedList<T>::removeAtTail(){
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
void doublyLinkedList<T>::removeAt(int index){
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
    Node* temp = first;
    while(temp != NULL){

    }
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
void doublyLinkedList<T>::clear(){
    Node* curr = new Node;
    while(first != NULL){
        curr = first;
        first = first->next;
        delete first;
    }
    length = 0;
}

// --------------------------------------------------------------------------------------------------------------------------

template<class T>
class Stack{
    struct Node{
        T val;
        Node* next;
        Node(T val, Node* next){
            this->val = val;
            this->next = next;
        }
        Node(){}
    };
    Node* head;
    int _size;
public:
    Stack();
    void push(T newElement);
    void pop();
    T top();
    bool isEmpty();
    int stackSize();
    void clear();
    void print();
};

template <class T>
Stack<T>::Stack(){
    head = NULL;
    _size = 0;
}

template <class T>
bool Stack<T>::isEmpty(){
    return _size;
}

template <class T>
void Stack<T>::push(T newElement){
    head = new Node(newElement, head);
    ++_size;
}
template <class T>
void Stack<T>::pop(){
    if(_size == 0){
        cout << "The stack is empty!\n";
    } else {
        Node* temp = head; 
        head = head->next;
        delete temp;
        --_size;
    }
}

template <class T>
T Stack<T>::top(){
    if(_size == 0){
        cout << "The stack is empty!\n";
        return 0;
    } else {
        return head->val;
    }
}

template <class T>
int Stack<T>::stackSize(){
    return (_size == 0);
}

template <class T>
void Stack<T>::clear(){
    Node* temp = new Node();
    while(head != NULL){
        temp = head;
        head = head->next;
        delete temp;
    }
    _size = 0;
}

template <class T>
void Stack<T>::print(){
    if(head == NULL){
    cout << "The stack is empty!\n";
    } else{
        Node* curr = head;
        while(curr != NULL){
            cout << curr->val << ' ';
            curr = curr->next;
        }
        cout << '\n';
    }
}



