#include <bits/stdc++.h>
using namespace std;

class StackImplementation
{
    int size;
    int *arr;
    int top;

public:
    StackImplementation()
    {
        top = -1;
        size = 4;
        arr = new int[size];
    }

    void push(int num)
    {
        if (top == size - 1)
        {
            cout << "Stack overflow" << endl;
            return;
        }
        top++;
        arr[top] = num;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        int topEle = arr[top];
        top--;
        return topEle;
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }

    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Stack elements (top to bottom):" << endl;
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }
};

int main()
{
    StackImplementation s;

    int choice, val;

    while (true)
    {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> val;
            s.push(val);
            break;
        case 2:
            cout << "Popped element: " << s.pop() << endl;
            break;
        case 3:
            cout << "Top element: " << s.peek() << endl;
            break;
        case 4:
            s.display();
            break;
        case 5:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice!" << endl;
        }
    }
}
