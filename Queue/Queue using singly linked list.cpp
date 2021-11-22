#include <iostream>
using namespace std;

struct NODE{
    int data;
    NODE *next;
};

NODE *Front, *Rear, *temp;
void enqueue(int data){
    if( Rear == NULL){
        Rear = new NODE;
        Rear->data = data;
        Rear->next = NULL;
        Front = Rear;
    }else{
        Rear->next = new NODE;
        Rear = Rear->next;
        Rear->data = data;
        Rear->next = NULL;
    }
}


void dequeue(){
    if(Front == NULL){
        cout << "Queue is empty!" << endl;
    }else{
        temp = Front;
        Front = Front->next;
        delete temp;
    }
}

void display(string param){
    if(param == "queue"){
        temp = Front;
        while(temp != 0){
            cout << temp->data << endl;
            temp = temp->next;
        }
    }else if(param == "front"){
        cout << Front->data << endl;
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

