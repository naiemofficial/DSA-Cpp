#include <iostream>
using namespace std;
struct NODE{
    NODE *link;
    int data;
};
NODE *top=0, *newnode=0;
void push(int input){
    if( top == 0 ){
        newnode = new NODE;
        newnode->link = 0;
        newnode->data = input;
        top = newnode;
    }else{
        newnode = new NODE;
        newnode->link = top;
        newnode->data = input;
        top = newnode;
    }
}
void pop(){
    if(top != 0){
        NODE *popnode=top;
        top = popnode->link;
        delete popnode;
        if( top == 0 ){
            cout << "All nodes popped out from the stack" << endl;
        }
    }else{
        cout << "Unable to pop, because the stack is empty" << endl;
    }
}
void display(string args){
    if( top == 0 ){
        if( args == "stack"){
            cout << "Sorry can't display the stack, because the stack is empty" << endl;
        }else if( args == "top" ){
            cout << "Top: #NULL" << endl;
        }else if( args == "elements" ){
            cout << "Elements: " << 0 << endl;
        }
    }else{
        if( args == "stack" ){
            NODE *loop = top;
            while(loop != 0){
                cout << "["<< loop->data << "]  <==  ";
                loop = loop->link;
            }
            cout << endl;
        }else if(args == "top"){
            cout << "Top: " << top->data << endl;
        }else if(args == "elements"){
            NODE *loop = top;
            int total=0;
            while(loop!=0){
                total++;
                loop = loop->link;
            }
            cout << "Elements: " << total << endl;
            cout << "-------------" << endl;
        }
    }
}
int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    display("elements");
    display("stack");
    display("top");
    cout << endl << endl;
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    display("elements");
    display("stack");
    display("top");
}
