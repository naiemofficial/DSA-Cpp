#include <iostream>
#define N 4
using namespace std;

int Array[N];
int Front = -1, Rear = Front;
void enqueue(int data){
    if(Rear >= N-1){
        cout << "Can't enter [" << data << "]. Queue is full!" << endl;
    }else if( Front == -1 && Rear == -1){
        Rear++;
        Array[Rear] = data;
        Front = Rear;
    }else{
        Rear++;
        Array[Rear] = data;
    }
}

void display(){
    if(Front == Rear){
        cout << "Queue is empty!" << endl;
    }else{
        for(int x=0; x<N; x++){
            cout << Array[x] << endl;
        }
    }
}

void dequeue(){
    if( Front == Rear ){
        cout << "Queue is emtpy! (underflow)!" << endl;
    }else{
        Front++;
    }
}
int main(){
    enqueue(5);
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    cout << endl << endl;
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    cout << Array[Front] << endl;
    cout << Array[Rear] << endl;
    return 0;
}
