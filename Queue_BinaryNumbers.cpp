#include<bits/stdc++.h>
#include "linear_structures.cpp"
using namespace std;

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

int main() {
    cout << "Binary numbers from 1 to 3 \n";
    QueueBinaryNumbers(3);
    cout << '\n';

    cout << "Binary numbers from 1 to 5 \n";
    QueueBinaryNumbers(5);
    cout << '\n';

}
