
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Node{
    int data;
    Node * next;

    Node(int value){
        data = value;
        next = nullptr;
    }
};

class Stack{
    private:
        Node * head;

    public:
        Stack(){
            head = nullptr;
        }

        void push(int value){
            Node * newNode = new Node(value);
            newNode->next = head;
            head = newNode;
        }

        int pop(){
            if (head == nullptr){
                cout << "Stack Underflow" << endl;
                return -1;
            }
            else{
                int popValue = head->data;
                Node * popNode = head;
                head = head->next;
                delete popNode;
                return popValue;
            }
        }

        bool isEmpty(){
            return (head == nullptr);
        }

        int stackTop(){
            if (head == nullptr){
                cout << "Stack Underflow" << endl;
                return -1;
            }
            else{
                return head->data;
            }
        }

        void display(){
            if (head == nullptr){
                cout << "Stack Underflow" << endl;
            }
            Node * current = head;
            cout << "stack : ";
            while(current != nullptr){
                cout << current->data << "  ";
                current = current->next;
            }
            cout << endl;
        }
};

int main()
{
    Stack stack;
    auto startTime = high_resolution_clock::now();
    stack.push(8); stack.push(10); stack.push(5); stack.push(11); stack.push(15); stack.push(23); stack.push(6); stack.push(18); stack.push(20); stack.push(17);

    stack.display();

    stack.pop(); stack.pop(); stack.pop(); stack.pop(); stack.pop();

    stack.display();

    stack.push(4); stack.push(30); stack.push(3); stack.push(1);

    stack.display();

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime- startTime);
    cout << "Execution time: " << duration.count() << " microseconds" << endl;
    return 0;
}