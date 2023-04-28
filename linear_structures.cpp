#include<bits/stdc++.h>
using namespace std;

// Array-Based List
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
// #####################################################################################################################
//Single Linked List
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
// #####################################################################################################################
//Doubly Linked List
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
//Circular Linked List
template<class T>
class circularLinkedList{
    struct Node{
        T item;
        Node* next;
    };
    Node* head;
    Node* tail;
    int length;
public:
    circularLinkedList();
    void insertAtHead(T element);
    void insertAtEnd(T element);
    void insertAt(T element, int index);
    void removeAtHead();
    void removeAtEnd();
    void removeAt(int index);
    T retrieveAt(int index);
    void replaceAt(T newElement, int index);
    bool isExist (T element);
    bool isItemAtEqual(T element, int index);
    void  swap (int firstItemIdx, int secondItemIdx);
    bool isEmpty();
    int circularLinkedListSize();
    void clear();
    void print();
};

template <class T>
circularLinkedList<T>::circularLinkedList() {
    head=tail=NULL;
    length=0;
}

template <class T>
void circularLinkedList<T>::insertAtHead(T element) {
    Node* node= new Node;
    node->item=element;
    if(isEmpty()){
        head=tail=node;
        tail->next=head;
    }
    else{
        node->next=head;
        head=node;
        tail->next=head;
    }
    length++;
}

template <class T>
void circularLinkedList<T>::insertAtEnd(T element) {
    Node* node= new Node;
    node->item=element;
    if(isEmpty()){
        head=tail=node;
        tail->next=head;
    }
    else{
        tail->next=node;
        node->next=head;
        tail=node;
    }
    length++;
}

template<class T>
void circularLinkedList<T>::insertAt(T element, int index) {
    if(index<0||index>length)
        cout<<"OUT OF RANGE!\n";
    else if(index==0)
        insertAtHead(element);
    else if(index==length)
        insertAtEnd(element);
    else{
        Node* node = new Node;
        node -> item = element;
        Node* current = head;
        for(int i=1; i<index; i++){
            current=current->next;
        }
        node->next= current->next;
        current->next=node;
        length++;
    }
}

template<class T>
void circularLinkedList<T>::removeAtHead() {
    if(length==0)
        cout << "The list is empty!\n";
    else if(length==1){
        delete head;
        head=tail=NULL;
        length--;
    }
    else{
        head= head->next;
        tail->next=head;
        length--;
    }
}

template<class T>
void circularLinkedList<T>::removeAtEnd() {
    if(length==0)
        cout << "The list is empty!\n";
    else if(length==1){
        delete head;
        head=tail=NULL;
        length--;
    }
    else{
        Node* node=head;
        Node* nextNode=head->next;
        while(nextNode!=tail){
            node=nextNode;
            nextNode=nextNode->next;
        }
        delete nextNode;
        node->next=head;
        tail=node;
        length--;
    }
}

template<class T>
void circularLinkedList<T>::removeAt(int index) {
    if (index < 0 || index >= length)
        cout << "OUT OF RANGE!\n";
    else if(index==0)
        removeAtHead();
    else if (index==length-1)
        removeAtEnd();
    else{
        Node* node = head;
        Node* nextNode=head->next;
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
T circularLinkedList<T>::retrieveAt(int index) {
    if(index<0||index>=length) {
        cout << "OUT OF RANGE!\n";
        return 0;
    }
    else {
        Node *node = head;
        for (int i = 0; i < index; i++) {
            node = node->next;
        }
        return node->item;
    }
}

template<class T>
void circularLinkedList<T>::replaceAt(T newElement, int index) {
    if (index < 0 || index >= length)
        cout << "OUT OF RANGE!\n";
    else {
        Node *node = head;
        for (int i = 0; i < index; i++) {
            node = node->next;
        }
        node->item = newElement;
    }
}

template<class T>
bool circularLinkedList<T>::isExist(T element) {
    Node *node = head;
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
bool circularLinkedList<T>::isItemAtEqual(T element, int index) {
    if (index < 0 || index > length) {
        cout << "OUT OF RANGE!\n";
        return 0;
    }
    else {
        Node* node = head;
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

template <class T>
bool circularLinkedList<T>::isEmpty() {
    return (length==0);
}


template <class T>
void circularLinkedList<T>::clear() {
    Node* current=head;
    Node* nextNode=NULL;
    do {
        nextNode = current->next;
        delete current;
        current = nextNode;
    } while (current != head);
    head = NULL;
    length=0;
}
template <class T>
void circularLinkedList<T>::print() {
    if(isEmpty()){
        cout<<"The circular linked list is empty!\n";
        return;
    }
    else {
        Node* current = head;
        do{
            cout<<current->item<<" ";
            current=current->next;
        }
        while(current!=head);
        cout<<endl;
    }
}
// #####################################################################################################################
//Stack
template<class T>
class Stack {
    struct Node {
        T val;
        Node* next;
        Node(T val, Node* next) {
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
Stack<T>::Stack() {
    head = NULL;
    _size = 0;
}

template <class T>
bool Stack<T>::isEmpty() {
    return (_size == 0);
}

template <class T>
void Stack<T>::push(T newElement) {
    head = new Node(newElement, head);
    ++_size;
}
template <class T>
void Stack<T>::pop() {
    if(_size == 0) {
        cout << "The stack is empty!\n";
    } else {
        Node* temp = head; 
        head = head->next;
        delete temp;
        --_size;
    }
}

template <class T>
T Stack<T>::top() {
    if(_size == 0) {
        cout << "The stack is empty!\n";
        return 0;
    } else {
        return head->val;
    }
}

template <class T>
int Stack<T>::stackSize() {
    return (_size == 0);
}

template <class T>
void Stack<T>::clear() {
    Node* temp = new Node();
    while(head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
    _size = 0;
}

template <class T>
void Stack<T>::print() {
    if(head == NULL) {
    cout << "The stack is empty!\n";
    } else{
        Node* curr = head;
        while(curr != NULL) {
            cout << curr->val << ' ';
            curr = curr->next;
        }
        cout << '\n';
    }
}

// #####################################################################################################################
//Queue
template<class T>
class Queue {
    struct Node {
        Node *next;
        T item;
    };
    int length;
    Node *front, *end;
public:
    Queue();
    void enqueue(T element);
    T dequeue();
    T first();
    bool isEmpty();
    int queueSize();
    void clear();
    void print();
};

template<class T>
Queue<T>::Queue() {
    front = end = NULL;
    length=0;
}

template<class T>
void Queue<T>::enqueue(T element) {
    Node* node = new Node;
    node->item=element;
    node->next=NULL;
    if(isEmpty()){
        front=end=node;
    }
    else{
        end->next=node;
        end=node;
    }
    length++;
}

template<class T>
T Queue<T>::dequeue() {
    if(isEmpty()){
        cout<<"Empty Queue!\n";
        return T(); // Return default value of T
    }
    else{
        T item = front->item;
        Node* temp = front;
        front = front->next;
        delete temp;
        length--;
        return item;
    }
}

template<class T>
T Queue<T>::first() {
    if(isEmpty()){
        cout<<"Empty Queue!\n";
        return 0;
    }
    else{
        return front->item;
    }
}

template<class T>
bool Queue<T>::isEmpty() {
    return (length==0);
}

template<class T>
int Queue<T>::queueSize() {
    return length;
}

template<class T>
void Queue<T>::clear() {
    if (isEmpty())
        cout << "The Queue is empty!\n";
    else {
        Node *current;
        while (front != NULL) {
            current = front;
            front = front->next;
            delete current;
        }
        front = end = NULL;
        length = 0;
    }
}

template<class T>
void Queue<T>::print(){
    if(isEmpty())
        cout<<"The Queue is empty!\n";
    else {
        Node *current = front;
        while (current != NULL) {
            cout << current->item << " ";
            current = current->next;
        }
        cout << '\n';
    }
}
