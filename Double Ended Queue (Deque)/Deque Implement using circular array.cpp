#include <iostream>
using namespace std;
#define Size 5

int Array[Size], Front=-1, Rear=-1;
void push(int data){
    if(Front==-1 && Rear ==-1){
        Front = Rear = 0;
        Array[Rear] = data;
    }else if((Rear+1)%Size == Front){
        cout << "Queue is full! Ref: push" << endl;
    }else{
        Rear = (Rear+1)%Size;
        Array[Rear] = data;
    }
}
void push_front(int data){
    if(Front==0 && Rear==Size-1){
        cout << "Queue is full! Ref: push_front" << endl;
    }else if(Front == 0){
        Front = Size-1;
        Array[Front] = data;
    }else{
        Front--;
        Array[Front] = data;
    }
}
void pop(){
    if(Front==-1 && Rear==-1){
        cout << "Queue is empty! Ref: pop" << endl;
    }else if(Front == Rear){
        Front = Rear = -1;
    }else{
        Front = (Front+1)%Size;
    }
}
void pop_back(){
    if(Front==-1 && Rear==-1){
        cout << "Queue is empty! Ref: pop" << endl;
    }else if(Front == Rear){
        Front = Rear = -1;
    }else if(Rear == 0){
        Rear = Size-1;
    }else{
        Rear--;
    }
}
void display(){
    if(Front==-1 && Rear==-1){
        cout << "Queue is empty! Ref: display" << endl;
    }else{
        int i=Front;
        while(i != Rear){
            cout << Array[i] << endl;
            i=(i+1)%Size;
        }
        if(i==Rear){
            cout << Array[i] << endl;
        }
    }
}
int main(){
    push(10);
    push_front(20);
    push(30);
    push_front(15);
    pop();
    pop_back();
    display();
    return 0;
}
