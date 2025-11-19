// a queue is FIFO (First in first out)
// so first element inserted, will be the first to be removed
// enqueue(x) -> insert x into the queue
// dequeue() -> remove element from the front
// front() / peek() -> get first element without removing it
// isEmpty(), isFull() for checks

#include <bits/stdc++.h>
using namespace std;
#define SIZE 5

int arr[SIZE];
int front = -1, rear = -1;
// front : first element of queue (oldest) -> used in dequeue / peek() to remove or look at element
// rear : last element (latest/newest inserted) -> used in enqueue() : to insert new element

void enqueue(int x)
{
    if (rear == SIZE - 1)
    {
        cout << "Queue overflow\n";
        return;
    }

    // so making front to be 0, always will point at first element
    if (front == -1)
        front = 0;
    rear++;
    arr[rear] = x;
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue underflow\n";
        return;
    }

    cout << "Deleted: " << arr[front] << endl;
    front++;

    // reset when queue becomes empty
    if (front > rear)
        front = rear = -1;
}

void peek()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue is empty\n";
        return;
    }

    cout << "Front element: " << arr[front] << endl;
}

void display()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue is empty\n";
        return;
    }

    cout << "Queue elements:\n";
    for (int i = front; i <= rear; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int choice, val;

    while (true)
    {
        cout << "\n----- Queue Operations -----\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek (Front element)\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> val;
            enqueue(val);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            cout << "Existing program...\n";
            return 0;

        default:
            cout << "Invalid choice.";
        }
    }
}