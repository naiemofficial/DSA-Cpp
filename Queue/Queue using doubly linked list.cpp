#include <iostream>
using namespace std;

struct NODE{
    int data;
    NODE *next;
};

NODE *Front, *Rear, *temp;
void enqueue(int data){
    if( Rear == NULL){
        Front = Rear = new NODE;
        Rear->data = data;
        Rear->next = Front;
    }else{
        Rear->next = new NODE;
        Rear = Rear->next;
        Rear->data = data;
        Rear->next = Front;
    }
}
void display(string param){
    if(param == "queue"){
        temp = Front;
        do{
            cout << temp->data << endl;
            temp = temp->next;
        }while(temp != Front);
    }else if(param == "front"){
        cout << Front->data << endl;
    }
}

void dequeue(){
    temp = Front;
    if(Front == NULL){
        cout << "Queue is empty!" << endl;
    }else if(Front == Rear){
        Front = Rear = 0;
        delete temp;
    }else{
        Front = Front->next;
        delete temp;
        Rear->next = Front;
    }
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    dequeue();
    display("queue");
    cout << endl;
    display("front");
    return 0;
}
