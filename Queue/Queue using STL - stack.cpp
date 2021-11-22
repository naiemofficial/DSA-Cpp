#include <iostream>
#include <stack>
using namespace std;

stack<int> Stack_1, Stack_2;
void enqueue(int data){
    Stack_1.push(data);
}
void dequeue(){
    if(Stack_1.empty()){
        cout << "Queue(stack) is emtpy! - Ref: Deque" << endl;
    }else{
        while(!Stack_1.empty()){
            Stack_2.push(Stack_1.top());
            Stack_1.pop();
        }

        Stack_2.pop();
        while(!Stack_2.empty()){
            Stack_1.push(Stack_2.top());
            Stack_2.pop();
        }
    }
}
void display(){
    if(Stack_1.empty()){
        cout << "Queue(stack) is emtpy! - Ref: Display" << endl;
    }else{
        while(!Stack_1.empty()){
            cout << " => " << Stack_1.top();
            Stack_1.pop();
        }
    }
}
int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    dequeue();
    dequeue();
    dequeue();
    display();
    return 0;
}
