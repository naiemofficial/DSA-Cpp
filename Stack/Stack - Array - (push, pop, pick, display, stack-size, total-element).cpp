#include <iostream>
using namespace std;

#define Size 5
int Stack[Size];
int top=-1;

void push(int input){
    if( top == Size-1 ){
        cout << "You can't add [" << input << "]. Because, the stack is overflow (means limit exceeded)" << endl;
    }else{
        top++;
        Stack[top] = input;
    }
}
void pop(){
    if( top < 0 ){
        cout << "The stack is underflow" << endl;
    }else{
        top--;
    }
}
void pick(){
    if( top < 0 ){
        cout << "Sorry, you can't pick data from the stack. Because it's emty." << endl;
    }else{
        cout << "You've been picked:[" << Stack[top] << "]" << endl;
    }
}
void display(string args){
    if(args == "stack"){
        if( top < 0 ){
            cout << "The stack is empty" << endl;
        }else{
            cout << "[STACK]: ";
            for(int i=top; i>=0; i--){ //top=5
                cout << Stack[i] << "       ";
            }
        }
    }else if(args == "total-element"){
        if( top < 0 ){
            cout << "Total element is: " << 0 << endl;
        }else{
            cout << "Total element is: " << top+1 << endl;
        }
    }else if(args == "stack-size"){
        cout << "Stack size is: " << Size << endl;
    }else{
        cout << "Invalid Argument" << endl;
    }
}
int main(){
    push(10); // add=10
    push(20); // add=20
    push(30); // add=30
    push(40); // add=40
    push(50); // add=50
    push(60); // stack is overflow -> limit exceeded
    display("stack"); // display full stack
    pop(); // delete=50
    pop(); // delete=40
    pop(); // delete=30
    pop(); // delete=20
    pick(); // Pick=10
    pop(); // delete=10
    pick(); // Can't pick, because stack is empty
    pop(); // stack is underflow
    pop(); // stack is underflow
    display("stack"); // stack is empty
    display("stack-size"); // show stack-size
    display("total-element"); // Show total element

    return 0;
}
