#include <iostream>
#include <chrono>
#define MAX_SIZE 100

using namespace std;
using namespace std::chrono;

class Stack{
    private:
        int stackArr[MAX_SIZE];
        int top;
    public:
        Stack(){
            top = -1;
        }

        bool isEmpty(){
            return (top==-1);
        }

        bool isFull(){
            return (top==MAX_SIZE-1);
        }

        void push(int value){
            if (isFull()){
                cout << "Stack Overflow" << endl;
            } else {
                top++;
                stackArr[top] = value;
            }
        }

        int pop(){
            if (isEmpty()){
                cout << "Stack Underflow" << endl;
                return -1;
            } else {
                top--;
                return stackArr[top+1];
            }
        }

        int stackTop(){
            if (isEmpty()){
                cout << "Stack is Empty" << endl;
                return -1;
            } else {
                return stackArr[top];
            }
        }

        void display(){
            if (isEmpty()){
                cout << "Stack is Empty" << endl;
            } else {
                cout << "Stack : ";
                for (int i=0; i<=top; i++){
                    cout << stackArr[i] << "  ";
                }
                cout << endl;
            }
        }


};

int main(){
    auto startTime = high_resolution_clock::now();
    Stack s;
    //pushing 8, 10, 5, 11, 15, 23, 6, 18, 20, 17
    s.push(8); s.push(10); s.push(5); s.push(11); s.push(15); s.push(23); s.push(6); s.push(18); s.push(20); s.push(17);
    
    s.display();

    s.pop(); s.pop(); s.pop(); s.pop(); s.pop();

    s.display();
    //pushing 4, 30, 3, 1
    s.push(4); s.push(30); s.push(3); s.push(1);

    s.display();
    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    cout << "Execution time: " << duration.count() << " micro seconds" << endl;
    return 0;
}