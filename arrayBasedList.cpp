// Array-Based List Implementation
#include <bits/stdc++.h>
using namespace std;

template <class T>
class arrayBasedList
{
    T *list;
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

template <class T>
arrayBasedList<T>::arrayBasedList(int size)
{
    if (size <= 0)
    {
        cout << "Incorrect initial size for the array.\n";
        maxSize = 100;
    }
    else
    {
        maxSize = size;
        length = 0;
        list = new int[maxSize];
    }
}

template <class T>
void arrayBasedList<T>::insert(T element)
{
    if (isFull())
    {
        cout << "The list is full.\n";
    }
    else
    {
        list[length++] = element;
    }
}

template <class T>
void arrayBasedList<T>::removeAt(int index)
{
    if (index < 0 || index > length)
    {
        cout << "Out of range.\n";
    }
    else
    {
        for (int i = index; i < length; ++i)
        {
            list[i] = list[i + 1];
        }
        length--;
    }
}

template <class T>
void arrayBasedList<T>::replaceAt(T newElement, int index)
{
    if (index < 0 || index > length)
    {
        cout << "Out of range.\n";
    }
    else
    {
        list[index] = newElement;
    }
}

template <class T>
void arrayBasedList<T>::insertAt(T element, int index)
{
    if (isFull())
    {
        cout << "The list is full.\n";
    }
    else if (index < 0 || index > length)
    {
        cout << "Out of range.\n";
    }
    else
    {
        for (int i = length; i > index; --i)
        {
            list[i] = list[i - 1];
        }
        list[index] = element;
        length++;
    }
}

template <class T>
bool arrayBasedList<T>::isEmpty()
{
    if (length == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
bool arrayBasedList<T>::isFull()
{
    if (length == maxSize)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
bool arrayBasedList<T>::isItemAtEqual(T element, int index)
{
    if (index >= length || index < 0)
    {
        return false;
    }
    else
    {
        return (list[index] == element);
    }
}

template <class T>
int arrayBasedList<T>::maxListSize()
{
    return maxSize;
}

template <class T>
int arrayBasedList<T>::listSize()
{
    return length;
}

template <class T>
arrayBasedList<T>::~arrayBasedList()
{
    delete[] list;
}

template <class T>
void arrayBasedList<T>::print()
{
    if (isEmpty())
        cout << "The array is empty.\n";
    else
    {
        for (int i = 0; i < length; ++i)
        {
            cout << list[i] << ' ';
        }
        cout << "\n";
    }
}

template <class T>
void arrayBasedList<T>::clear()
{
    length = 0;
}
