#include <iostream>
using namespace std;
#define Size 4

int Array[Size], Front=-1, Rear=-1;
void push(int data){
    if(Front == -1 && Rear == -1){
        Front = Rear = 0;
        Array[Rear] = data;
    }else if((Rear+1)%Size == Front){
        cout << "Queue is full!" << endl;
    }else{
        Rear = (Rear+1)%Size;
        Array[Rear] = data;
    }
}
void pop(){
    if(Front == -1 && Rear == -1){
        cout << "Queue is empty!" << endl;
    }else if(Front == Rear){
        Front =  Rear = -1;
    }else{
        Front = (Front+1)%Size;
    }
}
void display(){
    if(Front == -1 && Rear == -1){
        cout << "Queue is empty!" << endl;
    }else{
        int i=Front;
        while(i != Rear){
            cout << Array[i] << endl;
            i = (i+1)%Size;
        }
        if(i==Rear){
            cout << Array[i] << endl;
        }
    }
}
int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    pop();
    pop();
    display();
    cout << endl;
    pop();
    push(60);
    push(70);
    push(80);
    display();
    return 0;
}
