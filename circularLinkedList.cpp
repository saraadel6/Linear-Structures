// Circular Linked List Implementation
#include <bits/stdc++.h>
using namespace std;
template <class T>
class circularLinkedList
{
    struct Node
    {
        T item;
        Node *next;
    };
    Node *head;
    Node *tail;
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
    bool isExist(T element);
    bool isItemAtEqual(T element, int index);
    void swap(int firstItemIdx, int secondItemIdx);
    bool isEmpty();
    int circularLinkedListSize();
    void clear();
    void print();
};

template <class T>
circularLinkedList<T>::circularLinkedList()
{
    head = tail = NULL;
    length = 0;
}

template <class T>
void circularLinkedList<T>::insertAtHead(T element)
{
    Node *node = new Node;
    node->item = element;
    if (isEmpty())
    {
        head = tail = node;
        tail->next = head;
    }
    else
    {
        node->next = head;
        head = node;
        tail->next = head;
    }
    length++;
}

template <class T>
void circularLinkedList<T>::insertAtEnd(T element)
{
    Node *node = new Node;
    node->item = element;
    if (isEmpty())
    {
        head = tail = node;
        tail->next = head;
    }
    else
    {
        tail->next = node;
        node->next = head;
        tail = node;
    }
    length++;
}

template <class T>
void circularLinkedList<T>::insertAt(T element, int index)
{
    if (index < 0 || index > length)
        cout << "OUT OF RANGE!\n";
    else if (index == 0)
        insertAtHead(element);
    else if (index == length)
        insertAtEnd(element);
    else
    {
        Node *node = new Node;
        node->item = element;
        Node *current = head;
        for (int i = 1; i < index; i++)
        {
            current = current->next;
        }
        node->next = current->next;
        current->next = node;
        length++;
    }
}

template <class T>
void circularLinkedList<T>::removeAtHead()
{
    if (length == 0)
        cout << "The list is empty!\n";
    else if (length == 1)
    {
        delete head;
        head = tail = NULL;
        length--;
    }
    else
    {
        head = head->next;
        tail->next = head;
        length--;
    }
}

template <class T>
void circularLinkedList<T>::removeAtEnd()
{
    if (length == 0)
        cout << "The list is empty!\n";
    else if (length == 1)
    {
        delete head;
        head = tail = NULL;
        length--;
    }
    else
    {
        Node *node = head;
        Node *nextNode = head->next;
        while (nextNode != tail)
        {
            node = nextNode;
            nextNode = nextNode->next;
        }
        delete nextNode;
        node->next = head;
        tail = node;
        length--;
    }
}

template <class T>
void circularLinkedList<T>::removeAt(int index)
{
    if (index < 0 || index >= length)
        cout << "OUT OF RANGE!\n";
    else if (index == 0)
        removeAtHead();
    else if (index == length - 1)
        removeAtEnd();
    else
    {
        Node *node = head;
        Node *nextNode = head->next;
        for (int i = 1; i < index; i++)
        {
            node = nextNode;
            nextNode = nextNode->next;
        }
        node->next = nextNode->next;
        delete nextNode;
        length--;
    }
}

template <class T>
T circularLinkedList<T>::retrieveAt(int index)
{
    if (index < 0 || index >= length)
    {
        cout << "OUT OF RANGE!\n";
        return 0;
    }
    else
    {
        Node *node = head;
        for (int i = 0; i < index; i++)
        {
            node = node->next;
        }
        return node->item;
    }
}

template <class T>
void circularLinkedList<T>::replaceAt(T newElement, int index)
{
    if (index < 0 || index >= length)
        cout << "OUT OF RANGE!\n";
    else
    {
        Node *node = head;
        for (int i = 0; i < index; i++)
        {
            node = node->next;
        }
        node->item = newElement;
    }
}

template <class T>
bool circularLinkedList<T>::isExist(T element)
{
    Node *node = head;
    for (int i = 0; i < length; i++)
    {
        if (node->item == element)
        {
            cout << "YES, EXIST\n";
            return true;
        }
        node = node->next;
    }
    cout << "NOT EXIST!\n";
    return false;
}

template <class T>
bool circularLinkedList<T>::isItemAtEqual(T element, int index)
{
    if (index < 0 || index > length)
    {
        cout << "OUT OF RANGE!\n";
        return 0;
    }
    else
    {
        Node *node = head;
        for (int i = 1; i <= index; ++i)
        {
            node = node->next;
        }
        if (element == node->item)
        {
            cout << "Yes, equal\n";

            return 1;
        }
        cout << "Not equal!\n";

        return 0;
    }
}

template <class T>
bool circularLinkedList<T>::isEmpty()
{
    return (length == 0);
}

template <class T>
void circularLinkedList<T>::clear()
{
    Node *current = head;
    Node *nextNode = NULL;
    do
    {
        nextNode = current->next;
        delete current;
        current = nextNode;
    } while (current != head);
    head = NULL;
    length = 0;
}
template <class T>
void circularLinkedList<T>::print()
{
    if (isEmpty())
    {
        cout << "The circular linked list is empty!\n";
        return;
    }
    else
    {
        Node *current = head;
        do
        {
            cout << current->item << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }
}
// #####################################################################################################################
