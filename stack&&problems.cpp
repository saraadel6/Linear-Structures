//Stack Implementation
#include<bits/stdc++.h>
using namespace std;
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
    T pop();
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
T Stack<T>::pop() {
    if(_size == 0) {
        cout << "The stack is empty!\n";
        return T();
    } else {
        T poppedItem = head->val;
        Node* temp = head; 
        head = head->next;
        delete temp;
        --_size;
        return poppedItem;
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


bool ArePair(char open, char close)
{
	if (open == '(' && close == ')') 
		return true;
	else if (open == '{' && close == '}') 
		return true;
	else if (open == '[' && close == ']')
		return true;
	return false;
}
void noOfBalanced(string exp)
{
    int balancedNo = 0;
	Stack<char> S;
	int length = exp.length();
	for (int i = 0; i < length; i++)
	{
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			S.push(exp[i]);
		else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if (!S.isEmpty() && ArePair(S.top(), exp[i])){
                balancedNo += 2;
				S.pop();
            }
		}
	}
	cout << balancedNo << '\n';
}

//###################################################################################################################
// Stack Problems

int preced(char sign) {
    if(sign == '+' || sign == '-') {
      return 1;       
   }else if(sign == '*' || sign == '/') {
      return 2;            
   }else if(sign == '^') {
      return 3;            
   }else {
      return 0;
   }
}

string inToPost(string infix ) {
Stack<char> stk;
stk.push('#');               
string postfix = "";         
string::iterator it;

for(it = infix.begin(); it!=infix.end(); it++) {
    if(isalnum(char(*it)))
        postfix += *it;      
    else if(*it == '(')
        stk.push('(');
    else if(*it == '^')
        stk.push('^');
    else if(*it == ')') {
        while(stk.top() != '#' && stk.top() != '(') {
            postfix += stk.top(); 
            stk.pop();
        }
        stk.pop();          
    }else {
        if(preced(*it) > preced(stk.top()))
            stk.push(*it); 
        else {
            while(stk.top() != '#' && preced(*it) <= preced(stk.top())) {
            postfix += stk.top();        
            stk.pop();
            }
            stk.push(*it);
        }
    }
}

while(stk.top() != '#') {
    postfix += stk.top();        
    stk.pop();
}
return postfix;
}