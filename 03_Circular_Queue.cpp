
#include <iostream>
using namespace std;

#define SIZE 5

int q[SIZE], front = -1, rear = -1;

void enqueue(int x) {
    if ((rear + 1) % SIZE == front) {
        cout << "Queue Full\n";
        return;
    }

    if (front == -1) front = 0;

    rear = (rear + 1) % SIZE;
    q[rear] = x;
}

void dequeue() {
    if (front == -1) {
        cout << "Queue Empty\n";
        return;
    }

    cout << "Deleted: " << q[front] << endl;

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
}

void display() {
    if (front == -1) {
        cout << "Queue Empty\n";
        return;
    }

    for (int i = front; ; i = (i + 1) % SIZE) {
        cout << q[i] << " ";
        if (i == rear) break;
    }
    cout << endl;
}

int main() {
    int ch, x;

    do {
        cout << "\n1.Enqueue  2.Dequeue  3.Display  0.Exit\n";
        cin >> ch;

        switch (ch) {
            case 1:
                cin >> x;
                enqueue(x);
                break;
            case 2: dequeue(); break;
            case 3: display(); break;
        }

    } while (ch != 0);

    return 0;
}
