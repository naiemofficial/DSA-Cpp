#include <iostream>
using namespace std;
#define Size 5

struct NODE{
    NODE *prev;
    int data;
    NODE *next;
};
NODE *Front=0, *Rear=0, *tempFront, *tempRear;

void push(int data){
    if(Rear == 0){
        Rear = new NODE;
        tempFront = Front = tempRear = Rear;
        Rear->prev = 0;
        Rear->data = data;
        Rear->next = 0;
    }else{
        Rear->next = new NODE;
        Rear = Rear->next;
        Rear->prev = tempRear;
        Rear->data = data;
        Rear->next = 0;
        tempRear = Rear;
    }
}

void push_front(int data){
    if(Front==0){
        cout << "Deque is empty, push any content first. Ref: push_front" << endl;
    }else{
        Front->prev = new NODE;
        Front = Front->prev;
        Front->data = data;
        Front->prev = 0;
        Front->next = tempFront;
        tempFront = Front;
    }
}

void pop(){
    if(Rear==0){
        cout << "Deque is empty. Ref: pop" << endl;
    }else{
        Front = Front->next;
        delete Front->prev;
        Front->prev = 0;
        tempFront = Front;
    }
}
void pop_back(){
    if(Rear==0){
        cout << "Deque is empty. Ref: pop_back" << endl;
    }else{
        Rear = Rear->prev;
        delete tempRear;
        Rear->next = 0;
        tempRear = Rear;
    }
}

void display(){
    if(Front==0){
        cout << "Deque is empty. Ref: display" << endl;
    }else{
        NODE *Loop=Front;
        do{
            cout << Loop->data << endl;
            Loop = Loop->next;
        }while(Loop != 0);
    }
}


int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    pop();
    pop_back();
    display();
    return 0;
}
