
#include <iostream>
using namespace std;

#define SIZE 5

int q[SIZE], front = -1, rear = -1;

// Insert element
void enqueue(int x) {
    if ((rear + 1) % SIZE == front) {
        cout << "Queue Full!\n";
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % SIZE;
    q[rear] = x;

    cout << "Inserted!\n";
}

// Delete element
void dequeue() {
    if (front == -1) {
        cout << "Queue Empty!\n";
        return;
    }

    cout << "Deleted: " << q[front] << endl;

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
}

// Display elements
void display() {
    if (front == -1) {
        cout << "Queue Empty!\n";
        return;
    }

    int i = front;
    while (true) {
        cout << q[i] << " ";
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    cout << endl;
}

int main() {
    int ch, x;

    do {
        cout << "\n1.Enqueue  2.Dequeue";
        cout << "\n3.Display  0.Exit";
        cout << "\nEnter choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter value: ";
                cin >> x;
                enqueue(x);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;
        }
    } while (ch != 0);

    return 0;
}
