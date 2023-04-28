//Queue Implementation
#include<bits/stdc++.h>
using namespace std;
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

//##########################################################################################################################

void QueueBinaryNumbers(int n) {
    Queue <string> queue1;
    queue1.enqueue("1");
    while (n > 0) {
        string First = queue1.first();
        queue1.dequeue();

        cout << First << " ";

        queue1.enqueue(First + "0");
        queue1.enqueue(First + "1");
        n--;
    }
}

//##########################################################################################################################

template <class T>
class StackFromQueue{
    Queue<T>queue1,queue2;
public:

    void push(T element){
        queue1.enqueue(element);
    }

    T pop(){
        if(queue1.isEmpty()){
            cout<<"Empty Stack!\n";
            return T();
        }
        while (queue1.queueSize() > 1) {
            T element = queue1.dequeue();
            queue2.enqueue(element);
        }
        T element = queue1.dequeue();
        Queue<T> temp = queue1;
        queue1 = queue2;
        queue2 = temp;
        return element;
    }
    void print(){
        queue1.print();
    }
};