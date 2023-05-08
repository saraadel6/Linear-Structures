//Queue Implementation
#include<bits/stdc++.h>
using namespace std;
template<class T>
struct QNode {
public:
    QNode *next;
    T item;
};
template<class T>
class Queue {
    int length;
    QNode<T> *front, *end;
public:
    Queue();
    void enqueue(T element);
    T dequeue();
    T first();
    bool isEmpty();
    int queueSize();
    void clear();
    void print();
    void setFront(QNode<T>* node);
    QNode<T>* getFront();
    void setEnd(QNode<T>* node);
};

template<class T>
Queue<T>::Queue() {
    front = end = NULL;
    length=0;
}

template<class T>
void Queue<T>::enqueue(T element) {
    QNode<T>* node = new QNode<T>();
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
        return T();
    }
    else if (length == 1)
    {
        T item = front->item;
        delete front;
        end = NULL;
        length = 0;
        return item;

    }
    else{
        T item = front->item;
        QNode<T> *temp = front;
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
        QNode<T> *current;
        while (front != NULL) {
            current = front;
            front = front->next;
            delete current;
        }
        delete end;
        front = end = NULL;
        length = 0;
    }
}

template<class T>
void Queue<T>::print(){
    if(isEmpty())
        cout<<"The Queue is empty!\n";
    else {
        QNode<T> *current = front;
        while (current != NULL) {
            cout << current->item << " ";
            current = current->next;
        }
        cout << '\n';
    }
}
template<class T>
QNode<T> *Queue<T>::getFront() {
    return front;
}

template<class T>
void Queue<T>::setFront(QNode<T>* node) {
    front= node;
}
template<class T>
void Queue<T>::setEnd(QNode<T>* node) {
    end= node;
}

//##########################################################################################################################
//problems

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

//##########################################################################################################################
template<class T>
void sort(Queue<T>&queue) {
    if (queue.isEmpty()) {
        return;
    }
    int size = queue.queueSize();
    for (int i = 0; i < size - 1; i++) {
        QNode<T>* current = queue.getFront();
        QNode<T>* prev = NULL;
        while (current != NULL && current->next != NULL) {
            if (current->item > current->next->item) {
                if (prev != NULL) {
                    prev->next = current->next;
                }
                else {
                    queue.setFront(current->next) ;
                }
                QNode<T>* temp = current->next->next;
                current->next->next = current;
                current->next = temp;
                if (temp == NULL) {
                    queue.setEnd(current->next);
                }
                if (prev == NULL)
                    current = queue.getFront();
                else
                    current = prev->next;
            }
            else {
                prev = current;
                current = current->next;
            }
        }
    }
}